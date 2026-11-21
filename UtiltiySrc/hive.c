/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Reads the services of an offline SYSTEM hive
 */

/*
 * Only what listing the image's drivers needs: the hive is read whole, cells are
 * looked up by offset, keys by name through their subkey lists. Values bigger than
 * one cell are not followed, no service value is that big.
 */

#include "rmsetup.h"

#define HIVE_BASE_BLOCK         0x1000
#define HIVE_KEY_COMPRESSED     0x0020
#define HIVE_VALUE_COMPRESSED   0x0001
#define HIVE_DATA_INLINE        0x80000000

typedef struct _HIVE
{
    PUCHAR Data;
    ULONG Size;
} HIVE, *PHIVE;

static
const UCHAR *
HiveCell(
    _In_ PHIVE Hive,
    _In_ ULONG Offset,
    _In_ ULONG Needed)
{
    ULONG Start = HIVE_BASE_BLOCK + Offset + 4;

    if (Offset == 0xFFFFFFFF || Start < Offset || Start + Needed > Hive->Size || Start + Needed < Start)
        return NULL;
    return Hive->Data + Start;
}

static
USHORT
Le16(
    _In_ const UCHAR *Data)
{
    return (USHORT)(Data[0] | (Data[1] << 8));
}

static
ULONG
Le32(
    _In_ const UCHAR *Data)
{
    return Data[0] | (Data[1] << 8) | (Data[2] << 16) | ((ULONG)Data[3] << 24);
}

/* The name of a key or value cell, ASCII when compressed, UTF-16 otherwise */
static
VOID
HiveName(
    _In_reads_(Length) const UCHAR *Raw,
    _In_ USHORT Length,
    _In_ BOOL Compressed,
    _Out_writes_z_(Size) PWSTR Name,
    _In_ SIZE_T Size)
{
    SIZE_T Count = 0, Index;

    if (Compressed)
    {
        for (Index = 0; Index < Length && Count + 1 < Size; Index++)
            Name[Count++] = Raw[Index];
    }
    else
    {
        for (Index = 0; Index + 1 < Length && Count + 1 < Size; Index += 2)
            Name[Count++] = (WCHAR)Le16(Raw + Index);
    }
    Name[Count] = UNICODE_NULL;
}

static
const UCHAR *
HiveKey(
    _In_ PHIVE Hive,
    _In_ ULONG Offset)
{
    const UCHAR *Key = HiveCell(Hive, Offset, 0x4C);

    if (!Key || Key[0] != 'n' || Key[1] != 'k' || !HiveCell(Hive, Offset, 0x4C + Le16(Key + 0x48)))
        return NULL;
    return Key;
}

/* Calls Routine for every subkey offset of a key, through ri lists of lf, lh and li ones */
typedef BOOL (*HIVE_SUBKEY_ROUTINE)(_In_ PHIVE Hive, _In_ ULONG Offset, _In_opt_ PVOID Context);

static
BOOL
HiveWalkList(
    _In_ PHIVE Hive,
    _In_ ULONG ListOffset,
    _In_ HIVE_SUBKEY_ROUTINE Routine,
    _In_opt_ PVOID Context,
    _In_ ULONG Depth)
{
    const UCHAR *List = HiveCell(Hive, ListOffset, 4);
    ULONG Count, Index, Stride;

    if (!List || Depth > 2)
        return FALSE;

    Count = Le16(List + 2);
    if ((List[0] == 'l' && (List[1] == 'f' || List[1] == 'h')))
        Stride = 8;
    else if ((List[0] == 'l' && List[1] == 'i') || (List[0] == 'r' && List[1] == 'i'))
        Stride = 4;
    else
        return FALSE;

    if (!HiveCell(Hive, ListOffset, 4 + Count * Stride))
        return FALSE;

    for (Index = 0; Index < Count; Index++)
    {
        ULONG Child = Le32(List + 4 + Index * Stride);

        if (List[0] == 'r')
        {
            if (HiveWalkList(Hive, Child, Routine, Context, Depth + 1))
                return TRUE;
        }
        else if (Routine(Hive, Child, Context))
        {
            return TRUE;
        }
    }
    return FALSE;
}

typedef struct _HIVE_FIND
{
    PCWSTR Name;
    ULONG Found;
} HIVE_FIND;

static
BOOL
HiveMatch(
    _In_ PHIVE Hive,
    _In_ ULONG Offset,
    _In_opt_ PVOID Context)
{
    HIVE_FIND *Find = Context;
    const UCHAR *Key = HiveKey(Hive, Offset);
    WCHAR Name[256];

    if (!Key)
        return FALSE;

    HiveName(Key + 0x4C, Le16(Key + 0x48), (Le16(Key + 2) & HIVE_KEY_COMPRESSED) != 0, Name, ARRAYSIZE(Name));
    if (_wcsicmp(Name, Find->Name))
        return FALSE;

    Find->Found = Offset;
    return TRUE;
}

/* A subkey by path, components split on backslashes */
static
ULONG
HiveOpen(
    _In_ PHIVE Hive,
    _In_ ULONG Root,
    _In_z_ PCWSTR Path)
{
    WCHAR Component[256];
    ULONG Current = Root;

    while (*Path)
    {
        const UCHAR *Key = HiveKey(Hive, Current);
        HIVE_FIND Find;
        SIZE_T Length = 0;

        while (*Path && *Path != L'\\' && Length + 1 < ARRAYSIZE(Component))
            Component[Length++] = *Path++;
        Component[Length] = UNICODE_NULL;
        if (*Path == L'\\')
            Path++;

        if (!Key || !Le32(Key + 0x14))
            return 0xFFFFFFFF;

        Find.Name = Component;
        Find.Found = 0xFFFFFFFF;
        HiveWalkList(Hive, Le32(Key + 0x1C), HiveMatch, &Find, 0);
        if (Find.Found == 0xFFFFFFFF)
            return 0xFFFFFFFF;
        Current = Find.Found;
    }
    return Current;
}

/* A value's data and type, FALSE when the key has no such value */
static
BOOL
HiveValue(
    _In_ PHIVE Hive,
    _In_ ULONG KeyOffset,
    _In_z_ PCWSTR Name,
    _Out_ PULONG Type,
    _Outptr_result_bytebuffer_(*Length) const UCHAR **Data,
    _Out_ PULONG Length)
{
    const UCHAR *Key = HiveKey(Hive, KeyOffset);
    const UCHAR *List;
    ULONG Count, Index;

    if (!Key)
        return FALSE;

    Count = Le32(Key + 0x24);
    List = HiveCell(Hive, Le32(Key + 0x28), Count * 4);
    if (!Count || !List)
        return FALSE;

    for (Index = 0; Index < Count; Index++)
    {
        ULONG ValueOffset = Le32(List + Index * 4);
        const UCHAR *Value = HiveCell(Hive, ValueOffset, 0x14);
        WCHAR ValueName[256];
        ULONG Size, DataOffset;

        if (!Value || Value[0] != 'v' || Value[1] != 'k' || !HiveCell(Hive, ValueOffset, 0x14 + Le16(Value + 2)))
            continue;

        HiveName(Value + 0x14, Le16(Value + 2), (Le16(Value + 0x10) & HIVE_VALUE_COMPRESSED) != 0,
                 ValueName, ARRAYSIZE(ValueName));
        if (_wcsicmp(ValueName, Name))
            continue;

        Size = Le32(Value + 4);
        DataOffset = Le32(Value + 8);
        *Type = Le32(Value + 0x0C);

        /* Four bytes or less live in the offset field itself */
        if (Size & HIVE_DATA_INLINE)
        {
            *Data = Value + 8;
            *Length = min(Size & ~HIVE_DATA_INLINE, 4);
            return TRUE;
        }

        *Data = HiveCell(Hive, DataOffset, Size);
        *Length = Size;
        return *Data != NULL;
    }
    return FALSE;
}

static
VOID
HiveString(
    _In_ PHIVE Hive,
    _In_ ULONG Key,
    _In_z_ PCWSTR Name,
    _Out_writes_z_(Size) PWSTR Out,
    _In_ SIZE_T Size)
{
    const UCHAR *Data;
    ULONG Type, Length;

    Out[0] = UNICODE_NULL;
    if (!HiveValue(Hive, Key, Name, &Type, &Data, &Length) || (Type != REG_SZ && Type != REG_EXPAND_SZ))
        return;

    Length = (ULONG)min(Length / sizeof(WCHAR), Size - 1);
    memcpy(Out, Data, Length * sizeof(WCHAR));
    Out[Length] = UNICODE_NULL;
}

static
ULONG
HiveDword(
    _In_ PHIVE Hive,
    _In_ ULONG Key,
    _In_z_ PCWSTR Name,
    _In_ ULONG Default)
{
    const UCHAR *Data;
    ULONG Type, Length;

    if (!HiveValue(Hive, Key, Name, &Type, &Data, &Length) || Type != REG_DWORD || Length < 4)
        return Default;
    return Le32(Data);
}

typedef struct _HIVE_SERVICES
{
    PCWSTR MountDir;
    RMS_SERVICE_ROUTINE Routine;
    PVOID Context;
} HIVE_SERVICES;

/* An image path like system32\drivers\x.sys or \SystemRoot\..., found on the live tree */
static
BOOL
ServicePresent(
    _In_opt_z_ PCWSTR MountDir,
    _In_z_ PCWSTR ImagePath,
    _In_z_ PCWSTR Name)
{
    WCHAR Path[MAX_PATH * 2];
    PCWSTR Relative = ImagePath;

    if (!MountDir)
        return TRUE;

    if (!_wcsnicmp(Relative, L"\\SystemRoot\\", 12))
        Relative += 12;
    else if (!_wcsnicmp(Relative, L"%SystemRoot%\\", 13))
        Relative += 13;

    if (Relative[0])
        swprintf_s(Path, ARRAYSIZE(Path), L"%s\\reactos\\%s", MountDir, Relative);
    else
        swprintf_s(Path, ARRAYSIZE(Path), L"%s\\reactos\\system32\\drivers\\%s.sys", MountDir, Name);
    return RmsFileExists(Path);
}

static
BOOL
HiveService(
    _In_ PHIVE Hive,
    _In_ ULONG Offset,
    _In_opt_ PVOID Context)
{
    HIVE_SERVICES *Services = Context;
    const UCHAR *Key = HiveKey(Hive, Offset);
    RMS_SERVICE Service;

    if (!Key)
        return FALSE;

    ZeroMemory(&Service, sizeof(Service));
    HiveName(Key + 0x4C, Le16(Key + 0x48), (Le16(Key + 2) & HIVE_KEY_COMPRESSED) != 0,
             Service.Name, ARRAYSIZE(Service.Name));

    Service.Type = HiveDword(Hive, Offset, L"Type", 0);
    Service.Start = HiveDword(Hive, Offset, L"Start", SERVICE_DISABLED);
    HiveString(Hive, Offset, L"DisplayName", Service.DisplayName, ARRAYSIZE(Service.DisplayName));
    HiveString(Hive, Offset, L"Group", Service.Group, ARRAYSIZE(Service.Group));
    HiveString(Hive, Offset, L"ImagePath", Service.ImagePath, ARRAYSIZE(Service.ImagePath));

    /* Kernel and file system drivers, the services the image boots or loads on demand */
    if (Service.Type & (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER))
    {
        Service.Present = ServicePresent(Services->MountDir, Service.ImagePath, Service.Name);
        Services->Routine(&Service, Services->Context);
    }
    return FALSE;
}

/**
 * @brief Lists the driver services of a SYSTEM hive file.
 *
 * @param[in] MountDir
 * The mounted image, to tell whether each driver's file is on the media.
 */
BOOL
RmsEnumServices(
    _In_z_ PCWSTR HivePath,
    _In_opt_z_ PCWSTR MountDir,
    _In_ RMS_SERVICE_ROUTINE Routine,
    _In_opt_ PVOID Context)
{
    HIVE Hive;
    HIVE_SERVICES Services;
    HANDLE File;
    LARGE_INTEGER Size;
    DWORD Read;
    ULONG Root, Select, Services_;
    WCHAR ControlSet[64];

    File = CreateFileW(HivePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (File == INVALID_HANDLE_VALUE)
    {
        RmsError(L"cannot open the hive %s (%lu)", HivePath, GetLastError());
        return FALSE;
    }

    if (!GetFileSizeEx(File, &Size) || Size.QuadPart < HIVE_BASE_BLOCK || Size.QuadPart > 512 * 1024 * 1024)
    {
        CloseHandle(File);
        return FALSE;
    }

    Hive.Size = (ULONG)Size.QuadPart;
    Hive.Data = malloc(Hive.Size);
    if (!Hive.Data || !ReadFile(File, Hive.Data, Hive.Size, &Read, NULL) || Read != Hive.Size ||
        memcmp(Hive.Data, "regf", 4))
    {
        RmsError(L"%s is not a registry hive", HivePath);
        CloseHandle(File);
        free(Hive.Data);
        return FALSE;
    }
    CloseHandle(File);

    /* The current control set, as the loader picks it */
    Root = Le32(Hive.Data + 0x24);
    Select = HiveOpen(&Hive, Root, L"Select");
    swprintf_s(ControlSet, ARRAYSIZE(ControlSet), L"ControlSet%03lu\\Services",
               Select != 0xFFFFFFFF ? HiveDword(&Hive, Select, L"Current", 1) : 1);

    Services_ = HiveOpen(&Hive, Root, ControlSet);
    if (Services_ == 0xFFFFFFFF)
    {
        RmsError(L"%s has no %s", HivePath, ControlSet);
        free(Hive.Data);
        return FALSE;
    }

    Services.MountDir = MountDir;
    Services.Routine = Routine;
    Services.Context = Context;
    {
        const UCHAR *Key = HiveKey(&Hive, Services_);

        if (Key && Le32(Key + 0x14))
            HiveWalkList(&Hive, Le32(Key + 0x1C), HiveService, &Services, 0);
    }

    free(Hive.Data);
    return TRUE;
}
