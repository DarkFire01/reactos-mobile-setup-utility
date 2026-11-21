/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Files, text and processes
 */

#include "rmsetup.h"
#include <stdarg.h>

RMS_LOG_ROUTINE RmsLogRoutine;

static
VOID
RmsLog(
    _In_ BOOL Error,
    _In_z_ PCWSTR Format,
    _In_ va_list Args)
{
    WCHAR Message[2048];

    _vsnwprintf_s(Message, ARRAYSIZE(Message), _TRUNCATE, Format, Args);
    if (RmsLogRoutine)
        RmsLogRoutine(Error, Message);
    else if (Error)
        fwprintf(stderr, L"error: %s\n", Message);
    else
        wprintf(L"%s\n", Message);
}

VOID
RmsError(
    _In_z_ _Printf_format_string_ PCWSTR Format, ...)
{
    va_list Args;

    va_start(Args, Format);
    RmsLog(TRUE, Format, Args);
    va_end(Args);
}

VOID
RmsInfo(
    _In_z_ _Printf_format_string_ PCWSTR Format, ...)
{
    va_list Args;

    va_start(Args, Format);
    RmsLog(FALSE, Format, Args);
    va_end(Args);
}

/* First\Second, freed by the caller */
PWSTR
RmsJoin(
    _In_z_ PCWSTR First,
    _In_z_ PCWSTR Second)
{
    SIZE_T Length = wcslen(First) + wcslen(Second) + 2;
    PWSTR Path = malloc(Length * sizeof(WCHAR));
    SIZE_T FirstLength = wcslen(First);

    if (!Path)
        exit(1);

    wcscpy_s(Path, Length, First);
    if (FirstLength && First[FirstLength - 1] != L'\\' && First[FirstLength - 1] != L'/' && Second[0])
        wcscat_s(Path, Length, L"\\");
    wcscat_s(Path, Length, Second);
    return Path;
}

BOOL
RmsMakeDirectories(
    _In_z_ PCWSTR Path)
{
    WCHAR Partial[MAX_PATH * 4];
    SIZE_T Index;

    if (wcslen(Path) >= ARRAYSIZE(Partial))
        return FALSE;

    for (Index = 0; Path[Index]; Index++)
    {
        Partial[Index] = (Path[Index] == L'/') ? L'\\' : Path[Index];
        if (Partial[Index] == L'\\' && Index > 0 && Partial[Index - 1] != L':')
        {
            Partial[Index] = UNICODE_NULL;
            CreateDirectoryW(Partial, NULL);
            Partial[Index] = L'\\';
        }
    }
    Partial[Index] = UNICODE_NULL;

    return CreateDirectoryW(Partial, NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}

BOOL
RmsDirectoryExists(
    _In_z_ PCWSTR Path)
{
    DWORD Attributes = GetFileAttributesW(Path);

    return Attributes != INVALID_FILE_ATTRIBUTES && (Attributes & FILE_ATTRIBUTE_DIRECTORY);
}

BOOL
RmsFileExists(
    _In_z_ PCWSTR Path)
{
    DWORD Attributes = GetFileAttributesW(Path);

    return Attributes != INVALID_FILE_ATTRIBUTES && !(Attributes & FILE_ATTRIBUTE_DIRECTORY);
}

BOOL
RmsDirectoryEmpty(
    _In_z_ PCWSTR Path)
{
    WIN32_FIND_DATAW Find;
    PWSTR Pattern = RmsJoin(Path, L"*");
    HANDLE Handle = FindFirstFileW(Pattern, &Find);
    BOOL Empty = TRUE;

    free(Pattern);
    if (Handle == INVALID_HANDLE_VALUE)
        return TRUE;

    do
    {
        if (wcscmp(Find.cFileName, L".") && wcscmp(Find.cFileName, L".."))
        {
            Empty = FALSE;
            break;
        }
    } while (FindNextFileW(Handle, &Find));

    FindClose(Handle);
    return Empty;
}

/* Copies a file into a directory or onto a file path, making the directories on the way */
BOOL
RmsCopyFileTo(
    _In_z_ PCWSTR Source,
    _In_z_ PCWSTR Destination)
{
    WCHAR Directory[MAX_PATH * 4];
    PWCHAR Slash;

    wcscpy_s(Directory, ARRAYSIZE(Directory), Destination);
    Slash = wcsrchr(Directory, L'\\');
    if (Slash)
    {
        *Slash = UNICODE_NULL;
        RmsMakeDirectories(Directory);
    }

    if (!CopyFileW(Source, Destination, FALSE))
    {
        RmsError(L"cannot copy %s to %s (%lu)", Source, Destination, GetLastError());
        return FALSE;
    }

    /* Files off read-only media keep the attribute, the image has to stay writable */
    SetFileAttributesW(Destination, FILE_ATTRIBUTE_NORMAL);
    return TRUE;
}

BOOL
RmsCopyTree(
    _In_z_ PCWSTR Source,
    _In_z_ PCWSTR Destination)
{
    WIN32_FIND_DATAW Find;
    PWSTR Pattern = RmsJoin(Source, L"*");
    HANDLE Handle = FindFirstFileW(Pattern, &Find);
    BOOL Ok = TRUE;

    free(Pattern);
    if (Handle == INVALID_HANDLE_VALUE)
        return FALSE;

    RmsMakeDirectories(Destination);
    do
    {
        PWSTR From, To;

        if (!wcscmp(Find.cFileName, L".") || !wcscmp(Find.cFileName, L".."))
            continue;

        From = RmsJoin(Source, Find.cFileName);
        To = RmsJoin(Destination, Find.cFileName);
        if (Find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            Ok = RmsCopyTree(From, To) && Ok;
        else
            Ok = RmsCopyFileTo(From, To) && Ok;
        free(From);
        free(To);
    } while (FindNextFileW(Handle, &Find));

    FindClose(Handle);
    return Ok;
}

/* Reads UTF-16 with a byte order mark, UTF-8 or ANSI text, freed by the caller */
PWSTR
RmsReadText(
    _In_z_ PCWSTR Path)
{
    HANDLE File;
    LARGE_INTEGER Size;
    PUCHAR Data;
    PWSTR Text;
    DWORD Read;
    int Chars;

    File = CreateFileW(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (File == INVALID_HANDLE_VALUE)
        return NULL;

    if (!GetFileSizeEx(File, &Size) || Size.QuadPart > 64 * 1024 * 1024)
    {
        CloseHandle(File);
        return NULL;
    }

    Data = malloc((SIZE_T)Size.QuadPart + 2);
    if (!Data || !ReadFile(File, Data, (DWORD)Size.QuadPart, &Read, NULL))
    {
        CloseHandle(File);
        free(Data);
        return NULL;
    }
    CloseHandle(File);

    if (Read >= 2 && Data[0] == 0xFF && Data[1] == 0xFE)
    {
        Text = malloc(Read + sizeof(WCHAR));
        memcpy(Text, Data + 2, Read - 2);
        Text[(Read - 2) / sizeof(WCHAR)] = UNICODE_NULL;
    }
    else
    {
        UINT CodePage = CP_ACP;
        PUCHAR Start = Data;
        DWORD Length = Read;

        if (Read >= 3 && Data[0] == 0xEF && Data[1] == 0xBB && Data[2] == 0xBF)
        {
            CodePage = CP_UTF8;
            Start += 3;
            Length -= 3;
        }

        Chars = MultiByteToWideChar(CodePage, 0, (LPCSTR)Start, Length, NULL, 0);
        Text = malloc((Chars + 1) * sizeof(WCHAR));
        MultiByteToWideChar(CodePage, 0, (LPCSTR)Start, Length, Text, Chars);
        Text[Chars] = UNICODE_NULL;
    }

    free(Data);
    return Text;
}

/* Writes UTF-16LE with a byte order mark, as the registry INFs of the build are */
BOOL
RmsWriteText(
    _In_z_ PCWSTR Path,
    _In_z_ PCWSTR Text)
{
    static const UCHAR Bom[2] = { 0xFF, 0xFE };
    HANDLE File;
    DWORD Written;
    BOOL Ok;

    File = CreateFileW(Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (File == INVALID_HANDLE_VALUE)
    {
        RmsError(L"cannot write %s (%lu)", Path, GetLastError());
        return FALSE;
    }

    Ok = WriteFile(File, Bom, sizeof(Bom), &Written, NULL) &&
         WriteFile(File, Text, (DWORD)(wcslen(Text) * sizeof(WCHAR)), &Written, NULL);
    CloseHandle(File);
    return Ok;
}

/* The ORDER manifest is plain text, one name per line */
BOOL
RmsAppendLine(
    _In_z_ PCWSTR Path,
    _In_z_ PCWSTR Line)
{
    FILE *File;

    if (_wfopen_s(&File, Path, L"a, ccs=UTF-8") || !File)
        return FALSE;

    fwprintf(File, L"%s\n", Line);
    fclose(File);
    return TRUE;
}

BOOL
RmsRun(
    _In_z_ PCWSTR CommandLine)
{
    STARTUPINFOW Startup;
    PROCESS_INFORMATION Process;
    PWSTR Mutable = _wcsdup(CommandLine);
    DWORD ExitCode = 1;

    ZeroMemory(&Startup, sizeof(Startup));
    Startup.cb = sizeof(Startup);

    if (!CreateProcessW(NULL, Mutable, NULL, NULL, FALSE, 0, NULL, NULL, &Startup, &Process))
    {
        RmsError(L"cannot run %s (%lu)", CommandLine, GetLastError());
        free(Mutable);
        return FALSE;
    }

    WaitForSingleObject(Process.hProcess, INFINITE);
    GetExitCodeProcess(Process.hProcess, &ExitCode);
    CloseHandle(Process.hThread);
    CloseHandle(Process.hProcess);
    free(Mutable);

    if (ExitCode)
        RmsError(L"%s failed with %lu", CommandLine, ExitCode);
    return ExitCode == 0;
}

/* The ReactOS host tools travel beside the utility in tools\ */
PCWSTR
RmsToolPath(
    _In_z_ PCWSTR Tool)
{
    static WCHAR Path[MAX_PATH * 2];
    PWCHAR Slash;

    GetModuleFileNameW(NULL, Path, MAX_PATH);
    Slash = wcsrchr(Path, L'\\');
    if (Slash)
        Slash[1] = UNICODE_NULL;

    wcscat_s(Path, ARRAYSIZE(Path), L"tools\\");
    wcscat_s(Path, ARRAYSIZE(Path), Tool);
    return Path;
}

VOID
RmsTextAppend(
    _Inout_ PRMS_TEXT Text,
    _In_z_ PCWSTR String)
{
    SIZE_T Length = wcslen(String);

    if (Text->Length + Length + 1 > Text->Capacity)
    {
        SIZE_T Capacity = max(Text->Capacity * 2, Text->Length + Length + 1024);
        PWSTR Buffer = realloc(Text->Buffer, Capacity * sizeof(WCHAR));

        if (!Buffer)
            exit(1);
        Text->Buffer = Buffer;
        Text->Capacity = Capacity;
    }

    memcpy(Text->Buffer + Text->Length, String, (Length + 1) * sizeof(WCHAR));
    Text->Length += Length;
}

VOID
RmsTextAppendF(
    _Inout_ PRMS_TEXT Text,
    _In_z_ _Printf_format_string_ PCWSTR Format, ...)
{
    WCHAR Line[4096];
    va_list Args;

    va_start(Args, Format);
    _vsnwprintf_s(Line, ARRAYSIZE(Line), _TRUNCATE, Format, Args);
    va_end(Args);
    RmsTextAppend(Text, Line);
}

VOID
RmsTextFree(
    _Inout_ PRMS_TEXT Text)
{
    free(Text->Buffer);
    ZeroMemory(Text, sizeof(*Text));
}
