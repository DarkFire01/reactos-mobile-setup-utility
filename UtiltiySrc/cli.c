/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Text mode front end, DISM style commands and an interactive menu
 */

#include "rmsetup.h"
#include <io.h>
#include <fcntl.h>

#define MAX_LIST    64

static
VOID
Usage(VOID)
{
    wprintf(L"ReactOS Mobile Setup Utility\n\n"
            L"Without arguments it runs an interactive menu. Commands:\n\n"
            L"  rmsetup /Mount-Image /ImageFile:<iso> /MountDir:<dir>\n"
            L"  rmsetup /Get-Drivers /MountDir:<dir> [/All]\n"
            L"  rmsetup /Add-Driver /MountDir:<dir> /Driver:<inf or folder> [/Recurse] [/Prompt]\n"
            L"          [/Device:<hardware id>]... [/Instance:<instance path>]... [/BootStart] [/DriverKey:<n>]\n"
            L"  rmsetup /Add-Package /MountDir:<dir> /PackagePath:<package>\n"
            L"  rmsetup /Add-Firmware /MountDir:<dir> /Source:<file or folder> [/Destination:<system root folder>]\n"
            L"  rmsetup /Add-Overlay /MountDir:<dir> /Source:<folder>\n"
            L"  rmsetup /Add-Registry /MountDir:<dir> /Inf:<registry inf>\n"
            L"  rmsetup /Commit-Image /MountDir:<dir> /ImageFile:<iso>\n");
}

/* /Name:value, or NULL when the argument is something else */
static
PCWSTR
Option(
    _In_z_ PCWSTR Argument,
    _In_z_ PCWSTR Name)
{
    SIZE_T Length = wcslen(Name);

    if ((Argument[0] == L'/' || Argument[0] == L'-') && !_wcsnicmp(Argument + 1, Name, Length) &&
        Argument[1 + Length] == L':')
    {
        return Argument + 2 + Length;
    }
    return NULL;
}

static
BOOL
Switch(
    _In_z_ PCWSTR Argument,
    _In_z_ PCWSTR Name)
{
    return (Argument[0] == L'/' || Argument[0] == L'-') && !_wcsicmp(Argument + 1, Name);
}

static
PCWSTR
StartName(
    _In_ ULONG Start)
{
    static PCWSTR Names[] = { L"boot", L"system", L"auto", L"demand", L"disabled" };

    return Start < ARRAYSIZE(Names) ? Names[Start] : L"?";
}

typedef struct _LIST_CONTEXT
{
    BOOL All;
    ULONG Count;
} LIST_CONTEXT;

static
VOID
PrintService(
    _In_ const RMS_SERVICE *Service,
    _In_opt_ PVOID Context)
{
    LIST_CONTEXT *List = Context;

    if (!List->All && Service->Start > SERVICE_DEMAND_START)
        return;

    List->Count++;
    wprintf(L"  %-24s %-8s %-22s %s%s\n", Service->Name, StartName(Service->Start), Service->Group,
            Service->ImagePath[0] ? Service->ImagePath : L"(default image)",
            Service->Present ? L"" : L"  [file missing]");
}

static
int
ListDrivers(
    _In_z_ PCWSTR MountDir,
    _In_ BOOL All)
{
    LIST_CONTEXT List = { All, 0 };
    int Result;

    wprintf(L"Drivers in the image's SYSTEM hive%s:\n", All ? L"" : L" (disabled ones left out, /All lists them)");
    wprintf(L"  %-24s %-8s %-22s %s\n", L"Service", L"Start", L"Group", L"Image");
    Result = RmsListServices(MountDir, PrintService, &List);
    wprintf(L"%lu driver(s)\n\n", List.Count);
    RmsGetDrivers(MountDir);
    return Result;
}

/* Asks about one driver INF on the console */
static
RMS_CHOICE
ConsolePrompt(
    _In_z_ PCWSTR InfPath,
    _In_z_ PCWSTR Summary,
    _In_opt_ PVOID Context)
{
    WCHAR Answer[16];

    UNREFERENCED_PARAMETER(Context);

    wprintf(L"\n%s\n%s", InfPath, Summary);
    for (;;)
    {
        wprintf(L"Install? [y]es, [b]oot start, [n]o, [a]ll remaining, [q]uit: ");
        if (!fgetws(Answer, ARRAYSIZE(Answer), stdin))
            return RmsChoiceCancel;

        switch (towlower(Answer[0]))
        {
            case L'y': return RmsChoiceInstall;
            case L'b': return RmsChoiceBootStart;
            case L'n': return RmsChoiceSkip;
            case L'a': return RmsChoiceInstallAll;
            case L'q': return RmsChoiceCancel;
        }
    }
}

static
VOID
Ask(
    _In_z_ PCWSTR Question,
    _Out_writes_z_(Size) PWSTR Answer,
    _In_ SIZE_T Size)
{
    SIZE_T Length;

    wprintf(L"%s", Question);
    if (!fgetws(Answer, (int)Size, stdin))
    {
        Answer[0] = UNICODE_NULL;
        return;
    }

    Length = wcslen(Answer);
    while (Length && (Answer[Length - 1] == L'\n' || Answer[Length - 1] == L'\r'))
        Answer[--Length] = UNICODE_NULL;

    /* Paths pasted from Explorer come quoted */
    if (Length >= 2 && Answer[0] == L'"' && Answer[Length - 1] == L'"')
    {
        memmove(Answer, Answer + 1, (Length - 2) * sizeof(WCHAR));
        Answer[Length - 2] = UNICODE_NULL;
    }
}

/* The menu remembers the mounted image between steps */
static
int
Interactive(VOID)
{
    WCHAR MountDir[MAX_PATH] = L"", Input[MAX_PATH], Second[MAX_PATH];
    RMS_DRIVER_OPTIONS Options;

    for (;;)
    {
        wprintf(L"\nReactOS Mobile Setup Utility%s%s\n"
                L"  1  Mount an ISO image\n"
                L"  2  Use an already mounted image folder\n"
                L"  3  List the image's drivers\n"
                L"  4  Add drivers from a folder, asking about each\n"
                L"  5  Add one driver INF\n"
                L"  6  Add a driver package built by build.cmd\n"
                L"  7  Add firmware\n"
                L"  8  Add a slipstream overlay\n"
                L"  9  Add a registry INF\n"
                L"  c  Commit the image to an ISO\n"
                L"  q  Quit\n",
                MountDir[0] ? L", image: " : L"", MountDir);
        Ask(L"> ", Input, ARRAYSIZE(Input));

        if (Input[0] == L'q' || Input[0] == L'Q')
            return 0;

        if (Input[0] == L'1')
        {
            Ask(L"ISO image: ", Input, ARRAYSIZE(Input));
            Ask(L"Folder to mount it in: ", MountDir, ARRAYSIZE(MountDir));
            if (RmsMountImage(Input, MountDir))
                MountDir[0] = UNICODE_NULL;
            continue;
        }

        if (Input[0] == L'2')
        {
            Ask(L"Mounted image folder: ", MountDir, ARRAYSIZE(MountDir));
            if (!RmsIsMounted(MountDir))
            {
                RmsError(L"%s is not a mounted image", MountDir);
                MountDir[0] = UNICODE_NULL;
            }
            continue;
        }

        if (!MountDir[0])
        {
            RmsError(L"mount an image first");
            continue;
        }

        ZeroMemory(&Options, sizeof(Options));
        switch (towlower(Input[0]))
        {
            case L'3':
                ListDrivers(MountDir, FALSE);
                break;

            case L'4':
                Ask(L"Driver folder (searched with its subfolders): ", Input, ARRAYSIZE(Input));
                RmsAddDriver(MountDir, Input, TRUE, &Options, ConsolePrompt, NULL);
                break;

            case L'5':
            {
                PCWSTR Devices[1];

                Ask(L"Driver INF: ", Input, ARRAYSIZE(Input));
                Ask(L"Hardware id to install for (empty for all): ", Second, ARRAYSIZE(Second));
                if (Second[0])
                {
                    Devices[0] = Second;
                    Options.Devices = Devices;
                    Options.DeviceCount = 1;
                }
                RmsAddDriver(MountDir, Input, FALSE, &Options, NULL, NULL);
                break;
            }

            case L'6':
                Ask(L"Package folder: ", Input, ARRAYSIZE(Input));
                RmsAddPackage(MountDir, Input);
                break;

            case L'7':
                Ask(L"Firmware file or folder: ", Input, ARRAYSIZE(Input));
                Ask(L"Folder under the system root (empty for system32\\drivers): ", Second, ARRAYSIZE(Second));
                RmsAddFirmware(MountDir, Input, Second);
                break;

            case L'8':
                Ask(L"Overlay folder: ", Input, ARRAYSIZE(Input));
                RmsAddOverlay(MountDir, Input);
                break;

            case L'9':
                Ask(L"Registry INF: ", Input, ARRAYSIZE(Input));
                RmsAddRegistry(MountDir, Input);
                break;

            case L'c':
                Ask(L"ISO image to write: ", Input, ARRAYSIZE(Input));
                RmsCommitImage(MountDir, Input);
                break;
        }
    }
}

int
wmain(
    int argc,
    PWSTR argv[])
{
    PCWSTR Command, ImageFile = NULL, MountDir = NULL, Driver = NULL, Package = NULL;
    PCWSTR Inf = NULL, Source = NULL, Destination = NULL, Value;
    PCWSTR Devices[MAX_LIST], Instances[MAX_LIST];
    RMS_DRIVER_OPTIONS Options;
    BOOL Recurse = FALSE, Prompt = FALSE, All = FALSE;
    int Index;

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    if (argc < 2)
        return Interactive();

    ZeroMemory(&Options, sizeof(Options));
    Options.Devices = Devices;
    Options.Instances = Instances;

    Command = argv[1];
    for (Index = 2; Index < argc; Index++)
    {
        PCWSTR Arg = argv[Index];

        if ((Value = Option(Arg, L"ImageFile")) != NULL)
            ImageFile = Value;
        else if ((Value = Option(Arg, L"MountDir")) != NULL)
            MountDir = Value;
        else if ((Value = Option(Arg, L"Driver")) != NULL)
            Driver = Value;
        else if ((Value = Option(Arg, L"PackagePath")) != NULL)
            Package = Value;
        else if ((Value = Option(Arg, L"Inf")) != NULL)
            Inf = Value;
        else if ((Value = Option(Arg, L"Source")) != NULL)
            Source = Value;
        else if ((Value = Option(Arg, L"Destination")) != NULL)
            Destination = Value;
        else if ((Value = Option(Arg, L"Device")) != NULL && Options.DeviceCount < MAX_LIST)
            Devices[Options.DeviceCount++] = Value;
        else if ((Value = Option(Arg, L"Instance")) != NULL && Options.InstanceCount < MAX_LIST)
            Instances[Options.InstanceCount++] = Value;
        else if ((Value = Option(Arg, L"DriverKey")) != NULL)
            Options.DriverKey = wcstoul(Value, NULL, 0);
        else if (Switch(Arg, L"Recurse"))
            Recurse = TRUE;
        else if (Switch(Arg, L"Prompt"))
            Prompt = TRUE;
        else if (Switch(Arg, L"BootStart"))
            Options.BootStart = TRUE;
        else if (Switch(Arg, L"All"))
            All = TRUE;
        else
        {
            RmsError(L"unknown argument %s", Arg);
            Usage();
            return 1;
        }
    }

    if (Switch(Command, L"?") || Switch(Command, L"Help"))
    {
        Usage();
        return 0;
    }

    if (!MountDir)
    {
        RmsError(L"/MountDir is needed");
        Usage();
        return 1;
    }

    if (Switch(Command, L"Mount-Image") && ImageFile)
        return RmsMountImage(ImageFile, MountDir);
    if (Switch(Command, L"Get-Drivers"))
        return ListDrivers(MountDir, All);
    if (Switch(Command, L"Add-Driver") && Driver)
        return RmsAddDriver(MountDir, Driver, Recurse, &Options, Prompt ? ConsolePrompt : NULL, NULL);
    if (Switch(Command, L"Add-Package") && Package)
        return RmsAddPackage(MountDir, Package);
    if (Switch(Command, L"Add-Firmware") && Source)
        return RmsAddFirmware(MountDir, Source, Destination);
    if (Switch(Command, L"Add-Overlay") && Source)
        return RmsAddOverlay(MountDir, Source);
    if (Switch(Command, L"Add-Registry") && Inf)
        return RmsAddRegistry(MountDir, Inf);
    if (Switch(Command, L"Commit-Image") && ImageFile)
        return RmsCommitImage(MountDir, ImageFile);

    RmsError(L"%s is not a command, or misses an argument", Command);
    Usage();
    return 1;
}
