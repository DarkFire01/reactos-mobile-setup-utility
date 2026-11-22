/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Mounting, servicing and committing a ReactOS boot image
 */

/*
 * A mounted image is the extracted ISO plus rmsetup\ with what was added: the
 * registry INFs in the order they came, and image.ini. Committing builds the hives
 * again from the INFs the image was built from with the added ones after them, so
 * a committed image can be mounted and serviced again and stays reproducible.
 *
 * The boot media carries two system trees: reactos\ for the live environment the
 * device boots and <arch>\ for text mode setup. Files go into both.
 */

#include "rmsetup.h"

/* The hives of the live environment, and what the build makes them from */
static PCWSTR LiveHives[] = { L"system", L"software", L"default", L"sam", L"security" };
static PCWSTR LiveSources[] = { L"livecd.inf", L"caroots.inf", L"hiveinst.inf" };

static
PWSTR
ImagePath(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Relative)
{
    WCHAR Full[MAX_PATH * 2];
    PWSTR Joined = RmsJoin(MountDir, Relative);

    GetFullPathNameW(Joined, ARRAYSIZE(Full), Full, NULL);
    free(Joined);
    return _wcsdup(Full);
}

static
VOID
ImageGet(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Name,
    _Out_writes_z_(Size) PWSTR Value,
    _In_ DWORD Size)
{
    PWSTR Ini = ImagePath(MountDir, RMS_IMAGE_INI);

    GetPrivateProfileStringW(L"Image", Name, L"", Value, Size, Ini);
    free(Ini);
}

static
VOID
ImageSet(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Name,
    _In_z_ PCWSTR Value)
{
    PWSTR Ini = ImagePath(MountDir, RMS_IMAGE_INI);

    WritePrivateProfileStringW(L"Image", Name, Value, Ini);
    free(Ini);
}

/**
 * @brief Gets the setup folder name of the mounted image, such as arm64 or amd64, empty when unknown.
 */
VOID
RmsGetImageArch(
    _In_z_ PCWSTR MountDir,
    _Out_writes_z_(Size) PWSTR Arch,
    _In_ DWORD Size)
{
    ImageGet(MountDir, L"Arch", Arch, Size);
}

/* The setup tree is the root folder that holds txtsetup.sif */
static
BOOL
ImageFindArch(
    _In_z_ PCWSTR MountDir,
    _Out_writes_z_(Size) PWSTR Arch,
    _In_ SIZE_T Size)
{
    WIN32_FIND_DATAW Find;
    PWSTR Pattern = RmsJoin(MountDir, L"*");
    HANDLE Handle = FindFirstFileW(Pattern, &Find);
    BOOL Found = FALSE;

    free(Pattern);
    Arch[0] = UNICODE_NULL;
    if (Handle == INVALID_HANDLE_VALUE)
        return FALSE;

    do
    {
        PWSTR Folder, Sif;

        if (!(Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || Find.cFileName[0] == L'.')
            continue;

        Folder = RmsJoin(MountDir, Find.cFileName);
        Sif = RmsJoin(Folder, L"txtsetup.sif");
        if (RmsFileExists(Sif))
        {
            wcscpy_s(Arch, Size, Find.cFileName);
            Found = TRUE;
        }
        free(Sif);
        free(Folder);
    } while (!Found && FindNextFileW(Handle, &Find));

    FindClose(Handle);
    return Found;
}

static
BOOL
ImageMounted(
    _In_z_ PCWSTR MountDir)
{
    PWSTR Ini = ImagePath(MountDir, RMS_IMAGE_INI);
    BOOL Mounted = RmsFileExists(Ini);

    free(Ini);
    if (!Mounted)
        RmsError(L"%s is not a mounted image, use /Mount-Image first", MountDir);
    return Mounted;
}

/**
 * @brief Copies a file into both system trees of the image.
 *
 * @param[in] RelativeDir
 * The folder under the system root, like system32\drivers.
 */
BOOL
RmsStageSystemFile(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Source,
    _In_z_ PCWSTR RelativeDir,
    _In_opt_z_ PCWSTR TargetName)
{
    WCHAR Arch[64], Target[MAX_PATH * 2];
    PCWSTR Roots[2] = { L"reactos", NULL };
    PCWSTR Name = wcsrchr(Source, L'\\');
    ULONG Index;
    BOOL Ok = TRUE;

    Name = (TargetName && TargetName[0]) ? TargetName : (Name ? Name + 1 : Source);
    ImageGet(MountDir, L"Arch", Arch, ARRAYSIZE(Arch));
    if (Arch[0])
        Roots[1] = Arch;

    for (Index = 0; Index < ARRAYSIZE(Roots); Index++)
    {
        if (!Roots[Index])
            continue;

        swprintf_s(Target, ARRAYSIZE(Target), L"%s\\%s%s%s\\%s", MountDir, Roots[Index],
                   RelativeDir[0] ? L"\\" : L"", RelativeDir, Name);
        Ok = RmsCopyFileTo(Source, Target) && Ok;
    }
    return Ok;
}

/* Puts a registry INF into the image, a name added before keeps its place in the order */
BOOL
RmsRegisterInf(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Name,
    _In_opt_z_ PCWSTR SourcePath,
    _In_opt_z_ PCWSTR Text)
{
    PWSTR Registry = ImagePath(MountDir, RMS_REGISTRY_DIR);
    PWSTR Order = ImagePath(MountDir, RMS_ORDER_FILE);
    PWSTR Target = RmsJoin(Registry, Name);
    PWSTR Existing = RmsReadText(Order);
    BOOL Listed = FALSE, Ok;

    if (Existing)
    {
        PWSTR Line, Context = NULL;

        for (Line = wcstok_s(Existing, L"\r\n", &Context); Line; Line = wcstok_s(NULL, L"\r\n", &Context))
        {
            if (!_wcsicmp(Line, Name))
                Listed = TRUE;
        }
        free(Existing);
    }

    RmsMakeDirectories(Registry);
    Ok = SourcePath ? RmsCopyFileTo(SourcePath, Target) : RmsWriteText(Target, Text);
    if (Ok && !Listed)
        Ok = RmsAppendLine(Order, Name);

    free(Registry);
    free(Order);
    free(Target);
    return Ok;
}

int
RmsMountImage(
    _In_z_ PCWSTR ImageFile,
    _In_z_ PCWSTR MountDir)
{
    WCHAR VolumeId[64], Arch[64];
    PWSTR State;

    if (RmsDirectoryExists(MountDir) && !RmsDirectoryEmpty(MountDir))
    {
        RmsError(L"%s is not empty", MountDir);
        return 1;
    }

    if (!RmsExtractIso(ImageFile, MountDir, VolumeId, ARRAYSIZE(VolumeId)))
        return 1;

    State = ImagePath(MountDir, RMS_REGISTRY_DIR);
    RmsMakeDirectories(State);
    free(State);

    if (!ImageFindArch(MountDir, Arch, ARRAYSIZE(Arch)))
        RmsInfo(L"No setup tree in the image, files go into reactos\\ only");

    /* A remounted image keeps its driver key counter */
    {
        WCHAR Next[32];

        ImageGet(MountDir, L"NextDriverKey", Next, ARRAYSIZE(Next));
        if (!Next[0])
        {
            swprintf_s(Next, ARRAYSIZE(Next), L"0x%x", RMS_FIRST_DRIVER_KEY);
            ImageSet(MountDir, L"NextDriverKey", Next);
        }
    }
    ImageSet(MountDir, L"VolumeId", VolumeId[0] ? VolumeId : L"ReactOS");
    ImageSet(MountDir, L"Arch", Arch);

    RmsInfo(L"Mounted %s at %s (volume %s, setup tree %s)", ImageFile, MountDir,
            VolumeId, Arch[0] ? Arch : L"none");
    return 0;
}

/* A package from the driver build: files laid out like the boot media and registry INFs */
int
RmsAddPackage(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR PackagePath)
{
    PWSTR Files, Registry, Order, Text;
    WCHAR Arch[64];
    BOOL Ok = TRUE;

    if (!ImageMounted(MountDir))
        return 1;

    Files = RmsJoin(PackagePath, L"reactos");
    if (RmsDirectoryExists(Files))
    {
        PWSTR Live = RmsJoin(MountDir, L"reactos");

        Ok = RmsCopyTree(Files, Live);
        free(Live);

        ImageGet(MountDir, L"Arch", Arch, ARRAYSIZE(Arch));
        if (Arch[0])
        {
            PWSTR Setup = RmsJoin(MountDir, Arch);

            Ok = RmsCopyTree(Files, Setup) && Ok;
            free(Setup);
        }
    }
    free(Files);

    Registry = RmsJoin(PackagePath, L"registry");
    Order = RmsJoin(Registry, L"ORDER");
    Text = RmsReadText(Order);
    if (Text)
    {
        PWSTR Line, Context = NULL;

        for (Line = wcstok_s(Text, L"\r\n", &Context); Line; Line = wcstok_s(NULL, L"\r\n", &Context))
        {
            PWSTR Source = RmsJoin(Registry, Line);

            Ok = RmsRegisterInf(MountDir, Line, Source, NULL) && Ok;
            RmsInfo(L"  registry %s", Line);
            free(Source);
        }
        free(Text);
    }
    free(Order);
    free(Registry);

    RmsInfo(Ok ? L"Package %s added" : L"Package %s added with errors", PackagePath);
    return Ok ? 0 : 1;
}

int
RmsAddRegistry(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR InfPath)
{
    PCWSTR Name = wcsrchr(InfPath, L'\\');

    if (!ImageMounted(MountDir))
        return 1;

    Name = Name ? Name + 1 : InfPath;
    if (!RmsRegisterInf(MountDir, Name, InfPath, NULL))
        return 1;

    RmsInfo(L"Registry %s added", Name);
    return 0;
}

static
BOOL
AddDriverInf(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR InfPath,
    _In_ const RMS_DRIVER_OPTIONS *Options)
{
    WCHAR Text[32];
    ULONG Next;
    BOOL Ok;

    ImageGet(MountDir, L"NextDriverKey", Text, ARRAYSIZE(Text));
    Next = Text[0] ? wcstoul(Text, NULL, 0) : RMS_FIRST_DRIVER_KEY;

    Ok = RmsTranslateDriver(MountDir, InfPath, Options, &Next);

    swprintf_s(Text, ARRAYSIZE(Text), L"0x%lx", Next);
    ImageSet(MountDir, L"NextDriverKey", Text);
    return Ok;
}

typedef struct _ADD_FOLDER
{
    PCWSTR MountDir;
    BOOL Recurse;
    const RMS_DRIVER_OPTIONS *Options;
    RMS_PROMPT_ROUTINE Prompt;
    PVOID PromptContext;
    BOOL InstallAll;
    BOOL Cancelled;
    BOOL Extensions;
    ULONG Added;
} ADD_FOLDER, *PADD_FOLDER;

/* One INF of a folder: described first, so the prompt can show what it would install */
static
VOID
AddFolderInf(
    _Inout_ PADD_FOLDER Folder,
    _In_z_ PCWSTR InfPath)
{
    RMS_DRIVER_OPTIONS Options = *Folder->Options;
    RMS_TEXT Summary = { 0 };
    RMS_CHOICE Choice = RmsChoiceInstall;
    ULONG Scratch = RMS_FIRST_DRIVER_KEY;

    /* Extensions go in on the second pass, once the drivers they extend are there */
    if (RmsIsExtensionInf(InfPath) != Folder->Extensions)
        return;

    Options.DryRun = TRUE;
    Options.Summary = &Summary;
    if (!RmsTranslateDriver(Folder->MountDir, InfPath, &Options, &Scratch))
    {
        /* Nothing in it for the devices asked for, or not a driver INF at all */
        RmsTextFree(&Summary);
        return;
    }

    if (Folder->Prompt && !Folder->InstallAll)
    {
        Choice = Folder->Prompt(InfPath, Summary.Buffer ? Summary.Buffer : L"", Folder->PromptContext);
        if (Choice == RmsChoiceInstallAll)
        {
            Folder->InstallAll = TRUE;
            Choice = RmsChoiceInstall;
        }
    }
    RmsTextFree(&Summary);

    if (Choice == RmsChoiceCancel)
    {
        Folder->Cancelled = TRUE;
        return;
    }
    if (Choice == RmsChoiceSkip)
        return;

    Options = *Folder->Options;
    Options.BootStart = Options.BootStart || Choice == RmsChoiceBootStart;
    if (AddDriverInf(Folder->MountDir, InfPath, &Options))
        Folder->Added++;
}

static
VOID
AddDriverFolder(
    _Inout_ PADD_FOLDER Folder,
    _In_z_ PCWSTR Path)
{
    WIN32_FIND_DATAW Find;
    PWSTR Pattern = RmsJoin(Path, L"*");
    HANDLE Handle = FindFirstFileW(Pattern, &Find);

    free(Pattern);
    if (Handle == INVALID_HANDLE_VALUE)
        return;

    do
    {
        PWSTR Child;
        SIZE_T Length = wcslen(Find.cFileName);

        if (Find.cFileName[0] == L'.')
            continue;

        Child = RmsJoin(Path, Find.cFileName);
        if (Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (Folder->Recurse)
                AddDriverFolder(Folder, Child);
        }
        else if (Length > 4 && !_wcsicmp(Find.cFileName + Length - 4, L".inf"))
        {
            AddFolderInf(Folder, Child);
        }
        free(Child);
    } while (!Folder->Cancelled && FindNextFileW(Handle, &Find));

    FindClose(Handle);
}

/**
 * @brief Installs a driver INF, or every driver INF of a folder.
 *
 * @param[in] Prompt
 * Asked about each INF of a folder before it goes in, NULL installs them all.
 */
int
RmsAddDriver(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR DriverPath,
    _In_ BOOL Recurse,
    _In_ const RMS_DRIVER_OPTIONS *Options,
    _In_opt_ RMS_PROMPT_ROUTINE Prompt,
    _In_opt_ PVOID PromptContext)
{
    if (!ImageMounted(MountDir))
        return 1;

    if (RmsDirectoryExists(DriverPath))
    {
        ADD_FOLDER Folder;

        ZeroMemory(&Folder, sizeof(Folder));
        Folder.MountDir = MountDir;
        Folder.Recurse = Recurse;
        Folder.Options = Options;
        Folder.Prompt = Prompt;
        Folder.PromptContext = PromptContext;
        AddDriverFolder(&Folder, DriverPath);
        Folder.Extensions = TRUE;
        if (!Folder.Cancelled)
            AddDriverFolder(&Folder, DriverPath);

        RmsInfo(L"%lu driver package(s) added from %s%s", Folder.Added, DriverPath,
                Folder.Cancelled ? L", stopped on request" : L"");
        return Folder.Added ? 0 : 1;
    }

    return AddDriverInf(MountDir, DriverPath, Options) ? 0 : 1;
}

/* Firmware a driver loads by path: into system32\drivers unless another folder is given */
int
RmsAddFirmware(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Source,
    _In_opt_z_ PCWSTR Destination)
{
    PCWSTR Relative = (Destination && Destination[0]) ? Destination : L"system32\\drivers";
    WCHAR Arch[64];
    BOOL Ok = TRUE;

    if (!ImageMounted(MountDir))
        return 1;

    if (RmsFileExists(Source))
    {
        Ok = RmsStageSystemFile(MountDir, Source, Relative, NULL);
    }
    else if (RmsDirectoryExists(Source))
    {
        WCHAR Target[MAX_PATH * 2];

        /* A folder keeps its layout below the destination, like MCFG\... does */
        swprintf_s(Target, ARRAYSIZE(Target), L"%s\\reactos\\%s", MountDir, Relative);
        Ok = RmsCopyTree(Source, Target);

        ImageGet(MountDir, L"Arch", Arch, ARRAYSIZE(Arch));
        if (Arch[0])
        {
            swprintf_s(Target, ARRAYSIZE(Target), L"%s\\%s\\%s", MountDir, Arch, Relative);
            Ok = RmsCopyTree(Source, Target) && Ok;
        }
    }
    else
    {
        RmsError(L"%s does not exist", Source);
        return 1;
    }

    RmsInfo(Ok ? L"Firmware %s added to %s" : L"Firmware %s added to %s with errors", Source, Relative);
    return Ok ? 0 : 1;
}

/*
 * A slipstream overlay. One laid out like a driver tree maps drivers\ to
 * system32\drivers, system32\ to system32 and root\ to the system root; any other
 * layout is taken relative to the system root as it is.
 */
int
RmsAddOverlay(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Overlay)
{
    static PCWSTR Mapped[][2] = { { L"drivers", L"system32\\drivers" }, { L"system32", L"system32" }, { L"root", L"" } };
    PWSTR Drivers = RmsJoin(Overlay, L"drivers");
    PWSTR Root = RmsJoin(Overlay, L"root");
    BOOL TreeLayout = RmsDirectoryExists(Drivers) || RmsDirectoryExists(Root);
    ULONG Index;
    int Result = 0;

    free(Drivers);
    free(Root);
    if (!ImageMounted(MountDir))
        return 1;

    if (!TreeLayout)
        return RmsAddFirmware(MountDir, Overlay, L"");

    for (Index = 0; Index < ARRAYSIZE(Mapped); Index++)
    {
        PWSTR Folder = RmsJoin(Overlay, Mapped[Index][0]);

        if (RmsDirectoryExists(Folder))
            Result |= RmsAddFirmware(MountDir, Folder, Mapped[Index][1]);
        free(Folder);
    }
    return Result;
}

/* The driver key a hardware id was installed with, so extension INFs find the device they extend */
BOOL
RmsSetDeviceKey(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR DeviceId,
    _In_z_ PCWSTR DriverKey)
{
    PWSTR Ini = ImagePath(MountDir, RMS_DEVICES_INI);
    BOOL Ok = WritePrivateProfileStringW(L"DriverKeys", DeviceId, DriverKey, Ini);

    free(Ini);
    return Ok;
}

/**
 * @brief Gets every recorded id=driverkey pair, as a double null terminated list the caller frees.
 */
PWSTR
RmsGetDeviceKeys(
    _In_z_ PCWSTR MountDir)
{
    PWSTR Ini = ImagePath(MountDir, RMS_DEVICES_INI);
    DWORD Size = 0x8000, Length;
    PWSTR List = NULL;

    for (;;)
    {
        free(List);
        List = malloc(Size * sizeof(*List));
        if (!List)
            break;

        Length = GetPrivateProfileSectionW(L"DriverKeys", List, Size, Ini);
        if (Length < Size - 2)
            break;
        Size *= 2;
    }

    free(Ini);
    return List;
}

BOOL
RmsIsMounted(
    _In_z_ PCWSTR MountDir)
{
    PWSTR Ini = ImagePath(MountDir, RMS_IMAGE_INI);
    BOOL Mounted = RmsFileExists(Ini);

    free(Ini);
    return Mounted;
}

/* The driver services of the image's live SYSTEM hive, as it was last built */
int
RmsListServices(
    _In_z_ PCWSTR MountDir,
    _In_ RMS_SERVICE_ROUTINE Routine,
    _In_opt_ PVOID Context)
{
    PWSTR Hive = ImagePath(MountDir, L"reactos\\system32\\config\\system");
    PWSTR Root = ImagePath(MountDir, L"");
    BOOL Ok = RmsEnumServices(Hive, Root, Routine, Context);

    free(Hive);
    free(Root);
    return Ok ? 0 : 1;
}

int
RmsGetDrivers(
    _In_z_ PCWSTR MountDir)
{
    PWSTR Order, Text, Line, Context = NULL;
    ULONG Count = 0;

    if (!ImageMounted(MountDir))
        return 1;

    Order = ImagePath(MountDir, RMS_ORDER_FILE);
    Text = RmsReadText(Order);
    free(Order);

    RmsInfo(L"Registry INFs merged into the hives, in order:");
    for (Line = Text ? wcstok_s(Text, L"\r\n", &Context) : NULL; Line; Line = wcstok_s(NULL, L"\r\n", &Context))
        RmsInfo(L"  %2lu. %s", ++Count, Line);
    if (!Count)
        RmsInfo(L"  none");

    free(Text);
    return 0;
}

/* " path" appended to a command line */
static
VOID
AppendQuoted(
    _Inout_ PRMS_TEXT Command,
    _In_z_ PCWSTR Path)
{
    RmsTextAppendF(Command, L" \"%s\"", Path);
}

/* The added INFs, after the ones the image was built from */
static
BOOL
AppendAddedInfs(
    _In_z_ PCWSTR MountDir,
    _Inout_ PRMS_TEXT Command)
{
    PWSTR Order = ImagePath(MountDir, RMS_ORDER_FILE);
    PWSTR Registry = ImagePath(MountDir, RMS_REGISTRY_DIR);
    PWSTR Text = RmsReadText(Order);
    PWSTR Line, Context = NULL;
    BOOL Ok = TRUE;

    for (Line = Text ? wcstok_s(Text, L"\r\n", &Context) : NULL; Line; Line = wcstok_s(NULL, L"\r\n", &Context))
    {
        PWSTR Inf = RmsJoin(Registry, Line);

        if (!RmsFileExists(Inf))
        {
            RmsError(L"%s is listed but missing", Inf);
            Ok = FALSE;
        }
        AppendQuoted(Command, Inf);
        free(Inf);
    }

    free(Text);
    free(Registry);
    free(Order);
    return Ok;
}

static
BOOL
BuildHives(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Arch,
    _In_z_ PCWSTR WorkDir)
{
    RMS_TEXT Command = { 0 };
    WCHAR Setup[MAX_PATH * 2], Path[MAX_PATH * 2];
    PWSTR Registry;
    ULONG Index;
    BOOL Ok;

    /* The base registry the build concatenated, and the hive sources it shipped beside it */
    swprintf_s(Setup, ARRAYSIZE(Setup), L"%s\\%s", MountDir, Arch);
    Registry = RmsJoin(Setup, L"registry.inf");
    if (!RmsFileExists(Registry))
    {
        RmsError(L"%s is missing, the image cannot have its hives built again", Registry);
        free(Registry);
        return FALSE;
    }

    for (Index = 0; Index < ARRAYSIZE(LiveSources); Index++)
    {
        swprintf_s(Path, ARRAYSIZE(Path), L"%s\\hives\\%s", Setup, LiveSources[Index]);
        if (!RmsFileExists(Path))
        {
            RmsError(L"%s is missing; the image has to come from a build that ships its hive sources", Path);
            free(Registry);
            return FALSE;
        }
    }

    /* The live environment's hives */
    RmsTextAppendF(&Command, L"\"%s\" -h:SYSTEM,SOFTWARE,DEFAULT,SAM,SECURITY -d:\"%s\"", RmsToolPath(L"mkhive.exe"), WorkDir);
    AppendQuoted(&Command, Registry);
    for (Index = 0; Index < ARRAYSIZE(LiveSources); Index++)
    {
        swprintf_s(Path, ARRAYSIZE(Path), L"%s\\hives\\%s", Setup, LiveSources[Index]);
        AppendQuoted(&Command, Path);
    }
    Ok = AppendAddedInfs(MountDir, &Command) && RmsRun(Command.Buffer);
    RmsTextFree(&Command);

    for (Index = 0; Ok && Index < ARRAYSIZE(LiveHives); Index++)
    {
        WCHAR From[MAX_PATH * 2], To[MAX_PATH * 2];

        swprintf_s(From, ARRAYSIZE(From), L"%s\\%s", WorkDir, LiveHives[Index]);
        swprintf_s(To, ARRAYSIZE(To), L"%s\\reactos\\system32\\config\\%s", MountDir, LiveHives[Index]);
        Ok = RmsCopyFileTo(From, To);
    }

    /* Text mode setup's hive */
    swprintf_s(Path, ARRAYSIZE(Path), L"%s\\hives\\setupreg.inf", Setup);
    if (Ok && RmsFileExists(Path))
    {
        WCHAR From[MAX_PATH * 2], To[MAX_PATH * 2];

        RmsTextAppendF(&Command, L"\"%s\" -h:SETUPREG -u -d:\"%s\"", RmsToolPath(L"mkhive.exe"), WorkDir);
        AppendQuoted(&Command, Registry);
        AppendQuoted(&Command, Path);
        Ok = AppendAddedInfs(MountDir, &Command) && RmsRun(Command.Buffer);
        RmsTextFree(&Command);

        swprintf_s(From, ARRAYSIZE(From), L"%s\\SETUPREG.HIV", WorkDir);
        swprintf_s(To, ARRAYSIZE(To), L"%s\\SETUPREG.HIV", Setup);
        Ok = Ok && RmsCopyFileTo(From, To);
    }

    free(Registry);
    return Ok;
}

/* Builds the hives again and writes the image back out as a UEFI bootable ISO */
int
RmsCommitImage(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR ImageFile)
{
    RMS_TEXT Command = { 0 };
    WCHAR Arch[64], VolumeId[64], Work[MAX_PATH * 2], Temp[MAX_PATH];
    PWSTR Root, Boot;
    BOOL Ok;

    if (!ImageMounted(MountDir))
        return 1;

    ImageGet(MountDir, L"Arch", Arch, ARRAYSIZE(Arch));
    ImageGet(MountDir, L"VolumeId", VolumeId, ARRAYSIZE(VolumeId));
    if (!Arch[0])
    {
        RmsError(L"the image has no setup tree to take its registry from");
        return 1;
    }

    GetTempPathW(ARRAYSIZE(Temp), Temp);
    swprintf_s(Work, ARRAYSIZE(Work), L"%srmsetup-%lu", Temp, GetCurrentProcessId());
    RmsMakeDirectories(Work);

    RmsInfo(L"Building the hives");
    Root = ImagePath(MountDir, L"");
    if (!BuildHives(Root, Arch, Work))
    {
        free(Root);
        return 1;
    }

    Boot = RmsJoin(Root, L"loader\\efisys.bin");
    if (!RmsFileExists(Boot))
    {
        RmsError(L"%s is missing, the image would not boot", Boot);
        free(Boot);
        free(Root);
        return 1;
    }
    free(Boot);

    /* The same layout the ReactOS build writes */
    RmsInfo(L"Writing %s", ImageFile);
    RmsTextAppendF(&Command,
                   L"\"%s\" -quiet -o \"%s\" -iso-level 4 -publisher \"ReactOS Project\" -preparer \"ReactOS Project\""
                   L" -volid \"%s\" -volset \"%s\" -eltorito-platform efi -eltorito-boot loader/efisys.bin"
                   L" -no-emul-boot -hide boot.catalog -duplicates-once -no-cache-inodes \"%s\"",
                   RmsToolPath(L"mkisofs.exe"), ImageFile, VolumeId, VolumeId, Root);
    Ok = RmsRun(Command.Buffer);
    RmsTextFree(&Command);
    free(Root);

    if (Ok)
        RmsInfo(L"Committed %s", ImageFile);
    return Ok ? 0 : 1;
}
