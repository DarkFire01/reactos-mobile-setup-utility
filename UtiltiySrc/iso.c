/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     ISO 9660 image extraction
 */

#include "rmsetup.h"

#define ISO_SECTOR              2048
#define ISO_FIRST_DESCRIPTOR    16

#define ISO_TYPE_PRIMARY        1
#define ISO_TYPE_SUPPLEMENTARY  2
#define ISO_TYPE_TERMINATOR     255

#define ISO_FLAG_DIRECTORY      0x02

typedef struct _ISO_READER
{
    HANDLE File;
    BOOL Joliet;
    ULONG Depth;
} ISO_READER, *PISO_READER;

static
BOOL
IsoRead(
    _In_ PISO_READER Reader,
    _In_ ULONGLONG Offset,
    _Out_writes_bytes_(Length) PVOID Buffer,
    _In_ DWORD Length)
{
    LARGE_INTEGER Position;
    DWORD Read;

    Position.QuadPart = (LONGLONG)Offset;
    return SetFilePointerEx(Reader->File, Position, NULL, FILE_BEGIN) &&
           ReadFile(Reader->File, Buffer, Length, &Read, NULL) && Read == Length;
}

static
ULONG
IsoLe32(
    _In_reads_(4) const UCHAR *Data)
{
    return Data[0] | (Data[1] << 8) | (Data[2] << 16) | ((ULONG)Data[3] << 24);
}

/* Names of the tree being walked, Joliet ones are UCS-2 big endian */
static
VOID
IsoName(
    _In_ PISO_READER Reader,
    _In_reads_(Length) const UCHAR *Raw,
    _In_ ULONG Length,
    _Out_writes_z_(Size) PWSTR Name,
    _In_ SIZE_T Size)
{
    SIZE_T Count = 0;
    ULONG Index;
    PWCHAR Version;

    if (Reader->Joliet)
    {
        for (Index = 0; Index + 1 < Length && Count + 1 < Size; Index += 2)
            Name[Count++] = (WCHAR)((Raw[Index] << 8) | Raw[Index + 1]);
    }
    else
    {
        for (Index = 0; Index < Length && Count + 1 < Size; Index++)
            Name[Count++] = Raw[Index];
    }
    Name[Count] = UNICODE_NULL;

    /* Plain ISO 9660 names end in ;1, and in a dot when they have no extension */
    Version = wcschr(Name, L';');
    if (Version)
        *Version = UNICODE_NULL;
    Count = wcslen(Name);
    if (Count && Name[Count - 1] == L'.')
        Name[Count - 1] = UNICODE_NULL;
}

static
BOOL
IsoExtractFile(
    _In_ PISO_READER Reader,
    _In_ ULONG Extent,
    _In_ ULONG Size,
    _In_z_ PCWSTR Path)
{
    HANDLE Out;
    PUCHAR Buffer;
    ULONG Done = 0, Chunk;
    DWORD Written;
    BOOL Ok = TRUE;

    Out = CreateFileW(Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (Out == INVALID_HANDLE_VALUE)
    {
        RmsError(L"cannot create %s (%lu)", Path, GetLastError());
        return FALSE;
    }

    Buffer = malloc(64 * ISO_SECTOR);
    while (Ok && Done < Size)
    {
        Chunk = min(Size - Done, 64 * ISO_SECTOR);
        Ok = IsoRead(Reader, (ULONGLONG)Extent * ISO_SECTOR + Done, Buffer, Chunk) &&
             WriteFile(Out, Buffer, Chunk, &Written, NULL);
        Done += Chunk;
    }

    free(Buffer);
    CloseHandle(Out);
    return Ok;
}

static
BOOL
IsoExtractDirectory(
    _In_ PISO_READER Reader,
    _In_ ULONG Extent,
    _In_ ULONG Size,
    _In_z_ PCWSTR Path)
{
    PUCHAR Data;
    ULONG Offset = 0;
    BOOL Ok = TRUE;

    if (++Reader->Depth > 64)
        return FALSE;

    Data = malloc(Size);
    if (!Data || !IsoRead(Reader, (ULONGLONG)Extent * ISO_SECTOR, Data, Size))
    {
        free(Data);
        return FALSE;
    }

    RmsMakeDirectories(Path);
    while (Offset < Size)
    {
        const UCHAR *Record = Data + Offset;
        ULONG RecordLength = Record[0];
        WCHAR Name[256];
        PWSTR Child;

        /* Records never cross a sector, the rest of one is padding */
        if (RecordLength == 0)
        {
            Offset = (Offset / ISO_SECTOR + 1) * ISO_SECTOR;
            continue;
        }

        if (Offset + RecordLength > Size || RecordLength < 34)
            break;

        /* The first two records are the directory itself and its parent */
        if (!(Record[32] == 1 && (Record[33] == 0 || Record[33] == 1)))
        {
            IsoName(Reader, Record + 33, Record[32], Name, ARRAYSIZE(Name));
            Child = RmsJoin(Path, Name);
            if (Record[25] & ISO_FLAG_DIRECTORY)
                Ok = IsoExtractDirectory(Reader, IsoLe32(Record + 2), IsoLe32(Record + 10), Child) && Ok;
            else
                Ok = IsoExtractFile(Reader, IsoLe32(Record + 2), IsoLe32(Record + 10), Child) && Ok;
            free(Child);
        }

        Offset += RecordLength;
    }

    free(Data);
    Reader->Depth--;
    return Ok;
}

/**
 * @brief Extracts every file of an ISO 9660 image.
 *
 * The Joliet tree is used when there is one, then the ISO 9660:1999 one mkisofs
 * writes for -iso-level 4, then the primary one.
 */
BOOL
RmsExtractIso(
    _In_z_ PCWSTR ImageFile,
    _In_z_ PCWSTR Directory,
    _Out_writes_z_(VolumeSize) PWSTR VolumeId,
    _In_ SIZE_T VolumeSize)
{
    ISO_READER Reader;
    UCHAR Descriptor[ISO_SECTOR], Root[34], Primary[34], Enhanced[34];
    BOOL HavePrimary = FALSE, HaveEnhanced = FALSE, HaveJoliet = FALSE;
    ULONG Sector;
    SIZE_T Index;
    BOOL Ok;

    ZeroMemory(&Reader, sizeof(Reader));
    VolumeId[0] = UNICODE_NULL;

    Reader.File = CreateFileW(ImageFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (Reader.File == INVALID_HANDLE_VALUE)
    {
        RmsError(L"cannot open %s (%lu)", ImageFile, GetLastError());
        return FALSE;
    }

    for (Sector = ISO_FIRST_DESCRIPTOR; Sector < ISO_FIRST_DESCRIPTOR + 32; Sector++)
    {
        if (!IsoRead(&Reader, (ULONGLONG)Sector * ISO_SECTOR, Descriptor, ISO_SECTOR) ||
            memcmp(Descriptor + 1, "CD001", 5))
        {
            break;
        }

        if (Descriptor[0] == ISO_TYPE_TERMINATOR)
            break;

        if (Descriptor[0] == ISO_TYPE_PRIMARY)
        {
            memcpy(Primary, Descriptor + 156, sizeof(Primary));
            HavePrimary = TRUE;

            /* The volume id is 32 padded characters */
            for (Index = 0; Index < 32 && Index + 1 < VolumeSize; Index++)
                VolumeId[Index] = Descriptor[40 + Index];
            VolumeId[Index] = UNICODE_NULL;
            while (Index && VolumeId[Index - 1] == L' ')
                VolumeId[--Index] = UNICODE_NULL;
        }
        else if (Descriptor[0] == ISO_TYPE_SUPPLEMENTARY)
        {
            /* Joliet marks its escape sequence, the 1999 descriptor is version 2 */
            if (Descriptor[88] == '%' && Descriptor[89] == '/' &&
                (Descriptor[90] == '@' || Descriptor[90] == 'C' || Descriptor[90] == 'E'))
            {
                memcpy(Root, Descriptor + 156, sizeof(Root));
                HaveJoliet = TRUE;
            }
            else if (Descriptor[6] == 2)
            {
                memcpy(Enhanced, Descriptor + 156, sizeof(Enhanced));
                HaveEnhanced = TRUE;
            }
        }
    }

    if (HaveJoliet)
        Reader.Joliet = TRUE;
    else if (HaveEnhanced)
        memcpy(Root, Enhanced, sizeof(Root));
    else if (HavePrimary)
        memcpy(Root, Primary, sizeof(Root));
    else
    {
        RmsError(L"%s is not an ISO 9660 image", ImageFile);
        CloseHandle(Reader.File);
        return FALSE;
    }

    RmsInfo(L"Extracting %s (%s names)", ImageFile,
            HaveJoliet ? L"Joliet" : HaveEnhanced ? L"ISO 9660:1999" : L"ISO 9660");
    Ok = IsoExtractDirectory(&Reader, IsoLe32(Root + 2), IsoLe32(Root + 10), Directory);
    CloseHandle(Reader.File);
    return Ok;
}
