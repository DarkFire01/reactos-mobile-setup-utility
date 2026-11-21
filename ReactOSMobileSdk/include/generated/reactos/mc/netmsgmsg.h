
 netmsg_msg.mc MESSAGE resources for netmsg.dll


 IMPORTANT: When a new language is added, all messages in this file need to be
 either translated or at least duplicated for the new language.
 This is a new requirement by MS mc.exe
 To do this, start with a regex replace:
 - In VS IDE: "Language=English\r\n(?<String>(?:[^\.].*\r\n)*\.\r\n)" -> "Language=English\r\n${String}Language=MyLanguage\r\n${String}"
 - In Notepad++: "Language=English\r\n([^\.].*\r\n\.\r\n)" -> "Language=English\r\n(\1)Language=MyLanguage\r\n(\1)"


 Polish translation by; Updated by pithwz - Piotr Hetnarowicz (piotrhwz@gmail.com) (April, 2020)
 Romanian translation by  Russian translation by Kudratov Olimjon (olim98@bk.ru)
 Spanish translation by Ismael Ferreras Morezuelas <2014-11-07>
 Turkish translation by 2015 Erdem Ersoy (eersoy93) (erdemersoy [at] erdemersoy [dot] net)
 Simplified Chinese translation by Henry Tang Ih 2016 (henrytang2@hotmail.com)
 Traditional Chinese translation by Henry Tang Ih 2016 (henrytang2@hotmail.com)


 lmerr.h message definitions (2100 - 2999 NERR_BASE)

//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_SYSTEM                  0x0


//
// Define the severity codes
//
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: NERR_NetNotStarted
//
// MessageText:
//
// The workstation driver is not installed.
//
#define NERR_NetNotStarted               ((DWORD)0x00000836L)

//
// MessageId: NERR_UnknownServer
//
// MessageText:
//
// The server could not be located.
//
#define NERR_UnknownServer               ((DWORD)0x00000837L)

//
// MessageId: NERR_ShareMem
//
// MessageText:
//
// An internal error occurred. The network cannot access a shared memory segment.
//
#define NERR_ShareMem                    ((DWORD)0x00000838L)

//
// MessageId: NERR_NoNetworkResource
//
// MessageText:
//
// A network resource shortage occurred.
//
#define NERR_NoNetworkResource           ((DWORD)0x00000839L)

//
// MessageId: NERR_RemoteOnly
//
// MessageText:
//
// This operation is not supported on workstations.
//
#define NERR_RemoteOnly                  ((DWORD)0x0000083AL)

//
// MessageId: NERR_DevNotRedirected
//
// MessageText:
//
// The device is not connected.
//
#define NERR_DevNotRedirected            ((DWORD)0x0000083BL)

//
// MessageId: NERR_ServerNotStarted
//
// MessageText:
//
// The Server service is not started.
//
#define NERR_ServerNotStarted            ((DWORD)0x00000842L)

//
// MessageId: NERR_ItemNotFound
//
// MessageText:
//
// The queue is empty.
//
#define NERR_ItemNotFound                ((DWORD)0x00000843L)

//
// MessageId: NERR_UnknownDevDir
//
// MessageText:
//
// The device or directory does not exist.
//
#define NERR_UnknownDevDir               ((DWORD)0x00000844L)

//
// MessageId: NERR_RedirectedPath
//
// MessageText:
//
// The operation is invalid on a redirected resource.
//
#define NERR_RedirectedPath              ((DWORD)0x00000845L)

//
// MessageId: NERR_DuplicateShare
//
// MessageText:
//
// The name has already been shared.
//
#define NERR_DuplicateShare              ((DWORD)0x00000846L)

//
// MessageId: NERR_NoRoom
//
// MessageText:
//
// The server is currently out of the requested resource.
//
#define NERR_NoRoom                      ((DWORD)0x00000847L)

//
// MessageId: NERR_TooManyItems
//
// MessageText:
//
// Requested addition of items exceeds the maximum allowed.
//
#define NERR_TooManyItems                ((DWORD)0x00000849L)

//
// MessageId: NERR_InvalidMaxUsers
//
// MessageText:
//
// The Peer service supports only two simultaneous users.
//
#define NERR_InvalidMaxUsers             ((DWORD)0x0000084AL)

//
// MessageId: NERR_BufTooSmall
//
// MessageText:
//
// The API return buffer is too small.
//
#define NERR_BufTooSmall                 ((DWORD)0x0000084BL)

//
// MessageId: NERR_RemoteErr
//
// MessageText:
//
// A remote API error occurred.
//
#define NERR_RemoteErr                   ((DWORD)0x0000084FL)

//
// MessageId: NERR_LanmanIniError
//
// MessageText:
//
// An error occurred when opening or reading the configuration file.
//
#define NERR_LanmanIniError              ((DWORD)0x00000853L)

//
// MessageId: NERR_NetworkError
//
// MessageText:
//
// A general network error occurred.
//
#define NERR_NetworkError                ((DWORD)0x00000858L)

//
// MessageId: NERR_WkstaInconsistentState
//
// MessageText:
//
// The Workstation service is in an inconsistent state. Restart the computer before restarting the Workstation service.
//
#define NERR_WkstaInconsistentState      ((DWORD)0x00000859L)

//
// MessageId: NERR_WkstaNotStarted
//
// MessageText:
//
// The Workstation service has not been started.
//
#define NERR_WkstaNotStarted             ((DWORD)0x0000085AL)

//
// MessageId: NERR_BrowserNotStarted
//
// MessageText:
//
// The requested information is not available.
//
#define NERR_BrowserNotStarted           ((DWORD)0x0000085BL)

//
// MessageId: NERR_InternalError
//
// MessageText:
//
// An internal error occurred.
//
#define NERR_InternalError               ((DWORD)0x0000085CL)

//
// MessageId: NERR_BadTransactConfig
//
// MessageText:
//
// The server is not configured for transactions.
//
#define NERR_BadTransactConfig           ((DWORD)0x0000085DL)

//
// MessageId: NERR_InvalidAPI
//
// MessageText:
//
// The requested API is not supported on the remote server.
//
#define NERR_InvalidAPI                  ((DWORD)0x0000085EL)

//
// MessageId: NERR_BadEventName
//
// MessageText:
//
// The event name is invalid.
//
#define NERR_BadEventName                ((DWORD)0x0000085FL)

//
// MessageId: NERR_DupNameReboot
//
// MessageText:
//
// The computer name already exists on the network. Change it and restart the computer.
//
#define NERR_DupNameReboot               ((DWORD)0x00000860L)

//
// MessageId: NERR_CfgCompNotFound
//
// MessageText:
//
// The specified component could not be found in the configuration information.
//
#define NERR_CfgCompNotFound             ((DWORD)0x00000862L)

//
// MessageId: NERR_CfgParamNotFound
//
// MessageText:
//
// The specified parameter could not be found in the configuration information.
//
#define NERR_CfgParamNotFound            ((DWORD)0x00000863L)

//
// MessageId: NERR_LineTooLong
//
// MessageText:
//
// A line in the configuration file is too long.
//
#define NERR_LineTooLong                 ((DWORD)0x00000865L)

//
// MessageId: NERR_QNotFound
//
// MessageText:
//
// The printer does not exist.
//
#define NERR_QNotFound                   ((DWORD)0x00000866L)

//
// MessageId: NERR_JobNotFound
//
// MessageText:
//
// The print job does not exist.
//
#define NERR_JobNotFound                 ((DWORD)0x00000867L)

//
// MessageId: NERR_DestNotFound
//
// MessageText:
//
// The printer destination cannot be found.
//
#define NERR_DestNotFound                ((DWORD)0x00000868L)

//
// MessageId: NERR_DestExists
//
// MessageText:
//
// The printer destination already exists.
//
#define NERR_DestExists                  ((DWORD)0x00000869L)

//
// MessageId: NERR_QExists
//
// MessageText:
//
// The printer queue already exists.
//
#define NERR_QExists                     ((DWORD)0x0000086AL)

//
// MessageId: NERR_QNoRoom
//
// MessageText:
//
// No more printers can be added.
//
#define NERR_QNoRoom                     ((DWORD)0x0000086BL)

//
// MessageId: NERR_JobNoRoom
//
// MessageText:
//
// No more print jobs can be added.
//
#define NERR_JobNoRoom                   ((DWORD)0x0000086CL)

//
// MessageId: NERR_DestNoRoom
//
// MessageText:
//
// No more printer destinations can be added.
//
#define NERR_DestNoRoom                  ((DWORD)0x0000086DL)

//
// MessageId: NERR_DestIdle
//
// MessageText:
//
// This printer destination is idle and cannot accept control operations.
//
#define NERR_DestIdle                    ((DWORD)0x0000086EL)

//
// MessageId: NERR_DestInvalidOp
//
// MessageText:
//
// This printer destination request contains an invalid control function.
//
#define NERR_DestInvalidOp               ((DWORD)0x0000086FL)

//
// MessageId: NERR_ProcNoRespond
//
// MessageText:
//
// The print processor is not responding.
//
#define NERR_ProcNoRespond               ((DWORD)0x00000870L)

//
// MessageId: NERR_SpoolerNotLoaded
//
// MessageText:
//
// The spooler is not running.
//
#define NERR_SpoolerNotLoaded            ((DWORD)0x00000871L)

//
// MessageId: NERR_DestInvalidState
//
// MessageText:
//
// This operation cannot be performed on the print destination in its current state.
//
#define NERR_DestInvalidState            ((DWORD)0x00000872L)

//
// MessageId: NERR_QInvalidState
//
// MessageText:
//
// This operation cannot be performed on the printer queue in its current state.
//
#define NERR_QInvalidState               ((DWORD)0x00000873L)

//
// MessageId: NERR_JobInvalidState
//
// MessageText:
//
// This operation cannot be performed on the print job in its current state.
//
#define NERR_JobInvalidState             ((DWORD)0x00000874L)

//
// MessageId: NERR_SpoolNoMemory
//
// MessageText:
//
// A spooler memory allocation failure occurred.
//
#define NERR_SpoolNoMemory               ((DWORD)0x00000875L)

//
// MessageId: NERR_DriverNotFound
//
// MessageText:
//
// The device driver does not exist.
//
#define NERR_DriverNotFound              ((DWORD)0x00000876L)

//
// MessageId: NERR_DataTypeInvalid
//
// MessageText:
//
// The data type is not supported by the print processor.
//
#define NERR_DataTypeInvalid             ((DWORD)0x00000877L)

//
// MessageId: NERR_ProcNotFound
//
// MessageText:
//
// The print processor is not installed.
//
#define NERR_ProcNotFound                ((DWORD)0x00000878L)

//
// MessageId: NERR_ServiceTableLocked
//
// MessageText:
//
// The service database is locked.
//
#define NERR_ServiceTableLocked          ((DWORD)0x00000884L)

//
// MessageId: NERR_ServiceTableFull
//
// MessageText:
//
// The service table is full.
//
#define NERR_ServiceTableFull            ((DWORD)0x00000885L)

//
// MessageId: NERR_ServiceInstalled
//
// MessageText:
//
// The requested service has already been started.
//
#define NERR_ServiceInstalled            ((DWORD)0x00000886L)

//
// MessageId: NERR_ServiceEntryLocked
//
// MessageText:
//
// The service does not respond to control actions.
//
#define NERR_ServiceEntryLocked          ((DWORD)0x00000887L)

//
// MessageId: NERR_ServiceNotInstalled
//
// MessageText:
//
// The service has not been started.
//
#define NERR_ServiceNotInstalled         ((DWORD)0x00000888L)

//
// MessageId: NERR_BadServiceName
//
// MessageText:
//
// The service name is invalid.
//
#define NERR_BadServiceName              ((DWORD)0x00000889L)

//
// MessageId: NERR_ServiceCtlTimeout
//
// MessageText:
//
// The service is not responding to the control function.
//
#define NERR_ServiceCtlTimeout           ((DWORD)0x0000088AL)

//
// MessageId: NERR_ServiceCtlBusy
//
// MessageText:
//
// The service control is busy.
//
#define NERR_ServiceCtlBusy              ((DWORD)0x0000088BL)

//
// MessageId: NERR_BadServiceProgName
//
// MessageText:
//
// The configuration file contains an invalid service program name.
//
#define NERR_BadServiceProgName          ((DWORD)0x0000088CL)

//
// MessageId: NERR_ServiceNotCtrl
//
// MessageText:
//
// The service could not be controlled in its present state.
//
#define NERR_ServiceNotCtrl              ((DWORD)0x0000088DL)

//
// MessageId: NERR_ServiceKillProc
//
// MessageText:
//
// The service ended abnormally.
//
#define NERR_ServiceKillProc             ((DWORD)0x0000088EL)

//
// MessageId: NERR_ServiceCtlNotValid
//
// MessageText:
//
// The requested pause, continue, or stop is not valid for this service.
//
#define NERR_ServiceCtlNotValid          ((DWORD)0x0000088FL)

//
// MessageId: NERR_NotInDispatchTbl
//
// MessageText:
//
// The service control dispatcher could not find the service name in the dispatch table.
//
#define NERR_NotInDispatchTbl            ((DWORD)0x00000890L)

//
// MessageId: NERR_BadControlRecv
//
// MessageText:
//
// The service control dispatcher pipe read failed.
//
#define NERR_BadControlRecv              ((DWORD)0x00000891L)

//
// MessageId: NERR_ServiceNotStarting
//
// MessageText:
//
// A thread for the new service could not be created.
//
#define NERR_ServiceNotStarting          ((DWORD)0x00000892L)

//
// MessageId: NERR_AlreadyLoggedOn
//
// MessageText:
//
// This workstation is already logged on to the local-area network.
//
#define NERR_AlreadyLoggedOn             ((DWORD)0x00000898L)

//
// MessageId: NERR_NotLoggedOn
//
// MessageText:
//
// The workstation is not logged on to the local-area network.
//
#define NERR_NotLoggedOn                 ((DWORD)0x00000899L)

//
// MessageId: NERR_BadUsername
//
// MessageText:
//
// The user name or group name parameter is invalid.
//
#define NERR_BadUsername                 ((DWORD)0x0000089AL)

//
// MessageId: NERR_BadPassword
//
// MessageText:
//
// The password parameter is invalid.
//
#define NERR_BadPassword                 ((DWORD)0x0000089BL)

//
// MessageId: NERR_UnableToAddName_W
//
// MessageText:
//
// The logon processor did not add the message alias.
//
#define NERR_UnableToAddName_W           ((DWORD)0x0000089CL)

//
// MessageId: NERR_UnableToAddName_F
//
// MessageText:
//
// The logon processor did not add the message alias.
//
#define NERR_UnableToAddName_F           ((DWORD)0x0000089DL)

//
// MessageId: NERR_UnableToDelName_W
//
// MessageText:
//
// The logoff processor did not delete the message alias.
//
#define NERR_UnableToDelName_W           ((DWORD)0x0000089EL)

//
// MessageId: NERR_UnableToDelName_F
//
// MessageText:
//
// The logoff processor did not delete the message alias.
//
#define NERR_UnableToDelName_F           ((DWORD)0x0000089FL)

//
// MessageId: NERR_LogonsPaused
//
// MessageText:
//
// Network logons are paused.
//
#define NERR_LogonsPaused                ((DWORD)0x000008A1L)

//
// MessageId: NERR_LogonServerConflict
//
// MessageText:
//
// A centralized logon-server conflict occurred.
//
#define NERR_LogonServerConflict         ((DWORD)0x000008A2L)

//
// MessageId: NERR_LogonNoUserPath
//
// MessageText:
//
// The server is configured without a valid user path.
//
#define NERR_LogonNoUserPath             ((DWORD)0x000008A3L)

//
// MessageId: NERR_LogonScriptError
//
// MessageText:
//
// An error occurred while loading or running the logon script.
//
#define NERR_LogonScriptError            ((DWORD)0x000008A4L)

//
// MessageId: NERR_StandaloneLogon
//
// MessageText:
//
// The logon server was not specified.  Your computer will be logged on as STANDALONE.
//
#define NERR_StandaloneLogon             ((DWORD)0x000008A6L)

//
// MessageId: NERR_LogonServerNotFound
//
// MessageText:
//
// The logon server could not be found.
//
#define NERR_LogonServerNotFound         ((DWORD)0x000008A7L)

//
// MessageId: NERR_LogonDomainExists
//
// MessageText:
//
// There is already a logon domain for this computer.
//
#define NERR_LogonDomainExists           ((DWORD)0x000008A8L)

//
// MessageId: NERR_NonValidatedLogon
//
// MessageText:
//
// The logon server could not validate the logon.
//
#define NERR_NonValidatedLogon           ((DWORD)0x000008A9L)

//
// MessageId: NERR_ACFNotFound
//
// MessageText:
//
// The security database could not be found.
//
#define NERR_ACFNotFound                 ((DWORD)0x000008ABL)

//
// MessageId: NERR_GroupNotFound
//
// MessageText:
//
// The group name could not be found.
//
#define NERR_GroupNotFound               ((DWORD)0x000008ACL)

//
// MessageId: NERR_UserNotFound
//
// MessageText:
//
// The user name could not be found.
//
#define NERR_UserNotFound                ((DWORD)0x000008ADL)

//
// MessageId: NERR_ResourceNotFound
//
// MessageText:
//
// The resource name could not be found.
//
#define NERR_ResourceNotFound            ((DWORD)0x000008AEL)

//
// MessageId: NERR_GroupExists
//
// MessageText:
//
// The group already exists.
//
#define NERR_GroupExists                 ((DWORD)0x000008AFL)

//
// MessageId: NERR_UserExists
//
// MessageText:
//
// The account already exists.
//
#define NERR_UserExists                  ((DWORD)0x000008B0L)

//
// MessageId: NERR_ResourceExists
//
// MessageText:
//
// The resource permission list already exists.
//
#define NERR_ResourceExists              ((DWORD)0x000008B1L)

//
// MessageId: NERR_NotPrimary
//
// MessageText:
//
// This operation is only allowed on the primary domain controller of the domain.
//
#define NERR_NotPrimary                  ((DWORD)0x000008B2L)

//
// MessageId: NERR_ACFNotLoaded
//
// MessageText:
//
// The security database has not been started.
//
#define NERR_ACFNotLoaded                ((DWORD)0x000008B3L)

//
// MessageId: NERR_ACFNoRoom
//
// MessageText:
//
// There are too many names in the user accounts database.
//
#define NERR_ACFNoRoom                   ((DWORD)0x000008B4L)

//
// MessageId: NERR_ACFFileIOFail
//
// MessageText:
//
// A disk I/O failure occurred.
//
#define NERR_ACFFileIOFail               ((DWORD)0x000008B5L)

//
// MessageId: NERR_ACFTooManyLists
//
// MessageText:
//
// The limit of 64 entries per resource was exceeded.
//
#define NERR_ACFTooManyLists             ((DWORD)0x000008B6L)

//
// MessageId: NERR_UserLogon
//
// MessageText:
//
// Deleting a user with a session is not allowed.
//
#define NERR_UserLogon                   ((DWORD)0x000008B7L)

//
// MessageId: NERR_ACFNoParent
//
// MessageText:
//
// The parent directory could not be located.
//
#define NERR_ACFNoParent                 ((DWORD)0x000008B8L)

//
// MessageId: NERR_CanNotGrowSegment
//
// MessageText:
//
// Unable to add to the security database session cache segment.
//
#define NERR_CanNotGrowSegment           ((DWORD)0x000008B9L)

//
// MessageId: NERR_SpeGroupOp
//
// MessageText:
//
// This operation is not allowed on this special group.
//
#define NERR_SpeGroupOp                  ((DWORD)0x000008BAL)

//
// MessageId: NERR_NotInCache
//
// MessageText:
//
// This user is not cached in user accounts database session cache.
//
#define NERR_NotInCache                  ((DWORD)0x000008BBL)

//
// MessageId: NERR_UserInGroup
//
// MessageText:
//
// The user already belongs to this group.
//
#define NERR_UserInGroup                 ((DWORD)0x000008BCL)

//
// MessageId: NERR_UserNotInGroup
//
// MessageText:
//
// The user does not belong to this group.
//
#define NERR_UserNotInGroup              ((DWORD)0x000008BDL)

//
// MessageId: NERR_AccountUndefined
//
// MessageText:
//
// This user account is undefined.
//
#define NERR_AccountUndefined            ((DWORD)0x000008BEL)

//
// MessageId: NERR_AccountExpired
//
// MessageText:
//
// This user account has expired.
//
#define NERR_AccountExpired              ((DWORD)0x000008BFL)

//
// MessageId: NERR_InvalidWorkstation
//
// MessageText:
//
// The user is not allowed to log on from this workstation.
//
#define NERR_InvalidWorkstation          ((DWORD)0x000008C0L)

//
// MessageId: NERR_InvalidLogonHours
//
// MessageText:
//
// The user is not allowed to log on at this time.
//
#define NERR_InvalidLogonHours           ((DWORD)0x000008C1L)

//
// MessageId: NERR_PasswordExpired
//
// MessageText:
//
// The password of this user has expired.
//
#define NERR_PasswordExpired             ((DWORD)0x000008C2L)

//
// MessageId: NERR_PasswordCantChange
//
// MessageText:
//
// The password of this user cannot change.
//
#define NERR_PasswordCantChange          ((DWORD)0x000008C3L)

//
// MessageId: NERR_PasswordHistConflict
//
// MessageText:
//
// This password cannot be used now.
//
#define NERR_PasswordHistConflict        ((DWORD)0x000008C4L)

//
// MessageId: NERR_PasswordTooShort
//
// MessageText:
//
// The password does not meet the password policy requirements. Check the minimum password length, password complexity and password history requirements.
//
#define NERR_PasswordTooShort            ((DWORD)0x000008C5L)

//
// MessageId: NERR_PasswordTooRecent
//
// MessageText:
//
// The password of this user is too recent to change.
//
#define NERR_PasswordTooRecent           ((DWORD)0x000008C6L)

//
// MessageId: NERR_InvalidDatabase
//
// MessageText:
//
// The security database is corrupted.
//
#define NERR_InvalidDatabase             ((DWORD)0x000008C7L)

//
// MessageId: NERR_DatabaseUpToDate
//
// MessageText:
//
// No updates are necessary to this replicant network/local security database.
//
#define NERR_DatabaseUpToDate            ((DWORD)0x000008C8L)

//
// MessageId: NERR_SyncRequired
//
// MessageText:
//
// This replicant database is outdated; synchronization is required.
//
#define NERR_SyncRequired                ((DWORD)0x000008C9L)

//
// MessageId: NERR_UseNotFound
//
// MessageText:
//
// The network connection could not be found.
//
#define NERR_UseNotFound                 ((DWORD)0x000008CAL)

//
// MessageId: NERR_BadAsgType
//
// MessageText:
//
// This asg_type is invalid.
//
#define NERR_BadAsgType                  ((DWORD)0x000008CBL)

//
// MessageId: NERR_DeviceIsShared
//
// MessageText:
//
// This device is currently being shared.
//
#define NERR_DeviceIsShared              ((DWORD)0x000008CCL)

//
// MessageId: NERR_NoComputerName
//
// MessageText:
//
// The computer name could not be added as a message alias.  The name may already exist on the network.
//
#define NERR_NoComputerName              ((DWORD)0x000008DEL)

//
// MessageId: NERR_MsgAlreadyStarted
//
// MessageText:
//
// The Messenger service is already started.
//
#define NERR_MsgAlreadyStarted           ((DWORD)0x000008DFL)

//
// MessageId: NERR_MsgInitFailed
//
// MessageText:
//
// The Messenger service failed to start.
//
#define NERR_MsgInitFailed               ((DWORD)0x000008E0L)

//
// MessageId: NERR_NameNotFound
//
// MessageText:
//
// The message alias could not be found on the network.
//
#define NERR_NameNotFound                ((DWORD)0x000008E1L)

//
// MessageId: NERR_AlreadyForwarded
//
// MessageText:
//
// This message alias has already been forwarded.
//
#define NERR_AlreadyForwarded            ((DWORD)0x000008E2L)

//
// MessageId: NERR_AddForwarded
//
// MessageText:
//
// This message alias has been added but is still forwarded.
//
#define NERR_AddForwarded                ((DWORD)0x000008E3L)

//
// MessageId: NERR_AlreadyExists
//
// MessageText:
//
// This message alias already exists locally.
//
#define NERR_AlreadyExists               ((DWORD)0x000008E4L)

//
// MessageId: NERR_TooManyNames
//
// MessageText:
//
// The maximum number of added message aliases has been exceeded.
//
#define NERR_TooManyNames                ((DWORD)0x000008E5L)

//
// MessageId: NERR_DelComputerName
//
// MessageText:
//
// The computer name could not be deleted.
//
#define NERR_DelComputerName             ((DWORD)0x000008E6L)

//
// MessageId: NERR_LocalForward
//
// MessageText:
//
// Messages cannot be forwarded back to the same workstation.
//
#define NERR_LocalForward                ((DWORD)0x000008E7L)

//
// MessageId: NERR_GrpMsgProcessor
//
// MessageText:
//
// An error occurred in the domain message processor.
//
#define NERR_GrpMsgProcessor             ((DWORD)0x000008E8L)

//
// MessageId: NERR_PausedRemote
//
// MessageText:
//
// The message was sent, but the recipient has paused the Messenger service.
//
#define NERR_PausedRemote                ((DWORD)0x000008E9L)

//
// MessageId: NERR_BadReceive
//
// MessageText:
//
// The message was sent but not received.
//
#define NERR_BadReceive                  ((DWORD)0x000008EAL)

//
// MessageId: NERR_NameInUse
//
// MessageText:
//
// The message alias is currently in use. Try again later.
//
#define NERR_NameInUse                   ((DWORD)0x000008EBL)

//
// MessageId: NERR_MsgNotStarted
//
// MessageText:
//
// The Messenger service has not been started.
//
#define NERR_MsgNotStarted               ((DWORD)0x000008ECL)

//
// MessageId: NERR_NotLocalName
//
// MessageText:
//
// The name is not on the local computer.
//
#define NERR_NotLocalName                ((DWORD)0x000008EDL)

//
// MessageId: NERR_NoForwardName
//
// MessageText:
//
// The forwarded message alias could not be found on the network.
//
#define NERR_NoForwardName               ((DWORD)0x000008EEL)

//
// MessageId: NERR_RemoteFull
//
// MessageText:
//
// The message alias table on the remote station is full.
//
#define NERR_RemoteFull                  ((DWORD)0x000008EFL)

//
// MessageId: NERR_NameNotForwarded
//
// MessageText:
//
// Messages for this alias are not currently being forwarded.
//
#define NERR_NameNotForwarded            ((DWORD)0x000008F0L)

//
// MessageId: NERR_TruncatedBroadcast
//
// MessageText:
//
// The broadcast message was truncated.
//
#define NERR_TruncatedBroadcast          ((DWORD)0x000008F1L)

//
// MessageId: NERR_InvalidDevice
//
// MessageText:
//
// This is an invalid device name.
//
#define NERR_InvalidDevice               ((DWORD)0x000008F6L)

//
// MessageId: NERR_WriteFault
//
// MessageText:
//
// A write fault occurred.
//
#define NERR_WriteFault                  ((DWORD)0x000008F7L)

//
// MessageId: NERR_DuplicateName
//
// MessageText:
//
// A duplicate message alias exists on the network.
//
#define NERR_DuplicateName               ((DWORD)0x000008F9L)

//
// MessageId: NERR_DeleteLater
//
// MessageText:
//
// This message alias will be deleted later.
//
#define NERR_DeleteLater                 ((DWORD)0x000008FAL)

//
// MessageId: NERR_IncompleteDel
//
// MessageText:
//
// The message alias was not successfully deleted from all networks.
//
#define NERR_IncompleteDel               ((DWORD)0x000008FBL)

//
// MessageId: NERR_MultipleNets
//
// MessageText:
//
// This operation is not supported on computers with multiple networks.
//
#define NERR_MultipleNets                ((DWORD)0x000008FCL)

//
// MessageId: NERR_NetNameNotFound
//
// MessageText:
//
// This shared resource does not exist.
//
#define NERR_NetNameNotFound             ((DWORD)0x00000906L)

//
// MessageId: NERR_DeviceNotShared
//
// MessageText:
//
// This device is not shared.
//
#define NERR_DeviceNotShared             ((DWORD)0x00000907L)

//
// MessageId: NERR_ClientNameNotFound
//
// MessageText:
//
// A session does not exist with that computer name.
//
#define NERR_ClientNameNotFound          ((DWORD)0x00000908L)

//
// MessageId: NERR_FileIdNotFound
//
// MessageText:
//
// There is not an open file with that identification number.
//
#define NERR_FileIdNotFound              ((DWORD)0x0000090AL)

//
// MessageId: NERR_ExecFailure
//
// MessageText:
//
// A failure occurred when executing a remote administration command.
//
#define NERR_ExecFailure                 ((DWORD)0x0000090BL)

//
// MessageId: NERR_TmpFile
//
// MessageText:
//
// A failure occurred when opening a remote temporary file.
//
#define NERR_TmpFile                     ((DWORD)0x0000090CL)

//
// MessageId: NERR_TooMuchData
//
// MessageText:
//
// The data returned from a remote administration command has been truncated to 64K.
//
#define NERR_TooMuchData                 ((DWORD)0x0000090DL)

//
// MessageId: NERR_DeviceShareConflict
//
// MessageText:
//
// This device cannot be shared as both a spooled and a non-spooled resource.
//
#define NERR_DeviceShareConflict         ((DWORD)0x0000090EL)

//
// MessageId: NERR_BrowserTableIncomplete
//
// MessageText:
//
// The information in the list of servers may be incorrect.
//
#define NERR_BrowserTableIncomplete      ((DWORD)0x0000090FL)

//
// MessageId: NERR_NotLocalDomain
//
// MessageText:
//
// The computer is not active in this domain.
//
#define NERR_NotLocalDomain              ((DWORD)0x00000910L)

//
// MessageId: NERR_IsDfsShare
//
// MessageText:
//
// The share must be removed from the Distributed File System before it can be deleted.
//
#define NERR_IsDfsShare                  ((DWORD)0x00000911L)

//
// MessageId: NERR_DevInvalidOpCode
//
// MessageText:
//
// The operation is invalid for this device.
//
#define NERR_DevInvalidOpCode            ((DWORD)0x0000091BL)

//
// MessageId: NERR_DevNotFound
//
// MessageText:
//
// This device cannot be shared.
//
#define NERR_DevNotFound                 ((DWORD)0x0000091CL)

//
// MessageId: NERR_DevNotOpen
//
// MessageText:
//
// This device was not open.
//
#define NERR_DevNotOpen                  ((DWORD)0x0000091DL)

//
// MessageId: NERR_BadQueueDevString
//
// MessageText:
//
// This device name list is invalid.
//
#define NERR_BadQueueDevString           ((DWORD)0x0000091EL)

//
// MessageId: NERR_BadQueuePriority
//
// MessageText:
//
// The queue priority is invalid.
//
#define NERR_BadQueuePriority            ((DWORD)0x0000091FL)

//
// MessageId: NERR_NoCommDevs
//
// MessageText:
//
// There are no shared communication devices.
//
#define NERR_NoCommDevs                  ((DWORD)0x00000921L)

//
// MessageId: NERR_QueueNotFound
//
// MessageText:
//
// The queue you specified does not exist.
//
#define NERR_QueueNotFound               ((DWORD)0x00000922L)

//
// MessageId: NERR_BadDevString
//
// MessageText:
//
// This list of devices is invalid.
//
#define NERR_BadDevString                ((DWORD)0x00000924L)

//
// MessageId: NERR_BadDev
//
// MessageText:
//
// The requested device is invalid.
//
#define NERR_BadDev                      ((DWORD)0x00000925L)

//
// MessageId: NERR_InUseBySpooler
//
// MessageText:
//
// This device is already in use by the spooler.
//
#define NERR_InUseBySpooler              ((DWORD)0x00000926L)

//
// MessageId: NERR_CommDevInUse
//
// MessageText:
//
// This device is already in use as a communication device.
//
#define NERR_CommDevInUse                ((DWORD)0x00000927L)

//
// MessageId: NERR_InvalidComputer
//
// MessageText:
//
// This computer name is invalid.
//
#define NERR_InvalidComputer             ((DWORD)0x0000092FL)

//
// MessageId: NERR_MaxLenExceeded
//
// MessageText:
//
// The string and prefix specified are too long.
//
#define NERR_MaxLenExceeded              ((DWORD)0x00000932L)

//
// MessageId: NERR_BadComponent
//
// MessageText:
//
// This path component is invalid.
//
#define NERR_BadComponent                ((DWORD)0x00000934L)

//
// MessageId: NERR_CantType
//
// MessageText:
//
// Could not determine the type of input.
//
#define NERR_CantType                    ((DWORD)0x00000935L)

//
// MessageId: NERR_TooManyEntries
//
// MessageText:
//
// The buffer for types is not big enough.
//
#define NERR_TooManyEntries              ((DWORD)0x0000093AL)

//
// MessageId: NERR_ProfileFileTooBig
//
// MessageText:
//
// Profile files cannot exceed 64K.
//
#define NERR_ProfileFileTooBig           ((DWORD)0x00000942L)

//
// MessageId: NERR_ProfileOffset
//
// MessageText:
//
// The start offset is out of range.
//
#define NERR_ProfileOffset               ((DWORD)0x00000943L)

//
// MessageId: NERR_ProfileCleanup
//
// MessageText:
//
// The system cannot delete current connections to network resources.
//
#define NERR_ProfileCleanup              ((DWORD)0x00000944L)

//
// MessageId: NERR_ProfileUnknownCmd
//
// MessageText:
//
// The system was unable to parse the command line in this file.
//
#define NERR_ProfileUnknownCmd           ((DWORD)0x00000945L)

//
// MessageId: NERR_ProfileLoadErr
//
// MessageText:
//
// An error occurred while loading the profile file.
//
#define NERR_ProfileLoadErr              ((DWORD)0x00000946L)

//
// MessageId: NERR_ProfileSaveErr
//
// MessageText:
//
// Errors occurred while saving the profile file.  The profile was partially saved.
//
#define NERR_ProfileSaveErr              ((DWORD)0x00000947L)

//
// MessageId: NERR_LogOverflow
//
// MessageText:
//
// Log file %1 is full.
//
#define NERR_LogOverflow                 ((DWORD)0x00000949L)

//
// MessageId: NERR_LogFileChanged
//
// MessageText:
//
// This log file has changed between reads.
//
#define NERR_LogFileChanged              ((DWORD)0x0000094AL)

//
// MessageId: NERR_LogFileCorrupt
//
// MessageText:
//
// Log file %1 is corrupt.
//
#define NERR_LogFileCorrupt              ((DWORD)0x0000094BL)

//
// MessageId: NERR_SourceIsDir
//
// MessageText:
//
// The source path cannot be a directory.
//
#define NERR_SourceIsDir                 ((DWORD)0x0000094CL)

//
// MessageId: NERR_BadSource
//
// MessageText:
//
// The source path is illegal.
//
#define NERR_BadSource                   ((DWORD)0x0000094DL)

//
// MessageId: NERR_BadDest
//
// MessageText:
//
// The destination path is illegal.
//
#define NERR_BadDest                     ((DWORD)0x0000094EL)

//
// MessageId: NERR_DifferentServers
//
// MessageText:
//
// The source and destination paths are on different servers.
//
#define NERR_DifferentServers            ((DWORD)0x0000094FL)

//
// MessageId: NERR_RunSrvPaused
//
// MessageText:
//
// The Run server you requested is paused.
//
#define NERR_RunSrvPaused                ((DWORD)0x00000951L)

//
// MessageId: NERR_ErrCommRunSrv
//
// MessageText:
//
// An error occurred when communicating with a Run server.
//
#define NERR_ErrCommRunSrv               ((DWORD)0x00000955L)

//
// MessageId: NERR_ErrorExecingGhost
//
// MessageText:
//
// An error occurred when starting a background process.
//
#define NERR_ErrorExecingGhost           ((DWORD)0x00000957L)

//
// MessageId: NERR_ShareNotFound
//
// MessageText:
//
// The shared resource you are connected to could not be found.
//
#define NERR_ShareNotFound               ((DWORD)0x00000958L)

//
// MessageId: NERR_InvalidLana
//
// MessageText:
//
// The LAN adapter number is invalid.
//
#define NERR_InvalidLana                 ((DWORD)0x00000960L)

//
// MessageId: NERR_OpenFiles
//
// MessageText:
//
// There are open files on the connection.
//
#define NERR_OpenFiles                   ((DWORD)0x00000961L)

//
// MessageId: NERR_ActiveConns
//
// MessageText:
//
// Active connections still exist.
//
#define NERR_ActiveConns                 ((DWORD)0x00000962L)

//
// MessageId: NERR_BadPasswordCore
//
// MessageText:
//
// This share name or password is invalid.
//
#define NERR_BadPasswordCore             ((DWORD)0x00000963L)

//
// MessageId: NERR_DevInUse
//
// MessageText:
//
// The device is being accessed by an active process.
//
#define NERR_DevInUse                    ((DWORD)0x00000964L)

//
// MessageId: NERR_LocalDrive
//
// MessageText:
//
// The drive letter is in use locally.
//
#define NERR_LocalDrive                  ((DWORD)0x00000965L)

//
// MessageId: NERR_AlertExists
//
// MessageText:
//
// The specified client is already registered for the specified event.
//
#define NERR_AlertExists                 ((DWORD)0x0000097EL)

//
// MessageId: NERR_TooManyAlerts
//
// MessageText:
//
// The alert table is full.
//
#define NERR_TooManyAlerts               ((DWORD)0x0000097FL)

//
// MessageId: NERR_NoSuchAlert
//
// MessageText:
//
// An invalid or nonexistent alert name was raised.
//
#define NERR_NoSuchAlert                 ((DWORD)0x00000980L)

//
// MessageId: NERR_BadRecipient
//
// MessageText:
//
// The alert recipient is invalid.
//
#define NERR_BadRecipient                ((DWORD)0x00000981L)

//
// MessageId: NERR_AcctLimitExceeded
//
// MessageText:
//
// A user's session with this server has been deleted\nbecause the user's logon hours are no longer valid.
//
#define NERR_AcctLimitExceeded           ((DWORD)0x00000982L)

//
// MessageId: NERR_InvalidLogSeek
//
// MessageText:
//
// The log file does not contain the requested record number.
//
#define NERR_InvalidLogSeek              ((DWORD)0x00000988L)

//
// MessageId: NERR_BadUasConfig
//
// MessageText:
//
// The user accounts database is not configured correctly.
//
#define NERR_BadUasConfig                ((DWORD)0x00000992L)

//
// MessageId: NERR_InvalidUASOp
//
// MessageText:
//
// This operation is not permitted when the Netlogon service is running.
//
#define NERR_InvalidUASOp                ((DWORD)0x00000993L)

//
// MessageId: NERR_LastAdmin
//
// MessageText:
//
// This operation is not allowed on the last administrative account.
//
#define NERR_LastAdmin                   ((DWORD)0x00000994L)

//
// MessageId: NERR_DCNotFound
//
// MessageText:
//
// Could not find domain controller for this domain.
//
#define NERR_DCNotFound                  ((DWORD)0x00000995L)

//
// MessageId: NERR_LogonTrackingError
//
// MessageText:
//
// Could not set logon information for this user.
//
#define NERR_LogonTrackingError          ((DWORD)0x00000996L)

//
// MessageId: NERR_NetlogonNotStarted
//
// MessageText:
//
// The Netlogon service has not been started.
//
#define NERR_NetlogonNotStarted          ((DWORD)0x00000997L)

//
// MessageId: NERR_CanNotGrowUASFile
//
// MessageText:
//
// Unable to add to the user accounts database.
//
#define NERR_CanNotGrowUASFile           ((DWORD)0x00000998L)

//
// MessageId: NERR_TimeDiffAtDC
//
// MessageText:
//
// This server's clock is not synchronized with the primary domain controller's clock.
//
#define NERR_TimeDiffAtDC                ((DWORD)0x00000999L)

//
// MessageId: NERR_PasswordMismatch
//
// MessageText:
//
// A password mismatch has been detected.
//
#define NERR_PasswordMismatch            ((DWORD)0x0000099AL)

//
// MessageId: NERR_NoSuchServer
//
// MessageText:
//
// The server identification does not specify a valid server.
//
#define NERR_NoSuchServer                ((DWORD)0x0000099CL)

//
// MessageId: NERR_NoSuchSession
//
// MessageText:
//
// The session identification does not specify a valid session.
//
#define NERR_NoSuchSession               ((DWORD)0x0000099DL)

//
// MessageId: NERR_NoSuchConnection
//
// MessageText:
//
// The connection identification does not specify a valid connection.
//
#define NERR_NoSuchConnection            ((DWORD)0x0000099EL)

//
// MessageId: NERR_TooManyServers
//
// MessageText:
//
// There is no space for another entry in the table of available servers.
//
#define NERR_TooManyServers              ((DWORD)0x0000099FL)

//
// MessageId: NERR_TooManySessions
//
// MessageText:
//
// The server has reached the maximum number of sessions it supports.
//
#define NERR_TooManySessions             ((DWORD)0x000009A0L)

//
// MessageId: NERR_TooManyConnections
//
// MessageText:
//
// The server has reached the maximum number of connections it supports.
//
#define NERR_TooManyConnections          ((DWORD)0x000009A1L)

//
// MessageId: NERR_TooManyFiles
//
// MessageText:
//
// The server cannot open more files because it has reached its maximum number.
//
#define NERR_TooManyFiles                ((DWORD)0x000009A2L)

//
// MessageId: NERR_NoAlternateServers
//
// MessageText:
//
// There are no alternate servers registered on this server.
//
#define NERR_NoAlternateServers          ((DWORD)0x000009A3L)

//
// MessageId: NERR_TryDownLevel
//
// MessageText:
//
// Try down-level (remote admin protocol) version of API instead.
//
#define NERR_TryDownLevel                ((DWORD)0x000009A6L)

//
// MessageId: NERR_UPSDriverNotStarted
//
// MessageText:
//
// The UPS driver could not be accessed by the UPS service.
//
#define NERR_UPSDriverNotStarted         ((DWORD)0x000009B0L)

//
// MessageId: NERR_UPSInvalidConfig
//
// MessageText:
//
// The UPS service is not configured correctly.
//
#define NERR_UPSInvalidConfig            ((DWORD)0x000009B1L)

//
// MessageId: NERR_UPSInvalidCommPort
//
// MessageText:
//
// The UPS service could not access the specified Comm Port.
//
#define NERR_UPSInvalidCommPort          ((DWORD)0x000009B2L)

//
// MessageId: NERR_UPSSignalAsserted
//
// MessageText:
//
// The UPS indicated a line fail or low battery situation. Service not started.
//
#define NERR_UPSSignalAsserted           ((DWORD)0x000009B3L)

//
// MessageId: NERR_UPSShutdownFailed
//
// MessageText:
//
// The UPS service failed to perform a system shut down.
//
#define NERR_UPSShutdownFailed           ((DWORD)0x000009B4L)

//
// MessageId: NERR_BadDosRetCode
//
// MessageText:
//
// The program below returned a DOS error code:
//
#define NERR_BadDosRetCode               ((DWORD)0x000009C4L)

//
// MessageId: NERR_ProgNeedsExtraMem
//
// MessageText:
//
// The program below needs more memory:
//
#define NERR_ProgNeedsExtraMem           ((DWORD)0x000009C5L)

//
// MessageId: NERR_BadDosFunction
//
// MessageText:
//
// The program below called an unsupported DOS function:
//
#define NERR_BadDosFunction              ((DWORD)0x000009C6L)

//
// MessageId: NERR_RemoteBootFailed
//
// MessageText:
//
// The workstation failed to boot.
//
#define NERR_RemoteBootFailed            ((DWORD)0x000009C7L)

//
// MessageId: NERR_BadFileCheckSum
//
// MessageText:
//
// The file below is corrupt.
//
#define NERR_BadFileCheckSum             ((DWORD)0x000009C8L)

//
// MessageId: NERR_NoRplBootSystem
//
// MessageText:
//
// No loader is specified in the boot-block definition file.
//
#define NERR_NoRplBootSystem             ((DWORD)0x000009C9L)

//
// MessageId: NERR_RplLoadrNetBiosErr
//
// MessageText:
//
// NetBIOS returned an error: The NCB and SMB are dumped above.
//
#define NERR_RplLoadrNetBiosErr          ((DWORD)0x000009CAL)

//
// MessageId: NERR_RplLoadrDiskErr
//
// MessageText:
//
// A disk I/O error occurred.
//
#define NERR_RplLoadrDiskErr             ((DWORD)0x000009CBL)

//
// MessageId: NERR_ImageParamErr
//
// MessageText:
//
// Image parameter substitution failed.
//
#define NERR_ImageParamErr               ((DWORD)0x000009CCL)

//
// MessageId: NERR_TooManyImageParams
//
// MessageText:
//
// Too many image parameters cross disk sector boundaries.
//
#define NERR_TooManyImageParams          ((DWORD)0x000009CDL)

//
// MessageId: NERR_NonDosFloppyUsed
//
// MessageText:
//
// The image was not generated from a DOS diskette formatted with /S.
//
#define NERR_NonDosFloppyUsed            ((DWORD)0x000009CEL)

//
// MessageId: NERR_RplBootRestart
//
// MessageText:
//
// Remote boot will be restarted later.
//
#define NERR_RplBootRestart              ((DWORD)0x000009CFL)

//
// MessageId: NERR_RplSrvrCallFailed
//
// MessageText:
//
// The call to the Remoteboot server failed.
//
#define NERR_RplSrvrCallFailed           ((DWORD)0x000009D0L)

//
// MessageId: NERR_CantConnectRplSrvr
//
// MessageText:
//
// Cannot connect to the Remoteboot server.
//
#define NERR_CantConnectRplSrvr          ((DWORD)0x000009D1L)

//
// MessageId: NERR_CantOpenImageFile
//
// MessageText:
//
// Cannot open image file on the Remoteboot server.
//
#define NERR_CantOpenImageFile           ((DWORD)0x000009D2L)

//
// MessageId: NERR_CallingRplSrvr
//
// MessageText:
//
// Connecting to the Remoteboot server...
//
#define NERR_CallingRplSrvr              ((DWORD)0x000009D3L)

//
// MessageId: NERR_StartingRplBoot
//
// MessageText:
//
// Connecting to the Remoteboot server...
//
#define NERR_StartingRplBoot             ((DWORD)0x000009D4L)

//
// MessageId: NERR_RplBootServiceTerm
//
// MessageText:
//
// Remote boot service was stopped; check the error log for the cause of the problem.
//
#define NERR_RplBootServiceTerm          ((DWORD)0x000009D5L)

//
// MessageId: NERR_RplBootStartFailed
//
// MessageText:
//
// Remote boot startup failed; check the error log for the cause of the problem.
//
#define NERR_RplBootStartFailed          ((DWORD)0x000009D6L)

//
// MessageId: NERR_RPL_CONNECTED
//
// MessageText:
//
// A second connection to a Remoteboot resource is not allowed.
//
#define NERR_RPL_CONNECTED               ((DWORD)0x000009D7L)

//
// MessageId: NERR_BrowserConfiguredToNotRun
//
// MessageText:
//
// The browser service was configured with MaintainServerList=No.
//
#define NERR_BrowserConfiguredToNotRun   ((DWORD)0x000009F6L)

//
// MessageId: NERR_RplNoAdaptersStarted
//
// MessageText:
//
// Service failed to start since none of the network adapters started with this service.
//
#define NERR_RplNoAdaptersStarted        ((DWORD)0x00000A32L)

//
// MessageId: NERR_RplBadRegistry
//
// MessageText:
//
// Service failed to start due to bad startup information in the registry.
//
#define NERR_RplBadRegistry              ((DWORD)0x00000A33L)

//
// MessageId: NERR_RplBadDatabase
//
// MessageText:
//
// Service failed to start because its database is absent or corrupt.
//
#define NERR_RplBadDatabase              ((DWORD)0x00000A34L)

//
// MessageId: NERR_RplRplfilesShare
//
// MessageText:
//
// Service failed to start because RPLFILES share is absent.
//
#define NERR_RplRplfilesShare            ((DWORD)0x00000A35L)

//
// MessageId: NERR_RplNotRplServer
//
// MessageText:
//
// Service failed to start because RPLUSER group is absent.
//
#define NERR_RplNotRplServer             ((DWORD)0x00000A36L)

//
// MessageId: NERR_RplCannotEnum
//
// MessageText:
//
// Cannot enumerate service records.
//
#define NERR_RplCannotEnum               ((DWORD)0x00000A37L)

//
// MessageId: NERR_RplWkstaInfoCorrupted
//
// MessageText:
//
// Workstation record information has been corrupted.
//
#define NERR_RplWkstaInfoCorrupted       ((DWORD)0x00000A38L)

//
// MessageId: NERR_RplWkstaNotFound
//
// MessageText:
//
// Workstation record was not found.
//
#define NERR_RplWkstaNotFound            ((DWORD)0x00000A39L)

//
// MessageId: NERR_RplWkstaNameUnavailable
//
// MessageText:
//
// Workstation name is in use by some other workstation.
//
#define NERR_RplWkstaNameUnavailable     ((DWORD)0x00000A3AL)

//
// MessageId: NERR_RplProfileInfoCorrupted
//
// MessageText:
//
// Profile record information has been corrupted.
//
#define NERR_RplProfileInfoCorrupted     ((DWORD)0x00000A3BL)

//
// MessageId: NERR_RplProfileNotFound
//
// MessageText:
//
// Profile record was not found.
//
#define NERR_RplProfileNotFound          ((DWORD)0x00000A3CL)

//
// MessageId: NERR_RplProfileNameUnavailable
//
// MessageText:
//
// Profile name is in use by some other profile.
//
#define NERR_RplProfileNameUnavailable   ((DWORD)0x00000A3DL)

//
// MessageId: NERR_RplProfileNotEmpty
//
// MessageText:
//
// There are workstations using this profile.
//
#define NERR_RplProfileNotEmpty          ((DWORD)0x00000A3EL)

//
// MessageId: NERR_RplConfigInfoCorrupted
//
// MessageText:
//
// Configuration record information has been corrupted.
//
#define NERR_RplConfigInfoCorrupted      ((DWORD)0x00000A3FL)

//
// MessageId: NERR_RplConfigNotFound
//
// MessageText:
//
// Configuration record was not found.
//
#define NERR_RplConfigNotFound           ((DWORD)0x00000A40L)

//
// MessageId: NERR_RplAdapterInfoCorrupted
//
// MessageText:
//
// Adapter id record information has been corrupted.
//
#define NERR_RplAdapterInfoCorrupted     ((DWORD)0x00000A41L)

//
// MessageId: NERR_RplInternal
//
// MessageText:
//
// An internal service error has occurred.
//
#define NERR_RplInternal                 ((DWORD)0x00000A42L)

//
// MessageId: NERR_RplVendorInfoCorrupted
//
// MessageText:
//
// Vendor id record information has been corrupted.
//
#define NERR_RplVendorInfoCorrupted      ((DWORD)0x00000A43L)

//
// MessageId: NERR_RplBootInfoCorrupted
//
// MessageText:
//
// Boot block record information has been corrupted.
//
#define NERR_RplBootInfoCorrupted        ((DWORD)0x00000A44L)

//
// MessageId: NERR_RplWkstaNeedsUserAcct
//
// MessageText:
//
// The user account for this workstation record is missing.
//
#define NERR_RplWkstaNeedsUserAcct       ((DWORD)0x00000A45L)

//
// MessageId: NERR_RplNeedsRPLUSERAcct
//
// MessageText:
//
// The RPLUSER local group could not be found.
//
#define NERR_RplNeedsRPLUSERAcct         ((DWORD)0x00000A46L)

//
// MessageId: NERR_RplBootNotFound
//
// MessageText:
//
// Boot block record was not found.
//
#define NERR_RplBootNotFound             ((DWORD)0x00000A47L)

//
// MessageId: NERR_RplIncompatibleProfile
//
// MessageText:
//
// Chosen profile is incompatible with this workstation.
//
#define NERR_RplIncompatibleProfile      ((DWORD)0x00000A48L)

//
// MessageId: NERR_RplAdapterNameUnavailable
//
// MessageText:
//
// Chosen network adapter id is in use by some other workstation.
//
#define NERR_RplAdapterNameUnavailable   ((DWORD)0x00000A49L)

//
// MessageId: NERR_RplConfigNotEmpty
//
// MessageText:
//
// There are profiles using this configuration.
//
#define NERR_RplConfigNotEmpty           ((DWORD)0x00000A4AL)

//
// MessageId: NERR_RplBootInUse
//
// MessageText:
//
// There are workstations, profiles or configurations using this boot block.
//
#define NERR_RplBootInUse                ((DWORD)0x00000A4BL)

//
// MessageId: NERR_RplBackupDatabase
//
// MessageText:
//
// Service failed to backup Remoteboot database.
//
#define NERR_RplBackupDatabase           ((DWORD)0x00000A4CL)

//
// MessageId: NERR_RplAdapterNotFound
//
// MessageText:
//
// Adapter record was not found.
//
#define NERR_RplAdapterNotFound          ((DWORD)0x00000A4DL)

//
// MessageId: NERR_RplVendorNotFound
//
// MessageText:
//
// Vendor record was not found.
//
#define NERR_RplVendorNotFound           ((DWORD)0x00000A4EL)

//
// MessageId: NERR_RplVendorNameUnavailable
//
// MessageText:
//
// Vendor name is in use by some other vendor record.
//
#define NERR_RplVendorNameUnavailable    ((DWORD)0x00000A4FL)

//
// MessageId: NERR_RplBootNameUnavailable
//
// MessageText:
//
// (boot name, vendor id) is in use by some other boot block record.
//
#define NERR_RplBootNameUnavailable      ((DWORD)0x00000A50L)

//
// MessageId: NERR_RplConfigNameUnavailable
//
// MessageText:
//
// Configuration name is in use by some other configuration.
//
#define NERR_RplConfigNameUnavailable    ((DWORD)0x00000A51L)

//
// MessageId: NERR_DfsInternalCorruption
//
// MessageText:
//
// The internal database maintained by the DFS service is corrupt
//
#define NERR_DfsInternalCorruption       ((DWORD)0x00000A64L)

//
// MessageId: NERR_DfsVolumeDataCorrupt
//
// MessageText:
//
// One of the records in the internal DFS database is corrupt
//
#define NERR_DfsVolumeDataCorrupt        ((DWORD)0x00000A65L)

//
// MessageId: NERR_DfsNoSuchVolume
//
// MessageText:
//
// There is no DFS name whose entry path matches the input Entry Path
//
#define NERR_DfsNoSuchVolume             ((DWORD)0x00000A66L)

//
// MessageId: NERR_DfsVolumeAlreadyExists
//
// MessageText:
//
// A root or link with the given name already exists
//
#define NERR_DfsVolumeAlreadyExists      ((DWORD)0x00000A67L)

//
// MessageId: NERR_DfsAlreadyShared
//
// MessageText:
//
// The server share specified is already shared in the DFS
//
#define NERR_DfsAlreadyShared            ((DWORD)0x00000A68L)

//
// MessageId: NERR_DfsNoSuchShare
//
// MessageText:
//
// The indicated server share does not support the indicated DFS namespace
//
#define NERR_DfsNoSuchShare              ((DWORD)0x00000A69L)

//
// MessageId: NERR_DfsNotALeafVolume
//
// MessageText:
//
// The operation is not valid on this portion of the namespace
//
#define NERR_DfsNotALeafVolume           ((DWORD)0x00000A6AL)

//
// MessageId: NERR_DfsLeafVolume
//
// MessageText:
//
// The operation is not valid on this portion of the namespace
//
#define NERR_DfsLeafVolume               ((DWORD)0x00000A6BL)

//
// MessageId: NERR_DfsVolumeHasMultipleServers
//
// MessageText:
//
// The operation is ambiguous because the link has multiple servers
//
#define NERR_DfsVolumeHasMultipleServers ((DWORD)0x00000A6CL)

//
// MessageId: NERR_DfsCantCreateJunctionPoint
//
// MessageText:
//
// Unable to create a link
//
#define NERR_DfsCantCreateJunctionPoint  ((DWORD)0x00000A6DL)

//
// MessageId: NERR_DfsServerNotDfsAware
//
// MessageText:
//
// The server is not DFS Aware
//
#define NERR_DfsServerNotDfsAware        ((DWORD)0x00000A6EL)

//
// MessageId: NERR_DfsBadRenamePath
//
// MessageText:
//
// The specified rename target path is invalid
//
#define NERR_DfsBadRenamePath            ((DWORD)0x00000A6FL)

//
// MessageId: NERR_DfsVolumeIsOffline
//
// MessageText:
//
// The specified DFS link is offline
//
#define NERR_DfsVolumeIsOffline          ((DWORD)0x00000A70L)

//
// MessageId: NERR_DfsNoSuchServer
//
// MessageText:
//
// The specified server is not a server for this link
//
#define NERR_DfsNoSuchServer             ((DWORD)0x00000A71L)

//
// MessageId: NERR_DfsCyclicalName
//
// MessageText:
//
// A cycle in the DFS name was detected
//
#define NERR_DfsCyclicalName             ((DWORD)0x00000A72L)

//
// MessageId: NERR_DfsNotSupportedInServerDfs
//
// MessageText:
//
// The operation is not supported on a server-based DFS
//
#define NERR_DfsNotSupportedInServerDfs  ((DWORD)0x00000A73L)

//
// MessageId: NERR_DfsDuplicateService
//
// MessageText:
//
// This link is already supported by the specified server-share
//
#define NERR_DfsDuplicateService         ((DWORD)0x00000A74L)

//
// MessageId: NERR_DfsCantRemoveLastServerShare
//
// MessageText:
//
// Can't remove the last server-share supporting this root or link
//
#define NERR_DfsCantRemoveLastServerShare ((DWORD)0x00000A75L)

//
// MessageId: NERR_DfsVolumeIsInterDfs
//
// MessageText:
//
// The operation is not supported for an Inter-DFS link
//
#define NERR_DfsVolumeIsInterDfs         ((DWORD)0x00000A76L)

//
// MessageId: NERR_DfsInconsistent
//
// MessageText:
//
// The internal state of the DFS Service has become inconsistent
//
#define NERR_DfsInconsistent             ((DWORD)0x00000A77L)

//
// MessageId: NERR_DfsServerUpgraded
//
// MessageText:
//
// The DFS Service has been installed on the specified server
//
#define NERR_DfsServerUpgraded           ((DWORD)0x00000A78L)

//
// MessageId: NERR_DfsDataIsIdentical
//
// MessageText:
//
// The DFS data being reconciled is identical
//
#define NERR_DfsDataIsIdentical          ((DWORD)0x00000A79L)

//
// MessageId: NERR_DfsCantRemoveDfsRoot
//
// MessageText:
//
// The DFS root cannot be deleted - Uninstall DFS if required
//
#define NERR_DfsCantRemoveDfsRoot        ((DWORD)0x00000A7AL)

//
// MessageId: NERR_DfsChildOrParentInDfs
//
// MessageText:
//
// A child or parent directory of the share is already in a DFS
//
#define NERR_DfsChildOrParentInDfs       ((DWORD)0x00000A7BL)

//
// MessageId: NERR_DfsInternalError
//
// MessageText:
//
// DFS internal error
//
#define NERR_DfsInternalError            ((DWORD)0x00000A82L)

//
// MessageId: NERR_SetupAlreadyJoined
//
// MessageText:
//
// This machine is already joined to a domain.
//
#define NERR_SetupAlreadyJoined          ((DWORD)0x00000A83L)

//
// MessageId: NERR_SetupNotJoined
//
// MessageText:
//
// This machine is not currently joined to a domain.
//
#define NERR_SetupNotJoined              ((DWORD)0x00000A84L)

//
// MessageId: NERR_SetupDomainController
//
// MessageText:
//
// This machine is a domain controller and cannot be unjoined from a domain.
//
#define NERR_SetupDomainController       ((DWORD)0x00000A85L)

//
// MessageId: NERR_DefaultJoinRequired
//
// MessageText:
//
// The destination domain controller does not support creating machine accounts in OUs.
//
#define NERR_DefaultJoinRequired         ((DWORD)0x00000A86L)

//
// MessageId: NERR_InvalidWorkgroupName
//
// MessageText:
//
// The specified workgroup name is invalid.
//
#define NERR_InvalidWorkgroupName        ((DWORD)0x00000A87L)

//
// MessageId: NERR_NameUsesIncompatibleCodePage
//
// MessageText:
//
// The specified computer name is incompatible with the default language used on the domain controller.
//
#define NERR_NameUsesIncompatibleCodePage ((DWORD)0x00000A88L)

//
// MessageId: NERR_ComputerAccountNotFound
//
// MessageText:
//
// The specified computer account could not be found.
//
#define NERR_ComputerAccountNotFound     ((DWORD)0x00000A89L)

//
// MessageId: NERR_PersonalSku
//
// MessageText:
//
// This version of the operating system cannot be joined to a domain.
//
#define NERR_PersonalSku                 ((DWORD)0x00000A8AL)

//
// MessageId: NERR_PasswordMustChange
//
// MessageText:
//
// Password must change at next logon
//
#define NERR_PasswordMustChange          ((DWORD)0x00000A8DL)

//
// MessageId: NERR_AccountLockedOut
//
// MessageText:
//
// Account is locked out
//
#define NERR_AccountLockedOut            ((DWORD)0x00000A8EL)

//
// MessageId: NERR_PasswordTooLong
//
// MessageText:
//
// Password is too long
//
#define NERR_PasswordTooLong             ((DWORD)0x00000A8FL)

//
// MessageId: NERR_PasswordNotComplexEnough
//
// MessageText:
//
// Password doesn't meet the complexity policy
//
#define NERR_PasswordNotComplexEnough    ((DWORD)0x00000A90L)

//
// MessageId: NERR_PasswordFilterError
//
// MessageText:
//
// Password doesn't meet the requirements of the filter dll's
//
#define NERR_PasswordFilterError         ((DWORD)0x00000A91L)

//
// MessageId: MAX_NERR
//
// MessageText:
//
// This is the last error in NERR range.
//
#define MAX_NERR                         ((DWORD)0x00000BB7L)


 alertmsg.h (non-public) message definitions (3000 - 3049 ALERT_BASE)

//
// MessageId: ALERT_3000
//
// MessageText:
//
// Drive %1 is nearly full. %2 bytes are available.\n
// Please warn users and delete unneeded files.
//
#define ALERT_3000                       ((DWORD)0x00000BB8L)

//
// MessageId: ALERT_3001
//
// MessageText:
//
// %1 errors were logged in the last %2 minutes.\n
// Please review the server's error log.
//
#define ALERT_3001                       ((DWORD)0x00000BB9L)

//
// MessageId: ALERT_3002
//
// MessageText:
//
// %1 network errors occurred in the last %2 minutes.\n
// Please review the server's error log.  The server and/or\n
// network hardware may need service.
//
#define ALERT_3002                       ((DWORD)0x00000BBAL)

//
// MessageId: ALERT_3003
//
// MessageText:
//
// There were %1 bad password attempts in the last %2 minutes.\n
// Please review the server's audit trail.
//
#define ALERT_3003                       ((DWORD)0x00000BBBL)

//
// MessageId: ALERT_3004
//
// MessageText:
//
// There were %1 access-denied errors in the last %2 minutes.\n
// Please review the server's audit trail.
//
#define ALERT_3004                       ((DWORD)0x00000BBCL)

//
// MessageId: ALERT_3006
//
// MessageText:
//
// The error log is full.  No errors will be logged until\n
// the file is cleared or the limit is raised.
//
#define ALERT_3006                       ((DWORD)0x00000BBEL)

//
// MessageId: ALERT_3007
//
// MessageText:
//
// The error log is 80%% full.
//
#define ALERT_3007                       ((DWORD)0x00000BBFL)

//
// MessageId: ALERT_3008
//
// MessageText:
//
// The audit log is full.  No audit entries will be logged\n
// until the file is cleared or the limit is raised.
//
#define ALERT_3008                       ((DWORD)0x00000BC0L)

//
// MessageId: ALERT_3009
//
// MessageText:
//
// The audit log is 80%% full.
//
#define ALERT_3009                       ((DWORD)0x00000BC1L)

//
// MessageId: ALERT_3010
//
// MessageText:
//
// An error occurred closing file %1.\n
// Please check the file to make sure it is not corrupted.
//
#define ALERT_3010                       ((DWORD)0x00000BC2L)

//
// MessageId: ALERT_3011
//
// MessageText:
//
// The administrator has closed %1.
//
#define ALERT_3011                       ((DWORD)0x00000BC3L)

//
// MessageId: ALERT_3012
//
// MessageText:
//
// There were %1 access-denied errors in the last %2 minutes.
//
#define ALERT_3012                       ((DWORD)0x00000BC4L)

//
// MessageId: ALERT_3020
//
// MessageText:
//
// A power failure was detected at %1.  The server has been paused.
//
#define ALERT_3020                       ((DWORD)0x00000BCCL)

//
// MessageId: ALERT_3021
//
// MessageText:
//
// Power has been restored at %1.  The server is no longer paused.
//
#define ALERT_3021                       ((DWORD)0x00000BCDL)

//
// MessageId: ALERT_3022
//
// MessageText:
//
// The UPS service is starting shut down at %1 due to low battery.
//
#define ALERT_3022                       ((DWORD)0x00000BCEL)

//
// MessageId: ALERT_3023
//
// MessageText:
//
// There is a problem with a configuration of user specified\n
// shut down command file.  The UPS service started anyway.
//
#define ALERT_3023                       ((DWORD)0x00000BCFL)

//
// MessageId: ALERT_3025
//
// MessageText:
//
// A defective sector on drive %1 has been replaced (hotfixed).\n
// No data was lost.  You should run CHKDSK soon to restore full\n
// performance and replenish the volume's spare sector pool.\n\n
// The hotfix occurred while processing a remote request.
//
#define ALERT_3025                       ((DWORD)0x00000BD1L)

//
// MessageId: ALERT_3026
//
// MessageText:
//
// A disk error occurred on the HPFS volume in drive %1.\n
// The error occurred while processing a remote request.
//
#define ALERT_3026                       ((DWORD)0x00000BD2L)

//
// MessageId: ALERT_3027
//
// MessageText:
//
// The user accounts database (NET.ACC) is corrupted.  The local security\n
// system is replacing the corrupted NET.ACC with the backup\n
// made on %1 at %2.\n
// Any updates made to the database after this time are lost.\n
//
#define ALERT_3027                       ((DWORD)0x00000BD3L)

//
// MessageId: ALERT_3028
//
// MessageText:
//
// The user accounts database (NET.ACC) is missing. The local\n
// security system is restoring the backup database\n
// made on %1 at %2.\n
// Any updates made to the database after this time are lost.\n
//
#define ALERT_3028                       ((DWORD)0x00000BD4L)

//
// MessageId: ALERT_3029
//
// MessageText:
//
// Local security could not be started because the user accounts database\n
// (NET.ACC) was missing or corrupted, and no usable backup\n
// database was present.\n\n
// THE SYSTEM IS NOT SECURE.\n"
//
#define ALERT_3029                       ((DWORD)0x00000BD5L)

//
// MessageId: ALERT_3030
//
// MessageText:
//
// The server cannot export directory %1, to client %2.\n
// It is exported from another server.
//
#define ALERT_3030                       ((DWORD)0x00000BD6L)

//
// MessageId: ALERT_3031
//
// MessageText:
//
// The replication server could not update directory %2 from the source\n
// on %3 due to error %1.
//
#define ALERT_3031                       ((DWORD)0x00000BD7L)

//
// MessageId: ALERT_3032
//
// MessageText:
//
// Master %1 did not send an update notice for directory %2 at the expected\n
// time.
//
#define ALERT_3032                       ((DWORD)0x00000BD8L)

//
// MessageId: ALERT_3033
//
// MessageText:
//
// User %1 has exceeded account limitation %2 on server %3.
//
#define ALERT_3033                       ((DWORD)0x00000BD9L)

//
// MessageId: ALERT_3034
//
// MessageText:
//
// The primary domain controller for domain %1 failed.
//
#define ALERT_3034                       ((DWORD)0x00000BDAL)

//
// MessageId: ALERT_3035
//
// MessageText:
//
// Failed to authenticate with %2, a Windows NT or Windows 2000 Domain Controller for\n
// domain %1.
//
#define ALERT_3035                       ((DWORD)0x00000BDBL)

//
// MessageId: ALERT_3036
//
// MessageText:
//
// The replicator attempted to log on at %2 as %1 and failed.
//
#define ALERT_3036                       ((DWORD)0x00000BDCL)

//
// MessageId: ALERT_3037
//
// MessageText:
//
// @I *LOGON HOURS %0
//
#define ALERT_3037                       ((DWORD)0x00000BDDL)

//
// MessageId: ALERT_3038
//
// MessageText:
//
// Replicator could not access %2\n
// on %3 due to system error %1.
//
#define ALERT_3038                       ((DWORD)0x00000BDEL)

//
// MessageId: ALERT_3039
//
// MessageText:
//
// Replicator limit for files in a directory has been exceeded.
//
#define ALERT_3039                       ((DWORD)0x00000BDFL)

//
// MessageId: ALERT_3040
//
// MessageText:
//
// Replicator limit for tree depth has been exceeded.
//
#define ALERT_3040                       ((DWORD)0x00000BE0L)

//
// MessageId: ALERT_3041
//
// MessageText:
//
// The replicator cannot update directory %1. It has tree integrity\n
// and is the current directory for some process.
//
#define ALERT_3041                       ((DWORD)0x00000BE1L)

//
// MessageId: ALERT_3042
//
// MessageText:
//
// Network error %1 occurred.
//
#define ALERT_3042                       ((DWORD)0x00000BE2L)

//
// MessageId: ALERT_3045
//
// MessageText:
//
// System error %1 occurred.
//
#define ALERT_3045                       ((DWORD)0x00000BE5L)

//
// MessageId: ALERT_3046
//
// MessageText:
//
// Cannot log on. User is currently logged on and argument TRYUSER\n
// is set to NO.
//
#define ALERT_3046                       ((DWORD)0x00000BE6L)

//
// MessageId: ALERT_3047
//
// MessageText:
//
// IMPORT path %1 cannot be found.
//
#define ALERT_3047                       ((DWORD)0x00000BE7L)

//
// MessageId: ALERT_3048
//
// MessageText:
//
// EXPORT path %1 cannot be found.
//
#define ALERT_3048                       ((DWORD)0x00000BE8L)

//
// MessageId: ALERT_3049
//
// MessageText:
//
// Replicated data has changed in directory %1.
//
#define ALERT_3049                       ((DWORD)0x00000BE9L)

//
// MessageId: ALERT_3050
//
// MessageText:
//
// Replicator failed to update signal file in directory %2 due to\n
// %1 system error.
//
#define ALERT_3050                       ((DWORD)0x00000BEAL)


 lmsvc.h message definitions (3050 - 3099 SERVICE_BASE)

//
// MessageId: SERVICE_UIC_BADPARMVAL
//
// MessageText:
//
// The Registry or the information you just typed includes an illegal\n
// value for \"%1\".
//
#define SERVICE_UIC_BADPARMVAL           ((DWORD)0x00000BEBL)

//
// MessageId: SERVICE_UIC_MISSPARM
//
// MessageText:
//
// The required parameter was not provided on the command\nline or in the configuration file.
//
#define SERVICE_UIC_MISSPARM             ((DWORD)0x00000BECL)

//
// MessageId: SERVICE_UIC_UNKPARM
//
// MessageText:
//
// LAN Manager does not recognize \"%1\" as a valid option.
//
#define SERVICE_UIC_UNKPARM              ((DWORD)0x00000BEDL)

//
// MessageId: SERVICE_UIC_RESOURCE
//
// MessageText:
//
// A request for resource could not be satisfied.
//
#define SERVICE_UIC_RESOURCE             ((DWORD)0x00000BEEL)

//
// MessageId: SERVICE_UIC_CONFIG
//
// MessageText:
//
// A problem exists with the system configuration.
//
#define SERVICE_UIC_CONFIG               ((DWORD)0x00000BEFL)

//
// MessageId: SERVICE_UIC_SYSTEM
//
// MessageText:
//
// A system error has occurred.
//
#define SERVICE_UIC_SYSTEM               ((DWORD)0x00000BF0L)

//
// MessageId: SERVICE_UIC_INTERNAL
//
// MessageText:
//
// An internal consistency error has occurred.
//
#define SERVICE_UIC_INTERNAL             ((DWORD)0x00000BF1L)

//
// MessageId: SERVICE_UIC_AMBIGPARM
//
// MessageText:
//
// The configuration file or the command line has an ambiguous option.
//
#define SERVICE_UIC_AMBIGPARM            ((DWORD)0x00000BF2L)

//
// MessageId: SERVICE_UIC_DUPPARM
//
// MessageText:
//
// The configuration file or the command line has a duplicate parameter.
//
#define SERVICE_UIC_DUPPARM              ((DWORD)0x00000BF3L)

//
// MessageId: SERVICE_UIC_KILL
//
// MessageText:
//
// The service did not respond to control and was stopped with\nthe DosKillProc function.
//
#define SERVICE_UIC_KILL                 ((DWORD)0x00000BF4L)

//
// MessageId: SERVICE_UIC_EXEC
//
// MessageText:
//
// An error occurred when attempting to run the service program.
//
#define SERVICE_UIC_EXEC                 ((DWORD)0x00000BF5L)

//
// MessageId: SERVICE_UIC_SUBSERV
//
// MessageText:
//
// The sub-service failed to start.
//
#define SERVICE_UIC_SUBSERV              ((DWORD)0x00000BF6L)

//
// MessageId: SERVICE_UIC_CONFLPARM
//
// MessageText:
//
// There is a conflict in the value or use of these options: %1.
//
#define SERVICE_UIC_CONFLPARM            ((DWORD)0x00000BF7L)

//
// MessageId: SERVICE_UIC_FILE
//
// MessageText:
//
// There is a problem with the file.
//
#define SERVICE_UIC_FILE                 ((DWORD)0x00000BF8L)

//
// MessageId: SERVICE_UIC_M_MEMORY
//
// MessageText:
//
// memory
//
#define SERVICE_UIC_M_MEMORY             ((DWORD)0x00000BFEL)

//
// MessageId: SERVICE_UIC_M_DISK
//
// MessageText:
//
// disk space
//
#define SERVICE_UIC_M_DISK               ((DWORD)0x00000BFFL)

//
// MessageId: SERVICE_UIC_M_THREADS
//
// MessageText:
//
// thread
//
#define SERVICE_UIC_M_THREADS            ((DWORD)0x00000C00L)

//
// MessageId: SERVICE_UIC_M_PROCESSES
//
// MessageText:
//
// process
//
#define SERVICE_UIC_M_PROCESSES          ((DWORD)0x00000C01L)

//
// MessageId: SERVICE_UIC_M_SECURITY
//
// MessageText:
//
// Security Failure. %0
//
#define SERVICE_UIC_M_SECURITY           ((DWORD)0x00000C02L)

//
// MessageId: SERVICE_UIC_M_LANROOT
//
// MessageText:
//
// Bad or missing LAN Manager root directory.
//
#define SERVICE_UIC_M_LANROOT            ((DWORD)0x00000C03L)

//
// MessageId: SERVICE_UIC_M_REDIR
//
// MessageText:
//
// The network software is not installed.
//
#define SERVICE_UIC_M_REDIR              ((DWORD)0x00000C04L)

//
// MessageId: SERVICE_UIC_M_SERVER
//
// MessageText:
//
// The server is not started.
//
#define SERVICE_UIC_M_SERVER             ((DWORD)0x00000C05L)

//
// MessageId: SERVICE_UIC_M_SEC_FILE_ERR
//
// MessageText:
//
// The server cannot access the user accounts database (NET.ACC).
//
#define SERVICE_UIC_M_SEC_FILE_ERR       ((DWORD)0x00000C06L)

//
// MessageId: SERVICE_UIC_M_FILES
//
// MessageText:
//
// Incompatible files are installed in the LANMAN tree.
//
#define SERVICE_UIC_M_FILES              ((DWORD)0x00000C07L)

//
// MessageId: SERVICE_UIC_M_LOGS
//
// MessageText:
//
// The LANMAN\\LOGS directory is invalid.
//
#define SERVICE_UIC_M_LOGS               ((DWORD)0x00000C08L)

//
// MessageId: SERVICE_UIC_M_LANGROUP
//
// MessageText:
//
// The domain specified could not be used.
//
#define SERVICE_UIC_M_LANGROUP           ((DWORD)0x00000C09L)

//
// MessageId: SERVICE_UIC_M_MSGNAME
//
// MessageText:
//
// The computer name is being used as a message alias on another computer.
//
#define SERVICE_UIC_M_MSGNAME            ((DWORD)0x00000C0AL)

//
// MessageId: SERVICE_UIC_M_ANNOUNCE
//
// MessageText:
//
// The announcement of the server name failed.
//
#define SERVICE_UIC_M_ANNOUNCE           ((DWORD)0x00000C0BL)

//
// MessageId: SERVICE_UIC_M_UAS
//
// MessageText:
//
// The user accounts database is not configured correctly.
//
#define SERVICE_UIC_M_UAS                ((DWORD)0x00000C0CL)

//
// MessageId: SERVICE_UIC_M_SERVER_SEC_ERR
//
// MessageText:
//
// The server is not running with user-level security.
//
#define SERVICE_UIC_M_SERVER_SEC_ERR     ((DWORD)0x00000C0DL)

//
// MessageId: SERVICE_UIC_M_WKSTA
//
// MessageText:
//
// The workstation is not configured properly.
//
#define SERVICE_UIC_M_WKSTA              ((DWORD)0x00000C0FL)

//
// MessageId: SERVICE_UIC_M_ERRLOG
//
// MessageText:
//
// View your error log for details.
//
#define SERVICE_UIC_M_ERRLOG             ((DWORD)0x00000C10L)

//
// MessageId: SERVICE_UIC_M_FILE_UW
//
// MessageText:
//
// Unable to write to this file.
//
#define SERVICE_UIC_M_FILE_UW            ((DWORD)0x00000C11L)

//
// MessageId: SERVICE_UIC_M_ADDPAK
//
// MessageText:
//
// ADDPAK file is corrupted.  Delete LANMAN\\NETPROG\\ADDPAK.SER\n
// and reapply all ADDPAKs.
//
#define SERVICE_UIC_M_ADDPAK             ((DWORD)0x00000C12L)

//
// MessageId: SERVICE_UIC_M_LAZY
//
// MessageText:
//
// The LM386 server cannot be started because CACHE.EXE is not running.
//
#define SERVICE_UIC_M_LAZY               ((DWORD)0x00000C13L)

//
// MessageId: SERVICE_UIC_M_UAS_MACHINE_ACCT
//
// MessageText:
//
// There is no account for this computer in the security database.
//
#define SERVICE_UIC_M_UAS_MACHINE_ACCT   ((DWORD)0x00000C14L)

//
// MessageId: SERVICE_UIC_M_UAS_SERVERS_NMEMB
//
// MessageText:
//
// This computer is not a member of the group SERVERS.
//
#define SERVICE_UIC_M_UAS_SERVERS_NMEMB  ((DWORD)0x00000C15L)

//
// MessageId: SERVICE_UIC_M_UAS_SERVERS_NOGRP
//
// MessageText:
//
// The group SERVERS is not present in the local security database.
//
#define SERVICE_UIC_M_UAS_SERVERS_NOGRP  ((DWORD)0x00000C16L)

//
// MessageId: SERVICE_UIC_M_UAS_INVALID_ROLE
//
// MessageText:
//
// This computer is configured as a member of a workgroup, not as\n
// a member of a domain. The Netlogon service does not need to run in this\n
// configuration.
//
#define SERVICE_UIC_M_UAS_INVALID_ROLE   ((DWORD)0x00000C17L)

//
// MessageId: SERVICE_UIC_M_NETLOGON_NO_DC
//
// MessageText:
//
// The primary Domain Controller for this domain could not be located.
//
#define SERVICE_UIC_M_NETLOGON_NO_DC     ((DWORD)0x00000C18L)

//
// MessageId: SERVICE_UIC_M_NETLOGON_DC_CFLCT
//
// MessageText:
//
// This computer is configured to be the primary domain controller of its domain.\n
// However, the computer %1 is currently claiming to be the primary domain controller\n
// of the domain.
//
#define SERVICE_UIC_M_NETLOGON_DC_CFLCT  ((DWORD)0x00000C19L)

//
// MessageId: SERVICE_UIC_M_NETLOGON_AUTH
//
// MessageText:
//
// The service failed to authenticate with the primary domain controller.
//
#define SERVICE_UIC_M_NETLOGON_AUTH      ((DWORD)0x00000C1AL)

//
// MessageId: SERVICE_UIC_M_UAS_PROLOG
//
// MessageText:
//
// There is a problem with the security database creation date or serial number.
//
#define SERVICE_UIC_M_UAS_PROLOG         ((DWORD)0x00000C1BL)


 lmerrlog.h messages definitions (3100 - 3299 ERRLOG_BASE)

//
// MessageId: NELOG_Internal_Error
//
// MessageText:
//
// The operation failed because a network software error occurred.
//
#define NELOG_Internal_Error             ((DWORD)0x00000C1CL)

//
// MessageId: NELOG_Resource_Shortage
//
// MessageText:
//
// The system ran out of a resource controlled by the %1 option.
//
#define NELOG_Resource_Shortage          ((DWORD)0x00000C1DL)

//
// MessageId: NELOG_Unable_To_Lock_Segment
//
// MessageText:
//
// The service failed to obtain a long-term lock on the\nsegment for network control blocks (NCBs). The error code is the data.
//
#define NELOG_Unable_To_Lock_Segment     ((DWORD)0x00000C1EL)

//
// MessageId: NELOG_Unable_To_Unlock_Segment
//
// MessageText:
//
// The service failed to release the long-term lock on the\nsegment for network control blocks (NCBs). The error code is the data.
//
#define NELOG_Unable_To_Unlock_Segment   ((DWORD)0x00000C1FL)

//
// MessageId: NELOG_Uninstall_Service
//
// MessageText:
//
// There was an error stopping service %1.\nThe error code from NetServiceControl is the data.
//
#define NELOG_Uninstall_Service          ((DWORD)0x00000C20L)

//
// MessageId: NELOG_Init_Exec_Fail
//
// MessageText:
//
// Initialization failed because of a system execution failure on\npath %1. The system error code is the data.
//
#define NELOG_Init_Exec_Fail             ((DWORD)0x00000C21L)

//
// MessageId: NELOG_Ncb_Error
//
// MessageText:
//
// An unexpected network control block (NCB) was received. The NCB is the data.
//
#define NELOG_Ncb_Error                  ((DWORD)0x00000C22L)

//
// MessageId: NELOG_Net_Not_Started
//
// MessageText:
//
// The network is not started.
//
#define NELOG_Net_Not_Started            ((DWORD)0x00000C23L)

//
// MessageId: NELOG_Ioctl_Error
//
// MessageText:
//
// A DosDevIoctl or DosFsCtl to NETWKSTA.SYS failed.\nThe data shown is in this format:\nDWORD  approx CS:IP of call to ioctl or fsctl\nWORD   error code\nWORD   ioctl or fsctl number
//
#define NELOG_Ioctl_Error                ((DWORD)0x00000C24L)

//
// MessageId: NELOG_System_Semaphore
//
// MessageText:
//
// Unable to create or open system semaphore %1.\nThe error code is the data.
//
#define NELOG_System_Semaphore           ((DWORD)0x00000C25L)

//
// MessageId: NELOG_Init_OpenCreate_Err
//
// MessageText:
//
// Initialization failed because of an open/create error on the\nfile %1. The system error code is the data.
//
#define NELOG_Init_OpenCreate_Err        ((DWORD)0x00000C26L)

//
// MessageId: NELOG_NetBios
//
// MessageText:
//
// An unexpected NetBIOS error occurred.\nThe error code is the data.
//
#define NELOG_NetBios                    ((DWORD)0x00000C27L)

//
// MessageId: NELOG_SMB_Illegal
//
// MessageText:
//
// An illegal server message block (SMB) was received.\nThe SMB is the data.
//
#define NELOG_SMB_Illegal                ((DWORD)0x00000C28L)

//
// MessageId: NELOG_Service_Fail
//
// MessageText:
//
// Initialization failed because the requested service %1\ncould not be started.
//
#define NELOG_Service_Fail               ((DWORD)0x00000C29L)

//
// MessageId: NELOG_Entries_Lost
//
// MessageText:
//
// Some entries in the error log were lost because of a buffer\noverflow.
//
#define NELOG_Entries_Lost               ((DWORD)0x00000C2AL)

//
// MessageId: NELOG_Init_Seg_Overflow
//
// MessageText:
//
// Initialization parameters controlling resource usage other\nthan net buffers are sized so that too much memory is needed.
//
#define NELOG_Init_Seg_Overflow          ((DWORD)0x00000C30L)

//
// MessageId: NELOG_Srv_No_Mem_Grow
//
// MessageText:
//
// The server cannot increase the size of a memory segment.
//
#define NELOG_Srv_No_Mem_Grow            ((DWORD)0x00000C31L)

//
// MessageId: NELOG_Access_File_Bad
//
// MessageText:
//
// Initialization failed because account file %1 is either incorrect\nor not present.
//
#define NELOG_Access_File_Bad            ((DWORD)0x00000C32L)

//
// MessageId: NELOG_Srvnet_Not_Started
//
// MessageText:
//
// Initialization failed because network %1 was not started.
//
#define NELOG_Srvnet_Not_Started         ((DWORD)0x00000C33L)

//
// MessageId: NELOG_Init_Chardev_Err
//
// MessageText:
//
// The server failed to start. Either all three chdev\nparameters must be zero or all three must be nonzero.
//
#define NELOG_Init_Chardev_Err           ((DWORD)0x00000C34L)

//
// MessageId: NELOG_Remote_API
//
// MessageText:
//
// A remote API request was halted due to the following\ninvalid description string: %1.
//
#define NELOG_Remote_API                 ((DWORD)0x00000C35L)

//
// MessageId: NELOG_Ncb_TooManyErr
//
// MessageText:
//
// The network %1 ran out of network control blocks (NCBs).  You may need to increase NCBs\nfor this network.  The following information includes the\nnumber of NCBs submitted by the server when this error occurred:
//
#define NELOG_Ncb_TooManyErr             ((DWORD)0x00000C36L)

//
// MessageId: NELOG_Mailslot_err
//
// MessageText:
//
// The server cannot create the %1 mailslot needed to send\nthe ReleaseMemory alert message.  The error received is:
//
#define NELOG_Mailslot_err               ((DWORD)0x00000C37L)

//
// MessageId: NELOG_ReleaseMem_Alert
//
// MessageText:
//
// The server failed to register for the ReleaseMemory alert,\nwith recipient %1. The error code from\nNetAlertStart is the data.
//
#define NELOG_ReleaseMem_Alert           ((DWORD)0x00000C38L)

//
// MessageId: NELOG_AT_cannot_write
//
// MessageText:
//
// The server cannot update the AT schedule file. The file\nis corrupted.
//
#define NELOG_AT_cannot_write            ((DWORD)0x00000C39L)

//
// MessageId: NELOG_Cant_Make_Msg_File
//
// MessageText:
//
// The server encountered an error when calling\nNetIMakeLMFileName. The error code is the data.
//
#define NELOG_Cant_Make_Msg_File         ((DWORD)0x00000C3AL)

//
// MessageId: NELOG_Exec_Netservr_NoMem
//
// MessageText:
//
// Initialization failed because of a system execution failure on\npath %1. There is not enough memory to start the process.\nThe system error code is the data.
//
#define NELOG_Exec_Netservr_NoMem        ((DWORD)0x00000C3BL)

//
// MessageId: NELOG_Server_Lock_Failure
//
// MessageText:
//
// Longterm lock of the server buffers failed.\nCheck swap disk's free space and restart the system to start the server.
//
#define NELOG_Server_Lock_Failure        ((DWORD)0x00000C3CL)

//
// MessageId: NELOG_Msg_Shutdown
//
// MessageText:
//
// The service has stopped due to repeated consecutive\noccurrences of a network control block (NCB) error.  The last bad NCB follows\nin raw data.
//
#define NELOG_Msg_Shutdown               ((DWORD)0x00000C44L)

//
// MessageId: NELOG_Msg_Sem_Shutdown
//
// MessageText:
//
// The Message server has stopped due to a lock on the\nMessage server shared data segment.
//
#define NELOG_Msg_Sem_Shutdown           ((DWORD)0x00000C45L)

//
// MessageId: NELOG_Msg_Log_Err
//
// MessageText:
//
// A file system error occurred while opening or writing to the\nsystem message log file %1. Message logging has been\nswitched off due to the error. The error code is the data.
//
#define NELOG_Msg_Log_Err                ((DWORD)0x00000C4EL)

//
// MessageId: NELOG_VIO_POPUP_ERR
//
// MessageText:
//
// Unable to display message POPUP due to system VIO call error.\nThe error code is the data.
//
#define NELOG_VIO_POPUP_ERR              ((DWORD)0x00000C4FL)

//
// MessageId: NELOG_Msg_Unexpected_SMB_Type
//
// MessageText:
//
// An illegal server message block (SMB) was received.  The SMB is the data.
//
#define NELOG_Msg_Unexpected_SMB_Type    ((DWORD)0x00000C50L)

//
// MessageId: NELOG_Wksta_Infoseg
//
// MessageText:
//
// The workstation information segment is bigger than 64K.\nThe size follows, in DWORD format:
//
#define NELOG_Wksta_Infoseg              ((DWORD)0x00000C58L)

//
// MessageId: NELOG_Wksta_Compname
//
// MessageText:
//
// The workstation was unable to get the name-number of the computer.
//
#define NELOG_Wksta_Compname             ((DWORD)0x00000C59L)

//
// MessageId: NELOG_Wksta_BiosThreadFailure
//
// MessageText:
//
// The workstation could not initialize the Async NetBIOS Thread.\nThe error code is the data.
//
#define NELOG_Wksta_BiosThreadFailure    ((DWORD)0x00000C5AL)

//
// MessageId: NELOG_Wksta_IniSeg
//
// MessageText:
//
// The workstation could not open the initial shared segment.\nThe error code is the data.
//
#define NELOG_Wksta_IniSeg               ((DWORD)0x00000C5BL)

//
// MessageId: NELOG_Wksta_HostTab_Full
//
// MessageText:
//
// The workstation host table is full.
//
#define NELOG_Wksta_HostTab_Full         ((DWORD)0x00000C5CL)

//
// MessageId: NELOG_Wksta_Bad_Mailslot_SMB
//
// MessageText:
//
// A bad mailslot server message block (SMB) was received.  The SMB is the data.
//
#define NELOG_Wksta_Bad_Mailslot_SMB     ((DWORD)0x00000C5DL)

//
// MessageId: NELOG_Wksta_UASInit
//
// MessageText:
//
// The workstation encountered an error while trying to start the user accounts database.\nThe error code is the data.
//
#define NELOG_Wksta_UASInit              ((DWORD)0x00000C5EL)

//
// MessageId: NELOG_Wksta_SSIRelogon
//
// MessageText:
//
// The workstation encountered an error while responding to an SSI revalidation request.\nThe function code and the error codes are the data.
//
#define NELOG_Wksta_SSIRelogon           ((DWORD)0x00000C5FL)

//
// MessageId: NELOG_Build_Name
//
// MessageText:
//
// The Alerter service had a problem creating the list of\nalert recipients.  The error code is %1.
//
#define NELOG_Build_Name                 ((DWORD)0x00000C62L)

//
// MessageId: NELOG_Name_Expansion
//
// MessageText:
//
// There was an error expanding %1 as a group name. Try\nsplitting the group into two or more smaller groups.
//
#define NELOG_Name_Expansion             ((DWORD)0x00000C63L)

//
// MessageId: NELOG_Message_Send
//
// MessageText:
//
// There was an error sending %2 the alert message -\n(\n%3 )\nThe error code is %1.
//
#define NELOG_Message_Send               ((DWORD)0x00000C64L)

//
// MessageId: NELOG_Mail_Slt_Err
//
// MessageText:
//
// There was an error in creating or reading the alerter mailslot.\nThe error code is %1.
//
#define NELOG_Mail_Slt_Err               ((DWORD)0x00000C65L)

//
// MessageId: NELOG_AT_cannot_read
//
// MessageText:
//
// The server could not read the AT schedule file.
//
#define NELOG_AT_cannot_read             ((DWORD)0x00000C66L)

//
// MessageId: NELOG_AT_sched_err
//
// MessageText:
//
// The server found an invalid AT schedule record.
//
#define NELOG_AT_sched_err               ((DWORD)0x00000C67L)

//
// MessageId: NELOG_AT_schedule_file_created
//
// MessageText:
//
// The server could not find an AT schedule file so it created one.
//
#define NELOG_AT_schedule_file_created   ((DWORD)0x00000C68L)

//
// MessageId: NELOG_Srvnet_NB_Open
//
// MessageText:
//
// The server could not access the %1 network with NetBiosOpen.
//
#define NELOG_Srvnet_NB_Open             ((DWORD)0x00000C69L)

//
// MessageId: NELOG_AT_Exec_Err
//
// MessageText:
//
// The AT command processor could not run %1.
//
#define NELOG_AT_Exec_Err                ((DWORD)0x00000C6AL)

//
// MessageId: NELOG_Lazy_Write_Err
//
// MessageText:
//
// WARNING:  Because of a lazy-write error, drive %1 now\ncontains some corrupted data.  The cache is stopped.
//
#define NELOG_Lazy_Write_Err             ((DWORD)0x00000C6CL)

//
// MessageId: NELOG_HotFix
//
// MessageText:
//
// A defective sector on drive %1 has been replaced (hotfixed).\nNo data was lost.  You should run CHKDSK soon to restore full\nperformance and replenish the volume's spare sector pool.\n\nThe hotfix occurred while processing a remote request.
//
#define NELOG_HotFix                     ((DWORD)0x00000C6DL)

//
// MessageId: NELOG_HardErr_From_Server
//
// MessageText:
//
// A disk error occurred on the HPFS volume in drive %1.\nThe error occurred while processing a remote request.
//
#define NELOG_HardErr_From_Server        ((DWORD)0x00000C6EL)

//
// MessageId: NELOG_LocalSecFail1
//
// MessageText:
//
// The user accounts database (NET.ACC) is corrupted.  The local security\nsystem is replacing the corrupted NET.ACC with the backup\nmade at %1.\nAny updates made to the database after this time are lost.\n
//
#define NELOG_LocalSecFail1              ((DWORD)0x00000C6FL)

//
// MessageId: NELOG_LocalSecFail2
//
// MessageText:
//
// The user accounts database (NET.ACC) is missing.  The local\nsecurity system is restoring the backup database\nmade at %1.\nAny updates made to the database made after this time are lost.\n
//
#define NELOG_LocalSecFail2              ((DWORD)0x00000C70L)

//
// MessageId: NELOG_LocalSecFail3
//
// MessageText:
//
// Local security could not be started because the user accounts database\n(NET.ACC) was missing or corrupted, and no usable backup\ndatabase was present.\n\nTHE SYSTEM IS NOT SECURE.
//
#define NELOG_LocalSecFail3              ((DWORD)0x00000C71L)

//
// MessageId: NELOG_LocalSecGeneralFail
//
// MessageText:
//
// Local security could not be started because an error\noccurred during initialization. The error code returned is %1.\n\nTHE SYSTEM IS NOT SECURE.\n
//
#define NELOG_LocalSecGeneralFail        ((DWORD)0x00000C72L)

//
// MessageId: NELOG_NetWkSta_Internal_Error
//
// MessageText:
//
// A NetWksta internal error has occurred:\n%1
//
#define NELOG_NetWkSta_Internal_Error    ((DWORD)0x00000C76L)

//
// MessageId: NELOG_NetWkSta_No_Resource
//
// MessageText:
//
// The redirector is out of a resource: %1.
//
#define NELOG_NetWkSta_No_Resource       ((DWORD)0x00000C77L)

//
// MessageId: NELOG_NetWkSta_SMB_Err
//
// MessageText:
//
// A server message block (SMB) error occurred on the connection to %1.\nThe SMB header is the data.
//
#define NELOG_NetWkSta_SMB_Err           ((DWORD)0x00000C78L)

//
// MessageId: NELOG_NetWkSta_VC_Err
//
// MessageText:
//
// A virtual circuit error occurred on the session to %1.\nThe network control block (NCB) command and return code is the data.
//
#define NELOG_NetWkSta_VC_Err            ((DWORD)0x00000C79L)

//
// MessageId: NELOG_NetWkSta_Stuck_VC_Err
//
// MessageText:
//
// Hanging up a stuck session to %1.
//
#define NELOG_NetWkSta_Stuck_VC_Err      ((DWORD)0x00000C7AL)

//
// MessageId: NELOG_NetWkSta_NCB_Err
//
// MessageText:
//
// A network control block (NCB) error occurred (%1).\nThe NCB is the data.
//
#define NELOG_NetWkSta_NCB_Err           ((DWORD)0x00000C7BL)

//
// MessageId: NELOG_NetWkSta_Write_Behind_Err
//
// MessageText:
//
// A write operation to %1 failed.\nData may have been lost.
//
#define NELOG_NetWkSta_Write_Behind_Err  ((DWORD)0x00000C7CL)

//
// MessageId: NELOG_NetWkSta_Reset_Err
//
// MessageText:
//
// Reset of driver %1 failed to complete the network control block (NCB).\nThe NCB is the data.
//
#define NELOG_NetWkSta_Reset_Err         ((DWORD)0x00000C7DL)

//
// MessageId: NELOG_NetWkSta_Too_Many
//
// MessageText:
//
// The amount of resource %1 requested was more\nthan the maximum. The maximum amount was allocated.
//
#define NELOG_NetWkSta_Too_Many          ((DWORD)0x00000C7EL)

//
// MessageId: NELOG_Srv_Thread_Failure
//
// MessageText:
//
// The server could not create a thread.\nThe THREADS parameter in the CONFIG.SYS file should be increased.
//
#define NELOG_Srv_Thread_Failure         ((DWORD)0x00000C84L)

//
// MessageId: NELOG_Srv_Close_Failure
//
// MessageText:
//
// The server could not close %1.\nThe file is probably corrupted.
//
#define NELOG_Srv_Close_Failure          ((DWORD)0x00000C85L)

//
// MessageId: NELOG_ReplUserCurDir
//
// MessageText:
//
// The replicator cannot update directory %1. It has tree integrity\nand is the current directory for some process.
//
#define NELOG_ReplUserCurDir             ((DWORD)0x00000C86L)

//
// MessageId: NELOG_ReplCannotMasterDir
//
// MessageText:
//
// The server cannot export directory %1 to client %2.\nIt is exported from another server.
//
#define NELOG_ReplCannotMasterDir        ((DWORD)0x00000C87L)

//
// MessageId: NELOG_ReplUpdateError
//
// MessageText:
//
// The replication server could not update directory %2 from the source\non %3 due to error %1.
//
#define NELOG_ReplUpdateError            ((DWORD)0x00000C88L)

//
// MessageId: NELOG_ReplLostMaster
//
// MessageText:
//
// Master %1 did not send an update notice for directory %2 at the expected\ntime.
//
#define NELOG_ReplLostMaster             ((DWORD)0x00000C89L)

//
// MessageId: NELOG_NetlogonAuthDCFail
//
// MessageText:
//
// This computer could not authenticate with %2, a domain controller\n
// for domain %1, and therefore this computer might deny logon requests.\n
// This inability to authenticate might be caused by another computer on the\n
// same network using the same name or the password for this computer account\n
// is not recognized. If this message appears again, contact your system\n
// administrator.
//
#define NELOG_NetlogonAuthDCFail         ((DWORD)0x00000C8AL)

//
// MessageId: NELOG_ReplLogonFailed
//
// MessageText:
//
// The replicator attempted to log on at %2 as %1 and failed.
//
#define NELOG_ReplLogonFailed            ((DWORD)0x00000C8BL)

//
// MessageId: NELOG_ReplNetErr
//
// MessageText:
//
// Network error %1 occurred.
//
#define NELOG_ReplNetErr                 ((DWORD)0x00000C8CL)

//
// MessageId: NELOG_ReplMaxFiles
//
// MessageText:
//
// Replicator limit for files in a directory has been exceeded.
//
#define NELOG_ReplMaxFiles               ((DWORD)0x00000C8DL)

//
// MessageId: NELOG_ReplMaxTreeDepth
//
// MessageText:
//
// Replicator limit for tree depth has been exceeded.
//
#define NELOG_ReplMaxTreeDepth           ((DWORD)0x00000C8EL)

//
// MessageId: NELOG_ReplBadMsg
//
// MessageText:
//
// Unrecognized message received in mailslot.
//
#define NELOG_ReplBadMsg                 ((DWORD)0x00000C8FL)

//
// MessageId: NELOG_ReplSysErr
//
// MessageText:
//
// System error %1 occurred.
//
#define NELOG_ReplSysErr                 ((DWORD)0x00000C90L)

//
// MessageId: NELOG_ReplUserLoged
//
// MessageText:
//
// Cannot log on. User is currently logged on and argument TRYUSER\nis set to NO.
//
#define NELOG_ReplUserLoged              ((DWORD)0x00000C91L)

//
// MessageId: NELOG_ReplBadImport
//
// MessageText:
//
// IMPORT path %1 cannot be found.
//
#define NELOG_ReplBadImport              ((DWORD)0x00000C92L)

//
// MessageId: NELOG_ReplBadExport
//
// MessageText:
//
// EXPORT path %1 cannot be found.
//
#define NELOG_ReplBadExport              ((DWORD)0x00000C93L)

//
// MessageId: NELOG_ReplSignalFileErr
//
// MessageText:
//
// Replicator failed to update signal file in directory %2 due to\n%1 system error.
//
#define NELOG_ReplSignalFileErr          ((DWORD)0x00000C94L)

//
// MessageId: NELOG_DiskFT
//
// MessageText:
//
// Disk Fault Tolerance Error\n\n%1
//
#define NELOG_DiskFT                     ((DWORD)0x00000C95L)

//
// MessageId: NELOG_ReplAccessDenied
//
// MessageText:
//
// Replicator could not access %2\non %3 due to system error %1.
//
#define NELOG_ReplAccessDenied           ((DWORD)0x00000C96L)

//
// MessageId: NELOG_NetlogonFailedPrimary
//
// MessageText:
//
// The primary domain controller for domain %1 has apparently failed.
//
#define NELOG_NetlogonFailedPrimary      ((DWORD)0x00000C97L)

//
// MessageId: NELOG_NetlogonPasswdSetFailed
//
// MessageText:
//
// Changing machine account password for account %1 failed with\nthe following error: %n%2
//
#define NELOG_NetlogonPasswdSetFailed    ((DWORD)0x00000C98L)

//
// MessageId: NELOG_NetlogonTrackingError
//
// MessageText:
//
// An error occurred while updating the logon or logoff information for %1.
//
#define NELOG_NetlogonTrackingError      ((DWORD)0x00000C99L)

//
// MessageId: NELOG_NetlogonSyncError
//
// MessageText:
//
// An error occurred while synchronizing with primary domain controller %1
//
#define NELOG_NetlogonSyncError          ((DWORD)0x00000C9AL)

//
// MessageId: NELOG_NetlogonRequireSignOrSealError
//
// MessageText:
//
// The session setup to the Domain Controller %1 for the domain %2 failed\n
// because %1 does not support signing or sealing the Netlogon session.\n\n
// Either upgrade the Domain Controller or set the RequireSignOrSeal\n
// registry entry on this machine to 0.
//
#define NELOG_NetlogonRequireSignOrSealError ((DWORD)0x00000C9BL)

//
// MessageId: NELOG_UPS_PowerOut
//
// MessageText:
//
// A power failure was detected at the server.
//
#define NELOG_UPS_PowerOut               ((DWORD)0x00000C9EL)

//
// MessageId: NELOG_UPS_Shutdown
//
// MessageText:
//
// The UPS service performed server shut down.
//
#define NELOG_UPS_Shutdown               ((DWORD)0x00000C9FL)

//
// MessageId: NELOG_UPS_CmdFileError
//
// MessageText:
//
// The UPS service did not complete execution of the\nuser specified shut down command file.
//
#define NELOG_UPS_CmdFileError           ((DWORD)0x00000CA0L)

//
// MessageId: NELOG_UPS_CannotOpenDriver
//
// MessageText:
//
// The UPS driver could not be opened.  The error code is\nthe data.
//
#define NELOG_UPS_CannotOpenDriver       ((DWORD)0x00000CA1L)

//
// MessageId: NELOG_UPS_PowerBack
//
// MessageText:
//
// Power has been restored.
//
#define NELOG_UPS_PowerBack              ((DWORD)0x00000CA2L)

//
// MessageId: NELOG_UPS_CmdFileConfig
//
// MessageText:
//
// There is a problem with a configuration of user specified\nshut down command file.
//
#define NELOG_UPS_CmdFileConfig          ((DWORD)0x00000CA3L)

//
// MessageId: NELOG_UPS_CmdFileExec
//
// MessageText:
//
// The UPS service failed to execute a user specified shutdown\ncommand file %1.  The error code is the data.
//
#define NELOG_UPS_CmdFileExec            ((DWORD)0x00000CA4L)

//
// MessageId: NELOG_Missing_Parameter
//
// MessageText:
//
// Initialization failed because of an invalid or missing\nparameter in the configuration file %1.
//
#define NELOG_Missing_Parameter          ((DWORD)0x00000CB2L)

//
// MessageId: NELOG_Invalid_Config_Line
//
// MessageText:
//
// Initialization failed because of an invalid line in the\nconfiguration file %1. The invalid line is the data.
//
#define NELOG_Invalid_Config_Line        ((DWORD)0x00000CB3L)

//
// MessageId: NELOG_Invalid_Config_File
//
// MessageText:
//
// Initialization failed because of an error in the configuration\nfile %1.
//
#define NELOG_Invalid_Config_File        ((DWORD)0x00000CB4L)

//
// MessageId: NELOG_File_Changed
//
// MessageText:
//
// The file %1 has been changed after initialization.\nThe boot-block loading was temporarily terminated.
//
#define NELOG_File_Changed               ((DWORD)0x00000CB5L)

//
// MessageId: NELOG_Files_Dont_Fit
//
// MessageText:
//
// The files do not fit to the boot-block configuration\nfile %1. Change the BASE and ORG definitions or the order\nof the files.
//
#define NELOG_Files_Dont_Fit             ((DWORD)0x00000CB6L)

//
// MessageId: NELOG_Wrong_DLL_Version
//
// MessageText:
//
// Initialization failed because the dynamic-link\nlibrary %1 returned an incorrect version number.
//
#define NELOG_Wrong_DLL_Version          ((DWORD)0x00000CB7L)

//
// MessageId: NELOG_Error_in_DLL
//
// MessageText:
//
// There was an unrecoverable error in the dynamic-\nlink library of the service.
//
#define NELOG_Error_in_DLL               ((DWORD)0x00000CB8L)

//
// MessageId: NELOG_System_Error
//
// MessageText:
//
// The system returned an unexpected error code.\nThe error code is the data.
//
#define NELOG_System_Error               ((DWORD)0x00000CB9L)

//
// MessageId: NELOG_FT_ErrLog_Too_Large
//
// MessageText:
//
// The fault-tolerance error log file, LANROOT\\LOGS\\FT.LOG,\nis more than 64K.
//
#define NELOG_FT_ErrLog_Too_Large        ((DWORD)0x00000CBAL)

//
// MessageId: NELOG_FT_Update_In_Progress
//
// MessageText:
//
// The fault-tolerance error-log file, LANROOT\\LOGS\\FT.LOG, had the\n
// update in progress bit set upon opening, which means that the\n
// system crashed while working on the error log.
//
#define NELOG_FT_Update_In_Progress      ((DWORD)0x00000CBBL)

//
// MessageId: NELOG_Joined_Domain
//
// MessageText:
//
// This computer has been successfully joined to domain '%1'.
//
#define NELOG_Joined_Domain              ((DWORD)0x00000CBCL)

//
// MessageId: NELOG_Joined_Workgroup
//
// MessageText:
//
// This computer has been successfully joined to workgroup '%1'.
//
#define NELOG_Joined_Workgroup           ((DWORD)0x00000CBDL)

//
// MessageId: NELOG_OEM_Code
//
// MessageText:
//
// %1 %2 %3 %4 %5 %6 %7 %8 %9.
//
#define NELOG_OEM_Code                   ((DWORD)0x00000CE3L)


 msgtext.h (non-public) message definitions (3300 - 3499 MTXT_BASE)

//
// MessageId: MTXT_3301
//
// MessageText:
//
// Remote IPC %0
//
#define MTXT_3301                        ((DWORD)0x00000CE5L)

//
// MessageId: MTXT_3302
//
// MessageText:
//
// Remote Admin %0
//
#define MTXT_3302                        ((DWORD)0x00000CE6L)

//
// MessageId: MTXT_3303
//
// MessageText:
//
// Logon server share %0
//
#define MTXT_3303                        ((DWORD)0x00000CE7L)

//
// MessageId: MTXT_3304
//
// MessageText:
//
// A network error occurred. %0
//
#define MTXT_3304                        ((DWORD)0x00000CE8L)

//
// MessageId: MTXT_3400
//
// MessageText:
//
// There is not enough memory to start the Workstation service.
//
#define MTXT_3400                        ((DWORD)0x00000D48L)

//
// MessageId: MTXT_3401
//
// MessageText:
//
// An error occurred when reading the NETWORKS entry in the LANMAN.INI file.
//
#define MTXT_3401                        ((DWORD)0x00000D49L)

//
// MessageId: MTXT_3402
//
// MessageText:
//
// This is an invalid argument: %1.
//
#define MTXT_3402                        ((DWORD)0x00000D4AL)

//
// MessageId: MTXT_3403
//
// MessageText:
//
// The %1 NETWORKS entry in the LANMAN.INI file has a\nsyntax error and will be ignored.
//
#define MTXT_3403                        ((DWORD)0x00000D4BL)

//
// MessageId: MTXT_3404
//
// MessageText:
//
// There are too many NETWORKS entries in the LANMAN.INI file.
//
#define MTXT_3404                        ((DWORD)0x00000D4CL)

//
// MessageId: MTXT_3406
//
// MessageText:
//
// An error occurred when opening network\ndevice driver %1 = %2.
//
#define MTXT_3406                        ((DWORD)0x00000D4EL)

//
// MessageId: MTXT_3407
//
// MessageText:
//
// Device driver %1 sent a bad BiosLinkage response.
//
#define MTXT_3407                        ((DWORD)0x00000D4FL)

//
// MessageId: MTXT_3408
//
// MessageText:
//
// The program cannot be used with this operating system.
//
#define MTXT_3408                        ((DWORD)0x00000D50L)

//
// MessageId: MTXT_3409
//
// MessageText:
//
// The redirector is already installed.
//
#define MTXT_3409                        ((DWORD)0x00000D51L)

//
// MessageId: MTXT_3410
//
// MessageText:
//
// Installing NETWKSTA.SYS Version %1.%2.%3  (%4)\n
//
#define MTXT_3410                        ((DWORD)0x00000D52L)

//
// MessageId: MTXT_3411
//
// MessageText:
//
// There was an error installing NETWKSTA.SYS.\n\n
// Press ENTER to continue.
//
#define MTXT_3411                        ((DWORD)0x00000D53L)

//
// MessageId: MTXT_3412
//
// MessageText:
//
// Resolver linkage problem.
//
#define MTXT_3412                        ((DWORD)0x00000D54L)

//
// MessageId: MTXT_3413
//
// MessageText:
//
// Your logon time at %1 ends at %2.\n
// Please clean up and log off.
//
#define MTXT_3413                        ((DWORD)0x00000D55L)

//
// MessageId: MTXT_3414
//
// MessageText:
//
// You will be automatically disconnected at %1.
//
#define MTXT_3414                        ((DWORD)0x00000D56L)

//
// MessageId: MTXT_3415
//
// MessageText:
//
// Your logon time at %1 has ended.
//
#define MTXT_3415                        ((DWORD)0x00000D57L)

//
// MessageId: MTXT_3416
//
// MessageText:
//
// Your logon time at %1 ended at %2.
//
#define MTXT_3416                        ((DWORD)0x00000D58L)

//
// MessageId: MTXT_3417
//
// MessageText:
//
// WARNING: You have until %1 to logoff. If you\n
// have not logged off at this time, your session will be\n
// disconnected, and any open files or devices you\n
// have open may lose data.
//
#define MTXT_3417                        ((DWORD)0x00000D59L)

//
// MessageId: MTXT_3418
//
// MessageText:
//
// WARNING: You must log off at %1 now.  You have\n
// two minutes to log off, or you will be disconnected.
//
#define MTXT_3418                        ((DWORD)0x00000D5AL)

//
// MessageId: MTXT_3419
//
// MessageText:
//
// You have open files or devices, and a forced\n
// disconnection may cause you to lose data.
//
#define MTXT_3419                        ((DWORD)0x00000D5BL)

//
// MessageId: MTXT_3420
//
// MessageText:
//
// Default Share for Internal Use %0
//
#define MTXT_3420                        ((DWORD)0x00000D5CL)

//
// MessageId: MTXT_3421
//
// MessageText:
//
// Messenger Service %0
//
#define MTXT_3421                        ((DWORD)0x00000D5DL)


 apperr.h (non-public) message definitions (3500 - 3999 APPERR_BASE)

//
// MessageId: APPERR_3500
//
// MessageText:
//
// The command completed successfully.
//
#define APPERR_3500                      ((DWORD)0x00000DACL)

//
// MessageId: APPERR_3501
//
// MessageText:
//
// You used an invalid option.
//
#define APPERR_3501                      ((DWORD)0x00000DADL)

//
// MessageId: APPERR_3502
//
// MessageText:
//
// System error %1 has occurred.
//
#define APPERR_3502                      ((DWORD)0x00000DAEL)

//
// MessageId: APPERR_3503
//
// MessageText:
//
// The command contains an invalid number of arguments.
//
#define APPERR_3503                      ((DWORD)0x00000DAFL)

//
// MessageId: APPERR_3504
//
// MessageText:
//
// The command completed with one or more errors.
//
#define APPERR_3504                      ((DWORD)0x00000DB0L)

//
// MessageId: APPERR_3505
//
// MessageText:
//
// You used an option with an invalid value.
//
#define APPERR_3505                      ((DWORD)0x00000DB1L)

//
// MessageId: APPERR_3506
//
// MessageText:
//
// The option %1 is unknown.
//
#define APPERR_3506                      ((DWORD)0x00000DB2L)

//
// MessageId: APPERR_3507
//
// MessageText:
//
// Option %1 is ambiguous.
//
#define APPERR_3507                      ((DWORD)0x00000DB3L)

//
// MessageId: APPERR_3510
//
// MessageText:
//
// A command was used with conflicting switches.
//
#define APPERR_3510                      ((DWORD)0x00000DB6L)

//
// MessageId: APPERR_3511
//
// MessageText:
//
// Could not find subprogram %1.
//
#define APPERR_3511                      ((DWORD)0x00000DB7L)

//
// MessageId: APPERR_3512
//
// MessageText:
//
// The software requires a newer version of the operating\nsystem.
//
#define APPERR_3512                      ((DWORD)0x00000DB8L)

//
// MessageId: APPERR_3513
//
// MessageText:
//
// More data is available than can be returned by the operating\nsystem.
//
#define APPERR_3513                      ((DWORD)0x00000DB9L)

//
// MessageId: APPERR_3514
//
// MessageText:
//
// More help is available by typing NET HELPMSG %1.
//
#define APPERR_3514                      ((DWORD)0x00000DBAL)

//
// MessageId: APPERR_3515
//
// MessageText:
//
// The command can be used only on a Domain Controller.
//
#define APPERR_3515                      ((DWORD)0x00000DBBL)

//
// MessageId: APPERR_3516
//
// MessageText:
//
// This command cannot be used on a Domain Controller.
//
#define APPERR_3516                      ((DWORD)0x00000DBCL)

//
// MessageId: APPERR_3520
//
// MessageText:
//
// These services are started:
//
#define APPERR_3520                      ((DWORD)0x00000DC0L)

//
// MessageId: APPERR_3521
//
// MessageText:
//
// The %1 service is not started.
//
#define APPERR_3521                      ((DWORD)0x00000DC1L)

//
// MessageId: APPERR_3522
//
// MessageText:
//
// The %1 service is starting%0
//
#define APPERR_3522                      ((DWORD)0x00000DC2L)

//
// MessageId: APPERR_3523
//
// MessageText:
//
// The %1 service could not be started.
//
#define APPERR_3523                      ((DWORD)0x00000DC3L)

//
// MessageId: APPERR_3524
//
// MessageText:
//
// The %1 service was started successfully.
//
#define APPERR_3524                      ((DWORD)0x00000DC4L)

//
// MessageId: APPERR_3525
//
// MessageText:
//
// Stopping the Workstation service also stops the Server service.
//
#define APPERR_3525                      ((DWORD)0x00000DC5L)

//
// MessageId: APPERR_3526
//
// MessageText:
//
// The workstation has open files.
//
#define APPERR_3526                      ((DWORD)0x00000DC6L)

//
// MessageId: APPERR_3527
//
// MessageText:
//
// The %1 service is stopping%0
//
#define APPERR_3527                      ((DWORD)0x00000DC7L)

//
// MessageId: APPERR_3528
//
// MessageText:
//
// The %1 service could not be stopped.
//
#define APPERR_3528                      ((DWORD)0x00000DC8L)

//
// MessageId: APPERR_3529
//
// MessageText:
//
// The %1 service was stopped successfully.
//
#define APPERR_3529                      ((DWORD)0x00000DC9L)

//
// MessageId: APPERR_3530
//
// MessageText:
//
// The following services are dependent on the %1 service.\nStopping the %1 service will also stop these services.
//
#define APPERR_3530                      ((DWORD)0x00000DCAL)

//
// MessageId: APPERR_3533
//
// MessageText:
//
// The service is starting or stopping.  Please try again later.
//
#define APPERR_3533                      ((DWORD)0x00000DCDL)

//
// MessageId: APPERR_3534
//
// MessageText:
//
// The service did not report an error.
//
#define APPERR_3534                      ((DWORD)0x00000DCEL)

//
// MessageId: APPERR_3535
//
// MessageText:
//
// An error occurred controlling the device.
//
#define APPERR_3535                      ((DWORD)0x00000DCFL)

//
// MessageId: APPERR_3536
//
// MessageText:
//
// The %1 service was continued successfully.
//
#define APPERR_3536                      ((DWORD)0x00000DD0L)

//
// MessageId: APPERR_3537
//
// MessageText:
//
// The %1 service was paused successfully.
//
#define APPERR_3537                      ((DWORD)0x00000DD1L)

//
// MessageId: APPERR_3538
//
// MessageText:
//
// The %1 service failed to resume.
//
#define APPERR_3538                      ((DWORD)0x00000DD2L)

//
// MessageId: APPERR_3539
//
// MessageText:
//
// The %1 service failed to pause.
//
#define APPERR_3539                      ((DWORD)0x00000DD3L)

//
// MessageId: APPERR_3540
//
// MessageText:
//
// The %1 service continue is pending%0
//
#define APPERR_3540                      ((DWORD)0x00000DD4L)

//
// MessageId: APPERR_3541
//
// MessageText:
//
// The %1 service pause is pending%0
//
#define APPERR_3541                      ((DWORD)0x00000DD5L)

//
// MessageId: APPERR_3542
//
// MessageText:
//
// %1 was continued successfully.
//
#define APPERR_3542                      ((DWORD)0x00000DD6L)

//
// MessageId: APPERR_3543
//
// MessageText:
//
// %1 was paused successfully.
//
#define APPERR_3543                      ((DWORD)0x00000DD7L)

//
// MessageId: APPERR_3544
//
// MessageText:
//
// The %1 service has been started by another process and is pending.%0
//
#define APPERR_3544                      ((DWORD)0x00000DD8L)

//
// MessageId: APPERR_3547
//
// MessageText:
//
// A service specific error occurred: %1.
//
#define APPERR_3547                      ((DWORD)0x00000DDBL)

//
// MessageId: APPERR_3660
//
// MessageText:
//
// These workstations have sessions on this server:
//
#define APPERR_3660                      ((DWORD)0x00000E4CL)

//
// MessageId: APPERR_3661
//
// MessageText:
//
// These workstations have sessions with open files on this server:
//
#define APPERR_3661                      ((DWORD)0x00000E4DL)

//
// MessageId: APPERR_3666
//
// MessageText:
//
// The message alias is forwarded.
//
#define APPERR_3666                      ((DWORD)0x00000E52L)

//
// MessageId: APPERR_3670
//
// MessageText:
//
// You have these remote connections:
//
#define APPERR_3670                      ((DWORD)0x00000E56L)

//
// MessageId: APPERR_3671
//
// MessageText:
//
// Continuing will cancel the connections.
//
#define APPERR_3671                      ((DWORD)0x00000E57L)

//
// MessageId: APPERR_3675
//
// MessageText:
//
// The session from %1 has open files.
//
#define APPERR_3675                      ((DWORD)0x00000E5BL)

//
// MessageId: APPERR_3676
//
// MessageText:
//
// New connections will be remembered.
//
#define APPERR_3676                      ((DWORD)0x00000E5CL)

//
// MessageId: APPERR_3677
//
// MessageText:
//
// New connections will not be remembered.
//
#define APPERR_3677                      ((DWORD)0x00000E5DL)

//
// MessageId: APPERR_3678
//
// MessageText:
//
// An error occurred while saving your profile. The state of your remembered connections has not changed.
//
#define APPERR_3678                      ((DWORD)0x00000E5EL)

//
// MessageId: APPERR_3679
//
// MessageText:
//
// An error occurred while reading your profile.
//
#define APPERR_3679                      ((DWORD)0x00000E5FL)

//
// MessageId: APPERR_3680
//
// MessageText:
//
// An error occurred while restoring the connection to %1.
//
#define APPERR_3680                      ((DWORD)0x00000E60L)

//
// MessageId: APPERR_3682
//
// MessageText:
//
// No network services are started.
//
#define APPERR_3682                      ((DWORD)0x00000E62L)

//
// MessageId: APPERR_3683
//
// MessageText:
//
// There are no entries in the list.
//
#define APPERR_3683                      ((DWORD)0x00000E63L)

//
// MessageId: APPERR_3688
//
// MessageText:
//
// Users have open files on %1.  Continuing the operation will force the files closed.
//
#define APPERR_3688                      ((DWORD)0x00000E68L)

//
// MessageId: APPERR_3689
//
// MessageText:
//
// The Workstation service is already running. The operating system will ignore command options for the workstation.
//
#define APPERR_3689                      ((DWORD)0x00000E69L)

//
// MessageId: APPERR_3691
//
// MessageText:
//
// There are open files and/or incomplete directory searches pending on the connection to %1.
//
#define APPERR_3691                      ((DWORD)0x00000E6BL)

//
// MessageId: APPERR_3693
//
// MessageText:
//
// The request will be processed at a domain controller for domain %1.
//
#define APPERR_3693                      ((DWORD)0x00000E6DL)

//
// MessageId: APPERR_3694
//
// MessageText:
//
// The shared queue cannot be deleted while a print job is being spooled to the queue.
//
#define APPERR_3694                      ((DWORD)0x00000E6EL)

//
// MessageId: APPERR_3695
//
// MessageText:
//
// %1 has a remembered connection to %2.
//
#define APPERR_3695                      ((DWORD)0x00000E6FL)

//
// MessageId: APPERR_3710
//
// MessageText:
//
// An error occurred while opening the Help file.
//
#define APPERR_3710                      ((DWORD)0x00000E7EL)

//
// MessageId: APPERR_3711
//
// MessageText:
//
// The Help file is empty.
//
#define APPERR_3711                      ((DWORD)0x00000E7FL)

//
// MessageId: APPERR_3712
//
// MessageText:
//
// The Help file is corrupted.
//
#define APPERR_3712                      ((DWORD)0x00000E80L)

//
// MessageId: APPERR_3713
//
// MessageText:
//
// Could not find a domain controller for domain %1.
//
#define APPERR_3713                      ((DWORD)0x00000E81L)

//
// MessageId: APPERR_3714
//
// MessageText:
//
// This operation is privileged on systems with earlier\nversions of the software.
//
#define APPERR_3714                      ((DWORD)0x00000E82L)

//
// MessageId: APPERR_3716
//
// MessageText:
//
// The device type is unknown.
//
#define APPERR_3716                      ((DWORD)0x00000E84L)

//
// MessageId: APPERR_3717
//
// MessageText:
//
// The log file has been corrupted.
//
#define APPERR_3717                      ((DWORD)0x00000E85L)

//
// MessageId: APPERR_3718
//
// MessageText:
//
// Program filenames must end with .EXE.
//
#define APPERR_3718                      ((DWORD)0x00000E86L)

//
// MessageId: APPERR_3719
//
// MessageText:
//
// A matching share could not be found so nothing was deleted.
//
#define APPERR_3719                      ((DWORD)0x00000E87L)

//
// MessageId: APPERR_3720
//
// MessageText:
//
// A bad value is in the units-per-week field of the user record.
//
#define APPERR_3720                      ((DWORD)0x00000E88L)

//
// MessageId: APPERR_3721
//
// MessageText:
//
// The password is invalid for %1.
//
#define APPERR_3721                      ((DWORD)0x00000E89L)

//
// MessageId: APPERR_3722
//
// MessageText:
//
// An error occurred while sending a message to %1.
//
#define APPERR_3722                      ((DWORD)0x00000E8AL)

//
// MessageId: APPERR_3723
//
// MessageText:
//
// The password or user name is invalid for %1.
//
#define APPERR_3723                      ((DWORD)0x00000E8BL)

//
// MessageId: APPERR_3725
//
// MessageText:
//
// An error occurred when the share was deleted.
//
#define APPERR_3725                      ((DWORD)0x00000E8DL)

//
// MessageId: APPERR_3726
//
// MessageText:
//
// The user name is invalid.
//
#define APPERR_3726                      ((DWORD)0x00000E8EL)

//
// MessageId: APPERR_3727
//
// MessageText:
//
// The password is invalid.
//
#define APPERR_3727                      ((DWORD)0x00000E8FL)

//
// MessageId: APPERR_3728
//
// MessageText:
//
// The passwords do not match.
//
#define APPERR_3728                      ((DWORD)0x00000E90L)

//
// MessageId: APPERR_3729
//
// MessageText:
//
// Your persistent connections were not all restored.
//
#define APPERR_3729                      ((DWORD)0x00000E91L)

//
// MessageId: APPERR_3730
//
// MessageText:
//
// This is not a valid computer name or domain name.
//
#define APPERR_3730                      ((DWORD)0x00000E92L)

//
// MessageId: APPERR_3732
//
// MessageText:
//
// Default permissions cannot be set for that resource.
//
#define APPERR_3732                      ((DWORD)0x00000E94L)

//
// MessageId: APPERR_3734
//
// MessageText:
//
// A valid password was not entered.
//
#define APPERR_3734                      ((DWORD)0x00000E96L)

//
// MessageId: APPERR_3735
//
// MessageText:
//
// A valid name was not entered.
//
#define APPERR_3735                      ((DWORD)0x00000E97L)

//
// MessageId: APPERR_3736
//
// MessageText:
//
// The resource named cannot be shared.
//
#define APPERR_3736                      ((DWORD)0x00000E98L)

//
// MessageId: APPERR_3737
//
// MessageText:
//
// The permissions string contains invalid permissions.
//
#define APPERR_3737                      ((DWORD)0x00000E99L)

//
// MessageId: APPERR_3738
//
// MessageText:
//
// You can only perform this operation on printers and communication devices.
//
#define APPERR_3738                      ((DWORD)0x00000E9AL)

//
// MessageId: APPERR_3742
//
// MessageText:
//
// %1 is an invalid user or group name.
//
#define APPERR_3742                      ((DWORD)0x00000E9EL)

//
// MessageId: APPERR_3743
//
// MessageText:
//
// The server is not configured for remote administration.
//
#define APPERR_3743                      ((DWORD)0x00000E9FL)

//
// MessageId: APPERR_3752
//
// MessageText:
//
// No users have sessions with this server.
//
#define APPERR_3752                      ((DWORD)0x00000EA8L)

//
// MessageId: APPERR_3753
//
// MessageText:
//
// User %1 is not a member of group %2.
//
#define APPERR_3753                      ((DWORD)0x00000EA9L)

//
// MessageId: APPERR_3754
//
// MessageText:
//
// User %1 is already a member of group %2.
//
#define APPERR_3754                      ((DWORD)0x00000EAAL)

//
// MessageId: APPERR_3755
//
// MessageText:
//
// There is no such user: %1.
//
#define APPERR_3755                      ((DWORD)0x00000EABL)

//
// MessageId: APPERR_3756
//
// MessageText:
//
// This is an invalid response.
//
#define APPERR_3756                      ((DWORD)0x00000EACL)

//
// MessageId: APPERR_3757
//
// MessageText:
//
// No valid response was provided.
//
#define APPERR_3757                      ((DWORD)0x00000EADL)

//
// MessageId: APPERR_3758
//
// MessageText:
//
// The destination list provided does not match the destination list of the printer queue.
//
#define APPERR_3758                      ((DWORD)0x00000EAEL)

//
// MessageId: APPERR_3759
//
// MessageText:
//
// Your password cannot be changed until %1.
//
#define APPERR_3759                      ((DWORD)0x00000EAFL)

//
// MessageId: APPERR_3760
//
// MessageText:
//
// %1 is not a recognized day of the week.
//
#define APPERR_3760                      ((DWORD)0x00000EB0L)

//
// MessageId: APPERR_3761
//
// MessageText:
//
// The time range specified ends before it starts.
//
#define APPERR_3761                      ((DWORD)0x00000EB1L)

//
// MessageId: APPERR_3762
//
// MessageText:
//
// %1 is not a recognized hour.
//
#define APPERR_3762                      ((DWORD)0x00000EB2L)

//
// MessageId: APPERR_3763
//
// MessageText:
//
// %1 is not a valid specification for minutes.
//
#define APPERR_3763                      ((DWORD)0x00000EB3L)

//
// MessageId: APPERR_3764
//
// MessageText:
//
// Time supplied is not exactly on the hour.
//
#define APPERR_3764                      ((DWORD)0x00000EB4L)

//
// MessageId: APPERR_3765
//
// MessageText:
//
// 12 and 24 hour time formats may not be mixed.
//
#define APPERR_3765                      ((DWORD)0x00000EB5L)

//
// MessageId: APPERR_3766
//
// MessageText:
//
// %1 is not a valid 12-hour suffix.
//
#define APPERR_3766                      ((DWORD)0x00000EB6L)

//
// MessageId: APPERR_3767
//
// MessageText:
//
// An illegal date format has been supplied.
//
#define APPERR_3767                      ((DWORD)0x00000EB7L)

//
// MessageId: APPERR_3768
//
// MessageText:
//
// An illegal day range has been supplied.
//
#define APPERR_3768                      ((DWORD)0x00000EB8L)

//
// MessageId: APPERR_3769
//
// MessageText:
//
// An illegal time range has been supplied.
//
#define APPERR_3769                      ((DWORD)0x00000EB9L)

//
// MessageId: APPERR_3770
//
// MessageText:
//
// Arguments to NET USER are invalid. Check the minimum password\n
// length and/or arguments supplied.
//
#define APPERR_3770                      ((DWORD)0x00000EBAL)

//
// MessageId: APPERR_3771
//
// MessageText:
//
// The value for ENABLESCRIPT must be YES.
//
#define APPERR_3771                      ((DWORD)0x00000EBBL)

//
// MessageId: APPERR_3773
//
// MessageText:
//
// An illegal country code has been supplied.
//
#define APPERR_3773                      ((DWORD)0x00000EBDL)

//
// MessageId: APPERR_3774
//
// MessageText:
//
// The user was successfully created but could not be added\n
// to the USERS local group.
//
#define APPERR_3774                      ((DWORD)0x00000EBEL)

//
// MessageId: APPERR_3775
//
// MessageText:
//
// The user context supplied is invalid.
//
#define APPERR_3775                      ((DWORD)0x00000EBFL)

//
// MessageId: APPERR_3776
//
// MessageText:
//
// The dynamic-link library %1 could not be loaded, or an error\n
// occurred while trying to use it.
//
#define APPERR_3776                      ((DWORD)0x00000EC0L)

//
// MessageId: APPERR_3777
//
// MessageText:
//
// Sending files is no longer supported.
//
#define APPERR_3777                      ((DWORD)0x00000EC1L)

//
// MessageId: APPERR_3778
//
// MessageText:
//
// You may not specify paths for ADMIN$ and IPC$ shares.
//
#define APPERR_3778                      ((DWORD)0x00000EC2L)

//
// MessageId: APPERR_3779
//
// MessageText:
//
// User or group %1 is already a member of local group %2.
//
#define APPERR_3779                      ((DWORD)0x00000EC3L)

//
// MessageId: APPERR_3780
//
// MessageText:
//
// There is no such user or group: %1.
//
#define APPERR_3780                      ((DWORD)0x00000EC4L)

//
// MessageId: APPERR_3781
//
// MessageText:
//
// There is no such computer: %1.
//
#define APPERR_3781                      ((DWORD)0x00000EC5L)

//
// MessageId: APPERR_3782
//
// MessageText:
//
// The computer %1 already exists.
//
#define APPERR_3782                      ((DWORD)0x00000EC6L)

//
// MessageId: APPERR_3783
//
// MessageText:
//
// There is no such global user or group: %1.
//
#define APPERR_3783                      ((DWORD)0x00000EC7L)

//
// MessageId: APPERR_3784
//
// MessageText:
//
// Only disk shares can be marked as cacheable
//
#define APPERR_3784                      ((DWORD)0x00000EC8L)

//
// MessageId: APPERR_3790
//
// MessageText:
//
// The system could not find message: %1.
//
#define APPERR_3790                      ((DWORD)0x00000ECEL)

//
// MessageId: APPERR_3802
//
// MessageText:
//
// This schedule date is invalid.
//
#define APPERR_3802                      ((DWORD)0x00000EDAL)

//
// MessageId: APPERR_3803
//
// MessageText:
//
// The LANMAN root directory is unavailable.
//
#define APPERR_3803                      ((DWORD)0x00000EDBL)

//
// MessageId: APPERR_3804
//
// MessageText:
//
// The SCHED.LOG file could not be opened.
//
#define APPERR_3804                      ((DWORD)0x00000EDCL)

//
// MessageId: APPERR_3805
//
// MessageText:
//
// The Server service has not been started.
//
#define APPERR_3805                      ((DWORD)0x00000EDDL)

//
// MessageId: APPERR_3806
//
// MessageText:
//
// The AT job ID does not exist.
//
#define APPERR_3806                      ((DWORD)0x00000EDEL)

//
// MessageId: APPERR_3807
//
// MessageText:
//
// The AT schedule file is corrupted.
//
#define APPERR_3807                      ((DWORD)0x00000EDFL)

//
// MessageId: APPERR_3808
//
// MessageText:
//
// The delete failed due to a problem with the AT schedule file.
//
#define APPERR_3808                      ((DWORD)0x00000EE0L)

//
// MessageId: APPERR_3809
//
// MessageText:
//
// The command line cannot exceed 259 characters.
//
#define APPERR_3809                      ((DWORD)0x00000EE1L)

//
// MessageId: APPERR_3810
//
// MessageText:
//
// The AT schedule file could not be updated because the disk is full.
//
#define APPERR_3810                      ((DWORD)0x00000EE2L)

//
// MessageId: APPERR_3812
//
// MessageText:
//
// The AT schedule file is invalid.  Please delete the file and create a new one.
//
#define APPERR_3812                      ((DWORD)0x00000EE4L)

//
// MessageId: APPERR_3813
//
// MessageText:
//
// The AT schedule file was deleted.
//
#define APPERR_3813                      ((DWORD)0x00000EE5L)

//
// MessageId: APPERR_3814
//
// MessageText:
//
// The syntax of this command is:\n\n
// AT [id] [/DELETE]\n
// AT time [/EVERY:date | /NEXT:date] command\n\n
// The AT command schedules a program command to run at a\n
// later date and time on a server.  It also displays the\n
// list of programs and commands scheduled to be run.\n\n
// You can specify the date as M,T,W,Th,F,Sa,Su or 1-31\n
// for the day of the month.\n\n
// You can specify the time in the 24 hour HH:MM format.
//
#define APPERR_3814                      ((DWORD)0x00000EE6L)

//
// MessageId: APPERR_3815
//
// MessageText:
//
// The AT command has timed-out.\n
// Please try again later.
//
#define APPERR_3815                      ((DWORD)0x00000EE7L)

//
// MessageId: APPERR_3816
//
// MessageText:
//
// The minimum password age for user accounts cannot be greater\n
// than the maximum password age.
//
#define APPERR_3816                      ((DWORD)0x00000EE8L)

//
// MessageId: APPERR_3817
//
// MessageText:
//
// You have specified a value that is incompatible\n
// with servers with down-level software. Please specify a lower value.
//
#define APPERR_3817                      ((DWORD)0x00000EE9L)

//
// MessageId: APPERR_3870
//
// MessageText:
//
// %1 is not a valid computer name.
//
#define APPERR_3870                      ((DWORD)0x00000F1EL)

//
// MessageId: APPERR_3871
//
// MessageText:
//
// %1 is not a valid Windows network message number.
//
#define APPERR_3871                      ((DWORD)0x00000F1FL)

//
// MessageId: APPERR_3900
//
// MessageText:
//
// Message from %1 to %2 on %3
//
#define APPERR_3900                      ((DWORD)0x00000F3CL)

//
// MessageId: APPERR_3901
//
// MessageText:
//
// ****
//
#define APPERR_3901                      ((DWORD)0x00000F3DL)

//
// MessageId: APPERR_3902
//
// MessageText:
//
// **** unexpected end of message ****
//
#define APPERR_3902                      ((DWORD)0x00000F3EL)

//
// MessageId: APPERR_3905
//
// MessageText:
//
// Press ESC to exit
//
#define APPERR_3905                      ((DWORD)0x00000F41L)

//
// MessageId: APPERR_3906
//
// MessageText:
//
// ...
//
#define APPERR_3906                      ((DWORD)0x00000F42L)

//
// MessageId: APPERR_3910
//
// MessageText:
//
// Current time at %1 is %2
//
#define APPERR_3910                      ((DWORD)0x00000F46L)

//
// MessageId: APPERR_3911
//
// MessageText:
//
// The current local clock is %1\n
// Do you want to set the local computer's time to match the\n
// time at %2? %3: %0
//
#define APPERR_3911                      ((DWORD)0x00000F47L)

//
// MessageId: APPERR_3912
//
// MessageText:
//
// Could not locate a time-server.
//
#define APPERR_3912                      ((DWORD)0x00000F48L)

//
// MessageId: APPERR_3913
//
// MessageText:
//
// Could not find the domain controller for domain %1.
//
#define APPERR_3913                      ((DWORD)0x00000F49L)

//
// MessageId: APPERR_3914
//
// MessageText:
//
// Local time (GMT%3) at %1 is %2
//
#define APPERR_3914                      ((DWORD)0x00000F4AL)

//
// MessageId: APPERR_3915
//
// MessageText:
//
// The user's home directory could not be determined.
//
#define APPERR_3915                      ((DWORD)0x00000F4BL)

//
// MessageId: APPERR_3916
//
// MessageText:
//
// The user's home directory has not been specified.
//
#define APPERR_3916                      ((DWORD)0x00000F4CL)

//
// MessageId: APPERR_3917
//
// MessageText:
//
// The name specified for the user's home directory (%1) is not a universal naming convention (UNC) name.
//
#define APPERR_3917                      ((DWORD)0x00000F4DL)

//
// MessageId: APPERR_3918
//
// MessageText:
//
// Drive %1 is now connected to %2. Your home directory is %3\\%4.
//
#define APPERR_3918                      ((DWORD)0x00000F4EL)

//
// MessageId: APPERR_3919
//
// MessageText:
//
// Drive %1 is now connected to %2.
//
#define APPERR_3919                      ((DWORD)0x00000F4FL)

 Language=Italian
 %1 è ora connesso con %2.
 .
//
// MessageId: APPERR_3920
//
// MessageText:
//
// There are no available drive letters left.
//
#define APPERR_3920                      ((DWORD)0x00000F50L)

//
// MessageId: APPERR_3932
//
// MessageText:
//
// %1 is not a valid domain or workgroup name.
//
#define APPERR_3932                      ((DWORD)0x00000F5CL)

//
// MessageId: APPERR_3935
//
// MessageText:
//
// The current SNTP value is: %1
//
#define APPERR_3935                      ((DWORD)0x00000F5FL)

//
// MessageId: APPERR_3936
//
// MessageText:
//
// This computer is not currently configured to use a specific SNTP server.
//
#define APPERR_3936                      ((DWORD)0x00000F60L)

//
// MessageId: APPERR_3937
//
// MessageText:
//
// This current autoconfigured SNTP value is: %1
//
#define APPERR_3937                      ((DWORD)0x00000F61L)

//
// MessageId: APPERR_3951
//
// MessageText:
//
// You specified too many values for the %1 option.
//
#define APPERR_3951                      ((DWORD)0x00000F6FL)

//
// MessageId: APPERR_3952
//
// MessageText:
//
// You entered an invalid value for the %1 option.
//
#define APPERR_3952                      ((DWORD)0x00000F70L)

//
// MessageId: APPERR_3953
//
// MessageText:
//
// The syntax is incorrect.
//
#define APPERR_3953                      ((DWORD)0x00000F71L)

//
// MessageId: APPERR_3960
//
// MessageText:
//
// You specified an invalid file number.
//
#define APPERR_3960                      ((DWORD)0x00000F78L)

//
// MessageId: APPERR_3961
//
// MessageText:
//
// You specified an invalid print job number.
//
#define APPERR_3961                      ((DWORD)0x00000F79L)

//
// MessageId: APPERR_3963
//
// MessageText:
//
// The user or group account specified cannot be found.
//
#define APPERR_3963                      ((DWORD)0x00000F7BL)

//
// MessageId: APPERR_3965
//
// MessageText:
//
// The user was added but could not be enabled for File and Print\n
// Services for NetWare.
//
#define APPERR_3965                      ((DWORD)0x00000F7DL)

//
// MessageId: APPERR_3966
//
// MessageText:
//
// File and Print Services for NetWare is not installed.
//
#define APPERR_3966                      ((DWORD)0x00000F7EL)

//
// MessageId: APPERR_3967
//
// MessageText:
//
// Cannot set user properties for File and Print Services for NetWare.
//
#define APPERR_3967                      ((DWORD)0x00000F7FL)

//
// MessageId: APPERR_3968
//
// MessageText:
//
// Password for %1 is: %2
//
#define APPERR_3968                      ((DWORD)0x00000F80L)

//
// MessageId: APPERR_3969
//
// MessageText:
//
// NetWare compatible logon
//
#define APPERR_3969                      ((DWORD)0x00000F81L)


 apperr2.h (non-public) message definitions (4300 - 5299 APPERR2_BASE)

//
// MessageId: APPERR2_4300
//
// MessageText:
//
// Yes%0
//
#define APPERR2_4300                     ((DWORD)0x000010CCL)

//
// MessageId: APPERR2_4301
//
// MessageText:
//
// No%0
//
#define APPERR2_4301                     ((DWORD)0x000010CDL)

//
// MessageId: APPERR2_4302
//
// MessageText:
//
// All%0
//
#define APPERR2_4302                     ((DWORD)0x000010CEL)

//
// MessageId: APPERR2_4303
//
// MessageText:
//
// None%0
//
#define APPERR2_4303                     ((DWORD)0x000010CFL)

//
// MessageId: APPERR2_4304
//
// MessageText:
//
// Always%0
//
#define APPERR2_4304                     ((DWORD)0x000010D0L)

//
// MessageId: APPERR2_4305
//
// MessageText:
//
// Never%0
//
#define APPERR2_4305                     ((DWORD)0x000010D1L)

//
// MessageId: APPERR2_4306
//
// MessageText:
//
// Unlimited%0
//
#define APPERR2_4306                     ((DWORD)0x000010D2L)

//
// MessageId: APPERR2_4307
//
// MessageText:
//
// Sunday%0
//
#define APPERR2_4307                     ((DWORD)0x000010D3L)

//
// MessageId: APPERR2_4308
//
// MessageText:
//
// Monday%0
//
#define APPERR2_4308                     ((DWORD)0x000010D4L)

//
// MessageId: APPERR2_4309
//
// MessageText:
//
// Tuesday%0
//
#define APPERR2_4309                     ((DWORD)0x000010D5L)

//
// MessageId: APPERR2_4310
//
// MessageText:
//
// Wednesday%0
//
#define APPERR2_4310                     ((DWORD)0x000010D6L)

//
// MessageId: APPERR2_4311
//
// MessageText:
//
// Thursday%0
//
#define APPERR2_4311                     ((DWORD)0x000010D7L)

//
// MessageId: APPERR2_4312
//
// MessageText:
//
// Friday%0
//
#define APPERR2_4312                     ((DWORD)0x000010D8L)

//
// MessageId: APPERR2_4313
//
// MessageText:
//
// Saturday%0
//
#define APPERR2_4313                     ((DWORD)0x000010D9L)

//
// MessageId: APPERR2_4314
//
// MessageText:
//
// Su%0
//
#define APPERR2_4314                     ((DWORD)0x000010DAL)

//
// MessageId: APPERR2_4315
//
// MessageText:
//
// M%0
//
#define APPERR2_4315                     ((DWORD)0x000010DBL)

//
// MessageId: APPERR2_4316
//
// MessageText:
//
// T%0
//
#define APPERR2_4316                     ((DWORD)0x000010DCL)

//
// MessageId: APPERR2_4317
//
// MessageText:
//
// W%0
//
#define APPERR2_4317                     ((DWORD)0x000010DDL)

//
// MessageId: APPERR2_4318
//
// MessageText:
//
// Th%0
//
#define APPERR2_4318                     ((DWORD)0x000010DEL)

//
// MessageId: APPERR2_4319
//
// MessageText:
//
// F%0
//
#define APPERR2_4319                     ((DWORD)0x000010DFL)

//
// MessageId: APPERR2_4320
//
// MessageText:
//
// S%0
//
#define APPERR2_4320                     ((DWORD)0x000010E0L)

//
// MessageId: APPERR2_4321
//
// MessageText:
//
// Unknown%0
//
#define APPERR2_4321                     ((DWORD)0x000010E1L)

//
// MessageId: APPERR2_4322
//
// MessageText:
//
// AM%0
//
#define APPERR2_4322                     ((DWORD)0x000010E2L)

//
// MessageId: APPERR2_4323
//
// MessageText:
//
// A.M.%0
//
#define APPERR2_4323                     ((DWORD)0x000010E3L)

//
// MessageId: APPERR2_4324
//
// MessageText:
//
// PM%0
//
#define APPERR2_4324                     ((DWORD)0x000010E4L)

//
// MessageId: APPERR2_4325
//
// MessageText:
//
// P.M.%0
//
#define APPERR2_4325                     ((DWORD)0x000010E5L)

//
// MessageId: APPERR2_4326
//
// MessageText:
//
// Server%0
//
#define APPERR2_4326                     ((DWORD)0x000010E6L)

//
// MessageId: APPERR2_4327
//
// MessageText:
//
// Redirector%0
//
#define APPERR2_4327                     ((DWORD)0x000010E7L)

//
// MessageId: APPERR2_4328
//
// MessageText:
//
// Application%0
//
#define APPERR2_4328                     ((DWORD)0x000010E8L)

//
// MessageId: APPERR2_4329
//
// MessageText:
//
// Total%0
//
#define APPERR2_4329                     ((DWORD)0x000010E9L)

//
// MessageId: APPERR2_4330
//
// MessageText:
//
// ? %1 %0
//
#define APPERR2_4330                     ((DWORD)0x000010EAL)

//
// MessageId: APPERR2_4331
//
// MessageText:
//
// K%0
//
#define APPERR2_4331                     ((DWORD)0x000010EBL)

//
// MessageId: APPERR2_4332
//
// MessageText:
//
// (none)%0
//
#define APPERR2_4332                     ((DWORD)0x000010ECL)

//
// MessageId: APPERR2_4333
//
// MessageText:
//
// Device%0
//
#define APPERR2_4333                     ((DWORD)0x000010EDL)

//
// MessageId: APPERR2_4334
//
// MessageText:
//
// Remark%0
//
#define APPERR2_4334                     ((DWORD)0x000010EEL)

//
// MessageId: APPERR2_4335
//
// MessageText:
//
// At%0
//
#define APPERR2_4335                     ((DWORD)0x000010EFL)

//
// MessageId: APPERR2_4336
//
// MessageText:
//
// Queue%0
//
#define APPERR2_4336                     ((DWORD)0x000010F0L)

//
// MessageId: APPERR2_4337
//
// MessageText:
//
// Queues%0
//
#define APPERR2_4337                     ((DWORD)0x000010F1L)

//
// MessageId: APPERR2_4338
//
// MessageText:
//
// User name%0
//
#define APPERR2_4338                     ((DWORD)0x000010F2L)

//
// MessageId: APPERR2_4339
//
// MessageText:
//
// Path%0
//
#define APPERR2_4339                     ((DWORD)0x000010F3L)

//
// MessageId: APPERR2_4340
//
// MessageText:
//
// (Y/N) [Y]%0
//
#define APPERR2_4340                     ((DWORD)0x000010F4L)

//
// MessageId: APPERR2_4341
//
// MessageText:
//
// (Y/N) [N]%0
//
#define APPERR2_4341                     ((DWORD)0x000010F5L)

//
// MessageId: APPERR2_4342
//
// MessageText:
//
// Error%0
//
#define APPERR2_4342                     ((DWORD)0x000010F6L)

//
// MessageId: APPERR2_4343
//
// MessageText:
//
// OK%0
//
#define APPERR2_4343                     ((DWORD)0x000010F7L)

//
// MessageId: APPERR2_4344
//
// MessageText:
//
// Y%0
//
#define APPERR2_4344                     ((DWORD)0x000010F8L)

//
// MessageId: APPERR2_4345
//
// MessageText:
//
// N%0
//
#define APPERR2_4345                     ((DWORD)0x000010F9L)

//
// MessageId: APPERR2_4346
//
// MessageText:
//
// Any%0
//
#define APPERR2_4346                     ((DWORD)0x000010FAL)

//
// MessageId: APPERR2_4347
//
// MessageText:
//
// A%0
//
#define APPERR2_4347                     ((DWORD)0x000010FBL)

//
// MessageId: APPERR2_4348
//
// MessageText:
//
// P%0
//
#define APPERR2_4348                     ((DWORD)0x000010FCL)

//
// MessageId: APPERR2_4349
//
// MessageText:
//
// (not found)%0
//
#define APPERR2_4349                     ((DWORD)0x000010FDL)

//
// MessageId: APPERR2_4350
//
// MessageText:
//
// (unknown)%0
//
#define APPERR2_4350                     ((DWORD)0x000010FEL)

//
// MessageId: APPERR2_4351
//
// MessageText:
//
// For help on %1 type NET HELP %1
//
#define APPERR2_4351                     ((DWORD)0x000010FFL)

//
// MessageId: APPERR2_4352
//
// MessageText:
//
// Grant%0
//
#define APPERR2_4352                     ((DWORD)0x00001100L)

//
// MessageId: APPERR2_4353
//
// MessageText:
//
// Read%0
//
#define APPERR2_4353                     ((DWORD)0x00001101L)

//
// MessageId: APPERR2_4354
//
// MessageText:
//
// Change%0
//
#define APPERR2_4354                     ((DWORD)0x00001102L)

//
// MessageId: APPERR2_4355
//
// MessageText:
//
// Full%0
//
#define APPERR2_4355                     ((DWORD)0x00001103L)

//
// MessageId: APPERR2_4356
//
// MessageText:
//
// Please type the password: %0
//
#define APPERR2_4356                     ((DWORD)0x00001104L)

//
// MessageId: APPERR2_4357
//
// MessageText:
//
// Type the password for %1: %0
//
#define APPERR2_4357                     ((DWORD)0x00001105L)

//
// MessageId: APPERR2_4358
//
// MessageText:
//
// Type a password for the user: %0
//
#define APPERR2_4358                     ((DWORD)0x00001106L)

//
// MessageId: APPERR2_4359
//
// MessageText:
//
// Type the password for the shared resource: %0
//
#define APPERR2_4359                     ((DWORD)0x00001107L)

//
// MessageId: APPERR2_4360
//
// MessageText:
//
// Type your password: %0
//
#define APPERR2_4360                     ((DWORD)0x00001108L)

//
// MessageId: APPERR2_4361
//
// MessageText:
//
// Retype the password to confirm: %0
//
#define APPERR2_4361                     ((DWORD)0x00001109L)

//
// MessageId: APPERR2_4362
//
// MessageText:
//
// Type the user's old password: %0
//
#define APPERR2_4362                     ((DWORD)0x0000110AL)

//
// MessageId: APPERR2_4363
//
// MessageText:
//
// Type the user's new password: %0
//
#define APPERR2_4363                     ((DWORD)0x0000110BL)

//
// MessageId: APPERR2_4364
//
// MessageText:
//
// Type your new password: %0
//
#define APPERR2_4364                     ((DWORD)0x0000110CL)

//
// MessageId: APPERR2_4365
//
// MessageText:
//
// Type the Replicator service password: %0
//
#define APPERR2_4365                     ((DWORD)0x0000110DL)

//
// MessageId: APPERR2_4366
//
// MessageText:
//
// Type your user name, or press ENTER if it is %1: %0
//
#define APPERR2_4366                     ((DWORD)0x0000110EL)

//
// MessageId: APPERR2_4367
//
// MessageText:
//
// Type the domain or server where you want to change a password, or\n
// press ENTER if it is for domain %1: %0.
//
#define APPERR2_4367                     ((DWORD)0x0000110FL)

//
// MessageId: APPERR2_4368
//
// MessageText:
//
// Type your user name: %0
//
#define APPERR2_4368                     ((DWORD)0x00001110L)

//
// MessageId: APPERR2_4369
//
// MessageText:
//
// Network statistics for \\%1
//
#define APPERR2_4369                     ((DWORD)0x00001111L)

//
// MessageId: APPERR2_4370
//
// MessageText:
//
// Printing options for %1
//
#define APPERR2_4370                     ((DWORD)0x00001112L)

//
// MessageId: APPERR2_4371
//
// MessageText:
//
// Communication-device queues accessing %1
//
#define APPERR2_4371                     ((DWORD)0x00001113L)

//
// MessageId: APPERR2_4372
//
// MessageText:
//
// Print job detail
//
#define APPERR2_4372                     ((DWORD)0x00001114L)

//
// MessageId: APPERR2_4373
//
// MessageText:
//
// Communication-device queues at \\%1
//
#define APPERR2_4373                     ((DWORD)0x00001115L)

//
// MessageId: APPERR2_4374
//
// MessageText:
//
// Printers at %1
//
#define APPERR2_4374                     ((DWORD)0x00001116L)

//
// MessageId: APPERR2_4375
//
// MessageText:
//
// Printers accessing %1
//
#define APPERR2_4375                     ((DWORD)0x00001117L)

//
// MessageId: APPERR2_4376
//
// MessageText:
//
// Print jobs at %1:
//
#define APPERR2_4376                     ((DWORD)0x00001118L)

//
// MessageId: APPERR2_4377
//
// MessageText:
//
// Shared resources at %1
//
#define APPERR2_4377                     ((DWORD)0x00001119L)

//
// MessageId: APPERR2_4378
//
// MessageText:
//
// The following running services can be controlled:
//
#define APPERR2_4378                     ((DWORD)0x0000111AL)

//
// MessageId: APPERR2_4379
//
// MessageText:
//
// Statistics are available for the following running services:
//
#define APPERR2_4379                     ((DWORD)0x0000111BL)

//
// MessageId: APPERR2_4380
//
// MessageText:
//
// User accounts for \\%1
//
#define APPERR2_4380                     ((DWORD)0x0000111CL)

//
// MessageId: APPERR2_4381
//
// MessageText:
//
// The syntax of this command is:
//
#define APPERR2_4381                     ((DWORD)0x0000111DL)

//
// MessageId: APPERR2_4382
//
// MessageText:
//
// The options of this command are:
//
#define APPERR2_4382                     ((DWORD)0x0000111EL)

//
// MessageId: APPERR2_4383
//
// MessageText:
//
// Please enter the name of the Primary Domain Controller: %0
//
#define APPERR2_4383                     ((DWORD)0x0000111FL)

//
// MessageId: APPERR2_4384
//
// MessageText:
//
// The string you have entered is too long. The maximum\n
// is %1, please reenter. %0
//
#define APPERR2_4384                     ((DWORD)0x00001120L)

//
// MessageId: APPERR2_4385
//
// MessageText:
//
// Sunday%0
//
#define APPERR2_4385                     ((DWORD)0x00001121L)

//
// MessageId: APPERR2_4386
//
// MessageText:
//
// Monday%0
//
#define APPERR2_4386                     ((DWORD)0x00001122L)

//
// MessageId: APPERR2_4387
//
// MessageText:
//
// Tuesday%0
//
#define APPERR2_4387                     ((DWORD)0x00001123L)

//
// MessageId: APPERR2_4388
//
// MessageText:
//
// Wednesday%0
//
#define APPERR2_4388                     ((DWORD)0x00001124L)

//
// MessageId: APPERR2_4389
//
// MessageText:
//
// Thursday%0
//
#define APPERR2_4389                     ((DWORD)0x00001125L)

//
// MessageId: APPERR2_4390
//
// MessageText:
//
// Friday%0
//
#define APPERR2_4390                     ((DWORD)0x00001126L)

//
// MessageId: APPERR2_4391
//
// MessageText:
//
// Saturday%0
//
#define APPERR2_4391                     ((DWORD)0x00001127L)

//
// MessageId: APPERR2_4392
//
// MessageText:
//
// Su%0
//
#define APPERR2_4392                     ((DWORD)0x00001128L)

//
// MessageId: APPERR2_4393
//
// MessageText:
//
// M%0
//
#define APPERR2_4393                     ((DWORD)0x00001129L)

//
// MessageId: APPERR2_4394
//
// MessageText:
//
// T%0
//
#define APPERR2_4394                     ((DWORD)0x0000112AL)

//
// MessageId: APPERR2_4395
//
// MessageText:
//
// W%0
//
#define APPERR2_4395                     ((DWORD)0x0000112BL)

//
// MessageId: APPERR2_4396
//
// MessageText:
//
// Th%0
//
#define APPERR2_4396                     ((DWORD)0x0000112CL)

//
// MessageId: APPERR2_4397
//
// MessageText:
//
// F%0
//
#define APPERR2_4397                     ((DWORD)0x0000112DL)

//
// MessageId: APPERR2_4398
//
// MessageText:
//
// S%0
//
#define APPERR2_4398                     ((DWORD)0x0000112EL)

//
// MessageId: APPERR2_4399
//
// MessageText:
//
// Sa%0
//
#define APPERR2_4399                     ((DWORD)0x0000112FL)

//
// MessageId: APPERR2_4400
//
// MessageText:
//
// Group Accounts for \\%1
//
#define APPERR2_4400                     ((DWORD)0x00001130L)

//
// MessageId: APPERR2_4401
//
// MessageText:
//
// Group name%0
//
#define APPERR2_4401                     ((DWORD)0x00001131L)

//
// MessageId: APPERR2_4402
//
// MessageText:
//
// Comment%0
//
#define APPERR2_4402                     ((DWORD)0x00001132L)

//
// MessageId: APPERR2_4403
//
// MessageText:
//
// Members
//
#define APPERR2_4403                     ((DWORD)0x00001133L)

//
// MessageId: APPERR2_4405
//
// MessageText:
//
// Aliases for \\%1
//
#define APPERR2_4405                     ((DWORD)0x00001135L)

//
// MessageId: APPERR2_4406
//
// MessageText:
//
// Alias name%0
//
#define APPERR2_4406                     ((DWORD)0x00001136L)

//
// MessageId: APPERR2_4407
//
// MessageText:
//
// Comment%0
//
#define APPERR2_4407                     ((DWORD)0x00001137L)

//
// MessageId: APPERR2_4408
//
// MessageText:
//
// Members
//
#define APPERR2_4408                     ((DWORD)0x00001138L)

//
// MessageId: APPERR2_4410
//
// MessageText:
//
// User Accounts for \\%1
//
#define APPERR2_4410                     ((DWORD)0x0000113AL)

//
// MessageId: APPERR2_4411
//
// MessageText:
//
// User name%0
//
#define APPERR2_4411                     ((DWORD)0x0000113BL)

//
// MessageId: APPERR2_4412
//
// MessageText:
//
// Full Name%0
//
#define APPERR2_4412                     ((DWORD)0x0000113CL)

//
// MessageId: APPERR2_4413
//
// MessageText:
//
// Comment%0
//
#define APPERR2_4413                     ((DWORD)0x0000113DL)

//
// MessageId: APPERR2_4414
//
// MessageText:
//
// User's comment%0
//
#define APPERR2_4414                     ((DWORD)0x0000113EL)

//
// MessageId: APPERR2_4415
//
// MessageText:
//
// Parameters%0
//
#define APPERR2_4415                     ((DWORD)0x0000113FL)

//
// MessageId: APPERR2_4416
//
// MessageText:
//
// Country code%0
//
#define APPERR2_4416                     ((DWORD)0x00001140L)

//
// MessageId: APPERR2_4417
//
// MessageText:
//
// Privilege level%0
//
#define APPERR2_4417                     ((DWORD)0x00001141L)

//
// MessageId: APPERR2_4418
//
// MessageText:
//
// Operator privileges%0
//
#define APPERR2_4418                     ((DWORD)0x00001142L)

//
// MessageId: APPERR2_4419
//
// MessageText:
//
// Account active%0
//
#define APPERR2_4419                     ((DWORD)0x00001143L)

//
// MessageId: APPERR2_4420
//
// MessageText:
//
// Account expires%0
//
#define APPERR2_4420                     ((DWORD)0x00001144L)

//
// MessageId: APPERR2_4421
//
// MessageText:
//
// Password last set%0
//
#define APPERR2_4421                     ((DWORD)0x00001145L)

//
// MessageId: APPERR2_4422
//
// MessageText:
//
// Password expires%0
//
#define APPERR2_4422                     ((DWORD)0x00001146L)

//
// MessageId: APPERR2_4423
//
// MessageText:
//
// Password changeable%0
//
#define APPERR2_4423                     ((DWORD)0x00001147L)

//
// MessageId: APPERR2_4424
//
// MessageText:
//
// Workstations allowed%0
//
#define APPERR2_4424                     ((DWORD)0x00001148L)

//
// MessageId: APPERR2_4425
//
// MessageText:
//
// Maximum disk space%0
//
#define APPERR2_4425                     ((DWORD)0x00001149L)

//
// MessageId: APPERR2_4426
//
// MessageText:
//
// Unlimited%0
//
#define APPERR2_4426                     ((DWORD)0x0000114AL)

//
// MessageId: APPERR2_4427
//
// MessageText:
//
// Local Group Memberships%0
//
#define APPERR2_4427                     ((DWORD)0x0000114BL)

//
// MessageId: APPERR2_4428
//
// MessageText:
//
// Domain controller%0
//
#define APPERR2_4428                     ((DWORD)0x0000114CL)

//
// MessageId: APPERR2_4429
//
// MessageText:
//
// Logon script%0
//
#define APPERR2_4429                     ((DWORD)0x0000114DL)

//
// MessageId: APPERR2_4430
//
// MessageText:
//
// Last logon%0
//
#define APPERR2_4430                     ((DWORD)0x0000114EL)

//
// MessageId: APPERR2_4431
//
// MessageText:
//
// Global Group memberships%0
//
#define APPERR2_4431                     ((DWORD)0x0000114FL)

//
// MessageId: APPERR2_4432
//
// MessageText:
//
// Logon hours allowed%0
//
#define APPERR2_4432                     ((DWORD)0x00001150L)

//
// MessageId: APPERR2_4433
//
// MessageText:
//
// All%0
//
#define APPERR2_4433                     ((DWORD)0x00001151L)

//
// MessageId: APPERR2_4434
//
// MessageText:
//
// None%0
//
#define APPERR2_4434                     ((DWORD)0x00001152L)

//
// MessageId: APPERR2_4435
//
// MessageText:
//
// Daily %1 - %2%0
//
#define APPERR2_4435                     ((DWORD)0x00001153L)

//
// MessageId: APPERR2_4436
//
// MessageText:
//
// Home directory%0
//
#define APPERR2_4436                     ((DWORD)0x00001154L)

//
// MessageId: APPERR2_4437
//
// MessageText:
//
// Password required%0
//
#define APPERR2_4437                     ((DWORD)0x00001155L)

//
// MessageId: APPERR2_4438
//
// MessageText:
//
// User may change password%0
//
#define APPERR2_4438                     ((DWORD)0x00001156L)

//
// MessageId: APPERR2_4439
//
// MessageText:
//
// User profile%0
//
#define APPERR2_4439                     ((DWORD)0x00001157L)

//
// MessageId: APPERR2_4440
//
// MessageText:
//
// Locked%0
//
#define APPERR2_4440                     ((DWORD)0x00001158L)

//
// MessageId: APPERR2_4450
//
// MessageText:
//
// Computer name%0
//
#define APPERR2_4450                     ((DWORD)0x00001162L)

//
// MessageId: APPERR2_4451
//
// MessageText:
//
// User name%0
//
#define APPERR2_4451                     ((DWORD)0x00001163L)

//
// MessageId: APPERR2_4452
//
// MessageText:
//
// Software version%0
//
#define APPERR2_4452                     ((DWORD)0x00001164L)

//
// MessageId: APPERR2_4453
//
// MessageText:
//
// Workstation active on%0
//
#define APPERR2_4453                     ((DWORD)0x00001165L)

//
// MessageId: APPERR2_4454
//
// MessageText:
//
// ReactOS root directory%0
//
#define APPERR2_4454                     ((DWORD)0x00001166L)

//
// MessageId: APPERR2_4455
//
// MessageText:
//
// Workstation domain%0
//
#define APPERR2_4455                     ((DWORD)0x00001167L)

//
// MessageId: APPERR2_4456
//
// MessageText:
//
// Logon domain%0
//
#define APPERR2_4456                     ((DWORD)0x00001168L)

//
// MessageId: APPERR2_4457
//
// MessageText:
//
// Other domain(s)%0
//
#define APPERR2_4457                     ((DWORD)0x00001169L)

//
// MessageId: APPERR2_4458
//
// MessageText:
//
// COM Open Timeout (sec)%0
//
#define APPERR2_4458                     ((DWORD)0x0000116AL)

//
// MessageId: APPERR2_4459
//
// MessageText:
//
// COM Send Count (byte)%0
//
#define APPERR2_4459                     ((DWORD)0x0000116BL)

//
// MessageId: APPERR2_4460
//
// MessageText:
//
// COM Send Timeout (msec)%0
//
#define APPERR2_4460                     ((DWORD)0x0000116CL)

//
// MessageId: APPERR2_4461
//
// MessageText:
//
// DOS session print time-out (sec)%0
//
#define APPERR2_4461                     ((DWORD)0x0000116DL)

//
// MessageId: APPERR2_4462
//
// MessageText:
//
// Maximum error log size (K)%0
//
#define APPERR2_4462                     ((DWORD)0x0000116EL)

//
// MessageId: APPERR2_4463
//
// MessageText:
//
// Maximum cache memory (K)%0
//
#define APPERR2_4463                     ((DWORD)0x0000116FL)

//
// MessageId: APPERR2_4464
//
// MessageText:
//
// Number of network buffers%0
//
#define APPERR2_4464                     ((DWORD)0x00001170L)

//
// MessageId: APPERR2_4465
//
// MessageText:
//
// Number of character buffers%0
//
#define APPERR2_4465                     ((DWORD)0x00001171L)

//
// MessageId: APPERR2_4466
//
// MessageText:
//
// Size of network buffers%0
//
#define APPERR2_4466                     ((DWORD)0x00001172L)

//
// MessageId: APPERR2_4467
//
// MessageText:
//
// Size of character buffers%0
//
#define APPERR2_4467                     ((DWORD)0x00001173L)

//
// MessageId: APPERR2_4468
//
// MessageText:
//
// Full Computer name%0
//
#define APPERR2_4468                     ((DWORD)0x00001174L)

//
// MessageId: APPERR2_4469
//
// MessageText:
//
// Workstation Domain DNS Name%0
//
#define APPERR2_4469                     ((DWORD)0x00001175L)

//
// MessageId: APPERR2_4470
//
// MessageText:
//
// ReactOS%0
//
#define APPERR2_4470                     ((DWORD)0x00001176L)

//
// MessageId: APPERR2_4481
//
// MessageText:
//
// Server Name%0
//
#define APPERR2_4481                     ((DWORD)0x00001181L)

//
// MessageId: APPERR2_4482
//
// MessageText:
//
// Server Comment%0
//
#define APPERR2_4482                     ((DWORD)0x00001182L)

//
// MessageId: APPERR2_4483
//
// MessageText:
//
// Send administrative alerts to%0
//
#define APPERR2_4483                     ((DWORD)0x00001183L)

//
// MessageId: APPERR2_4484
//
// MessageText:
//
// Software version%0
//
#define APPERR2_4484                     ((DWORD)0x00001184L)

//
// MessageId: APPERR2_4485
//
// MessageText:
//
// Peer Server%0
//
#define APPERR2_4485                     ((DWORD)0x00001185L)

//
// MessageId: APPERR2_4486
//
// MessageText:
//
// ReactOS%0
//
#define APPERR2_4486                     ((DWORD)0x00001186L)

//
// MessageId: APPERR2_4487
//
// MessageText:
//
// Server Level%0
//
#define APPERR2_4487                     ((DWORD)0x00001187L)

//
// MessageId: APPERR2_4488
//
// MessageText:
//
// ReactOS Server%0
//
#define APPERR2_4488                     ((DWORD)0x00001188L)

//
// MessageId: APPERR2_4489
//
// MessageText:
//
// Server is active on%0
//
#define APPERR2_4489                     ((DWORD)0x00001189L)

//
// MessageId: APPERR2_4492
//
// MessageText:
//
// Server hidden%0
//
#define APPERR2_4492                     ((DWORD)0x0000118CL)

//
// MessageId: APPERR2_4506
//
// MessageText:
//
// Maximum Logged On Users%0
//
#define APPERR2_4506                     ((DWORD)0x0000119AL)

//
// MessageId: APPERR2_4507
//
// MessageText:
//
// Maximum concurrent administrators%0
//
#define APPERR2_4507                     ((DWORD)0x0000119BL)

//
// MessageId: APPERR2_4508
//
// MessageText:
//
// Maximum resources shared%0
//
#define APPERR2_4508                     ((DWORD)0x0000119CL)

//
// MessageId: APPERR2_4509
//
// MessageText:
//
// Maximum connections to resources%0
//
#define APPERR2_4509                     ((DWORD)0x0000119DL)

//
// MessageId: APPERR2_4510
//
// MessageText:
//
// Maximum open files on server%0
//
#define APPERR2_4510                     ((DWORD)0x0000119EL)

//
// MessageId: APPERR2_4511
//
// MessageText:
//
// Maximum open files per session%0
//
#define APPERR2_4511                     ((DWORD)0x0000119FL)

//
// MessageId: APPERR2_4512
//
// MessageText:
//
// Maximum file locks%0
//
#define APPERR2_4512                     ((DWORD)0x000011A0L)

//
// MessageId: APPERR2_4520
//
// MessageText:
//
// Idle session time (min)%0
//
#define APPERR2_4520                     ((DWORD)0x000011A8L)

//
// MessageId: APPERR2_4526
//
// MessageText:
//
// Share-level%0
//
#define APPERR2_4526                     ((DWORD)0x000011AEL)

//
// MessageId: APPERR2_4527
//
// MessageText:
//
// User-level%0
//
#define APPERR2_4527                     ((DWORD)0x000011AFL)

//
// MessageId: APPERR2_4530
//
// MessageText:
//
// Unlimited Server%0
//
#define APPERR2_4530                     ((DWORD)0x000011B2L)

//
// MessageId: APPERR2_4570
//
// MessageText:
//
// Force user logoff how long after time expires?:%0\n
//
#define APPERR2_4570                     ((DWORD)0x000011DAL)

//
// MessageId: APPERR2_4571
//
// MessageText:
//
// Lock out account after how many bad passwords?:%0\n
//
#define APPERR2_4571                     ((DWORD)0x000011DBL)

//
// MessageId: APPERR2_4572
//
// MessageText:
//
// Minimum password age (days):%0
//
#define APPERR2_4572                     ((DWORD)0x000011DCL)

//
// MessageId: APPERR2_4573
//
// MessageText:
//
// Maximum password age (days):%0
//
#define APPERR2_4573                     ((DWORD)0x000011DDL)

//
// MessageId: APPERR2_4574
//
// MessageText:
//
// Minimum password length:%0
//
#define APPERR2_4574                     ((DWORD)0x000011DEL)

//
// MessageId: APPERR2_4575
//
// MessageText:
//
// Length of password history maintained:%0
//
#define APPERR2_4575                     ((DWORD)0x000011DFL)

//
// MessageId: APPERR2_4576
//
// MessageText:
//
// Computer role:%0
//
#define APPERR2_4576                     ((DWORD)0x000011E0L)

//
// MessageId: APPERR2_4577
//
// MessageText:
//
// Primary Domain controller for workstation domain:%0.
//
#define APPERR2_4577                     ((DWORD)0x000011E1L)

//
// MessageId: APPERR2_4578
//
// MessageText:
//
// Lockout threshold:%0
//
#define APPERR2_4578                     ((DWORD)0x000011E2L)

//
// MessageId: APPERR2_4579
//
// MessageText:
//
// Lockout duration (minutes):%0
//
#define APPERR2_4579                     ((DWORD)0x000011E3L)

//
// MessageId: APPERR2_4580
//
// MessageText:
//
// Lockout observation window (minutes):%0
//
#define APPERR2_4580                     ((DWORD)0x000011E4L)

//
// MessageId: APPERR2_4600
//
// MessageText:
//
// Statistics since%0
//
#define APPERR2_4600                     ((DWORD)0x000011F8L)

//
// MessageId: APPERR2_4601
//
// MessageText:
//
// Sessions accepted%0
//
#define APPERR2_4601                     ((DWORD)0x000011F9L)

//
// MessageId: APPERR2_4602
//
// MessageText:
//
// Sessions timed-out%0
//
#define APPERR2_4602                     ((DWORD)0x000011FAL)

//
// MessageId: APPERR2_4603
//
// MessageText:
//
// Sessions errored-out%0
//
#define APPERR2_4603                     ((DWORD)0x000011FBL)

//
// MessageId: APPERR2_4604
//
// MessageText:
//
// Kilobytes sent%0
//
#define APPERR2_4604                     ((DWORD)0x000011FCL)

//
// MessageId: APPERR2_4605
//
// MessageText:
//
// Kilobytes received%0
//
#define APPERR2_4605                     ((DWORD)0x000011FDL)

//
// MessageId: APPERR2_4606
//
// MessageText:
//
// Mean response time (msec)%0
//
#define APPERR2_4606                     ((DWORD)0x000011FEL)

//
// MessageId: APPERR2_4607
//
// MessageText:
//
// Network errors%0
//
#define APPERR2_4607                     ((DWORD)0x000011FFL)

//
// MessageId: APPERR2_4608
//
// MessageText:
//
// Files accessed%0
//
#define APPERR2_4608                     ((DWORD)0x00001200L)

//
// MessageId: APPERR2_4609
//
// MessageText:
//
// Print jobs spooled%0
//
#define APPERR2_4609                     ((DWORD)0x00001201L)

//
// MessageId: APPERR2_4610
//
// MessageText:
//
// System errors%0
//
#define APPERR2_4610                     ((DWORD)0x00001202L)

//
// MessageId: APPERR2_4611
//
// MessageText:
//
// Password violations%0
//
#define APPERR2_4611                     ((DWORD)0x00001203L)

//
// MessageId: APPERR2_4612
//
// MessageText:
//
// Permission violations%0
//
#define APPERR2_4612                     ((DWORD)0x00001204L)

//
// MessageId: APPERR2_4613
//
// MessageText:
//
// Communication devices accessed%0
//
#define APPERR2_4613                     ((DWORD)0x00001205L)

//
// MessageId: APPERR2_4614
//
// MessageText:
//
// Sessions started%0
//
#define APPERR2_4614                     ((DWORD)0x00001206L)

//
// MessageId: APPERR2_4615
//
// MessageText:
//
// Sessions reconnected%0
//
#define APPERR2_4615                     ((DWORD)0x00001207L)

//
// MessageId: APPERR2_4616
//
// MessageText:
//
// Sessions starts failed%0
//
#define APPERR2_4616                     ((DWORD)0x00001208L)

//
// MessageId: APPERR2_4617
//
// MessageText:
//
// Sessions disconnected%0
//
#define APPERR2_4617                     ((DWORD)0x00001209L)

//
// MessageId: APPERR2_4618
//
// MessageText:
//
// Network I/O's performed%0
//
#define APPERR2_4618                     ((DWORD)0x0000120AL)

//
// MessageId: APPERR2_4619
//
// MessageText:
//
// Files and pipes accessed%0
//
#define APPERR2_4619                     ((DWORD)0x0000120BL)

//
// MessageId: APPERR2_4620
//
// MessageText:
//
// Times buffers exhausted
//
#define APPERR2_4620                     ((DWORD)0x0000120CL)

//
// MessageId: APPERR2_4621
//
// MessageText:
//
// Big buffers%0
//
#define APPERR2_4621                     ((DWORD)0x0000120DL)

//
// MessageId: APPERR2_4622
//
// MessageText:
//
// Request buffers%0
//
#define APPERR2_4622                     ((DWORD)0x0000120EL)

//
// MessageId: APPERR2_4623
//
// MessageText:
//
// Workstation Statistics for \\%1
//
#define APPERR2_4623                     ((DWORD)0x0000120FL)

//
// MessageId: APPERR2_4624
//
// MessageText:
//
// Server Statistics for \\%1
//
#define APPERR2_4624                     ((DWORD)0x00001210L)

//
// MessageId: APPERR2_4625
//
// MessageText:
//
// Statistics since %1
//
#define APPERR2_4625                     ((DWORD)0x00001211L)

//
// MessageId: APPERR2_4626
//
// MessageText:
//
// Connections made%0
//
#define APPERR2_4626                     ((DWORD)0x00001212L)

//
// MessageId: APPERR2_4627
//
// MessageText:
//
// Connections failed%0
//
#define APPERR2_4627                     ((DWORD)0x00001213L)

//
// MessageId: APPERR2_4630
//
// MessageText:
//
// Bytes received%0
//
#define APPERR2_4630                     ((DWORD)0x00001216L)

//
// MessageId: APPERR2_4631
//
// MessageText:
//
// Server Message Blocks (SMBs) received%0
//
#define APPERR2_4631                     ((DWORD)0x00001217L)

//
// MessageId: APPERR2_4632
//
// MessageText:
//
// Bytes transmitted%0
//
#define APPERR2_4632                     ((DWORD)0x00001218L)

//
// MessageId: APPERR2_4633
//
// MessageText:
//
// Server Message Blocks (SMBs) transmitted%0
//
#define APPERR2_4633                     ((DWORD)0x00001219L)

//
// MessageId: APPERR2_4634
//
// MessageText:
//
// Read operations%0
//
#define APPERR2_4634                     ((DWORD)0x0000121AL)

//
// MessageId: APPERR2_4635
//
// MessageText:
//
// Write operations%0
//
#define APPERR2_4635                     ((DWORD)0x0000121BL)

//
// MessageId: APPERR2_4636
//
// MessageText:
//
// Raw reads denied%0
//
#define APPERR2_4636                     ((DWORD)0x0000121CL)

//
// MessageId: APPERR2_4637
//
// MessageText:
//
// Raw writes denied%0
//
#define APPERR2_4637                     ((DWORD)0x0000121DL)

//
// MessageId: APPERR2_4638
//
// MessageText:
//
// Network errors%0
//
#define APPERR2_4638                     ((DWORD)0x0000121EL)

//
// MessageId: APPERR2_4639
//
// MessageText:
//
// Connections made%0
//
#define APPERR2_4639                     ((DWORD)0x0000121FL)

//
// MessageId: APPERR2_4640
//
// MessageText:
//
// Reconnections made%0
//
#define APPERR2_4640                     ((DWORD)0x00001220L)

//
// MessageId: APPERR2_4641
//
// MessageText:
//
// Server disconnects%0
//
#define APPERR2_4641                     ((DWORD)0x00001221L)

//
// MessageId: APPERR2_4642
//
// MessageText:
//
// Sessions started%0
//
#define APPERR2_4642                     ((DWORD)0x00001222L)

//
// MessageId: APPERR2_4643
//
// MessageText:
//
// Hung sessions%0
//
#define APPERR2_4643                     ((DWORD)0x00001223L)

//
// MessageId: APPERR2_4644
//
// MessageText:
//
// Failed sessions%0
//
#define APPERR2_4644                     ((DWORD)0x00001224L)

//
// MessageId: APPERR2_4645
//
// MessageText:
//
// Failed operations%0
//
#define APPERR2_4645                     ((DWORD)0x00001225L)

//
// MessageId: APPERR2_4646
//
// MessageText:
//
// Use count%0
//
#define APPERR2_4646                     ((DWORD)0x00001226L)

//
// MessageId: APPERR2_4647
//
// MessageText:
//
// Failed use count%0
//
#define APPERR2_4647                     ((DWORD)0x00001227L)

//
// MessageId: APPERR2_4650
//
// MessageText:
//
// %1 was deleted successfully.
//
#define APPERR2_4650                     ((DWORD)0x0000122AL)

//
// MessageId: APPERR2_4651
//
// MessageText:
//
// %1 was used successfully.
//
#define APPERR2_4651                     ((DWORD)0x0000122BL)

//
// MessageId: APPERR2_4652
//
// MessageText:
//
// The message was successfully sent to %1.
//
#define APPERR2_4652                     ((DWORD)0x0000122CL)

//
// MessageId: APPERR2_4653
//
// MessageText:
//
// The message name %1 was forwarded successfully.
//
#define APPERR2_4653                     ((DWORD)0x0000122DL)

//
// MessageId: APPERR2_4654
//
// MessageText:
//
// The message name %1 was added successfully.
//
#define APPERR2_4654                     ((DWORD)0x0000122EL)

//
// MessageId: APPERR2_4655
//
// MessageText:
//
// The message name forwarding was successfully canceled.
//
#define APPERR2_4655                     ((DWORD)0x0000122FL)

//
// MessageId: APPERR2_4656
//
// MessageText:
//
// %1 was shared successfully.
//
#define APPERR2_4656                     ((DWORD)0x00001230L)

//
// MessageId: APPERR2_4657
//
// MessageText:
//
// The server %1 successfully logged you on as %2.
//
#define APPERR2_4657                     ((DWORD)0x00001231L)

//
// MessageId: APPERR2_4658
//
// MessageText:
//
// %1 was logged off successfully.
//
#define APPERR2_4658                     ((DWORD)0x00001232L)

//
// MessageId: APPERR2_4659
//
// MessageText:
//
// %1 was successfully removed from the list of shares the Server creates\n
// on startup.
//
#define APPERR2_4659                     ((DWORD)0x00001233L)

//
// MessageId: APPERR2_4661
//
// MessageText:
//
// The password was changed successfully.
//
#define APPERR2_4661                     ((DWORD)0x00001235L)

//
// MessageId: APPERR2_4662
//
// MessageText:
//
// %1 file(s) copied.
//
#define APPERR2_4662                     ((DWORD)0x00001236L)

//
// MessageId: APPERR2_4663
//
// MessageText:
//
// %1 file(s) moved.
//
#define APPERR2_4663                     ((DWORD)0x00001237L)

//
// MessageId: APPERR2_4664
//
// MessageText:
//
// The message was successfully sent to all users of the network.
//
#define APPERR2_4664                     ((DWORD)0x00001238L)

//
// MessageId: APPERR2_4665
//
// MessageText:
//
// The message was successfully sent to domain %1.
//
#define APPERR2_4665                     ((DWORD)0x00001239L)

//
// MessageId: APPERR2_4666
//
// MessageText:
//
// The message was successfully sent to all users of this server.
//
#define APPERR2_4666                     ((DWORD)0x0000123AL)

//
// MessageId: APPERR2_4667
//
// MessageText:
//
// The message was successfully sent to group *%1.
//
#define APPERR2_4667                     ((DWORD)0x0000123BL)

//
// MessageId: APPERR2_4695
//
// MessageText:
//
// Microsoft LAN Manager Version %1
//
#define APPERR2_4695                     ((DWORD)0x00001257L)

//
// MessageId: APPERR2_4696
//
// MessageText:
//
// ReactOS Server
//
#define APPERR2_4696                     ((DWORD)0x00001258L)

//
// MessageId: APPERR2_4697
//
// MessageText:
//
// ReactOS Workstation
//
#define APPERR2_4697                     ((DWORD)0x00001259L)

//
// MessageId: APPERR2_4698
//
// MessageText:
//
// MS-DOS Enhanced Workstation
//
#define APPERR2_4698                     ((DWORD)0x0000125AL)

//
// MessageId: APPERR2_4699
//
// MessageText:
//
// Created at %1
//
#define APPERR2_4699                     ((DWORD)0x0000125BL)

//
// MessageId: APPERR2_4700
//
// MessageText:
//
// Server Name            Remark
//
#define APPERR2_4700                     ((DWORD)0x0000125CL)

//
// MessageId: APPERR2_4702
//
// MessageText:
//
// (UNC)%0
//
#define APPERR2_4702                     ((DWORD)0x0000125EL)

//
// MessageId: APPERR2_4703
//
// MessageText:
//
// ...%0
//
#define APPERR2_4703                     ((DWORD)0x0000125FL)

//
// MessageId: APPERR2_4704
//
// MessageText:
//
// Domain
//
#define APPERR2_4704                     ((DWORD)0x00001260L)

//
// MessageId: APPERR2_4705
//
// MessageText:
//
// Resources on %1
//
#define APPERR2_4705                     ((DWORD)0x00001261L)

//
// MessageId: APPERR2_4706
//
// MessageText:
//
// Invalid network provider.  Available networks are:
//
#define APPERR2_4706                     ((DWORD)0x00001262L)

//
// MessageId: APPERR2_4710
//
// MessageText:
//
// Disk%0
//
#define APPERR2_4710                     ((DWORD)0x00001266L)

//
// MessageId: APPERR2_4711
//
// MessageText:
//
// Print%0
//
#define APPERR2_4711                     ((DWORD)0x00001267L)

//
// MessageId: APPERR2_4712
//
// MessageText:
//
// Comm%0
//
#define APPERR2_4712                     ((DWORD)0x00001268L)

//
// MessageId: APPERR2_4713
//
// MessageText:
//
// IPC%0
//
#define APPERR2_4713                     ((DWORD)0x00001269L)

//
// MessageId: APPERR2_4714
//
// MessageText:
//
// Status       Local     Remote                    Network
//
#define APPERR2_4714                     ((DWORD)0x0000126AL)

//
// MessageId: APPERR2_4715
//
// MessageText:
//
// OK%0
//
#define APPERR2_4715                     ((DWORD)0x0000126BL)

//
// MessageId: APPERR2_4716
//
// MessageText:
//
// Dormant%0
//
#define APPERR2_4716                     ((DWORD)0x0000126CL)

//
// MessageId: APPERR2_4717
//
// MessageText:
//
// Paused%0
//
#define APPERR2_4717                     ((DWORD)0x0000126DL)

//
// MessageId: APPERR2_4718
//
// MessageText:
//
// Disconnected%0
//
#define APPERR2_4718                     ((DWORD)0x0000126EL)

//
// MessageId: APPERR2_4719
//
// MessageText:
//
// Error%0
//
#define APPERR2_4719                     ((DWORD)0x0000126FL)

//
// MessageId: APPERR2_4720
//
// MessageText:
//
// Connecting%0
//
#define APPERR2_4720                     ((DWORD)0x00001270L)

//
// MessageId: APPERR2_4721
//
// MessageText:
//
// Reconnecting%0
//
#define APPERR2_4721                     ((DWORD)0x00001271L)

//
// MessageId: APPERR2_4722
//
// MessageText:
//
// Status%0
//
#define APPERR2_4722                     ((DWORD)0x00001272L)

//
// MessageId: APPERR2_4723
//
// MessageText:
//
// Local name%0
//
#define APPERR2_4723                     ((DWORD)0x00001273L)

//
// MessageId: APPERR2_4724
//
// MessageText:
//
// Remote name%0
//
#define APPERR2_4724                     ((DWORD)0x00001274L)

//
// MessageId: APPERR2_4725
//
// MessageText:
//
// Resource type%0
//
#define APPERR2_4725                     ((DWORD)0x00001275L)

//
// MessageId: APPERR2_4726
//
// MessageText:
//
// # Opens%0
//
#define APPERR2_4726                     ((DWORD)0x00001276L)

//
// MessageId: APPERR2_4727
//
// MessageText:
//
// # Connections%0
//
#define APPERR2_4727                     ((DWORD)0x00001277L)

//
// MessageId: APPERR2_4728
//
// MessageText:
//
// Unavailable%0
//
#define APPERR2_4728                     ((DWORD)0x00001278L)

//
// MessageId: APPERR2_4730
//
// MessageText:
//
// Share name   Resource                        Remark
//
#define APPERR2_4730                     ((DWORD)0x0000127AL)

//
// MessageId: APPERR2_4731
//
// MessageText:
//
// Share name%0
//
#define APPERR2_4731                     ((DWORD)0x0000127BL)

//
// MessageId: APPERR2_4732
//
// MessageText:
//
// Resource%0
//
#define APPERR2_4732                     ((DWORD)0x0000127CL)

//
// MessageId: APPERR2_4733
//
// MessageText:
//
// Spooled%0
//
#define APPERR2_4733                     ((DWORD)0x0000127DL)

//
// MessageId: APPERR2_4734
//
// MessageText:
//
// Permission%0
//
#define APPERR2_4734                     ((DWORD)0x0000127EL)

//
// MessageId: APPERR2_4735
//
// MessageText:
//
// Maximum users%0
//
#define APPERR2_4735                     ((DWORD)0x0000127FL)

//
// MessageId: APPERR2_4736
//
// MessageText:
//
// No limit%0
//
#define APPERR2_4736                     ((DWORD)0x00001280L)

//
// MessageId: APPERR2_4737
//
// MessageText:
//
// Users%0
//
#define APPERR2_4737                     ((DWORD)0x00001281L)

//
// MessageId: APPERR2_4738
//
// MessageText:
//
// The share name entered may not be accessible from some MS-DOS workstations.\n
// Are you sure you want to use this share name? %1: %0
//
#define APPERR2_4738                     ((DWORD)0x00001282L)

//
// MessageId: APPERR2_4739
//
// MessageText:
//
// Caching%0
//
#define APPERR2_4739                     ((DWORD)0x00001283L)

//
// MessageId: APPERR2_4740
//
// MessageText:
//
// ID         Path                                    User name            # Locks
//
#define APPERR2_4740                     ((DWORD)0x00001284L)

//
// MessageId: APPERR2_4741
//
// MessageText:
//
// File ID%0
//
#define APPERR2_4741                     ((DWORD)0x00001285L)

//
// MessageId: APPERR2_4742
//
// MessageText:
//
// Locks%0
//
#define APPERR2_4742                     ((DWORD)0x00001286L)

//
// MessageId: APPERR2_4743
//
// MessageText:
//
// Permissions%0
//
#define APPERR2_4743                     ((DWORD)0x00001287L)

//
// MessageId: APPERR2_4744
//
// MessageText:
//
// Share name%0
//
#define APPERR2_4744                     ((DWORD)0x00001288L)

//
// MessageId: APPERR2_4745
//
// MessageText:
//
// Type%0
//
#define APPERR2_4745                     ((DWORD)0x00001289L)

//
// MessageId: APPERR2_4746
//
// MessageText:
//
// Used as%0
//
#define APPERR2_4746                     ((DWORD)0x0000128AL)

//
// MessageId: APPERR2_4747
//
// MessageText:
//
// Comment%0
//
#define APPERR2_4747                     ((DWORD)0x0000128BL)

//
// MessageId: APPERR2_4750
//
// MessageText:
//
// Computer               User name            Client Type       Opens Idle time
//
#define APPERR2_4750                     ((DWORD)0x0000128EL)

//
// MessageId: APPERR2_4751
//
// MessageText:
//
// Computer%0
//
#define APPERR2_4751                     ((DWORD)0x0000128FL)

//
// MessageId: APPERR2_4752
//
// MessageText:
//
// Sess time%0
//
#define APPERR2_4752                     ((DWORD)0x00001290L)

//
// MessageId: APPERR2_4753
//
// MessageText:
//
// Idle time%0
//
#define APPERR2_4753                     ((DWORD)0x00001291L)

//
// MessageId: APPERR2_4754
//
// MessageText:
//
// Share name     Type     # Opens
//
#define APPERR2_4754                     ((DWORD)0x00001292L)

//
// MessageId: APPERR2_4755
//
// MessageText:
//
// Client type%0
//
#define APPERR2_4755                     ((DWORD)0x00001293L)

//
// MessageId: APPERR2_4756
//
// MessageText:
//
// Guest logon%0
//
#define APPERR2_4756                     ((DWORD)0x00001294L)

//
// MessageId: APPERR2_4770
//
// MessageText:
//
// Manual caching of documents%0
//
#define APPERR2_4770                     ((DWORD)0x000012A2L)

//
// MessageId: APPERR2_4771
//
// MessageText:
//
// Automatic caching of documents%0
//
#define APPERR2_4771                     ((DWORD)0x000012A3L)

//
// MessageId: APPERR2_4772
//
// MessageText:
//
// Automatic caching of programs and documents%0
//
#define APPERR2_4772                     ((DWORD)0x000012A4L)

//
// MessageId: APPERR2_4773
//
// MessageText:
//
// Caching disabled%0
//
#define APPERR2_4773                     ((DWORD)0x000012A5L)

//
// MessageId: APPERR2_4774
//
// MessageText:
//
// Automatic%0
//
#define APPERR2_4774                     ((DWORD)0x000012A6L)

//
// MessageId: APPERR2_4775
//
// MessageText:
//
// Manual%0
//
#define APPERR2_4775                     ((DWORD)0x000012A7L)

//
// MessageId: APPERR2_4776
//
// MessageText:
//
// Documents%0
//
#define APPERR2_4776                     ((DWORD)0x000012A8L)

//
// MessageId: APPERR2_4777
//
// MessageText:
//
// Programs%0
//
#define APPERR2_4777                     ((DWORD)0x000012A9L)

//
// MessageId: APPERR2_4778
//
// MessageText:
//
// None%0
//
#define APPERR2_4778                     ((DWORD)0x000012AAL)

//
// MessageId: APPERR2_4800
//
// MessageText:
//
// Name%0
//
#define APPERR2_4800                     ((DWORD)0x000012C0L)

//
// MessageId: APPERR2_4801
//
// MessageText:
//
// Forwarded to%0
//
#define APPERR2_4801                     ((DWORD)0x000012C1L)

//
// MessageId: APPERR2_4802
//
// MessageText:
//
// Forwarded to you from%0
//
#define APPERR2_4802                     ((DWORD)0x000012C2L)

//
// MessageId: APPERR2_4803
//
// MessageText:
//
// Users of this server%0
//
#define APPERR2_4803                     ((DWORD)0x000012C3L)

//
// MessageId: APPERR2_4804
//
// MessageText:
//
// Net Send has been interrupted by a Ctrl+Break from the user.
//
#define APPERR2_4804                     ((DWORD)0x000012C4L)

//
// MessageId: APPERR2_4810
//
// MessageText:
//
// Name                         Job #      Size            Status
//
#define APPERR2_4810                     ((DWORD)0x000012CAL)

//
// MessageId: APPERR2_4811
//
// MessageText:
//
// jobs%0
//
#define APPERR2_4811                     ((DWORD)0x000012CBL)

//
// MessageId: APPERR2_4812
//
// MessageText:
//
// Print%0
//
#define APPERR2_4812                     ((DWORD)0x000012CCL)

//
// MessageId: APPERR2_4813
//
// MessageText:
//
// Name%0
//
#define APPERR2_4813                     ((DWORD)0x000012CDL)

//
// MessageId: APPERR2_4814
//
// MessageText:
//
// Job #%0
//
#define APPERR2_4814                     ((DWORD)0x000012CEL)

//
// MessageId: APPERR2_4815
//
// MessageText:
//
// Size%0
//
#define APPERR2_4815                     ((DWORD)0x000012CFL)

//
// MessageId: APPERR2_4816
//
// MessageText:
//
// Status%0
//
#define APPERR2_4816                     ((DWORD)0x000012D0L)

//
// MessageId: APPERR2_4817
//
// MessageText:
//
// Separator file%0
//
#define APPERR2_4817                     ((DWORD)0x000012D1L)

//
// MessageId: APPERR2_4818
//
// MessageText:
//
// Comment%0
//
#define APPERR2_4818                     ((DWORD)0x000012D2L)

//
// MessageId: APPERR2_4819
//
// MessageText:
//
// Priority%0
//
#define APPERR2_4819                     ((DWORD)0x000012D3L)

//
// MessageId: APPERR2_4820
//
// MessageText:
//
// Print after%0
//
#define APPERR2_4820                     ((DWORD)0x000012D4L)

//
// MessageId: APPERR2_4821
//
// MessageText:
//
// Print until%0
//
#define APPERR2_4821                     ((DWORD)0x000012D5L)

//
// MessageId: APPERR2_4822
//
// MessageText:
//
// Print processor%0
//
#define APPERR2_4822                     ((DWORD)0x000012D6L)

//
// MessageId: APPERR2_4823
//
// MessageText:
//
// Additional info%0
//
#define APPERR2_4823                     ((DWORD)0x000012D7L)

//
// MessageId: APPERR2_4824
//
// MessageText:
//
// Parameters%0
//
#define APPERR2_4824                     ((DWORD)0x000012D8L)

//
// MessageId: APPERR2_4825
//
// MessageText:
//
// Print Devices%0
//
#define APPERR2_4825                     ((DWORD)0x000012D9L)

//
// MessageId: APPERR2_4826
//
// MessageText:
//
// Printer Active%0
//
#define APPERR2_4826                     ((DWORD)0x000012DAL)

//
// MessageId: APPERR2_4827
//
// MessageText:
//
// Printer held%0
//
#define APPERR2_4827                     ((DWORD)0x000012DBL)

//
// MessageId: APPERR2_4828
//
// MessageText:
//
// Printer error%0
//
#define APPERR2_4828                     ((DWORD)0x000012DCL)

//
// MessageId: APPERR2_4829
//
// MessageText:
//
// Printer being deleted%0
//
#define APPERR2_4829                     ((DWORD)0x000012DDL)

//
// MessageId: APPERR2_4830
//
// MessageText:
//
// Printer status unknown%0
//
#define APPERR2_4830                     ((DWORD)0x000012DEL)

//
// MessageId: APPERR2_4840
//
// MessageText:
//
// Held until %1%0
//
#define APPERR2_4840                     ((DWORD)0x000012E8L)

//
// MessageId: APPERR2_4841
//
// MessageText:
//
// Job #%0
//
#define APPERR2_4841                     ((DWORD)0x000012E9L)

//
// MessageId: APPERR2_4842
//
// MessageText:
//
// Submitting user%0
//
#define APPERR2_4842                     ((DWORD)0x000012EAL)

//
// MessageId: APPERR2_4843
//
// MessageText:
//
// Notify%0
//
#define APPERR2_4843                     ((DWORD)0x000012EBL)

//
// MessageId: APPERR2_4844
//
// MessageText:
//
// Job data type%0
//
#define APPERR2_4844                     ((DWORD)0x000012ECL)

//
// MessageId: APPERR2_4845
//
// MessageText:
//
// Job parameters%0
//
#define APPERR2_4845                     ((DWORD)0x000012EDL)

//
// MessageId: APPERR2_4846
//
// MessageText:
//
// Waiting%0
//
#define APPERR2_4846                     ((DWORD)0x000012EEL)

//
// MessageId: APPERR2_4847
//
// MessageText:
//
// Held in queue%0
//
#define APPERR2_4847                     ((DWORD)0x000012EFL)

//
// MessageId: APPERR2_4848
//
// MessageText:
//
// Spooling%0
//
#define APPERR2_4848                     ((DWORD)0x000012F0L)

//
// MessageId: APPERR2_4849
//
// MessageText:
//
// Paused%0
//
#define APPERR2_4849                     ((DWORD)0x000012F1L)

//
// MessageId: APPERR2_4850
//
// MessageText:
//
// Offline%0
//
#define APPERR2_4850                     ((DWORD)0x000012F2L)

//
// MessageId: APPERR2_4851
//
// MessageText:
//
// Error%0
//
#define APPERR2_4851                     ((DWORD)0x000012F3L)

//
// MessageId: APPERR2_4852
//
// MessageText:
//
// Out of paper%0
//
#define APPERR2_4852                     ((DWORD)0x000012F4L)

//
// MessageId: APPERR2_4853
//
// MessageText:
//
// Intervention required%0
//
#define APPERR2_4853                     ((DWORD)0x000012F5L)

//
// MessageId: APPERR2_4854
//
// MessageText:
//
// Printing%0
//
#define APPERR2_4854                     ((DWORD)0x000012F6L)

//
// MessageId: APPERR2_4855
//
// MessageText:
//
// on %0
//
#define APPERR2_4855                     ((DWORD)0x000012F7L)

//
// MessageId: APPERR2_4856
//
// MessageText:
//
// Paused on %1%0
//
#define APPERR2_4856                     ((DWORD)0x000012F8L)

//
// MessageId: APPERR2_4857
//
// MessageText:
//
// Offline on %1%0
//
#define APPERR2_4857                     ((DWORD)0x000012F9L)

//
// MessageId: APPERR2_4858
//
// MessageText:
//
// Error on%1%0
//
#define APPERR2_4858                     ((DWORD)0x000012FAL)

//
// MessageId: APPERR2_4859
//
// MessageText:
//
// Out of Paper on %1%0
//
#define APPERR2_4859                     ((DWORD)0x000012FBL)

//
// MessageId: APPERR2_4860
//
// MessageText:
//
// Check printer on %1%0
//
#define APPERR2_4860                     ((DWORD)0x000012FCL)

//
// MessageId: APPERR2_4861
//
// MessageText:
//
// Printing on %1%0
//
#define APPERR2_4861                     ((DWORD)0x000012FDL)

//
// MessageId: APPERR2_4862
//
// MessageText:
//
// Driver%0
//
#define APPERR2_4862                     ((DWORD)0x000012FEL)

//
// MessageId: APPERR2_4930
//
// MessageText:
//
// User name              Type                 Date%0
//
#define APPERR2_4930                     ((DWORD)0x00001342L)

//
// MessageId: APPERR2_4931
//
// MessageText:
//
// Lockout%0
//
#define APPERR2_4931                     ((DWORD)0x00001343L)

//
// MessageId: APPERR2_4932
//
// MessageText:
//
// Service%0
//
#define APPERR2_4932                     ((DWORD)0x00001344L)

//
// MessageId: APPERR2_4933
//
// MessageText:
//
// Server%0
//
#define APPERR2_4933                     ((DWORD)0x00001345L)

//
// MessageId: APPERR2_4934
//
// MessageText:
//
// Server started%0
//
#define APPERR2_4934                     ((DWORD)0x00001346L)

//
// MessageId: APPERR2_4935
//
// MessageText:
//
// Server paused%0
//
#define APPERR2_4935                     ((DWORD)0x00001347L)

//
// MessageId: APPERR2_4936
//
// MessageText:
//
// Server continued%0
//
#define APPERR2_4936                     ((DWORD)0x00001348L)

//
// MessageId: APPERR2_4937
//
// MessageText:
//
// Server stopped%0
//
#define APPERR2_4937                     ((DWORD)0x00001349L)

//
// MessageId: APPERR2_4938
//
// MessageText:
//
// Session%0
//
#define APPERR2_4938                     ((DWORD)0x0000134AL)

//
// MessageId: APPERR2_4939
//
// MessageText:
//
// Logon Guest%0
//
#define APPERR2_4939                     ((DWORD)0x0000134BL)

//
// MessageId: APPERR2_4940
//
// MessageText:
//
// Logon User%0
//
#define APPERR2_4940                     ((DWORD)0x0000134CL)

//
// MessageId: APPERR2_4941
//
// MessageText:
//
// Logon Administrator%0
//
#define APPERR2_4941                     ((DWORD)0x0000134DL)

//
// MessageId: APPERR2_4942
//
// MessageText:
//
// Logoff normal%0
//
#define APPERR2_4942                     ((DWORD)0x0000134EL)

//
// MessageId: APPERR2_4943
//
// MessageText:
//
// Logon%0
//
#define APPERR2_4943                     ((DWORD)0x0000134FL)

//
// MessageId: APPERR2_4944
//
// MessageText:
//
// Logoff error%0
//
#define APPERR2_4944                     ((DWORD)0x00001350L)

//
// MessageId: APPERR2_4945
//
// MessageText:
//
// Logoff auto-disconnect%0
//
#define APPERR2_4945                     ((DWORD)0x00001351L)

//
// MessageId: APPERR2_4946
//
// MessageText:
//
// Logoff administrator-disconnect%0
//
#define APPERR2_4946                     ((DWORD)0x00001352L)

//
// MessageId: APPERR2_4947
//
// MessageText:
//
// Logoff forced by logon restrictions%0
//
#define APPERR2_4947                     ((DWORD)0x00001353L)

//
// MessageId: APPERR2_4948
//
// MessageText:
//
// Service%0
//
#define APPERR2_4948                     ((DWORD)0x00001354L)

//
// MessageId: APPERR2_4949
//
// MessageText:
//
// %1 Installed%0
//
#define APPERR2_4949                     ((DWORD)0x00001355L)

//
// MessageId: APPERR2_4950
//
// MessageText:
//
// %1 Install Pending%0
//
#define APPERR2_4950                     ((DWORD)0x00001356L)

//
// MessageId: APPERR2_4951
//
// MessageText:
//
// %1 Paused%0
//
#define APPERR2_4951                     ((DWORD)0x00001357L)

//
// MessageId: APPERR2_4952
//
// MessageText:
//
// %1 Pause Pending%0
//
#define APPERR2_4952                     ((DWORD)0x00001358L)

//
// MessageId: APPERR2_4953
//
// MessageText:
//
// %1 Continued%0
//
#define APPERR2_4953                     ((DWORD)0x00001359L)

//
// MessageId: APPERR2_4954
//
// MessageText:
//
// %1 Continue Pending%0
//
#define APPERR2_4954                     ((DWORD)0x0000135AL)

//
// MessageId: APPERR2_4955
//
// MessageText:
//
// %1 Stopped%0
//
#define APPERR2_4955                     ((DWORD)0x0000135BL)

//
// MessageId: APPERR2_4956
//
// MessageText:
//
// %1 Stop Pending%0
//
#define APPERR2_4956                     ((DWORD)0x0000135CL)

//
// MessageId: APPERR2_4957
//
// MessageText:
//
// Account%0
//
#define APPERR2_4957                     ((DWORD)0x0000135DL)

//
// MessageId: APPERR2_4958
//
// MessageText:
//
// User account %1 was modified.%0
//
#define APPERR2_4958                     ((DWORD)0x0000135EL)

//
// MessageId: APPERR2_4959
//
// MessageText:
//
// Group account %1 was modified.%0
//
#define APPERR2_4959                     ((DWORD)0x0000135FL)

//
// MessageId: APPERR2_4960
//
// MessageText:
//
// User account %1 was deleted%0
//
#define APPERR2_4960                     ((DWORD)0x00001360L)

//
// MessageId: APPERR2_4961
//
// MessageText:
//
// Group account %1 was deleted%0
//
#define APPERR2_4961                     ((DWORD)0x00001361L)

//
// MessageId: APPERR2_4962
//
// MessageText:
//
// User account %1 was added%0
//
#define APPERR2_4962                     ((DWORD)0x00001362L)

//
// MessageId: APPERR2_4963
//
// MessageText:
//
// Group account %1 was added%0
//
#define APPERR2_4963                     ((DWORD)0x00001363L)

//
// MessageId: APPERR2_4964
//
// MessageText:
//
// Account system settings were modified%0
//
#define APPERR2_4964                     ((DWORD)0x00001364L)

//
// MessageId: APPERR2_4965
//
// MessageText:
//
// Logon restriction%0
//
#define APPERR2_4965                     ((DWORD)0x00001365L)

//
// MessageId: APPERR2_4966
//
// MessageText:
//
// Limit exceeded:  UNKNOWN%0
//
#define APPERR2_4966                     ((DWORD)0x00001366L)

//
// MessageId: APPERR2_4967
//
// MessageText:
//
// Limit exceeded:  Logon hours%0
//
#define APPERR2_4967                     ((DWORD)0x00001367L)

//
// MessageId: APPERR2_4968
//
// MessageText:
//
// Limit exceeded:  Account expired%0
//
#define APPERR2_4968                     ((DWORD)0x00001368L)

//
// MessageId: APPERR2_4969
//
// MessageText:
//
// Limit exceeded:  Workstation ID invalid%0
//
#define APPERR2_4969                     ((DWORD)0x00001369L)

//
// MessageId: APPERR2_4970
//
// MessageText:
//
// Limit exceeded:  Account disabled%0
//
#define APPERR2_4970                     ((DWORD)0x0000136AL)

//
// MessageId: APPERR2_4971
//
// MessageText:
//
// Limit exceeded:  Account deleted%0
//
#define APPERR2_4971                     ((DWORD)0x0000136BL)

//
// MessageId: APPERR2_4972
//
// MessageText:
//
// Share%0
//
#define APPERR2_4972                     ((DWORD)0x0000136CL)

//
// MessageId: APPERR2_4973
//
// MessageText:
//
// Use %1%0
//
#define APPERR2_4973                     ((DWORD)0x0000136DL)

//
// MessageId: APPERR2_4974
//
// MessageText:
//
// Unuse %1%0
//
#define APPERR2_4974                     ((DWORD)0x0000136EL)

//
// MessageId: APPERR2_4975
//
// MessageText:
//
// User's session disconnected %1%0
//
#define APPERR2_4975                     ((DWORD)0x0000136FL)

//
// MessageId: APPERR2_4976
//
// MessageText:
//
// Administrator stopped sharing resource %1%0
//
#define APPERR2_4976                     ((DWORD)0x00001370L)

//
// MessageId: APPERR2_4977
//
// MessageText:
//
// User reached limit for %1%0
//
#define APPERR2_4977                     ((DWORD)0x00001371L)

//
// MessageId: APPERR2_4978
//
// MessageText:
//
// Bad password%0
//
#define APPERR2_4978                     ((DWORD)0x00001372L)

//
// MessageId: APPERR2_4979
//
// MessageText:
//
// Administrator privilege required%0
//
#define APPERR2_4979                     ((DWORD)0x00001373L)

//
// MessageId: APPERR2_4980
//
// MessageText:
//
// Access%0
//
#define APPERR2_4980                     ((DWORD)0x00001374L)

//
// MessageId: APPERR2_4981
//
// MessageText:
//
// %1 permissions added%0
//
#define APPERR2_4981                     ((DWORD)0x00001375L)

//
// MessageId: APPERR2_4982
//
// MessageText:
//
// %1 permissions modified%0
//
#define APPERR2_4982                     ((DWORD)0x00001376L)

//
// MessageId: APPERR2_4983
//
// MessageText:
//
// %1 permissions deleted%0
//
#define APPERR2_4983                     ((DWORD)0x00001377L)

//
// MessageId: APPERR2_4984
//
// MessageText:
//
// Access denied%0
//
#define APPERR2_4984                     ((DWORD)0x00001378L)

//
// MessageId: APPERR2_4985
//
// MessageText:
//
// Unknown%0
//
#define APPERR2_4985                     ((DWORD)0x00001379L)

//
// MessageId: APPERR2_4986
//
// MessageText:
//
// Other%0
//
#define APPERR2_4986                     ((DWORD)0x0000137AL)

//
// MessageId: APPERR2_4987
//
// MessageText:
//
// Duration:%0
//
#define APPERR2_4987                     ((DWORD)0x0000137BL)

//
// MessageId: APPERR2_4988
//
// MessageText:
//
// Duration: Not available%0
//
#define APPERR2_4988                     ((DWORD)0x0000137CL)

//
// MessageId: APPERR2_4989
//
// MessageText:
//
// Duration: Less than one second%0
//
#define APPERR2_4989                     ((DWORD)0x0000137DL)

//
// MessageId: APPERR2_4990
//
// MessageText:
//
// (none)%0
//
#define APPERR2_4990                     ((DWORD)0x0000137EL)

//
// MessageId: APPERR2_4991
//
// MessageText:
//
// Closed %1%0
//
#define APPERR2_4991                     ((DWORD)0x0000137FL)

//
// MessageId: APPERR2_4992
//
// MessageText:
//
// Closed %1 (disconnected)%0
//
#define APPERR2_4992                     ((DWORD)0x00001380L)

//
// MessageId: APPERR2_4993
//
// MessageText:
//
// Administrator closed %1%0
//
#define APPERR2_4993                     ((DWORD)0x00001381L)

//
// MessageId: APPERR2_4994
//
// MessageText:
//
// Access ended%0
//
#define APPERR2_4994                     ((DWORD)0x00001382L)

//
// MessageId: APPERR2_4995
//
// MessageText:
//
// Log on to network%0
//
#define APPERR2_4995                     ((DWORD)0x00001383L)

//
// MessageId: APPERR2_4996
//
// MessageText:
//
// Logon denied%0
//
#define APPERR2_4996                     ((DWORD)0x00001384L)

//
// MessageId: APPERR2_4997
//
// MessageText:
//
// Program             Message             Time%0
//
#define APPERR2_4997                     ((DWORD)0x00001385L)

//
// MessageId: APPERR2_4998
//
// MessageText:
//
// Account locked due to %1 bad passwords%0
//
#define APPERR2_4998                     ((DWORD)0x00001386L)

//
// MessageId: APPERR2_4999
//
// MessageText:
//
// Account unlocked by administrator%0
//
#define APPERR2_4999                     ((DWORD)0x00001387L)

//
// MessageId: APPERR2_5000
//
// MessageText:
//
// Log off network%0
//
#define APPERR2_5000                     ((DWORD)0x00001388L)

//
// MessageId: APPERR2_5009
//
// MessageText:
//
// 
//
#define APPERR2_5009                     ((DWORD)0x00001391L)

//
// MessageId: APPERR2_5010
//
// MessageText:
//
// Subj:   ** ADMINISTRATOR ALERT **
//
#define APPERR2_5010                     ((DWORD)0x00001392L)

//
// MessageId: APPERR2_5011
//
// MessageText:
//
// Subj:   ** PRINTING NOTIFICATION **
//
#define APPERR2_5011                     ((DWORD)0x00001393L)

//
// MessageId: APPERR2_5012
//
// MessageText:
//
// Subj:   ** USER NOTIFICATION **
//
#define APPERR2_5012                     ((DWORD)0x00001394L)

//
// MessageId: APPERR2_5013
//
// MessageText:
//
// From:   %1 at \\%2
//
#define APPERR2_5013                     ((DWORD)0x00001395L)

//
// MessageId: APPERR2_5014
//
// MessageText:
//
// Print job %1 has been canceled while printing on %2.
//
#define APPERR2_5014                     ((DWORD)0x00001396L)

//
// MessageId: APPERR2_5015
//
// MessageText:
//
// Print job %1 has been deleted and will not print.
//
#define APPERR2_5015                     ((DWORD)0x00001397L)

//
// MessageId: APPERR2_5016
//
// MessageText:
//
// Printing Complete\n\n
// %1 printed successfully on %2.
//
#define APPERR2_5016                     ((DWORD)0x00001398L)

//
// MessageId: APPERR2_5017
//
// MessageText:
//
// Print job %1 has not completed printing on %2.
//
#define APPERR2_5017                     ((DWORD)0x00001399L)

//
// MessageId: APPERR2_5018
//
// MessageText:
//
// Print job %1 has paused printing on %2.
//
#define APPERR2_5018                     ((DWORD)0x0000139AL)

//
// MessageId: APPERR2_5019
//
// MessageText:
//
// Print job %1 is now printing on %2.
//
#define APPERR2_5019                     ((DWORD)0x0000139BL)

//
// MessageId: APPERR2_5020
//
// MessageText:
//
// The printer is out of paper.
//
#define APPERR2_5020                     ((DWORD)0x0000139CL)

//
// MessageId: APPERR2_5021
//
// MessageText:
//
// The printer is offline.
//
#define APPERR2_5021                     ((DWORD)0x0000139DL)

//
// MessageId: APPERR2_5022
//
// MessageText:
//
// Printing errors occurred.
//
#define APPERR2_5022                     ((DWORD)0x0000139EL)

//
// MessageId: APPERR2_5023
//
// MessageText:
//
// There is a problem with the printer; please check it.
//
#define APPERR2_5023                     ((DWORD)0x0000139FL)

//
// MessageId: APPERR2_5024
//
// MessageText:
//
// Print job %1 is being held from printing.
//
#define APPERR2_5024                     ((DWORD)0x000013A0L)

//
// MessageId: APPERR2_5025
//
// MessageText:
//
// Print job %1 is queued for printing.
//
#define APPERR2_5025                     ((DWORD)0x000013A1L)

//
// MessageId: APPERR2_5026
//
// MessageText:
//
// Print job %1 is being spooled.
//
#define APPERR2_5026                     ((DWORD)0x000013A2L)

//
// MessageId: APPERR2_5027
//
// MessageText:
//
// Job was queued to %1 on %2
//
#define APPERR2_5027                     ((DWORD)0x000013A3L)

//
// MessageId: APPERR2_5028
//
// MessageText:
//
// Size of job is %1 bytes.
//
#define APPERR2_5028                     ((DWORD)0x000013A4L)

//
// MessageId: APPERR2_5030
//
// MessageText:
//
// To:     %1
//
#define APPERR2_5030                     ((DWORD)0x000013A6L)

//
// MessageId: APPERR2_5031
//
// MessageText:
//
// Date:   %1
//
#define APPERR2_5031                     ((DWORD)0x000013A7L)

//
// MessageId: APPERR2_5032
//
// MessageText:
//
// The error code is %1.\n
// There was an error retrieving the message. Make sure the file\n
// NET.MSG is available.
//
#define APPERR2_5032                     ((DWORD)0x000013A8L)

//
// MessageId: APPERR2_5033
//
// MessageText:
//
// Printing Failed\n\n
// \"%1\" failed to print on %2 on %3.\n\n
// For more help use the print troubleshooter.
//
#define APPERR2_5033                     ((DWORD)0x000013A9L)

//
// MessageId: APPERR2_5034
//
// MessageText:
//
// Printing Failed\n\n
// \"%1\" failed to print on %2 on %3.  The Printer is %4.\n\n
// For more help use the print troubleshooter.
//
#define APPERR2_5034                     ((DWORD)0x000013AAL)

//
// MessageId: APPERR2_5035
//
// MessageText:
//
// Printing Complete\n\n
// \"%1\" printed successfully on %2 on %3.
//
#define APPERR2_5035                     ((DWORD)0x000013ABL)

//
// MessageId: APPERR2_5041
//
// MessageText:
//
// January%0
//
#define APPERR2_5041                     ((DWORD)0x000013B1L)

//
// MessageId: APPERR2_5042
//
// MessageText:
//
// February%0
//
#define APPERR2_5042                     ((DWORD)0x000013B2L)

//
// MessageId: APPERR2_5043
//
// MessageText:
//
// March%0
//
#define APPERR2_5043                     ((DWORD)0x000013B3L)

//
// MessageId: APPERR2_5044
//
// MessageText:
//
// April%0
//
#define APPERR2_5044                     ((DWORD)0x000013B4L)

//
// MessageId: APPERR2_5045
//
// MessageText:
//
// May%0
//
#define APPERR2_5045                     ((DWORD)0x000013B5L)

//
// MessageId: APPERR2_5046
//
// MessageText:
//
// June%0
//
#define APPERR2_5046                     ((DWORD)0x000013B6L)

//
// MessageId: APPERR2_5047
//
// MessageText:
//
// July%0
//
#define APPERR2_5047                     ((DWORD)0x000013B7L)

//
// MessageId: APPERR2_5048
//
// MessageText:
//
// August%0
//
#define APPERR2_5048                     ((DWORD)0x000013B8L)

//
// MessageId: APPERR2_5049
//
// MessageText:
//
// September%0
//
#define APPERR2_5049                     ((DWORD)0x000013B9L)

//
// MessageId: APPERR2_5050
//
// MessageText:
//
// October%0
//
#define APPERR2_5050                     ((DWORD)0x000013BAL)

//
// MessageId: APPERR2_5051
//
// MessageText:
//
// November%0
//
#define APPERR2_5051                     ((DWORD)0x000013BBL)

//
// MessageId: APPERR2_5052
//
// MessageText:
//
// December%0
//
#define APPERR2_5052                     ((DWORD)0x000013BCL)

//
// MessageId: APPERR2_5053
//
// MessageText:
//
// Jan%0
//
#define APPERR2_5053                     ((DWORD)0x000013BDL)

//
// MessageId: APPERR2_5054
//
// MessageText:
//
// Feb%0
//
#define APPERR2_5054                     ((DWORD)0x000013BEL)

//
// MessageId: APPERR2_5055
//
// MessageText:
//
// Mar%0
//
#define APPERR2_5055                     ((DWORD)0x000013BFL)

//
// MessageId: APPERR2_5056
//
// MessageText:
//
// Apr%0
//
#define APPERR2_5056                     ((DWORD)0x000013C0L)

//
// MessageId: APPERR2_5057
//
// MessageText:
//
// May%0
//
#define APPERR2_5057                     ((DWORD)0x000013C1L)

//
// MessageId: APPERR2_5058
//
// MessageText:
//
// Jun%0
//
#define APPERR2_5058                     ((DWORD)0x000013C2L)

//
// MessageId: APPERR2_5059
//
// MessageText:
//
// Jul%0
//
#define APPERR2_5059                     ((DWORD)0x000013C3L)

//
// MessageId: APPERR2_5060
//
// MessageText:
//
// Aug%0
//
#define APPERR2_5060                     ((DWORD)0x000013C4L)

//
// MessageId: APPERR2_5061
//
// MessageText:
//
// Sep%0
//
#define APPERR2_5061                     ((DWORD)0x000013C5L)

//
// MessageId: APPERR2_5062
//
// MessageText:
//
// Oct%0
//
#define APPERR2_5062                     ((DWORD)0x000013C6L)

//
// MessageId: APPERR2_5063
//
// MessageText:
//
// Nov%0
//
#define APPERR2_5063                     ((DWORD)0x000013C7L)

//
// MessageId: APPERR2_5064
//
// MessageText:
//
// Dec%0
//
#define APPERR2_5064                     ((DWORD)0x000013C8L)

//
// MessageId: APPERR2_5065
//
// MessageText:
//
// D%0
//
#define APPERR2_5065                     ((DWORD)0x000013C9L)

//
// MessageId: APPERR2_506
//
// MessageText:
//
// H%0
//
#define APPERR2_506                      ((DWORD)0x000013CAL)

//
// MessageId: APPERR2_5067
//
// MessageText:
//
// M%0
//
#define APPERR2_5067                     ((DWORD)0x000013CBL)

//
// MessageId: APPERR2_5068
//
// MessageText:
//
// Sa%0
//
#define APPERR2_5068                     ((DWORD)0x000013CCL)

//
// MessageId: APPERR2_5070
//
// MessageText:
//
// PRIMARY%0.
//
#define APPERR2_5070                     ((DWORD)0x000013CEL)

//
// MessageId: APPERR2_5071
//
// MessageText:
//
// BACKUP%0.
//
#define APPERR2_5071                     ((DWORD)0x000013CFL)

//
// MessageId: APPERR2_5072
//
// MessageText:
//
// WORKSTATION%0.
//
#define APPERR2_5072                     ((DWORD)0x000013D0L)

//
// MessageId: APPERR2_5073
//
// MessageText:
//
// SERVER%0.
//
#define APPERR2_5073                     ((DWORD)0x000013D1L)

//
// MessageId: APPERR2_5080
//
// MessageText:
//
// System Default%0
//
#define APPERR2_5080                     ((DWORD)0x000013D8L)

//
// MessageId: APPERR2_5081
//
// MessageText:
//
// United States%0
//
#define APPERR2_5081                     ((DWORD)0x000013D9L)

//
// MessageId: APPERR2_5082
//
// MessageText:
//
// Canada (French)%0
//
#define APPERR2_5082                     ((DWORD)0x000013DAL)

//
// MessageId: APPERR2_5083
//
// MessageText:
//
// Latin America%0
//
#define APPERR2_5083                     ((DWORD)0x000013DBL)

//
// MessageId: APPERR2_5084
//
// MessageText:
//
// Netherlands%0
//
#define APPERR2_5084                     ((DWORD)0x000013DCL)

//
// MessageId: APPERR2_5085
//
// MessageText:
//
// Belgium%0
//
#define APPERR2_5085                     ((DWORD)0x000013DDL)

//
// MessageId: APPERR2_5086
//
// MessageText:
//
// France%0
//
#define APPERR2_5086                     ((DWORD)0x000013DEL)

//
// MessageId: APPERR2_5087
//
// MessageText:
//
// Italy%0
//
#define APPERR2_5087                     ((DWORD)0x000013DFL)

//
// MessageId: APPERR2_5088
//
// MessageText:
//
// Switzerland%0
//
#define APPERR2_5088                     ((DWORD)0x000013E0L)

//
// MessageId: APPERR2_5089
//
// MessageText:
//
// United Kingdom%0
//
#define APPERR2_5089                     ((DWORD)0x000013E1L)

//
// MessageId: APPERR2_5090
//
// MessageText:
//
// Spain%0
//
#define APPERR2_5090                     ((DWORD)0x000013E2L)

//
// MessageId: APPERR2_5091
//
// MessageText:
//
// Denmark%0
//
#define APPERR2_5091                     ((DWORD)0x000013E3L)

//
// MessageId: APPERR2_5092
//
// MessageText:
//
// Sweden%0
//
#define APPERR2_5092                     ((DWORD)0x000013E4L)

//
// MessageId: APPERR2_5093
//
// MessageText:
//
// Norway%0
//
#define APPERR2_5093                     ((DWORD)0x000013E5L)

//
// MessageId: APPERR2_5094
//
// MessageText:
//
// Germany%0
//
#define APPERR2_5094                     ((DWORD)0x000013E6L)

//
// MessageId: APPERR2_5095
//
// MessageText:
//
// Australia%0
//
#define APPERR2_5095                     ((DWORD)0x000013E7L)

//
// MessageId: APPERR2_5096
//
// MessageText:
//
// Japan%0
//
#define APPERR2_5096                     ((DWORD)0x000013E8L)

//
// MessageId: APPERR2_5097
//
// MessageText:
//
// Korea%0
//
#define APPERR2_5097                     ((DWORD)0x000013E9L)

//
// MessageId: APPERR2_5098
//
// MessageText:
//
// China (PRC)%0
//
#define APPERR2_5098                     ((DWORD)0x000013EAL)

//
// MessageId: APPERR2_5099
//
// MessageText:
//
// Taiwan%0
//
#define APPERR2_5099                     ((DWORD)0x000013EBL)

//
// MessageId: APPERR2_5100
//
// MessageText:
//
// Asia%0
//
#define APPERR2_5100                     ((DWORD)0x000013ECL)

//
// MessageId: APPERR2_5101
//
// MessageText:
//
// Portugal%0
//
#define APPERR2_5101                     ((DWORD)0x000013EDL)

//
// MessageId: APPERR2_5102
//
// MessageText:
//
// Finland%0
//
#define APPERR2_5102                     ((DWORD)0x000013EEL)

//
// MessageId: APPERR2_5103
//
// MessageText:
//
// Arabic%0
//
#define APPERR2_5103                     ((DWORD)0x000013EFL)

//
// MessageId: APPERR2_5104
//
// MessageText:
//
// Hebrew%0
//
#define APPERR2_5104                     ((DWORD)0x000013F0L)

//
// MessageId: APPERR2_5150
//
// MessageText:
//
// A power failure has occurred at %1.  Please terminate all activity with this server.
//
#define APPERR2_5150                     ((DWORD)0x0000141EL)

//
// MessageId: APPERR2_5151
//
// MessageText:
//
// Power has been restored at %1.  Normal operations have resumed.
//
#define APPERR2_5151                     ((DWORD)0x0000141FL)

//
// MessageId: APPERR2_5152
//
// MessageText:
//
// The UPS service is starting shut down at %1.
//
#define APPERR2_5152                     ((DWORD)0x00001420L)

//
// MessageId: APPERR2_5153
//
// MessageText:
//
// The UPS service is about to perform final shut down.
//
#define APPERR2_5153                     ((DWORD)0x00001421L)

//
// MessageId: APPERR2_5170
//
// MessageText:
//
// The Workstation must be started with the NET START command.
//
#define APPERR2_5170                     ((DWORD)0x00001432L)

//
// MessageId: APPERR2_5175
//
// MessageText:
//
// Remote IPC%0
//
#define APPERR2_5175                     ((DWORD)0x00001437L)

//
// MessageId: APPERR2_5176
//
// MessageText:
//
// Remote Admin%0
//
#define APPERR2_5176                     ((DWORD)0x00001438L)

//
// MessageId: APPERR2_5177
//
// MessageText:
//
// Default share%0
//
#define APPERR2_5177                     ((DWORD)0x00001439L)

//
// MessageId: APPERR2_5280
//
// MessageText:
//
// The password entered is longer than 14 characters.  Computers\n
// with Windows prior to Windows 2000 will not be able to use\n
// this account. Do you want to continue this operation? %1: %0
//
#define APPERR2_5280                     ((DWORD)0x000014A0L)

//
// MessageId: APPERR2_5281
//
// MessageText:
//
// %1 has a remembered connection to %2. Do you\n
// want to overwrite the remembered connection? %3: %0
//
#define APPERR2_5281                     ((DWORD)0x000014A1L)

//
// MessageId: APPERR2_5282
//
// MessageText:
//
// Do you want to resume loading the profile?  The command which\n
// caused the error will be ignored. %1: %0
//
#define APPERR2_5282                     ((DWORD)0x000014A2L)

//
// MessageId: APPERR2_5284
//
// MessageText:
//
// Do you want to continue this operation? %1: %0
//
#define APPERR2_5284                     ((DWORD)0x000014A4L)

//
// MessageId: APPERR2_5285
//
// MessageText:
//
// Do you want to add this? %1: %0
//
#define APPERR2_5285                     ((DWORD)0x000014A5L)

//
// MessageId: APPERR2_5286
//
// MessageText:
//
// Do you want to continue this operation? %1: %0
//
#define APPERR2_5286                     ((DWORD)0x000014A6L)

//
// MessageId: APPERR2_5287
//
// MessageText:
//
// Is it OK to start it? %1: %0
//
#define APPERR2_5287                     ((DWORD)0x000014A7L)

//
// MessageId: APPERR2_5288
//
// MessageText:
//
// Do you want to start the Workstation service? %1: %0
//
#define APPERR2_5288                     ((DWORD)0x000014A8L)

//
// MessageId: APPERR2_5289
//
// MessageText:
//
// Is it OK to continue disconnecting and force them closed? %1: %0
//
#define APPERR2_5289                     ((DWORD)0x000014A9L)

//
// MessageId: APPERR2_5290
//
// MessageText:
//
// The printer does not exist.  Do you want to create it? %1: %0
//
#define APPERR2_5290                     ((DWORD)0x000014AAL)

//
// MessageId: APPERR2_5291
//
// MessageText:
//
// Never%0
//
#define APPERR2_5291                     ((DWORD)0x000014ABL)

//
// MessageId: APPERR2_5292
//
// MessageText:
//
// Never%0
//
#define APPERR2_5292                     ((DWORD)0x000014ACL)

//
// MessageId: APPERR2_5293
//
// MessageText:
//
// Never%0
//
#define APPERR2_5293                     ((DWORD)0x000014ADL)

//
// MessageId: APPERR2_5295
//
// MessageText:
//
// NET.HLP%0
//
#define APPERR2_5295                     ((DWORD)0x000014AFL)

//
// MessageId: APPERR2_5296
//
// MessageText:
//
// NET.HLP%0
//
#define APPERR2_5296                     ((DWORD)0x000014B0L)


 ncberr.h (non-public) message definitions (5300 - 5499 NRCERR_BASE)

//
// MessageId: NRCERR_5300
//
// MessageText:
//
// The network control block (NCB) request completed successfully.\n
// The NCB is the data.
//
#define NRCERR_5300                      ((DWORD)0x000014B4L)

//
// MessageId: NRCERR_5301
//
// MessageText:
//
// Illegal network control block (NCB) buffer length on SEND DATAGRAM,\n
// SEND BROADCAST, ADAPTER STATUS, or SESSION STATUS.\n
// The NCB is the data.
//
#define NRCERR_5301                      ((DWORD)0x000014B5L)

//
// MessageId: NRCERR_5302
//
// MessageText:
//
// The data descriptor array specified in the network control block (NCB) is\n
// invalid.  The NCB is the data.
//
#define NRCERR_5302                      ((DWORD)0x000014B6L)

//
// MessageId: NRCERR_5303
//
// MessageText:
//
// The command specified in the network control block (NCB) is illegal.\n
// The NCB is the data.
//
#define NRCERR_5303                      ((DWORD)0x000014B7L)

//
// MessageId: NRCERR_5304
//
// MessageText:
//
// The message correlator specified in the network control block (NCB) is\n
// invalid.  The NCB is the data.
//
#define NRCERR_5304                      ((DWORD)0x000014B8L)

//
// MessageId: NRCERR_5305
//
// MessageText:
//
// A network control block (NCB) command timed-out.  The session may have\n
// terminated abnormally.  The NCB is the data.
//
#define NRCERR_5305                      ((DWORD)0x000014B9L)

//
// MessageId: NRCERR_5306
//
// MessageText:
//
// An incomplete network control block (NCB) message was received.\n
// The NCB is the data.
//
#define NRCERR_5306                      ((DWORD)0x000014BAL)

//
// MessageId: NRCERR_5307
//
// MessageText:
//
// The buffer address specified in the network control block (NCB) is illegal.\n
// The NCB is the data.
//
#define NRCERR_5307                      ((DWORD)0x000014BBL)

//
// MessageId: NRCERR_5308
//
// MessageText:
//
// The session number specified in the network control block (NCB) is not active.\n
// The NCB is the data.
//
#define NRCERR_5308                      ((DWORD)0x000014BCL)

//
// MessageId: NRCERR_5309
//
// MessageText:
//
// No resource was available in the network adapter.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5309                      ((DWORD)0x000014BDL)

//
// MessageId: NRCERR_5310
//
// MessageText:
//
// The session specified in the network control block (NCB) was closed.\n
// The NCB is the data.
//
#define NRCERR_5310                      ((DWORD)0x000014BEL)

//
// MessageId: NRCERR_5311
//
// MessageText:
//
// The network control block (NCB) command was canceled.\n
// The NCB is the data.
//
#define NRCERR_5311                      ((DWORD)0x000014BFL)

//
// MessageId: NRCERR_5312
//
// MessageText:
//
// The message segment specified in the network control block (NCB) is\n
// illogical.  The NCB is the data.
//
#define NRCERR_5312                      ((DWORD)0x000014C0L)

//
// MessageId: NRCERR_5313
//
// MessageText:
//
// The name already exists in the local adapter name table.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5313                      ((DWORD)0x000014C1L)

//
// MessageId: NRCERR_5314
//
// MessageText:
//
// The network adapter name table is full.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5314                      ((DWORD)0x000014C2L)

//
// MessageId: NRCERR_5315
//
// MessageText:
//
// The network name has active sessions and is now de-registered.\n
// The network control block (NCB) command completed.  The NCB is the data.
//
#define NRCERR_5315                      ((DWORD)0x000014C3L)

//
// MessageId: NRCERR_5316
//
// MessageText:
//
// A previously issued Receive Lookahead command is active\n
// for this session.  The network control block (NCB) command was rejected.\n
// The NCB is the data.
//
#define NRCERR_5316                      ((DWORD)0x000014C4L)

//
// MessageId: NRCERR_5317
//
// MessageText:
//
// The local session table is full. The network control block (NCB) request was refused.\n
// The NCB is the data.
//
#define NRCERR_5317                      ((DWORD)0x000014C5L)

//
// MessageId: NRCERR_5318
//
// MessageText:
//
// A network control block (NCB) session open was rejected.  No LISTEN is outstanding\n
// on the remote computer.  The NCB is the data.
//
#define NRCERR_5318                      ((DWORD)0x000014C6L)

//
// MessageId: NRCERR_5319
//
// MessageText:
//
// The name number specified in the network control block (NCB) is illegal.\n
// The NCB is the data.
//
#define NRCERR_5319                      ((DWORD)0x000014C7L)

//
// MessageId: NRCERR_5320
//
// MessageText:
//
// The call name specified in the network control block (NCB) cannot be found or\n
// did not answer.  The NCB is the data.
//
#define NRCERR_5320                      ((DWORD)0x000014C8L)

//
// MessageId: NRCERR_5321
//
// MessageText:
//
// The name specified in the network control block (NCB) was not found.  Cannot put '*' or\n
// 00h in the NCB name.  The NCB is the data.
//
#define NRCERR_5321                      ((DWORD)0x000014C9L)

//
// MessageId: NRCERR_5322
//
// MessageText:
//
// The name specified in the network control block (NCB) is in use on a remote adapter.\n
// The NCB is the data.
//
#define NRCERR_5322                      ((DWORD)0x000014CAL)

//
// MessageId: NRCERR_5323
//
// MessageText:
//
// The name specified in the network control block (NCB) has been deleted.\n
// The NCB is the data.
//
#define NRCERR_5323                      ((DWORD)0x000014CBL)

//
// MessageId: NRCERR_5324
//
// MessageText:
//
// The session specified in the network control block (NCB) ended abnormally.\n
// The NCB is the data.
//
#define NRCERR_5324                      ((DWORD)0x000014CCL)

//
// MessageId: NRCERR_5325
//
// MessageText:
//
// The network protocol has detected two or more identical\n
// names on the network.\tThe network control block (NCB) is the data.
//
#define NRCERR_5325                      ((DWORD)0x000014CDL)

//
// MessageId: NRCERR_5326
//
// MessageText:
//
// An unexpected protocol packet was received.  There may be an\n
// incompatible remote device.  The network control block (NCB) is the data.
//
#define NRCERR_5326                      ((DWORD)0x000014CEL)

//
// MessageId: NRCERR_5333
//
// MessageText:
//
// The NetBIOS interface is busy.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5333                      ((DWORD)0x000014D5L)

//
// MessageId: NRCERR_5334
//
// MessageText:
//
// There are too many network control block (NCB) commands outstanding.\n
// The NCB request was refused.  The NCB is the data.
//
#define NRCERR_5334                      ((DWORD)0x000014D6L)

//
// MessageId: NRCERR_5335
//
// MessageText:
//
// The adapter number specified in the network control block (NCB) is illegal.\n
// The NCB is the data.
//
#define NRCERR_5335                      ((DWORD)0x000014D7L)

//
// MessageId: NRCERR_5336
//
// MessageText:
//
// The network control block (NCB) command completed while a cancel was occurring.\n
// The NCB is the data.
//
#define NRCERR_5336                      ((DWORD)0x000014D8L)

//
// MessageId: NRCERR_5337
//
// MessageText:
//
// The name specified in the network control block (NCB) is reserved.\n
// The NCB is the data.
//
#define NRCERR_5337                      ((DWORD)0x000014D9L)

//
// MessageId: NRCERR_5338
//
// MessageText:
//
// The network control block (NCB) command is not valid to cancel.\n
// The NCB is the data.
//
#define NRCERR_5338                      ((DWORD)0x000014DAL)

//
// MessageId: NRCERR_5351
//
// MessageText:
//
// There are multiple network control block (NCB) requests for the same session.\n
// The NCB request was refused.  The NCB is the data.
//
#define NRCERR_5351                      ((DWORD)0x000014E7L)

//
// MessageId: NRCERR_5352
//
// MessageText:
//
// There has been a network adapter error. The only NetBIOS\n
// command that may be issued is an NCB RESET. The network control block (NCB) is\n
// the data.
//
#define NRCERR_5352                      ((DWORD)0x000014E8L)

//
// MessageId: NRCERR_5354
//
// MessageText:
//
// The maximum number of applications was exceeded.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5354                      ((DWORD)0x000014EAL)

//
// MessageId: NRCERR_5356
//
// MessageText:
//
// The requested resources are not available.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5356                      ((DWORD)0x000014ECL)

//
// MessageId: NRCERR_5364
//
// MessageText:
//
// A system error has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5364                      ((DWORD)0x000014F4L)

//
// MessageId: NRCERR_5365
//
// MessageText:
//
// A ROM checksum failure has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5365                      ((DWORD)0x000014F5L)

//
// MessageId: NRCERR_5366
//
// MessageText:
//
// A RAM test failure has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5366                      ((DWORD)0x000014F6L)

//
// MessageId: NRCERR_5367
//
// MessageText:
//
// A digital loopback failure has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5367                      ((DWORD)0x000014F7L)

//
// MessageId: NRCERR_5368
//
// MessageText:
//
// An analog loopback failure has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5368                      ((DWORD)0x000014F8L)

//
// MessageId: NRCERR_5369
//
// MessageText:
//
// An interface failure has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5369                      ((DWORD)0x000014F9L)

//
// MessageId: NRCERR_5370
//
// MessageText:
//
// An unrecognized network control block (NCB) return code was received.\n
// The NCB is the data.
//
#define NRCERR_5370                      ((DWORD)0x000014FAL)

//
// MessageId: NRCERR_5380
//
// MessageText:
//
// A network adapter malfunction has occurred.\n
// The network control block (NCB) request was refused.  The NCB is the data.
//
#define NRCERR_5380                      ((DWORD)0x00001504L)

//
// MessageId: NRCERR_5381
//
// MessageText:
//
// The network control block (NCB) command is still pending.\n
// The NCB is the data.
//
#define NRCERR_5381                      ((DWORD)0x00001505L)


 alertmsg.h (non-public) message definitions (5500 - 5549 ALERT2_BASE)

//
// MessageId: ALERT2_5500
//
// MessageText:
//
// The update log on %1 is over 80%% capacity. The primary\n
// domain controller %2 is not retrieving the updates.
//
#define ALERT2_5500                      ((DWORD)0x0000157CL)

//
// MessageId: ALERT2_5501
//
// MessageText:
//
// The update log on %1 is full, and no further updates\n
// can be added until the primary domain controller %2\n
// retrieves the updates.
//
#define ALERT2_5501                      ((DWORD)0x0000157DL)

//
// MessageId: ALERT2_5502
//
// MessageText:
//
// The time difference with the primary domain controller %1\n
// exceeds the maximum allowed skew of %2 seconds.
//
#define ALERT2_5502                      ((DWORD)0x0000157EL)

//
// MessageId: ALERT2_5503
//
// MessageText:
//
// The account of user %1 has been locked out on %2\n
// due to %3 bad password attempts.
//
#define ALERT2_5503                      ((DWORD)0x0000157FL)

//
// MessageId: ALERT2_5504
//
// MessageText:
//
// The %1 log file cannot be opened.
//
#define ALERT2_5504                      ((DWORD)0x00001580L)

//
// MessageId: ALERT2_5505
//
// MessageText:
//
// The %1 log file is corrupted and will be cleared.
//
#define ALERT2_5505                      ((DWORD)0x00001581L)

//
// MessageId: ALERT2_5506
//
// MessageText:
//
// The Application log file could not be opened.  %1 will be used as the\n
// default log file.
//
#define ALERT2_5506                      ((DWORD)0x00001582L)

//
// MessageId: ALERT2_5507
//
// MessageText:
//
// The %1 Log is full.  If this is the first time you have seen this\n
// message, take the following steps:%n\n
// 1. Click Start, click Run, type \"eventvwr\", and then click OK.%n\n
// 2. Click %1, click the Action menu, click Clear All Events, and then click No.\n%n\n
// If this dialog reappears, contact your helpdesk or system administrator.
//
#define ALERT2_5507                      ((DWORD)0x00001583L)

//
// MessageId: ALERT2_5508
//
// MessageText:
//
// The security database full synchronization has been initiated by the server %1.
//
#define ALERT2_5508                      ((DWORD)0x00001584L)

//
// MessageId: ALERT2_5509
//
// MessageText:
//
// The operating system could not be started as configured.\n
// A previous working configuration was used instead.
//
#define ALERT2_5509                      ((DWORD)0x00001585L)

//
// MessageId: ALERT2_5510
//
// MessageText:
//
// The exception 0x%1 occurred in the application %2 at location 0x%3.
//
#define ALERT2_5510                      ((DWORD)0x00001586L)

//
// MessageId: ALERT2_5511
//
// MessageText:
//
// The servers %1 and  %3 both claim to be an NT Domain Controller for\n
// the %2 domain. One of the servers should be removed from the\n
// domain because the servers have different security identifiers\n
// (SID).
//
#define ALERT2_5511                      ((DWORD)0x00001587L)

//
// MessageId: ALERT2_5512
//
// MessageText:
//
// The server %1 and %2 both claim to be the primary domain\n
// controller for the %3 domain. One of the servers should be\n
// demoted or removed from the domain.
//
#define ALERT2_5512                      ((DWORD)0x00001588L)

//
// MessageId: ALERT2_5513
//
// MessageText:
//
// The computer %1 tried to connect to the server %2 using\n
// the trust relationship established by the %3 domain. However, the\n
// computer lost the correct security identifier (SID)\n
// when the domain was reconfigured. Reestablish the trust\n
// relationship.
//
#define ALERT2_5513                      ((DWORD)0x00001589L)

//
// MessageId: ALERT2_5514
//
// MessageText:
//
// The computer has rebooted from a bugcheck.  The bugcheck was:\n
// %1.\n
// %2\n
// A full dump was not saved.
//
#define ALERT2_5514                      ((DWORD)0x0000158AL)

//
// MessageId: ALERT2_5515
//
// MessageText:
//
// The computer has rebooted from a bugcheck.  The bugcheck was:\n
// %1.\n
// %2\n
// A dump was saved in: %3.
//
#define ALERT2_5515                      ((DWORD)0x0000158BL)

//
// MessageId: ALERT2_5516
//
// MessageText:
//
// The computer or domain %1 trusts domain %2.  (This may be an indirect\n
// trust.)  However, %1 and %2 have the same machine security identifier\n
// (SID).  The operating system should be re-installed on either %1 or %2.
//
#define ALERT2_5516                      ((DWORD)0x0000158CL)

//
// MessageId: ALERT2_5517
//
// MessageText:
//
// The computer or domain %1 trusts domain %2.  (This may be an indirect\n
// trust.)  However, %2 is not a valid name for a trusted domain.\n
// The name of the trusted domain should be changed to a valid name.
//
#define ALERT2_5517                      ((DWORD)0x0000158DL)


 lmsvc.h message definitions (5600 - 5699 SERVICE2_BASE)

//
// MessageId: SERVICE_UIC_M_NETLOGON_MPATH
//
// MessageText:
//
// Could not share the User or Script path.
//
#define SERVICE_UIC_M_NETLOGON_MPATH     ((DWORD)0x000015E0L)

//
// MessageId: SERVICE_UIC_M_LSA_MACHINE_ACCT
//
// MessageText:
//
// The password for this computer is not found in the local security\ndatabase.
//
#define SERVICE_UIC_M_LSA_MACHINE_ACCT   ((DWORD)0x000015E1L)

//
// MessageId: SERVICE_UIC_M_DATABASE_ERROR
//
// MessageText:
//
// An internal error occurred while accessing the computer's\nlocal or network security database.
//
#define SERVICE_UIC_M_DATABASE_ERROR     ((DWORD)0x000015E2L)


 lmerrlog.h messages definitions (5700 - 5899 ERRLOG2_BASE)

//
// MessageId: NELOG_NetlogonSSIInitError
//
// MessageText:
//
// The Netlogon service could not initialize the replication data\n
// structures successfully. The service was terminated.  The following\n
// error occurred: %n%1
//
#define NELOG_NetlogonSSIInitError       ((DWORD)0x00001644L)

//
// MessageId: NELOG_NetlogonFailedToUpdateTrustList
//
// MessageText:
//
// The Netlogon service failed to update the domain trust list.  The\n
// following error occurred: %n%1
//
#define NELOG_NetlogonFailedToUpdateTrustList ((DWORD)0x00001645L)

//
// MessageId: NELOG_NetlogonFailedToAddRpcInterface
//
// MessageText:
//
// The Netlogon service could not add the RPC interface.  The\n
// service was terminated. The following error occurred: %n%1
//
#define NELOG_NetlogonFailedToAddRpcInterface ((DWORD)0x00001646L)

//
// MessageId: NELOG_NetlogonFailedToReadMailslot
//
// MessageText:
//
// The Netlogon service could not read a mailslot message from %1 due\n
// to the following error: %n%2
//
#define NELOG_NetlogonFailedToReadMailslot ((DWORD)0x00001647L)

//
// MessageId: NELOG_NetlogonFailedToRegisterSC
//
// MessageText:
//
// The Netlogon service failed to register the service with the\n
// service controller. The service was terminated. The following\n
// error occurred: %n%1
//
#define NELOG_NetlogonFailedToRegisterSC ((DWORD)0x00001648L)

//
// MessageId: NELOG_NetlogonChangeLogCorrupt
//
// MessageText:
//
// The change log cache maintained by the Netlogon service for %1\n
// database changes is inconsistent. The Netlogon service is resetting\n
// the change log.
//
#define NELOG_NetlogonChangeLogCorrupt   ((DWORD)0x00001649L)

//
// MessageId: NELOG_NetlogonFailedToCreateShare
//
// MessageText:
//
// The Netlogon service could not create server share %1.  The following\n
// error occurred: %n%2
//
#define NELOG_NetlogonFailedToCreateShare ((DWORD)0x0000164AL)

//
// MessageId: NELOG_NetlogonDownLevelLogonFailed
//
// MessageText:
//
// The down-level logon request for the user %1 from %2 failed.
//
#define NELOG_NetlogonDownLevelLogonFailed ((DWORD)0x0000164BL)

//
// MessageId: NELOG_NetlogonDownLevelLogoffFailed
//
// MessageText:
//
// The down-level logoff request for the user %1 from %2 failed.
//
#define NELOG_NetlogonDownLevelLogoffFailed ((DWORD)0x0000164CL)

//
// MessageId: NELOG_NetlogonNTLogonFailed
//
// MessageText:
//
// The Windows NT or Windows 2000 %1 logon request for the user %2\\%3 from %4 (via %5)\n
// failed.
//
#define NELOG_NetlogonNTLogonFailed      ((DWORD)0x0000164DL)

//
// MessageId: NELOG_NetlogonNTLogoffFailed
//
// MessageText:
//
// The Windows NT or Windows 2000 %1 logoff request for the user %2\\%3 from %4\n
// failed.
//
#define NELOG_NetlogonNTLogoffFailed     ((DWORD)0x0000164EL)

//
// MessageId: NELOG_NetlogonPartialSyncCallSuccess
//
// MessageText:
//
// The partial synchronization request from the server %1 completed\n
// successfully. %2 changes(s) has(have) been returned to the\n
// caller.
//
#define NELOG_NetlogonPartialSyncCallSuccess ((DWORD)0x0000164FL)

//
// MessageId: NELOG_NetlogonPartialSyncCallFailed
//
// MessageText:
//
// The partial synchronization request from the server %1 failed with\n
// the following error: %n%2
//
#define NELOG_NetlogonPartialSyncCallFailed ((DWORD)0x00001650L)

//
// MessageId: NELOG_NetlogonFullSyncCallSuccess
//
// MessageText:
//
// The full synchronization request from the server %1 completed\n
// successfully. %2 object(s) has(have) been returned to\n
// the caller.
//
#define NELOG_NetlogonFullSyncCallSuccess ((DWORD)0x00001651L)

//
// MessageId: NELOG_NetlogonFullSyncCallFailed
//
// MessageText:
//
// The full synchronization request from the server %1 failed with\n
// the following error: %n%2
//
#define NELOG_NetlogonFullSyncCallFailed ((DWORD)0x00001652L)

//
// MessageId: NELOG_NetlogonPartialSyncSuccess
//
// MessageText:
//
// The partial synchronization replication of the %1 database from the\n
// primary domain controller %2 completed successfully. %3 change(s) is(are)\n
// applied to the database.
//
#define NELOG_NetlogonPartialSyncSuccess ((DWORD)0x00001653L)

//
// MessageId: NELOG_NetlogonPartialSyncFailed
//
// MessageText:
//
// The partial synchronization replication of the %1 database from the\n
// primary domain controller %2 failed with the following error: %n%3
//
#define NELOG_NetlogonPartialSyncFailed  ((DWORD)0x00001654L)

//
// MessageId: NELOG_NetlogonFullSyncSuccess
//
// MessageText:
//
// The full synchronization replication of the %1 database from the\n
// primary domain controller %2 completed successfully.
//
#define NELOG_NetlogonFullSyncSuccess    ((DWORD)0x00001655L)

//
// MessageId: NELOG_NetlogonFullSyncFailed
//
// MessageText:
//
// The full synchronization replication of the %1 database from the\n
// primary domain controller %2 failed with the following error: %n%3
//
#define NELOG_NetlogonFullSyncFailed     ((DWORD)0x00001656L)

//
// MessageId: NELOG_NetlogonAuthNoDomainController
//
// MessageText:
//
// This computer was not able to set up a secure session with a domain\n
// controller in domain %1 due to the following: %n%2\n
// %nThis may lead to authentication problems. Make sure that this\n
// computer is connected to the network. If the problem persists,\n
// please contact your domain administrator.\n\n
// %n%nADDITIONAL INFO\n
// %nIf this computer is a domain controller for the specified domain, it\n
// sets up the secure session to the primary domain controller emulator in the specified\n
// domain. Otherwise, this computer sets up the secure session to any domain controller\n
// in the specified domain.
//
#define NELOG_NetlogonAuthNoDomainController ((DWORD)0x00001657L)

//
// MessageId: NELOG_NetlogonAuthNoTrustLsaSecret
//
// MessageText:
//
// The session setup to the Domain Controller %1 for the domain %2\n
// failed because the computer %3 does not have a local security database account.
//
#define NELOG_NetlogonAuthNoTrustLsaSecret ((DWORD)0x00001658L)

//
// MessageId: NELOG_NetlogonAuthNoTrustSamAccount
//
// MessageText:
//
// The session setup to the Domain Controller %1 for the domain %2\n
// failed because the Domain Controller did not have an account %4\n
// needed to set up the session by this computer %3.\n\n%n%nADDITIONAL DATA\n
// %nIf this computer is a member of or a Domain Controller in the specified domain, the\n
// aforementioned account is a computer account for this computer in the specified domain.\n
// Otherwise, the account is an interdomain trust account with the specified domain.
//
#define NELOG_NetlogonAuthNoTrustSamAccount ((DWORD)0x00001659L)

//
// MessageId: NELOG_NetlogonServerAuthFailed
//
// MessageText:
//
// The session setup from the computer %1 failed to authenticate.\n
// The name(s) of the account(s) referenced in the security database is\n
// %2.  The following error occurred: %n%3
//
#define NELOG_NetlogonServerAuthFailed   ((DWORD)0x0000165AL)

//
// MessageId: NELOG_NetlogonServerAuthNoTrustSamAccount
//
// MessageText:
//
// The session setup from computer '%1' failed because the security database\n
// does not contain a trust account '%2' referenced by the specified computer.\n\n
// %n%nUSER ACTION\n\n
// %nIf this is the first occurrence of this event for the specified computer\n
// and account, this may be a transient issue that doesn't require any action\n
// at this time. Otherwise, the following steps may be taken to resolve this problem:\n\n
// %n%nIf '%2' is a legitimate machine account for the computer '%1', then '%1'\n
// should be rejoined to the domain.\n\n
// %n%nIf '%2' is a legitimate interdomain trust account, then the trust should\n
// be recreated.\n\n
// %n%nOtherwise, assuming that '%2' is not a legitimate account, the following\n
// action should be taken on '%1':\n\n
// %n%nIf '%1' is a Domain Controller, then the trust associated with '%2' should be deleted.\n\n
// %n%nIf '%1' is not a Domain Controller, it should be disjoined from the domain.
//
#define NELOG_NetlogonServerAuthNoTrustSamAccount ((DWORD)0x0000165BL)

//
// MessageId: NELOG_FailedToRegisterSC
//
// MessageText:
//
// Could not register control handler with service controller %1.
//
#define NELOG_FailedToRegisterSC         ((DWORD)0x0000165CL)

//
// MessageId: NELOG_FailedToSetServiceStatus
//
// MessageText:
//
// Could not set service status with service controller %1.
//
#define NELOG_FailedToSetServiceStatus   ((DWORD)0x0000165DL)

//
// MessageId: NELOG_FailedToGetComputerName
//
// MessageText:
//
// Could not find the computer name %1.
//
#define NELOG_FailedToGetComputerName    ((DWORD)0x0000165EL)

//
// MessageId: NELOG_DriverNotLoaded
//
// MessageText:
//
// Could not load %1 device driver.
//
#define NELOG_DriverNotLoaded            ((DWORD)0x0000165FL)

//
// MessageId: NELOG_NoTranportLoaded
//
// MessageText:
//
// Could not load any transport.
//
#define NELOG_NoTranportLoaded           ((DWORD)0x00001660L)

//
// MessageId: NELOG_NetlogonFailedDomainDelta
//
// MessageText:
//
// Replication of the %1 Domain Object \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedDomainDelta  ((DWORD)0x00001661L)

//
// MessageId: NELOG_NetlogonFailedGlobalGroupDelta
//
// MessageText:
//
// Replication of the %1 Global Group \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedGlobalGroupDelta ((DWORD)0x00001662L)

//
// MessageId: NELOG_NetlogonFailedLocalGroupDelta
//
// MessageText:
//
// Replication of the %1 Local Group \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedLocalGroupDelta ((DWORD)0x00001663L)

//
// MessageId: NELOG_NetlogonFailedUserDelta
//
// MessageText:
//
// Replication of the %1 User \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedUserDelta    ((DWORD)0x00001664L)

//
// MessageId: NELOG_NetlogonFailedPolicyDelta
//
// MessageText:
//
// Replication of the %1 Policy Object \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedPolicyDelta  ((DWORD)0x00001665L)

//
// MessageId: NELOG_NetlogonFailedTrustedDomainDelta
//
// MessageText:
//
// Replication of the %1 Trusted Domain Object \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedTrustedDomainDelta ((DWORD)0x00001666L)

//
// MessageId: NELOG_NetlogonFailedAccountDelta
//
// MessageText:
//
// Replication of the %1 Account Object \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedAccountDelta ((DWORD)0x00001667L)

//
// MessageId: NELOG_NetlogonFailedSecretDelta
//
// MessageText:
//
// Replication of the %1 Secret \"%2\" from primary domain controller\n
// %3 failed with the following error: %n%4
//
#define NELOG_NetlogonFailedSecretDelta  ((DWORD)0x00001668L)

//
// MessageId: NELOG_NetlogonSystemError
//
// MessageText:
//
// The system returned the following unexpected error code: %n%1
//
#define NELOG_NetlogonSystemError        ((DWORD)0x00001669L)

//
// MessageId: NELOG_NetlogonDuplicateMachineAccounts
//
// MessageText:
//
// Netlogon has detected two machine accounts for server \"%1\".\n
// The server can be either a Windows 2000 Server that is a member of the\n
// domain or the server can be a LAN Manager server with an account in the\n
// SERVERS global group.  It cannot be both.
//
#define NELOG_NetlogonDuplicateMachineAccounts ((DWORD)0x0000166AL)

//
// MessageId: NELOG_NetlogonTooManyGlobalGroups
//
// MessageText:
//
// This domain has more global groups than can be replicated to a LanMan\n
// BDC.  Either delete some of your global groups or remove the LanMan\n
// BDCs from the domain.
//
#define NELOG_NetlogonTooManyGlobalGroups ((DWORD)0x0000166BL)

//
// MessageId: NELOG_NetlogonBrowserDriver
//
// MessageText:
//
// The Browser driver returned the following error to Netlogon: %n%1
//
#define NELOG_NetlogonBrowserDriver      ((DWORD)0x0000166CL)

//
// MessageId: NELOG_NetlogonAddNameFailure
//
// MessageText:
//
// Netlogon could not register the %1<1B> name for the following reason: %n%2
//
#define NELOG_NetlogonAddNameFailure     ((DWORD)0x0000166DL)

//
// MessageId: NELOG_RplMessages
//
// MessageText:
//
// Service failed to retrieve messages needed to boot remote boot clients.
//
#define NELOG_RplMessages                ((DWORD)0x0000166EL)

//
// MessageId: NELOG_RplXnsBoot
//
// MessageText:
//
// Service experienced a severe error and can no longer provide remote boot\n
// for 3Com 3Start remote boot clients.
//
#define NELOG_RplXnsBoot                 ((DWORD)0x0000166FL)

//
// MessageId: NELOG_RplSystem
//
// MessageText:
//
// Service experienced a severe system error and will shut itself down.
//
#define NELOG_RplSystem                  ((DWORD)0x00001670L)

//
// MessageId: NELOG_RplWkstaTimeout
//
// MessageText:
//
// Client with computer name %1 failed to acknowledge receipt of the\n
// boot data.  Remote boot of this client was not completed.
//
#define NELOG_RplWkstaTimeout            ((DWORD)0x00001671L)

//
// MessageId: NELOG_RplWkstaFileOpen
//
// MessageText:
//
// Client with computer name %1 was not booted due to an error in opening\n
// file %2.
//
#define NELOG_RplWkstaFileOpen           ((DWORD)0x00001672L)

//
// MessageId: NELOG_RplWkstaFileRead
//
// MessageText:
//
// Client with computer name %1 was not booted due to an error in reading\n
// file %2.
//
#define NELOG_RplWkstaFileRead           ((DWORD)0x00001673L)

//
// MessageId: NELOG_RplWkstaMemory
//
// MessageText:
//
// Client with computer name %1 was not booted due to insufficient memory\n
// at the remote boot server.
//
#define NELOG_RplWkstaMemory             ((DWORD)0x00001674L)

//
// MessageId: NELOG_RplWkstaFileChecksum
//
// MessageText:
//
// Client with computer name %1 will be booted without using checksums\n
// because checksum for file %2 could not be calculated.
//
#define NELOG_RplWkstaFileChecksum       ((DWORD)0x00001675L)

//
// MessageId: NELOG_RplWkstaFileLineCount
//
// MessageText:
//
// Client with computer name %1 was not booted due to too many lines in\n
// file %2.
//
#define NELOG_RplWkstaFileLineCount      ((DWORD)0x00001676L)

//
// MessageId: NELOG_RplWkstaBbcFile
//
// MessageText:
//
// Client with computer name %1 was not booted because the boot block\n
// configuration file %2 for this client does not contain boot block\n
// line and/or loader line.
//
#define NELOG_RplWkstaBbcFile            ((DWORD)0x00001677L)

//
// MessageId: NELOG_RplWkstaFileSize
//
// MessageText:
//
// Client with computer name %1 was not booted due to a bad size of\n
// file %2.
//
#define NELOG_RplWkstaFileSize           ((DWORD)0x00001678L)

//
// MessageId: NELOG_RplWkstaInternal
//
// MessageText:
//
// Client with computer name %1 was not booted due to remote boot\n
// service internal error.
//
#define NELOG_RplWkstaInternal           ((DWORD)0x00001679L)

//
// MessageId: NELOG_RplWkstaWrongVersion
//
// MessageText:
//
// Client with computer name %1 was not booted because file %2 has an\n
// invalid boot header.
//
#define NELOG_RplWkstaWrongVersion       ((DWORD)0x0000167AL)

//
// MessageId: NELOG_RplWkstaNetwork
//
// MessageText:
//
// Client with computer name %1 was not booted due to network error.
//
#define NELOG_RplWkstaNetwork            ((DWORD)0x0000167BL)

//
// MessageId: NELOG_RplAdapterResource
//
// MessageText:
//
// Client with adapter id %1 was not booted due to lack of resources.
//
#define NELOG_RplAdapterResource         ((DWORD)0x0000167CL)

//
// MessageId: NELOG_RplFileCopy
//
// MessageText:
//
// Service experienced error copying file or directory %1.
//
#define NELOG_RplFileCopy                ((DWORD)0x0000167DL)

//
// MessageId: NELOG_RplFileDelete
//
// MessageText:
//
// Service experienced error deleting file or directory %1.
//
#define NELOG_RplFileDelete              ((DWORD)0x0000167EL)

//
// MessageId: NELOG_RplFilePerms
//
// MessageText:
//
// Service experienced error setting permissions on file or directory %1.
//
#define NELOG_RplFilePerms               ((DWORD)0x0000167FL)

//
// MessageId: NELOG_RplCheckConfigs
//
// MessageText:
//
// Service experienced error evaluating RPL configurations.
//
#define NELOG_RplCheckConfigs            ((DWORD)0x00001680L)

//
// MessageId: NELOG_RplCreateProfiles
//
// MessageText:
//
// Service experienced error creating RPL profiles for all configurations.
//
#define NELOG_RplCreateProfiles          ((DWORD)0x00001681L)

//
// MessageId: NELOG_RplRegistry
//
// MessageText:
//
// Service experienced error accessing registry.
//
#define NELOG_RplRegistry                ((DWORD)0x00001682L)

//
// MessageId: NELOG_RplReplaceRPLDISK
//
// MessageText:
//
// Service experienced error replacing possibly outdated RPLDISK.SYS.
//
#define NELOG_RplReplaceRPLDISK          ((DWORD)0x00001683L)

//
// MessageId: NELOG_RplCheckSecurity
//
// MessageText:
//
// Service experienced error adding security accounts or setting\n
// file permissions.  These accounts are the RPLUSER local group\n
// and the user accounts for the individual RPL workstations.
//
#define NELOG_RplCheckSecurity           ((DWORD)0x00001684L)

//
// MessageId: NELOG_RplBackupDatabase
//
// MessageText:
//
// Service failed to back up its database.
//
#define NELOG_RplBackupDatabase          ((DWORD)0x00001685L)

//
// MessageId: NELOG_RplInitDatabase
//
// MessageText:
//
// Service failed to initialize from its database.  The database may be\n
// missing or corrupted.  Service will attempt restoring the database\n
// from the backup.
//
#define NELOG_RplInitDatabase            ((DWORD)0x00001686L)

//
// MessageId: NELOG_RplRestoreDatabaseFailure
//
// MessageText:
//
// Service failed to restore its database from the backup.  Service\n
// will not start.
//
#define NELOG_RplRestoreDatabaseFailure  ((DWORD)0x00001687L)

//
// MessageId: NELOG_RplRestoreDatabaseSuccess
//
// MessageText:
//
// Service successfully restored its database from the backup.
//
#define NELOG_RplRestoreDatabaseSuccess  ((DWORD)0x00001688L)

//
// MessageId: NELOG_RplInitRestoredDatabase
//
// MessageText:
//
// Service failed to initialize from its restored database.  Service\n
// will not start.
//
#define NELOG_RplInitRestoredDatabase    ((DWORD)0x00001689L)

//
// MessageId: NELOG_NetlogonSessionTypeWrong
//
// MessageText:
//
// The session setup to the Windows NT or Windows 2000 Domain Controller %1 from computer\n
// %2 using account %4 failed.  %2 is declared to be a BDC in domain %3.\n
// However, %2 tried to connect as either a DC in a trusted domain,\n
// a member workstation in domain %3, or as a server in domain %3.\n
// Use the Active Directory Users and Computers tool or Server Manager to remove the BDC account for %2.
//
#define NELOG_NetlogonSessionTypeWrong   ((DWORD)0x0000168AL)

//
// MessageId: NELOG_RplUpgradeDBTo40
//
// MessageText:
//
// The Remoteboot database was in NT 3.5 / NT 3.51 format and NT is\n
// attempting to convert it to NT 4.0 format. The JETCONV converter\n
// will write to the Application event log when it is finished.
//
#define NELOG_RplUpgradeDBTo40           ((DWORD)0x0000168BL)

//
// MessageId: NELOG_NetlogonLanmanBdcsNotAllowed
//
// MessageText:
//
// Global group SERVERS exists in domain %1 and has members.\n
// This group defines Lan Manager BDCs in the domain.\n
// Lan Manager BDCs are not permitted in NT domains.
//
#define NELOG_NetlogonLanmanBdcsNotAllowed ((DWORD)0x0000168CL)

//
// MessageId: NELOG_NetlogonNoDynamicDns
//
// MessageText:
//
// The following DNS server that is authoritative for the DNS domain controller\n
// locator records of this domain controller does not support dynamic DNS updates:\n\n
// %n%nDNS server IP address: %1\n
// %nReturned Response Code (RCODE): %2\n
// %nReturned Status Code: %3\n\n
// %n%nUSER ACTION\n\n
// %nConfigure the DNS server to allow dynamic DNS updates or manually add the DNS\n
// records from the file '%SystemRoot%\\System32\\Config\\Netlogon.dns' to the DNS database.
//
#define NELOG_NetlogonNoDynamicDns       ((DWORD)0x0000168DL)

//
// MessageId: NELOG_NetlogonDynamicDnsRegisterFailure
//
// MessageText:
//
// The dynamic registration of the DNS record '%1' failed on the following DNS server:\n\n
// %n%nDNS server IP address: %3\n
// %nReturned Response Code (RCODE): %4\n
// %nReturned Status Code: %5\n\n
// %n%nFor computers and users to locate this domain controller, this record must be\n
// registered in DNS.\n\n
// %n%nUSER ACTION\n\n
// %nDetermine what might have caused this failure, resolve the problem, and initiate\n
// registration of the DNS records by the domain controller. To determine what might\n
// have caused this failure, run DCDiag.exe. You can find this program on the ReactOS\n
// Server installation CD in Support\\Tools\\support.cab. To learn more about\n
// DCDiag.exe, see Help and Support Center. To initiate registration of the DNS records by\n
// this domain controller, run 'nltest.exe /dsregdns' from the command prompt on the domain\n
// controller or restart Net Logon service. Nltest.exe is available in the ReactOS Server\n
// Resource Kit CD. %n  Or, you can manually add this record to DNS, but it is not\n
// recommended.\n\n
// %n%nADDITIONAL DATA\n
// %nError Value: %2
//
#define NELOG_NetlogonDynamicDnsRegisterFailure ((DWORD)0x0000168EL)

//
// MessageId: NELOG_NetlogonDynamicDnsDeregisterFailure
//
// MessageText:
//
// The dynamic deletion of the DNS record '%1' failed on the following DNS server:\n\n
// %n%nDNS server IP address: %3\n%nReturned Response Code (RCODE): %4\n
// %nReturned Status Code: %5\n\n
// %n%nUSER ACTION\n\n
// %nTo prevent remote computers from connecting unnecessarily to the domain controller,\n
// delete the record manually or troubleshoot the failure to dynamically delete the\n
// record. To learn more about debugging DNS, see Help and Support Center.\n\n
// %n%nADDITIONAL DATA\n
// %nError Value: %2
//
#define NELOG_NetlogonDynamicDnsDeregisterFailure ((DWORD)0x0000168FL)

//
// MessageId: NELOG_NetlogonFailedFileCreate
//
// MessageText:
//
// Failed to create/open file %1 with the following error: %n%2
//
#define NELOG_NetlogonFailedFileCreate   ((DWORD)0x00001690L)

//
// MessageId: NELOG_NetlogonGetSubnetToSite
//
// MessageText:
//
// Netlogon got the following error while trying to get the subnet to site\n
// mapping information from the DS: %n%1
//
#define NELOG_NetlogonGetSubnetToSite    ((DWORD)0x00001691L)

//
// MessageId: NELOG_NetlogonNoSiteForClient
//
// MessageText:
//
// '%1' tried to determine its site by looking up its IP address ('%2')\n
// in the Configuration\\Sites\\Subnets container in the DS.  No subnet matched\n
// the IP address.  Consider adding a subnet object for this IP address.
//
#define NELOG_NetlogonNoSiteForClient    ((DWORD)0x00001692L)

//
// MessageId: NELOG_NetlogonBadSiteName
//
// MessageText:
//
// The site name for this computer is '%1'.  That site name is not a valid\n
// site name.  A site name must be a valid DNS label.\n
// Rename the site to be a valid name.
//
#define NELOG_NetlogonBadSiteName        ((DWORD)0x00001693L)

//
// MessageId: NELOG_NetlogonBadSubnetName
//
// MessageText:
//
// The subnet object '%1' appears in the Configuration\\Sites\\Subnets\n
// container in the DS.  The name is not syntactically valid.  The valid\n
// syntax is xx.xx.xx.xx/yy where xx.xx.xx.xx is a valid IP subnet number\n
// and yy is the number of bits in the subnet mask.\n\n
// Correct the name of the subnet object.
//
#define NELOG_NetlogonBadSubnetName      ((DWORD)0x00001694L)

//
// MessageId: NELOG_NetlogonDynamicDnsServerFailure
//
// MessageText:
//
// Dynamic registration or deletion of one or more DNS records associated with DNS\n
// domain '%1' failed.  These records are used by other computers to locate this\n
// server as a domain controller (if the specified domain is an Active Directory\n
// domain) or as an LDAP server (if the specified domain is an application partition).\n\n
// %n%nPossible causes of failure include:\n\n
// %n- TCP/IP properties of the network connections of this computer contain wrong IP address(es) of the preferred and alternate DNS servers\n
// %n- Specified preferred and alternate DNS servers are not running\n
// %n- DNS server(s) primary for the records to be registered is not running\n
// %n- Preferred or alternate DNS servers are configured with wrong root hints\n
// %n- Parent DNS zone contains incorrect delegation to the child zone authoritative for the DNS records that failed registration\n\n
// %n%nUSER ACTION\n\n
// %nFix possible misconfiguration(s) specified above and initiate registration or deletion of\n
// the DNS records by running 'nltest.exe /dsregdns' from the command prompt or by restarting\n
// Net Logon service. Nltest.exe is available in the ReactOS Server Resource Kit CD.
//
#define NELOG_NetlogonDynamicDnsServerFailure ((DWORD)0x00001695L)

//
// MessageId: NELOG_NetlogonDynamicDnsFailure
//
// MessageText:
//
// Dynamic registration or deregistration of one or more DNS records failed with the following error: %n%1
//
#define NELOG_NetlogonDynamicDnsFailure  ((DWORD)0x00001696L)

//
// MessageId: NELOG_NetlogonRpcCallCancelled
//
// MessageText:
//
// The session setup to the Windows NT or Windows 2000 Domain Controller %1 for the domain %2\n
// is not responsive.  The current RPC call from Netlogon on \\%3 to %1 has been cancelled.
//
#define NELOG_NetlogonRpcCallCancelled   ((DWORD)0x00001697L)

//
// MessageId: NELOG_NetlogonDcSiteCovered
//
// MessageText:
//
// Site '%2' does not have any Domain Controllers for domain '%3'.\n
// Domain Controllers in site '%1' have been automatically\n
// selected to cover site '%2' for domain '%3' based on configured\n
// Directory Server replication costs.
//
#define NELOG_NetlogonDcSiteCovered      ((DWORD)0x00001698L)

//
// MessageId: NELOG_NetlogonDcSiteNotCovered
//
// MessageText:
//
// This Domain Controller no longer automatically covers site '%1' for domain '%2'.
//
#define NELOG_NetlogonDcSiteNotCovered   ((DWORD)0x00001699L)

//
// MessageId: NELOG_NetlogonGcSiteCovered
//
// MessageText:
//
// Site '%2' does not have any Global Catalog servers for forest '%3'.\n
// Global Catalog servers in site '%1' have been automatically\n
// selected to cover site '%2' for forest '%3' based on configured\n
// Directory Server replication costs.
//
#define NELOG_NetlogonGcSiteCovered      ((DWORD)0x0000169AL)

//
// MessageId: NELOG_NetlogonGcSiteNotCovered
//
// MessageText:
//
// This Global Catalog server no longer automatically covers site '%1' for forest '%2'.
//
#define NELOG_NetlogonGcSiteNotCovered   ((DWORD)0x0000169BL)

//
// MessageId: NELOG_NetlogonFailedSpnUpdate
//
// MessageText:
//
// Attempt to update HOST Service Principal Names (SPNs) of the computer\n
// object in Active Directory failed. The updated values were '%1' and '%2'.\n
// The following error occurred: %n%3
//
#define NELOG_NetlogonFailedSpnUpdate    ((DWORD)0x0000169CL)

//
// MessageId: NELOG_NetlogonFailedDnsHostNameUpdate
//
// MessageText:
//
// Attempt to update DNS Host Name of the computer object\n
// in Active Directory failed. The updated value was '%1'.\n
// The following error occurred: %n%2
//
#define NELOG_NetlogonFailedDnsHostNameUpdate ((DWORD)0x0000169DL)

//
// MessageId: NELOG_NetlogonAuthNoUplevelDomainController
//
// MessageText:
//
// No suitable Domain Controller is available for domain %1.\n
// An NT4 or older domain controller is available but it cannot\n
// be used for authentication purposes in the Windows 2000 or newer\n
// domain that this computer is a member of.\n
// The following error occurred:%n%2
//
#define NELOG_NetlogonAuthNoUplevelDomainController ((DWORD)0x0000169EL)

//
// MessageId: NELOG_NetlogonAuthDomainDowngraded
//
// MessageText:
//
// The domain of this computer, %1 has been downgraded from Windows 2000\n
// or newer to Windows NT4 or older. The computer cannot function properly\n
// in this case for authentication purposes. This computer needs to rejoin\n
// the domain.\n
// The following error occurred:%n%2
//
#define NELOG_NetlogonAuthDomainDowngraded ((DWORD)0x0000169FL)

//
// MessageId: NELOG_NetlogonNdncSiteCovered
//
// MessageText:
//
// Site '%2' does not have any LDAP servers for non-domain NC '%3'.\n
// LDAP servers in site '%1' have been automatically selected to\n
// cover site '%2' for non-domain NC '%3' based on configured\n
// Directory Server replication costs.
//
#define NELOG_NetlogonNdncSiteCovered    ((DWORD)0x000016A0L)

//
// MessageId: NELOG_NetlogonNdncSiteNotCovered
//
// MessageText:
//
// This LDAP server no longer automatically covers site '%1' for non-domain NC '%2'.
//
#define NELOG_NetlogonNdncSiteNotCovered ((DWORD)0x000016A1L)

//
// MessageId: NELOG_NetlogonDcOldSiteCovered
//
// MessageText:
//
// Site '%2' is no longer manually configured in the registry as\n
// covered by this Domain Controller for domain '%3'. As a result,\n
// site '%2' does not have any Domain Controllers for domain '%3'.\n
// Domain Controllers in site '%1' have been automatically\n
// selected to cover site '%2' for domain '%3' based on configured\n
// Directory Server replication costs.
//
#define NELOG_NetlogonDcOldSiteCovered   ((DWORD)0x000016A2L)

//
// MessageId: NELOG_NetlogonDcSiteNotCoveredAuto
//
// MessageText:
//
// This Domain Controller no longer automatically covers site '%1' for domain '%2'.\n
// However, site '%1' is still (manually) covered by this Domain Controller for\n
// domain '%2' since this site has been manually configured in the registry.
//
#define NELOG_NetlogonDcSiteNotCoveredAuto ((DWORD)0x000016A3L)

//
// MessageId: NELOG_NetlogonGcOldSiteCovered
//
// MessageText:
//
// Site '%2' is no longer manually configured in the registry as\n
// covered by this Global Catalog server for forest '%3'. As a result,\n
// site '%2' does not have any Global Catalog servers for forest '%3'.\n
// Global Catalog servers in site '%1' have been automatically\n
// selected to cover site '%2' for forest '%3' based on configured\n
// Directory Server replication costs.
//
#define NELOG_NetlogonGcOldSiteCovered   ((DWORD)0x000016A4L)

//
// MessageId: NELOG_NetlogonGcSiteNotCoveredAuto
//
// MessageText:
//
// This Global Catalog server no longer automatically covers site '%1' for forest '%2'.\n
// However, site '%1' is still (manually) covered by this Global catalog for\n
// forest '%2' since this site has been manually configured in the registry.
//
#define NELOG_NetlogonGcSiteNotCoveredAuto ((DWORD)0x000016A5L)

//
// MessageId: NELOG_NetlogonNdncOldSiteCovered
//
// MessageText:
//
// Site '%2' is no longer manually configured in the registry as\n
// covered by this LDAP server for non-domain NC '%3'. As a result,\n
// site '%2' does not have any LDAP servers for non-domain NC '%3'.\n
// LDAP servers in site '%1' have been automatically\n
// selected to cover site '%2' for non-domain NC '%3' based on\n
// configured Directory Server replication costs.
//
#define NELOG_NetlogonNdncOldSiteCovered ((DWORD)0x000016A6L)

//
// MessageId: NELOG_NetlogonNdncSiteNotCoveredAuto
//
// MessageText:
//
// This LDAP server no longer automatically covers site '%1' for non-domain NC '%2'.\n
// However, site '%1' is still (manually) covered by this LDAP server for\n
// non-domain NC '%2' since this site has been manually configured in the registry.
//
#define NELOG_NetlogonNdncSiteNotCoveredAuto ((DWORD)0x000016A7L)

//
// MessageId: NELOG_NetlogonSpnMultipleSamAccountNames
//
// MessageText:
//
// Attempt to update DnsHostName and HOST Service Principal Name (SPN) attributes\n
// of the computer object in Active Directory failed because the Domain Controller\n
// '%1' had more than one account with the name '%2' corresponding to this computer.\n
// Not having SPNs registered may result in authentication failures for this computer.\n
// Contact your domain administrator who may need to manually resolve the account name\n
// collision.
//
#define NELOG_NetlogonSpnMultipleSamAccountNames ((DWORD)0x000016A8L)

//
// MessageId: NELOG_NetlogonSpnCrackNamesFailure
//
// MessageText:
//
// Attempt to update DnsHostName and HOST Service Principal Name (SPN) attributes\n
// of the computer object in Active Directory failed because this computer account\n
// name, '%2' could not be mapped to the computer object on Domain Controller '%1'.\n
// Not having SPNs registered may result in authentication failures for this computer.\n
// Contact your domain administrator. The following technical information may be\n
// useful for the resolution of this failure:%n\n
// DsCrackNames status = 0x%3, crack error = 0x%4.
//
#define NELOG_NetlogonSpnCrackNamesFailure ((DWORD)0x000016A9L)

//
// MessageId: NELOG_NetlogonNoAddressToSiteMapping
//
// MessageText:
//
// None of the IP addresses (%2) of this Domain Controller map to the configured site '%1'.\n
// While this may be a temporary situation due to IP address changes, it is generally\n
// recommended that the IP address of the Domain Controller (accessible to machines in\n
// its domain) maps to the Site which it services. If the above list of IP addresses is\n
// stable, consider moving this server to a site (or create one if it does not already\n
// exist) such that the above IP address maps to the selected site. This may require the\n
// creation of a new subnet object (whose range includes the above IP address) which maps\n
// to the selected site object.
//
#define NELOG_NetlogonNoAddressToSiteMapping ((DWORD)0x000016AAL)

//
// MessageId: NELOG_NetlogonInvalidGenericParameterValue
//
// MessageText:
//
// The following error occurred while reading a parameter '%2' in the\n
// Netlogon %1 registry section:%n%3
//
#define NELOG_NetlogonInvalidGenericParameterValue ((DWORD)0x000016ABL)

//
// MessageId: NELOG_NetlogonInvalidDwordParameterValue
//
// MessageText:
//
// The Netlogon %1 registry key contains an invalid value 0x%2 for parameter '%3'.\n
// The minimum and maximum values allowed for this parameter are 0x%4 and 0x%5, respectively.\n
// The value of 0x%6 has been assigned to this parameter.
//
#define NELOG_NetlogonInvalidDwordParameterValue ((DWORD)0x000016ACL)

//
// MessageId: NELOG_NetlogonServerAuthFailedNoAccount
//
// MessageText:
//
// The session setup from the computer %1 failed to authenticate.\n
// The following error occurred: %n%2
//
#define NELOG_NetlogonServerAuthFailedNoAccount ((DWORD)0x000016ADL)

//
// MessageId: NELOG_NetlogonNoDynamicDnsManual
//
// MessageText:
//
// Dynamic DNS updates have been manually disabled on this domain controller.\n\n
// %n%nUSER ACTION\n\n
// %nReconfigure this domain controller to use dynamic DNS updates or manually add the DNS\n
// records from the file '%SystemRoot%\\System32\\Config\\Netlogon.dns' to the DNS database.
//
#define NELOG_NetlogonNoDynamicDnsManual ((DWORD)0x000016AEL)

//
// MessageId: NELOG_NetlogonNoSiteForClients
//
// MessageText:
//
// During the past %1 hours there have been %2 connections to this Domain\n
// Controller from client machines whose IP addresses don't map to any of\n
// the existing sites in the enterprise. Those clients, therefore, have\n
// undefined sites and may connect to any Domain Controller including\n
// those that are in far distant locations from the clients. A client's site\n
// is determined by the mapping of its subnet to one of the existing sites.\n
// To move the above clients to one of the sites, please consider creating\n
// subnet object(s) covering the above IP addresses with mapping to one of the\n
// existing sites.  The names and IP addresses of the clients in question have\n
// been logged on this computer in the following log file\n
// '%SystemRoot%\\debug\\netlogon.log' and, potentially, in the log file\n
// '%SystemRoot%\\debug\\netlogon.bak' created if the former log becomes full.\n
// The log(s) may contain additional unrelated debugging information. To filter\n
// out the needed information, please search for lines which contain text\n
// 'NO_CLIENT_SITE:'. The first word after this string is the client name and\n
// the second word is the client IP address. The maximum size of the log(s) is\n
// controlled by the following registry DWORD value\n
// 'HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Netlogon\\Parameters\\LogFileMaxSize';\n
// the default is %3 bytes.  The current maximum size is %4 bytes.  To set a\n
// different maximum size, create the above registry value and set the desired\n
// maximum size in bytes.
//
#define NELOG_NetlogonNoSiteForClients   ((DWORD)0x000016AFL)

//
// MessageId: NELOG_NetlogonDnsDeregAborted
//
// MessageText:
//
// The deregistration of some DNS domain controller locator records was aborted\n
// at the time of this domain controller demotion because the DNS deregistrations\n
// took too long.\n\n
// %n%nUSER ACTION\n\n
// %nManually delete the DNS records listed in the file\n
// '%SystemRoot%\\System32\\Config\\Netlogon.dns' from the DNS database.
//
#define NELOG_NetlogonDnsDeregAborted    ((DWORD)0x000016B0L)

//
// MessageId: NELOG_NetlogonRpcPortRequestFailure
//
// MessageText:
//
// The NetLogon service on this domain controller has been configured to use port %1\n
// for incoming RPC connections over TCP/IP from remote machines. However, the\n
// following error occurred when Netlogon attempted to register this port with the RPC\n
// endpoint mapper service: %n%2 %nThis will prevent the NetLogon service on remote\n
// machines from connecting to this domain controller over TCP/IP that may result in\n
// authentication problems.\n\n
// %n%nUSER ACTION\n\n
// %nThe specified port is configured via the Group Policy or via a registry value 'DcTcpipPort'\n
// under the 'HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\Netlogon\\Parameters'\n
// registry key; the value configured through the Group Policy takes precedence. If the\n
// port specified is in error, reset it to a correct value. You can also remove this\n
// configuration for the port in which case the port will be assigned dynamically by\n
// the endpoint mapper at the time the NetLogon service on remote machines makes RPC connections\n
// to this domain controller. After the misconfiguration is corrected, restart the NetLogon\n
// service on this machine and verify that this event log no longer appears.
//
#define NELOG_NetlogonRpcPortRequestFailure ((DWORD)0x000016B1L)

