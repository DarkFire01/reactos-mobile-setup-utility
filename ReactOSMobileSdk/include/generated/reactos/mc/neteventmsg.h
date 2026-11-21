
 netevent.mc MESSAGE resources for netevent.dll


 IMPORTANT: When a new language is added, all messages in this file need to be
 either translated or at least duplicated for the new language.
 This is a new requirement by MS mc.exe
 To do this, start with a regex replace:
 - In VS IDE: "Language=English\r\n(?<String>(?:[^\.].*\r\n)*\.\r\n)" -> "Language=English\r\n${String}Language=MyLanguage\r\n${String}"


 message definitions

 Facility=System

 eventlog events 6000-6099

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
// MessageId: EVENT_LOG_FULL
//
// MessageText:
//
// The %1 log file is full.
//
#define EVENT_LOG_FULL                   ((DWORD)0x80001770L)

//
// MessageId: EVENT_LogFileNotOpened
//
// MessageText:
//
// The %1 log file cannot be opened.
//
#define EVENT_LogFileNotOpened           ((DWORD)0x80001771L)

//
// MessageId: EVENT_LogFileCorrupt
//
// MessageText:
//
// The %1 log file is corrupted and will be cleared.
//
#define EVENT_LogFileCorrupt             ((DWORD)0x80001772L)

//
// MessageId: EVENT_DefaultLogCorrupt
//
// MessageText:
//
// The Application log file could not be opened.  %1 will be used as the default log file.
//
#define EVENT_DefaultLogCorrupt          ((DWORD)0x80001773L)

//
// MessageId: EVENT_BadDriverPacket
//
// MessageText:
//
// A driver packet received from the I/O subsystem was invalid.  The data is the packet.
//
#define EVENT_BadDriverPacket            ((DWORD)0x80001774L)

//
// MessageId: EVENT_EventlogStarted
//
// MessageText:
//
// The Event log service was started.
//
#define EVENT_EventlogStarted            ((DWORD)0x80001775L)

//
// MessageId: EVENT_EventlogStopped
//
// MessageText:
//
// The Event log service was stopped.
//
#define EVENT_EventlogStopped            ((DWORD)0x80001776L)

//
// MessageId: TITLE_EventlogMessageBox
//
// MessageText:
//
// Eventlog Service %0
//
#define TITLE_EventlogMessageBox         ((DWORD)0x80001777L)

//
// MessageId: EVENT_EventlogAbnormalShutdown
//
// MessageText:
//
// The previous system shutdown at %1 on %2 was unexpected.
//
#define EVENT_EventlogAbnormalShutdown   ((DWORD)0x80001778L)

//
// MessageId: EVENT_EventLogProductInfo
//
// MessageText:
//
// ReactOS %1 %2 %3 %4.
//
#define EVENT_EventLogProductInfo        ((DWORD)0x80001779L)

//
// MessageId: EVENT_ServiceNoEventLog
//
// MessageText:
//
// The %1 service was unable to set up an event source.
//
#define EVENT_ServiceNoEventLog          ((DWORD)0xC000177AL)

//
// MessageId: EVENT_ComputerNameChange
//
// MessageText:
//
// The NetBIOS name and DNS host name of this machine have been changed from %1 to %2.
//
#define EVENT_ComputerNameChange         ((DWORD)0xC000177BL)

//
// MessageId: EVENT_DNSDomainNameChange
//
// MessageText:
//
// The DNS domain assigned to this computer has been changed from %1 to %2.
//
#define EVENT_DNSDomainNameChange        ((DWORD)0xC000177CL)


 system events 6100 - 6199

//
// MessageId: EVENT_UP_DRIVER_ON_MP
//
// MessageText:
//
// A uniprocessor-specific driver was loaded on a multiprocessor system.  The driver could not load.
//
#define EVENT_UP_DRIVER_ON_MP            ((DWORD)0xC00017D4L)


 service controller events 7000-7899

//
// MessageId: EVENT_SERVICE_START_FAILED
//
// MessageText:
//
// The %1 service failed to start due to the following error: %n%2
//
#define EVENT_SERVICE_START_FAILED       ((DWORD)0xC0001B58L)

//
// MessageId: EVENT_SERVICE_START_FAILED_II
//
// MessageText:
//
// The %1 service depends on the %2 service which failed to start because of the following error: %n%3
//
#define EVENT_SERVICE_START_FAILED_II    ((DWORD)0xC0001B59L)

//
// MessageId: EVENT_SERVICE_START_FAILED_GROUP
//
// MessageText:
//
// The %1 service depends on the %2 group and no member of this group started.
//
#define EVENT_SERVICE_START_FAILED_GROUP ((DWORD)0xC0001B5AL)

//
// MessageId: EVENT_SERVICE_START_FAILED_NONE
//
// MessageText:
//
// The %1 service depends on the following nonexistent service: %2
//
#define EVENT_SERVICE_START_FAILED_NONE  ((DWORD)0xC0001B5BL)

//
// MessageId: EVENT_CALL_TO_FUNCTION_FAILED
//
// MessageText:
//
// The %1 call failed with the following error: %n%2
//
#define EVENT_CALL_TO_FUNCTION_FAILED    ((DWORD)0xC0001B5DL)

//
// MessageId: EVENT_CALL_TO_FUNCTION_FAILED_II
//
// MessageText:
//
// The %1 call failed for %2 with the following error: %n%3
//
#define EVENT_CALL_TO_FUNCTION_FAILED_II ((DWORD)0xC0001B5EL)

//
// MessageId: EVENT_REVERTED_TO_LASTKNOWNGOOD
//
// MessageText:
//
// The system reverted to its last known good configuration.  The system is restarting....
//
#define EVENT_REVERTED_TO_LASTKNOWNGOOD  ((DWORD)0xC0001B5FL)

//
// MessageId: EVENT_BAD_ACCOUNT_NAME
//
// MessageText:
//
// No backslash is in the account name.
//
#define EVENT_BAD_ACCOUNT_NAME           ((DWORD)0xC0001B60L)

//
// MessageId: EVENT_CONNECTION_TIMEOUT
//
// MessageText:
//
// Timeout (%1 milliseconds) waiting for the %2 service to connect.
//
#define EVENT_CONNECTION_TIMEOUT         ((DWORD)0xC0001B61L)

//
// MessageId: EVENT_READFILE_TIMEOUT
//
// MessageText:
//
// Timeout (%1 milliseconds) waiting for ReadFile.
//
#define EVENT_READFILE_TIMEOUT           ((DWORD)0xC0001B62L)

//
// MessageId: EVENT_TRANSACT_TIMEOUT
//
// MessageText:
//
// Timeout (%1 milliseconds) waiting for a transaction response from the %2 service.
//
#define EVENT_TRANSACT_TIMEOUT           ((DWORD)0xC0001B63L)

//
// MessageId: EVENT_TRANSACT_INVALID
//
// MessageText:
//
// Message returned in transaction has incorrect size.
//
#define EVENT_TRANSACT_INVALID           ((DWORD)0xC0001B64L)

//
// MessageId: EVENT_FIRST_LOGON_FAILED
//
// MessageText:
//
// Logon attempt with current password failed with the following error: %n%1
//
#define EVENT_FIRST_LOGON_FAILED         ((DWORD)0xC0001B65L)

//
// MessageId: EVENT_SECOND_LOGON_FAILED
//
// MessageText:
//
// Second logon attempt with old password also failed with the following error: %n%1
//
#define EVENT_SECOND_LOGON_FAILED        ((DWORD)0xC0001B66L)

//
// MessageId: EVENT_INVALID_DRIVER_DEPENDENCY
//
// MessageText:
//
// Boot-start or system-start driver (%1) must not depend on a service.
//
#define EVENT_INVALID_DRIVER_DEPENDENCY  ((DWORD)0xC0001B67L)

//
// MessageId: EVENT_BAD_SERVICE_STATE
//
// MessageText:
//
// The %1 service has reported an invalid current state %2.
//
#define EVENT_BAD_SERVICE_STATE          ((DWORD)0xC0001B68L)

//
// MessageId: EVENT_CIRCULAR_DEPENDENCY_DEMAND
//
// MessageText:
//
// Detected circular dependencies demand starting %1.
//
#define EVENT_CIRCULAR_DEPENDENCY_DEMAND ((DWORD)0xC0001B69L)

//
// MessageId: EVENT_CIRCULAR_DEPENDENCY_AUTO
//
// MessageText:
//
// Detected circular dependencies auto-starting services.
//
#define EVENT_CIRCULAR_DEPENDENCY_AUTO   ((DWORD)0xC0001B6AL)

//
// MessageId: EVENT_DEPEND_ON_LATER_SERVICE
//
// MessageText:
//
// Circular dependency: The %1 service depends on a service in a group which starts later.
//
#define EVENT_DEPEND_ON_LATER_SERVICE    ((DWORD)0xC0001B6BL)

//
// MessageId: EVENT_DEPEND_ON_LATER_GROUP
//
// MessageText:
//
// Circular dependency: The %1 service depends on a group which starts later.
//
#define EVENT_DEPEND_ON_LATER_GROUP      ((DWORD)0xC0001B6CL)

//
// MessageId: EVENT_SEVERE_SERVICE_FAILED
//
// MessageText:
//
// About to revert to the last known good configuration because the %1 service failed to start.
//
#define EVENT_SEVERE_SERVICE_FAILED      ((DWORD)0xC0001B6DL)

//
// MessageId: EVENT_SERVICE_START_HUNG
//
// MessageText:
//
// The %1 service hung on starting.
//
#define EVENT_SERVICE_START_HUNG         ((DWORD)0xC0001B6EL)

//
// MessageId: EVENT_SERVICE_EXIT_FAILED
//
// MessageText:
//
// The %1 service terminated with the following error: %n%2
//
#define EVENT_SERVICE_EXIT_FAILED        ((DWORD)0xC0001B6FL)

//
// MessageId: EVENT_SERVICE_EXIT_FAILED_SPECIFIC
//
// MessageText:
//
// The %1 service terminated with service-specific error %2.
//
#define EVENT_SERVICE_EXIT_FAILED_SPECIFIC ((DWORD)0xC0001B70L)

//
// MessageId: EVENT_SERVICE_START_AT_BOOT_FAILED
//
// MessageText:
//
// At least one service or driver failed during system startup.  Use Event Viewer to examine the event log for details.
//
#define EVENT_SERVICE_START_AT_BOOT_FAILED ((DWORD)0xC0001B71L)

//
// MessageId: EVENT_BOOT_SYSTEM_DRIVERS_FAILED
//
// MessageText:
//
// The following boot-start or system-start driver(s) failed to load: %1
//
#define EVENT_BOOT_SYSTEM_DRIVERS_FAILED ((DWORD)0xC0001B72L)

//
// MessageId: EVENT_RUNNING_LASTKNOWNGOOD
//
// MessageText:
//
// ReactOS could not be started as configured.  A previous working configuration was used instead.
//
#define EVENT_RUNNING_LASTKNOWNGOOD      ((DWORD)0xC0001B73L)

//
// MessageId: EVENT_TAKE_OWNERSHIP
//
// MessageText:
//
// The %1 Registry key denied access to SYSTEM account programs so the Service Control Manager took ownership of the Registry key.
//
#define EVENT_TAKE_OWNERSHIP             ((DWORD)0xC0001B74L)

//
// MessageId: TITLE_SC_MESSAGE_BOX
//
// MessageText:
//
// Service Control Manager %0
//
#define TITLE_SC_MESSAGE_BOX             ((DWORD)0xC0001B75L)

//
// MessageId: EVENT_SERVICE_NOT_INTERACTIVE
//
// MessageText:
//
// The %1 service is marked as an interactive service.  However, the system is configured to not allow interactive services.  This service may not function properly.
//
#define EVENT_SERVICE_NOT_INTERACTIVE    ((DWORD)0xC0001B76L)

//
// MessageId: EVENT_SERVICE_CRASH
//
// MessageText:
//
// The %1 service terminated unexpectedly.  It has done this %2 time(s).  The following corrective action will be taken in %3 milliseconds: %5.
//
#define EVENT_SERVICE_CRASH              ((DWORD)0xC0001B77L)

//
// MessageId: EVENT_SERVICE_RECOVERY_FAILED
//
// MessageText:
//
// The Service Control Manager tried to take a corrective action (%2) after the unexpected termination of the %3 service, but this action failed with the following error: %n%4
//
#define EVENT_SERVICE_RECOVERY_FAILED    ((DWORD)0xC0001B78L)

//
// MessageId: EVENT_SERVICE_SCESRV_FAILED
//
// MessageText:
//
// The Service Control Manager did not initialize successfully. The security
// configuration server (scesrv.dll) failed to initialize with error %1.  The
// system is restarting...
//
#define EVENT_SERVICE_SCESRV_FAILED      ((DWORD)0xC0001B79L)

//
// MessageId: EVENT_SERVICE_CRASH_NO_ACTION
//
// MessageText:
//
// The %1 service terminated unexpectedly.  It has done this %2 time(s).
//
#define EVENT_SERVICE_CRASH_NO_ACTION    ((DWORD)0xC0001B7AL)

//
// MessageId: EVENT_SERVICE_CONTROL_SUCCESS
//
// MessageText:
//
// The %1 service was successfully sent a %2 control.
//
#define EVENT_SERVICE_CONTROL_SUCCESS    ((DWORD)0x40001B7BL)

//
// MessageId: EVENT_SERVICE_STATUS_SUCCESS
//
// MessageText:
//
// The %1 service entered the %2 state.
//
#define EVENT_SERVICE_STATUS_SUCCESS     ((DWORD)0x40001B7CL)

//
// MessageId: EVENT_SERVICE_CONFIG_BACKOUT_FAILED
//
// MessageText:
//
// The Service Control Manager encountered an error undoing a configuration change
// to the %1 service.  The service's %2 is currently in an unpredictable state.
// 
// If you do not correct this configuration, you may not be able to restart the %1
// service or may encounter other errors.  To ensure that the service is configured
// properly, use the Services snap-in in Microsoft Management Console (MMC).
//
#define EVENT_SERVICE_CONFIG_BACKOUT_FAILED ((DWORD)0xC0001B7DL)

//
// MessageId: EVENT_FIRST_LOGON_FAILED_II
//
// MessageText:
//
// The %1 service was unable to log on as %2 with the currently configured
// password due to the following error: %n%3%n%nTo ensure that the service is
// configured properly, use the Services snap-in in Microsoft Management
// Console (MMC).
//
#define EVENT_FIRST_LOGON_FAILED_II      ((DWORD)0xC0001B7EL)

//
// MessageId: EVENT_SERVICE_DIFFERENT_PID_CONNECTED
//
// MessageText:
//
// A service process other than the one launched by the Service Control Manager
// connected when starting the %1 service.  The Service Control Manager launched
// process %2 and process %3 connected instead.%n%n
// 
// Note that if this service is configured to start under a debugger, this behavior is expected.
//
#define EVENT_SERVICE_DIFFERENT_PID_CONNECTED ((DWORD)0x80001B7FL)

//
// MessageId: EVENT_SERVICE_START_TYPE_CHANGED
//
// MessageText:
//
// The start type of the %1 service was changed from %2 to %3.
//
#define EVENT_SERVICE_START_TYPE_CHANGED ((DWORD)0x40001B80L)

//
// MessageId: EVENT_SERVICE_LOGON_TYPE_NOT_GRANTED
//
// MessageText:
//
// The %1 service was unable to log on as %2 with the currently configured password due to the following error:%n
// Logon failure: the user has not been granted the requested logon type at this computer.%n%n
// Service: %1%n
// Domain and account: %2%n%n
// This service account does not have the necessary user right "Log on as a service."%n%n
// User Action%n%n
// Assign "Log on as a service" to the service account on this computer. You can
// use Local Security Settings (Secpol.msc) to do this. If this computer is a
// node in a cluster, check that this user right is assigned to the Cluster
// service account on all nodes in the cluster.%n%n
// If you have already assigned this user right to the service account, and the
// user right appears to be removed, a Group Policy object associated with this
// node might be removing the right. Check with your domain administrator to find
// out if this is happening.
//
#define EVENT_SERVICE_LOGON_TYPE_NOT_GRANTED ((DWORD)0xC0001B81L)

//
// MessageId: EVENT_SERVICE_STOP_SUCCESS_WITH_REASON
//
// MessageText:
//
// The %1 service was successfully sent a %2 control.%n%n
// The reason specified was: %3 [%4]%n%n
// Comment: %5
//
#define EVENT_SERVICE_STOP_SUCCESS_WITH_REASON ((DWORD)0x40001B82L)

//
// MessageId: EVENT_SERVICE_SHUTDOWN_FAILED
//
// MessageText:
//
// The %1 service did not shut down properly after receiving a preshutdown control.
//
#define EVENT_SERVICE_SHUTDOWN_FAILED    ((DWORD)0xC0001B83L)


 transport events 9000-9499

//
// MessageId: EVENT_TRANSPORT_REGISTER_FAILED
//
// MessageText:
//
// %2 failed to register itself with the NDIS wrapper.
//
#define EVENT_TRANSPORT_REGISTER_FAILED  ((DWORD)0xC000232CL)

//
// MessageId: EVENT_TRANSPORT_ADAPTER_NOT_FOUND
//
// MessageText:
//
// %2 could not find adapter %3.
//
#define EVENT_TRANSPORT_ADAPTER_NOT_FOUND ((DWORD)0xC000232EL)

