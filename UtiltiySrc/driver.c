/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Installs a Windows driver INF into an image the way setup would
 */

/*
 * Nothing runs a class installer while the image boots, so everything setup would
 * write for the driver is written ahead into a registry INF: the services, the
 * KMDF version, a driver key under the class, a critical device database entry per
 * hardware id and, for instances named on the command line, the Enum keys. The
 * files the install section copies are staged into the image.
 */

#include "rmsetup.h"
#include <setupapi.h>

#define INF_MAX_SECTIONS    4096
#define INF_MAX_STRINGS     2048
#define INF_MAX_FIELDS      32
#define INF_FIELD_MAX       1024

#define REG_SERVICES        L"SYSTEM\\CurrentControlSet\\Services\\"
#define REG_CLASS           L"SYSTEM\\CurrentControlSet\\Control\\Class\\"
#define REG_CDDB            L"SYSTEM\\CurrentControlSet\\Control\\CriticalDeviceDatabase\\"
#define REG_ENUM            L"SYSTEM\\CurrentControlSet\\Enum\\"

/* Class of extension INFs */
#define RMS_EXTENSION_CLASS L"{E2F84CE7-8EFA-411C-AA69-97454CA4CB57}"

/* INF platform name of the image being serviced (arm64, amd64 or x86), picked per INF */
static WCHAR InfPlatform[16] = L"arm64";

typedef struct _INF_SECTION
{
    PWSTR Name;
    PWSTR *Lines;
    ULONG Count;
    ULONG Capacity;
} INF_SECTION, *PINF_SECTION;

typedef struct _INF_STRING
{
    PWSTR Key;
    PWSTR Value;
} INF_STRING;

typedef struct _INF_FILE
{
    PWSTR Text;
    INF_SECTION Sections[INF_MAX_SECTIONS];
    ULONG SectionCount;
    INF_STRING Strings[INF_MAX_STRINGS];
    ULONG StringCount;
} INF_FILE, *PINF_FILE;

typedef struct _INF_FIELDS
{
    WCHAR Field[INF_MAX_FIELDS][INF_FIELD_MAX];
    ULONG Count;
} INF_FIELDS, *PINF_FIELDS;

static
PINF_SECTION
InfSection(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR Name)
{
    ULONG Index;

    for (Index = 0; Index < Inf->SectionCount; Index++)
    {
        if (!_wcsicmp(Inf->Sections[Index].Name, Name))
            return &Inf->Sections[Index];
    }
    return NULL;
}

static
VOID
InfAddLine(
    _Inout_ PINF_SECTION Section,
    _In_z_ PWSTR Line)
{
    if (Section->Count == Section->Capacity)
    {
        Section->Capacity = Section->Capacity ? Section->Capacity * 2 : 16;
        Section->Lines = realloc(Section->Lines, Section->Capacity * sizeof(PWSTR));
        if (!Section->Lines)
            exit(1);
    }
    Section->Lines[Section->Count++] = Line;
}

/* Cuts a comment off a line, ; inside quotes is text */
static
VOID
InfStripComment(
    _Inout_z_ PWSTR Line)
{
    BOOL Quoted = FALSE;

    for (; *Line; Line++)
    {
        if (*Line == L'"')
            Quoted = !Quoted;
        else if (*Line == L';' && !Quoted)
        {
            *Line = UNICODE_NULL;
            return;
        }
    }
}

static
PWSTR
InfTrim(
    _Inout_z_ PWSTR Text)
{
    PWSTR End;

    while (*Text == L' ' || *Text == L'\t')
        Text++;
    End = Text + wcslen(Text);
    while (End > Text && (End[-1] == L' ' || End[-1] == L'\t' || End[-1] == L'\r'))
        *--End = UNICODE_NULL;
    return Text;
}

static
VOID
InfUnquote(
    _Inout_z_ PWSTR Text)
{
    SIZE_T Length = wcslen(Text);

    if (Length >= 2 && Text[0] == L'"' && Text[Length - 1] == L'"')
    {
        memmove(Text, Text + 1, (Length - 2) * sizeof(WCHAR));
        Text[Length - 2] = UNICODE_NULL;
    }
}

static
BOOL
InfLoad(
    _In_z_ PCWSTR Path,
    _Out_ PINF_FILE Inf)
{
    PINF_SECTION Current = NULL;
    PWSTR Line, Next;

    ZeroMemory(Inf, sizeof(*Inf));
    Inf->Text = RmsReadText(Path);
    if (!Inf->Text)
    {
        RmsError(L"cannot read %s", Path);
        return FALSE;
    }

    for (Line = Inf->Text; Line; Line = Next)
    {
        PWSTR Trimmed;

        Next = wcschr(Line, L'\n');
        if (Next)
            *Next++ = UNICODE_NULL;

        InfStripComment(Line);
        Trimmed = InfTrim(Line);
        if (!*Trimmed)
            continue;

        if (Trimmed[0] == L'[')
        {
            PWCHAR Close = wcschr(Trimmed, L']');

            if (!Close)
                continue;

            /* Dropping sections would install a partial driver, so refuse the INF instead */
            if (Inf->SectionCount == INF_MAX_SECTIONS)
            {
                ULONG Index;

                RmsError(L"%s has more than %u sections", Path, INF_MAX_SECTIONS);
                for (Index = 0; Index < Inf->SectionCount; Index++)
                    free(Inf->Sections[Index].Lines);
                free(Inf->Text);
                Inf->Text = NULL;
                Inf->SectionCount = 0;
                return FALSE;
            }
            *Close = UNICODE_NULL;
            Current = &Inf->Sections[Inf->SectionCount++];
            Current->Name = InfTrim(Trimmed + 1);
            continue;
        }

        if (Current)
            InfAddLine(Current, Trimmed);
    }

    /* Strings, the standard numbers and the folders everything is staged into */
    {
        static PCWSTR Standard[][2] =
        {
            { L"SERVICE_KERNEL_DRIVER", L"1" }, { L"SERVICE_FILE_SYSTEM_DRIVER", L"2" },
            { L"SERVICE_WIN32_OWN_PROCESS", L"16" }, { L"SERVICE_BOOT_START", L"0" },
            { L"SERVICE_SYSTEM_START", L"1" }, { L"SERVICE_AUTO_START", L"2" },
            { L"SERVICE_DEMAND_START", L"3" }, { L"SERVICE_DISABLED", L"4" },
            { L"SERVICE_ERROR_IGNORE", L"0" }, { L"SERVICE_ERROR_NORMAL", L"1" },
            { L"SERVICE_ERROR_SEVERE", L"2" }, { L"SERVICE_ERROR_CRITICAL", L"3" },
            { L"SPSVCINST_ASSOCSERVICE", L"0x00000002" },
            { L"10", L"\\SystemRoot" }, { L"11", L"\\SystemRoot\\System32" },
            { L"12", L"\\SystemRoot\\System32\\drivers" }, { L"13", L"\\SystemRoot\\System32\\drivers" },
        };
        PINF_SECTION Strings = InfSection(Inf, L"Strings");
        ULONG Index;

        for (Index = 0; Index < ARRAYSIZE(Standard); Index++)
        {
            Inf->Strings[Inf->StringCount].Key = (PWSTR)Standard[Index][0];
            Inf->Strings[Inf->StringCount++].Value = (PWSTR)Standard[Index][1];
        }

        for (Index = 0; Strings && Index < Strings->Count && Inf->StringCount < INF_MAX_STRINGS; Index++)
        {
            PWSTR Equal = wcschr(Strings->Lines[Index], L'=');

            if (!Equal)
                continue;
            *Equal = UNICODE_NULL;
            Inf->Strings[Inf->StringCount].Key = InfTrim(Strings->Lines[Index]);
            Inf->Strings[Inf->StringCount].Value = InfTrim(Equal + 1);
            InfUnquote(Inf->Strings[Inf->StringCount].Value);
            Inf->StringCount++;
        }
    }

    return TRUE;
}

static
VOID
InfFree(
    _Inout_ PINF_FILE Inf)
{
    ULONG Index;

    for (Index = 0; Index < Inf->SectionCount; Index++)
        free(Inf->Sections[Index].Lines);
    free(Inf->Text);
}

/* Replaces %name% with its string, unknown names stay as they are */
static
VOID
InfExpand(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR Text,
    _Out_writes_z_(Size) PWSTR Out,
    _In_ SIZE_T Size)
{
    SIZE_T Used = 0;

    while (*Text && Used + 1 < Size)
    {
        PCWSTR Close;

        if (*Text == L'%' && (Close = wcschr(Text + 1, L'%')) != NULL && Close > Text + 1)
        {
            WCHAR Key[256];
            SIZE_T KeyLength = min((SIZE_T)(Close - Text - 1), ARRAYSIZE(Key) - 1);
            PCWSTR Value = NULL;
            ULONG Index;

            memcpy(Key, Text + 1, KeyLength * sizeof(WCHAR));
            Key[KeyLength] = UNICODE_NULL;
            for (Index = Inf->StringCount; Index-- > 0;)
            {
                if (!_wcsicmp(Inf->Strings[Index].Key, Key))
                {
                    Value = Inf->Strings[Index].Value;
                    break;
                }
            }

            if (Value)
            {
                while (*Value && Used + 1 < Size)
                    Out[Used++] = *Value++;
                Text = Close + 1;
                continue;
            }
        }

        Out[Used++] = *Text++;
    }
    Out[Used] = UNICODE_NULL;
}

/* Same as InfExpand, into text that grows with what it gets */
static
VOID
InfExpandText(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR Text,
    _Inout_ PRMS_TEXT Out)
{
    WCHAR Piece[2] = { 0 };

    while (*Text)
    {
        PCWSTR Close;

        if (*Text == L'%' && (Close = wcschr(Text + 1, L'%')) != NULL && Close > Text + 1)
        {
            WCHAR Key[256];
            SIZE_T KeyLength = min((SIZE_T)(Close - Text - 1), ARRAYSIZE(Key) - 1);
            ULONG Index;

            memcpy(Key, Text + 1, KeyLength * sizeof(WCHAR));
            Key[KeyLength] = UNICODE_NULL;
            for (Index = Inf->StringCount; Index-- > 0;)
            {
                if (!_wcsicmp(Inf->Strings[Index].Key, Key))
                    break;
            }

            if (Index != (ULONG)-1)
            {
                RmsTextAppend(Out, Inf->Strings[Index].Value);
                Text = Close + 1;
                continue;
            }
        }

        Piece[0] = *Text++;
        RmsTextAppend(Out, Piece);
    }
}

/*
 * Splits on commas outside quotes, each field trimmed; quotes stay. Stops after
 * Max fields and points Rest at what follows, NULL when the line ended first.
 */
static
VOID
InfSplitSome(
    _In_z_ PCWSTR Text,
    _Out_ PINF_FIELDS Fields,
    _In_ ULONG Max,
    _Out_opt_ PCWSTR *Rest)
{
    SIZE_T Used = 0;
    BOOL Quoted = FALSE;

    Fields->Count = 0;
    Fields->Field[0][0] = UNICODE_NULL;
    if (Rest)
        *Rest = NULL;

    for (;; Text++)
    {
        if (*Text == UNICODE_NULL || (*Text == L',' && !Quoted))
        {
            PWSTR Trimmed;

            Fields->Field[Fields->Count][Used] = UNICODE_NULL;
            Trimmed = InfTrim(Fields->Field[Fields->Count]);
            memmove(Fields->Field[Fields->Count], Trimmed, (wcslen(Trimmed) + 1) * sizeof(WCHAR));
            Fields->Count++;
            Used = 0;
            if (*Text == UNICODE_NULL)
                return;
            if (Fields->Count == Max)
            {
                if (Rest)
                    *Rest = Text + 1;
                return;
            }
            continue;
        }

        if (*Text == L'"')
            Quoted = !Quoted;
        if (Used + 1 < INF_FIELD_MAX)
            Fields->Field[Fields->Count][Used++] = *Text;
    }
}

static
VOID
InfSplit(
    _In_z_ PCWSTR Text,
    _Out_ PINF_FIELDS Fields)
{
    InfSplitSome(Text, Fields, INF_MAX_FIELDS, NULL);
}

/* key = value, the key and the value both trimmed; FALSE without an = */
static
BOOL
InfKeyValue(
    _In_z_ PCWSTR Line,
    _Out_writes_z_(KeySize) PWSTR Key,
    _In_ SIZE_T KeySize,
    _Out_writes_z_(ValueSize) PWSTR Value,
    _In_ SIZE_T ValueSize)
{
    PCWSTR Equal = wcschr(Line, L'=');
    WCHAR Buffer[INF_FIELD_MAX];
    SIZE_T Length;

    if (!Equal)
        return FALSE;

    Length = min((SIZE_T)(Equal - Line), ARRAYSIZE(Buffer) - 1);
    memcpy(Buffer, Line, Length * sizeof(WCHAR));
    Buffer[Length] = UNICODE_NULL;
    wcscpy_s(Key, KeySize, InfTrim(Buffer));

    wcsncpy_s(Buffer, ARRAYSIZE(Buffer), Equal + 1, _TRUNCATE);
    wcscpy_s(Value, ValueSize, InfTrim(Buffer));
    return TRUE;
}

/* Every value of a directive in a section, AddReg = a, b gives a and b */
static
ULONG
InfDirective(
    _In_ PINF_SECTION Section,
    _In_z_ PCWSTR Directive,
    _Out_writes_(Max) WCHAR Values[][INF_FIELD_MAX],
    _In_ ULONG Max)
{
    WCHAR Key[256], Value[INF_FIELD_MAX];
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    ULONG Count = 0, Line, Field;

    for (Line = 0; Section && Line < Section->Count; Line++)
    {
        if (!InfKeyValue(Section->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)) ||
            _wcsicmp(Key, Directive))
        {
            continue;
        }

        InfSplit(Value, Fields);
        for (Field = 0; Field < Fields->Count && Count < Max; Field++)
        {
            if (Fields->Field[Field][0])
                wcscpy_s(Values[Count++], INF_FIELD_MAX, Fields->Field[Field]);
        }
    }

    free(Fields);
    return Count;
}

static
VOID
InfLookupValue(
    _In_ PINF_FILE Inf,
    _In_ PINF_SECTION Section,
    _In_z_ PCWSTR Name,
    _Out_writes_z_(Size) PWSTR Out,
    _In_ SIZE_T Size)
{
    WCHAR Key[256], Value[INF_FIELD_MAX];
    ULONG Line;

    Out[0] = UNICODE_NULL;
    for (Line = 0; Section && Line < Section->Count; Line++)
    {
        if (InfKeyValue(Section->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)) &&
            !_wcsicmp(Key, Name))
        {
            InfExpand(Inf, Value, Out, Size);
            InfUnquote(Out);
            return;
        }
    }
}

static
PINF_SECTION
InfDecorated(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR Base,
    _In_opt_z_ PCWSTR Suffix)
{
    WCHAR Name[512], Decorations[3][24];
    ULONG Index;

    /* Most specific first */
    swprintf_s(Decorations[0], ARRAYSIZE(Decorations[0]), L".nt%s", InfPlatform);
    wcscpy_s(Decorations[1], ARRAYSIZE(Decorations[1]), L".nt");
    Decorations[2][0] = UNICODE_NULL;

    for (Index = 0; Index < ARRAYSIZE(Decorations); Index++)
    {
        PINF_SECTION Section;

        swprintf_s(Name, ARRAYSIZE(Name), L"%s%s%s", Base, Decorations[Index], Suffix ? Suffix : L"");
        Section = InfSection(Inf, Name);
        if (Section)
            return Section;
    }
    return NULL;
}

/* A line of the generated registry INF */
static
VOID
RegValue(
    _Inout_ PRMS_TEXT Out,
    _In_z_ PCWSTR Key,
    _In_z_ PCWSTR Name,
    _In_z_ PCWSTR Flags,
    _In_z_ PCWSTR Data)
{
    RmsTextAppendF(Out, L"HKLM,\"%s\",\"%s\",%s,%s\r\n", Key, Name, Flags, Data);
}

static
VOID
RegString(
    _Inout_ PRMS_TEXT Out,
    _In_z_ PCWSTR Key,
    _In_z_ PCWSTR Name,
    _In_z_ PCWSTR Data)
{
    WCHAR Quoted[INF_FIELD_MAX + 2];

    swprintf_s(Quoted, ARRAYSIZE(Quoted), L"\"%s\"", Data);
    RegValue(Out, Key, Name, L"0x00000000", Quoted);
}

static
VOID
RegDword(
    _Inout_ PRMS_TEXT Out,
    _In_z_ PCWSTR Key,
    _In_z_ PCWSTR Name,
    _In_ ULONG Data)
{
    WCHAR Number[16];

    swprintf_s(Number, ARRAYSIZE(Number), L"0x%08lx", Data);
    RegValue(Out, Key, Name, L"0x00010001", Number);
}

/*
 * AddReg sections, HKR becomes Base. With Filters set, the filter lists go to
 * FilterBase instead, the device key itself rather than its parameters.
 */
static
VOID
RegAddSections(
    _In_ PINF_FILE Inf,
    _In_ PINF_SECTION Install,
    _In_z_ PCWSTR Base,
    _In_opt_z_ PCWSTR FilterBase,
    _Inout_ PRMS_TEXT Out)
{
    WCHAR (*Names)[INF_FIELD_MAX] = malloc(32 * sizeof(*Names));
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    WCHAR Key[INF_FIELD_MAX * 2], Value[INF_FIELD_MAX];
    RMS_TEXT Expanded = { 0 };
    ULONG Count, Index, Line;

    Count = InfDirective(Install, L"AddReg", Names, 32);
    for (Index = 0; Index < Count; Index++)
    {
        PINF_SECTION Section = InfSection(Inf, Names[Index]);

        for (Line = 0; Section && Line < Section->Count; Line++)
        {
            PCWSTR Root, KeyBase, Data;

            /* Only root, key, name and flags are parsed, binary and multi string data can run to thousands of fields */
            RmsTextFree(&Expanded);
            InfExpandText(Inf, Section->Lines[Line], &Expanded);
            if (!Expanded.Buffer)
                continue;
            InfSplitSome(Expanded.Buffer, Fields, 4, &Data);
            if (Fields->Count < 1)
                continue;

            Root = Fields->Field[0];
            if (Fields->Count > 1)
                InfUnquote(Fields->Field[1]);
            if (Fields->Count > 2)
                InfUnquote(Fields->Field[2]);
            wcscpy_s(Value, ARRAYSIZE(Value), Fields->Count > 2 ? Fields->Field[2] : L"");

            if (!_wcsicmp(Root, L"HKR"))
            {
                KeyBase = (FilterBase && (!_wcsicmp(Value, L"LowerFilters") || !_wcsicmp(Value, L"UpperFilters")))
                          ? FilterBase : Base;
                if (Fields->Count > 1 && Fields->Field[1][0])
                    swprintf_s(Key, ARRAYSIZE(Key), L"%s\\%s", KeyBase, Fields->Field[1]);
                else
                    wcscpy_s(Key, ARRAYSIZE(Key), KeyBase);
                Root = L"HKLM";
            }
            else if (!_wcsicmp(Root, L"HKLM") || !_wcsicmp(Root, L"HKCR") ||
                     !_wcsicmp(Root, L"HKCU") || !_wcsicmp(Root, L"HKU"))
            {
                wcscpy_s(Key, ARRAYSIZE(Key), Fields->Count > 1 ? Fields->Field[1] : L"");
            }
            else
            {
                continue;
            }

            /* Event tracing sessions and security descriptors mean nothing to the image */
            if (wcsstr(Key, L"WMI\\Autologger") || !_wcsicmp(Value, L"Security"))
                continue;

            RmsTextAppendF(Out, L"%s,\"%s\",", Root, Key);
            if (Value[0])
                RmsTextAppendF(Out, L"\"%s\"", Value);
            if (Fields->Count > 3)
                RmsTextAppendF(Out, L",%s", Fields->Field[3]);
            if (Data)
            {
                RmsTextAppend(Out, L",");
                RmsTextAppend(Out, Data);
            }
            RmsTextAppend(Out, L"\r\n");
        }
    }

    RmsTextFree(&Expanded);
    free(Names);
    free(Fields);
}

static
ULONG
ParseNumber(
    _In_z_ PCWSTR Text,
    _In_ ULONG Default)
{
    PWSTR End;
    ULONG Value;

    if (!Text[0])
        return Default;
    Value = wcstoul(Text, &End, 0);
    return (End == Text) ? Default : Value;
}

/* A section with its platform form first, as SourceDisksFiles and SourceDisksNames come */
static
PINF_SECTION
InfPlatformSection(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR Base)
{
    WCHAR Name[128];
    PINF_SECTION Section;

    swprintf_s(Name, ARRAYSIZE(Name), L"%s.%s", Base, InfPlatform);
    Section = InfSection(Inf, Name);
    return Section ? Section : InfSection(Inf, Base);
}

/* The name a package ships a compressed file under, as Setup looks for it: a.dll becomes a.dl_ */
static
BOOL
CompressedSourcePath(
    _In_z_ PCWSTR Source,
    _Out_writes_z_(Size) PWSTR Packed,
    _In_ SIZE_T Size)
{
    PWCHAR Name, Dot;
    SIZE_T Length;

    wcscpy_s(Packed, Size, Source);
    Name = wcsrchr(Packed, L'\\');
    Name = Name ? Name + 1 : Packed;
    Dot = wcsrchr(Name, L'.');
    Length = wcslen(Packed);

    if (Dot != NULL && wcslen(Dot + 1) >= 3)
        Packed[Length - 1] = L'_';
    else if (Dot != NULL)
        wcscat_s(Packed, Size, L"_");
    else
        wcscat_s(Packed, Size, L"._");

    return RmsFileExists(Packed);
}

/* Expands a compressed package file and stages it under its real name */
static
BOOL
StageCompressedFile(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR Packed,
    _In_z_ PCWSTR RelativeDir,
    _In_z_ PCWSTR Target)
{
    WCHAR TempDir[MAX_PATH], TempFile[MAX_PATH];
    DWORD Error;
    BOOL Ok;

    if (!GetTempPathW(ARRAYSIZE(TempDir), TempDir) ||
        !GetTempFileNameW(TempDir, L"rms", 0, TempFile))
    {
        RmsError(L"no temporary file to expand %s into", Packed);
        return FALSE;
    }

    Error = SetupDecompressOrCopyFileW(Packed, TempFile, NULL);
    if (Error != ERROR_SUCCESS)
    {
        RmsError(L"expanding %s failed (error %lu)", Packed, Error);
        DeleteFileW(TempFile);
        return FALSE;
    }

    Ok = RmsStageSystemFile(MountDir, TempFile, RelativeDir, Target);
    DeleteFileW(TempFile);
    return Ok;
}

/* Where a file the INF copies sits: SourceDisksFiles gives its disk and folder, SourceDisksNames the disk's */
static
VOID
SourcePath(
    _In_ PINF_FILE Inf,
    _In_z_ PCWSTR InfDir,
    _In_z_ PCWSTR FileName,
    _Out_writes_z_(Size) PWSTR Out,
    _In_ SIZE_T Size)
{
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    WCHAR Entry[INF_FIELD_MAX], Disk[INF_FIELD_MAX], DiskPath[INF_FIELD_MAX] = L"", SubDir[INF_FIELD_MAX] = L"";

    InfLookupValue(Inf, InfPlatformSection(Inf, L"SourceDisksFiles"), FileName, Entry, ARRAYSIZE(Entry));
    if (Entry[0] && Fields)
    {
        InfSplit(Entry, Fields);
        wcscpy_s(Disk, ARRAYSIZE(Disk), Fields->Field[0]);
        if (Fields->Count > 1)
        {
            InfUnquote(Fields->Field[1]);
            wcscpy_s(SubDir, ARRAYSIZE(SubDir), Fields->Field[1]);
        }

        InfLookupValue(Inf, InfPlatformSection(Inf, L"SourceDisksNames"), Disk, Entry, ARRAYSIZE(Entry));
        if (Entry[0])
        {
            InfSplit(Entry, Fields);
            if (Fields->Count > 3)
            {
                InfUnquote(Fields->Field[3]);
                wcscpy_s(DiskPath, ARRAYSIZE(DiskPath), Fields->Field[3]);
            }
        }
    }
    free(Fields);

    swprintf_s(Out, Size, L"%s%s%s%s%s\\%s", InfDir,
               (DiskPath[0] && DiskPath[0] != L'\\') ? L"\\" : L"", DiskPath,
               (SubDir[0] && SubDir[0] != L'\\') ? L"\\" : L"", SubDir, FileName);
}

/* The files CopyFiles names, staged into the folder their DestinationDirs give */
static
BOOL
StageFiles(
    _In_z_ PCWSTR MountDir,
    _In_ PINF_FILE Inf,
    _In_ PINF_SECTION Install,
    _In_z_ PCWSTR InfDir,
    _In_ BOOL DryRun,
    _Inout_ PRMS_TEXT Comment)
{
    WCHAR (*Names)[INF_FIELD_MAX] = malloc(64 * sizeof(*Names));
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    PINF_SECTION Destinations = InfSection(Inf, L"DestinationDirs");
    WCHAR Dir[INF_FIELD_MAX], Default[INF_FIELD_MAX];
    ULONG Count, Index, Line;
    BOOL Ok = TRUE;

    InfLookupValue(Inf, Destinations, L"DefaultDestDir", Default, ARRAYSIZE(Default));
    Count = InfDirective(Install, L"CopyFiles", Names, 64);

    for (Index = 0; Index < Count; Index++)
    {
        PINF_SECTION Section = NULL;
        ULONG Files = 1;

        InfLookupValue(Inf, Destinations, Names[Index], Dir, ARRAYSIZE(Dir));
        if (!Dir[0])
            wcscpy_s(Dir, ARRAYSIZE(Dir), Default[0] ? Default : L"12");

        if (Names[Index][0] != L'@')
        {
            Section = InfSection(Inf, Names[Index]);
            Files = Section ? Section->Count : 0;
        }

        for (Line = 0; Line < Files; Line++)
        {
            WCHAR Source[MAX_PATH * 2], PackedSource[MAX_PATH * 2];
            PCWSTR Relative, Target, SourceName;
            ULONG DirId;
            BOOL Packed;

            /* A copy line is the name it gets, then the name it has in the package when they differ */
            if (Section)
            {
                WCHAR LineKey[INF_FIELD_MAX], LineValue[INF_FIELD_MAX];

                /* Setup reads a file line's fields after its key, so "x = a.sys" copies a.sys */
                if (InfKeyValue(Section->Lines[Line], LineKey, ARRAYSIZE(LineKey), LineValue, ARRAYSIZE(LineValue)))
                    InfSplit(LineValue, Fields);
                else
                    InfSplit(Section->Lines[Line], Fields);
                InfUnquote(Fields->Field[0]);
                if (Fields->Count > 1)
                    InfUnquote(Fields->Field[1]);
            }
            else
            {
                wcscpy_s(Fields->Field[0], INF_FIELD_MAX, Names[Index] + 1);
                Fields->Count = 1;
            }

            Target = Fields->Field[0];
            SourceName = (Fields->Count > 1 && Fields->Field[1][0]) ? Fields->Field[1] : Target;
            if (!Target[0])
                continue;

            DirId = ParseNumber(Dir, 12);
            Relative = (DirId == 11) ? L"system32" : (DirId == 10) ? L"" : L"system32\\drivers";

            SourcePath(Inf, InfDir, SourceName, Source, ARRAYSIZE(Source));
            Packed = !RmsFileExists(Source) && CompressedSourcePath(Source, PackedSource, ARRAYSIZE(PackedSource));
            if (DryRun)
            {
                if (!Packed && !RmsFileExists(Source))
                {
                    RmsError(L"%s is missing", Source);
                    Ok = FALSE;
                }
            }
            else if (Packed)
            {
                Ok = StageCompressedFile(MountDir, PackedSource, Relative, Target) && Ok;
            }
            else
            {
                Ok = RmsStageSystemFile(MountDir, Source, Relative, Target) && Ok;
            }
            RmsTextAppendF(Comment, L" %s", Target);
        }
    }

    free(Names);
    free(Fields);
    return Ok;
}

/* AddService lines; returns the device's own service, the one flagged as associated */
static
BOOL
WriteServices(
    _In_ PINF_FILE Inf,
    _In_ PINF_SECTION Services,
    _Inout_ PRMS_TEXT Out,
    _Out_writes_z_(ServiceSize) PWSTR Service,
    _In_ SIZE_T ServiceSize,
    _Out_writes_z_(DisplaySize) PWSTR Display,
    _In_ SIZE_T DisplaySize,
    _In_ BOOL BootStart)
{
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    WCHAR Key[256], Value[INF_FIELD_MAX], Expanded[INF_FIELD_MAX];
    WCHAR Name[INF_FIELD_MAX], ServiceKey[INF_FIELD_MAX], Text[INF_FIELD_MAX];
    ULONG Line, Flags;

    Service[0] = UNICODE_NULL;
    Display[0] = UNICODE_NULL;

    for (Line = 0; Services && Line < Services->Count; Line++)
    {
        PINF_SECTION Section;
        PWSTR Binary;

        if (!InfKeyValue(Services->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)) ||
            _wcsicmp(Key, L"AddService"))
        {
            continue;
        }

        InfExpand(Inf, Value, Expanded, ARRAYSIZE(Expanded));
        InfSplit(Expanded, Fields);
        if (Fields->Count < 3)
            continue;

        InfUnquote(Fields->Field[0]);
        wcscpy_s(Name, ARRAYSIZE(Name), Fields->Field[0]);
        Flags = ParseNumber(Fields->Field[1], 0);
        Section = InfSection(Inf, Fields->Field[2]);
        swprintf_s(ServiceKey, ARRAYSIZE(ServiceKey), REG_SERVICES L"%s", Name);

        InfLookupValue(Inf, Section, L"DisplayName", Text, ARRAYSIZE(Text));
        RegString(Out, ServiceKey, L"DisplayName", Text[0] ? Text : Name);
        if (Flags & 2)
        {
            wcscpy_s(Service, ServiceSize, Name);
            wcscpy_s(Display, DisplaySize, Text[0] ? Text : Name);
        }

        InfLookupValue(Inf, Section, L"Description", Text, ARRAYSIZE(Text));
        if (Text[0])
            RegString(Out, ServiceKey, L"Description", Text);

        InfLookupValue(Inf, Section, L"ErrorControl", Text, ARRAYSIZE(Text));
        RegDword(Out, ServiceKey, L"ErrorControl", ParseNumber(Text, 1));

        InfLookupValue(Inf, Section, L"LoadOrderGroup", Text, ARRAYSIZE(Text));
        if (Text[0])
            RegString(Out, ServiceKey, L"Group", Text);

        /* Everything is staged into system32\drivers, whatever folder the INF names */
        InfLookupValue(Inf, Section, L"ServiceBinary", Text, ARRAYSIZE(Text));
        Binary = wcsrchr(Text, L'\\');
        Binary = Binary ? Binary + 1 : Text;
        if (Binary[0])
        {
            WCHAR Image[INF_FIELD_MAX];

            swprintf_s(Image, ARRAYSIZE(Image), L"\"system32\\drivers\\%s\"", Binary);
            RegValue(Out, ServiceKey, L"ImagePath", L"0x00020000", Image);
        }

        /* Boot start on request, the device's own service only, its filters keep theirs */
        InfLookupValue(Inf, Section, L"StartType", Text, ARRAYSIZE(Text));
        RegDword(Out, ServiceKey, L"Start", (BootStart && (Flags & 2)) ? SERVICE_BOOT_START : ParseNumber(Text, 3));
        InfLookupValue(Inf, Section, L"ServiceType", Text, ARRAYSIZE(Text));
        RegDword(Out, ServiceKey, L"Type", ParseNumber(Text, 1));

        InfLookupValue(Inf, Section, L"Dependencies", Text, ARRAYSIZE(Text));
        if (Text[0])
        {
            WCHAR List[INF_FIELD_MAX * 2] = L"";
            INF_FIELDS *Deps = malloc(sizeof(*Deps));
            ULONG Dep;

            InfSplit(Text, Deps);
            for (Dep = 0; Dep < Deps->Count; Dep++)
            {
                if (!Deps->Field[Dep][0])
                    continue;
                if (List[0])
                    wcscat_s(List, ARRAYSIZE(List), L",");
                wcscat_s(List, ARRAYSIZE(List), L"\"");
                wcscat_s(List, ARRAYSIZE(List), Deps->Field[Dep]);
                wcscat_s(List, ARRAYSIZE(List), L"\"");
            }
            free(Deps);
            RegValue(Out, ServiceKey, L"DependOnService", L"0x00010000", List);
        }

        RegAddSections(Inf, Section, ServiceKey, NULL, Out);
    }

    free(Fields);
    return Service[0] != UNICODE_NULL;
}

/*
 * The device id an INF id stands for. ACPI\VEN_QCOM&DEV_0237&SUBSYS_... is what
 * many INFs list for the device the ACPI bus reports as ACPI\QCOM0237, and an id
 * with a subsystem also stands for the plain one.
 */
static
VOID
CanonicalId(
    _In_z_ PCWSTR Id,
    _Out_writes_z_(Size) PWSTR Out,
    _In_ SIZE_T Size)
{
    PWCHAR Amp;

    if (!_wcsnicmp(Id, L"ACPI\\VEN_", 9) && wcslen(Id) >= 9 + 4 + 5 + 4 && !_wcsnicmp(Id + 13, L"&DEV_", 5))
        swprintf_s(Out, Size, L"ACPI\\%.4s%.4s", Id + 9, Id + 18);
    else
        wcscpy_s(Out, Size, Id);

    Amp = wcschr(Out, L'&');
    if (Amp && !_wcsnicmp(Amp, L"&SUBSYS_", 8))
        *Amp = UNICODE_NULL;
}

static
BOOL
IdMatches(
    _In_z_ PCWSTR InfId,
    _In_z_ PCWSTR DeviceId)
{
    WCHAR Left[INF_FIELD_MAX], Right[INF_FIELD_MAX];

    CanonicalId(InfId, Left, ARRAYSIZE(Left));
    CanonicalId(DeviceId, Right, ARRAYSIZE(Right));
    return !_wcsicmp(Left, Right);
}

/* The device the user named that an INF id stands for, NULL when it serves none */
static
PCWSTR
WantedDevice(
    _In_z_ PCWSTR Id,
    _In_reads_(DeviceCount) PCWSTR *Devices,
    _In_ ULONG DeviceCount)
{
    ULONG Index;

    for (Index = 0; Index < DeviceCount; Index++)
    {
        if (IdMatches(Id, Devices[Index]))
            return Devices[Index];
    }
    return NULL;
}

/* A hardware id the user asked for, or any id when none was named */
static
BOOL
DeviceWanted(
    _In_z_ PCWSTR Id,
    _In_reads_(DeviceCount) PCWSTR *Devices,
    _In_ ULONG DeviceCount)
{
    return !DeviceCount || WantedDevice(Id, Devices, DeviceCount) != NULL;
}

/* The models sections the manufacturer section names, decorated for the image's platform where it says so */
static
ULONG
ModelSections(
    _In_ PINF_FILE Inf,
    _Out_writes_(Max) PINF_SECTION *Models,
    _In_ ULONG Max)
{
    PINF_SECTION Manufacturer = InfSection(Inf, L"Manufacturer");
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    WCHAR Key[256], Value[INF_FIELD_MAX], Name[512], Decoration[24];
    ULONG Count = 0, Line, Field;
    SIZE_T DecorationLength;

    swprintf_s(Decoration, ARRAYSIZE(Decoration), L"NT%s", InfPlatform);
    DecorationLength = wcslen(Decoration);

    for (Line = 0; Manufacturer && Line < Manufacturer->Count && Count < Max; Line++)
    {
        PINF_SECTION Section = NULL;

        if (!InfKeyValue(Manufacturer->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)))
            continue;

        InfSplit(Value, Fields);
        InfUnquote(Fields->Field[0]);

        for (Field = 1; Field < Fields->Count && !Section; Field++)
        {
            if (!_wcsnicmp(Fields->Field[Field], Decoration, DecorationLength))
            {
                swprintf_s(Name, ARRAYSIZE(Name), L"%s.%s", Fields->Field[0], Fields->Field[Field]);
                Section = InfSection(Inf, Name);
            }
        }
        if (!Section)
            Section = InfSection(Inf, Fields->Field[0]);
        if (Section)
            Models[Count++] = Section;
    }

    free(Fields);
    return Count;
}

#define ID_PARTS_MAX    8

typedef struct _ID_PARTS
{
    WCHAR Bus[32];
    WCHAR Name[ID_PARTS_MAX][16];
    WCHAR Value[ID_PARTS_MAX][64];
    ULONG Count;
} ID_PARTS, *PID_PARTS;

/* Splits BUS\VEN_X&DEV_Y&... into named parts, ACPI\QCOM0C36 reads as VEN_QCOM&DEV_0C36 */
static
BOOL
IdSplit(
    _In_z_ PCWSTR DeviceId,
    _Out_ PID_PARTS Parts)
{
    PCWSTR Slash = wcschr(DeviceId, L'\\'), Part, End;

    ZeroMemory(Parts, sizeof(*Parts));
    if (!Slash || Slash - DeviceId >= ARRAYSIZE(Parts->Bus))
        return FALSE;
    wcsncpy_s(Parts->Bus, ARRAYSIZE(Parts->Bus), DeviceId, Slash - DeviceId);

    Part = Slash + 1;
    if (wcslen(Part) == 8 && !wcschr(Part, L'_') && !wcschr(Part, L'&'))
    {
        wcscpy_s(Parts->Name[0], ARRAYSIZE(Parts->Name[0]), L"VEN");
        wcsncpy_s(Parts->Value[0], ARRAYSIZE(Parts->Value[0]), Part, 4);
        wcscpy_s(Parts->Name[1], ARRAYSIZE(Parts->Name[1]), L"DEV");
        wcscpy_s(Parts->Value[1], ARRAYSIZE(Parts->Value[1]), Part + 4);
        Parts->Count = 2;
        return TRUE;
    }

    while (*Part && Parts->Count < ID_PARTS_MAX)
    {
        PCWSTR Under;

        End = wcschr(Part, L'&');
        if (!End)
            End = Part + wcslen(Part);
        Under = wcschr(Part, L'_');
        if (!Under || Under > End || Under - Part >= ARRAYSIZE(Parts->Name[0]) ||
            End - Under - 1 >= ARRAYSIZE(Parts->Value[0]))
        {
            return FALSE;
        }

        wcsncpy_s(Parts->Name[Parts->Count], ARRAYSIZE(Parts->Name[0]), Part, Under - Part);
        wcsncpy_s(Parts->Value[Parts->Count], ARRAYSIZE(Parts->Value[0]), Under + 1, End - Under - 1);
        Parts->Count++;
        Part = *End ? End + 1 : End;
    }
    return TRUE;
}

static
PCWSTR
IdPart(
    _In_ const ID_PARTS *Parts,
    _In_z_ PCWSTR Name)
{
    ULONG Index;

    for (Index = 0; Index < Parts->Count; Index++)
    {
        if (!_wcsicmp(Parts->Name[Index], Name))
            return Parts->Value[Index];
    }
    return NULL;
}

/* Whether two ids can name the same device: same bus, vendor and device, no part that disagrees */
static
BOOL
IdSameDevice(
    _In_z_ PCWSTR First,
    _In_z_ PCWSTR Second)
{
    ID_PARTS A, B;
    ULONG Index;

    if (!_wcsicmp(First, Second))
        return TRUE;
    if (!IdSplit(First, &A) || !IdSplit(Second, &B) || _wcsicmp(A.Bus, B.Bus))
        return FALSE;
    if (!IdPart(&A, L"VEN") || !IdPart(&A, L"DEV") || !IdPart(&B, L"VEN") || !IdPart(&B, L"DEV"))
        return FALSE;

    for (Index = 0; Index < A.Count; Index++)
    {
        PCWSTR Other = IdPart(&B, A.Name[Index]);

        if (Other && _wcsicmp(Other, A.Value[Index]))
            return FALSE;
    }
    return TRUE;
}

/* The driver keys of the installed devices an extension id applies to */
static
ULONG
BaseDeviceKeys(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR DeviceId,
    _Out_writes_(MaxKeys) WCHAR Keys[][64],
    _In_ ULONG MaxKeys)
{
    PWSTR List = RmsGetDeviceKeys(MountDir);
    PWSTR Entry;
    ULONG Count = 0, Index;

    if (!List)
        return 0;

    for (Entry = List; *Entry && Count < MaxKeys; Entry += wcslen(Entry) + 1)
    {
        PWCHAR Equals = wcschr(Entry, L'=');

        if (!Equals)
            continue;
        *Equals = UNICODE_NULL;
        if (IdSameDevice(DeviceId, Entry))
        {
            for (Index = 0; Index < Count; Index++)
            {
                if (!_wcsicmp(Keys[Index], Equals + 1))
                    break;
            }
            if (Index == Count)
                wcscpy_s(Keys[Count++], 64, Equals + 1);
        }
        *Equals = L'=';
    }

    free(List);
    return Count;
}

/**
 * @brief Tells whether an INF is a driver extension INF.
 */
BOOL
RmsIsExtensionInf(
    _In_z_ PCWSTR InfPath)
{
    PINF_FILE Inf = malloc(sizeof(*Inf));
    WCHAR ClassGuid[128] = L"";
    BOOL IsExtension = FALSE;

    if (!Inf)
        return FALSE;

    if (InfLoad(InfPath, Inf))
    {
        InfLookupValue(Inf, InfSection(Inf, L"Version"), L"ClassGUID", ClassGuid, ARRAYSIZE(ClassGuid));
        IsExtension = !_wcsicmp(ClassGuid, RMS_EXTENSION_CLASS);
        InfFree(Inf);
    }

    free(Inf);
    return IsExtension;
}

/* Picks the INF platform from the image's setup folder, an unknown one keeps arm64 */
static
VOID
InfSelectPlatform(
    _In_z_ PCWSTR MountDir)
{
    WCHAR Arch[64];

    RmsGetImageArch(MountDir, Arch, ARRAYSIZE(Arch));

    if (!_wcsicmp(Arch, L"amd64") || !_wcsicmp(Arch, L"x64"))
        wcscpy_s(InfPlatform, ARRAYSIZE(InfPlatform), L"amd64");
    else if (!_wcsicmp(Arch, L"i386") || !_wcsicmp(Arch, L"x86"))
        wcscpy_s(InfPlatform, ARRAYSIZE(InfPlatform), L"x86");
    else
        wcscpy_s(InfPlatform, ARRAYSIZE(InfPlatform), L"arm64");
}

/**
 * @brief Installs one Windows driver INF into the mounted image.
 *
 * @param[in] Options
 * The hardware ids and instances to install for, and whether to only describe it.
 */
BOOL
RmsTranslateDriver(
    _In_z_ PCWSTR MountDir,
    _In_z_ PCWSTR InfPath,
    _In_ const RMS_DRIVER_OPTIONS *Options,
    _Inout_ PULONG NextDriverKey)
{
    PCWSTR *Devices = Options->Devices, *Instances = Options->Instances;
    ULONG DeviceCount = Options->DeviceCount, InstanceCount = Options->InstanceCount;
    PINF_FILE Inf = malloc(sizeof(*Inf));
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    PINF_SECTION Models[32];
    PINF_SECTION Version;
    RMS_TEXT Out = { 0 }, Comment = { 0 };
    WCHAR InfDir[MAX_PATH], InfName[MAX_PATH], RegName[MAX_PATH];
    WCHAR ClassGuid[128], ClassName[128], Provider[256], DriverVer[128];
    WCHAR Key[INF_FIELD_MAX], Value[INF_FIELD_MAX];
    WCHAR LastInstall[INF_FIELD_MAX] = L"";
    WCHAR Service[INF_FIELD_MAX], Display[INF_FIELD_MAX], DriverKey[64];
    ULONG ModelCount, Model, Line, Id, Instance, Installed = 0;
    PWCHAR Slash;
    BOOL Ok = TRUE, IsExtension;

    InfSelectPlatform(MountDir);

    if (!Inf || !Fields || !InfLoad(InfPath, Inf))
    {
        free(Inf);
        free(Fields);
        return FALSE;
    }

    wcscpy_s(InfDir, ARRAYSIZE(InfDir), InfPath);
    Slash = wcsrchr(InfDir, L'\\');
    wcscpy_s(InfName, ARRAYSIZE(InfName), Slash ? Slash + 1 : InfPath);
    if (Slash)
        *Slash = UNICODE_NULL;
    else
        wcscpy_s(InfDir, ARRAYSIZE(InfDir), L".");
    _wcslwr_s(InfName, ARRAYSIZE(InfName));

    Version = InfSection(Inf, L"Version");
    InfLookupValue(Inf, Version, L"ClassGUID", ClassGuid, ARRAYSIZE(ClassGuid));
    _wcsupr_s(ClassGuid, ARRAYSIZE(ClassGuid));
    InfLookupValue(Inf, Version, L"Class", ClassName, ARRAYSIZE(ClassName));
    InfLookupValue(Inf, Version, L"Provider", Provider, ARRAYSIZE(Provider));
    InfLookupValue(Inf, Version, L"DriverVer", DriverVer, ARRAYSIZE(DriverVer));

    /* An extension INF adds to a device another INF installs, it brings no driver of its own */
    IsExtension = !_wcsicmp(ClassGuid, RMS_EXTENSION_CLASS);

    RmsTextAppendF(&Out, L"; Installed by rmsetup from %s, do not edit\r\n\r\n[AddReg]\r\n", InfName);

    ModelCount = ModelSections(Inf, Models, ARRAYSIZE(Models));
    for (Model = 0; Model < ModelCount; Model++)
    {
        for (Line = 0; Line < Models[Model]->Count; Line++)
        {
            PINF_SECTION Install, Services, Hw, Wdf;
            WCHAR Description[INF_FIELD_MAX], InstallName[INF_FIELD_MAX];
            WCHAR ModelValue[INF_FIELD_MAX], FirstId[INF_FIELD_MAX];
            BOOL Wanted = FALSE;

            if (!InfKeyValue(Models[Model]->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)))
                continue;

            InfExpand(Inf, Value, ModelValue, ARRAYSIZE(ModelValue));
            InfSplit(ModelValue, Fields);
            if (Fields->Count < 2)
                continue;

            InfUnquote(Fields->Field[1]);
            wcscpy_s(FirstId, ARRAYSIZE(FirstId), Fields->Field[1]);
            for (Id = 1; Id < Fields->Count; Id++)
            {
                InfUnquote(Fields->Field[Id]);
                Wanted = Wanted || DeviceWanted(Fields->Field[Id], Devices, DeviceCount);
            }
            if (!Wanted)
                continue;

            wcscpy_s(InstallName, ARRAYSIZE(InstallName), Fields->Field[0]);
            Install = InfDecorated(Inf, InstallName, NULL);
            if (!Install)
            {
                RmsError(L"%s: no install section %s", InfName, InstallName);
                Ok = FALSE;
                continue;
            }

            InfExpand(Inf, Key, Description, ARRAYSIZE(Description));
            InfUnquote(Description);

            /* Each install section once, every id it serves after it */
            if (_wcsicmp(LastInstall, InstallName))
            {
                wcscpy_s(LastInstall, ARRAYSIZE(LastInstall), InstallName);

                RmsTextFree(&Comment);
                Ok = StageFiles(MountDir, Inf, Install, InfDir, Options->DryRun, &Comment) && Ok;

                /*
                 * A section without a function driver still installs: extensions add to the device
                 * another INF drives, software components bring services and settings of their own.
                 */
                Services = InfDecorated(Inf, InstallName, L".Services");
                if (!WriteServices(Inf, Services, &Out, Service, ARRAYSIZE(Service), Display, ARRAYSIZE(Display),
                                   Options->BootStart))
                {
                    Service[0] = UNICODE_NULL;
                    wcscpy_s(Display, ARRAYSIZE(Display), Description);
                }

                /* KMDF drivers name their framework version */
                Wdf = InfDecorated(Inf, InstallName, L".Wdf");
                if (Wdf)
                {
                    WCHAR Service2[INF_FIELD_MAX], Version2[64], WdfKey[INF_FIELD_MAX];
                    ULONG W;

                    for (W = 0; W < Wdf->Count; W++)
                    {
                        if (!InfKeyValue(Wdf->Lines[W], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)) ||
                            _wcsicmp(Key, L"KmdfService"))
                        {
                            continue;
                        }
                        InfSplit(Value, Fields);
                        InfUnquote(Fields->Field[0]);
                        wcscpy_s(Service2, ARRAYSIZE(Service2), Fields->Field[0]);
                        InfLookupValue(Inf, InfSection(Inf, Fields->Field[1]), L"KmdfLibraryVersion",
                                       Version2, ARRAYSIZE(Version2));
                        if (Version2[0])
                        {
                            swprintf_s(WdfKey, ARRAYSIZE(WdfKey), REG_SERVICES L"%s\\Parameters\\Wdf", Service2);
                            RegString(&Out, WdfKey, L"KmdfLibraryVersion", Version2);
                        }
                    }
                }

                /* An extension writes into the driver key of the device it extends, see below */
                DriverKey[0] = UNICODE_NULL;
                if (!IsExtension)
                {
                    /* A pinned key keeps values other INFs set on it in place */
                    swprintf_s(DriverKey, ARRAYSIZE(DriverKey), L"%s\\%04lX", ClassGuid,
                               Options->DriverKey ? Options->DriverKey : (*NextDriverKey)++);
                    swprintf_s(Key, ARRAYSIZE(Key), REG_CLASS L"%s", DriverKey);
                    RegString(&Out, Key, L"DriverDesc", Display);
                    RegString(&Out, Key, L"InfPath", InfName);
                    RegString(&Out, Key, L"InfSection", InstallName);
                    if (Provider[0])
                        RegString(&Out, Key, L"ProviderName", Provider);
                    if (DriverVer[0])
                    {
                        PWCHAR Comma = wcschr(DriverVer, L',');

                        RegString(&Out, Key, L"DriverVersion", Comma ? InfTrim(Comma + 1) : DriverVer);
                    }
                    RegString(&Out, Key, L"MatchingDeviceId", FirstId);
                    RegAddSections(Inf, Install, Key, NULL, &Out);
                }

                if (IsExtension)
                    RmsTextAppend(&Comment, L" -> extension");
                else if (Service[0])
                    RmsTextAppendF(&Comment, L" -> %s%s", Service, Options->BootStart ? L" (boot start)" : L"");
                else
                    RmsTextAppend(&Comment, L" -> no function driver");
                if (Options->Summary)
                    RmsTextAppendF(Options->Summary, L"%s: %s%s\r\n", InstallName, Description, Comment.Buffer ? Comment.Buffer : L"");
                if (!Options->DryRun)
                    RmsInfo(L"  %s: %s (%s)%s", InfName, InstallName, Description, Comment.Buffer ? Comment.Buffer : L"");
                Installed++;
            }

            Hw = InfDecorated(Inf, InstallName, L".HW");

            /* The critical device database, the kernel starts the service from it on arrival */
            InfSplit(ModelValue, Fields);
            for (Id = 1; Id < Fields->Count; Id++)
            {
                WCHAR Cddb[INF_FIELD_MAX], Params[INF_FIELD_MAX], *Char;

                PCWSTR Reported;

                InfUnquote(Fields->Field[Id]);
                if (!Fields->Field[Id][0] || !DeviceWanted(Fields->Field[Id], Devices, DeviceCount))
                    continue;

                /* Keyed by the id the bus reports, the one named, rather than the INF's form of it */
                Reported = DeviceCount ? WantedDevice(Fields->Field[Id], Devices, DeviceCount) : Fields->Field[Id];
                swprintf_s(Cddb, ARRAYSIZE(Cddb), REG_CDDB L"%s", Reported);
                for (Char = Cddb + wcslen(REG_CDDB); *Char; Char++)
                {
                    if (*Char == L'\\')
                        *Char = L'#';
                }
                if (!IsExtension && Service[0])
                {
                    RegString(&Out, Cddb, L"Service", Service);
                    RegString(&Out, Cddb, L"ClassGUID", ClassGuid);
                }
                swprintf_s(Params, ARRAYSIZE(Params), L"%s\\Device Parameters", Cddb);
                RegAddSections(Inf, Hw, Params, Cddb, &Out);

                if (Options->DryRun)
                    continue;

                if (!IsExtension)
                {
                    RmsSetDeviceKey(MountDir, Reported, DriverKey);
                }
                else
                {
                    WCHAR BaseKeys[16][64];
                    ULONG BaseCount, Base;

                    /* The extension's settings land in the driver keys of the devices it extends */
                    BaseCount = BaseDeviceKeys(MountDir, Reported, BaseKeys, ARRAYSIZE(BaseKeys));
                    for (Base = 0; Base < BaseCount; Base++)
                    {
                        swprintf_s(Key, ARRAYSIZE(Key), REG_CLASS L"%s", BaseKeys[Base]);
                        RegAddSections(Inf, Install, Key, NULL, &Out);
                    }
                    if (!BaseCount)
                    {
                        RmsInfo(L"  %s: no installed driver for %s yet, its driver settings are skipped",
                                InfName, Reported);
                    }
                }
            }

            /* Instances named on the command line get their Enum keys now */
            for (Instance = 0; Instance < InstanceCount; Instance++)
            {
                WCHAR Enum[INF_FIELD_MAX], Params[INF_FIELD_MAX];
                PCWSTR Last = wcsrchr(Instances[Instance], L'\\');
                WCHAR DeviceId[INF_FIELD_MAX];

                if (!Last)
                    continue;
                wcsncpy_s(DeviceId, ARRAYSIZE(DeviceId), Instances[Instance], Last - Instances[Instance]);

                for (Id = 1; Id < Fields->Count; Id++)
                {
                    if (IdMatches(Fields->Field[Id], DeviceId))
                        break;
                }
                if (Id == Fields->Count)
                    continue;

                swprintf_s(Enum, ARRAYSIZE(Enum), REG_ENUM L"%s", Instances[Instance]);
                if (!IsExtension)
                {
                    RegString(&Out, Enum, L"DeviceDesc", Description);
                    if (Service[0])
                        RegString(&Out, Enum, L"Service", Service);
                    RegString(&Out, Enum, L"ClassGUID", ClassGuid);
                    RegString(&Out, Enum, L"Class", ClassName);
                    RegString(&Out, Enum, L"Driver", DriverKey);
                }
                swprintf_s(Params, ARRAYSIZE(Params), L"%s\\Device Parameters", Enum);
                RegAddSections(Inf, Hw, Params, Enum, &Out);
            }
        }
    }

    if (!Installed)
    {
        if (!Options->DryRun)
            RmsError(L"%s: no model matches the devices asked for", InfName);
        Ok = FALSE;
    }
    else if (!Options->DryRun)
    {
        PWCHAR Dot;

        wcscpy_s(RegName, ARRAYSIZE(RegName), InfName);
        Dot = wcsrchr(RegName, L'.');
        if (Dot)
            *Dot = UNICODE_NULL;

        /* One INF installed for several devices gets one registry INF per device */
        if (DeviceCount)
        {
            PCWSTR Tail = wcsrchr(Devices[0], L'\\');
            WCHAR Suffix[64];
            PWCHAR Char;

            swprintf_s(Suffix, ARRAYSIZE(Suffix), L"_%s", Tail ? Tail + 1 : Devices[0]);
            for (Char = Suffix; *Char; Char++)
            {
                if (!iswalnum(*Char) && *Char != L'_')
                    *Char = L'_';
            }
            wcscat_s(RegName, ARRAYSIZE(RegName), Suffix);
        }
        wcscat_s(RegName, ARRAYSIZE(RegName), L"_driver_reg.inf");
        Ok = RmsRegisterInf(MountDir, RegName, NULL, Out.Buffer) && Ok;
    }

    RmsTextFree(&Out);
    RmsTextFree(&Comment);
    InfFree(Inf);
    free(Inf);
    free(Fields);
    return Ok;
}
