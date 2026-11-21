/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Graphical front end
 */

/*
 * One window: the actions along the top, the image's drivers in a list, the log
 * under it. Servicing runs on a worker thread; it logs through posted messages and
 * asks about each driver through a sent one, so the question shows on the UI thread.
 */

#include "rmsetup.h"
#include <commctrl.h>
#include <commdlg.h>
#include <shlobj.h>
#include <shobjidl.h>

#define ID_LIST         100
#define ID_LOG          101
#define ID_STATUS       102
#define ID_FIRST_ACTION 200

#define WM_APP_LOG      (WM_APP + 1)
#define WM_APP_PROMPT   (WM_APP + 2)
#define WM_APP_DONE     (WM_APP + 3)

typedef enum _ACTION
{
    ActionOpenIso,
    ActionOpenFolder,
    ActionAddDriverFolder,
    ActionAddDriverInf,
    ActionAddPackage,
    ActionAddFirmware,
    ActionAddOverlay,
    ActionAddRegistry,
    ActionCommit,
    ActionRefresh,
    ActionCount
} ACTION;

static PCWSTR ActionLabels[ActionCount] =
{
    L"Open ISO...", L"Open folder...", L"Add drivers...", L"Add INF...", L"Add package...",
    L"Add firmware...", L"Add overlay...", L"Add registry...", L"Commit ISO...", L"Refresh"
};

typedef struct _PROMPT_REQUEST
{
    PCWSTR InfPath;
    PCWSTR Summary;
    RMS_CHOICE Choice;
} PROMPT_REQUEST;

typedef struct _WORK
{
    ACTION Action;
    WCHAR Path[MAX_PATH];
    WCHAR Second[MAX_PATH];
} WORK;

static HWND MainWindow, ListWindow, LogWindow, StatusWindow;
static HWND Buttons[ActionCount];
static WCHAR MountDir[MAX_PATH];
static volatile LONG Busy;

static
VOID
GuiLog(
    _In_ BOOL Error,
    _In_z_ PCWSTR Message)
{
    SIZE_T Length = wcslen(Message) + 16;
    PWSTR Copy = malloc(Length * sizeof(WCHAR));

    if (!Copy)
        return;
    swprintf_s(Copy, Length, L"%s%s\r\n", Error ? L"error: " : L"", Message);
    if (!PostMessageW(MainWindow, WM_APP_LOG, 0, (LPARAM)Copy))
        free(Copy);
}

static
RMS_CHOICE
GuiPrompt(
    _In_z_ PCWSTR InfPath,
    _In_z_ PCWSTR Summary,
    _In_opt_ PVOID Context)
{
    PROMPT_REQUEST Request = { InfPath, Summary, RmsChoiceCancel };

    UNREFERENCED_PARAMETER(Context);
    SendMessageW(MainWindow, WM_APP_PROMPT, 0, (LPARAM)&Request);
    return Request.Choice;
}

static
RMS_CHOICE
ShowPrompt(
    _In_ const PROMPT_REQUEST *Request)
{
    static const TASKDIALOG_BUTTON Choices[] =
    {
        { RmsChoiceInstall + 1000, L"Install" },
        { RmsChoiceBootStart + 1000, L"Install as boot start" },
        { RmsChoiceSkip + 1000, L"Skip" },
        { RmsChoiceInstallAll + 1000, L"Install all remaining" },
        { RmsChoiceCancel + 1000, L"Stop" },
    };
    TASKDIALOGCONFIG Config;
    int Pressed = RmsChoiceCancel + 1000;

    ZeroMemory(&Config, sizeof(Config));
    Config.cbSize = sizeof(Config);
    Config.hwndParent = MainWindow;
    Config.pszWindowTitle = L"Add driver";
    Config.pszMainInstruction = Request->InfPath;
    Config.pszContent = Request->Summary;
    Config.pButtons = Choices;
    Config.cButtons = ARRAYSIZE(Choices);
    Config.nDefaultButton = RmsChoiceInstall + 1000;
    Config.dwFlags = TDF_SIZE_TO_CONTENT;

    if (FAILED(TaskDialogIndirect(&Config, &Pressed, NULL, NULL)))
        return RmsChoiceCancel;
    return (RMS_CHOICE)(Pressed - 1000);
}

static
VOID
SetStatus(VOID)
{
    WCHAR Text[MAX_PATH + 32];

    swprintf_s(Text, ARRAYSIZE(Text), MountDir[0] ? L"Image: %s" : L"No image%s", MountDir);
    SendMessageW(StatusWindow, SB_SETTEXTW, 0, (LPARAM)Text);
}

static
VOID
EnableActions(
    _In_ BOOL Enable)
{
    ULONG Index;

    for (Index = 0; Index < ActionCount; Index++)
    {
        BOOL NeedsImage = Index != ActionOpenIso && Index != ActionOpenFolder;

        EnableWindow(Buttons[Index], Enable && (!NeedsImage || MountDir[0]));
    }
}

static
PCWSTR
StartName(
    _In_ ULONG Start)
{
    static PCWSTR Names[] = { L"Boot", L"System", L"Auto", L"Demand", L"Disabled" };

    return Start < ARRAYSIZE(Names) ? Names[Start] : L"?";
}

static
VOID
AddRow(
    _In_z_ PCWSTR Name,
    _In_z_ PCWSTR Start,
    _In_z_ PCWSTR Group,
    _In_z_ PCWSTR Image,
    _In_z_ PCWSTR State)
{
    LVITEMW Item;
    int Row;

    ZeroMemory(&Item, sizeof(Item));
    Item.mask = LVIF_TEXT;
    Item.iItem = ListView_GetItemCount(ListWindow);
    Item.pszText = (PWSTR)Name;
    Row = ListView_InsertItem(ListWindow, &Item);

    ListView_SetItemText(ListWindow, Row, 1, (PWSTR)Start);
    ListView_SetItemText(ListWindow, Row, 2, (PWSTR)Group);
    ListView_SetItemText(ListWindow, Row, 3, (PWSTR)Image);
    ListView_SetItemText(ListWindow, Row, 4, (PWSTR)State);
}

static
VOID
ListService(
    _In_ const RMS_SERVICE *Service,
    _In_opt_ PVOID Context)
{
    UNREFERENCED_PARAMETER(Context);

    AddRow(Service->Name, StartName(Service->Start), Service->Group,
           Service->ImagePath[0] ? Service->ImagePath : L"(default)",
           Service->Present ? L"in image" : L"file missing");
}

/* The hive's drivers, boot ones first, then the registry INFs the next commit applies */
static
VOID
Refresh(VOID)
{
    PWSTR Order, Text, Line, Context = NULL;

    ListView_DeleteAllItems(ListWindow);
    SetStatus();
    if (!MountDir[0])
        return;

    SendMessageW(ListWindow, WM_SETREDRAW, FALSE, 0);
    RmsListServices(MountDir, ListService, NULL);

    Order = RmsJoin(MountDir, RMS_ORDER_FILE);
    Text = RmsReadText(Order);
    for (Line = Text ? wcstok_s(Text, L"\r\n", &Context) : NULL; Line; Line = wcstok_s(NULL, L"\r\n", &Context))
        AddRow(Line, L"", L"", L"rmsetup\\registry", L"applied at commit");
    free(Text);
    free(Order);

    SendMessageW(ListWindow, WM_SETREDRAW, TRUE, 0);
}

static
DWORD
WINAPI
Worker(
    _In_ LPVOID Parameter)
{
    WORK *Work = Parameter;
    RMS_DRIVER_OPTIONS Options;
    int Result = 0;

    ZeroMemory(&Options, sizeof(Options));
    switch (Work->Action)
    {
        case ActionOpenIso:
            Result = RmsMountImage(Work->Path, Work->Second);
            if (!Result)
                wcscpy_s(MountDir, ARRAYSIZE(MountDir), Work->Second);
            break;

        case ActionAddDriverFolder:
            Result = RmsAddDriver(MountDir, Work->Path, TRUE, &Options, GuiPrompt, NULL);
            break;

        case ActionAddDriverInf:
            Result = RmsAddDriver(MountDir, Work->Path, FALSE, &Options, NULL, NULL);
            break;

        case ActionAddPackage:
            Result = RmsAddPackage(MountDir, Work->Path);
            break;

        case ActionAddFirmware:
            Result = RmsAddFirmware(MountDir, Work->Path, NULL);
            break;

        case ActionAddOverlay:
            Result = RmsAddOverlay(MountDir, Work->Path);
            break;

        case ActionAddRegistry:
            Result = RmsAddRegistry(MountDir, Work->Path);
            break;

        case ActionCommit:
            Result = RmsCommitImage(MountDir, Work->Path);
            break;

        default:
            break;
    }

    PostMessageW(MainWindow, WM_APP_DONE, (WPARAM)Result, 0);
    free(Work);
    return 0;
}

static
BOOL
PickFolder(
    _In_z_ PCWSTR Title,
    _Out_writes_z_(Size) PWSTR Path,
    _In_ SIZE_T Size)
{
    IFileOpenDialog *Dialog;
    IShellItem *Item;
    PWSTR Name;
    BOOL Ok = FALSE;

    if (FAILED(CoCreateInstance(&CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, &IID_IFileOpenDialog, (void **)&Dialog)))
        return FALSE;

    Dialog->lpVtbl->SetOptions(Dialog, FOS_PICKFOLDERS | FOS_FORCEFILESYSTEM);
    Dialog->lpVtbl->SetTitle(Dialog, Title);
    if (SUCCEEDED(Dialog->lpVtbl->Show(Dialog, MainWindow)) &&
        SUCCEEDED(Dialog->lpVtbl->GetResult(Dialog, &Item)))
    {
        if (SUCCEEDED(Item->lpVtbl->GetDisplayName(Item, SIGDN_FILESYSPATH, &Name)))
        {
            wcscpy_s(Path, Size, Name);
            CoTaskMemFree(Name);
            Ok = TRUE;
        }
        Item->lpVtbl->Release(Item);
    }

    Dialog->lpVtbl->Release(Dialog);
    return Ok;
}

static
BOOL
PickFile(
    _In_z_ PCWSTR Filter,
    _In_ BOOL Save,
    _Out_writes_z_(Size) PWSTR Path,
    _In_ DWORD Size)
{
    OPENFILENAMEW Open;

    ZeroMemory(&Open, sizeof(Open));
    Path[0] = UNICODE_NULL;
    Open.lStructSize = sizeof(Open);
    Open.hwndOwner = MainWindow;
    Open.lpstrFilter = Filter;
    Open.lpstrFile = Path;
    Open.nMaxFile = Size;
    Open.Flags = Save ? (OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR) : (OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR);
    Open.lpstrDefExt = L"iso";
    return Save ? GetSaveFileNameW(&Open) : GetOpenFileNameW(&Open);
}

/* A fresh folder for the extracted image under the user's local application data */
static
VOID
MountFolderFor(
    _In_z_ PCWSTR ImageFile,
    _Out_writes_z_(Size) PWSTR Folder,
    _In_ SIZE_T Size)
{
    WCHAR Base[MAX_PATH], Name[MAX_PATH];
    PCWSTR Slash = wcsrchr(ImageFile, L'\\');
    PWCHAR Dot;
    ULONG Index;

    if (FAILED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, Base)))
        GetTempPathW(ARRAYSIZE(Base), Base);

    wcscpy_s(Name, ARRAYSIZE(Name), Slash ? Slash + 1 : ImageFile);
    Dot = wcsrchr(Name, L'.');
    if (Dot)
        *Dot = UNICODE_NULL;

    for (Index = 0; Index < 1000; Index++)
    {
        swprintf_s(Folder, Size, L"%s\\rmsetup\\images\\%s-%lu", Base, Name, Index);
        if (!RmsDirectoryExists(Folder) || RmsDirectoryEmpty(Folder))
            return;
    }
}

static
VOID
StartAction(
    _In_ ACTION Action)
{
    static const WCHAR IsoFilter[] = L"ISO images (*.iso)\0*.iso\0All files\0*.*\0";
    static const WCHAR InfFilter[] = L"Setup information (*.inf)\0*.inf\0All files\0*.*\0";
    WORK *Work;
    HANDLE Thread;
    BOOL Picked = FALSE;

    if (Busy)
        return;

    if (Action == ActionRefresh)
    {
        Refresh();
        return;
    }

    Work = calloc(1, sizeof(*Work));
    if (!Work)
        return;
    Work->Action = Action;

    switch (Action)
    {
        case ActionOpenIso:
            Picked = PickFile(IsoFilter, FALSE, Work->Path, ARRAYSIZE(Work->Path));
            if (Picked)
                MountFolderFor(Work->Path, Work->Second, ARRAYSIZE(Work->Second));
            break;

        case ActionOpenFolder:
            if (PickFolder(L"Mounted image folder", Work->Path, ARRAYSIZE(Work->Path)))
            {
                if (RmsIsMounted(Work->Path))
                {
                    wcscpy_s(MountDir, ARRAYSIZE(MountDir), Work->Path);
                    Refresh();
                    EnableActions(TRUE);
                }
                else
                {
                    GuiLog(TRUE, L"that folder is not a mounted image");
                }
            }
            free(Work);
            return;

        case ActionAddDriverFolder:
            Picked = PickFolder(L"Folder of drivers, searched with its subfolders", Work->Path, ARRAYSIZE(Work->Path));
            break;

        case ActionAddDriverInf:
        case ActionAddRegistry:
            Picked = PickFile(InfFilter, FALSE, Work->Path, ARRAYSIZE(Work->Path));
            break;

        case ActionAddPackage:
            Picked = PickFolder(L"Driver package (out\\drivers\\package)", Work->Path, ARRAYSIZE(Work->Path));
            break;

        case ActionAddFirmware:
            Picked = PickFolder(L"Firmware folder, copied into system32\\drivers", Work->Path, ARRAYSIZE(Work->Path));
            break;

        case ActionAddOverlay:
            Picked = PickFolder(L"Slipstream overlay folder", Work->Path, ARRAYSIZE(Work->Path));
            break;

        case ActionCommit:
            Picked = PickFile(IsoFilter, TRUE, Work->Path, ARRAYSIZE(Work->Path));
            break;

        default:
            break;
    }

    if (!Picked)
    {
        free(Work);
        return;
    }

    InterlockedExchange(&Busy, 1);
    EnableActions(FALSE);

    Thread = CreateThread(NULL, 0, Worker, Work, 0, NULL);
    if (Thread)
    {
        CloseHandle(Thread);
    }
    else
    {
        free(Work);
        InterlockedExchange(&Busy, 0);
        EnableActions(TRUE);
    }
}

static
VOID
Layout(
    _In_ int Width,
    _In_ int Height)
{
    RECT Status;
    int ButtonWidth = 112, ButtonHeight = 28, Margin = 6, Index, StatusHeight, ListHeight;
    int Columns = max(1, (Width - Margin) / (ButtonWidth + Margin));
    int Rows = (ActionCount + Columns - 1) / Columns;
    int Top = Margin + Rows * (ButtonHeight + Margin);

    for (Index = 0; Index < ActionCount; Index++)
    {
        MoveWindow(Buttons[Index], Margin + (Index % Columns) * (ButtonWidth + Margin),
                   Margin + (Index / Columns) * (ButtonHeight + Margin), ButtonWidth, ButtonHeight, TRUE);
    }

    SendMessageW(StatusWindow, WM_SIZE, 0, 0);
    GetWindowRect(StatusWindow, &Status);
    StatusHeight = Status.bottom - Status.top;

    ListHeight = (Height - Top - StatusHeight - 3 * Margin) * 2 / 3;
    MoveWindow(ListWindow, Margin, Top, Width - 2 * Margin, ListHeight, TRUE);
    MoveWindow(LogWindow, Margin, Top + ListHeight + Margin, Width - 2 * Margin,
               Height - Top - ListHeight - StatusHeight - 2 * Margin, TRUE);
}

static
LRESULT
CALLBACK
WindowProc(
    _In_ HWND Window,
    _In_ UINT Message,
    _In_ WPARAM WParam,
    _In_ LPARAM LParam)
{
    switch (Message)
    {
        case WM_CREATE:
        {
            static PCWSTR Columns[] = { L"Driver", L"Start", L"Group", L"Image", L"State" };
            static const int Widths[] = { 180, 70, 160, 300, 120 };
            HFONT Font = GetStockObject(DEFAULT_GUI_FONT);
            LVCOLUMNW Column;
            int Index;

            for (Index = 0; Index < ActionCount; Index++)
            {
                Buttons[Index] = CreateWindowW(L"BUTTON", ActionLabels[Index], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                               0, 0, 0, 0, Window, (HMENU)(INT_PTR)(ID_FIRST_ACTION + Index), NULL, NULL);
                SendMessageW(Buttons[Index], WM_SETFONT, (WPARAM)Font, TRUE);
            }

            ListWindow = CreateWindowExW(WS_EX_CLIENTEDGE, WC_LISTVIEWW, L"",
                                         WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SHOWSELALWAYS,
                                         0, 0, 0, 0, Window, (HMENU)ID_LIST, NULL, NULL);
            ListView_SetExtendedListViewStyle(ListWindow, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
            ZeroMemory(&Column, sizeof(Column));
            Column.mask = LVCF_TEXT | LVCF_WIDTH;
            for (Index = 0; Index < ARRAYSIZE(Columns); Index++)
            {
                Column.pszText = (PWSTR)Columns[Index];
                Column.cx = Widths[Index];
                ListView_InsertColumn(ListWindow, Index, &Column);
            }

            LogWindow = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
                                        WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL,
                                        0, 0, 0, 0, Window, (HMENU)ID_LOG, NULL, NULL);
            SendMessageW(LogWindow, WM_SETFONT, (WPARAM)Font, TRUE);
            SendMessageW(LogWindow, EM_SETLIMITTEXT, 0, 0);

            StatusWindow = CreateWindowW(STATUSCLASSNAMEW, L"", WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
                                         0, 0, 0, 0, Window, (HMENU)ID_STATUS, NULL, NULL);
            SetStatus();
            return 0;
        }

        case WM_SIZE:
            Layout(LOWORD(LParam), HIWORD(LParam));
            return 0;

        case WM_COMMAND:
            if (LOWORD(WParam) >= ID_FIRST_ACTION && LOWORD(WParam) < ID_FIRST_ACTION + ActionCount)
                StartAction((ACTION)(LOWORD(WParam) - ID_FIRST_ACTION));
            return 0;

        case WM_APP_LOG:
        {
            PWSTR Text = (PWSTR)LParam;
            int Length = GetWindowTextLengthW(LogWindow);

            SendMessageW(LogWindow, EM_SETSEL, Length, Length);
            SendMessageW(LogWindow, EM_REPLACESEL, FALSE, (LPARAM)Text);
            free(Text);
            return 0;
        }

        case WM_APP_PROMPT:
        {
            PROMPT_REQUEST *Request = (PROMPT_REQUEST *)LParam;

            Request->Choice = ShowPrompt(Request);
            return 0;
        }

        case WM_APP_DONE:
            InterlockedExchange(&Busy, 0);
            Refresh();
            EnableActions(TRUE);
            GuiLog(WParam != 0, WParam ? L"finished with errors" : L"done");
            return 0;

        case WM_GETMINMAXINFO:
            ((MINMAXINFO *)LParam)->ptMinTrackSize.x = 640;
            ((MINMAXINFO *)LParam)->ptMinTrackSize.y = 420;
            return 0;

        case WM_CLOSE:
            if (Busy && MessageBoxW(Window, L"Servicing is still running. Quit anyway?", L"ReactOS Mobile Setup",
                                    MB_YESNO | MB_ICONWARNING) != IDYES)
            {
                return 0;
            }
            DestroyWindow(Window);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(Window, Message, WParam, LParam);
}

int
WINAPI
wWinMain(
    _In_ HINSTANCE Instance,
    _In_opt_ HINSTANCE Previous,
    _In_ PWSTR CommandLine,
    _In_ int Show)
{
    INITCOMMONCONTROLSEX Controls = { sizeof(Controls), ICC_LISTVIEW_CLASSES | ICC_BAR_CLASSES };
    WNDCLASSW Class;
    MSG Message;

    UNREFERENCED_PARAMETER(Previous);
    UNREFERENCED_PARAMETER(CommandLine);

    InitCommonControlsEx(&Controls);
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    RmsLogRoutine = GuiLog;

    ZeroMemory(&Class, sizeof(Class));
    Class.lpfnWndProc = WindowProc;
    Class.hInstance = Instance;
    Class.hCursor = LoadCursorW(NULL, IDC_ARROW);
    Class.hIcon = LoadIconW(Instance, MAKEINTRESOURCEW(1));
    Class.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    Class.lpszClassName = L"ReactOSMobileSetup";
    RegisterClassW(&Class);

    MainWindow = CreateWindowW(Class.lpszClassName, L"ReactOS Mobile Setup", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 980, 680, NULL, NULL, Instance, NULL);
    EnableActions(TRUE);
    ShowWindow(MainWindow, Show);

    while (GetMessageW(&Message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Message);
        DispatchMessageW(&Message);
    }

    CoUninitialize();
    return (int)Message.wParam;
}
