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

#define INF_MAX_SECTIONS    512
#define INF_MAX_STRINGS     2048
#define INF_MAX_FIELDS      32
#define INF_FIELD_MAX       1024

#define REG_SERVICES        L"SYSTEM\\CurrentControlSet\\Services\\"
#define REG_CLASS           L"SYSTEM\\CurrentControlSet\\Control\\Class\\"
#define REG_CDDB            L"SYSTEM\\CurrentControlSet\\Control\\CriticalDeviceDatabase\\"
#define REG_ENUM            L"SYSTEM\\CurrentControlSet\\Enum\\"

/* Install sections are looked up with these decorations, most specific first */
static PCWSTR InfDecorations[] = { L".ntarm64", L".nt", L"" };

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

            if (!Close || Inf->SectionCount == INF_MAX_SECTIONS)
                continue;
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

/* Splits on commas outside quotes, each field trimmed; quotes stay */
static
VOID
InfSplit(
    _In_z_ PCWSTR Text,
    _Out_ PINF_FIELDS Fields)
{
    SIZE_T Used = 0;
    BOOL Quoted = FALSE;

    Fields->Count = 0;
    Fields->Field[0][0] = UNICODE_NULL;

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
            if (*Text == UNICODE_NULL || Fields->Count == INF_MAX_FIELDS)
                return;
            continue;
        }

        if (*Text == L'"')
            Quoted = !Quoted;
        if (Used + 1 < INF_FIELD_MAX)
            Fields->Field[Fields->Count][Used++] = *Text;
    }
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
    WCHAR Name[512];
    ULONG Index;

    for (Index = 0; Index < ARRAYSIZE(InfDecorations); Index++)
    {
        PINF_SECTION Section;

        swprintf_s(Name, ARRAYSIZE(Name), L"%s%s%s", Base, InfDecorations[Index], Suffix ? Suffix : L"");
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
    WCHAR Expanded[INF_FIELD_MAX * 2], Key[INF_FIELD_MAX * 2], Value[INF_FIELD_MAX];
    ULONG Count, Index, Line, Rest;

    Count = InfDirective(Install, L"AddReg", Names, 32);
    for (Index = 0; Index < Count; Index++)
    {
        PINF_SECTION Section = InfSection(Inf, Names[Index]);

        for (Line = 0; Section && Line < Section->Count; Line++)
        {
            PCWSTR Root, KeyBase;

            InfExpand(Inf, Section->Lines[Line], Expanded, ARRAYSIZE(Expanded));
            InfSplit(Expanded, Fields);
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
            for (Rest = 3; Rest < Fields->Count; Rest++)
                RmsTextAppendF(Out, L",%s", Fields->Field[Rest]);
            RmsTextAppend(Out, L"\r\n");
        }
    }

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
            PCWSTR Relative;
            PWSTR Source;
            ULONG DirId;

            if (Section)
            {
                InfSplit(Section->Lines[Line], Fields);
                InfUnquote(Fields->Field[0]);
            }
            else
            {
                wcscpy_s(Fields->Field[0], INF_FIELD_MAX, Names[Index] + 1);
            }

            DirId = ParseNumber(Dir, 12);
            Relative = (DirId == 11) ? L"system32" : (DirId == 10) ? L"" : L"system32\\drivers";

            Source = RmsJoin(InfDir, Fields->Field[0]);
            if (DryRun)
            {
                if (!RmsFileExists(Source))
                {
                    RmsError(L"%s is missing", Source);
                    Ok = FALSE;
                }
            }
            else
            {
                Ok = RmsStageSystemFile(MountDir, Source, Relative) && Ok;
            }
            RmsTextAppendF(Comment, L" %s", Fields->Field[0]);
            free(Source);
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

/* The models sections the manufacturer section names, decorated for ARM64 where it says so */
static
ULONG
ModelSections(
    _In_ PINF_FILE Inf,
    _Out_writes_(Max) PINF_SECTION *Models,
    _In_ ULONG Max)
{
    PINF_SECTION Manufacturer = InfSection(Inf, L"Manufacturer");
    INF_FIELDS *Fields = malloc(sizeof(*Fields));
    WCHAR Key[256], Value[INF_FIELD_MAX], Name[512];
    ULONG Count = 0, Line, Field;

    for (Line = 0; Manufacturer && Line < Manufacturer->Count && Count < Max; Line++)
    {
        PINF_SECTION Section = NULL;

        if (!InfKeyValue(Manufacturer->Lines[Line], Key, ARRAYSIZE(Key), Value, ARRAYSIZE(Value)))
            continue;

        InfSplit(Value, Fields);
        InfUnquote(Fields->Field[0]);

        for (Field = 1; Field < Fields->Count && !Section; Field++)
        {
            if (!_wcsnicmp(Fields->Field[Field], L"NTarm64", 7))
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
    BOOL Ok = TRUE;

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

                Services = InfDecorated(Inf, InstallName, L".Services");
                if (!WriteServices(Inf, Services, &Out, Service, ARRAYSIZE(Service), Display, ARRAYSIZE(Display),
                                   Options->BootStart))
                {
                    RmsError(L"%s: %s installs no function driver", InfName, InstallName);
                    Ok = FALSE;
                    continue;
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

                RmsTextAppendF(&Comment, L" -> %s%s", Service, Options->BootStart ? L" (boot start)" : L"");
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
                RegString(&Out, Cddb, L"Service", Service);
                RegString(&Out, Cddb, L"ClassGUID", ClassGuid);
                swprintf_s(Params, ARRAYSIZE(Params), L"%s\\Device Parameters", Cddb);
                RegAddSections(Inf, Hw, Params, Cddb, &Out);
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
                RegString(&Out, Enum, L"DeviceDesc", Description);
                RegString(&Out, Enum, L"Service", Service);
                RegString(&Out, Enum, L"ClassGUID", ClassGuid);
                RegString(&Out, Enum, L"Class", ClassName);
                RegString(&Out, Enum, L"Driver", DriverKey);
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
