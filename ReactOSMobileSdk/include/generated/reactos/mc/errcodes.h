
 IMPORTANT: When a new language is added, all messages in this file need to be
 either translated or at least duplicated for the new language.
 This is a new requirement by MS mc.exe
 To do this, start with a regex replace:
 - In VS IDE: "Language=English\r\n(?<String>(?:[^\.].*\r\n)*\.\r\n)" -> "Language=English\r\n${String}Language=MyLanguage\r\n${String}"

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
#define FACILITY_ITF                     0x4
#define FACILITY_GENERAL                 0x7


//
// Define the severity codes
//
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: ERROR_SUCCESS
//
// MessageText:
//
// The operation completed successfully.
//
#define ERROR_SUCCESS                    ((ULONG)0x00000000L)

//
// MessageId: ERROR_INVALID_FUNCTION
//
// MessageText:
//
// Incorrect function.
//
#define ERROR_INVALID_FUNCTION           ((ULONG)0x00000001L)

//
// MessageId: ERROR_FILE_NOT_FOUND
//
// MessageText:
//
// The system cannot find the file specified.
//
#define ERROR_FILE_NOT_FOUND             ((ULONG)0x00000002L)

//
// MessageId: ERROR_PATH_NOT_FOUND
//
// MessageText:
//
// The system cannot find the path specified.
//
#define ERROR_PATH_NOT_FOUND             ((ULONG)0x00000003L)

//
// MessageId: ERROR_TOO_MANY_OPEN_FILES
//
// MessageText:
//
// The system cannot open the file.
//
#define ERROR_TOO_MANY_OPEN_FILES        ((ULONG)0x00000004L)

//
// MessageId: ERROR_ACCESS_DENIED
//
// MessageText:
//
// Access is denied.
//
#define ERROR_ACCESS_DENIED              ((ULONG)0x00000005L)

//
// MessageId: ERROR_INVALID_HANDLE
//
// MessageText:
//
// The handle is invalid.
//
#define ERROR_INVALID_HANDLE             ((ULONG)0x00000006L)

//
// MessageId: ERROR_ARENA_TRASHED
//
// MessageText:
//
// The storage control blocks were destroyed.
//
#define ERROR_ARENA_TRASHED              ((ULONG)0x00000007L)

//
// MessageId: ERROR_NOT_ENOUGH_MEMORY
//
// MessageText:
//
// Not enough storage is available to process this command.
//
#define ERROR_NOT_ENOUGH_MEMORY          ((ULONG)0x00000008L)

//
// MessageId: ERROR_INVALID_BLOCK
//
// MessageText:
//
// The storage control block address is invalid.
//
#define ERROR_INVALID_BLOCK              ((ULONG)0x00000009L)

//
// MessageId: ERROR_BAD_ENVIRONMENT
//
// MessageText:
//
// The environment is incorrect.
//
#define ERROR_BAD_ENVIRONMENT            ((ULONG)0x0000000AL)

//
// MessageId: ERROR_BAD_FORMAT
//
// MessageText:
//
// An attempt was made to load a program with an incorrect format.
//
#define ERROR_BAD_FORMAT                 ((ULONG)0x0000000BL)

//
// MessageId: ERROR_INVALID_ACCESS
//
// MessageText:
//
// The access code is invalid.
//
#define ERROR_INVALID_ACCESS             ((ULONG)0x0000000CL)

//
// MessageId: ERROR_INVALID_DATA
//
// MessageText:
//
// The data is invalid.
//
#define ERROR_INVALID_DATA               ((ULONG)0x0000000DL)

//
// MessageId: ERROR_OUTOFMEMORY
//
// MessageText:
//
// Not enough storage is available to complete this operation.
//
#define ERROR_OUTOFMEMORY                ((ULONG)0x0000000EL)

//
// MessageId: ERROR_INVALID_DRIVE
//
// MessageText:
//
// The system cannot find the drive specified.
//
#define ERROR_INVALID_DRIVE              ((ULONG)0x0000000FL)

//
// MessageId: ERROR_CURRENT_DIRECTORY
//
// MessageText:
//
// The directory cannot be removed.
//
#define ERROR_CURRENT_DIRECTORY          ((ULONG)0x00000010L)

//
// MessageId: ERROR_NOT_SAME_DEVICE
//
// MessageText:
//
// The system cannot move the file to a different disk drive.
//
#define ERROR_NOT_SAME_DEVICE            ((ULONG)0x00000011L)

//
// MessageId: ERROR_NO_MORE_FILES
//
// MessageText:
//
// There are no more files.
//
#define ERROR_NO_MORE_FILES              ((ULONG)0x00000012L)

//
// MessageId: ERROR_WRITE_PROTECT
//
// MessageText:
//
// The media is write protected.
//
#define ERROR_WRITE_PROTECT              ((ULONG)0x00000013L)

//
// MessageId: ERROR_BAD_UNIT
//
// MessageText:
//
// The system cannot find the device specified.
//
#define ERROR_BAD_UNIT                   ((ULONG)0x00000014L)

//
// MessageId: ERROR_NOT_READY
//
// MessageText:
//
// The device is not ready.
//
#define ERROR_NOT_READY                  ((ULONG)0x00000015L)

//
// MessageId: ERROR_BAD_COMMAND
//
// MessageText:
//
// The device does not recognize the command.
//
#define ERROR_BAD_COMMAND                ((ULONG)0x00000016L)

//
// MessageId: ERROR_CRC
//
// MessageText:
//
// Data error (cyclic redundancy check).
//
#define ERROR_CRC                        ((ULONG)0x00000017L)

//
// MessageId: ERROR_BAD_LENGTH
//
// MessageText:
//
// The program issued a command but the command length is incorrect.
//
#define ERROR_BAD_LENGTH                 ((ULONG)0x00000018L)

//
// MessageId: ERROR_SEEK
//
// MessageText:
//
// The drive cannot locate a specific area or track on the disk.
//
#define ERROR_SEEK                       ((ULONG)0x00000019L)

//
// MessageId: ERROR_NOT_DOS_DISK
//
// MessageText:
//
// The specified disk or diskette cannot be accessed.
//
#define ERROR_NOT_DOS_DISK               ((ULONG)0x0000001AL)

//
// MessageId: ERROR_SECTOR_NOT_FOUND
//
// MessageText:
//
// The drive cannot find the sector requested.
//
#define ERROR_SECTOR_NOT_FOUND           ((ULONG)0x0000001BL)

//
// MessageId: ERROR_OUT_OF_PAPER
//
// MessageText:
//
// The printer is out of paper.
//
#define ERROR_OUT_OF_PAPER               ((ULONG)0x0000001CL)

//
// MessageId: ERROR_WRITE_FAULT
//
// MessageText:
//
// The system cannot write to the specified device.
//
#define ERROR_WRITE_FAULT                ((ULONG)0x0000001DL)

//
// MessageId: ERROR_READ_FAULT
//
// MessageText:
//
// The system cannot read from the specified device.
//
#define ERROR_READ_FAULT                 ((ULONG)0x0000001EL)

//
// MessageId: ERROR_GEN_FAILURE
//
// MessageText:
//
// A device attached to the system is not functioning.
//
#define ERROR_GEN_FAILURE                ((ULONG)0x0000001FL)

//
// MessageId: ERROR_SHARING_VIOLATION
//
// MessageText:
//
// The process cannot access the file because it is being used by another process.
//
#define ERROR_SHARING_VIOLATION          ((ULONG)0x00000020L)

//
// MessageId: ERROR_LOCK_VIOLATION
//
// MessageText:
//
// The process cannot access the file because another process has locked a portion of the file.
//
#define ERROR_LOCK_VIOLATION             ((ULONG)0x00000021L)

//
// MessageId: ERROR_WRONG_DISK
//
// MessageText:
//
// The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1.
//
#define ERROR_WRONG_DISK                 ((ULONG)0x00000022L)

//
// MessageId: ERROR_SHARING_BUFFER_EXCEEDED
//
// MessageText:
//
// Too many files opened for sharing.
//
#define ERROR_SHARING_BUFFER_EXCEEDED    ((ULONG)0x00000024L)

//
// MessageId: ERROR_HANDLE_EOF
//
// MessageText:
//
// Reached the end of the file.
//
#define ERROR_HANDLE_EOF                 ((ULONG)0x00000026L)

//
// MessageId: ERROR_HANDLE_DISK_FULL
//
// MessageText:
//
// The disk is full.
//
#define ERROR_HANDLE_DISK_FULL           ((ULONG)0x00000027L)

//
// MessageId: ERROR_NOT_SUPPORTED
//
// MessageText:
//
// The request is not supported.
//
#define ERROR_NOT_SUPPORTED              ((ULONG)0x00000032L)

//
// MessageId: ERROR_REM_NOT_LIST
//
// MessageText:
//
// ReactOS cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If ReactOS still cannot find the network path, contact your network administrator.
//
#define ERROR_REM_NOT_LIST               ((ULONG)0x00000033L)

//
// MessageId: ERROR_DUP_NAME
//
// MessageText:
//
// You were not connected because a duplicate name exists on the network. Go to System in the Control Panel to change the computer name and try again.
//
#define ERROR_DUP_NAME                   ((ULONG)0x00000034L)

//
// MessageId: ERROR_BAD_NETPATH
//
// MessageText:
//
// The network path was not found.
//
#define ERROR_BAD_NETPATH                ((ULONG)0x00000035L)

//
// MessageId: ERROR_NETWORK_BUSY
//
// MessageText:
//
// The network is busy.
//
#define ERROR_NETWORK_BUSY               ((ULONG)0x00000036L)

//
// MessageId: ERROR_DEV_NOT_EXIST
//
// MessageText:
//
// The specified network resource or device is no longer available.
//
#define ERROR_DEV_NOT_EXIST              ((ULONG)0x00000037L)

//
// MessageId: ERROR_TOO_MANY_CMDS
//
// MessageText:
//
// The network BIOS command limit has been reached.
//
#define ERROR_TOO_MANY_CMDS              ((ULONG)0x00000038L)

//
// MessageId: ERROR_ADAP_HDW_ERR
//
// MessageText:
//
// A network adapter hardware error occurred.
//
#define ERROR_ADAP_HDW_ERR               ((ULONG)0x00000039L)

//
// MessageId: ERROR_BAD_NET_RESP
//
// MessageText:
//
// The specified server cannot perform the requested operation.
//
#define ERROR_BAD_NET_RESP               ((ULONG)0x0000003AL)

//
// MessageId: ERROR_UNEXP_NET_ERR
//
// MessageText:
//
// An unexpected network error occurred.
//
#define ERROR_UNEXP_NET_ERR              ((ULONG)0x0000003BL)

//
// MessageId: ERROR_BAD_REM_ADAP
//
// MessageText:
//
// The remote adapter is not compatible.
//
#define ERROR_BAD_REM_ADAP               ((ULONG)0x0000003CL)

//
// MessageId: ERROR_PRINTQ_FULL
//
// MessageText:
//
// The printer queue is full.
//
#define ERROR_PRINTQ_FULL                ((ULONG)0x0000003DL)

//
// MessageId: ERROR_NO_SPOOL_SPACE
//
// MessageText:
//
// Space to store the file waiting to be printed is not available on the server.
//
#define ERROR_NO_SPOOL_SPACE             ((ULONG)0x0000003EL)

//
// MessageId: ERROR_PRINT_CANCELLED
//
// MessageText:
//
// Your file waiting to be printed was deleted.
//
#define ERROR_PRINT_CANCELLED            ((ULONG)0x0000003FL)

//
// MessageId: ERROR_NETNAME_DELETED
//
// MessageText:
//
// The specified network name is no longer available.
//
#define ERROR_NETNAME_DELETED            ((ULONG)0x00000040L)

//
// MessageId: ERROR_NETWORK_ACCESS_DENIED
//
// MessageText:
//
// Network access is denied.
//
#define ERROR_NETWORK_ACCESS_DENIED      ((ULONG)0x00000041L)

//
// MessageId: ERROR_BAD_DEV_TYPE
//
// MessageText:
//
// The network resource type is not correct.
//
#define ERROR_BAD_DEV_TYPE               ((ULONG)0x00000042L)

//
// MessageId: ERROR_BAD_NET_NAME
//
// MessageText:
//
// The network name cannot be found.
//
#define ERROR_BAD_NET_NAME               ((ULONG)0x00000043L)

//
// MessageId: ERROR_TOO_MANY_NAMES
//
// MessageText:
//
// The name limit for the local computer network adapter card was exceeded.
//
#define ERROR_TOO_MANY_NAMES             ((ULONG)0x00000044L)

//
// MessageId: ERROR_TOO_MANY_SESS
//
// MessageText:
//
// The network BIOS session limit was exceeded.
//
#define ERROR_TOO_MANY_SESS              ((ULONG)0x00000045L)

//
// MessageId: ERROR_SHARING_PAUSED
//
// MessageText:
//
// The remote server has been paused or is in the process of being started.
//
#define ERROR_SHARING_PAUSED             ((ULONG)0x00000046L)

//
// MessageId: ERROR_REQ_NOT_ACCEP
//
// MessageText:
//
// No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
//
#define ERROR_REQ_NOT_ACCEP              ((ULONG)0x00000047L)

//
// MessageId: ERROR_REDIR_PAUSED
//
// MessageText:
//
// The specified printer or disk device has been paused.
//
#define ERROR_REDIR_PAUSED               ((ULONG)0x00000048L)

//
// MessageId: ERROR_FILE_EXISTS
//
// MessageText:
//
// The file exists.
//
#define ERROR_FILE_EXISTS                ((ULONG)0x00000050L)

//
// MessageId: ERROR_CANNOT_MAKE
//
// MessageText:
//
// The directory or file cannot be created.
//
#define ERROR_CANNOT_MAKE                ((ULONG)0x00000052L)

//
// MessageId: ERROR_FAIL_I24
//
// MessageText:
//
// Fail on INT 24.
//
#define ERROR_FAIL_I24                   ((ULONG)0x00000053L)

//
// MessageId: ERROR_OUT_OF_STRUCTURES
//
// MessageText:
//
// Storage to process this request is not available.
//
#define ERROR_OUT_OF_STRUCTURES          ((ULONG)0x00000054L)

//
// MessageId: ERROR_ALREADY_ASSIGNED
//
// MessageText:
//
// The local device name is already in use.
//
#define ERROR_ALREADY_ASSIGNED           ((ULONG)0x00000055L)

//
// MessageId: ERROR_INVALID_PASSWORD
//
// MessageText:
//
// The specified network password is not correct.
//
#define ERROR_INVALID_PASSWORD           ((ULONG)0x00000056L)

//
// MessageId: ERROR_INVALID_PARAMETER
//
// MessageText:
//
// The parameter is incorrect.
//
#define ERROR_INVALID_PARAMETER          ((ULONG)0x00000057L)

//
// MessageId: ERROR_NET_WRITE_FAULT
//
// MessageText:
//
// A write fault occurred on the network.
//
#define ERROR_NET_WRITE_FAULT            ((ULONG)0x00000058L)

//
// MessageId: ERROR_NO_PROC_SLOTS
//
// MessageText:
//
// The system cannot start another process at this time.
//
#define ERROR_NO_PROC_SLOTS              ((ULONG)0x00000059L)

//
// MessageId: ERROR_TOO_MANY_SEMAPHORES
//
// MessageText:
//
// Cannot create another system semaphore.
//
#define ERROR_TOO_MANY_SEMAPHORES        ((ULONG)0x00000064L)

//
// MessageId: ERROR_EXCL_SEM_ALREADY_OWNED
//
// MessageText:
//
// The exclusive semaphore is owned by another process.
//
#define ERROR_EXCL_SEM_ALREADY_OWNED     ((ULONG)0x00000065L)

//
// MessageId: ERROR_SEM_IS_SET
//
// MessageText:
//
// The semaphore is set and cannot be closed.
//
#define ERROR_SEM_IS_SET                 ((ULONG)0x00000066L)

//
// MessageId: ERROR_TOO_MANY_SEM_REQUESTS
//
// MessageText:
//
// The semaphore cannot be set again.
//
#define ERROR_TOO_MANY_SEM_REQUESTS      ((ULONG)0x00000067L)

//
// MessageId: ERROR_INVALID_AT_INTERRUPT_TIME
//
// MessageText:
//
// Cannot request exclusive semaphores at interrupt time.
//
#define ERROR_INVALID_AT_INTERRUPT_TIME  ((ULONG)0x00000068L)

//
// MessageId: ERROR_SEM_OWNER_DIED
//
// MessageText:
//
// The previous ownership of this semaphore has ended.
//
#define ERROR_SEM_OWNER_DIED             ((ULONG)0x00000069L)

//
// MessageId: ERROR_SEM_USER_LIMIT
//
// MessageText:
//
// Insert the diskette for drive %1.
//
#define ERROR_SEM_USER_LIMIT             ((ULONG)0x0000006AL)

//
// MessageId: ERROR_DISK_CHANGE
//
// MessageText:
//
// The program stopped because an alternate diskette was not inserted.
//
#define ERROR_DISK_CHANGE                ((ULONG)0x0000006BL)

//
// MessageId: ERROR_DRIVE_LOCKED
//
// MessageText:
//
// The disk is in use or locked by another process.
//
#define ERROR_DRIVE_LOCKED               ((ULONG)0x0000006CL)

//
// MessageId: ERROR_BROKEN_PIPE
//
// MessageText:
//
// The pipe has been ended.
//
#define ERROR_BROKEN_PIPE                ((ULONG)0x0000006DL)

//
// MessageId: ERROR_OPEN_FAILED
//
// MessageText:
//
// The system cannot open the device or file specified.
//
#define ERROR_OPEN_FAILED                ((ULONG)0x0000006EL)

//
// MessageId: ERROR_BUFFER_OVERFLOW
//
// MessageText:
//
// The file name is too long.
//
#define ERROR_BUFFER_OVERFLOW            ((ULONG)0x0000006FL)

//
// MessageId: ERROR_DISK_FULL
//
// MessageText:
//
// There is not enough space on the disk.
//
#define ERROR_DISK_FULL                  ((ULONG)0x00000070L)

//
// MessageId: ERROR_NO_MORE_SEARCH_HANDLES
//
// MessageText:
//
// No more internal file identifiers available.
//
#define ERROR_NO_MORE_SEARCH_HANDLES     ((ULONG)0x00000071L)

//
// MessageId: ERROR_INVALID_TARGET_HANDLE
//
// MessageText:
//
// The target internal file identifier is incorrect.
//
#define ERROR_INVALID_TARGET_HANDLE      ((ULONG)0x00000072L)

//
// MessageId: ERROR_INVALID_CATEGORY
//
// MessageText:
//
// The IOCTL call made by the application program is not correct.
//
#define ERROR_INVALID_CATEGORY           ((ULONG)0x00000075L)

//
// MessageId: ERROR_INVALID_VERIFY_SWITCH
//
// MessageText:
//
// The verify-on-write switch parameter value is not correct.
//
#define ERROR_INVALID_VERIFY_SWITCH      ((ULONG)0x00000076L)

//
// MessageId: ERROR_BAD_DRIVER_LEVEL
//
// MessageText:
//
// The system does not support the command requested.
//
#define ERROR_BAD_DRIVER_LEVEL           ((ULONG)0x00000077L)

//
// MessageId: ERROR_CALL_NOT_IMPLEMENTED
//
// MessageText:
//
// This function is not supported on this system.
//
#define ERROR_CALL_NOT_IMPLEMENTED       ((ULONG)0x00000078L)

//
// MessageId: ERROR_SEM_TIMEOUT
//
// MessageText:
//
// The semaphore timeout period has expired.
//
#define ERROR_SEM_TIMEOUT                ((ULONG)0x00000079L)

//
// MessageId: ERROR_INSUFFICIENT_BUFFER
//
// MessageText:
//
// The data area passed to a system call is too small.
//
#define ERROR_INSUFFICIENT_BUFFER        ((ULONG)0x0000007AL)

//
// MessageId: ERROR_INVALID_NAME
//
// MessageText:
//
// The filename, directory name, or volume label syntax is incorrect.
//
#define ERROR_INVALID_NAME               ((ULONG)0x0000007BL)

//
// MessageId: ERROR_INVALID_LEVEL
//
// MessageText:
//
// The system call level is not correct.
//
#define ERROR_INVALID_LEVEL              ((ULONG)0x0000007CL)

//
// MessageId: ERROR_NO_VOLUME_LABEL
//
// MessageText:
//
// The disk has no volume label.
//
#define ERROR_NO_VOLUME_LABEL            ((ULONG)0x0000007DL)

//
// MessageId: ERROR_MOD_NOT_FOUND
//
// MessageText:
//
// The specified module could not be found.
//
#define ERROR_MOD_NOT_FOUND              ((ULONG)0x0000007EL)

//
// MessageId: ERROR_PROC_NOT_FOUND
//
// MessageText:
//
// The specified procedure could not be found.
//
#define ERROR_PROC_NOT_FOUND             ((ULONG)0x0000007FL)

//
// MessageId: ERROR_WAIT_NO_CHILDREN
//
// MessageText:
//
// There are no child processes to wait for.
//
#define ERROR_WAIT_NO_CHILDREN           ((ULONG)0x00000080L)

//
// MessageId: ERROR_CHILD_NOT_COMPLETE
//
// MessageText:
//
// The %1 application cannot be run in Win32 mode.
//
#define ERROR_CHILD_NOT_COMPLETE         ((ULONG)0x00000081L)

//
// MessageId: ERROR_DIRECT_ACCESS_HANDLE
//
// MessageText:
//
// Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
//
#define ERROR_DIRECT_ACCESS_HANDLE       ((ULONG)0x00000082L)

//
// MessageId: ERROR_NEGATIVE_SEEK
//
// MessageText:
//
// An attempt was made to move the file pointer before the beginning of the file.
//
#define ERROR_NEGATIVE_SEEK              ((ULONG)0x00000083L)

//
// MessageId: ERROR_SEEK_ON_DEVICE
//
// MessageText:
//
// The file pointer cannot be set on the specified device or file.
//
#define ERROR_SEEK_ON_DEVICE             ((ULONG)0x00000084L)

//
// MessageId: ERROR_IS_JOIN_TARGET
//
// MessageText:
//
// A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
//
#define ERROR_IS_JOIN_TARGET             ((ULONG)0x00000085L)

//
// MessageId: ERROR_IS_JOINED
//
// MessageText:
//
// An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
//
#define ERROR_IS_JOINED                  ((ULONG)0x00000086L)

//
// MessageId: ERROR_IS_SUBSTED
//
// MessageText:
//
// An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
//
#define ERROR_IS_SUBSTED                 ((ULONG)0x00000087L)

//
// MessageId: ERROR_NOT_JOINED
//
// MessageText:
//
// The system tried to delete the JOIN of a drive that is not joined.
//
#define ERROR_NOT_JOINED                 ((ULONG)0x00000088L)

//
// MessageId: ERROR_NOT_SUBSTED
//
// MessageText:
//
// The system tried to delete the substitution of a drive that is not substituted.
//
#define ERROR_NOT_SUBSTED                ((ULONG)0x00000089L)

//
// MessageId: ERROR_JOIN_TO_JOIN
//
// MessageText:
//
// The system tried to join a drive to a directory on a joined drive.
//
#define ERROR_JOIN_TO_JOIN               ((ULONG)0x0000008AL)

//
// MessageId: ERROR_SUBST_TO_SUBST
//
// MessageText:
//
// The system tried to substitute a drive to a directory on a substituted drive.
//
#define ERROR_SUBST_TO_SUBST             ((ULONG)0x0000008BL)

//
// MessageId: ERROR_JOIN_TO_SUBST
//
// MessageText:
//
// The system tried to join a drive to a directory on a substituted drive.
//
#define ERROR_JOIN_TO_SUBST              ((ULONG)0x0000008CL)

//
// MessageId: ERROR_SUBST_TO_JOIN
//
// MessageText:
//
// The system tried to SUBST a drive to a directory on a joined drive.
//
#define ERROR_SUBST_TO_JOIN              ((ULONG)0x0000008DL)

//
// MessageId: ERROR_BUSY_DRIVE
//
// MessageText:
//
// The system cannot perform a JOIN or SUBST at this time.
//
#define ERROR_BUSY_DRIVE                 ((ULONG)0x0000008EL)

//
// MessageId: ERROR_SAME_DRIVE
//
// MessageText:
//
// The system cannot join or substitute a drive to or for a directory on the same drive.
//
#define ERROR_SAME_DRIVE                 ((ULONG)0x0000008FL)

//
// MessageId: ERROR_DIR_NOT_ROOT
//
// MessageText:
//
// The directory is not a subdirectory of the root directory.
//
#define ERROR_DIR_NOT_ROOT               ((ULONG)0x00000090L)

//
// MessageId: ERROR_DIR_NOT_EMPTY
//
// MessageText:
//
// The directory is not empty.
//
#define ERROR_DIR_NOT_EMPTY              ((ULONG)0x00000091L)

//
// MessageId: ERROR_IS_SUBST_PATH
//
// MessageText:
//
// The path specified is being used in a substitute.
//
#define ERROR_IS_SUBST_PATH              ((ULONG)0x00000092L)

//
// MessageId: ERROR_IS_JOIN_PATH
//
// MessageText:
//
// Not enough resources are available to process this command.
//
#define ERROR_IS_JOIN_PATH               ((ULONG)0x00000093L)

//
// MessageId: ERROR_PATH_BUSY
//
// MessageText:
//
// The path specified cannot be used at this time.
//
#define ERROR_PATH_BUSY                  ((ULONG)0x00000094L)

//
// MessageId: ERROR_IS_SUBST_TARGET
//
// MessageText:
//
// An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
//
#define ERROR_IS_SUBST_TARGET            ((ULONG)0x00000095L)

//
// MessageId: ERROR_SYSTEM_TRACE
//
// MessageText:
//
// System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
//
#define ERROR_SYSTEM_TRACE               ((ULONG)0x00000096L)

//
// MessageId: ERROR_INVALID_EVENT_COUNT
//
// MessageText:
//
// The number of specified semaphore events for DosMuxSemWait is not correct.
//
#define ERROR_INVALID_EVENT_COUNT        ((ULONG)0x00000097L)

//
// MessageId: ERROR_TOO_MANY_MUXWAITERS
//
// MessageText:
//
// DosMuxSemWait did not execute; too many semaphores are already set.
//
#define ERROR_TOO_MANY_MUXWAITERS        ((ULONG)0x00000098L)

//
// MessageId: ERROR_INVALID_LIST_FORMAT
//
// MessageText:
//
// The DosMuxSemWait list is not correct.
//
#define ERROR_INVALID_LIST_FORMAT        ((ULONG)0x00000099L)

//
// MessageId: ERROR_LABEL_TOO_LONG
//
// MessageText:
//
// The volume label you entered exceeds the label character limit of the target file system.
//
#define ERROR_LABEL_TOO_LONG             ((ULONG)0x0000009AL)

//
// MessageId: ERROR_TOO_MANY_TCBS
//
// MessageText:
//
// Cannot create another thread.
//
#define ERROR_TOO_MANY_TCBS              ((ULONG)0x0000009BL)

//
// MessageId: ERROR_SIGNAL_REFUSED
//
// MessageText:
//
// The recipient process has refused the signal.
//
#define ERROR_SIGNAL_REFUSED             ((ULONG)0x0000009CL)

//
// MessageId: ERROR_DISCARDED
//
// MessageText:
//
// The segment is already discarded and cannot be locked.
//
#define ERROR_DISCARDED                  ((ULONG)0x0000009DL)

//
// MessageId: ERROR_NOT_LOCKED
//
// MessageText:
//
// The segment is already unlocked.
//
#define ERROR_NOT_LOCKED                 ((ULONG)0x0000009EL)

//
// MessageId: ERROR_BAD_THREADID_ADDR
//
// MessageText:
//
// The address for the thread ID is not correct.
//
#define ERROR_BAD_THREADID_ADDR          ((ULONG)0x0000009FL)

//
// MessageId: ERROR_BAD_ARGUMENTS
//
// MessageText:
//
// The argument string passed to DosExecPgm is not correct.
//
#define ERROR_BAD_ARGUMENTS              ((ULONG)0x000000A0L)

//
// MessageId: ERROR_BAD_PATHNAME
//
// MessageText:
//
// The specified path is invalid.
//
#define ERROR_BAD_PATHNAME               ((ULONG)0x000000A1L)

//
// MessageId: ERROR_SIGNAL_PENDING
//
// MessageText:
//
// A signal is already pending.
//
#define ERROR_SIGNAL_PENDING             ((ULONG)0x000000A2L)

//
// MessageId: ERROR_MAX_THRDS_REACHED
//
// MessageText:
//
// No more threads can be created in the system.
//
#define ERROR_MAX_THRDS_REACHED          ((ULONG)0x000000A4L)

//
// MessageId: ERROR_LOCK_FAILED
//
// MessageText:
//
// Unable to lock a region of a file.
//
#define ERROR_LOCK_FAILED                ((ULONG)0x000000A7L)

//
// MessageId: ERROR_BUSY
//
// MessageText:
//
// The requested resource is in use.
//
#define ERROR_BUSY                       ((ULONG)0x000000AAL)

//
// MessageId: ERROR_CANCEL_VIOLATION
//
// MessageText:
//
// A lock request was not outstanding for the supplied cancel region.
//
#define ERROR_CANCEL_VIOLATION           ((ULONG)0x000000ADL)

//
// MessageId: ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
//
// MessageText:
//
// The file system does not support atomic changes to the lock type.
//
#define ERROR_ATOMIC_LOCKS_NOT_SUPPORTED ((ULONG)0x000000AEL)

//
// MessageId: ERROR_INVALID_SEGMENT_NUMBER
//
// MessageText:
//
// The system detected a segment number that was not correct.
//
#define ERROR_INVALID_SEGMENT_NUMBER     ((ULONG)0x000000B4L)

//
// MessageId: ERROR_INVALID_ORDINAL
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_ORDINAL            ((ULONG)0x000000B6L)

//
// MessageId: ERROR_ALREADY_EXISTS
//
// MessageText:
//
// Cannot create a file when that file already exists.
//
#define ERROR_ALREADY_EXISTS             ((ULONG)0x000000B7L)

//
// MessageId: ERROR_INVALID_FLAG_NUMBER
//
// MessageText:
//
// The flag passed is not correct.
//
#define ERROR_INVALID_FLAG_NUMBER        ((ULONG)0x000000BAL)

//
// MessageId: ERROR_SEM_NOT_FOUND
//
// MessageText:
//
// The specified system semaphore name was not found.
//
#define ERROR_SEM_NOT_FOUND              ((ULONG)0x000000BBL)

//
// MessageId: ERROR_INVALID_STARTING_CODESEG
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_STARTING_CODESEG   ((ULONG)0x000000BCL)

//
// MessageId: ERROR_INVALID_STACKSEG
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_STACKSEG           ((ULONG)0x000000BDL)

//
// MessageId: ERROR_INVALID_MODULETYPE
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_MODULETYPE         ((ULONG)0x000000BEL)

//
// MessageId: ERROR_INVALID_EXE_SIGNATURE
//
// MessageText:
//
// Cannot run %1 in Win32 mode.
//
#define ERROR_INVALID_EXE_SIGNATURE      ((ULONG)0x000000BFL)

//
// MessageId: ERROR_EXE_MARKED_INVALID
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_EXE_MARKED_INVALID         ((ULONG)0x000000C0L)

//
// MessageId: ERROR_BAD_EXE_FORMAT
//
// MessageText:
//
// %1 is not a valid Win32 application.
//
#define ERROR_BAD_EXE_FORMAT             ((ULONG)0x000000C1L)

//
// MessageId: ERROR_ITERATED_DATA_EXCEEDS_64k
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_ITERATED_DATA_EXCEEDS_64k  ((ULONG)0x000000C2L)

//
// MessageId: ERROR_INVALID_MINALLOCSIZE
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_MINALLOCSIZE       ((ULONG)0x000000C3L)

//
// MessageId: ERROR_DYNLINK_FROM_INVALID_RING
//
// MessageText:
//
// The operating system cannot run this application program.
//
#define ERROR_DYNLINK_FROM_INVALID_RING  ((ULONG)0x000000C4L)

//
// MessageId: ERROR_IOPL_NOT_ENABLED
//
// MessageText:
//
// The operating system is not presently configured to run this application.
//
#define ERROR_IOPL_NOT_ENABLED           ((ULONG)0x000000C5L)

//
// MessageId: ERROR_INVALID_SEGDPL
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INVALID_SEGDPL             ((ULONG)0x000000C6L)

//
// MessageId: ERROR_AUTODATASEG_EXCEEDS_64k
//
// MessageText:
//
// The operating system cannot run this application program.
//
#define ERROR_AUTODATASEG_EXCEEDS_64k    ((ULONG)0x000000C7L)

//
// MessageId: ERROR_RING2SEG_MUST_BE_MOVABLE
//
// MessageText:
//
// The code segment cannot be greater than or equal to 64K.
//
#define ERROR_RING2SEG_MUST_BE_MOVABLE   ((ULONG)0x000000C8L)

//
// MessageId: ERROR_RELOC_CHAIN_XEEDS_SEGLIM
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_RELOC_CHAIN_XEEDS_SEGLIM   ((ULONG)0x000000C9L)

//
// MessageId: ERROR_INFLOOP_IN_RELOC_CHAIN
//
// MessageText:
//
// The operating system cannot run %1.
//
#define ERROR_INFLOOP_IN_RELOC_CHAIN     ((ULONG)0x000000CAL)

//
// MessageId: ERROR_ENVVAR_NOT_FOUND
//
// MessageText:
//
// The system could not find the environment option that was entered.
//
#define ERROR_ENVVAR_NOT_FOUND           ((ULONG)0x000000CBL)

//
// MessageId: ERROR_NO_SIGNAL_SENT
//
// MessageText:
//
// No process in the command subtree has a signal handler.
//
#define ERROR_NO_SIGNAL_SENT             ((ULONG)0x000000CDL)

//
// MessageId: ERROR_FILENAME_EXCED_RANGE
//
// MessageText:
//
// The filename or extension is too long.
//
#define ERROR_FILENAME_EXCED_RANGE       ((ULONG)0x000000CEL)

//
// MessageId: ERROR_RING2_STACK_IN_USE
//
// MessageText:
//
// The ring 2 stack is in use.
//
#define ERROR_RING2_STACK_IN_USE         ((ULONG)0x000000CFL)

//
// MessageId: ERROR_META_EXPANSION_TOO_LONG
//
// MessageText:
//
// The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
//
#define ERROR_META_EXPANSION_TOO_LONG    ((ULONG)0x000000D0L)

//
// MessageId: ERROR_INVALID_SIGNAL_NUMBER
//
// MessageText:
//
// The signal being posted is not correct.
//
#define ERROR_INVALID_SIGNAL_NUMBER      ((ULONG)0x000000D1L)

//
// MessageId: ERROR_THREAD_1_INACTIVE
//
// MessageText:
//
// The signal handler cannot be set.
//
#define ERROR_THREAD_1_INACTIVE          ((ULONG)0x000000D2L)

//
// MessageId: ERROR_LOCKED
//
// MessageText:
//
// The segment is locked and cannot be reallocated.
//
#define ERROR_LOCKED                     ((ULONG)0x000000D4L)

//
// MessageId: ERROR_TOO_MANY_MODULES
//
// MessageText:
//
// Too many dynamic-link modules are attached to this program or dynamic-link module.
//
#define ERROR_TOO_MANY_MODULES           ((ULONG)0x000000D6L)

//
// MessageId: ERROR_NESTING_NOT_ALLOWED
//
// MessageText:
//
// Cannot nest calls to LoadModule.
//
#define ERROR_NESTING_NOT_ALLOWED        ((ULONG)0x000000D7L)

//
// MessageId: ERROR_EXE_MACHINE_TYPE_MISMATCH
//
// MessageText:
//
// The image file %1 is valid, but is for a machine type other than the current machine.
//
#define ERROR_EXE_MACHINE_TYPE_MISMATCH  ((ULONG)0x000000D8L)

//
// MessageId: ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
//
// MessageText:
//
// The image file %1 is signed, unable to modify.
//
#define ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY ((ULONG)0x000000D9L)

//
// MessageId: ERRO_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
//
// MessageText:
//
// The image file %1 is strong signed, unable to modify.
//
#define ERRO_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY ((ULONG)0x000000DAL)

//
// MessageId: ERROR_BAD_PIPE
//
// MessageText:
//
// The pipe state is invalid.
//
#define ERROR_BAD_PIPE                   ((ULONG)0x000000E6L)

//
// MessageId: ERROR_PIPE_BUSY
//
// MessageText:
//
// All pipe instances are busy.
//
#define ERROR_PIPE_BUSY                  ((ULONG)0x000000E7L)

//
// MessageId: ERROR_NO_DATA
//
// MessageText:
//
// The pipe is being closed.
//
#define ERROR_NO_DATA                    ((ULONG)0x000000E8L)

//
// MessageId: ERROR_PIPE_NOT_CONNECTED
//
// MessageText:
//
// No process is on the other end of the pipe.
//
#define ERROR_PIPE_NOT_CONNECTED         ((ULONG)0x000000E9L)

//
// MessageId: ERROR_MORE_DATA
//
// MessageText:
//
// More data is available.
//
#define ERROR_MORE_DATA                  ((ULONG)0x000000EAL)

//
// MessageId: ERROR_VC_DISCONNECTED
//
// MessageText:
//
// The session was canceled.
//
#define ERROR_VC_DISCONNECTED            ((ULONG)0x000000F0L)

//
// MessageId: ERROR_INVALID_EA_NAME
//
// MessageText:
//
// The specified extended attribute name was invalid.
//
#define ERROR_INVALID_EA_NAME            ((ULONG)0x000000FEL)

//
// MessageId: ERROR_EA_LIST_INCONSISTENT
//
// MessageText:
//
// The extended attributes are inconsistent.
//
#define ERROR_EA_LIST_INCONSISTENT       ((ULONG)0x000000FFL)

//
// MessageId: WAIT_TIMEOUT
//
// MessageText:
//
// The wait operation timed out.
//
#define WAIT_TIMEOUT                     ((ULONG)0x00000102L)

//
// MessageId: ERROR_NO_MORE_ITEMS
//
// MessageText:
//
// No more data is available.
//
#define ERROR_NO_MORE_ITEMS              ((ULONG)0x00000103L)

//
// MessageId: ERROR_CANNOT_COPY
//
// MessageText:
//
// The copy functions cannot be used.
//
#define ERROR_CANNOT_COPY                ((ULONG)0x0000010AL)

//
// MessageId: ERROR_DIRECTORY
//
// MessageText:
//
// The directory name is invalid.
//
#define ERROR_DIRECTORY                  ((ULONG)0x0000010BL)

//
// MessageId: ERROR_EAS_DIDNT_FIT
//
// MessageText:
//
// The extended attributes did not fit in the buffer.
//
#define ERROR_EAS_DIDNT_FIT              ((ULONG)0x00000113L)

//
// MessageId: ERROR_EA_FILE_CORRUPT
//
// MessageText:
//
// The extended attribute file on the mounted file system is corrupt.
//
#define ERROR_EA_FILE_CORRUPT            ((ULONG)0x00000114L)

//
// MessageId: ERROR_EA_TABLE_FULL
//
// MessageText:
//
// The extended attribute table file is full.
//
#define ERROR_EA_TABLE_FULL              ((ULONG)0x00000115L)

//
// MessageId: ERROR_INVALID_EA_HANDLE
//
// MessageText:
//
// The specified extended attribute handle is invalid.
//
#define ERROR_INVALID_EA_HANDLE          ((ULONG)0x00000116L)

//
// MessageId: ERROR_EAS_NOT_SUPPORTED
//
// MessageText:
//
// The mounted file system does not support extended attributes.
//
#define ERROR_EAS_NOT_SUPPORTED          ((ULONG)0x0000011AL)

//
// MessageId: ERROR_NOT_OWNER
//
// MessageText:
//
// Attempt to release mutex not owned by caller.
//
#define ERROR_NOT_OWNER                  ((ULONG)0x00000120L)

//
// MessageId: ERROR_TOO_MANY_POSTS
//
// MessageText:
//
// Too many posts were made to a semaphore.
//
#define ERROR_TOO_MANY_POSTS             ((ULONG)0x0000012AL)

//
// MessageId: ERROR_PARTIAL_COPY
//
// MessageText:
//
// Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
//
#define ERROR_PARTIAL_COPY               ((ULONG)0x0000012BL)

//
// MessageId: ERROR_OPLOCK_NOT_GRANTED
//
// MessageText:
//
// The oplock request is denied.
//
#define ERROR_OPLOCK_NOT_GRANTED         ((ULONG)0x0000012CL)

//
// MessageId: ERROR_INVALID_OPLOCK_PROTOCOL
//
// MessageText:
//
// An invalid oplock acknowledgment was received by the system.
//
#define ERROR_INVALID_OPLOCK_PROTOCOL    ((ULONG)0x0000012DL)

//
// MessageId: ERROR_DISK_TOO_FRAGMENTED
//
// MessageText:
//
// The volume is too fragmented to complete this operation.
//
#define ERROR_DISK_TOO_FRAGMENTED        ((ULONG)0x0000012EL)

//
// MessageId: ERROR_DELETE_PENDING
//
// MessageText:
//
// The file cannot be opened because it is in the process of being deleted.
//
#define ERROR_DELETE_PENDING             ((ULONG)0x0000012FL)

//
// MessageId: ERROR_MR_MID_NOT_FOUND
//
// MessageText:
//
// The system cannot find message text for message number 0x%1 in the message file for %2.
//
#define ERROR_MR_MID_NOT_FOUND           ((ULONG)0x0000013DL)

//
// MessageId: ERROR_SCOPE_NOT_FOUND
//
// MessageText:
//
// The scope specified was not found.
//
#define ERROR_SCOPE_NOT_FOUND            ((ULONG)0x0000013EL)

//
// MessageId: ERROR_INVALID_ADDRESS
//
// MessageText:
//
// Attempt to access invalid address.
//
#define ERROR_INVALID_ADDRESS            ((ULONG)0x000001E7L)

//
// MessageId: ERROR_ARITHMETIC_OVERFLOW
//
// MessageText:
//
// Arithmetic result exceeded 32 bits.
//
#define ERROR_ARITHMETIC_OVERFLOW        ((ULONG)0x00000216L)

//
// MessageId: ERROR_PIPE_CONNECTED
//
// MessageText:
//
// There is a process on other end of the pipe.
//
#define ERROR_PIPE_CONNECTED             ((ULONG)0x00000217L)

//
// MessageId: ERROR_PIPE_LISTENING
//
// MessageText:
//
// Waiting for a process to open the other end of the pipe.
//
#define ERROR_PIPE_LISTENING             ((ULONG)0x00000218L)

//
// MessageId: ERROR_ACPI_ERROR
//
// MessageText:
//
// An error occurred in the ACPI subsystem.
//
#define ERROR_ACPI_ERROR                 ((ULONG)0x00000219L)

//
// MessageId: ERROR_ABIOS_ERROR
//
// MessageText:
//
// An error occurred in the ABIOS subsystem
//
#define ERROR_ABIOS_ERROR                ((ULONG)0x0000021AL)

//
// MessageId: ERROR_WX86_WARNING
//
// MessageText:
//
// A warning occurred in the WX86 subsystem.
//
#define ERROR_WX86_WARNING               ((ULONG)0x0000021BL)

//
// MessageId: ERROR_WX86_ERROR
//
// MessageText:
//
// An error occurred in the WX86 subsystem.
//
#define ERROR_WX86_ERROR                 ((ULONG)0x0000021CL)

//
// MessageId: ERROR_TIMER_NOT_CANCELED
//
// MessageText:
//
// An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
//
#define ERROR_TIMER_NOT_CANCELED         ((ULONG)0x0000021DL)

//
// MessageId: ERROR_UNWIND
//
// MessageText:
//
// Unwind exception code.
//
#define ERROR_UNWIND                     ((ULONG)0x0000021EL)

//
// MessageId: ERROR_BAD_STACK
//
// MessageText:
//
// An invalid or unaligned stack was encountered during an unwind operation.
//
#define ERROR_BAD_STACK                  ((ULONG)0x0000021FL)

//
// MessageId: ERROR_INVALID_UNWIND_TARGET
//
// MessageText:
//
// An invalid unwind target was encountered during an unwind operation.
//
#define ERROR_INVALID_UNWIND_TARGET      ((ULONG)0x00000220L)

//
// MessageId: ERROR_INVALID_PORT_ATTRIBUTES
//
// MessageText:
//
// Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
//
#define ERROR_INVALID_PORT_ATTRIBUTES    ((ULONG)0x00000221L)

//
// MessageId: ERROR_PORT_MESSAGE_TOO_LONG
//
// MessageText:
//
// Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
//
#define ERROR_PORT_MESSAGE_TOO_LONG      ((ULONG)0x00000222L)

//
// MessageId: ERROR_INVALID_QUOTA_LOWER
//
// MessageText:
//
// An attempt was made to lower a quota limit below the current usage.
//
#define ERROR_INVALID_QUOTA_LOWER        ((ULONG)0x00000223L)

//
// MessageId: ERROR_DEVICE_ALREADY_ATTACHED
//
// MessageText:
//
// An attempt was made to attach to a device that was already attached to another device.
//
#define ERROR_DEVICE_ALREADY_ATTACHED    ((ULONG)0x00000224L)

//
// MessageId: ERROR_INSTRUCTION_MISALIGNMENT
//
// MessageText:
//
// An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
//
#define ERROR_INSTRUCTION_MISALIGNMENT   ((ULONG)0x00000225L)

//
// MessageId: ERROR_PROFILING_NOT_STARTED
//
// MessageText:
//
// Profiling not started.
//
#define ERROR_PROFILING_NOT_STARTED      ((ULONG)0x00000226L)

//
// MessageId: ERROR_PROFILING_NOT_STOPPED
//
// MessageText:
//
// Profiling not stopped.
//
#define ERROR_PROFILING_NOT_STOPPED      ((ULONG)0x00000227L)

//
// MessageId: ERROR_COULD_NOT_INTERPRET
//
// MessageText:
//
// The passed ACL did not contain the minimum required information.
//
#define ERROR_COULD_NOT_INTERPRET        ((ULONG)0x00000228L)

//
// MessageId: ERROR_PROFILING_AT_LIMIT
//
// MessageText:
//
// The number of active profiling objects is at the maximum and no more may be started.
//
#define ERROR_PROFILING_AT_LIMIT         ((ULONG)0x00000229L)

//
// MessageId: ERROR_CANT_WAIT
//
// MessageText:
//
// Used to indicate that an operation cannot continue without blocking for I/O.
//
#define ERROR_CANT_WAIT                  ((ULONG)0x0000022AL)

//
// MessageId: ERROR_CANT_TERMINATE_SELF
//
// MessageText:
//
// Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
//
#define ERROR_CANT_TERMINATE_SELF        ((ULONG)0x0000022BL)

//
// MessageId: ERROR_UNEXPECTED_MM_CREATE_ERR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_CREATE_ERR   ((ULONG)0x0000022CL)

//
// MessageId: ERROR_UNEXPECTED_MM_MAP_ERROR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_MAP_ERROR    ((ULONG)0x0000022DL)

//
// MessageId: ERROR_UNEXPECTED_MM_EXTEND_ERR
//
// MessageText:
//
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
//
#define ERROR_UNEXPECTED_MM_EXTEND_ERR   ((ULONG)0x0000022EL)

//
// MessageId: ERROR_BAD_FUNCTION_TABLE
//
// MessageText:
//
// A malformed function table was encountered during an unwind operation.
//
#define ERROR_BAD_FUNCTION_TABLE         ((ULONG)0x0000022FL)

//
// MessageId: ERROR_NO_GUID_TRANSLATION
//
// MessageText:
//
// Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system. This causes the protection attempt to fail, which may cause a file creation attempt to fail.
//
#define ERROR_NO_GUID_TRANSLATION        ((ULONG)0x00000230L)

//
// MessageId: ERROR_INVALID_LDT_SIZE
//
// MessageText:
//
// Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
//
#define ERROR_INVALID_LDT_SIZE           ((ULONG)0x00000231L)

//
// MessageId: ERROR_INVALID_LDT_OFFSET
//
// MessageText:
//
// Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
//
#define ERROR_INVALID_LDT_OFFSET         ((ULONG)0x00000233L)

//
// MessageId: ERROR_INVALID_LDT_DESCRIPTOR
//
// MessageText:
//
// Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
//
#define ERROR_INVALID_LDT_DESCRIPTOR     ((ULONG)0x00000234L)

//
// MessageId: ERROR_TOO_MANY_THREADS
//
// MessageText:
//
// Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
//
#define ERROR_TOO_MANY_THREADS           ((ULONG)0x00000235L)

//
// MessageId: ERROR_THREAD_NOT_IN_PROCESS
//
// MessageText:
//
// An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
//
#define ERROR_THREAD_NOT_IN_PROCESS      ((ULONG)0x00000236L)

//
// MessageId: ERROR_PAGEFILE_QUOTA_EXCEEDED
//
// MessageText:
//
// Page file quota was exceeded.
//
#define ERROR_PAGEFILE_QUOTA_EXCEEDED    ((ULONG)0x00000237L)

//
// MessageId: ERROR_LOGON_SERVER_CONFLICT
//
// MessageText:
//
// The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
//
#define ERROR_LOGON_SERVER_CONFLICT      ((ULONG)0x00000238L)

//
// MessageId: ERROR_SYNCHRONIZATION_REQUIRED
//
// MessageText:
//
// The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
//
#define ERROR_SYNCHRONIZATION_REQUIRED   ((ULONG)0x00000239L)

//
// MessageId: ERROR_NET_OPEN_FAILED
//
// MessageText:
//
// The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
//
#define ERROR_NET_OPEN_FAILED            ((ULONG)0x0000023AL)

//
// MessageId: ERROR_IO_PRIVILEGE_FAILED
//
// MessageText:
//
// The I/O permissions for the process could not be changed.
//
#define ERROR_IO_PRIVILEGE_FAILED        ((ULONG)0x0000023BL)

//
// MessageId: ERROR_CONTROL_C_EXIT
//
// MessageText:
//
// The application terminated as a result of a CTRL+C.
//
#define ERROR_CONTROL_C_EXIT             ((ULONG)0x0000023CL)

//
// MessageId: ERROR_MISSING_SYSTEMFILE
//
// MessageText:
//
// The required system file %hs is bad or missing.
//
#define ERROR_MISSING_SYSTEMFILE         ((ULONG)0x0000023DL)

//
// MessageId: ERROR_UNHANDLED_EXCEPTION
//
// MessageText:
//
// The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
//
#define ERROR_UNHANDLED_EXCEPTION        ((ULONG)0x0000023EL)

//
// MessageId: ERROR_APP_INIT_FAILURE
//
// MessageText:
//
// The application failed to initialize properly (0x%lx). Click on OK to terminate the application.
//
#define ERROR_APP_INIT_FAILURE           ((ULONG)0x0000023FL)

//
// MessageId: ERROR_PAGEFILE_CREATE_FAILED
//
// MessageText:
//
// The creation of the paging file %hs failed (%lx). The requested size was %ld.
//
#define ERROR_PAGEFILE_CREATE_FAILED     ((ULONG)0x00000240L)

//
// MessageId: ERROR_NO_PAGEFILE
//
// MessageText:
//
// No paging file was specified in the system configuration.
//
#define ERROR_NO_PAGEFILE                ((ULONG)0x00000242L)

//
// MessageId: ERROR_ILLEGAL_FLOAT_CONTEXT
//
// MessageText:
//
// A real-mode application issued a floating-point instruction and floating-point hardware is not present.
//
#define ERROR_ILLEGAL_FLOAT_CONTEXT      ((ULONG)0x00000243L)

//
// MessageId: ERROR_NO_EVENT_PAIR
//
// MessageText:
//
// An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
//
#define ERROR_NO_EVENT_PAIR              ((ULONG)0x00000244L)

//
// MessageId: ERROR_DOMAIN_CTRLR_CONFIG_ERROR
//
// MessageText:
//
// A Windows Server has an incorrect configuration.
//
#define ERROR_DOMAIN_CTRLR_CONFIG_ERROR  ((ULONG)0x00000245L)

//
// MessageId: ERROR_ILLEGAL_CHARACTER
//
// MessageText:
//
// An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
//
#define ERROR_ILLEGAL_CHARACTER          ((ULONG)0x00000246L)

//
// MessageId: ERROR_UNDEFINED_CHARACTER
//
// MessageText:
//
// The Unicode character is not defined in the Unicode character set installed on the system.
//
#define ERROR_UNDEFINED_CHARACTER        ((ULONG)0x00000247L)

//
// MessageId: ERROR_FLOPPY_VOLUME
//
// MessageText:
//
// The paging file cannot be created on a floppy diskette.
//
#define ERROR_FLOPPY_VOLUME              ((ULONG)0x00000248L)

//
// MessageId: ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT
//
// MessageText:
//
// The system bios failed to connect a system interrupt to the device or bus for which the device is connected.
//
#define ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT ((ULONG)0x00000249L)

//
// MessageId: ERROR_BACKUP_CONTROLLER
//
// MessageText:
//
// This operation is only allowed for the Primary Domain Controller of the domain.
//
#define ERROR_BACKUP_CONTROLLER          ((ULONG)0x0000024AL)

//
// MessageId: ERROR_MUTANT_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
//
#define ERROR_MUTANT_LIMIT_EXCEEDED      ((ULONG)0x0000024BL)

//
// MessageId: ERROR_FS_DRIVER_REQUIRED
//
// MessageText:
//
// A volume has been accessed for which a file system driver is required that has not yet been loaded.
//
#define ERROR_FS_DRIVER_REQUIRED         ((ULONG)0x0000024CL)

//
// MessageId: ERROR_CANNOT_LOAD_REGISTRY_FILE
//
// MessageText:
//
// The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable.
//
#define ERROR_CANNOT_LOAD_REGISTRY_FILE  ((ULONG)0x0000024DL)

//
// MessageId: ERROR_DEBUG_ATTACH_FAILED
//
// MessageText:
//
// An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
//
#define ERROR_DEBUG_ATTACH_FAILED        ((ULONG)0x0000024EL)

//
// MessageId: ERROR_SYSTEM_PROCESS_TERMINATED
//
// MessageText:
//
// The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down.
//
#define ERROR_SYSTEM_PROCESS_TERMINATED  ((ULONG)0x0000024FL)

//
// MessageId: ERROR_DATA_NOT_ACCEPTED
//
// MessageText:
//
// The TDI client could not handle the data received during an indication.
//
#define ERROR_DATA_NOT_ACCEPTED          ((ULONG)0x00000250L)

//
// MessageId: ERROR_VDM_HARD_ERROR
//
// MessageText:
//
// NTVDM encountered a hard error.
//
#define ERROR_VDM_HARD_ERROR             ((ULONG)0x00000251L)

//
// MessageId: ERROR_DRIVER_CANCEL_TIMEOUT
//
// MessageText:
//
// The driver %hs failed to complete a cancelled I/O request in the allotted time.
//
#define ERROR_DRIVER_CANCEL_TIMEOUT      ((ULONG)0x00000252L)

//
// MessageId: ERROR_REPLY_MESSAGE_MISMATCH
//
// MessageText:
//
// An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
//
#define ERROR_REPLY_MESSAGE_MISMATCH     ((ULONG)0x00000253L)

//
// MessageId: ERROR_LOST_WRITEBEHIND_DATA
//
// MessageText:
//
// ReactOS was unable to save all the data for the file %hs. The data has been lost. This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
//
#define ERROR_LOST_WRITEBEHIND_DATA      ((ULONG)0x00000254L)

//
// MessageId: ERROR_CLIENT_SERVER_PARAMETERS_INVALID
//
// MessageText:
//
// The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
//
#define ERROR_CLIENT_SERVER_PARAMETERS_INVALID ((ULONG)0x00000255L)

//
// MessageId: ERROR_NOT_TINY_STREAM
//
// MessageText:
//
// The stream is not a tiny stream.
//
#define ERROR_NOT_TINY_STREAM            ((ULONG)0x00000256L)

//
// MessageId: ERROR_STACK_OVERFLOW_READ
//
// MessageText:
//
// The request must be handled by the stack overflow code.
//
#define ERROR_STACK_OVERFLOW_READ        ((ULONG)0x00000257L)

//
// MessageId: ERROR_CONVERT_TO_LARGE
//
// MessageText:
//
// Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
//
#define ERROR_CONVERT_TO_LARGE           ((ULONG)0x00000258L)

//
// MessageId: ERROR_FOUND_OUT_OF_SCOPE
//
// MessageText:
//
// The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
//
#define ERROR_FOUND_OUT_OF_SCOPE         ((ULONG)0x00000259L)

//
// MessageId: ERROR_ALLOCATE_BUCKET
//
// MessageText:
//
// The bucket array must be grown. Retry transaction after doing so.
//
#define ERROR_ALLOCATE_BUCKET            ((ULONG)0x0000025AL)

//
// MessageId: ERROR_MARSHALL_OVERFLOW
//
// MessageText:
//
// The user/kernel marshalling buffer has overflowed.
//
#define ERROR_MARSHALL_OVERFLOW          ((ULONG)0x0000025BL)

//
// MessageId: ERROR_INVALID_VARIANT
//
// MessageText:
//
// The supplied variant structure contains invalid data.
//
#define ERROR_INVALID_VARIANT            ((ULONG)0x0000025CL)

//
// MessageId: ERROR_BAD_COMPRESSION_BUFFER
//
// MessageText:
//
// The specified buffer contains ill-formed data.
//
#define ERROR_BAD_COMPRESSION_BUFFER     ((ULONG)0x0000025DL)

//
// MessageId: ERROR_AUDIT_FAILED
//
// MessageText:
//
// An attempt to generate a security audit failed.
//
#define ERROR_AUDIT_FAILED               ((ULONG)0x0000025EL)

//
// MessageId: ERROR_TIMER_RESOLUTION_NOT_SET
//
// MessageText:
//
// The timer resolution was not previously set by the current process.
//
#define ERROR_TIMER_RESOLUTION_NOT_SET   ((ULONG)0x0000025FL)

//
// MessageId: ERROR_INSUFFICIENT_LOGON_INFO
//
// MessageText:
//
// There is insufficient account information to log you on.
//
#define ERROR_INSUFFICIENT_LOGON_INFO    ((ULONG)0x00000260L)

//
// MessageId: ERROR_BAD_DLL_ENTRYPOINT
//
// MessageText:
//
// The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
//
#define ERROR_BAD_DLL_ENTRYPOINT         ((ULONG)0x00000261L)

//
// MessageId: ERROR_BAD_SERVICE_ENTRYPOINT
//
// MessageText:
//
// The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
//
#define ERROR_BAD_SERVICE_ENTRYPOINT     ((ULONG)0x00000262L)

//
// MessageId: ERROR_IP_ADDRESS_CONFLICT1
//
// MessageText:
//
// There is an IP address conflict with another system on the network
//
#define ERROR_IP_ADDRESS_CONFLICT1       ((ULONG)0x00000263L)

//
// MessageId: ERROR_IP_ADDRESS_CONFLICT2
//
// MessageText:
//
// There is an IP address conflict with another system on the network
//
#define ERROR_IP_ADDRESS_CONFLICT2       ((ULONG)0x00000264L)

//
// MessageId: ERROR_REGISTRY_QUOTA_LIMIT
//
// MessageText:
//
// The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
//
#define ERROR_REGISTRY_QUOTA_LIMIT       ((ULONG)0x00000265L)

//
// MessageId: ERROR_NO_CALLBACK_ACTIVE
//
// MessageText:
//
// A callback return system service cannot be executed when no callback is active.
//
#define ERROR_NO_CALLBACK_ACTIVE         ((ULONG)0x00000266L)

//
// MessageId: ERROR_PWD_TOO_SHORT
//
// MessageText:
//
// The password provided is too short to meet the policy of your user account. Please choose a longer password.
//
#define ERROR_PWD_TOO_SHORT              ((ULONG)0x00000267L)

//
// MessageId: ERROR_PWD_TOO_RECENT
//
// MessageText:
//
// The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
//
#define ERROR_PWD_TOO_RECENT             ((ULONG)0x00000268L)

//
// MessageId: ERROR_PWD_HISTORY_CONFLICT
//
// MessageText:
//
// You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Please select a password that you have not previously used.
//
#define ERROR_PWD_HISTORY_CONFLICT       ((ULONG)0x00000269L)

//
// MessageId: ERROR_UNSUPPORTED_COMPRESSION
//
// MessageText:
//
// The specified compression format is unsupported.
//
#define ERROR_UNSUPPORTED_COMPRESSION    ((ULONG)0x0000026AL)

//
// MessageId: ERROR_INVALID_HW_PROFILE
//
// MessageText:
//
// The specified hardware profile configuration is invalid.
//
#define ERROR_INVALID_HW_PROFILE         ((ULONG)0x0000026BL)

//
// MessageId: ERROR_INVALID_PLUGPLAY_DEVICE_PATH
//
// MessageText:
//
// The specified Plug and Play registry device path is invalid.
//
#define ERROR_INVALID_PLUGPLAY_DEVICE_PATH ((ULONG)0x0000026CL)

//
// MessageId: ERROR_QUOTA_LIST_INCONSISTENT
//
// MessageText:
//
// The specified quota list is internally inconsistent with its descriptor.
//
#define ERROR_QUOTA_LIST_INCONSISTENT    ((ULONG)0x0000026DL)

//
// MessageId: ERROR_EVALUATION_EXPIRATION
//
// MessageText:
//
// The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
//
#define ERROR_EVALUATION_EXPIRATION      ((ULONG)0x0000026EL)

//
// MessageId: ERROR_ILLEGAL_DLL_RELOCATION
//
// MessageText:
//
// The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range reserved for ReactOS system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
//
#define ERROR_ILLEGAL_DLL_RELOCATION     ((ULONG)0x0000026FL)

//
// MessageId: ERROR_DLL_INIT_FAILED_LOGOFF
//
// MessageText:
//
// The application failed to initialize because the window station is shutting down.
//
#define ERROR_DLL_INIT_FAILED_LOGOFF     ((ULONG)0x00000270L)

//
// MessageId: ERROR_VALIDATE_CONTINUE
//
// MessageText:
//
// The validation process needs to continue on to the next step.
//
#define ERROR_VALIDATE_CONTINUE          ((ULONG)0x00000271L)

//
// MessageId: ERROR_NO_MORE_MATCHES
//
// MessageText:
//
// There are no more matches for the current index enumeration.
//
#define ERROR_NO_MORE_MATCHES            ((ULONG)0x00000272L)

//
// MessageId: ERROR_RANGE_LIST_CONFLICT
//
// MessageText:
//
// The range could not be added to the range list because of a conflict.
//
#define ERROR_RANGE_LIST_CONFLICT        ((ULONG)0x00000273L)

//
// MessageId: ERROR_SERVER_SID_MISMATCH
//
// MessageText:
//
// The server process is running under a SID different than that required by client.
//
#define ERROR_SERVER_SID_MISMATCH        ((ULONG)0x00000274L)

//
// MessageId: ERROR_CANT_ENABLE_DENY_ONLY
//
// MessageText:
//
// A group marked use for deny only cannot be enabled.
//
#define ERROR_CANT_ENABLE_DENY_ONLY      ((ULONG)0x00000275L)

//
// MessageId: ERROR_FLOAT_MULTIPLE_FAULTS
//
// MessageText:
//
// Multiple floating point faults.
//
#define ERROR_FLOAT_MULTIPLE_FAULTS      ((ULONG)0x00000276L)

//
// MessageId: ERROR_FLOAT_MULTIPLE_TRAPS
//
// MessageText:
//
// Multiple floating point traps.
//
#define ERROR_FLOAT_MULTIPLE_TRAPS       ((ULONG)0x00000277L)

//
// MessageId: ERROR_NOINTERFACE
//
// MessageText:
//
// The requested interface is not supported.
//
#define ERROR_NOINTERFACE                ((ULONG)0x00000278L)

//
// MessageId: ERROR_DRIVER_FAILED_SLEEP
//
// MessageText:
//
// The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
//
#define ERROR_DRIVER_FAILED_SLEEP        ((ULONG)0x00000279L)

//
// MessageId: ERROR_CORRUPT_SYSTEM_FILE
//
// MessageText:
//
// The system file %1 has become corrupt and has been replaced.
//
#define ERROR_CORRUPT_SYSTEM_FILE        ((ULONG)0x0000027AL)

//
// MessageId: ERROR_COMMITMENT_MINIMUM
//
// MessageText:
//
// Your system is low on virtual memory. ReactOS is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.
//
#define ERROR_COMMITMENT_MINIMUM         ((ULONG)0x0000027BL)

//
// MessageId: ERROR_PNP_RESTART_ENUMERATION
//
// MessageText:
//
// A device was removed so enumeration must be restarted.
//
#define ERROR_PNP_RESTART_ENUMERATION    ((ULONG)0x0000027CL)

//
// MessageId: ERROR_SYSTEM_IMAGE_BAD_SIGNATURE
//
// MessageText:
//
// The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down.
//
#define ERROR_SYSTEM_IMAGE_BAD_SIGNATURE ((ULONG)0x0000027DL)

//
// MessageId: ERROR_PNP_REBOOT_REQUIRED
//
// MessageText:
//
// Device will not start without a reboot.
//
#define ERROR_PNP_REBOOT_REQUIRED        ((ULONG)0x0000027EL)

//
// MessageId: ERROR_INSUFFICIENT_POWER
//
// MessageText:
//
// There is not enough power to complete the requested operation.
//
#define ERROR_INSUFFICIENT_POWER         ((ULONG)0x0000027FL)

//
// MessageId: ERROR_SYSTEM_SHUTDOWN
//
// MessageText:
//
// The system is in the process of shutting down.
//
#define ERROR_SYSTEM_SHUTDOWN            ((ULONG)0x00000281L)

//
// MessageId: ERROR_PORT_NOT_SET
//
// MessageText:
//
// An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
//
#define ERROR_PORT_NOT_SET               ((ULONG)0x00000282L)

//
// MessageId: ERROR_DS_VERSION_CHECK_FAILURE
//
// MessageText:
//
// This version of ReactOS is not compatible with the behavior version of directory forest, domain or domain controller.
//
#define ERROR_DS_VERSION_CHECK_FAILURE   ((ULONG)0x00000283L)

//
// MessageId: ERROR_RANGE_NOT_FOUND
//
// MessageText:
//
// The specified range could not be found in the range list.
//
#define ERROR_RANGE_NOT_FOUND            ((ULONG)0x00000284L)

//
// MessageId: ERROR_NOT_SAFE_MODE_DRIVER
//
// MessageText:
//
// The driver was not loaded because the system is booting into safe mode.
//
#define ERROR_NOT_SAFE_MODE_DRIVER       ((ULONG)0x00000286L)

//
// MessageId: ERROR_FAILED_DRIVER_ENTRY
//
// MessageText:
//
// The driver was not loaded because it failed its initialization call.
//
#define ERROR_FAILED_DRIVER_ENTRY        ((ULONG)0x00000287L)

//
// MessageId: ERROR_DEVICE_ENUMERATION_ERROR
//
// MessageText:
//
// The \"%hs\" encountered an error while applying power or reading the device configuration. This may be caused by a failure of your hardware or by a poor connection.
//
#define ERROR_DEVICE_ENUMERATION_ERROR   ((ULONG)0x00000288L)

//
// MessageId: ERROR_MOUNT_POINT_NOT_RESOLVED
//
// MessageText:
//
// The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
//
#define ERROR_MOUNT_POINT_NOT_RESOLVED   ((ULONG)0x00000289L)

//
// MessageId: ERROR_INVALID_DEVICE_OBJECT_PARAMETER
//
// MessageText:
//
// The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
//
#define ERROR_INVALID_DEVICE_OBJECT_PARAMETER ((ULONG)0x0000028AL)

//
// MessageId: ERROR_MCA_OCCURED
//
// MessageText:
//
// A Machine Check Error has occurred. Please check the system eventlog for additional information.
//
#define ERROR_MCA_OCCURED                ((ULONG)0x0000028BL)

//
// MessageId: ERROR_DRIVER_DATABASE_ERROR
//
// MessageText:
//
// There was error [%2] processing the driver database.
//
#define ERROR_DRIVER_DATABASE_ERROR      ((ULONG)0x0000028CL)

//
// MessageId: ERROR_SYSTEM_HIVE_TOO_LARGE
//
// MessageText:
//
// System hive size has exceeded its limit.
//
#define ERROR_SYSTEM_HIVE_TOO_LARGE      ((ULONG)0x0000028DL)

//
// MessageId: ERROR_DRIVER_FAILED_PRIOR_UNLOAD
//
// MessageText:
//
// The driver could not be loaded because a previous version of the driver is still in memory.
//
#define ERROR_DRIVER_FAILED_PRIOR_UNLOAD ((ULONG)0x0000028EL)

//
// MessageId: ERROR_VOLSNAP_PREPARE_HIBERNATE
//
// MessageText:
//
// Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
//
#define ERROR_VOLSNAP_PREPARE_HIBERNATE  ((ULONG)0x0000028FL)

//
// MessageId: ERROR_HIBERNATION_FAILURE
//
// MessageText:
//
// The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
//
#define ERROR_HIBERNATION_FAILURE        ((ULONG)0x00000290L)

//
// MessageId: ERROR_HUNG_DISPLAY_DRIVER_THREAD
//
// MessageText:
//
// The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft.
//
#define ERROR_HUNG_DISPLAY_DRIVER_THREAD ((ULONG)0x00000291L)

//
// MessageId: ERROR_FILE_SYSTEM_LIMITATION
//
// MessageText:
//
// The requested operation could not be completed due to a file system limitation.
//
#define ERROR_FILE_SYSTEM_LIMITATION     ((ULONG)0x00000299L)

//
// MessageId: ERROR_ASSERTION_FAILURE
//
// MessageText:
//
// An assertion failure has occurred.
//
#define ERROR_ASSERTION_FAILURE          ((ULONG)0x0000029CL)

//
// MessageId: ERROR_VERIFIER_STOP
//
// MessageText:
//
// Application verifier has found an error in the current process.
//
#define ERROR_VERIFIER_STOP              ((ULONG)0x0000029DL)

//
// MessageId: ERROR_WOW_ASSERTION
//
// MessageText:
//
// WOW Assertion Error.
//
#define ERROR_WOW_ASSERTION              ((ULONG)0x0000029EL)

//
// MessageId: ERROR_PNP_BAD_MPS_TABLE
//
// MessageText:
//
// A device is missing in the system BIOS MPS table. This device will not be used. Please contact your system vendor for system BIOS update.
//
#define ERROR_PNP_BAD_MPS_TABLE          ((ULONG)0x0000029FL)

//
// MessageId: ERROR_PNP_TRANSLATION_FAILED
//
// MessageText:
//
// A translator failed to translate resources.
//
#define ERROR_PNP_TRANSLATION_FAILED     ((ULONG)0x000002A0L)

//
// MessageId: ERROR_PNP_IRQ_TRANSLATION_FAILED
//
// MessageText:
//
// A IRQ translator failed to translate resources.
//
#define ERROR_PNP_IRQ_TRANSLATION_FAILED ((ULONG)0x000002A1L)

//
// MessageId: ERROR_PNP_INVALID_ID
//
// MessageText:
//
// Driver %2 returned invalid ID for a child device (%3).
//
#define ERROR_PNP_INVALID_ID             ((ULONG)0x000002A2L)

//
// MessageId: ERROR_WAKE_SYSTEM_DEBUGGER
//
// MessageText:
//
// The system debugger was awakened by an interrupt.
//
#define ERROR_WAKE_SYSTEM_DEBUGGER       ((ULONG)0x000002A3L)

//
// MessageId: ERROR_HANDLES_CLOSED
//
// MessageText:
//
// Handles to objects have been automatically closed as a result of the requested operation.
//
#define ERROR_HANDLES_CLOSED             ((ULONG)0x000002A4L)

//
// MessageId: ERROR_EXTRANEOUS_INFORMATION
//
// MessageText:
//
// The specified access control list (ACL) contained more information than was expected.
//
#define ERROR_EXTRANEOUS_INFORMATION     ((ULONG)0x000002A5L)

//
// MessageId: ERROR_RXACT_COMMIT_NECESSARY
//
// MessageText:
//
// This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
//
#define ERROR_RXACT_COMMIT_NECESSARY     ((ULONG)0x000002A6L)

//
// MessageId: ERROR_MEDIA_CHECK
//
// MessageText:
//
// The media may have changed.
//
#define ERROR_MEDIA_CHECK                ((ULONG)0x000002A7L)

//
// MessageId: ERROR_GUID_SUBSTITUTION_MADE
//
// MessageText:
//
// During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.
//
#define ERROR_GUID_SUBSTITUTION_MADE     ((ULONG)0x000002A8L)

//
// MessageId: ERROR_STOPPED_ON_SYMLINK
//
// MessageText:
//
// The create operation stopped after reaching a symbolic link.
//
#define ERROR_STOPPED_ON_SYMLINK         ((ULONG)0x000002A9L)

//
// MessageId: ERROR_LONGJUMP
//
// MessageText:
//
// A long jump has been executed.
//
#define ERROR_LONGJUMP                   ((ULONG)0x000002AAL)

//
// MessageId: ERROR_PLUGPLAY_QUERY_VETOED
//
// MessageText:
//
// The Plug and Play query operation was not successful.
//
#define ERROR_PLUGPLAY_QUERY_VETOED      ((ULONG)0x000002ABL)

//
// MessageId: ERROR_UNWIND_CONSOLIDATE
//
// MessageText:
//
// A frame consolidation has been executed.
//
#define ERROR_UNWIND_CONSOLIDATE         ((ULONG)0x000002ACL)

//
// MessageId: ERROR_REGISTRY_HIVE_RECOVERED
//
// MessageText:
//
// Registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost.
//
#define ERROR_REGISTRY_HIVE_RECOVERED    ((ULONG)0x000002ADL)

//
// MessageId: ERROR_DLL_MIGHT_BE_INSECURE
//
// MessageText:
//
// The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
//
#define ERROR_DLL_MIGHT_BE_INSECURE      ((ULONG)0x000002AEL)

//
// MessageId: ERROR_DLL_MIGHT_BE_INCOMPATIBLE
//
// MessageText:
//
// The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
//
#define ERROR_DLL_MIGHT_BE_INCOMPATIBLE  ((ULONG)0x000002AFL)

//
// MessageId: ERROR_DBG_EXCEPTION_NOT_HANDLED
//
// MessageText:
//
// Debugger did not handle the exception.
//
#define ERROR_DBG_EXCEPTION_NOT_HANDLED  ((ULONG)0x000002B0L)

//
// MessageId: ERROR_DBG_REPLY_LATER
//
// MessageText:
//
// Debugger will reply later.
//
#define ERROR_DBG_REPLY_LATER            ((ULONG)0x000002B1L)

//
// MessageId: ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE
//
// MessageText:
//
// Debugger can not provide handle.
//
#define ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE ((ULONG)0x000002B2L)

//
// MessageId: ERROR_DBG_TERMINATE_THREAD
//
// MessageText:
//
// Debugger terminated thread.
//
#define ERROR_DBG_TERMINATE_THREAD       ((ULONG)0x000002B3L)

//
// MessageId: ERROR_DBG_TERMINATE_PROCESS
//
// MessageText:
//
// Debugger terminated process.
//
#define ERROR_DBG_TERMINATE_PROCESS      ((ULONG)0x000002B4L)

//
// MessageId: ERROR_DBG_CONTROL_C
//
// MessageText:
//
// Debugger got control C.
//
#define ERROR_DBG_CONTROL_C              ((ULONG)0x000002B5L)

//
// MessageId: ERROR_DBG_PRINTEXCEPTION_C
//
// MessageText:
//
// Debugger printed exception on control C.
//
#define ERROR_DBG_PRINTEXCEPTION_C       ((ULONG)0x000002B6L)

//
// MessageId: ERROR_DBG_RIPEXCEPTION
//
// MessageText:
//
// Debugger received RIP exception.
//
#define ERROR_DBG_RIPEXCEPTION           ((ULONG)0x000002B7L)

//
// MessageId: ERROR_DBG_CONTROL_BREAK
//
// MessageText:
//
// Debugger received control break.
//
#define ERROR_DBG_CONTROL_BREAK          ((ULONG)0x000002B8L)

//
// MessageId: ERROR_DBG_COMMAND_EXCEPTION
//
// MessageText:
//
// Debugger command communication exception.
//
#define ERROR_DBG_COMMAND_EXCEPTION      ((ULONG)0x000002B9L)

//
// MessageId: ERROR_OBJECT_NAME_EXISTS
//
// MessageText:
//
// An attempt was made to create an object and the object name already existed.
//
#define ERROR_OBJECT_NAME_EXISTS         ((ULONG)0x000002BAL)

//
// MessageId: ERROR_THREAD_WAS_SUSPENDED
//
// MessageText:
//
// A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
//
#define ERROR_THREAD_WAS_SUSPENDED       ((ULONG)0x000002BBL)

//
// MessageId: ERROR_IMAGE_NOT_AT_BASE
//
// MessageText:
//
// An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
//
#define ERROR_IMAGE_NOT_AT_BASE          ((ULONG)0x000002BCL)

//
// MessageId: ERROR_RXACT_STATE_CREATED
//
// MessageText:
//
// This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
//
#define ERROR_RXACT_STATE_CREATED        ((ULONG)0x000002BDL)

//
// MessageId: ERROR_SEGMENT_NOTIFICATION
//
// MessageText:
//
// A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image. An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
//
#define ERROR_SEGMENT_NOTIFICATION       ((ULONG)0x000002BEL)

//
// MessageId: ERROR_BAD_CURRENT_DIRECTORY
//
// MessageText:
//
// The process cannot switch to the startup current directory %hs. Select OK to set current directory to %hs, or select CANCEL to exit.
//
#define ERROR_BAD_CURRENT_DIRECTORY      ((ULONG)0x000002BFL)

//
// MessageId: ERROR_FT_READ_RECOVERY_FROM_BACKUP
//
// MessageText:
//
// To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
//
#define ERROR_FT_READ_RECOVERY_FROM_BACKUP ((ULONG)0x000002C0L)

//
// MessageId: ERROR_FT_WRITE_RECOVERY
//
// MessageText:
//
// To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
//
#define ERROR_FT_WRITE_RECOVERY          ((ULONG)0x000002C1L)

//
// MessageId: ERROR_IMAGE_MACHINE_TYPE_MISMATCH
//
// MessageText:
//
// The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
//
#define ERROR_IMAGE_MACHINE_TYPE_MISMATCH ((ULONG)0x000002C2L)

//
// MessageId: ERROR_RECEIVE_PARTIAL
//
// MessageText:
//
// The network transport returned partial data to its client. The remaining data will be sent later.
//
#define ERROR_RECEIVE_PARTIAL            ((ULONG)0x000002C3L)

//
// MessageId: ERROR_RECEIVE_EXPEDITED
//
// MessageText:
//
// The network transport returned data to its client that was marked as expedited by the remote system.
//
#define ERROR_RECEIVE_EXPEDITED          ((ULONG)0x000002C4L)

//
// MessageId: ERROR_RECEIVE_PARTIAL_EXPEDITED
//
// MessageText:
//
// The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
//
#define ERROR_RECEIVE_PARTIAL_EXPEDITED  ((ULONG)0x000002C5L)

//
// MessageId: ERROR_EVENT_DONE
//
// MessageText:
//
// The TDI indication has completed successfully.
//
#define ERROR_EVENT_DONE                 ((ULONG)0x000002C6L)

//
// MessageId: ERROR_EVENT_PENDING
//
// MessageText:
//
// The TDI indication has entered the pending state.
//
#define ERROR_EVENT_PENDING              ((ULONG)0x000002C7L)

//
// MessageId: ERROR_CHECKING_FILE_SYSTEM
//
// MessageText:
//
// Checking file system on %wZ.
//
#define ERROR_CHECKING_FILE_SYSTEM       ((ULONG)0x000002C8L)

//
// MessageId: ERROR_PREDEFINED_HANDLE
//
// MessageText:
//
// The specified registry key is referenced by a predefined handle.
//
#define ERROR_PREDEFINED_HANDLE          ((ULONG)0x000002CAL)

//
// MessageId: ERROR_WAS_UNLOCKED
//
// MessageText:
//
// The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
//
#define ERROR_WAS_UNLOCKED               ((ULONG)0x000002CBL)

//
// MessageId: ERROR_WAS_LOCKED
//
// MessageText:
//
// One of the pages to lock was already locked.
//
#define ERROR_WAS_LOCKED                 ((ULONG)0x000002CDL)

//
// MessageId: ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE
//
// MessageText:
//
// The image file %hs is valid, but is for a machine type other than the current machine.
//
#define ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE ((ULONG)0x000002D0L)

//
// MessageId: ERROR_NO_YIELD_PERFORMED
//
// MessageText:
//
// A yield execution was performed and no thread was available to run.
//
#define ERROR_NO_YIELD_PERFORMED         ((ULONG)0x000002D1L)

//
// MessageId: ERROR_TIMER_RESUME_IGNORED
//
// MessageText:
//
// The resumable flag to a timer API was ignored.
//
#define ERROR_TIMER_RESUME_IGNORED       ((ULONG)0x000002D2L)

//
// MessageId: ERROR_ARBITRATION_UNHANDLED
//
// MessageText:
//
// The arbiter has deferred arbitration of these resources to its parent.
//
#define ERROR_ARBITRATION_UNHANDLED      ((ULONG)0x000002D3L)

//
// MessageId: ERROR_CARDBUS_NOT_SUPPORTED
//
// MessageText:
//
// The device \"%hs\" has detected a CardBus card in its slot, but the firmware on this system is not configured to allow the CardBus controller to be run in CardBus mode. The operating system will currently accept only 16-bit (R2) pc-cards on this controller.
//
#define ERROR_CARDBUS_NOT_SUPPORTED      ((ULONG)0x000002D4L)

//
// MessageId: ERROR_MP_PROCESSOR_MISMATCH
//
// MessageText:
//
// The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
//
#define ERROR_MP_PROCESSOR_MISMATCH      ((ULONG)0x000002D5L)

//
// MessageId: ERROR_HIBERNATED
//
// MessageText:
//
// The system was put into hibernation.
//
#define ERROR_HIBERNATED                 ((ULONG)0x000002D6L)

//
// MessageId: ERROR_RESUME_HIBERNATION
//
// MessageText:
//
// The system was resumed from hibernation.
//
#define ERROR_RESUME_HIBERNATION         ((ULONG)0x000002D7L)

//
// MessageId: ERROR_FIRMWARE_UPDATED
//
// MessageText:
//
// ReactOS has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
//
#define ERROR_FIRMWARE_UPDATED           ((ULONG)0x000002D8L)

//
// MessageId: ERROR_DRIVERS_LEAKING_LOCKED_PAGES
//
// MessageText:
//
// A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
//
#define ERROR_DRIVERS_LEAKING_LOCKED_PAGES ((ULONG)0x000002D9L)

//
// MessageId: ERROR_WAKE_SYSTEM
//
// MessageText:
//
// The system has awoken
//
#define ERROR_WAKE_SYSTEM                ((ULONG)0x000002DAL)

//
// MessageId: ERROR_ELEVATION_REQUIRED
//
// MessageText:
//
// The requested operation requires elevation.
//
#define ERROR_ELEVATION_REQUIRED         ((ULONG)0x000002E4L)

//
// MessageId: ERROR_REPARSE
//
// MessageText:
//
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
//
#define ERROR_REPARSE                    ((ULONG)0x000002E5L)

//
// MessageId: ERROR_OPLOCK_BREAK_IN_PROGRESS
//
// MessageText:
//
// An open/create operation completed while an oplock break is underway.
//
#define ERROR_OPLOCK_BREAK_IN_PROGRESS   ((ULONG)0x000002E6L)

//
// MessageId: ERROR_VOLUME_MOUNTED
//
// MessageText:
//
// A new volume has been mounted by a file system.
//
#define ERROR_VOLUME_MOUNTED             ((ULONG)0x000002E7L)

//
// MessageId: ERROR_RXACT_COMMITTED
//
// MessageText:
//
// This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.
//
#define ERROR_RXACT_COMMITTED            ((ULONG)0x000002E8L)

//
// MessageId: ERROR_NOTIFY_CLEANUP
//
// MessageText:
//
// This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
//
#define ERROR_NOTIFY_CLEANUP             ((ULONG)0x000002E9L)

//
// MessageId: ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED
//
// MessageText:
//
// An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed. The computer WAS able to connect on a secondary transport.
//
#define ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED ((ULONG)0x000002EAL)

//
// MessageId: ERROR_PAGE_FAULT_TRANSITION
//
// MessageText:
//
// Page fault was a transition fault.
//
#define ERROR_PAGE_FAULT_TRANSITION      ((ULONG)0x000002EBL)

//
// MessageId: ERROR_PAGE_FAULT_DEMAND_ZERO
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_DEMAND_ZERO     ((ULONG)0x000002ECL)

//
// MessageId: ERROR_PAGE_FAULT_COPY_ON_WRITE
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_COPY_ON_WRITE   ((ULONG)0x000002EDL)

//
// MessageId: ERROR_PAGE_FAULT_GUARD_PAGE
//
// MessageText:
//
// Page fault was a demand zero fault.
//
#define ERROR_PAGE_FAULT_GUARD_PAGE      ((ULONG)0x000002EEL)

//
// MessageId: ERROR_PAGE_FAULT_PAGING_FILE
//
// MessageText:
//
// Page fault was satisfied by reading from a secondary storage device.
//
#define ERROR_PAGE_FAULT_PAGING_FILE     ((ULONG)0x000002EFL)

//
// MessageId: ERROR_CACHE_PAGE_LOCKED
//
// MessageText:
//
// Cached page was locked during operation.
//
#define ERROR_CACHE_PAGE_LOCKED          ((ULONG)0x000002F0L)

//
// MessageId: ERROR_CRASH_DUMP
//
// MessageText:
//
// Crash dump exists in paging file.
//
#define ERROR_CRASH_DUMP                 ((ULONG)0x000002F1L)

//
// MessageId: ERROR_BUFFER_ALL_ZEROS
//
// MessageText:
//
// Specified buffer contains all zeros.
//
#define ERROR_BUFFER_ALL_ZEROS           ((ULONG)0x000002F2L)

//
// MessageId: ERROR_REPARSE_OBJECT
//
// MessageText:
//
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
//
#define ERROR_REPARSE_OBJECT             ((ULONG)0x000002F3L)

//
// MessageId: ERROR_RESOURCE_REQUIREMENTS_CHANGED
//
// MessageText:
//
// The device has succeeded a query-stop and its resource requirements have changed.
//
#define ERROR_RESOURCE_REQUIREMENTS_CHANGED ((ULONG)0x000002F4L)

//
// MessageId: ERROR_TRANSLATION_COMPLETE
//
// MessageText:
//
// The translator has translated these resources into the global space and no further translations should be performed.
//
#define ERROR_TRANSLATION_COMPLETE       ((ULONG)0x000002F5L)

//
// MessageId: ERROR_NOTHING_TO_TERMINATE
//
// MessageText:
//
// A process being terminated has no threads to terminate.
//
#define ERROR_NOTHING_TO_TERMINATE       ((ULONG)0x000002F6L)

//
// MessageId: ERROR_PROCESS_NOT_IN_JOB
//
// MessageText:
//
// The specified process is not part of a job.
//
#define ERROR_PROCESS_NOT_IN_JOB         ((ULONG)0x000002F7L)

//
// MessageId: ERROR_PROCESS_IN_JOB
//
// MessageText:
//
// The specified process is part of a job.
//
#define ERROR_PROCESS_IN_JOB             ((ULONG)0x000002F8L)

//
// MessageId: ERROR_VOLSNAP_HIBERNATE_READY
//
// MessageText:
//
// The system is now ready for hibernation.
//
#define ERROR_VOLSNAP_HIBERNATE_READY    ((ULONG)0x000002F9L)

//
// MessageId: ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY
//
// MessageText:
//
// A file system or file system filter driver has successfully completed an FsFilter operation.
//
#define ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY ((ULONG)0x000002FAL)

//
// MessageId: ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED
//
// MessageText:
//
// The specified interrupt vector was already connected.
//
#define ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED ((ULONG)0x000002FBL)

//
// MessageId: ERROR_INTERRUPT_STILL_CONNECTED
//
// MessageText:
//
// The specified interrupt vector is still connected.
//
#define ERROR_INTERRUPT_STILL_CONNECTED  ((ULONG)0x000002FCL)

//
// MessageId: ERROR_WAIT_FOR_OPLOCK
//
// MessageText:
//
// An operation is blocked waiting for an oplock.
//
#define ERROR_WAIT_FOR_OPLOCK            ((ULONG)0x000002FDL)

//
// MessageId: ERROR_DBG_EXCEPTION_HANDLED
//
// MessageText:
//
// Debugger handled exception.
//
#define ERROR_DBG_EXCEPTION_HANDLED      ((ULONG)0x000002FEL)

//
// MessageId: ERROR_DBG_CONTINUE
//
// MessageText:
//
// Debugger continued
//
#define ERROR_DBG_CONTINUE               ((ULONG)0x000002FFL)

//
// MessageId: ERROR_CALLBACK_POP_STACK
//
// MessageText:
//
// An exception occurred in a user mode callback and the kernel callback frame should be removed.
//
#define ERROR_CALLBACK_POP_STACK         ((ULONG)0x00000300L)

//
// MessageId: ERROR_COMPRESSION_DISABLED
//
// MessageText:
//
// Compression is disabled for this volume.
//
#define ERROR_COMPRESSION_DISABLED       ((ULONG)0x00000301L)

//
// MessageId: ERROR_CANTFETCHBACKWARDS
//
// MessageText:
//
// The data provider cannot fetch backwards through a result set.
//
#define ERROR_CANTFETCHBACKWARDS         ((ULONG)0x00000302L)

//
// MessageId: ERROR_CANTSCROLLBACKWARDS
//
// MessageText:
//
// The data provider cannot scroll backwards through a result set.
//
#define ERROR_CANTSCROLLBACKWARDS        ((ULONG)0x00000303L)

//
// MessageId: ERROR_ROWSNOTRELEASED
//
// MessageText:
//
// The data provider requires that previously fetched data is released before asking for more data.
//
#define ERROR_ROWSNOTRELEASED            ((ULONG)0x00000304L)

//
// MessageId: ERROR_BAD_ACCESSOR_FLAGS
//
// MessageText:
//
// The data provider was not able to interpret the flags set for a column binding in an accessor.
//
#define ERROR_BAD_ACCESSOR_FLAGS         ((ULONG)0x00000305L)

//
// MessageId: ERROR_ERRORS_ENCOUNTERED
//
// MessageText:
//
// One or more errors occurred while processing the request.
//
#define ERROR_ERRORS_ENCOUNTERED         ((ULONG)0x00000306L)

//
// MessageId: ERROR_NOT_CAPABLE
//
// MessageText:
//
// The implementation is not capable of performing the request.
//
#define ERROR_NOT_CAPABLE                ((ULONG)0x00000307L)

//
// MessageId: ERROR_REQUEST_OUT_OF_SEQUENCE
//
// MessageText:
//
// The client of a component requested an operation which is not valid given the state of the component instance.
//
#define ERROR_REQUEST_OUT_OF_SEQUENCE    ((ULONG)0x00000308L)

//
// MessageId: ERROR_VERSION_PARSE_ERROR
//
// MessageText:
//
// A version number could not be parsed.
//
#define ERROR_VERSION_PARSE_ERROR        ((ULONG)0x00000309L)

//
// MessageId: ERROR_BADSTARTPOSITION
//
// MessageText:
//
// The iterator's start position is invalid.
//
#define ERROR_BADSTARTPOSITION           ((ULONG)0x0000030AL)

//
// MessageId: ERROR_EA_ACCESS_DENIED
//
// MessageText:
//
// Access to the extended attribute was denied.
//
#define ERROR_EA_ACCESS_DENIED           ((ULONG)0x000003E2L)

//
// MessageId: ERROR_OPERATION_ABORTED
//
// MessageText:
//
// The I/O operation has been aborted because of either a thread exit or an application request.
//
#define ERROR_OPERATION_ABORTED          ((ULONG)0x000003E3L)

//
// MessageId: ERROR_IO_INCOMPLETE
//
// MessageText:
//
// Overlapped I/O event is not in a signaled state.
//
#define ERROR_IO_INCOMPLETE              ((ULONG)0x000003E4L)

//
// MessageId: ERROR_IO_PENDING
//
// MessageText:
//
// Overlapped I/O operation is in progress.
//
#define ERROR_IO_PENDING                 ((ULONG)0x000003E5L)

//
// MessageId: ERROR_NOACCESS
//
// MessageText:
//
// Invalid access to memory location.
//
#define ERROR_NOACCESS                   ((ULONG)0x000003E6L)

//
// MessageId: ERROR_SWAPERROR
//
// MessageText:
//
// Error performing inpage operation.
//
#define ERROR_SWAPERROR                  ((ULONG)0x000003E7L)

//
// MessageId: ERROR_STACK_OVERFLOW
//
// MessageText:
//
// Recursion too deep; the stack overflowed.
//
#define ERROR_STACK_OVERFLOW             ((ULONG)0x000003E9L)

//
// MessageId: ERROR_INVALID_MESSAGE
//
// MessageText:
//
// The window cannot act on the sent message.
//
#define ERROR_INVALID_MESSAGE            ((ULONG)0x000003EAL)

//
// MessageId: ERROR_CAN_NOT_COMPLETE
//
// MessageText:
//
// Cannot complete this function.
//
#define ERROR_CAN_NOT_COMPLETE           ((ULONG)0x000003EBL)

//
// MessageId: ERROR_INVALID_FLAGS
//
// MessageText:
//
// Invalid flags.
//
#define ERROR_INVALID_FLAGS              ((ULONG)0x000003ECL)

//
// MessageId: ERROR_UNRECOGNIZED_VOLUME
//
// MessageText:
//
// The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
//
#define ERROR_UNRECOGNIZED_VOLUME        ((ULONG)0x000003EDL)

//
// MessageId: ERROR_FILE_INVALID
//
// MessageText:
//
// The volume for a file has been externally altered so that the opened file is no longer valid.
//
#define ERROR_FILE_INVALID               ((ULONG)0x000003EEL)

//
// MessageId: ERROR_FULLSCREEN_MODE
//
// MessageText:
//
// The requested operation cannot be performed in full-screen mode.
//
#define ERROR_FULLSCREEN_MODE            ((ULONG)0x000003EFL)

//
// MessageId: ERROR_NO_TOKEN
//
// MessageText:
//
// An attempt was made to reference a token that does not exist.
//
#define ERROR_NO_TOKEN                   ((ULONG)0x000003F0L)

//
// MessageId: ERROR_BADDB
//
// MessageText:
//
// The configuration registry database is corrupt.
//
#define ERROR_BADDB                      ((ULONG)0x000003F1L)

//
// MessageId: ERROR_BADKEY
//
// MessageText:
//
// The configuration registry key is invalid.
//
#define ERROR_BADKEY                     ((ULONG)0x000003F2L)

//
// MessageId: ERROR_CANTOPEN
//
// MessageText:
//
// The configuration registry key could not be opened.
//
#define ERROR_CANTOPEN                   ((ULONG)0x000003F3L)

//
// MessageId: ERROR_CANTREAD
//
// MessageText:
//
// The configuration registry key could not be read.
//
#define ERROR_CANTREAD                   ((ULONG)0x000003F4L)

//
// MessageId: ERROR_CANTWRITE
//
// MessageText:
//
// The configuration registry key could not be written.
//
#define ERROR_CANTWRITE                  ((ULONG)0x000003F5L)

//
// MessageId: ERROR_REGISTRY_RECOVERED
//
// MessageText:
//
// One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
//
#define ERROR_REGISTRY_RECOVERED         ((ULONG)0x000003F6L)

//
// MessageId: ERROR_REGISTRY_CORRUPT
//
// MessageText:
//
// The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
//
#define ERROR_REGISTRY_CORRUPT           ((ULONG)0x000003F7L)

//
// MessageId: ERROR_REGISTRY_IO_FAILED
//
// MessageText:
//
// An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
//
#define ERROR_REGISTRY_IO_FAILED         ((ULONG)0x000003F8L)

//
// MessageId: ERROR_NOT_REGISTRY_FILE
//
// MessageText:
//
// The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
//
#define ERROR_NOT_REGISTRY_FILE          ((ULONG)0x000003F9L)

//
// MessageId: ERROR_KEY_DELETED
//
// MessageText:
//
// Illegal operation attempted on a registry key that has been marked for deletion.
//
#define ERROR_KEY_DELETED                ((ULONG)0x000003FAL)

//
// MessageId: ERROR_NO_LOG_SPACE
//
// MessageText:
//
// System could not allocate the required space in a registry log.
//
#define ERROR_NO_LOG_SPACE               ((ULONG)0x000003FBL)

//
// MessageId: ERROR_KEY_HAS_CHILDREN
//
// MessageText:
//
// Cannot create a symbolic link in a registry key that already has subkeys or values.
//
#define ERROR_KEY_HAS_CHILDREN           ((ULONG)0x000003FCL)

//
// MessageId: ERROR_CHILD_MUST_BE_VOLATILE
//
// MessageText:
//
// Cannot create a stable subkey under a volatile parent key.
//
#define ERROR_CHILD_MUST_BE_VOLATILE     ((ULONG)0x000003FDL)

//
// MessageId: ERROR_NOTIFY_ENUM_DIR
//
// MessageText:
//
// A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.
//
#define ERROR_NOTIFY_ENUM_DIR            ((ULONG)0x000003FEL)

//
// MessageId: ERROR_DEPENDENT_SERVICES_RUNNING
//
// MessageText:
//
// A stop control has been sent to a service that other running services are dependent on.
//
#define ERROR_DEPENDENT_SERVICES_RUNNING ((ULONG)0x0000041BL)

//
// MessageId: ERROR_INVALID_SERVICE_CONTROL
//
// MessageText:
//
// The requested control is not valid for this service.
//
#define ERROR_INVALID_SERVICE_CONTROL    ((ULONG)0x0000041CL)

//
// MessageId: ERROR_SERVICE_REQUEST_TIMEOUT
//
// MessageText:
//
// The service did not respond to the start or control request in a timely fashion.
//
#define ERROR_SERVICE_REQUEST_TIMEOUT    ((ULONG)0x0000041DL)

//
// MessageId: ERROR_SERVICE_NO_THREAD
//
// MessageText:
//
// A thread could not be created for the service.
//
#define ERROR_SERVICE_NO_THREAD          ((ULONG)0x0000041EL)

//
// MessageId: ERROR_SERVICE_DATABASE_LOCKED
//
// MessageText:
//
// The service database is locked.
//
#define ERROR_SERVICE_DATABASE_LOCKED    ((ULONG)0x0000041FL)

//
// MessageId: ERROR_SERVICE_ALREADY_RUNNING
//
// MessageText:
//
// An instance of the service is already running.
//
#define ERROR_SERVICE_ALREADY_RUNNING    ((ULONG)0x00000420L)

//
// MessageId: ERROR_INVALID_SERVICE_ACCOUNT
//
// MessageText:
//
// The account name is invalid or does not exist, or the password is invalid for the account name specified.
//
#define ERROR_INVALID_SERVICE_ACCOUNT    ((ULONG)0x00000421L)

//
// MessageId: ERROR_SERVICE_DISABLED
//
// MessageText:
//
// The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
//
#define ERROR_SERVICE_DISABLED           ((ULONG)0x00000422L)

//
// MessageId: ERROR_CIRCULAR_DEPENDENCY
//
// MessageText:
//
// Circular service dependency was specified.
//
#define ERROR_CIRCULAR_DEPENDENCY        ((ULONG)0x00000423L)

//
// MessageId: ERROR_SERVICE_DOES_NOT_EXIST
//
// MessageText:
//
// The specified service does not exist as an installed service.
//
#define ERROR_SERVICE_DOES_NOT_EXIST     ((ULONG)0x00000424L)

//
// MessageId: ERROR_SERVICE_CANNOT_ACCEPT_CTRL
//
// MessageText:
//
// The service cannot accept control messages at this time.
//
#define ERROR_SERVICE_CANNOT_ACCEPT_CTRL ((ULONG)0x00000425L)

//
// MessageId: ERROR_SERVICE_NOT_ACTIVE
//
// MessageText:
//
// The service has not been started.
//
#define ERROR_SERVICE_NOT_ACTIVE         ((ULONG)0x00000426L)

//
// MessageId: ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
//
// MessageText:
//
// The service process could not connect to the service controller.
//
#define ERROR_FAILED_SERVICE_CONTROLLER_CONNECT ((ULONG)0x00000427L)

//
// MessageId: ERROR_EXCEPTION_IN_SERVICE
//
// MessageText:
//
// An exception occurred in the service when handling the control request.
//
#define ERROR_EXCEPTION_IN_SERVICE       ((ULONG)0x00000428L)

//
// MessageId: ERROR_DATABASE_DOES_NOT_EXIST
//
// MessageText:
//
// The database specified does not exist.
//
#define ERROR_DATABASE_DOES_NOT_EXIST    ((ULONG)0x00000429L)

//
// MessageId: ERROR_SERVICE_SPECIFIC_ERROR
//
// MessageText:
//
// The service has returned a service-specific error code.
//
#define ERROR_SERVICE_SPECIFIC_ERROR     ((ULONG)0x0000042AL)

//
// MessageId: ERROR_PROCESS_ABORTED
//
// MessageText:
//
// The process terminated unexpectedly.
//
#define ERROR_PROCESS_ABORTED            ((ULONG)0x0000042BL)

//
// MessageId: ERROR_SERVICE_DEPENDENCY_FAIL
//
// MessageText:
//
// The dependency service or group failed to start.
//
#define ERROR_SERVICE_DEPENDENCY_FAIL    ((ULONG)0x0000042CL)

//
// MessageId: ERROR_SERVICE_LOGON_FAILED
//
// MessageText:
//
// The service did not start due to a logon failure.
//
#define ERROR_SERVICE_LOGON_FAILED       ((ULONG)0x0000042DL)

//
// MessageId: ERROR_SERVICE_START_HANG
//
// MessageText:
//
// After starting, the service hung in a start-pending state.
//
#define ERROR_SERVICE_START_HANG         ((ULONG)0x0000042EL)

//
// MessageId: ERROR_INVALID_SERVICE_LOCK
//
// MessageText:
//
// The specified service database lock is invalid.
//
#define ERROR_INVALID_SERVICE_LOCK       ((ULONG)0x0000042FL)

//
// MessageId: ERROR_SERVICE_MARKED_FOR_DELETE
//
// MessageText:
//
// The specified service has been marked for deletion.
//
#define ERROR_SERVICE_MARKED_FOR_DELETE  ((ULONG)0x00000430L)

//
// MessageId: ERROR_SERVICE_EXISTS
//
// MessageText:
//
// The specified service already exists.
//
#define ERROR_SERVICE_EXISTS             ((ULONG)0x00000431L)

//
// MessageId: ERROR_ALREADY_RUNNING_LKG
//
// MessageText:
//
// The system is currently running with the last-known-good configuration.
//
#define ERROR_ALREADY_RUNNING_LKG        ((ULONG)0x00000432L)

//
// MessageId: ERROR_SERVICE_DEPENDENCY_DELETED
//
// MessageText:
//
// The dependency service does not exist or has been marked for deletion.
//
#define ERROR_SERVICE_DEPENDENCY_DELETED ((ULONG)0x00000433L)

//
// MessageId: ERROR_BOOT_ALREADY_ACCEPTED
//
// MessageText:
//
// The current boot has already been accepted for use as the last-known-good control set.
//
#define ERROR_BOOT_ALREADY_ACCEPTED      ((ULONG)0x00000434L)

//
// MessageId: ERROR_SERVICE_NEVER_STARTED
//
// MessageText:
//
// No attempts to start the service have been made since the last boot.
//
#define ERROR_SERVICE_NEVER_STARTED      ((ULONG)0x00000435L)

//
// MessageId: ERROR_DUPLICATE_SERVICE_NAME
//
// MessageText:
//
// The name is already in use as either a service name or a service display name.
//
#define ERROR_DUPLICATE_SERVICE_NAME     ((ULONG)0x00000436L)

//
// MessageId: ERROR_DIFFERENT_SERVICE_ACCOUNT
//
// MessageText:
//
// The account specified for this service is different from the account specified for other services running in the same process.
//
#define ERROR_DIFFERENT_SERVICE_ACCOUNT  ((ULONG)0x00000437L)

//
// MessageId: ERROR_CANNOT_DETECT_DRIVER_FAILURE
//
// MessageText:
//
// Failure actions can only be set for Win32 services, not for drivers.
//
#define ERROR_CANNOT_DETECT_DRIVER_FAILURE ((ULONG)0x00000438L)

//
// MessageId: ERROR_CANNOT_DETECT_PROCESS_ABORT
//
// MessageText:
//
// This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
//
#define ERROR_CANNOT_DETECT_PROCESS_ABORT ((ULONG)0x00000439L)

//
// MessageId: ERROR_NO_RECOVERY_PROGRAM
//
// MessageText:
//
// No recovery program has been configured for this service.
//
#define ERROR_NO_RECOVERY_PROGRAM        ((ULONG)0x0000043AL)

//
// MessageId: ERROR_SERVICE_NOT_IN_EXE
//
// MessageText:
//
// The executable program that this service is configured to run in does not implement the service.
//
#define ERROR_SERVICE_NOT_IN_EXE         ((ULONG)0x0000043BL)

//
// MessageId: ERROR_NOT_SAFEBOOT_SERVICE
//
// MessageText:
//
// This service cannot be started in Safe Mode.
//
#define ERROR_NOT_SAFEBOOT_SERVICE       ((ULONG)0x0000043CL)

//
// MessageId: ERROR_END_OF_MEDIA
//
// MessageText:
//
// The physical end of the tape has been reached.
//
#define ERROR_END_OF_MEDIA               ((ULONG)0x0000044CL)

//
// MessageId: ERROR_FILEMARK_DETECTED
//
// MessageText:
//
// A tape access reached a filemark.
//
#define ERROR_FILEMARK_DETECTED          ((ULONG)0x0000044DL)

//
// MessageId: ERROR_BEGINNING_OF_MEDIA
//
// MessageText:
//
// The beginning of the tape or a partition was encountered.
//
#define ERROR_BEGINNING_OF_MEDIA         ((ULONG)0x0000044EL)

//
// MessageId: ERROR_SETMARK_DETECTED
//
// MessageText:
//
// A tape access reached the end of a set of files.
//
#define ERROR_SETMARK_DETECTED           ((ULONG)0x0000044FL)

//
// MessageId: ERROR_NO_DATA_DETECTED
//
// MessageText:
//
// No more data is on the tape.
//
#define ERROR_NO_DATA_DETECTED           ((ULONG)0x00000450L)

//
// MessageId: ERROR_PARTITION_FAILURE
//
// MessageText:
//
// Tape could not be partitioned.
//
#define ERROR_PARTITION_FAILURE          ((ULONG)0x00000451L)

//
// MessageId: ERROR_INVALID_BLOCK_LENGTH
//
// MessageText:
//
// When accessing a new tape of a multivolume partition, the current block size is incorrect.
//
#define ERROR_INVALID_BLOCK_LENGTH       ((ULONG)0x00000452L)

//
// MessageId: ERROR_DEVICE_NOT_PARTITIONED
//
// MessageText:
//
// Tape partition information could not be found when loading a tape.
//
#define ERROR_DEVICE_NOT_PARTITIONED     ((ULONG)0x00000453L)

//
// MessageId: ERROR_UNABLE_TO_LOCK_MEDIA
//
// MessageText:
//
// Unable to lock the media eject mechanism.
//
#define ERROR_UNABLE_TO_LOCK_MEDIA       ((ULONG)0x00000454L)

//
// MessageId: ERROR_UNABLE_TO_UNLOAD_MEDIA
//
// MessageText:
//
// Unable to unload the media.
//
#define ERROR_UNABLE_TO_UNLOAD_MEDIA     ((ULONG)0x00000455L)

//
// MessageId: ERROR_MEDIA_CHANGED
//
// MessageText:
//
// The media in the drive may have changed.
//
#define ERROR_MEDIA_CHANGED              ((ULONG)0x00000456L)

//
// MessageId: ERROR_BUS_RESET
//
// MessageText:
//
// The I/O bus was reset.
//
#define ERROR_BUS_RESET                  ((ULONG)0x00000457L)

//
// MessageId: ERROR_NO_MEDIA_IN_DRIVE
//
// MessageText:
//
// No media in drive.
//
#define ERROR_NO_MEDIA_IN_DRIVE          ((ULONG)0x00000458L)

//
// MessageId: ERROR_NO_UNICODE_TRANSLATION
//
// MessageText:
//
// No mapping for the Unicode character exists in the target multi-byte code page.
//
#define ERROR_NO_UNICODE_TRANSLATION     ((ULONG)0x00000459L)

//
// MessageId: ERROR_DLL_INIT_FAILED
//
// MessageText:
//
// A dynamic link library (DLL) initialization routine failed.
//
#define ERROR_DLL_INIT_FAILED            ((ULONG)0x0000045AL)

//
// MessageId: ERROR_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// A system shutdown is in progress.
//
#define ERROR_SHUTDOWN_IN_PROGRESS       ((ULONG)0x0000045BL)

//
// MessageId: ERROR_NO_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// Unable to abort the system shutdown because no shutdown was in progress.
//
#define ERROR_NO_SHUTDOWN_IN_PROGRESS    ((ULONG)0x0000045CL)

//
// MessageId: ERROR_IO_DEVICE
//
// MessageText:
//
// The request could not be performed because of an I/O device error.
//
#define ERROR_IO_DEVICE                  ((ULONG)0x0000045DL)

//
// MessageId: ERROR_SERIAL_NO_DEVICE
//
// MessageText:
//
// No serial device was successfully initialized. The serial driver will unload.
//
#define ERROR_SERIAL_NO_DEVICE           ((ULONG)0x0000045EL)

//
// MessageId: ERROR_IRQ_BUSY
//
// MessageText:
//
// Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.
//
#define ERROR_IRQ_BUSY                   ((ULONG)0x0000045FL)

//
// MessageId: ERROR_MORE_WRITES
//
// MessageText:
//
// A serial I/O operation was completed by another write to the serial port. (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
//
#define ERROR_MORE_WRITES                ((ULONG)0x00000460L)

//
// MessageId: ERROR_COUNTER_TIMEOUT
//
// MessageText:
//
// A serial I/O operation completed because the timeout period expired. (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
//
#define ERROR_COUNTER_TIMEOUT            ((ULONG)0x00000461L)

//
// MessageId: ERROR_FLOPPY_ID_MARK_NOT_FOUND
//
// MessageText:
//
// No ID address mark was found on the floppy disk.
//
#define ERROR_FLOPPY_ID_MARK_NOT_FOUND   ((ULONG)0x00000462L)

//
// MessageId: ERROR_FLOPPY_WRONG_CYLINDER
//
// MessageText:
//
// Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
//
#define ERROR_FLOPPY_WRONG_CYLINDER      ((ULONG)0x00000463L)

//
// MessageId: ERROR_FLOPPY_UNKNOWN_ERROR
//
// MessageText:
//
// The floppy disk controller reported an error that is not recognized by the floppy disk driver.
//
#define ERROR_FLOPPY_UNKNOWN_ERROR       ((ULONG)0x00000464L)

//
// MessageId: ERROR_FLOPPY_BAD_REGISTERS
//
// MessageText:
//
// The floppy disk controller returned inconsistent results in its registers.
//
#define ERROR_FLOPPY_BAD_REGISTERS       ((ULONG)0x00000465L)

//
// MessageId: ERROR_DISK_RECALIBRATE_FAILED
//
// MessageText:
//
// While accessing the hard disk, a recalibrate operation failed, even after retries.
//
#define ERROR_DISK_RECALIBRATE_FAILED    ((ULONG)0x00000466L)

//
// MessageId: ERROR_DISK_OPERATION_FAILED
//
// MessageText:
//
// While accessing the hard disk, a disk operation failed even after retries.
//
#define ERROR_DISK_OPERATION_FAILED      ((ULONG)0x00000467L)

//
// MessageId: ERROR_DISK_RESET_FAILED
//
// MessageText:
//
// While accessing the hard disk, a disk controller reset was needed, but even that failed.
//
#define ERROR_DISK_RESET_FAILED          ((ULONG)0x00000468L)

//
// MessageId: ERROR_EOM_OVERFLOW
//
// MessageText:
//
// Physical end of tape encountered.
//
#define ERROR_EOM_OVERFLOW               ((ULONG)0x00000469L)

//
// MessageId: ERROR_NOT_ENOUGH_SERVER_MEMORY
//
// MessageText:
//
// Not enough server storage is available to process this command.
//
#define ERROR_NOT_ENOUGH_SERVER_MEMORY   ((ULONG)0x0000046AL)

//
// MessageId: ERROR_POSSIBLE_DEADLOCK
//
// MessageText:
//
// A potential deadlock condition has been detected.
//
#define ERROR_POSSIBLE_DEADLOCK          ((ULONG)0x0000046BL)

//
// MessageId: ERROR_MAPPED_ALIGNMENT
//
// MessageText:
//
// The base address or the file offset specified does not have the proper alignment.
//
#define ERROR_MAPPED_ALIGNMENT           ((ULONG)0x0000046CL)

//
// MessageId: ERROR_SET_POWER_STATE_VETOED
//
// MessageText:
//
// An attempt to change the system power state was vetoed by another application or driver.
//
#define ERROR_SET_POWER_STATE_VETOED     ((ULONG)0x00000474L)

//
// MessageId: ERROR_SET_POWER_STATE_FAILED
//
// MessageText:
//
// The system BIOS failed an attempt to change the system power state.
//
#define ERROR_SET_POWER_STATE_FAILED     ((ULONG)0x00000475L)

//
// MessageId: ERROR_TOO_MANY_LINKS
//
// MessageText:
//
// An attempt was made to create more links on a file than the file system supports.
//
#define ERROR_TOO_MANY_LINKS             ((ULONG)0x00000476L)

//
// MessageId: ERROR_OLD_WIN_VERSION
//
// MessageText:
//
// The specified program requires a newer version of ReactOS.
//
#define ERROR_OLD_WIN_VERSION            ((ULONG)0x0000047EL)

//
// MessageId: ERROR_APP_WRONG_OS
//
// MessageText:
//
// The specified program is not a Windows or MS-DOS program.
//
#define ERROR_APP_WRONG_OS               ((ULONG)0x0000047FL)

//
// MessageId: ERROR_SINGLE_INSTANCE_APP
//
// MessageText:
//
// Cannot start more than one instance of the specified program.
//
#define ERROR_SINGLE_INSTANCE_APP        ((ULONG)0x00000480L)

//
// MessageId: ERROR_RMODE_APP
//
// MessageText:
//
// The specified program was written for an earlier version of ReactOS.
//
#define ERROR_RMODE_APP                  ((ULONG)0x00000481L)

//
// MessageId: ERROR_INVALID_DLL
//
// MessageText:
//
// One of the library files needed to run this application is damaged.
//
#define ERROR_INVALID_DLL                ((ULONG)0x00000482L)

//
// MessageId: ERROR_NO_ASSOCIATION
//
// MessageText:
//
// No application is associated with the specified file for this operation.
//
#define ERROR_NO_ASSOCIATION             ((ULONG)0x00000483L)

//
// MessageId: ERROR_DDE_FAIL
//
// MessageText:
//
// An error occurred in sending the command to the application.
//
#define ERROR_DDE_FAIL                   ((ULONG)0x00000484L)

//
// MessageId: ERROR_DLL_NOT_FOUND
//
// MessageText:
//
// One of the library files needed to run this application cannot be found.
//
#define ERROR_DLL_NOT_FOUND              ((ULONG)0x00000485L)

//
// MessageId: ERROR_NO_MORE_USER_HANDLES
//
// MessageText:
//
// The current process has used all of its system allowance of handles for Window Manager objects.
//
#define ERROR_NO_MORE_USER_HANDLES       ((ULONG)0x00000486L)

//
// MessageId: ERROR_MESSAGE_SYNC_ONLY
//
// MessageText:
//
// The message can be used only with synchronous operations.
//
#define ERROR_MESSAGE_SYNC_ONLY          ((ULONG)0x00000487L)

//
// MessageId: ERROR_SOURCE_ELEMENT_EMPTY
//
// MessageText:
//
// The indicated source element has no media.
//
#define ERROR_SOURCE_ELEMENT_EMPTY       ((ULONG)0x00000488L)

//
// MessageId: ERROR_DESTINATION_ELEMENT_FULL
//
// MessageText:
//
// The indicated destination element already contains media.
//
#define ERROR_DESTINATION_ELEMENT_FULL   ((ULONG)0x00000489L)

//
// MessageId: ERROR_ILLEGAL_ELEMENT_ADDRESS
//
// MessageText:
//
// The indicated element does not exist.
//
#define ERROR_ILLEGAL_ELEMENT_ADDRESS    ((ULONG)0x0000048AL)

//
// MessageId: ERROR_MAGAZINE_NOT_PRESENT
//
// MessageText:
//
// The indicated element is part of a magazine that is not present.
//
#define ERROR_MAGAZINE_NOT_PRESENT       ((ULONG)0x0000048BL)

//
// MessageId: ERROR_DEVICE_REINITIALIZATION_NEEDED
//
// MessageText:
//
// The indicated device requires reinitialization due to hardware errors.
//
#define ERROR_DEVICE_REINITIALIZATION_NEEDED ((ULONG)0x0000048CL)

//
// MessageId: ERROR_DEVICE_REQUIRES_CLEANING
//
// MessageText:
//
// The device has indicated that cleaning is required before further operations are attempted.
//
#define ERROR_DEVICE_REQUIRES_CLEANING   ((ULONG)0x0000048DL)

//
// MessageId: ERROR_DEVICE_DOOR_OPEN
//
// MessageText:
//
// The device has indicated that its door is open.
//
#define ERROR_DEVICE_DOOR_OPEN           ((ULONG)0x0000048EL)

//
// MessageId: ERROR_DEVICE_NOT_CONNECTED
//
// MessageText:
//
// The device is not connected.
//
#define ERROR_DEVICE_NOT_CONNECTED       ((ULONG)0x0000048FL)

//
// MessageId: ERROR_NOT_FOUND
//
// MessageText:
//
// Element not found.
//
#define ERROR_NOT_FOUND                  ((ULONG)0x00000490L)

//
// MessageId: ERROR_NO_MATCH
//
// MessageText:
//
// There was no match for the specified key in the index.
//
#define ERROR_NO_MATCH                   ((ULONG)0x00000491L)

//
// MessageId: ERROR_SET_NOT_FOUND
//
// MessageText:
//
// The property set specified does not exist on the object.
//
#define ERROR_SET_NOT_FOUND              ((ULONG)0x00000492L)

//
// MessageId: ERROR_POINT_NOT_FOUND
//
// MessageText:
//
// The point passed to GetMouseMovePointsEx is not in the buffer.
//
#define ERROR_POINT_NOT_FOUND            ((ULONG)0x00000493L)

//
// MessageId: ERROR_NO_TRACKING_SERVICE
//
// MessageText:
//
// The tracking (workstation) service is not running.
//
#define ERROR_NO_TRACKING_SERVICE        ((ULONG)0x00000494L)

//
// MessageId: ERROR_NO_VOLUME_ID
//
// MessageText:
//
// The Volume ID could not be found.
//
#define ERROR_NO_VOLUME_ID               ((ULONG)0x00000495L)

//
// MessageId: ERROR_UNABLE_TO_REMOVE_REPLACED
//
// MessageText:
//
// Unable to remove the file to be replaced.
//
#define ERROR_UNABLE_TO_REMOVE_REPLACED  ((ULONG)0x00000497L)

//
// MessageId: ERROR_UNABLE_TO_MOVE_REPLACEMENT
//
// MessageText:
//
// Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.
//
#define ERROR_UNABLE_TO_MOVE_REPLACEMENT ((ULONG)0x00000498L)

//
// MessageId: ERROR_UNABLE_TO_MOVE_REPLACEMENT_2
//
// MessageText:
//
// Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.
//
#define ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 ((ULONG)0x00000499L)

//
// MessageId: ERROR_JOURNAL_DELETE_IN_PROGRESS
//
// MessageText:
//
// The volume change journal is being deleted.
//
#define ERROR_JOURNAL_DELETE_IN_PROGRESS ((ULONG)0x0000049AL)

//
// MessageId: ERROR_JOURNAL_NOT_ACTIVE
//
// MessageText:
//
// The volume change journal is not active.
//
#define ERROR_JOURNAL_NOT_ACTIVE         ((ULONG)0x0000049BL)

//
// MessageId: ERROR_POTENTIAL_FILE_FOUND
//
// MessageText:
//
// A file was found, but it may not be the correct file.
//
#define ERROR_POTENTIAL_FILE_FOUND       ((ULONG)0x0000049CL)

//
// MessageId: ERROR_JOURNAL_ENTRY_DELETED
//
// MessageText:
//
// The journal entry has been deleted from the journal.
//
#define ERROR_JOURNAL_ENTRY_DELETED      ((ULONG)0x0000049DL)

//
// MessageId: ERROR_BAD_DEVICE
//
// MessageText:
//
// The specified device name is invalid.
//
#define ERROR_BAD_DEVICE                 ((ULONG)0x000004B0L)

//
// MessageId: ERROR_CONNECTION_UNAVAIL
//
// MessageText:
//
// The device is not currently connected but it is a remembered connection.
//
#define ERROR_CONNECTION_UNAVAIL         ((ULONG)0x000004B1L)

//
// MessageId: ERROR_DEVICE_ALREADY_REMEMBERED
//
// MessageText:
//
// The local device name has a remembered connection to another network resource.
//
#define ERROR_DEVICE_ALREADY_REMEMBERED  ((ULONG)0x000004B2L)

//
// MessageId: ERROR_NO_NET_OR_BAD_PATH
//
// MessageText:
//
// The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.
//
#define ERROR_NO_NET_OR_BAD_PATH         ((ULONG)0x000004B3L)

//
// MessageId: ERROR_BAD_PROVIDER
//
// MessageText:
//
// The specified network provider name is invalid.
//
#define ERROR_BAD_PROVIDER               ((ULONG)0x000004B4L)

//
// MessageId: ERROR_CANNOT_OPEN_PROFILE
//
// MessageText:
//
// Unable to open the network connection profile.
//
#define ERROR_CANNOT_OPEN_PROFILE        ((ULONG)0x000004B5L)

//
// MessageId: ERROR_BAD_PROFILE
//
// MessageText:
//
// The network connection profile is corrupted.
//
#define ERROR_BAD_PROFILE                ((ULONG)0x000004B6L)

//
// MessageId: ERROR_NOT_CONTAINER
//
// MessageText:
//
// Cannot enumerate a noncontainer.
//
#define ERROR_NOT_CONTAINER              ((ULONG)0x000004B7L)

//
// MessageId: ERROR_EXTENDED_ERROR
//
// MessageText:
//
// An extended error has occurred.
//
#define ERROR_EXTENDED_ERROR             ((ULONG)0x000004B8L)

//
// MessageId: ERROR_INVALID_GROUPNAME
//
// MessageText:
//
// The format of the specified group name is invalid.
//
#define ERROR_INVALID_GROUPNAME          ((ULONG)0x000004B9L)

//
// MessageId: ERROR_INVALID_COMPUTERNAME
//
// MessageText:
//
// The format of the specified computer name is invalid.
//
#define ERROR_INVALID_COMPUTERNAME       ((ULONG)0x000004BAL)

//
// MessageId: ERROR_INVALID_EVENTNAME
//
// MessageText:
//
// The format of the specified event name is invalid.
//
#define ERROR_INVALID_EVENTNAME          ((ULONG)0x000004BBL)

//
// MessageId: ERROR_INVALID_DOMAINNAME
//
// MessageText:
//
// The format of the specified domain name is invalid.
//
#define ERROR_INVALID_DOMAINNAME         ((ULONG)0x000004BCL)

//
// MessageId: ERROR_INVALID_SERVICENAME
//
// MessageText:
//
// The format of the specified service name is invalid.
//
#define ERROR_INVALID_SERVICENAME        ((ULONG)0x000004BDL)

//
// MessageId: ERROR_INVALID_NETNAME
//
// MessageText:
//
// The format of the specified network name is invalid.
//
#define ERROR_INVALID_NETNAME            ((ULONG)0x000004BEL)

//
// MessageId: ERROR_INVALID_SHARENAME
//
// MessageText:
//
// The format of the specified share name is invalid.
//
#define ERROR_INVALID_SHARENAME          ((ULONG)0x000004BFL)

//
// MessageId: ERROR_INVALID_PASSWORDNAME
//
// MessageText:
//
// The format of the specified password is invalid.
//
#define ERROR_INVALID_PASSWORDNAME       ((ULONG)0x000004C0L)

//
// MessageId: ERROR_INVALID_MESSAGENAME
//
// MessageText:
//
// The format of the specified message name is invalid.
//
#define ERROR_INVALID_MESSAGENAME        ((ULONG)0x000004C1L)

//
// MessageId: ERROR_INVALID_MESSAGEDEST
//
// MessageText:
//
// The format of the specified message destination is invalid.
//
#define ERROR_INVALID_MESSAGEDEST        ((ULONG)0x000004C2L)

//
// MessageId: ERROR_SESSION_CREDENTIAL_CONFLICT
//
// MessageText:
//
// Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.
//
#define ERROR_SESSION_CREDENTIAL_CONFLICT ((ULONG)0x000004C3L)

//
// MessageId: ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
//
#define ERROR_REMOTE_SESSION_LIMIT_EXCEEDED ((ULONG)0x000004C4L)

//
// MessageId: ERROR_DUP_DOMAINNAME
//
// MessageText:
//
// The workgroup or domain name is already in use by another computer on the network.
//
#define ERROR_DUP_DOMAINNAME             ((ULONG)0x000004C5L)

//
// MessageId: ERROR_NO_NETWORK
//
// MessageText:
//
// The network is not present or not started.
//
#define ERROR_NO_NETWORK                 ((ULONG)0x000004C6L)

//
// MessageId: ERROR_CANCELLED
//
// MessageText:
//
// The operation was canceled by the user.
//
#define ERROR_CANCELLED                  ((ULONG)0x000004C7L)

//
// MessageId: ERROR_USER_MAPPED_FILE
//
// MessageText:
//
// The requested operation cannot be performed on a file with a user-mapped section open.
//
#define ERROR_USER_MAPPED_FILE           ((ULONG)0x000004C8L)

//
// MessageId: ERROR_CONNECTION_REFUSED
//
// MessageText:
//
// The remote system refused the network connection.
//
#define ERROR_CONNECTION_REFUSED         ((ULONG)0x000004C9L)

//
// MessageId: ERROR_GRACEFUL_DISCONNECT
//
// MessageText:
//
// The network connection was gracefully closed.
//
#define ERROR_GRACEFUL_DISCONNECT        ((ULONG)0x000004CAL)

//
// MessageId: ERROR_ADDRESS_ALREADY_ASSOCIATED
//
// MessageText:
//
// The network transport endpoint already has an address associated with it.
//
#define ERROR_ADDRESS_ALREADY_ASSOCIATED ((ULONG)0x000004CBL)

//
// MessageId: ERROR_ADDRESS_NOT_ASSOCIATED
//
// MessageText:
//
// An address has not yet been associated with the network endpoint.
//
#define ERROR_ADDRESS_NOT_ASSOCIATED     ((ULONG)0x000004CCL)

//
// MessageId: ERROR_CONNECTION_INVALID
//
// MessageText:
//
// An operation was attempted on a nonexistent network connection.
//
#define ERROR_CONNECTION_INVALID         ((ULONG)0x000004CDL)

//
// MessageId: ERROR_CONNECTION_ACTIVE
//
// MessageText:
//
// An invalid operation was attempted on an active network connection.
//
#define ERROR_CONNECTION_ACTIVE          ((ULONG)0x000004CEL)

//
// MessageId: ERROR_NETWORK_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see ReactOS Help.
//
#define ERROR_NETWORK_UNREACHABLE        ((ULONG)0x000004CFL)

//
// MessageId: ERROR_HOST_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see ReactOS Help.
//
#define ERROR_HOST_UNREACHABLE           ((ULONG)0x000004D0L)

//
// MessageId: ERROR_PROTOCOL_UNREACHABLE
//
// MessageText:
//
// The network location cannot be reached. For information about network troubleshooting, see ReactOS Help.
//
#define ERROR_PROTOCOL_UNREACHABLE       ((ULONG)0x000004D1L)

//
// MessageId: ERROR_PORT_UNREACHABLE
//
// MessageText:
//
// No service is operating at the destination network endpoint on the remote system.
//
#define ERROR_PORT_UNREACHABLE           ((ULONG)0x000004D2L)

//
// MessageId: ERROR_REQUEST_ABORTED
//
// MessageText:
//
// The request was aborted.
//
#define ERROR_REQUEST_ABORTED            ((ULONG)0x000004D3L)

//
// MessageId: ERROR_CONNECTION_ABORTED
//
// MessageText:
//
// The network connection was aborted by the local system.
//
#define ERROR_CONNECTION_ABORTED         ((ULONG)0x000004D4L)

//
// MessageId: ERROR_RETRY
//
// MessageText:
//
// The operation could not be completed. A retry should be performed.
//
#define ERROR_RETRY                      ((ULONG)0x000004D5L)

//
// MessageId: ERROR_CONNECTION_COUNT_LIMIT
//
// MessageText:
//
// A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
//
#define ERROR_CONNECTION_COUNT_LIMIT     ((ULONG)0x000004D6L)

//
// MessageId: ERROR_LOGIN_TIME_RESTRICTION
//
// MessageText:
//
// Attempting to log in during an unauthorized time of day for this account.
//
#define ERROR_LOGIN_TIME_RESTRICTION     ((ULONG)0x000004D7L)

//
// MessageId: ERROR_LOGIN_WKSTA_RESTRICTION
//
// MessageText:
//
// The account is not authorized to log in from this station.
//
#define ERROR_LOGIN_WKSTA_RESTRICTION    ((ULONG)0x000004D8L)

//
// MessageId: ERROR_INCORRECT_ADDRESS
//
// MessageText:
//
// The network address could not be used for the operation requested.
//
#define ERROR_INCORRECT_ADDRESS          ((ULONG)0x000004D9L)

//
// MessageId: ERROR_ALREADY_REGISTERED
//
// MessageText:
//
// The service is already registered.
//
#define ERROR_ALREADY_REGISTERED         ((ULONG)0x000004DAL)

//
// MessageId: ERROR_SERVICE_NOT_FOUND
//
// MessageText:
//
// The specified service does not exist.
//
#define ERROR_SERVICE_NOT_FOUND          ((ULONG)0x000004DBL)

//
// MessageId: ERROR_NOT_AUTHENTICATED
//
// MessageText:
//
// The operation being requested was not performed because the user has not been authenticated.
//
#define ERROR_NOT_AUTHENTICATED          ((ULONG)0x000004DCL)

//
// MessageId: ERROR_NOT_LOGGED_ON
//
// MessageText:
//
// The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.
//
#define ERROR_NOT_LOGGED_ON              ((ULONG)0x000004DDL)

//
// MessageId: ERROR_CONTINUE
//
// MessageText:
//
// Continue with work in progress.
//
#define ERROR_CONTINUE                   ((ULONG)0x000004DEL)

//
// MessageId: ERROR_ALREADY_INITIALIZED
//
// MessageText:
//
// An attempt was made to perform an initialization operation when initialization has already been completed.
//
#define ERROR_ALREADY_INITIALIZED        ((ULONG)0x000004DFL)

//
// MessageId: ERROR_NO_MORE_DEVICES
//
// MessageText:
//
// No more local devices.
//
#define ERROR_NO_MORE_DEVICES            ((ULONG)0x000004E0L)

//
// MessageId: ERROR_NO_SUCH_SITE
//
// MessageText:
//
// The specified site does not exist.
//
#define ERROR_NO_SUCH_SITE               ((ULONG)0x000004E1L)

//
// MessageId: ERROR_DOMAIN_CONTROLLER_EXISTS
//
// MessageText:
//
// A domain controller with the specified name already exists.
//
#define ERROR_DOMAIN_CONTROLLER_EXISTS   ((ULONG)0x000004E2L)

//
// MessageId: ERROR_ONLY_IF_CONNECTED
//
// MessageText:
//
// This operation is supported only when you are connected to the server.
//
#define ERROR_ONLY_IF_CONNECTED          ((ULONG)0x000004E3L)

//
// MessageId: ERROR_OVERRIDE_NOCHANGES
//
// MessageText:
//
// The group policy framework should call the extension even if there are no changes.
//
#define ERROR_OVERRIDE_NOCHANGES         ((ULONG)0x000004E4L)

//
// MessageId: ERROR_BAD_USER_PROFILE
//
// MessageText:
//
// The specified user does not have a valid profile.
//
#define ERROR_BAD_USER_PROFILE           ((ULONG)0x000004E5L)

//
// MessageId: ERROR_NOT_SUPPORTED_ON_SBS
//
// MessageText:
//
// This operation is not supported on a computer running Windows Server 2003 for Small Business Server.
//
#define ERROR_NOT_SUPPORTED_ON_SBS       ((ULONG)0x000004E6L)

//
// MessageId: ERROR_SERVER_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// The server machine is shutting down.
//
#define ERROR_SERVER_SHUTDOWN_IN_PROGRESS ((ULONG)0x000004E7L)

//
// MessageId: ERROR_HOST_DOWN
//
// MessageText:
//
// The remote system is not available. For information about network troubleshooting, see ReactOS Help.
//
#define ERROR_HOST_DOWN                  ((ULONG)0x000004E8L)

//
// MessageId: ERROR_NON_ACCOUNT_SID
//
// MessageText:
//
// The security identifier provided is not from an account domain.
//
#define ERROR_NON_ACCOUNT_SID            ((ULONG)0x000004E9L)

//
// MessageId: ERROR_NON_DOMAIN_SID
//
// MessageText:
//
// The security identifier provided does not have a domain component.
//
#define ERROR_NON_DOMAIN_SID             ((ULONG)0x000004EAL)

//
// MessageId: ERROR_APPHELP_BLOCK
//
// MessageText:
//
// AppHelp dialog canceled thus preventing the application from starting.
//
#define ERROR_APPHELP_BLOCK              ((ULONG)0x000004EBL)

//
// MessageId: ERROR_ACCESS_DISABLED_BY_POLICY
//
// MessageText:
//
// ReactOS cannot open this program because it has been prevented by a software restriction policy. For more information, open Event Viewer or contact your system administrator.
//
#define ERROR_ACCESS_DISABLED_BY_POLICY  ((ULONG)0x000004ECL)

//
// MessageId: ERROR_REG_NAT_CONSUMPTION
//
// MessageText:
//
// A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.
//
#define ERROR_REG_NAT_CONSUMPTION        ((ULONG)0x000004EDL)

//
// MessageId: ERROR_CSCSHARE_OFFLINE
//
// MessageText:
//
// The share is currently offline or does not exist.
//
#define ERROR_CSCSHARE_OFFLINE           ((ULONG)0x000004EEL)

//
// MessageId: ERROR_PKINIT_FAILURE
//
// MessageText:
//
// The kerberos protocol encountered an error while validating the KDC certificate during smartcard logon.
//
#define ERROR_PKINIT_FAILURE             ((ULONG)0x000004EFL)

//
// MessageId: ERROR_SMARTCARD_SUBSYSTEM_FAILURE
//
// MessageText:
//
// The kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
//
#define ERROR_SMARTCARD_SUBSYSTEM_FAILURE ((ULONG)0x000004F0L)

//
// MessageId: ERROR_DOWNGRADE_DETECTED
//
// MessageText:
//
// The system detected a possible attempt to compromise security. Please ensure that you can contact the server that authenticated you.
//
#define ERROR_DOWNGRADE_DETECTED         ((ULONG)0x000004F1L)

//
// MessageId: SEC_E_SMARTCARD_CERT_REVOKED
//
// MessageText:
//
// The smartcard certificate used for authentication has been revoked. Please contact your system administrator. There may be additional information in the event log.
//
#define SEC_E_SMARTCARD_CERT_REVOKED     ((ULONG)0x000004F2L)

//
// MessageId: SEC_E_ISSUING_CA_UNTRUSTED
//
// MessageText:
//
// An untrusted certificate authority was detected while processing the smartcard certificate used for authentication. Please contact your system administrator.
//
#define SEC_E_ISSUING_CA_UNTRUSTED       ((ULONG)0x000004F3L)

//
// MessageId: SEC_E_REVOCATION_OFFLINE_C
//
// MessageText:
//
// The revocation status of the smartcard certificate used for authentication could not be determined. Please contact your system administrator.
//
#define SEC_E_REVOCATION_OFFLINE_C       ((ULONG)0x000004F4L)

//
// MessageId: SEC_E_PKINIT_CLIENT_FAILUR
//
// MessageText:
//
// The smartcard certificate used for authentication was not trusted. Please contact your system administrator.
//
#define SEC_E_PKINIT_CLIENT_FAILUR       ((ULONG)0x000004F5L)

//
// MessageId: SEC_E_SMARTCARD_CERT_EXPIRED
//
// MessageText:
//
// The smartcard certificate used for authentication has expired. Please contact your system administrator.
//
#define SEC_E_SMARTCARD_CERT_EXPIRED     ((ULONG)0x000004F6L)

//
// MessageId: ERROR_MACHINE_LOCKED
//
// MessageText:
//
// The machine is locked and cannot be shut down without the force option.
//
#define ERROR_MACHINE_LOCKED             ((ULONG)0x000004F7L)

//
// MessageId: ERROR_CALLBACK_SUPPLIED_INVALID_DATA
//
// MessageText:
//
// An application-defined callback gave invalid data when called.
//
#define ERROR_CALLBACK_SUPPLIED_INVALID_DATA ((ULONG)0x000004F9L)

//
// MessageId: ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED
//
// MessageText:
//
// The group policy framework should call the extension in the synchronous foreground policy refresh.
//
#define ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED ((ULONG)0x000004FAL)

//
// MessageId: ERROR_DRIVER_BLOCKED
//
// MessageText:
//
// This driver has been blocked from loading.
//
#define ERROR_DRIVER_BLOCKED             ((ULONG)0x000004FBL)

//
// MessageId: ERROR_INVALID_IMPORT_OF_NON_DLL
//
// MessageText:
//
// A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.
//
#define ERROR_INVALID_IMPORT_OF_NON_DLL  ((ULONG)0x000004FCL)

//
// MessageId: ERROR_ACCESS_DISABLED_WEBBLADE
//
// MessageText:
//
// ReactOS cannot open this program since it has been disabled.
//
#define ERROR_ACCESS_DISABLED_WEBBLADE   ((ULONG)0x000004FDL)

//
// MessageId: ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER
//
// MessageText:
//
// ReactOS cannot open this program because the license enforcement system has been tampered with or become corrupted.
//
#define ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER ((ULONG)0x000004FEL)

//
// MessageId: ERROR_RECOVERY_FAILURE
//
// MessageText:
//
// A transaction recovery failed.
//
#define ERROR_RECOVERY_FAILURE           ((ULONG)0x000004FFL)

//
// MessageId: ERROR_ALREADY_FIBER
//
// MessageText:
//
// The current thread has already been converted to a fiber.
//
#define ERROR_ALREADY_FIBER              ((ULONG)0x00000500L)

//
// MessageId: ERROR_ALREADY_THREAD
//
// MessageText:
//
// The current thread has already been converted from a fiber.
//
#define ERROR_ALREADY_THREAD             ((ULONG)0x00000501L)

//
// MessageId: ERROR_STACK_BUFFER_OVERRUN
//
// MessageText:
//
// The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.
//
#define ERROR_STACK_BUFFER_OVERRUN       ((ULONG)0x00000502L)

//
// MessageId: ERROR_PARAMETER_QUOTA_EXCEEDED
//
// MessageText:
//
// Data present in one of the parameters is more than the function can operate on.
//
#define ERROR_PARAMETER_QUOTA_EXCEEDED   ((ULONG)0x00000503L)

//
// MessageId: ERROR_DEBUGGER_INACTIVE
//
// MessageText:
//
// An attempt to do an operation on a debug object failed because the object is in the process of being deleted.
//
#define ERROR_DEBUGGER_INACTIVE          ((ULONG)0x00000504L)

//
// MessageId: ERROR_DELAY_LOAD_FAILED
//
// MessageText:
//
// An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
//
#define ERROR_DELAY_LOAD_FAILED          ((ULONG)0x00000505L)

//
// MessageId: ERROR_VDM_DISALLOWED
//
// MessageText:
//
// %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.
//
#define ERROR_VDM_DISALLOWED             ((ULONG)0x00000506L)

//
// MessageId: ERROR_UNIDENTIFIED_ERROR
//
// MessageText:
//
// Insufficient information exists to identify the cause of failure.
//
#define ERROR_UNIDENTIFIED_ERROR         ((ULONG)0x00000507L)

//
// MessageId: ERROR_INVALID_BANDWIDTH_PARAMETERS
//
// MessageText:
//
// An invalid budget or period parameter was specified.
//
#define ERROR_INVALID_BANDWIDTH_PARAMETERS ((ULONG)0x00000508L)

//
// MessageId: ERROR_AFFINITY_NOT_COMPATIBLE
//
// MessageText:
//
// An attempt was made to join a thread to a reserve whose affinity did not intersect the reserve affinity or an attempt was made to associate a process with a reserve whose affinity did not intersect the reserve affinity.
//
#define ERROR_AFFINITY_NOT_COMPATIBLE    ((ULONG)0x00000509L)

//
// MessageId: ERROR_THREAD_ALREADY_IN_RESERVE
//
// MessageText:
//
// An attempt was made to join a thread to a reserve which was already joined to another reserve.
//
#define ERROR_THREAD_ALREADY_IN_RESERVE  ((ULONG)0x0000050AL)

//
// MessageId: ERROR_THREAD_NOT_IN_RESERVE
//
// MessageText:
//
// An attempt was made to disjoin a thread from a reserve, but the thread was not joined to the reserve.
//
#define ERROR_THREAD_NOT_IN_RESERVE      ((ULONG)0x0000050BL)

//
// MessageId: ERROR_THREAD_PROCESS_IN_RESERVE
//
// MessageText:
//
// An attempt was made to disjoin a thread from a reserve whose process is associated with a reserve.
//
#define ERROR_THREAD_PROCESS_IN_RESERVE  ((ULONG)0x0000050CL)

//
// MessageId: ERROR_PROCESS_ALREADY_IN_RESERVE
//
// MessageText:
//
// An attempt was made to associate a process with a reserve that was already associated with a reserve.
//
#define ERROR_PROCESS_ALREADY_IN_RESERVE ((ULONG)0x0000050DL)

//
// MessageId: ERROR_PROCESS_NOT_IN_RESERVE
//
// MessageText:
//
// An attempt was made to disassociate a process from a reserve, but the process did not have an associated reserve.
//
#define ERROR_PROCESS_NOT_IN_RESERVE     ((ULONG)0x0000050EL)

//
// MessageId: ERROR_PROCESS_THREADS_IN_RESERVE
//
// MessageText:
//
// An attempt was made to associate a process with a reserve, but the process contained thread joined to a reserve.
//
#define ERROR_PROCESS_THREADS_IN_RESERVE ((ULONG)0x0000050FL)

//
// MessageId: ERROR_AFFINITY_NOT_SET_IN_RESERVE
//
// MessageText:
//
// An attempt was made to set the affinity of a thread or a process, but the thread or process was joined or associated with a reserve.
//
#define ERROR_AFFINITY_NOT_SET_IN_RESERVE ((ULONG)0x00000510L)

//
// MessageId: ERROR_IMPLEMENTATION_LIMIT
//
// MessageText:
//
// An operation attempted to exceed an implementation-defined limit.
//
#define ERROR_IMPLEMENTATION_LIMIT       ((ULONG)0x00000511L)

//
// MessageId: ERROR_DS_CACHE_ONLY
//
// MessageText:
//
// The requested object is for internal DS operations only.
//
#define ERROR_DS_CACHE_ONLY              ((ULONG)0x00000512L)

//
// MessageId: ERROR_NOT_ALL_ASSIGNED
//
// MessageText:
//
// Not all privileges referenced are assigned to the caller.
//
#define ERROR_NOT_ALL_ASSIGNED           ((ULONG)0x00000514L)

//
// MessageId: ERROR_SOME_NOT_MAPPED
//
// MessageText:
//
// Some mapping between account names and security IDs was not done.
//
#define ERROR_SOME_NOT_MAPPED            ((ULONG)0x00000515L)

//
// MessageId: ERROR_NO_QUOTAS_FOR_ACCOUNT
//
// MessageText:
//
// No system quota limits are specifically set for this account.
//
#define ERROR_NO_QUOTAS_FOR_ACCOUNT      ((ULONG)0x00000516L)

//
// MessageId: ERROR_LOCAL_USER_SESSION_KEY
//
// MessageText:
//
// No encryption key is available. A well-known encryption key was returned.
//
#define ERROR_LOCAL_USER_SESSION_KEY     ((ULONG)0x00000517L)

//
// MessageId: ERROR_NULL_LM_PASSWORD
//
// MessageText:
//
// The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.
//
#define ERROR_NULL_LM_PASSWORD           ((ULONG)0x00000518L)

//
// MessageId: ERROR_UNKNOWN_REVISION
//
// MessageText:
//
// The revision level is unknown.
//
#define ERROR_UNKNOWN_REVISION           ((ULONG)0x00000519L)

//
// MessageId: ERROR_REVISION_MISMATCH
//
// MessageText:
//
// Indicates two revision levels are incompatible.
//
#define ERROR_REVISION_MISMATCH          ((ULONG)0x0000051AL)

//
// MessageId: ERROR_INVALID_OWNER
//
// MessageText:
//
// This security ID may not be assigned as the owner of this object.
//
#define ERROR_INVALID_OWNER              ((ULONG)0x0000051BL)

//
// MessageId: ERROR_INVALID_PRIMARY_GROUP
//
// MessageText:
//
// This security ID may not be assigned as the primary group of an object.
//
#define ERROR_INVALID_PRIMARY_GROUP      ((ULONG)0x0000051CL)

//
// MessageId: ERROR_NO_IMPERSONATION_TOKEN
//
// MessageText:
//
// An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
//
#define ERROR_NO_IMPERSONATION_TOKEN     ((ULONG)0x0000051DL)

//
// MessageId: ERROR_CANT_DISABLE_MANDATORY
//
// MessageText:
//
// The group may not be disabled.
//
#define ERROR_CANT_DISABLE_MANDATORY     ((ULONG)0x0000051EL)

//
// MessageId: ERROR_NO_LOGON_SERVERS
//
// MessageText:
//
// There are currently no logon servers available to service the logon request.
//
#define ERROR_NO_LOGON_SERVERS           ((ULONG)0x0000051FL)

//
// MessageId: ERROR_NO_SUCH_LOGON_SESSION
//
// MessageText:
//
// A specified logon session does not exist. It may already have been terminated.
//
#define ERROR_NO_SUCH_LOGON_SESSION      ((ULONG)0x00000520L)

//
// MessageId: ERROR_NO_SUCH_PRIVILEGE
//
// MessageText:
//
// A specified privilege does not exist.
//
#define ERROR_NO_SUCH_PRIVILEGE          ((ULONG)0x00000521L)

//
// MessageId: ERROR_PRIVILEGE_NOT_HELD
//
// MessageText:
//
// A required privilege is not held by the client.
//
#define ERROR_PRIVILEGE_NOT_HELD         ((ULONG)0x00000522L)

//
// MessageId: ERROR_INVALID_ACCOUNT_NAME
//
// MessageText:
//
// The name provided is not a properly formed account name.
//
#define ERROR_INVALID_ACCOUNT_NAME       ((ULONG)0x00000523L)

//
// MessageId: ERROR_USER_EXISTS
//
// MessageText:
//
// The specified user already exists.
//
#define ERROR_USER_EXISTS                ((ULONG)0x00000524L)

//
// MessageId: ERROR_NO_SUCH_USER
//
// MessageText:
//
// The specified user does not exist.
//
#define ERROR_NO_SUCH_USER               ((ULONG)0x00000525L)

//
// MessageId: ERROR_GROUP_EXISTS
//
// MessageText:
//
// The specified group already exists.
//
#define ERROR_GROUP_EXISTS               ((ULONG)0x00000526L)

//
// MessageId: ERROR_NO_SUCH_GROUP
//
// MessageText:
//
// The specified group does not exist.
//
#define ERROR_NO_SUCH_GROUP              ((ULONG)0x00000527L)

//
// MessageId: ERROR_MEMBER_IN_GROUP
//
// MessageText:
//
// Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.
//
#define ERROR_MEMBER_IN_GROUP            ((ULONG)0x00000528L)

//
// MessageId: ERROR_MEMBER_NOT_IN_GROUP
//
// MessageText:
//
// The specified user account is not a member of the specified group account.
//
#define ERROR_MEMBER_NOT_IN_GROUP        ((ULONG)0x00000529L)

//
// MessageId: ERROR_LAST_ADMIN
//
// MessageText:
//
// The last remaining administration account cannot be disabled or deleted.
//
#define ERROR_LAST_ADMIN                 ((ULONG)0x0000052AL)

//
// MessageId: ERROR_WRONG_PASSWORD
//
// MessageText:
//
// Unable to update the password. The value provided as the current password is incorrect.
//
#define ERROR_WRONG_PASSWORD             ((ULONG)0x0000052BL)

//
// MessageId: ERROR_ILL_FORMED_PASSWORD
//
// MessageText:
//
// Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.
//
#define ERROR_ILL_FORMED_PASSWORD        ((ULONG)0x0000052CL)

//
// MessageId: ERROR_PASSWORD_RESTRICTION
//
// MessageText:
//
// Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirement of the domain.
//
#define ERROR_PASSWORD_RESTRICTION       ((ULONG)0x0000052DL)

//
// MessageId: ERROR_LOGON_FAILURE
//
// MessageText:
//
// Logon failure: unknown user name or bad password.
//
#define ERROR_LOGON_FAILURE              ((ULONG)0x0000052EL)

//
// MessageId: ERROR_ACCOUNT_RESTRICTION
//
// MessageText:
//
// Logon failure: user account restriction. Possible reasons are blank passwords not allowed, logon hour restrictions, or a policy restriction has been enforced.
//
#define ERROR_ACCOUNT_RESTRICTION        ((ULONG)0x0000052FL)

//
// MessageId: ERROR_INVALID_LOGON_HOURS
//
// MessageText:
//
// Logon failure: account logon time restriction violation.
//
#define ERROR_INVALID_LOGON_HOURS        ((ULONG)0x00000530L)

//
// MessageId: ERROR_INVALID_WORKSTATION
//
// MessageText:
//
// Logon failure: user not allowed to log on to this computer.
//
#define ERROR_INVALID_WORKSTATION        ((ULONG)0x00000531L)

//
// MessageId: ERROR_PASSWORD_EXPIRED
//
// MessageText:
//
// Logon failure: the specified account password has expired.
//
#define ERROR_PASSWORD_EXPIRED           ((ULONG)0x00000532L)

//
// MessageId: ERROR_ACCOUNT_DISABLED
//
// MessageText:
//
// Logon failure: account currently disabled.
//
#define ERROR_ACCOUNT_DISABLED           ((ULONG)0x00000533L)

//
// MessageId: ERROR_NONE_MAPPED
//
// MessageText:
//
// No mapping between account names and security IDs was done.
//
#define ERROR_NONE_MAPPED                ((ULONG)0x00000534L)

//
// MessageId: ERROR_TOO_MANY_LUIDS_REQUESTED
//
// MessageText:
//
// Too many local user identifiers (LUIDs) were requested at one time.
//
#define ERROR_TOO_MANY_LUIDS_REQUESTED   ((ULONG)0x00000535L)

//
// MessageId: ERROR_LUIDS_EXHAUSTED
//
// MessageText:
//
// No more local user identifiers (LUIDs) are available.
//
#define ERROR_LUIDS_EXHAUSTED            ((ULONG)0x00000536L)

//
// MessageId: ERROR_INVALID_SUB_AUTHORITY
//
// MessageText:
//
// The subauthority part of a security ID is invalid for this particular use.
//
#define ERROR_INVALID_SUB_AUTHORITY      ((ULONG)0x00000537L)

//
// MessageId: ERROR_INVALID_ACL
//
// MessageText:
//
// The access control list (ACL) structure is invalid.
//
#define ERROR_INVALID_ACL                ((ULONG)0x00000538L)

//
// MessageId: ERROR_INVALID_SID
//
// MessageText:
//
// The security ID structure is invalid.
//
#define ERROR_INVALID_SID                ((ULONG)0x00000539L)

//
// MessageId: ERROR_INVALID_SECURITY_DESCR
//
// MessageText:
//
// The security descriptor structure is invalid.
//
#define ERROR_INVALID_SECURITY_DESCR     ((ULONG)0x0000053AL)

//
// MessageId: ERROR_BAD_INHERITANCE_ACL
//
// MessageText:
//
// The inherited access control list (ACL) or access control entry (ACE) could not be built.
//
#define ERROR_BAD_INHERITANCE_ACL        ((ULONG)0x0000053CL)

//
// MessageId: ERROR_SERVER_DISABLED
//
// MessageText:
//
// The server is currently disabled.
//
#define ERROR_SERVER_DISABLED            ((ULONG)0x0000053DL)

//
// MessageId: ERROR_SERVER_NOT_DISABLED
//
// MessageText:
//
// The server is currently enabled.
//
#define ERROR_SERVER_NOT_DISABLED        ((ULONG)0x0000053EL)

//
// MessageId: ERROR_INVALID_ID_AUTHORITY
//
// MessageText:
//
// The value provided was an invalid value for an identifier authority.
//
#define ERROR_INVALID_ID_AUTHORITY       ((ULONG)0x0000053FL)

//
// MessageId: ERROR_ALLOTTED_SPACE_EXCEEDED
//
// MessageText:
//
// No more memory is available for security information updates.
//
#define ERROR_ALLOTTED_SPACE_EXCEEDED    ((ULONG)0x00000540L)

//
// MessageId: ERROR_INVALID_GROUP_ATTRIBUTES
//
// MessageText:
//
// The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
//
#define ERROR_INVALID_GROUP_ATTRIBUTES   ((ULONG)0x00000541L)

//
// MessageId: ERROR_BAD_IMPERSONATION_LEVEL
//
// MessageText:
//
// Either a required impersonation level was not provided, or the provided impersonation level is invalid.
//
#define ERROR_BAD_IMPERSONATION_LEVEL    ((ULONG)0x00000542L)

//
// MessageId: ERROR_CANT_OPEN_ANONYMOUS
//
// MessageText:
//
// Cannot open an anonymous level security token.
//
#define ERROR_CANT_OPEN_ANONYMOUS        ((ULONG)0x00000543L)

//
// MessageId: ERROR_BAD_VALIDATION_CLASS
//
// MessageText:
//
// The validation information class requested was invalid.
//
#define ERROR_BAD_VALIDATION_CLASS       ((ULONG)0x00000544L)

//
// MessageId: ERROR_BAD_TOKEN_TYPE
//
// MessageText:
//
// The type of the token is inappropriate for its attempted use.
//
#define ERROR_BAD_TOKEN_TYPE             ((ULONG)0x00000545L)

//
// MessageId: ERROR_NO_SECURITY_ON_OBJECT
//
// MessageText:
//
// Unable to perform a security operation on an object that has no associated security.
//
#define ERROR_NO_SECURITY_ON_OBJECT      ((ULONG)0x00000546L)

//
// MessageId: ERROR_CANT_ACCESS_DOMAIN_INFO
//
// MessageText:
//
// Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
//
#define ERROR_CANT_ACCESS_DOMAIN_INFO    ((ULONG)0x00000547L)

//
// MessageId: ERROR_INVALID_SERVER_STATE
//
// MessageText:
//
// The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.
//
#define ERROR_INVALID_SERVER_STATE       ((ULONG)0x00000548L)

//
// MessageId: ERROR_INVALID_DOMAIN_STATE
//
// MessageText:
//
// The domain was in the wrong state to perform the security operation.
//
#define ERROR_INVALID_DOMAIN_STATE       ((ULONG)0x00000549L)

//
// MessageId: ERROR_INVALID_DOMAIN_ROLE
//
// MessageText:
//
// This operation is only allowed for the Primary Domain Controller of the domain.
//
#define ERROR_INVALID_DOMAIN_ROLE        ((ULONG)0x0000054AL)

//
// MessageId: ERROR_NO_SUCH_DOMAIN
//
// MessageText:
//
// The specified domain either does not exist or could not be contacted.
//
#define ERROR_NO_SUCH_DOMAIN             ((ULONG)0x0000054BL)

//
// MessageId: ERROR_DOMAIN_EXISTS
//
// MessageText:
//
// The specified domain already exists.
//
#define ERROR_DOMAIN_EXISTS              ((ULONG)0x0000054CL)

//
// MessageId: ERROR_DOMAIN_LIMIT_EXCEEDED
//
// MessageText:
//
// An attempt was made to exceed the limit on the number of domains per server.
//
#define ERROR_DOMAIN_LIMIT_EXCEEDED      ((ULONG)0x0000054DL)

//
// MessageId: ERROR_INTERNAL_DB_CORRUPTION
//
// MessageText:
//
// Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.
//
#define ERROR_INTERNAL_DB_CORRUPTION     ((ULONG)0x0000054EL)

//
// MessageId: ERROR_INTERNAL_ERROR
//
// MessageText:
//
// An internal error occurred.
//
#define ERROR_INTERNAL_ERROR             ((ULONG)0x0000054FL)

//
// MessageId: ERROR_GENERIC_NOT_MAPPED
//
// MessageText:
//
// Generic access types were contained in an access mask which should already be mapped to nongeneric types.
//
#define ERROR_GENERIC_NOT_MAPPED         ((ULONG)0x00000550L)

//
// MessageId: ERROR_BAD_DESCRIPTOR_FORMAT
//
// MessageText:
//
// A security descriptor is not in the right format (absolute or self-relative).
//
#define ERROR_BAD_DESCRIPTOR_FORMAT      ((ULONG)0x00000551L)

//
// MessageId: ERROR_NOT_LOGON_PROCESS
//
// MessageText:
//
// The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.
//
#define ERROR_NOT_LOGON_PROCESS          ((ULONG)0x00000552L)

//
// MessageId: ERROR_LOGON_SESSION_EXISTS
//
// MessageText:
//
// Cannot start a new logon session with an ID that is already in use.
//
#define ERROR_LOGON_SESSION_EXISTS       ((ULONG)0x00000553L)

//
// MessageId: ERROR_NO_SUCH_PACKAGE
//
// MessageText:
//
// A specified authentication package is unknown.
//
#define ERROR_NO_SUCH_PACKAGE            ((ULONG)0x00000554L)

//
// MessageId: ERROR_BAD_LOGON_SESSION_STATE
//
// MessageText:
//
// The logon session is not in a state that is consistent with the requested operation.
//
#define ERROR_BAD_LOGON_SESSION_STATE    ((ULONG)0x00000555L)

//
// MessageId: ERROR_LOGON_SESSION_COLLISION
//
// MessageText:
//
// The logon session ID is already in use.
//
#define ERROR_LOGON_SESSION_COLLISION    ((ULONG)0x00000556L)

//
// MessageId: ERROR_INVALID_LOGON_TYPE
//
// MessageText:
//
// A logon request contained an invalid logon type value.
//
#define ERROR_INVALID_LOGON_TYPE         ((ULONG)0x00000557L)

//
// MessageId: ERROR_CANNOT_IMPERSONATE
//
// MessageText:
//
// Unable to impersonate using a named pipe until data has been read from that pipe.
//
#define ERROR_CANNOT_IMPERSONATE         ((ULONG)0x00000558L)

//
// MessageId: ERROR_RXACT_INVALID_STATE
//
// MessageText:
//
// The transaction state of a registry subtree is incompatible with the requested operation.
//
#define ERROR_RXACT_INVALID_STATE        ((ULONG)0x00000559L)

//
// MessageId: ERROR_RXACT_COMMIT_FAILURE
//
// MessageText:
//
// An internal security database corruption has been encountered.
//
#define ERROR_RXACT_COMMIT_FAILURE       ((ULONG)0x0000055AL)

//
// MessageId: ERROR_SPECIAL_ACCOUNT
//
// MessageText:
//
// Cannot perform this operation on built-in accounts.
//
#define ERROR_SPECIAL_ACCOUNT            ((ULONG)0x0000055BL)

//
// MessageId: ERROR_SPECIAL_GROUP
//
// MessageText:
//
// Cannot perform this operation on this built-in special group.
//
#define ERROR_SPECIAL_GROUP              ((ULONG)0x0000055CL)

//
// MessageId: ERROR_SPECIAL_USER
//
// MessageText:
//
// Cannot perform this operation on this built-in special user.
//
#define ERROR_SPECIAL_USER               ((ULONG)0x0000055DL)

//
// MessageId: ERROR_MEMBERS_PRIMARY_GROUP
//
// MessageText:
//
// The user cannot be removed from a group because the group is currently the user's primary group.
//
#define ERROR_MEMBERS_PRIMARY_GROUP      ((ULONG)0x0000055EL)

//
// MessageId: ERROR_TOKEN_ALREADY_IN_USE
//
// MessageText:
//
// The token is already in use as a primary token.
//
#define ERROR_TOKEN_ALREADY_IN_USE       ((ULONG)0x0000055FL)

//
// MessageId: ERROR_NO_SUCH_ALIAS
//
// MessageText:
//
// The specified local group does not exist.
//
#define ERROR_NO_SUCH_ALIAS              ((ULONG)0x00000560L)

//
// MessageId: ERROR_MEMBER_NOT_IN_ALIAS
//
// MessageText:
//
// The specified account name is not a member of the local group.
//
#define ERROR_MEMBER_NOT_IN_ALIAS        ((ULONG)0x00000561L)

//
// MessageId: ERROR_MEMBER_IN_ALIAS
//
// MessageText:
//
// The specified account name is already a member of the local group.
//
#define ERROR_MEMBER_IN_ALIAS            ((ULONG)0x00000562L)

//
// MessageId: ERROR_ALIAS_EXISTS
//
// MessageText:
//
// The specified local group already exists.
//
#define ERROR_ALIAS_EXISTS               ((ULONG)0x00000563L)

//
// MessageId: ERROR_LOGON_NOT_GRANTED
//
// MessageText:
//
// Logon failure: the user has not been granted the requested logon type at this computer.
//
#define ERROR_LOGON_NOT_GRANTED          ((ULONG)0x00000564L)

//
// MessageId: ERROR_TOO_MANY_SECRETS
//
// MessageText:
//
// The maximum number of secrets that may be stored in a single system has been exceeded.
//
#define ERROR_TOO_MANY_SECRETS           ((ULONG)0x00000565L)

//
// MessageId: ERROR_SECRET_TOO_LONG
//
// MessageText:
//
// The length of a secret exceeds the maximum length allowed.
//
#define ERROR_SECRET_TOO_LONG            ((ULONG)0x00000566L)

//
// MessageId: ERROR_INTERNAL_DB_ERROR
//
// MessageText:
//
// The local security authority database contains an internal inconsistency.
//
#define ERROR_INTERNAL_DB_ERROR          ((ULONG)0x00000567L)

//
// MessageId: ERROR_TOO_MANY_CONTEXT_IDS
//
// MessageText:
//
// During a logon attempt, the user's security context accumulated too many security IDs.
//
#define ERROR_TOO_MANY_CONTEXT_IDS       ((ULONG)0x00000568L)

//
// MessageId: ERROR_LOGON_TYPE_NOT_GRANTED
//
// MessageText:
//
// Logon failure: the user has not been granted the requested logon type at this computer.
//
#define ERROR_LOGON_TYPE_NOT_GRANTED     ((ULONG)0x00000569L)

//
// MessageId: ERROR_NT_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
// A cross-encrypted password is necessary to change a user password.
//
#define ERROR_NT_CROSS_ENCRYPTION_REQUIRED ((ULONG)0x0000056AL)

//
// MessageId: ERROR_NO_SUCH_MEMBER
//
// MessageText:
//
// A new member could not be added to or removed from the local group because the member does not exist.
//
#define ERROR_NO_SUCH_MEMBER             ((ULONG)0x0000056BL)

//
// MessageId: ERROR_INVALID_MEMBER
//
// MessageText:
//
// A new member could not be added to a local group because the member has the wrong account type.
//
#define ERROR_INVALID_MEMBER             ((ULONG)0x0000056CL)

//
// MessageId: ERROR_TOO_MANY_SIDS
//
// MessageText:
//
// Too many security IDs have been specified.
//
#define ERROR_TOO_MANY_SIDS              ((ULONG)0x0000056DL)

//
// MessageId: ERROR_LM_CROSS_ENCRYPTION_REQUIRED
//
// MessageText:
//
// A cross-encrypted password is necessary to change this user password.
//
#define ERROR_LM_CROSS_ENCRYPTION_REQUIRED ((ULONG)0x0000056EL)

//
// MessageId: ERROR_NO_INHERITANCE
//
// MessageText:
//
// Indicates an ACL contains no inheritable components.
//
#define ERROR_NO_INHERITANCE             ((ULONG)0x0000056FL)

//
// MessageId: ERROR_FILE_CORRUPT
//
// MessageText:
//
// The file or directory is corrupted and unreadable.
//
#define ERROR_FILE_CORRUPT               ((ULONG)0x00000570L)

//
// MessageId: ERROR_DISK_CORRUPT
//
// MessageText:
//
// The disk structure is corrupted and unreadable.
//
#define ERROR_DISK_CORRUPT               ((ULONG)0x00000571L)

//
// MessageId: ERROR_NO_USER_SESSION_KEY
//
// MessageText:
//
// There is no user session key for the specified logon session.
//
#define ERROR_NO_USER_SESSION_KEY        ((ULONG)0x00000572L)

//
// MessageId: ERROR_LICENSE_QUOTA_EXCEEDED
//
// MessageText:
//
// The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.
//
#define ERROR_LICENSE_QUOTA_EXCEEDED     ((ULONG)0x00000573L)

//
// MessageId: ERROR_WRONG_TARGET_NAME
//
// MessageText:
//
// Logon Failure: The target account name is incorrect.
//
#define ERROR_WRONG_TARGET_NAME          ((ULONG)0x00000574L)

//
// MessageId: ERROR_MUTUAL_AUTH_FAILED
//
// MessageText:
//
// Mutual Authentication failed. The server's password is out of date at the domain controller.
//
#define ERROR_MUTUAL_AUTH_FAILED         ((ULONG)0x00000575L)

//
// MessageId: ERROR_TIME_SKEW
//
// MessageText:
//
// There is a time and/or date difference between the client and server.
//
#define ERROR_TIME_SKEW                  ((ULONG)0x00000576L)

//
// MessageId: ERROR_CURRENT_DOMAIN_NOT_ALLOWED
//
// MessageText:
//
// This operation cannot be performed on the current domain.
//
#define ERROR_CURRENT_DOMAIN_NOT_ALLOWED ((ULONG)0x00000577L)

//
// MessageId: ERROR_INVALID_WINDOW_HANDLE
//
// MessageText:
//
// Invalid window handle.
//
#define ERROR_INVALID_WINDOW_HANDLE      ((ULONG)0x00000578L)

//
// MessageId: ERROR_INVALID_MENU_HANDLE
//
// MessageText:
//
// Invalid menu handle.
//
#define ERROR_INVALID_MENU_HANDLE        ((ULONG)0x00000579L)

//
// MessageId: ERROR_INVALID_CURSOR_HANDLE
//
// MessageText:
//
// Invalid cursor handle.
//
#define ERROR_INVALID_CURSOR_HANDLE      ((ULONG)0x0000057AL)

//
// MessageId: ERROR_INVALID_ACCEL_HANDLE
//
// MessageText:
//
// Invalid accelerator table handle.
//
#define ERROR_INVALID_ACCEL_HANDLE       ((ULONG)0x0000057BL)

//
// MessageId: ERROR_INVALID_HOOK_HANDLE
//
// MessageText:
//
// Invalid hook handle.
//
#define ERROR_INVALID_HOOK_HANDLE        ((ULONG)0x0000057CL)

//
// MessageId: ERROR_INVALID_DWP_HANDLE
//
// MessageText:
//
// Invalid handle to a multiple-window position structure.
//
#define ERROR_INVALID_DWP_HANDLE         ((ULONG)0x0000057DL)

//
// MessageId: ERROR_TLW_WITH_WSCHILD
//
// MessageText:
//
// Cannot create a top-level child window.
//
#define ERROR_TLW_WITH_WSCHILD           ((ULONG)0x0000057EL)

//
// MessageId: ERROR_CANNOT_FIND_WND_CLASS
//
// MessageText:
//
// Cannot find window class.
//
#define ERROR_CANNOT_FIND_WND_CLASS      ((ULONG)0x0000057FL)

//
// MessageId: ERROR_WINDOW_OF_OTHER_THREAD
//
// MessageText:
//
// Invalid window; it belongs to other thread.
//
#define ERROR_WINDOW_OF_OTHER_THREAD     ((ULONG)0x00000580L)

//
// MessageId: ERROR_HOTKEY_ALREADY_REGISTERED
//
// MessageText:
//
// Hot key is already registered.
//
#define ERROR_HOTKEY_ALREADY_REGISTERED  ((ULONG)0x00000581L)

//
// MessageId: ERROR_CLASS_ALREADY_EXISTS
//
// MessageText:
//
// Class already exists.
//
#define ERROR_CLASS_ALREADY_EXISTS       ((ULONG)0x00000582L)

//
// MessageId: ERROR_CLASS_DOES_NOT_EXIST
//
// MessageText:
//
// Class does not exist.
//
#define ERROR_CLASS_DOES_NOT_EXIST       ((ULONG)0x00000583L)

//
// MessageId: ERROR_CLASS_HAS_WINDOWS
//
// MessageText:
//
// Class still has open windows.
//
#define ERROR_CLASS_HAS_WINDOWS          ((ULONG)0x00000584L)

//
// MessageId: ERROR_INVALID_INDEX
//
// MessageText:
//
// Invalid index.
//
#define ERROR_INVALID_INDEX              ((ULONG)0x00000585L)

//
// MessageId: ERROR_INVALID_ICON_HANDLE
//
// MessageText:
//
// Invalid icon handle.
//
#define ERROR_INVALID_ICON_HANDLE        ((ULONG)0x00000586L)

//
// MessageId: ERROR_PRIVATE_DIALOG_INDEX
//
// MessageText:
//
// Using private DIALOG window words.
//
#define ERROR_PRIVATE_DIALOG_INDEX       ((ULONG)0x00000587L)

//
// MessageId: ERROR_LISTBOX_ID_NOT_FOUND
//
// MessageText:
//
// The list box identifier was not found.
//
#define ERROR_LISTBOX_ID_NOT_FOUND       ((ULONG)0x00000588L)

//
// MessageId: ERROR_NO_WILDCARD_CHARACTERS
//
// MessageText:
//
// No wildcards were found.
//
#define ERROR_NO_WILDCARD_CHARACTERS     ((ULONG)0x00000589L)

//
// MessageId: ERROR_CLIPBOARD_NOT_OPEN
//
// MessageText:
//
// Thread does not have a clipboard open.
//
#define ERROR_CLIPBOARD_NOT_OPEN         ((ULONG)0x0000058AL)

//
// MessageId: ERROR_HOTKEY_NOT_REGISTERED
//
// MessageText:
//
// Hot key is not registered.
//
#define ERROR_HOTKEY_NOT_REGISTERED      ((ULONG)0x0000058BL)

//
// MessageId: ERROR_WINDOW_NOT_DIALOG
//
// MessageText:
//
// The window is not a valid dialog window.
//
#define ERROR_WINDOW_NOT_DIALOG          ((ULONG)0x0000058CL)

//
// MessageId: ERROR_CONTROL_ID_NOT_FOUND
//
// MessageText:
//
// Control ID not found.
//
#define ERROR_CONTROL_ID_NOT_FOUND       ((ULONG)0x0000058DL)

//
// MessageId: ERROR_INVALID_COMBOBOX_MESSAGE
//
// MessageText:
//
// Invalid message for a combo box because it does not have an edit control.
//
#define ERROR_INVALID_COMBOBOX_MESSAGE   ((ULONG)0x0000058EL)

//
// MessageId: ERROR_WINDOW_NOT_COMBOBOX
//
// MessageText:
//
// The window is not a combo box.
//
#define ERROR_WINDOW_NOT_COMBOBOX        ((ULONG)0x0000058FL)

//
// MessageId: ERROR_INVALID_EDIT_HEIGHT
//
// MessageText:
//
// Height must be less than 256.
//
#define ERROR_INVALID_EDIT_HEIGHT        ((ULONG)0x00000590L)

//
// MessageId: ERROR_DC_NOT_FOUND
//
// MessageText:
//
// Invalid device context (DC) handle.
//
#define ERROR_DC_NOT_FOUND               ((ULONG)0x00000591L)

//
// MessageId: ERROR_INVALID_HOOK_FILTER
//
// MessageText:
//
// Invalid hook procedure type.
//
#define ERROR_INVALID_HOOK_FILTER        ((ULONG)0x00000592L)

//
// MessageId: ERROR_INVALID_FILTER_PROC
//
// MessageText:
//
// Invalid hook procedure.
//
#define ERROR_INVALID_FILTER_PROC        ((ULONG)0x00000593L)

//
// MessageId: ERROR_HOOK_NEEDS_HMOD
//
// MessageText:
//
// Cannot set nonlocal hook without a module handle.
//
#define ERROR_HOOK_NEEDS_HMOD            ((ULONG)0x00000594L)

//
// MessageId: ERROR_GLOBAL_ONLY_HOOK
//
// MessageText:
//
// This hook procedure can only be set globally.
//
#define ERROR_GLOBAL_ONLY_HOOK           ((ULONG)0x00000595L)

//
// MessageId: ERROR_JOURNAL_HOOK_SET
//
// MessageText:
//
// The journal hook procedure is already installed.
//
#define ERROR_JOURNAL_HOOK_SET           ((ULONG)0x00000596L)

//
// MessageId: ERROR_HOOK_NOT_INSTALLED
//
// MessageText:
//
// The hook procedure is not installed.
//
#define ERROR_HOOK_NOT_INSTALLED         ((ULONG)0x00000597L)

//
// MessageId: ERROR_INVALID_LB_MESSAGE
//
// MessageText:
//
// Invalid message for single-selection list box.
//
#define ERROR_INVALID_LB_MESSAGE         ((ULONG)0x00000598L)

//
// MessageId: ERROR_SETCOUNT_ON_BAD_LB
//
// MessageText:
//
// LB_SETCOUNT sent to non-lazy list box.
//
#define ERROR_SETCOUNT_ON_BAD_LB         ((ULONG)0x00000599L)

//
// MessageId: ERROR_LB_WITHOUT_TABSTOPS
//
// MessageText:
//
// This list box does not support tab stops.
//
#define ERROR_LB_WITHOUT_TABSTOPS        ((ULONG)0x0000059AL)

//
// MessageId: ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
//
// MessageText:
//
// Cannot destroy object created by another thread.
//
#define ERROR_DESTROY_OBJECT_OF_OTHER_THREAD ((ULONG)0x0000059BL)

//
// MessageId: ERROR_CHILD_WINDOW_MENU
//
// MessageText:
//
// Child windows cannot have menus.
//
#define ERROR_CHILD_WINDOW_MENU          ((ULONG)0x0000059CL)

//
// MessageId: ERROR_NO_SYSTEM_MENU
//
// MessageText:
//
// The window does not have a system menu.
//
#define ERROR_NO_SYSTEM_MENU             ((ULONG)0x0000059DL)

//
// MessageId: ERROR_INVALID_MSGBOX_STYLE
//
// MessageText:
//
// Invalid message box style.
//
#define ERROR_INVALID_MSGBOX_STYLE       ((ULONG)0x0000059EL)

//
// MessageId: ERROR_INVALID_SPI_VALUE
//
// MessageText:
//
// Invalid system-wide (SPI_*) parameter.
//
#define ERROR_INVALID_SPI_VALUE          ((ULONG)0x0000059FL)

//
// MessageId: ERROR_SCREEN_ALREADY_LOCKED
//
// MessageText:
//
// Screen already locked.
//
#define ERROR_SCREEN_ALREADY_LOCKED      ((ULONG)0x000005A0L)

//
// MessageId: ERROR_HWNDS_HAVE_DIFF_PARENT
//
// MessageText:
//
// All handles to windows in a multiple-window position structure must have the same parent.
//
#define ERROR_HWNDS_HAVE_DIFF_PARENT     ((ULONG)0x000005A1L)

//
// MessageId: ERROR_NOT_CHILD_WINDOW
//
// MessageText:
//
// The window is not a child window.
//
#define ERROR_NOT_CHILD_WINDOW           ((ULONG)0x000005A2L)

//
// MessageId: ERROR_INVALID_GW_COMMAND
//
// MessageText:
//
// Invalid GW_* command.
//
#define ERROR_INVALID_GW_COMMAND         ((ULONG)0x000005A3L)

//
// MessageId: ERROR_INVALID_THREAD_ID
//
// MessageText:
//
// Invalid thread identifier.
//
#define ERROR_INVALID_THREAD_ID          ((ULONG)0x000005A4L)

//
// MessageId: ERROR_NON_MDICHILD_WINDOW
//
// MessageText:
//
// Cannot process a message from a window that is not a multiple document interface (MDI) window.
//
#define ERROR_NON_MDICHILD_WINDOW        ((ULONG)0x000005A5L)

//
// MessageId: ERROR_POPUP_ALREADY_ACTIVE
//
// MessageText:
//
// Popup menu already active.
//
#define ERROR_POPUP_ALREADY_ACTIVE       ((ULONG)0x000005A6L)

//
// MessageId: ERROR_NO_SCROLLBARS
//
// MessageText:
//
// The window does not have scroll bars.
//
#define ERROR_NO_SCROLLBARS              ((ULONG)0x000005A7L)

//
// MessageId: ERROR_INVALID_SCROLLBAR_RANGE
//
// MessageText:
//
// Scroll bar range cannot be greater than MAXLONG.
//
#define ERROR_INVALID_SCROLLBAR_RANGE    ((ULONG)0x000005A8L)

//
// MessageId: ERROR_INVALID_SHOWWIN_COMMAND
//
// MessageText:
//
// Cannot show or remove the window in the way specified.
//
#define ERROR_INVALID_SHOWWIN_COMMAND    ((ULONG)0x000005A9L)

//
// MessageId: ERROR_NO_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_NO_SYSTEM_RESOURCES        ((ULONG)0x000005AAL)

//
// MessageId: ERROR_NONPAGED_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_NONPAGED_SYSTEM_RESOURCES  ((ULONG)0x000005ABL)

//
// MessageId: ERROR_PAGED_SYSTEM_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the requested service.
//
#define ERROR_PAGED_SYSTEM_RESOURCES     ((ULONG)0x000005ACL)

//
// MessageId: ERROR_WORKING_SET_QUOTA
//
// MessageText:
//
// Insufficient quota to complete the requested service.
//
#define ERROR_WORKING_SET_QUOTA          ((ULONG)0x000005ADL)

//
// MessageId: ERROR_PAGEFILE_QUOTA
//
// MessageText:
//
// Insufficient quota to complete the requested service.
//
#define ERROR_PAGEFILE_QUOTA             ((ULONG)0x000005AEL)

//
// MessageId: ERROR_COMMITMENT_LIMIT
//
// MessageText:
//
// The paging file is too small for this operation to complete.
//
#define ERROR_COMMITMENT_LIMIT           ((ULONG)0x000005AFL)

//
// MessageId: ERROR_MENU_ITEM_NOT_FOUND
//
// MessageText:
//
// A menu item was not found.
//
#define ERROR_MENU_ITEM_NOT_FOUND        ((ULONG)0x000005B0L)

//
// MessageId: ERROR_INVALID_KEYBOARD_HANDLE
//
// MessageText:
//
// Invalid keyboard layout handle.
//
#define ERROR_INVALID_KEYBOARD_HANDLE    ((ULONG)0x000005B1L)

//
// MessageId: ERROR_HOOK_TYPE_NOT_ALLOWED
//
// MessageText:
//
// Hook type not allowed.
//
#define ERROR_HOOK_TYPE_NOT_ALLOWED      ((ULONG)0x000005B2L)

//
// MessageId: ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
//
// MessageText:
//
// This operation requires an interactive window station.
//
#define ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION ((ULONG)0x000005B3L)

//
// MessageId: ERROR_TIMEOUT
//
// MessageText:
//
// This operation returned because the timeout period expired.
//
#define ERROR_TIMEOUT                    ((ULONG)0x000005B4L)

//
// MessageId: ERROR_INVALID_MONITOR_HANDLE
//
// MessageText:
//
// Invalid monitor handle.
//
#define ERROR_INVALID_MONITOR_HANDLE     ((ULONG)0x000005B5L)

//
// MessageId: ERROR_EVENTLOG_FILE_CORRUPT
//
// MessageText:
//
// The event log file is corrupted.
//
#define ERROR_EVENTLOG_FILE_CORRUPT      ((ULONG)0x000005DCL)

//
// MessageId: ERROR_EVENTLOG_CANT_START
//
// MessageText:
//
// No event log file could be opened, so the event logging service did not start.
//
#define ERROR_EVENTLOG_CANT_START        ((ULONG)0x000005DDL)

//
// MessageId: ERROR_LOG_FILE_FULL
//
// MessageText:
//
// The event log file is full.
//
#define ERROR_LOG_FILE_FULL              ((ULONG)0x000005DEL)

//
// MessageId: ERROR_EVENTLOG_FILE_CHANGED
//
// MessageText:
//
// The event log file has changed between read operations.
//
#define ERROR_EVENTLOG_FILE_CHANGED      ((ULONG)0x000005DFL)

//
// MessageId: ERROR_INSTALL_SERVICE_FAILURE
//
// MessageText:
//
// The ReactOS Installer service could not be accessed. This can occur if you are running ReactOS in safe mode, or if the ReactOS Installer is not correctly installed. Contact your support personnel for assistance.
//
#define ERROR_INSTALL_SERVICE_FAILURE    ((ULONG)0x00000641L)

//
// MessageId: ERROR_INSTALL_USEREXIT
//
// MessageText:
//
// User cancelled installation.
//
#define ERROR_INSTALL_USEREXIT           ((ULONG)0x00000642L)

//
// MessageId: ERROR_INSTALL_FAILURE
//
// MessageText:
//
// Fatal error during installation.
//
#define ERROR_INSTALL_FAILURE            ((ULONG)0x00000643L)

//
// MessageId: ERROR_INSTALL_SUSPEND
//
// MessageText:
//
// Installation suspended, incomplete.
//
#define ERROR_INSTALL_SUSPEND            ((ULONG)0x00000644L)

//
// MessageId: ERROR_UNKNOWN_PRODUCT
//
// MessageText:
//
// This action is only valid for products that are currently installed.
//
#define ERROR_UNKNOWN_PRODUCT            ((ULONG)0x00000645L)

//
// MessageId: ERROR_UNKNOWN_FEATURE
//
// MessageText:
//
// Feature ID not registered.
//
#define ERROR_UNKNOWN_FEATURE            ((ULONG)0x00000646L)

//
// MessageId: ERROR_UNKNOWN_COMPONENT
//
// MessageText:
//
// Component ID not registered.
//
#define ERROR_UNKNOWN_COMPONENT          ((ULONG)0x00000647L)

//
// MessageId: ERROR_UNKNOWN_PROPERTY
//
// MessageText:
//
// Unknown property.
//
#define ERROR_UNKNOWN_PROPERTY           ((ULONG)0x00000648L)

//
// MessageId: ERROR_INVALID_HANDLE_STATE
//
// MessageText:
//
// Handle is in an invalid state.
//
#define ERROR_INVALID_HANDLE_STATE       ((ULONG)0x00000649L)

//
// MessageId: ERROR_BAD_CONFIGURATION
//
// MessageText:
//
// The configuration data for this product is corrupt. Contact your support personnel.
//
#define ERROR_BAD_CONFIGURATION          ((ULONG)0x0000064AL)

//
// MessageId: ERROR_INDEX_ABSENT
//
// MessageText:
//
// Component qualifier not present.
//
#define ERROR_INDEX_ABSENT               ((ULONG)0x0000064BL)

//
// MessageId: ERROR_INSTALL_SOURCE_ABSENT
//
// MessageText:
//
// The installation source for this product is not available. Verify that the source exists and that you can access it.
//
#define ERROR_INSTALL_SOURCE_ABSENT      ((ULONG)0x0000064CL)

//
// MessageId: ERROR_INSTALL_PACKAGE_VERSION
//
// MessageText:
//
// This installation package cannot be installed by the ReactOS Installer service. You must install a ReactOS service pack that contains a newer version of the ReactOS Installer service.
//
#define ERROR_INSTALL_PACKAGE_VERSION    ((ULONG)0x0000064DL)

//
// MessageId: ERROR_PRODUCT_UNINSTALLED
//
// MessageText:
//
// Product is uninstalled.
//
#define ERROR_PRODUCT_UNINSTALLED        ((ULONG)0x0000064EL)

//
// MessageId: ERROR_BAD_QUERY_SYNTAX
//
// MessageText:
//
// SQL query syntax invalid or unsupported.
//
#define ERROR_BAD_QUERY_SYNTAX           ((ULONG)0x0000064FL)

//
// MessageId: ERROR_INVALID_FIELD
//
// MessageText:
//
// Record field does not exist.
//
#define ERROR_INVALID_FIELD              ((ULONG)0x00000650L)

//
// MessageId: ERROR_DEVICE_REMOVED
//
// MessageText:
//
// The device has been removed.
//
#define ERROR_DEVICE_REMOVED             ((ULONG)0x00000651L)

//
// MessageId: ERROR_INSTALL_ALREADY_RUNNING
//
// MessageText:
//
// Another installation is already in progress. Complete that installation before proceeding with this install.
//
#define ERROR_INSTALL_ALREADY_RUNNING    ((ULONG)0x00000652L)

//
// MessageId: ERROR_INSTALL_PACKAGE_OPEN_FAILED
//
// MessageText:
//
// This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.
//
#define ERROR_INSTALL_PACKAGE_OPEN_FAILED ((ULONG)0x00000653L)

//
// MessageId: ERROR_INSTALL_PACKAGE_INVALID
//
// MessageText:
//
// This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.
//
#define ERROR_INSTALL_PACKAGE_INVALID    ((ULONG)0x00000654L)

//
// MessageId: ERROR_INSTALL_UI_FAILURE
//
// MessageText:
//
// There was an error starting the ReactOS Installer service user interface. Contact your support personnel.
//
#define ERROR_INSTALL_UI_FAILURE         ((ULONG)0x00000655L)

//
// MessageId: ERROR_INSTALL_LOG_FAILURE
//
// MessageText:
//
// Error opening installation log file. Verify that the specified log file location exists and that you can write to it.
//
#define ERROR_INSTALL_LOG_FAILURE        ((ULONG)0x00000656L)

//
// MessageId: ERROR_INSTALL_LANGUAGE_UNSUPPORTED
//
// MessageText:
//
// The language of this installation package is not supported by your system.
//
#define ERROR_INSTALL_LANGUAGE_UNSUPPORTED ((ULONG)0x00000657L)

//
// MessageId: ERROR_INSTALL_TRANSFORM_FAILURE
//
// MessageText:
//
// Error applying transforms. Verify that the specified transform paths are valid.
//
#define ERROR_INSTALL_TRANSFORM_FAILURE  ((ULONG)0x00000658L)

//
// MessageId: ERROR_INSTALL_PACKAGE_REJECTED
//
// MessageText:
//
// This installation is forbidden by system policy. Contact your system administrator.
//
#define ERROR_INSTALL_PACKAGE_REJECTED   ((ULONG)0x00000659L)

//
// MessageId: ERROR_FUNCTION_NOT_CALLED
//
// MessageText:
//
// Function could not be executed.
//
#define ERROR_FUNCTION_NOT_CALLED        ((ULONG)0x0000065AL)

//
// MessageId: ERROR_FUNCTION_FAILED
//
// MessageText:
//
// Function failed during execution.
//
#define ERROR_FUNCTION_FAILED            ((ULONG)0x0000065BL)

//
// MessageId: ERROR_INVALID_TABLE
//
// MessageText:
//
// Invalid or unknown table specified.
//
#define ERROR_INVALID_TABLE              ((ULONG)0x0000065CL)

//
// MessageId: ERROR_DATATYPE_MISMATCH
//
// MessageText:
//
// Data supplied is of wrong type.
//
#define ERROR_DATATYPE_MISMATCH          ((ULONG)0x0000065DL)

//
// MessageId: ERROR_UNSUPPORTED_TYPE
//
// MessageText:
//
// Data of this type is not supported.
//
#define ERROR_UNSUPPORTED_TYPE           ((ULONG)0x0000065EL)

//
// MessageId: ERROR_CREATE_FAILED
//
// MessageText:
//
// The ReactOS Installer service failed to start. Contact your support personnel.
//
#define ERROR_CREATE_FAILED              ((ULONG)0x0000065FL)

//
// MessageId: ERROR_INSTALL_TEMP_UNWRITABLE
//
// MessageText:
//
// The Temp folder is on a drive that is full or inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.
//
#define ERROR_INSTALL_TEMP_UNWRITABLE    ((ULONG)0x00000660L)

//
// MessageId: ERROR_INSTALL_PLATFORM_UNSUPPORTED
//
// MessageText:
//
// This installation package is not supported by this processor type. Contact your product vendor.
//
#define ERROR_INSTALL_PLATFORM_UNSUPPORTED ((ULONG)0x00000661L)

//
// MessageId: ERROR_INSTALL_NOTUSED
//
// MessageText:
//
// Component not used on this computer.
//
#define ERROR_INSTALL_NOTUSED            ((ULONG)0x00000662L)

//
// MessageId: ERROR_PATCH_PACKAGE_OPEN_FAILED
//
// MessageText:
//
// This patch package could not be opened. Verify that the patch package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer patch package.
//
#define ERROR_PATCH_PACKAGE_OPEN_FAILED  ((ULONG)0x00000663L)

//
// MessageId: ERROR_PATCH_PACKAGE_INVALID
//
// MessageText:
//
// This patch package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer patch package.
//
#define ERROR_PATCH_PACKAGE_INVALID      ((ULONG)0x00000664L)

//
// MessageId: ERROR_PATCH_PACKAGE_UNSUPPORTED
//
// MessageText:
//
// This patch package cannot be processed by the ReactOS Installer service. You must install a ReactOS service pack that contains a newer version of the ReactOS Installer service.
//
#define ERROR_PATCH_PACKAGE_UNSUPPORTED  ((ULONG)0x00000665L)

//
// MessageId: ERROR_PRODUCT_VERSION
//
// MessageText:
//
// Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
//
#define ERROR_PRODUCT_VERSION            ((ULONG)0x00000666L)

//
// MessageId: ERROR_INVALID_COMMAND_LINE
//
// MessageText:
//
// Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.
//
#define ERROR_INVALID_COMMAND_LINE       ((ULONG)0x00000667L)

//
// MessageId: ERROR_INSTALL_REMOTE_DISALLOWED
//
// MessageText:
//
// Only administrators have permission to add, remove, or configure server software during a Terminal Services remote session. If you want to install or configure software on the server, contact your network administrator.
//
#define ERROR_INSTALL_REMOTE_DISALLOWED  ((ULONG)0x00000668L)

//
// MessageId: ERROR_SUCCESS_REBOOT_INITIATED
//
// MessageText:
//
// The requested operation completed successfully. The system will be restarted so the changes can take effect.
//
#define ERROR_SUCCESS_REBOOT_INITIATED   ((ULONG)0x00000669L)

//
// MessageId: ERROR_PATCH_TARGET_NOT_FOUND
//
// MessageText:
//
// The upgrade patch cannot be installed by the ReactOS Installer service because the program to be upgraded may be missing, or the upgrade patch may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade patch.
//
#define ERROR_PATCH_TARGET_NOT_FOUND     ((ULONG)0x0000066AL)

//
// MessageId: ERROR_PATCH_PACKAGE_REJECTED
//
// MessageText:
//
// The patch package is not permitted by software restriction policy.
//
#define ERROR_PATCH_PACKAGE_REJECTED     ((ULONG)0x0000066BL)

//
// MessageId: ERROR_INSTALL_TRANSFORM_REJECTED
//
// MessageText:
//
// One or more customizations are not permitted by software restriction policy.
//
#define ERROR_INSTALL_TRANSFORM_REJECTED ((ULONG)0x0000066CL)

//
// MessageId: ERROR_INSTALL_REMOTE_PROHIBITED
//
// MessageText:
//
// The ReactOS Installer does not permit installation from a Remote Desktop Connection.
//
#define ERROR_INSTALL_REMOTE_PROHIBITED  ((ULONG)0x0000066DL)

//
// MessageId: ERROR_INSTALL_REJECTED
//
// MessageText:
//
// The app that you are trying to run is not supported on this version of Windows.
//
#define ERROR_INSTALL_REJECTED           ((ULONG)0x00000676L)

//
// MessageId: RPC_S_INVALID_STRING_BINDING
//
// MessageText:
//
// The string binding is invalid.
//
#define RPC_S_INVALID_STRING_BINDING     ((ULONG)0x000006A4L)

//
// MessageId: RPC_S_WRONG_KIND_OF_BINDING
//
// MessageText:
//
// The binding handle is not the correct type.
//
#define RPC_S_WRONG_KIND_OF_BINDING      ((ULONG)0x000006A5L)

//
// MessageId: RPC_S_INVALID_BINDING
//
// MessageText:
//
// The binding handle is invalid.
//
#define RPC_S_INVALID_BINDING            ((ULONG)0x000006A6L)

//
// MessageId: RPC_S_PROTSEQ_NOT_SUPPORTED
//
// MessageText:
//
// The RPC protocol sequence is not supported.
//
#define RPC_S_PROTSEQ_NOT_SUPPORTED      ((ULONG)0x000006A7L)

//
// MessageId: RPC_S_INVALID_RPC_PROTSEQ
//
// MessageText:
//
// The RPC protocol sequence is invalid.
//
#define RPC_S_INVALID_RPC_PROTSEQ        ((ULONG)0x000006A8L)

//
// MessageId: RPC_S_INVALID_STRING_UUID
//
// MessageText:
//
// The string universal unique identifier (UUID) is invalid.
//
#define RPC_S_INVALID_STRING_UUID        ((ULONG)0x000006A9L)

//
// MessageId: RPC_S_INVALID_ENDPOINT_FORMAT
//
// MessageText:
//
// The endpoint format is invalid.
//
#define RPC_S_INVALID_ENDPOINT_FORMAT    ((ULONG)0x000006AAL)

//
// MessageId: RPC_S_INVALID_NET_ADDR
//
// MessageText:
//
// The network address is invalid.
//
#define RPC_S_INVALID_NET_ADDR           ((ULONG)0x000006ABL)

//
// MessageId: RPC_S_NO_ENDPOINT_FOUND
//
// MessageText:
//
// No endpoint was found.
//
#define RPC_S_NO_ENDPOINT_FOUND          ((ULONG)0x000006ACL)

//
// MessageId: RPC_S_INVALID_TIMEOUT
//
// MessageText:
//
// The timeout value is invalid.
//
#define RPC_S_INVALID_TIMEOUT            ((ULONG)0x000006ADL)

//
// MessageId: RPC_S_OBJECT_NOT_FOUND
//
// MessageText:
//
// The object universal unique identifier (UUID) was not found.
//
#define RPC_S_OBJECT_NOT_FOUND           ((ULONG)0x000006AEL)

//
// MessageId: RPC_S_ALREADY_REGISTERED
//
// MessageText:
//
// The object universal unique identifier (UUID) has already been registered.
//
#define RPC_S_ALREADY_REGISTERED         ((ULONG)0x000006AFL)

//
// MessageId: RPC_S_TYPE_ALREADY_REGISTERED
//
// MessageText:
//
// The type universal unique identifier (UUID) has already been registered.
//
#define RPC_S_TYPE_ALREADY_REGISTERED    ((ULONG)0x000006B0L)

//
// MessageId: RPC_S_ALREADY_LISTENING
//
// MessageText:
//
// The RPC server is already listening.
//
#define RPC_S_ALREADY_LISTENING          ((ULONG)0x000006B1L)

//
// MessageId: RPC_S_NO_PROTSEQS_REGISTERED
//
// MessageText:
//
// No protocol sequences have been registered.
//
#define RPC_S_NO_PROTSEQS_REGISTERED     ((ULONG)0x000006B2L)

//
// MessageId: RPC_S_NOT_LISTENING
//
// MessageText:
//
// The RPC server is not listening.
//
#define RPC_S_NOT_LISTENING              ((ULONG)0x000006B3L)

//
// MessageId: RPC_S_UNKNOWN_MGR_TYPE
//
// MessageText:
//
// The manager type is unknown.
//
#define RPC_S_UNKNOWN_MGR_TYPE           ((ULONG)0x000006B4L)

//
// MessageId: RPC_S_UNKNOWN_IF
//
// MessageText:
//
// The interface is unknown.
//
#define RPC_S_UNKNOWN_IF                 ((ULONG)0x000006B5L)

//
// MessageId: RPC_S_NO_BINDINGS
//
// MessageText:
//
// There are no bindings.
//
#define RPC_S_NO_BINDINGS                ((ULONG)0x000006B6L)

//
// MessageId: RPC_S_NO_PROTSEQS
//
// MessageText:
//
// There are no protocol sequences.
//
#define RPC_S_NO_PROTSEQS                ((ULONG)0x000006B7L)

//
// MessageId: RPC_S_CANT_CREATE_ENDPOINT
//
// MessageText:
//
// The endpoint cannot be created.
//
#define RPC_S_CANT_CREATE_ENDPOINT       ((ULONG)0x000006B8L)

//
// MessageId: RPC_S_OUT_OF_RESOURCES
//
// MessageText:
//
// Not enough resources are available to complete this operation.
//
#define RPC_S_OUT_OF_RESOURCES           ((ULONG)0x000006B9L)

//
// MessageId: RPC_S_SERVER_UNAVAILABLE
//
// MessageText:
//
// The RPC server is unavailable.
//
#define RPC_S_SERVER_UNAVAILABLE         ((ULONG)0x000006BAL)

//
// MessageId: RPC_S_SERVER_TOO_BUSY
//
// MessageText:
//
// The RPC server is too busy to complete this operation.
//
#define RPC_S_SERVER_TOO_BUSY            ((ULONG)0x000006BBL)

//
// MessageId: RPC_S_INVALID_NETWORK_OPTIONS
//
// MessageText:
//
// The network options are invalid.
//
#define RPC_S_INVALID_NETWORK_OPTIONS    ((ULONG)0x000006BCL)

//
// MessageId: RPC_S_NO_CALL_ACTIVE
//
// MessageText:
//
// There are no remote procedure calls active on this thread.
//
#define RPC_S_NO_CALL_ACTIVE             ((ULONG)0x000006BDL)

//
// MessageId: RPC_S_CALL_FAILED
//
// MessageText:
//
// The remote procedure call failed.
//
#define RPC_S_CALL_FAILED                ((ULONG)0x000006BEL)

//
// MessageId: RPC_S_CALL_FAILED_DNE
//
// MessageText:
//
// The remote procedure call failed and did not execute.
//
#define RPC_S_CALL_FAILED_DNE            ((ULONG)0x000006BFL)

//
// MessageId: RPC_S_PROTOCOL_ERROR
//
// MessageText:
//
// A remote procedure call (RPC) protocol error occurred.
//
#define RPC_S_PROTOCOL_ERROR             ((ULONG)0x000006C0L)

//
// MessageId: RPC_S_UNSUPPORTED_TRANS_SYN
//
// MessageText:
//
// The transfer syntax is not supported by the RPC server.
//
#define RPC_S_UNSUPPORTED_TRANS_SYN      ((ULONG)0x000006C2L)

//
// MessageId: RPC_S_UNSUPPORTED_TYPE
//
// MessageText:
//
// The universal unique identifier (UUID) type is not supported.
//
#define RPC_S_UNSUPPORTED_TYPE           ((ULONG)0x000006C4L)

//
// MessageId: RPC_S_INVALID_TAG
//
// MessageText:
//
// The tag is invalid.
//
#define RPC_S_INVALID_TAG                ((ULONG)0x000006C5L)

//
// MessageId: RPC_S_INVALID_BOUND
//
// MessageText:
//
// The array bounds are invalid.
//
#define RPC_S_INVALID_BOUND              ((ULONG)0x000006C6L)

//
// MessageId: RPC_S_NO_ENTRY_NAME
//
// MessageText:
//
// The binding does not contain an entry name.
//
#define RPC_S_NO_ENTRY_NAME              ((ULONG)0x000006C7L)

//
// MessageId: RPC_S_INVALID_NAME_SYNTAX
//
// MessageText:
//
// The name syntax is invalid.
//
#define RPC_S_INVALID_NAME_SYNTAX        ((ULONG)0x000006C8L)

//
// MessageId: RPC_S_UNSUPPORTED_NAME_SYNTAX
//
// MessageText:
//
// The name syntax is not supported.
//
#define RPC_S_UNSUPPORTED_NAME_SYNTAX    ((ULONG)0x000006C9L)

//
// MessageId: RPC_S_UUID_NO_ADDRESS
//
// MessageText:
//
// No network address is available to use to construct a universal unique identifier (UUID).
//
#define RPC_S_UUID_NO_ADDRESS            ((ULONG)0x000006CBL)

//
// MessageId: RPC_S_DUPLICATE_ENDPOINT
//
// MessageText:
//
// The endpoint is a duplicate.
//
#define RPC_S_DUPLICATE_ENDPOINT         ((ULONG)0x000006CCL)

//
// MessageId: RPC_S_UNKNOWN_AUTHN_TYPE
//
// MessageText:
//
// The authentication type is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_TYPE         ((ULONG)0x000006CDL)

//
// MessageId: RPC_S_MAX_CALLS_TOO_SMALL
//
// MessageText:
//
// The maximum number of calls is too small.
//
#define RPC_S_MAX_CALLS_TOO_SMALL        ((ULONG)0x000006CEL)

//
// MessageId: RPC_S_STRING_TOO_LONG
//
// MessageText:
//
// The string is too long.
//
#define RPC_S_STRING_TOO_LONG            ((ULONG)0x000006CFL)

//
// MessageId: RPC_S_PROTSEQ_NOT_FOUND
//
// MessageText:
//
// The RPC protocol sequence was not found.
//
#define RPC_S_PROTSEQ_NOT_FOUND          ((ULONG)0x000006D0L)

//
// MessageId: RPC_S_PROCNUM_OUT_OF_RANGE
//
// MessageText:
//
// The procedure number is out of range.
//
#define RPC_S_PROCNUM_OUT_OF_RANGE       ((ULONG)0x000006D1L)

//
// MessageId: RPC_S_BINDING_HAS_NO_AUTH
//
// MessageText:
//
// The binding does not contain any authentication information.
//
#define RPC_S_BINDING_HAS_NO_AUTH        ((ULONG)0x000006D2L)

//
// MessageId: RPC_S_UNKNOWN_AUTHN_SERVICE
//
// MessageText:
//
// The authentication service is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_SERVICE      ((ULONG)0x000006D3L)

//
// MessageId: RPC_S_UNKNOWN_AUTHN_LEVEL
//
// MessageText:
//
// The authentication level is unknown.
//
#define RPC_S_UNKNOWN_AUTHN_LEVEL        ((ULONG)0x000006D4L)

//
// MessageId: RPC_S_INVALID_AUTH_IDENTITY
//
// MessageText:
//
// The security context is invalid.
//
#define RPC_S_INVALID_AUTH_IDENTITY      ((ULONG)0x000006D5L)

//
// MessageId: RPC_S_UNKNOWN_AUTHZ_SERVICE
//
// MessageText:
//
// The authorization service is unknown.
//
#define RPC_S_UNKNOWN_AUTHZ_SERVICE      ((ULONG)0x000006D6L)

//
// MessageId: EPT_S_INVALID_ENTRY
//
// MessageText:
//
// The entry is invalid.
//
#define EPT_S_INVALID_ENTRY              ((ULONG)0x000006D7L)

//
// MessageId: EPT_S_CANT_PERFORM_OP
//
// MessageText:
//
// The server endpoint cannot perform the operation.
//
#define EPT_S_CANT_PERFORM_OP            ((ULONG)0x000006D8L)

//
// MessageId: EPT_S_NOT_REGISTERED
//
// MessageText:
//
// There are no more endpoints available from the endpoint mapper.
//
#define EPT_S_NOT_REGISTERED             ((ULONG)0x000006D9L)

//
// MessageId: RPC_S_NOTHING_TO_EXPORT
//
// MessageText:
//
// No interfaces have been exported.
//
#define RPC_S_NOTHING_TO_EXPORT          ((ULONG)0x000006DAL)

//
// MessageId: RPC_S_INCOMPLETE_NAME
//
// MessageText:
//
// The entry name is incomplete.
//
#define RPC_S_INCOMPLETE_NAME            ((ULONG)0x000006DBL)

//
// MessageId: RPC_S_INVALID_VERS_OPTION
//
// MessageText:
//
// The version option is invalid.
//
#define RPC_S_INVALID_VERS_OPTION        ((ULONG)0x000006DCL)

//
// MessageId: RPC_S_NO_MORE_MEMBERS
//
// MessageText:
//
// There are no more members.
//
#define RPC_S_NO_MORE_MEMBERS            ((ULONG)0x000006DDL)

//
// MessageId: RPC_S_NOT_ALL_OBJS_UNEXPORTED
//
// MessageText:
//
// There is nothing to unexport.
//
#define RPC_S_NOT_ALL_OBJS_UNEXPORTED    ((ULONG)0x000006DEL)

//
// MessageId: RPC_S_INTERFACE_NOT_FOUND
//
// MessageText:
//
// The interface was not found.
//
#define RPC_S_INTERFACE_NOT_FOUND        ((ULONG)0x000006DFL)

//
// MessageId: RPC_S_ENTRY_ALREADY_EXISTS
//
// MessageText:
//
// The entry already exists.
//
#define RPC_S_ENTRY_ALREADY_EXISTS       ((ULONG)0x000006E0L)

//
// MessageId: RPC_S_ENTRY_NOT_FOUND
//
// MessageText:
//
// The entry is not found.
//
#define RPC_S_ENTRY_NOT_FOUND            ((ULONG)0x000006E1L)

//
// MessageId: RPC_S_NAME_SERVICE_UNAVAILABLE
//
// MessageText:
//
// The name service is unavailable.
//
#define RPC_S_NAME_SERVICE_UNAVAILABLE   ((ULONG)0x000006E2L)

//
// MessageId: RPC_S_INVALID_NAF_ID
//
// MessageText:
//
// The network address family is invalid.
//
#define RPC_S_INVALID_NAF_ID             ((ULONG)0x000006E3L)

//
// MessageId: RPC_S_CANNOT_SUPPORT
//
// MessageText:
//
// The requested operation is not supported.
//
#define RPC_S_CANNOT_SUPPORT             ((ULONG)0x000006E4L)

//
// MessageId: RPC_S_NO_CONTEXT_AVAILABLE
//
// MessageText:
//
// No security context is available to allow impersonation.
//
#define RPC_S_NO_CONTEXT_AVAILABLE       ((ULONG)0x000006E5L)

//
// MessageId: RPC_S_INTERNAL_ERROR
//
// MessageText:
//
// An internal error occurred in a remote procedure call (RPC).
//
#define RPC_S_INTERNAL_ERROR             ((ULONG)0x000006E6L)

//
// MessageId: RPC_S_ZERO_DIVIDE
//
// MessageText:
//
// The RPC server attempted an integer division by zero.
//
#define RPC_S_ZERO_DIVIDE                ((ULONG)0x000006E7L)

//
// MessageId: RPC_S_ADDRESS_ERROR
//
// MessageText:
//
// An addressing error occurred in the RPC server.
//
#define RPC_S_ADDRESS_ERROR              ((ULONG)0x000006E8L)

//
// MessageId: RPC_S_FP_DIV_ZERO
//
// MessageText:
//
// A floating-point operation at the RPC server caused a division by zero.
//
#define RPC_S_FP_DIV_ZERO                ((ULONG)0x000006E9L)

//
// MessageId: RPC_S_FP_UNDERFLOW
//
// MessageText:
//
// A floating-point underflow occurred at the RPC server.
//
#define RPC_S_FP_UNDERFLOW               ((ULONG)0x000006EAL)

//
// MessageId: RPC_S_FP_OVERFLOW
//
// MessageText:
//
// A floating-point overflow occurred at the RPC server.
//
#define RPC_S_FP_OVERFLOW                ((ULONG)0x000006EBL)

//
// MessageId: RPC_X_NO_MORE_ENTRIES
//
// MessageText:
//
// The list of RPC servers available for the binding of auto handles has been exhausted.
//
#define RPC_X_NO_MORE_ENTRIES            ((ULONG)0x000006ECL)

//
// MessageId: RPC_X_SS_CHAR_TRANS_OPEN_FAIL
//
// MessageText:
//
// Unable to open the character translation table file.
//
#define RPC_X_SS_CHAR_TRANS_OPEN_FAIL    ((ULONG)0x000006EDL)

//
// MessageId: RPC_X_SS_CHAR_TRANS_SHORT_FILE
//
// MessageText:
//
// The file containing the character translation table has fewer than 512 bytes.
//
#define RPC_X_SS_CHAR_TRANS_SHORT_FILE   ((ULONG)0x000006EEL)

//
// MessageId: RPC_X_SS_IN_NULL_CONTEXT
//
// MessageText:
//
// A null context handle was passed from the client to the host during a remote procedure call.
//
#define RPC_X_SS_IN_NULL_CONTEXT         ((ULONG)0x000006EFL)

//
// MessageId: RPC_X_SS_CONTEXT_DAMAGED
//
// MessageText:
//
// The context handle changed during a remote procedure call.
//
#define RPC_X_SS_CONTEXT_DAMAGED         ((ULONG)0x000006F1L)

//
// MessageId: RPC_X_SS_HANDLES_MISMATCH
//
// MessageText:
//
// The binding handles passed to a remote procedure call do not match.
//
#define RPC_X_SS_HANDLES_MISMATCH        ((ULONG)0x000006F2L)

//
// MessageId: RPC_X_SS_CANNOT_GET_CALL_HANDLE
//
// MessageText:
//
// The stub is unable to get the remote procedure call handle.
//
#define RPC_X_SS_CANNOT_GET_CALL_HANDLE  ((ULONG)0x000006F3L)

//
// MessageId: RPC_X_NULL_REF_POINTER
//
// MessageText:
//
// A null reference pointer was passed to the stub.
//
#define RPC_X_NULL_REF_POINTER           ((ULONG)0x000006F4L)

//
// MessageId: RPC_X_ENUM_VALUE_OUT_OF_RANGE
//
// MessageText:
//
// The enumeration value is out of range.
//
#define RPC_X_ENUM_VALUE_OUT_OF_RANGE    ((ULONG)0x000006F5L)

//
// MessageId: RPC_X_BYTE_COUNT_TOO_SMALL
//
// MessageText:
//
// The byte count is too small.
//
#define RPC_X_BYTE_COUNT_TOO_SMALL       ((ULONG)0x000006F6L)

//
// MessageId: RPC_X_BAD_STUB_DATA
//
// MessageText:
//
// The stub received bad data.
//
#define RPC_X_BAD_STUB_DATA              ((ULONG)0x000006F7L)

//
// MessageId: ERROR_INVALID_USER_BUFFER
//
// MessageText:
//
// The supplied user buffer is not valid for the requested operation.
//
#define ERROR_INVALID_USER_BUFFER        ((ULONG)0x000006F8L)

//
// MessageId: ERROR_UNRECOGNIZED_MEDIA
//
// MessageText:
//
// The disk media is not recognized. It may not be formatted.
//
#define ERROR_UNRECOGNIZED_MEDIA         ((ULONG)0x000006F9L)

//
// MessageId: ERROR_NO_TRUST_LSA_SECRET
//
// MessageText:
//
// The workstation does not have a trust secret.
//
#define ERROR_NO_TRUST_LSA_SECRET        ((ULONG)0x000006FAL)

//
// MessageId: ERROR_NO_TRUST_SAM_ACCOUNT
//
// MessageText:
//
// The security database on the server does not have a computer account for this workstation trust relationship.
//
#define ERROR_NO_TRUST_SAM_ACCOUNT       ((ULONG)0x000006FBL)

//
// MessageId: ERROR_TRUSTED_DOMAIN_FAILURE
//
// MessageText:
//
// The trust relationship between the primary domain and the trusted domain failed.
//
#define ERROR_TRUSTED_DOMAIN_FAILURE     ((ULONG)0x000006FCL)

//
// MessageId: ERROR_TRUSTED_RELATIONSHIP_FAILURE
//
// MessageText:
//
// The trust relationship between this workstation and the primary domain failed.
//
#define ERROR_TRUSTED_RELATIONSHIP_FAILURE ((ULONG)0x000006FDL)

//
// MessageId: ERROR_TRUST_FAILURE
//
// MessageText:
//
// The network logon failed.
//
#define ERROR_TRUST_FAILURE              ((ULONG)0x000006FEL)

//
// MessageId: RPC_S_CALL_IN_PROGRESS
//
// MessageText:
//
// A remote procedure call is already in progress for this thread.
//
#define RPC_S_CALL_IN_PROGRESS           ((ULONG)0x000006FFL)

//
// MessageId: ERROR_NETLOGON_NOT_STARTED
//
// MessageText:
//
// An attempt was made to logon, but the network logon service was not started.
//
#define ERROR_NETLOGON_NOT_STARTED       ((ULONG)0x00000700L)

//
// MessageId: ERROR_ACCOUNT_EXPIRED
//
// MessageText:
//
// The user's account has expired.
//
#define ERROR_ACCOUNT_EXPIRED            ((ULONG)0x00000701L)

//
// MessageId: ERROR_REDIRECTOR_HAS_OPEN_HANDLES
//
// MessageText:
//
// The redirector is in use and cannot be unloaded.
//
#define ERROR_REDIRECTOR_HAS_OPEN_HANDLES ((ULONG)0x00000702L)

//
// MessageId: ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
//
// MessageText:
//
// The specified printer driver is already installed.
//
#define ERROR_PRINTER_DRIVER_ALREADY_INSTALLED ((ULONG)0x00000703L)

//
// MessageId: ERROR_UNKNOWN_PORT
//
// MessageText:
//
// The specified port is unknown.
//
#define ERROR_UNKNOWN_PORT               ((ULONG)0x00000704L)

//
// MessageId: ERROR_UNKNOWN_PRINTER_DRIVER
//
// MessageText:
//
// The printer driver is unknown.
//
#define ERROR_UNKNOWN_PRINTER_DRIVER     ((ULONG)0x00000705L)

//
// MessageId: ERROR_UNKNOWN_PRINTPROCESSOR
//
// MessageText:
//
// The print processor is unknown.
//
#define ERROR_UNKNOWN_PRINTPROCESSOR     ((ULONG)0x00000706L)

//
// MessageId: ERROR_INVALID_SEPARATOR_FILE
//
// MessageText:
//
// The specified separator file is invalid.
//
#define ERROR_INVALID_SEPARATOR_FILE     ((ULONG)0x00000707L)

//
// MessageId: ERROR_INVALID_PRIORITY
//
// MessageText:
//
// The specified priority is invalid.
//
#define ERROR_INVALID_PRIORITY           ((ULONG)0x00000708L)

//
// MessageId: ERROR_INVALID_PRINTER_NAME
//
// MessageText:
//
// The printer name is invalid.
//
#define ERROR_INVALID_PRINTER_NAME       ((ULONG)0x00000709L)

//
// MessageId: ERROR_PRINTER_ALREADY_EXISTS
//
// MessageText:
//
// The printer already exists.
//
#define ERROR_PRINTER_ALREADY_EXISTS     ((ULONG)0x0000070AL)

//
// MessageId: ERROR_INVALID_PRINTER_COMMAND
//
// MessageText:
//
// The printer command is invalid.
//
#define ERROR_INVALID_PRINTER_COMMAND    ((ULONG)0x0000070BL)

//
// MessageId: ERROR_INVALID_DATATYPE
//
// MessageText:
//
// The specified datatype is invalid.
//
#define ERROR_INVALID_DATATYPE           ((ULONG)0x0000070CL)

//
// MessageId: ERROR_INVALID_ENVIRONMENT
//
// MessageText:
//
// The environment specified is invalid.
//
#define ERROR_INVALID_ENVIRONMENT        ((ULONG)0x0000070DL)

//
// MessageId: RPC_S_NO_MORE_BINDINGS
//
// MessageText:
//
// There are no more bindings.
//
#define RPC_S_NO_MORE_BINDINGS           ((ULONG)0x0000070EL)

//
// MessageId: ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is an interdomain trust account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT ((ULONG)0x0000070FL)

//
// MessageId: ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is a computer account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT ((ULONG)0x00000710L)

//
// MessageId: ERROR_NOLOGON_SERVER_TRUST_ACCOUNT
//
// MessageText:
//
// The account used is a server trust account. Use your global user account or local user account to access this server.
//
#define ERROR_NOLOGON_SERVER_TRUST_ACCOUNT ((ULONG)0x00000711L)

//
// MessageId: ERROR_DOMAIN_TRUST_INCONSISTENT
//
// MessageText:
//
// The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.
//
#define ERROR_DOMAIN_TRUST_INCONSISTENT  ((ULONG)0x00000712L)

//
// MessageId: ERROR_SERVER_HAS_OPEN_HANDLES
//
// MessageText:
//
// The server is in use and cannot be unloaded.
//
#define ERROR_SERVER_HAS_OPEN_HANDLES    ((ULONG)0x00000713L)

//
// MessageId: ERROR_RESOURCE_DATA_NOT_FOUND
//
// MessageText:
//
// The specified image file did not contain a resource section.
//
#define ERROR_RESOURCE_DATA_NOT_FOUND    ((ULONG)0x00000714L)

//
// MessageId: ERROR_RESOURCE_TYPE_NOT_FOUND
//
// MessageText:
//
// The specified resource type cannot be found in the image file.
//
#define ERROR_RESOURCE_TYPE_NOT_FOUND    ((ULONG)0x00000715L)

//
// MessageId: ERROR_RESOURCE_NAME_NOT_FOUND
//
// MessageText:
//
// The specified resource name cannot be found in the image file.
//
#define ERROR_RESOURCE_NAME_NOT_FOUND    ((ULONG)0x00000716L)

//
// MessageId: ERROR_RESOURCE_LANG_NOT_FOUND
//
// MessageText:
//
// The specified resource language ID cannot be found in the image file.
//
#define ERROR_RESOURCE_LANG_NOT_FOUND    ((ULONG)0x00000717L)

//
// MessageId: ERROR_NOT_ENOUGH_QUOTA
//
// MessageText:
//
// Not enough quota is available to process this command.
//
#define ERROR_NOT_ENOUGH_QUOTA           ((ULONG)0x00000718L)

//
// MessageId: RPC_S_NO_INTERFACES
//
// MessageText:
//
// No interfaces have been registered.
//
#define RPC_S_NO_INTERFACES              ((ULONG)0x00000719L)

//
// MessageId: RPC_S_CALL_CANCELLED
//
// MessageText:
//
// The remote procedure call was cancelled.
//
#define RPC_S_CALL_CANCELLED             ((ULONG)0x0000071AL)

//
// MessageId: RPC_S_BINDING_INCOMPLETE
//
// MessageText:
//
// The binding handle does not contain all required information.
//
#define RPC_S_BINDING_INCOMPLETE         ((ULONG)0x0000071BL)

//
// MessageId: RPC_S_COMM_FAILURE
//
// MessageText:
//
// A communications failure occurred during a remote procedure call.
//
#define RPC_S_COMM_FAILURE               ((ULONG)0x0000071CL)

//
// MessageId: RPC_S_UNSUPPORTED_AUTHN_LEVEL
//
// MessageText:
//
// The requested authentication level is not supported.
//
#define RPC_S_UNSUPPORTED_AUTHN_LEVEL    ((ULONG)0x0000071DL)

//
// MessageId: RPC_S_NO_PRINC_NAME
//
// MessageText:
//
// No principal name registered.
//
#define RPC_S_NO_PRINC_NAME              ((ULONG)0x0000071EL)

//
// MessageId: RPC_S_NOT_RPC_ERROR
//
// MessageText:
//
// The error specified is not a valid Windows RPC error code.
//
#define RPC_S_NOT_RPC_ERROR              ((ULONG)0x0000071FL)

//
// MessageId: RPC_S_UUID_LOCAL_ONLY
//
// MessageText:
//
// A UUID that is valid only on this computer has been allocated.
//
#define RPC_S_UUID_LOCAL_ONLY            ((ULONG)0x00000720L)

//
// MessageId: RPC_S_SEC_PKG_ERROR
//
// MessageText:
//
// A security package specific error occurred.
//
#define RPC_S_SEC_PKG_ERROR              ((ULONG)0x00000721L)

//
// MessageId: RPC_S_NOT_CANCELLED
//
// MessageText:
//
// Thread is not canceled.
//
#define RPC_S_NOT_CANCELLED              ((ULONG)0x00000722L)

//
// MessageId: RPC_X_INVALID_ES_ACTION
//
// MessageText:
//
// Invalid operation on the encoding/decoding handle.
//
#define RPC_X_INVALID_ES_ACTION          ((ULONG)0x00000723L)

//
// MessageId: RPC_X_WRONG_ES_VERSION
//
// MessageText:
//
// Incompatible version of the serializing package.
//
#define RPC_X_WRONG_ES_VERSION           ((ULONG)0x00000724L)

//
// MessageId: RPC_X_WRONG_STUB_VERSION
//
// MessageText:
//
// Incompatible version of the RPC stub.
//
#define RPC_X_WRONG_STUB_VERSION         ((ULONG)0x00000725L)

//
// MessageId: RPC_X_INVALID_PIPE_OBJECT
//
// MessageText:
//
// The RPC pipe object is invalid or corrupted.
//
#define RPC_X_INVALID_PIPE_OBJECT        ((ULONG)0x00000726L)

//
// MessageId: RPC_X_WRONG_PIPE_ORDER
//
// MessageText:
//
// An invalid operation was attempted on an RPC pipe object.
//
#define RPC_X_WRONG_PIPE_ORDER           ((ULONG)0x00000727L)

//
// MessageId: RPC_X_WRONG_PIPE_VERSION
//
// MessageText:
//
// Unsupported RPC pipe version.
//
#define RPC_X_WRONG_PIPE_VERSION         ((ULONG)0x00000728L)

//
// MessageId: RPC_S_GROUP_MEMBER_NOT_FOUND
//
// MessageText:
//
// The group member was not found.
//
#define RPC_S_GROUP_MEMBER_NOT_FOUND     ((ULONG)0x0000076AL)

//
// MessageId: EPT_S_CANT_CREATE
//
// MessageText:
//
// The endpoint mapper database entry could not be created.
//
#define EPT_S_CANT_CREATE                ((ULONG)0x0000076BL)

//
// MessageId: RPC_S_INVALID_OBJECT
//
// MessageText:
//
// The object universal unique identifier (UUID) is the nil UUID.
//
#define RPC_S_INVALID_OBJECT             ((ULONG)0x0000076CL)

//
// MessageId: ERROR_INVALID_TIME
//
// MessageText:
//
// The specified time is invalid.
//
#define ERROR_INVALID_TIME               ((ULONG)0x0000076DL)

//
// MessageId: ERROR_INVALID_FORM_NAME
//
// MessageText:
//
// The specified form name is invalid.
//
#define ERROR_INVALID_FORM_NAME          ((ULONG)0x0000076EL)

//
// MessageId: ERROR_INVALID_FORM_SIZE
//
// MessageText:
//
// The specified form size is invalid.
//
#define ERROR_INVALID_FORM_SIZE          ((ULONG)0x0000076FL)

//
// MessageId: ERROR_ALREADY_WAITING
//
// MessageText:
//
// The specified printer handle is already being waited on
//
#define ERROR_ALREADY_WAITING            ((ULONG)0x00000770L)

//
// MessageId: ERROR_PRINTER_DELETED
//
// MessageText:
//
// The specified printer has been deleted.
//
#define ERROR_PRINTER_DELETED            ((ULONG)0x00000771L)

//
// MessageId: ERROR_INVALID_PRINTER_STATE
//
// MessageText:
//
// The state of the printer is invalid.
//
#define ERROR_INVALID_PRINTER_STATE      ((ULONG)0x00000772L)

//
// MessageId: ERROR_PASSWORD_MUST_CHANGE
//
// MessageText:
//
// The user's password must be changed before logging on the first time.
//
#define ERROR_PASSWORD_MUST_CHANGE       ((ULONG)0x00000773L)

//
// MessageId: ERROR_DOMAIN_CONTROLLER_NOT_FOUND
//
// MessageText:
//
// Could not find the domain controller for this domain.
//
#define ERROR_DOMAIN_CONTROLLER_NOT_FOUND ((ULONG)0x00000774L)

//
// MessageId: ERROR_ACCOUNT_LOCKED_OUT
//
// MessageText:
//
// The referenced account is currently locked out and may not be used to log on.
//
#define ERROR_ACCOUNT_LOCKED_OUT         ((ULONG)0x00000775L)

//
// MessageId: OR_INVALID_OXID
//
// MessageText:
//
// The object exporter specified was not found.
//
#define OR_INVALID_OXID                  ((ULONG)0x00000776L)

//
// MessageId: OR_INVALID_OID
//
// MessageText:
//
// The object specified was not found.
//
#define OR_INVALID_OID                   ((ULONG)0x00000777L)

//
// MessageId: OR_INVALID_SET
//
// MessageText:
//
// The object resolver set specified was not found.
//
#define OR_INVALID_SET                   ((ULONG)0x00000778L)

//
// MessageId: RPC_S_SEND_INCOMPLETE
//
// MessageText:
//
// Some data remains to be sent in the request buffer.
//
#define RPC_S_SEND_INCOMPLETE            ((ULONG)0x00000779L)

//
// MessageId: RPC_S_INVALID_ASYNC_HANDLE
//
// MessageText:
//
// Invalid asynchronous remote procedure call handle.
//
#define RPC_S_INVALID_ASYNC_HANDLE       ((ULONG)0x0000077AL)

//
// MessageId: RPC_S_INVALID_ASYNC_CALL
//
// MessageText:
//
// Invalid asynchronous RPC call handle for this operation.
//
#define RPC_S_INVALID_ASYNC_CALL         ((ULONG)0x0000077BL)

//
// MessageId: RPC_X_PIPE_CLOSED
//
// MessageText:
//
// The RPC pipe object has already been closed.
//
#define RPC_X_PIPE_CLOSED                ((ULONG)0x0000077CL)

//
// MessageId: RPC_X_PIPE_DISCIPLINE_ERROR
//
// MessageText:
//
// The RPC call completed before all pipes were processed.
//
#define RPC_X_PIPE_DISCIPLINE_ERROR      ((ULONG)0x0000077DL)

//
// MessageId: RPC_X_PIPE_EMPTY
//
// MessageText:
//
// No more data is available from the RPC pipe.
//
#define RPC_X_PIPE_EMPTY                 ((ULONG)0x0000077EL)

//
// MessageId: ERROR_NO_SITENAME
//
// MessageText:
//
// No site name is available for this machine.
//
#define ERROR_NO_SITENAME                ((ULONG)0x0000077FL)

//
// MessageId: ERROR_CANT_ACCESS_FILE
//
// MessageText:
//
// The file cannot be accessed by the system.
//
#define ERROR_CANT_ACCESS_FILE           ((ULONG)0x00000780L)

//
// MessageId: ERROR_CANT_RESOLVE_FILENAME
//
// MessageText:
//
// The name of the file cannot be resolved by the system.
//
#define ERROR_CANT_RESOLVE_FILENAME      ((ULONG)0x00000781L)

//
// MessageId: RPC_S_ENTRY_TYPE_MISMATCH
//
// MessageText:
//
// The entry is not of the expected type.
//
#define RPC_S_ENTRY_TYPE_MISMATCH        ((ULONG)0x00000782L)

//
// MessageId: RPC_S_NOT_ALL_OBJS_EXPORTED
//
// MessageText:
//
// Not all object UUIDs could be exported to the specified entry.
//
#define RPC_S_NOT_ALL_OBJS_EXPORTED      ((ULONG)0x00000783L)

//
// MessageId: RPC_S_INTERFACE_NOT_EXPORTED
//
// MessageText:
//
// Interface could not be exported to the specified entry.
//
#define RPC_S_INTERFACE_NOT_EXPORTED     ((ULONG)0x00000784L)

//
// MessageId: RPC_S_PROFILE_NOT_ADDED
//
// MessageText:
//
// The specified profile entry could not be added.
//
#define RPC_S_PROFILE_NOT_ADDED          ((ULONG)0x00000785L)

//
// MessageId: RPC_S_PRF_ELT_NOT_ADDED
//
// MessageText:
//
// The specified profile element could not be added.
//
#define RPC_S_PRF_ELT_NOT_ADDED          ((ULONG)0x00000786L)

//
// MessageId: RPC_S_PRF_ELT_NOT_REMOVED
//
// MessageText:
//
// The specified profile element could not be removed.
//
#define RPC_S_PRF_ELT_NOT_REMOVED        ((ULONG)0x00000787L)

//
// MessageId: RPC_S_GRP_ELT_NOT_ADDED
//
// MessageText:
//
// The group element could not be added.
//
#define RPC_S_GRP_ELT_NOT_ADDED          ((ULONG)0x00000788L)

//
// MessageId: RPC_S_GRP_ELT_NOT_REMOVED
//
// MessageText:
//
// The group element could not be removed.
//
#define RPC_S_GRP_ELT_NOT_REMOVED        ((ULONG)0x00000789L)

//
// MessageId: ERROR_KM_DRIVER_BLOCKED
//
// MessageText:
//
// The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.
//
#define ERROR_KM_DRIVER_BLOCKED          ((ULONG)0x0000078AL)

//
// MessageId: ERROR_CONTEXT_EXPIRED
//
// MessageText:
//
// The context has expired and can no longer be used.
//
#define ERROR_CONTEXT_EXPIRED            ((ULONG)0x0000078BL)

//
// MessageId: ERROR_PER_USER_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The current user's delegated trust creation quota has been exceeded.
//
#define ERROR_PER_USER_TRUST_QUOTA_EXCEEDED ((ULONG)0x0000078CL)

//
// MessageId: ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The total delegated trust creation quota has been exceeded.
//
#define ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED ((ULONG)0x0000078DL)

//
// MessageId: ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED
//
// MessageText:
//
// The current user's delegated trust deletion quota has been exceeded.
//
#define ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED ((ULONG)0x0000078EL)

//
// MessageId: ERROR_INVALID_PIXEL_FORMAT
//
// MessageText:
//
// The pixel format is invalid.
//
#define ERROR_INVALID_PIXEL_FORMAT       ((ULONG)0x000007D0L)

//
// MessageId: ERROR_BAD_DRIVER
//
// MessageText:
//
// The specified driver is invalid.
//
#define ERROR_BAD_DRIVER                 ((ULONG)0x000007D1L)

//
// MessageId: ERROR_INVALID_WINDOW_STYLE
//
// MessageText:
//
// The window style or class attribute is invalid for this operation.
//
#define ERROR_INVALID_WINDOW_STYLE       ((ULONG)0x000007D2L)

//
// MessageId: ERROR_METAFILE_NOT_SUPPORTED
//
// MessageText:
//
// The requested metafile operation is not supported.
//
#define ERROR_METAFILE_NOT_SUPPORTED     ((ULONG)0x000007D3L)

//
// MessageId: ERROR_TRANSFORM_NOT_SUPPORTED
//
// MessageText:
//
// The requested transformation operation is not supported.
//
#define ERROR_TRANSFORM_NOT_SUPPORTED    ((ULONG)0x000007D4L)

//
// MessageId: ERROR_CLIPPING_NOT_SUPPORTED
//
// MessageText:
//
// The requested clipping operation is not supported.
//
#define ERROR_CLIPPING_NOT_SUPPORTED     ((ULONG)0x000007D5L)

//
// MessageId: ERROR_INVALID_CMM
//
// MessageText:
//
// The specified color management module is invalid.
//
#define ERROR_INVALID_CMM                ((ULONG)0x000007DAL)

//
// MessageId: ERROR_INVALID_PROFILE
//
// MessageText:
//
// The specified color profile is invalid.
//
#define ERROR_INVALID_PROFILE            ((ULONG)0x000007DBL)

//
// MessageId: ERROR_TAG_NOT_FOUND
//
// MessageText:
//
// The specified tag was not found.
//
#define ERROR_TAG_NOT_FOUND              ((ULONG)0x000007DCL)

//
// MessageId: ERROR_TAG_NOT_PRESENT
//
// MessageText:
//
// A required tag is not present.
//
#define ERROR_TAG_NOT_PRESENT            ((ULONG)0x000007DDL)

//
// MessageId: ERROR_DUPLICATE_TAG
//
// MessageText:
//
// The specified tag is already present.
//
#define ERROR_DUPLICATE_TAG              ((ULONG)0x000007DEL)

//
// MessageId: ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE
//
// MessageText:
//
// The specified color profile is not associated with any device.
//
#define ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE ((ULONG)0x000007DFL)

//
// MessageId: ERROR_PROFILE_NOT_FOUND
//
// MessageText:
//
// The specified color profile was not found.
//
#define ERROR_PROFILE_NOT_FOUND          ((ULONG)0x000007E0L)

//
// MessageId: ERROR_INVALID_COLORSPACE
//
// MessageText:
//
// The specified color space is invalid.
//
#define ERROR_INVALID_COLORSPACE         ((ULONG)0x000007E1L)

//
// MessageId: ERROR_ICM_NOT_ENABLED
//
// MessageText:
//
// Image Color Management is not enabled.
//
#define ERROR_ICM_NOT_ENABLED            ((ULONG)0x000007E2L)

//
// MessageId: ERROR_DELETING_ICM_XFORM
//
// MessageText:
//
// There was an error while deleting the color transform.
//
#define ERROR_DELETING_ICM_XFORM         ((ULONG)0x000007E3L)

//
// MessageId: ERROR_INVALID_TRANSFORM
//
// MessageText:
//
// The specified color transform is invalid.
//
#define ERROR_INVALID_TRANSFORM          ((ULONG)0x000007E4L)

//
// MessageId: ERROR_COLORSPACE_MISMATCH
//
// MessageText:
//
// The specified transform does not match the bitmap's color space.
//
#define ERROR_COLORSPACE_MISMATCH        ((ULONG)0x000007E5L)

//
// MessageId: ERROR_INVALID_COLORINDEX
//
// MessageText:
//
// The specified named color index is not present in the profile.
//
#define ERROR_INVALID_COLORINDEX         ((ULONG)0x000007E6L)

//
// MessageId: ERROR_CONNECTED_OTHER_PASSWORD
//
// MessageText:
//
// The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.
//
#define ERROR_CONNECTED_OTHER_PASSWORD   ((ULONG)0x0000083CL)

//
// MessageId: ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
//
// MessageText:
//
// The network connection was made successfully using default credentials.
//
#define ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT ((ULONG)0x0000083DL)

//
// MessageId: ERROR_BAD_USERNAME
//
// MessageText:
//
// The specified username is invalid.
//
#define ERROR_BAD_USERNAME               ((ULONG)0x0000089AL)

//
// MessageId: ERROR_NOT_CONNECTED
//
// MessageText:
//
// This network connection does not exist.
//
#define ERROR_NOT_CONNECTED              ((ULONG)0x000008CAL)

//
// MessageId: ERROR_OPEN_FILES
//
// MessageText:
//
// This network connection has files open or requests pending.
//
#define ERROR_OPEN_FILES                 ((ULONG)0x00000961L)

//
// MessageId: ERROR_ACTIVE_CONNECTIONS
//
// MessageText:
//
// Active connections still exist.
//
#define ERROR_ACTIVE_CONNECTIONS         ((ULONG)0x00000962L)

//
// MessageId: ERROR_DEVICE_IN_USE
//
// MessageText:
//
// The device is in use by an active process and cannot be disconnected.
//
#define ERROR_DEVICE_IN_USE              ((ULONG)0x00000964L)

//
// MessageId: ERROR_UNKNOWN_PRINT_MONITOR
//
// MessageText:
//
// The specified print monitor is unknown.
//
#define ERROR_UNKNOWN_PRINT_MONITOR      ((ULONG)0x00000BB8L)

//
// MessageId: ERROR_PRINTER_DRIVER_IN_USE
//
// MessageText:
//
// The specified printer driver is currently in use.
//
#define ERROR_PRINTER_DRIVER_IN_USE      ((ULONG)0x00000BB9L)

//
// MessageId: ERROR_SPOOL_FILE_NOT_FOUND
//
// MessageText:
//
// The spool file was not found.
//
#define ERROR_SPOOL_FILE_NOT_FOUND       ((ULONG)0x00000BBAL)

//
// MessageId: ERROR_SPL_NO_STARTDOC
//
// MessageText:
//
// A StartDocPrinter call was not issued.
//
#define ERROR_SPL_NO_STARTDOC            ((ULONG)0x00000BBBL)

//
// MessageId: ERROR_SPL_NO_ADDJOB
//
// MessageText:
//
// An AddJob call was not issued.
//
#define ERROR_SPL_NO_ADDJOB              ((ULONG)0x00000BBCL)

//
// MessageId: ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED
//
// MessageText:
//
// The specified print processor has already been installed.
//
#define ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED ((ULONG)0x00000BBDL)

//
// MessageId: ERROR_PRINT_MONITOR_ALREADY_INSTALLED
//
// MessageText:
//
// The specified print monitor has already been installed.
//
#define ERROR_PRINT_MONITOR_ALREADY_INSTALLED ((ULONG)0x00000BBEL)

//
// MessageId: ERROR_INVALID_PRINT_MONITOR
//
// MessageText:
//
// The specified print monitor does not have the required functions.
//
#define ERROR_INVALID_PRINT_MONITOR      ((ULONG)0x00000BBFL)

//
// MessageId: ERROR_PRINT_MONITOR_IN_USE
//
// MessageText:
//
// The specified print monitor is currently in use.
//
#define ERROR_PRINT_MONITOR_IN_USE       ((ULONG)0x00000BC0L)

//
// MessageId: ERROR_PRINTER_HAS_JOBS_QUEUED
//
// MessageText:
//
// The requested operation is not allowed when there are jobs queued to the printer.
//
#define ERROR_PRINTER_HAS_JOBS_QUEUED    ((ULONG)0x00000BC1L)

//
// MessageId: ERROR_SUCCESS_REBOOT_REQUIRED
//
// MessageText:
//
// The requested operation is successful. Changes will not be effective until the system is rebooted.
//
#define ERROR_SUCCESS_REBOOT_REQUIRED    ((ULONG)0x00000BC2L)

//
// MessageId: ERROR_SUCCESS_RESTART_REQUIRED
//
// MessageText:
//
// The requested operation is successful. Changes will not be effective until the service is restarted.
//
#define ERROR_SUCCESS_RESTART_REQUIRED   ((ULONG)0x00000BC3L)

//
// MessageId: ERROR_PRINTER_NOT_FOUND
//
// MessageText:
//
// No printers were found.
//
#define ERROR_PRINTER_NOT_FOUND          ((ULONG)0x00000BC4L)

//
// MessageId: ERROR_PRINTER_DRIVER_WARNED
//
// MessageText:
//
// The printer driver is known to be unreliable.
//
#define ERROR_PRINTER_DRIVER_WARNED      ((ULONG)0x00000BC5L)

//
// MessageId: ERROR_PRINTER_DRIVER_BLOCKED
//
// MessageText:
//
// The printer driver is known to harm the system.
//
#define ERROR_PRINTER_DRIVER_BLOCKED     ((ULONG)0x00000BC6L)

//
// MessageId: ERROR_XML_UNDEFINED_ENTITY
//
// MessageText:
//
// The XML contains an entity reference to an undefined entity.
//
#define ERROR_XML_UNDEFINED_ENTITY       ((ULONG)0x00000C1CL)

//
// MessageId: ERROR_XML_MALFORMED_ENTITY
//
// MessageText:
//
// The XML contains a malformed entity reference.
//
#define ERROR_XML_MALFORMED_ENTITY       ((ULONG)0x00000C1DL)

//
// MessageId: ERROR_XML_CHAR_NOT_IN_RANGE
//
// MessageText:
//
// The XML contains a character which is not permitted in XML.
//
#define ERROR_XML_CHAR_NOT_IN_RANGE      ((ULONG)0x00000C1EL)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_EXTERNAL_PROXY
//
// MessageText:
//
// The manifest contained a duplicate definition for external proxy stub %1 at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_EXTERNAL_PROXY ((ULONG)0x00000C80L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_ASSEMBLY_REFERENCE
//
// MessageText:
//
// The manifest already contains a reference to %4 - a second reference was found at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_ASSEMBLY_REFERENCE ((ULONG)0x00000C81L)

//
// MessageId: ERROR_PCM_COMPILER_INVALID_ASSEMBLY_REFERENCE
//
// MessageText:
//
// The assembly reference at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_INVALID_ASSEMBLY_REFERENCE ((ULONG)0x00000C82L)

//
// MessageId: ERROR_PCM_COMPILER_INVALID_ASSEMBLY_DEFINITION
//
// MessageText:
//
// The assembly definition at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_INVALID_ASSEMBLY_DEFINITION ((ULONG)0x00000C83L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_WINDOW_CLASS
//
// MessageText:
//
// The manifest already contained the window class %4, found a second declaration at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_WINDOW_CLASS ((ULONG)0x00000C84L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_PROGID
//
// MessageText:
//
// The manifest already declared the progId %4, found a second declaration at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_PROGID ((ULONG)0x00000C85L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_NOINHERIT
//
// MessageText:
//
// Only one noInherit tag may be present in a manifest, found a second tag at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_NOINHERIT ((ULONG)0x00000C86L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_NOINHERITABLE
//
// MessageText:
//
// Only one noInheritable tag may be present in a manifest, found a second tag at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_NOINHERITABLE ((ULONG)0x00000C87L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_COM_CLASS
//
// MessageText:
//
// The manifest contained a duplicate declaration of COM class %4 at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_COM_CLASS ((ULONG)0x00000C88L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_FILE_NAME
//
// MessageText:
//
// The manifest already declared the file %4, a second definition was found at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_FILE_NAME ((ULONG)0x00000C89L)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_CLR_SURROGATE
//
// MessageText:
//
// CLR surrogate %1 was already defined, second definition at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_DUPLICATE_CLR_SURROGATE ((ULONG)0x00000C8AL)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_TYPE_LIBRARY
//
// MessageText:
//
// Type library %1 was already defined, second definition at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_DUPLICATE_TYPE_LIBRARY ((ULONG)0x00000C8BL)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_PROXY_STUB
//
// MessageText:
//
// Proxy stub definition %1 was already defined, second definition at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_DUPLICATE_PROXY_STUB ((ULONG)0x00000C8CL)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_CATEGORY_NAME
//
// MessageText:
//
// Category friendly name %4 was already used, second definition was found at (%1:%2,%3) is invalid.
//
#define ERROR_PCM_COMPILER_DUPLICATE_CATEGORY_NAME ((ULONG)0x00000C8DL)

//
// MessageId: ERROR_PCM_COMPILER_DUPLICATE_TOP_LEVEL_IDENTITY_FOUND
//
// MessageText:
//
// Only one top-level assemblyIdentity tag may be present in a manifest. A second tag with identity %4 was found at (%1:%2,%3)
//
#define ERROR_PCM_COMPILER_DUPLICATE_TOP_LEVEL_IDENTITY_FOUND ((ULONG)0x00000C8EL)

//
// MessageId: ERROR_PCM_COMPILER_UNKNOWN_ROOT_ELEMENT
//
// MessageText:
//
// The root element for a manifest found at (%1:%2,%3) was not expected or was of the wrong version.
//
#define ERROR_PCM_COMPILER_UNKNOWN_ROOT_ELEMENT ((ULONG)0x00000C8FL)

//
// MessageId: ERROR_PCM_COMPILER_INVALID_ELEMENT
//
// MessageText:
//
// The element found at (%1:%2,%3) was not expected according to the manifest schema.
//
#define ERROR_PCM_COMPILER_INVALID_ELEMENT ((ULONG)0x00000C90L)

//
// MessageId: ERROR_PCM_COMPILER_MISSING_REQUIRED_ATTRIBUTE
//
// MessageText:
//
// The element found at (%1:%2,%3) was missing the required attribute '%4'. See the manifest schema for more information
//
#define ERROR_PCM_COMPILER_MISSING_REQUIRED_ATTRIBUTE ((ULONG)0x00000C91L)

//
// MessageId: ERROR_PCM_COMPILER_INVALID_ATTRIBUTE_VALUE
//
// MessageText:
//
// The attribute value %4 at (%1:%2,%3) was invalid according to the schema.
//
#define ERROR_PCM_COMPILER_INVALID_ATTRIBUTE_VALUE ((ULONG)0x00000C92L)

//
// MessageId: ERROR_PCM_COMPILER_UNEXPECTED_PCDATA
//
// MessageText:
//
// PCDATA or CDATA found at (%1:%2,%3) in the source document was not expected in the parent element %4.
//
#define ERROR_PCM_COMPILER_UNEXPECTED_PCDATA ((ULONG)0x00000C93L)

//
// MessageId: ERROR_PCM_DUPLICATE_STRING_TABLE_ENT
//
// MessageText:
//
// The string table entry with culture %4, name %5, and value '%6' at (%1:%2,%3) duplicated a previous entry.
//
#define ERROR_PCM_DUPLICATE_STRING_TABLE_ENT ((ULONG)0x00000C94L)

//
// MessageId: ERROR_WINS_INTERNAL
//
// MessageText:
//
// WINS encountered an error while processing the command.
//
#define ERROR_WINS_INTERNAL              ((ULONG)0x00000FA0L)

//
// MessageId: ERROR_CAN_NOT_DEL_LOCAL_WINS
//
// MessageText:
//
// The local WINS cannot be deleted.
//
#define ERROR_CAN_NOT_DEL_LOCAL_WINS     ((ULONG)0x00000FA1L)

//
// MessageId: ERROR_STATIC_INIT
//
// MessageText:
//
// The importation from the file failed.
//
#define ERROR_STATIC_INIT                ((ULONG)0x00000FA2L)

//
// MessageId: ERROR_INC_BACKUP
//
// MessageText:
//
// The backup failed. Was a full backup done before?
//
#define ERROR_INC_BACKUP                 ((ULONG)0x00000FA3L)

//
// MessageId: ERROR_FULL_BACKUP
//
// MessageText:
//
// The backup failed. Check the directory to which you are backing the database.
//
#define ERROR_FULL_BACKUP                ((ULONG)0x00000FA4L)

//
// MessageId: ERROR_REC_NON_EXISTENT
//
// MessageText:
//
// The name does not exist in the WINS database.
//
#define ERROR_REC_NON_EXISTENT           ((ULONG)0x00000FA5L)

//
// MessageId: ERROR_RPL_NOT_ALLOWED
//
// MessageText:
//
// Replication with a nonconfigured partner is not allowed.
//
#define ERROR_RPL_NOT_ALLOWED            ((ULONG)0x00000FA6L)

//
// MessageId: ERROR_DHCP_ADDRESS_CONFLICT
//
// MessageText:
//
// The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.
//
#define ERROR_DHCP_ADDRESS_CONFLICT      ((ULONG)0x00001004L)

//
// MessageId: ERROR_WMI_GUID_NOT_FOUND
//
// MessageText:
//
// The GUID passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_GUID_NOT_FOUND         ((ULONG)0x00001068L)

//
// MessageId: ERROR_WMI_INSTANCE_NOT_FOUND
//
// MessageText:
//
// The instance name passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_INSTANCE_NOT_FOUND     ((ULONG)0x00001069L)

//
// MessageId: ERROR_WMI_ITEMID_NOT_FOUND
//
// MessageText:
//
// The data item ID passed was not recognized as valid by a WMI data provider.
//
#define ERROR_WMI_ITEMID_NOT_FOUND       ((ULONG)0x0000106AL)

//
// MessageId: ERROR_WMI_TRY_AGAIN
//
// MessageText:
//
// The WMI request could not be completed and should be retried.
//
#define ERROR_WMI_TRY_AGAIN              ((ULONG)0x0000106BL)

//
// MessageId: ERROR_WMI_DP_NOT_FOUND
//
// MessageText:
//
// The WMI data provider could not be located.
//
#define ERROR_WMI_DP_NOT_FOUND           ((ULONG)0x0000106CL)

//
// MessageId: ERROR_WMI_UNRESOLVED_INSTANCE_REF
//
// MessageText:
//
// The WMI data provider references an instance set that has not been registered.
//
#define ERROR_WMI_UNRESOLVED_INSTANCE_REF ((ULONG)0x0000106DL)

//
// MessageId: ERROR_WMI_ALREADY_ENABLED
//
// MessageText:
//
// The WMI data block or event notification has already been enabled.
//
#define ERROR_WMI_ALREADY_ENABLED        ((ULONG)0x0000106EL)

//
// MessageId: ERROR_WMI_GUID_DISCONNECTED
//
// MessageText:
//
// The WMI data block is no longer available.
//
#define ERROR_WMI_GUID_DISCONNECTED      ((ULONG)0x0000106FL)

//
// MessageId: ERROR_WMI_SERVER_UNAVAILABLE
//
// MessageText:
//
// The WMI data service is not available.
//
#define ERROR_WMI_SERVER_UNAVAILABLE     ((ULONG)0x00001070L)

//
// MessageId: ERROR_WMI_DP_FAILED
//
// MessageText:
//
// The WMI data provider failed to carry out the request.
//
#define ERROR_WMI_DP_FAILED              ((ULONG)0x00001071L)

//
// MessageId: ERROR_WMI_INVALID_MOF
//
// MessageText:
//
// The WMI MOF information is not valid.
//
#define ERROR_WMI_INVALID_MOF            ((ULONG)0x00001072L)

//
// MessageId: ERROR_WMI_INVALID_REGINFO
//
// MessageText:
//
// The WMI registration information is not valid.
//
#define ERROR_WMI_INVALID_REGINFO        ((ULONG)0x00001073L)

//
// MessageId: ERROR_WMI_ALREADY_DISABLED
//
// MessageText:
//
// The WMI data block or event notification has already been disabled.
//
#define ERROR_WMI_ALREADY_DISABLED       ((ULONG)0x00001074L)

//
// MessageId: ERROR_WMI_READ_ONLY
//
// MessageText:
//
// The WMI data item or data block is read-only.
//
#define ERROR_WMI_READ_ONLY              ((ULONG)0x00001075L)

//
// MessageId: ERROR_WMI_SET_FAILURE
//
// MessageText:
//
// The WMI data item or data block could not be changed.
//
#define ERROR_WMI_SET_FAILURE            ((ULONG)0x00001076L)

//
// MessageId: ERROR_INVALID_MEDIA
//
// MessageText:
//
// The media identifier does not represent a valid medium.
//
#define ERROR_INVALID_MEDIA              ((ULONG)0x000010CCL)

//
// MessageId: ERROR_INVALID_LIBRARY
//
// MessageText:
//
// The library identifier does not represent a valid library.
//
#define ERROR_INVALID_LIBRARY            ((ULONG)0x000010CDL)

//
// MessageId: ERROR_INVALID_MEDIA_POOL
//
// MessageText:
//
// The media pool identifier does not represent a valid media pool.
//
#define ERROR_INVALID_MEDIA_POOL         ((ULONG)0x000010CEL)

//
// MessageId: ERROR_DRIVE_MEDIA_MISMATCH
//
// MessageText:
//
// The drive and medium are not compatible or exist in different libraries.
//
#define ERROR_DRIVE_MEDIA_MISMATCH       ((ULONG)0x000010CFL)

//
// MessageId: ERROR_MEDIA_OFFLINE
//
// MessageText:
//
// The medium currently exists in an offline library and must be online to perform this operation.
//
#define ERROR_MEDIA_OFFLINE              ((ULONG)0x000010D0L)

//
// MessageId: ERROR_LIBRARY_OFFLINE
//
// MessageText:
//
// The operation cannot be performed on an offline library.
//
#define ERROR_LIBRARY_OFFLINE            ((ULONG)0x000010D1L)

//
// MessageId: ERROR_EMPTY
//
// MessageText:
//
// The library, drive, or media pool is empty.
//
#define ERROR_EMPTY                      ((ULONG)0x000010D2L)

//
// MessageId: ERROR_NOT_EMPTY
//
// MessageText:
//
// The library, drive, or media pool must be empty to perform this operation.
//
#define ERROR_NOT_EMPTY                  ((ULONG)0x000010D3L)

//
// MessageId: ERROR_MEDIA_UNAVAILABLE
//
// MessageText:
//
// No media is currently available in this media pool or library.
//
#define ERROR_MEDIA_UNAVAILABLE          ((ULONG)0x000010D4L)

//
// MessageId: ERROR_RESOURCE_DISABLED
//
// MessageText:
//
// A resource required for this operation is disabled.
//
#define ERROR_RESOURCE_DISABLED          ((ULONG)0x000010D5L)

//
// MessageId: ERROR_INVALID_CLEANER
//
// MessageText:
//
// The media identifier does not represent a valid cleaner.
//
#define ERROR_INVALID_CLEANER            ((ULONG)0x000010D6L)

//
// MessageId: ERROR_UNABLE_TO_CLEAN
//
// MessageText:
//
// The drive cannot be cleaned or does not support cleaning.
//
#define ERROR_UNABLE_TO_CLEAN            ((ULONG)0x000010D7L)

//
// MessageId: ERROR_OBJECT_NOT_FOUND
//
// MessageText:
//
// The object identifier does not represent a valid object.
//
#define ERROR_OBJECT_NOT_FOUND           ((ULONG)0x000010D8L)

//
// MessageId: ERROR_DATABASE_FAILURE
//
// MessageText:
//
// Unable to read from or write to the database.
//
#define ERROR_DATABASE_FAILURE           ((ULONG)0x000010D9L)

//
// MessageId: ERROR_DATABASE_FULL
//
// MessageText:
//
// The database is full.
//
#define ERROR_DATABASE_FULL              ((ULONG)0x000010DAL)

//
// MessageId: ERROR_MEDIA_INCOMPATIBLE
//
// MessageText:
//
// The medium is not compatible with the device or media pool.
//
#define ERROR_MEDIA_INCOMPATIBLE         ((ULONG)0x000010DBL)

//
// MessageId: ERROR_RESOURCE_NOT_PRESENT
//
// MessageText:
//
// The resource required for this operation does not exist.
//
#define ERROR_RESOURCE_NOT_PRESENT       ((ULONG)0x000010DCL)

//
// MessageId: ERROR_INVALID_OPERATION
//
// MessageText:
//
// The operation identifier is not valid.
//
#define ERROR_INVALID_OPERATION          ((ULONG)0x000010DDL)

//
// MessageId: ERROR_MEDIA_NOT_AVAILABLE
//
// MessageText:
//
// The media is not mounted or ready for use.
//
#define ERROR_MEDIA_NOT_AVAILABLE        ((ULONG)0x000010DEL)

//
// MessageId: ERROR_DEVICE_NOT_AVAILABLE
//
// MessageText:
//
// The device is not ready for use.
//
#define ERROR_DEVICE_NOT_AVAILABLE       ((ULONG)0x000010DFL)

//
// MessageId: ERROR_REQUEST_REFUSED
//
// MessageText:
//
// The operator or administrator has refused the request.
//
#define ERROR_REQUEST_REFUSED            ((ULONG)0x000010E0L)

//
// MessageId: ERROR_INVALID_DRIVE_OBJECT
//
// MessageText:
//
// The drive identifier does not represent a valid drive.
//
#define ERROR_INVALID_DRIVE_OBJECT       ((ULONG)0x000010E1L)

//
// MessageId: ERROR_LIBRARY_FULL
//
// MessageText:
//
// Library is full. No slot is available for use.
//
#define ERROR_LIBRARY_FULL               ((ULONG)0x000010E2L)

//
// MessageId: ERROR_MEDIUM_NOT_ACCESSIBLE
//
// MessageText:
//
// The transport cannot access the medium.
//
#define ERROR_MEDIUM_NOT_ACCESSIBLE      ((ULONG)0x000010E3L)

//
// MessageId: ERROR_UNABLE_TO_LOAD_MEDIUM
//
// MessageText:
//
// Unable to load the medium into the drive.
//
#define ERROR_UNABLE_TO_LOAD_MEDIUM      ((ULONG)0x000010E4L)

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_DRIVE
//
// MessageText:
//
// Unable to retrieve status about the drive.
//
#define ERROR_UNABLE_TO_INVENTORY_DRIVE  ((ULONG)0x000010E5L)

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_SLOT
//
// MessageText:
//
// Unable to retrieve status about the slot.
//
#define ERROR_UNABLE_TO_INVENTORY_SLOT   ((ULONG)0x000010E6L)

//
// MessageId: ERROR_UNABLE_TO_INVENTORY_TRANSPORT
//
// MessageText:
//
// Unable to retrieve status about the transport.
//
#define ERROR_UNABLE_TO_INVENTORY_TRANSPORT ((ULONG)0x000010E7L)

//
// MessageId: ERROR_TRANSPORT_FULL
//
// MessageText:
//
// Cannot use the transport because it is already in use.
//
#define ERROR_TRANSPORT_FULL             ((ULONG)0x000010E8L)

//
// MessageId: ERROR_CONTROLLING_IEPORT
//
// MessageText:
//
// Unable to open or close the inject/eject port.
//
#define ERROR_CONTROLLING_IEPORT         ((ULONG)0x000010E9L)

//
// MessageId: ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA
//
// MessageText:
//
// Unable to eject the media because it is in a drive.
//
#define ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA ((ULONG)0x000010EAL)

//
// MessageId: ERROR_CLEANER_SLOT_SET
//
// MessageText:
//
// A cleaner slot is already reserved.
//
#define ERROR_CLEANER_SLOT_SET           ((ULONG)0x000010EBL)

//
// MessageId: ERROR_CLEANER_SLOT_NOT_SET
//
// MessageText:
//
// A cleaner slot is not reserved.
//
#define ERROR_CLEANER_SLOT_NOT_SET       ((ULONG)0x000010ECL)

//
// MessageId: ERROR_CLEANER_CARTRIDGE_SPENT
//
// MessageText:
//
// The cleaner cartridge has performed the maximum number of drive cleanings.
//
#define ERROR_CLEANER_CARTRIDGE_SPENT    ((ULONG)0x000010EDL)

//
// MessageId: ERROR_UNEXPECTED_OMID
//
// MessageText:
//
// Unexpected on-medium identifier.
//
#define ERROR_UNEXPECTED_OMID            ((ULONG)0x000010EEL)

//
// MessageId: ERROR_CANT_DELETE_LAST_ITEM
//
// MessageText:
//
// The last remaining item in this group or resource cannot be deleted.
//
#define ERROR_CANT_DELETE_LAST_ITEM      ((ULONG)0x000010EFL)

//
// MessageId: ERROR_MESSAGE_EXCEEDS_MAX_SIZE
//
// MessageText:
//
// The message provided exceeds the maximum size allowed for this parameter.
//
#define ERROR_MESSAGE_EXCEEDS_MAX_SIZE   ((ULONG)0x000010F0L)

//
// MessageId: ERROR_VOLUME_CONTAINS_SYS_FILES
//
// MessageText:
//
// The volume contains system or paging files.
//
#define ERROR_VOLUME_CONTAINS_SYS_FILES  ((ULONG)0x000010F1L)

//
// MessageId: ERROR_INDIGENOUS_TYPE
//
// MessageText:
//
// The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.
//
#define ERROR_INDIGENOUS_TYPE            ((ULONG)0x000010F2L)

//
// MessageId: ERROR_NO_SUPPORTING_DRIVES
//
// MessageText:
//
// This offline media cannot be mounted on this system since no enabled drives are present which can be used.
//
#define ERROR_NO_SUPPORTING_DRIVES       ((ULONG)0x000010F3L)

//
// MessageId: ERROR_CLEANER_CARTRIDGE_INSTALLED
//
// MessageText:
//
// A cleaner cartridge is present in the tape library.
//
#define ERROR_CLEANER_CARTRIDGE_INSTALLED ((ULONG)0x000010F4L)

//
// MessageId: ERROR_FILE_OFFLINE
//
// MessageText:
//
// The remote storage service was not able to recall the file.
//
#define ERROR_FILE_OFFLINE               ((ULONG)0x000010FEL)

//
// MessageId: ERROR_REMOTE_STORAGE_NOT_ACTIVE
//
// MessageText:
//
// The remote storage service is not operational at this time.
//
#define ERROR_REMOTE_STORAGE_NOT_ACTIVE  ((ULONG)0x000010FFL)

//
// MessageId: ERROR_REMOTE_STORAGE_MEDIA_ERROR
//
// MessageText:
//
// The remote storage service encountered a media error.
//
#define ERROR_REMOTE_STORAGE_MEDIA_ERROR ((ULONG)0x00001100L)

//
// MessageId: ERROR_NOT_A_REPARSE_POINT
//
// MessageText:
//
// The file or directory is not a reparse point.
//
#define ERROR_NOT_A_REPARSE_POINT        ((ULONG)0x00001126L)

//
// MessageId: ERROR_REPARSE_ATTRIBUTE_CONFLICT
//
// MessageText:
//
// The reparse point attribute cannot be set because it conflicts with an existing attribute.
//
#define ERROR_REPARSE_ATTRIBUTE_CONFLICT ((ULONG)0x00001127L)

//
// MessageId: ERROR_INVALID_REPARSE_DATA
//
// MessageText:
//
// The data present in the reparse point buffer is invalid.
//
#define ERROR_INVALID_REPARSE_DATA       ((ULONG)0x00001128L)

//
// MessageId: ERROR_REPARSE_TAG_INVALID
//
// MessageText:
//
// The tag present in the reparse point buffer is invalid.
//
#define ERROR_REPARSE_TAG_INVALID        ((ULONG)0x00001129L)

//
// MessageId: ERROR_REPARSE_TAG_MISMATCH
//
// MessageText:
//
// There is a mismatch between the tag specified in the request and the tag present in the reparse point.
//
#define ERROR_REPARSE_TAG_MISMATCH       ((ULONG)0x0000112AL)

//
// MessageId: ERROR_VOLUME_NOT_SIS_ENABLED
//
// MessageText:
//
// Single Instance Storage is not available on this volume.
//
#define ERROR_VOLUME_NOT_SIS_ENABLED     ((ULONG)0x00001194L)

//
// MessageId: ERROR_DEPENDENT_RESOURCE_EXISTS
//
// MessageText:
//
// The cluster resource cannot be moved to another group because other resources are dependent on it.
//
#define ERROR_DEPENDENT_RESOURCE_EXISTS  ((ULONG)0x00001389L)

//
// MessageId: ERROR_DEPENDENCY_NOT_FOUND
//
// MessageText:
//
// The cluster resource dependency cannot be found.
//
#define ERROR_DEPENDENCY_NOT_FOUND       ((ULONG)0x0000138AL)

//
// MessageId: ERROR_DEPENDENCY_ALREADY_EXISTS
//
// MessageText:
//
// The cluster resource cannot be made dependent on the specified resource because it is already dependent.
//
#define ERROR_DEPENDENCY_ALREADY_EXISTS  ((ULONG)0x0000138BL)

//
// MessageId: ERROR_RESOURCE_NOT_ONLINE
//
// MessageText:
//
// The cluster resource is not online.
//
#define ERROR_RESOURCE_NOT_ONLINE        ((ULONG)0x0000138CL)

//
// MessageId: ERROR_HOST_NODE_NOT_AVAILABLE
//
// MessageText:
//
// A cluster node is not available for this operation.
//
#define ERROR_HOST_NODE_NOT_AVAILABLE    ((ULONG)0x0000138DL)

//
// MessageId: ERROR_RESOURCE_NOT_AVAILABLE
//
// MessageText:
//
// The cluster resource is not available.
//
#define ERROR_RESOURCE_NOT_AVAILABLE     ((ULONG)0x0000138EL)

//
// MessageId: ERROR_RESOURCE_NOT_FOUND
//
// MessageText:
//
// The cluster resource could not be found.
//
#define ERROR_RESOURCE_NOT_FOUND         ((ULONG)0x0000138FL)

//
// MessageId: ERROR_SHUTDOWN_CLUSTER
//
// MessageText:
//
// The cluster is being shut down.
//
#define ERROR_SHUTDOWN_CLUSTER           ((ULONG)0x00001390L)

//
// MessageId: ERROR_CANT_EVICT_ACTIVE_NODE
//
// MessageText:
//
// A cluster node cannot be evicted from the cluster unless the node is down.
//
#define ERROR_CANT_EVICT_ACTIVE_NODE     ((ULONG)0x00001391L)

//
// MessageId: ERROR_OBJECT_ALREADY_EXISTS
//
// MessageText:
//
// The object already exists.
//
#define ERROR_OBJECT_ALREADY_EXISTS      ((ULONG)0x00001392L)

//
// MessageId: ERROR_OBJECT_IN_LIST
//
// MessageText:
//
// The object is already in the list.
//
#define ERROR_OBJECT_IN_LIST             ((ULONG)0x00001393L)

//
// MessageId: ERROR_GROUP_NOT_AVAILABLE
//
// MessageText:
//
// The cluster group is not available for any new requests.
//
#define ERROR_GROUP_NOT_AVAILABLE        ((ULONG)0x00001394L)

//
// MessageId: ERROR_GROUP_NOT_FOUND
//
// MessageText:
//
// The cluster group could not be found.
//
#define ERROR_GROUP_NOT_FOUND            ((ULONG)0x00001395L)

//
// MessageId: ERROR_GROUP_NOT_ONLINE
//
// MessageText:
//
// The operation could not be completed because the cluster group is not online.
//
#define ERROR_GROUP_NOT_ONLINE           ((ULONG)0x00001396L)

//
// MessageId: ERROR_HOST_NODE_NOT_RESOURCE_OWNER
//
// MessageText:
//
// The cluster node is not the owner of the resource.
//
#define ERROR_HOST_NODE_NOT_RESOURCE_OWNER ((ULONG)0x00001397L)

//
// MessageId: ERROR_HOST_NODE_NOT_GROUP_OWNER
//
// MessageText:
//
// The cluster node is not the owner of the group.
//
#define ERROR_HOST_NODE_NOT_GROUP_OWNER  ((ULONG)0x00001398L)

//
// MessageId: ERROR_RESMON_CREATE_FAILED
//
// MessageText:
//
// The cluster resource could not be created in the specified resource monitor.
//
#define ERROR_RESMON_CREATE_FAILED       ((ULONG)0x00001399L)

//
// MessageId: ERROR_RESMON_ONLINE_FAILED
//
// MessageText:
//
// The cluster resource could not be brought online by the resource monitor.
//
#define ERROR_RESMON_ONLINE_FAILED       ((ULONG)0x0000139AL)

//
// MessageId: ERROR_RESOURCE_ONLINE
//
// MessageText:
//
// The operation could not be completed because the cluster resource is online.
//
#define ERROR_RESOURCE_ONLINE            ((ULONG)0x0000139BL)

//
// MessageId: ERROR_QUORUM_RESOURCE
//
// MessageText:
//
// The cluster resource could not be deleted or brought offline because it is the quorum resource.
//
#define ERROR_QUORUM_RESOURCE            ((ULONG)0x0000139CL)

//
// MessageId: ERROR_NOT_QUORUM_CAPABLE
//
// MessageText:
//
// The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.
//
#define ERROR_NOT_QUORUM_CAPABLE         ((ULONG)0x0000139DL)

//
// MessageId: ERROR_CLUSTER_SHUTTING_DOWN
//
// MessageText:
//
// The cluster software is shutting down.
//
#define ERROR_CLUSTER_SHUTTING_DOWN      ((ULONG)0x0000139EL)

//
// MessageId: ERROR_INVALID_STATE
//
// MessageText:
//
// The group or resource is not in the correct state to perform the requested operation.
//
#define ERROR_INVALID_STATE              ((ULONG)0x0000139FL)

//
// MessageId: ERROR_RESOURCE_PROPERTIES_STORED
//
// MessageText:
//
// The properties were stored but not all changes will take effect until the next time the resource is brought online.
//
#define ERROR_RESOURCE_PROPERTIES_STORED ((ULONG)0x000013A0L)

//
// MessageId: ERROR_NOT_QUORUM_CLASS
//
// MessageText:
//
// The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.
//
#define ERROR_NOT_QUORUM_CLASS           ((ULONG)0x000013A1L)

//
// MessageId: ERROR_CORE_RESOURCE
//
// MessageText:
//
// The cluster resource could not be deleted since it is a core resource.
//
#define ERROR_CORE_RESOURCE              ((ULONG)0x000013A2L)

//
// MessageId: ERROR_QUORUM_RESOURCE_ONLINE_FAILED
//
// MessageText:
//
// The quorum resource failed to come online.
//
#define ERROR_QUORUM_RESOURCE_ONLINE_FAILED ((ULONG)0x000013A3L)

//
// MessageId: ERROR_QUORUMLOG_OPEN_FAILED
//
// MessageText:
//
// The quorum log could not be created or mounted successfully.
//
#define ERROR_QUORUMLOG_OPEN_FAILED      ((ULONG)0x000013A4L)

//
// MessageId: ERROR_CLUSTERLOG_CORRUPT
//
// MessageText:
//
// The cluster log is corrupt.
//
#define ERROR_CLUSTERLOG_CORRUPT         ((ULONG)0x000013A5L)

//
// MessageId: ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE
//
// MessageText:
//
// The record could not be written to the cluster log since it exceeds the maximum size.
//
#define ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE ((ULONG)0x000013A6L)

//
// MessageId: ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE
//
// MessageText:
//
// The cluster log exceeds its maximum size.
//
#define ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE ((ULONG)0x000013A7L)

//
// MessageId: ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND
//
// MessageText:
//
// No checkpoint record was found in the cluster log.
//
#define ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND ((ULONG)0x000013A8L)

//
// MessageId: ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE
//
// MessageText:
//
// The minimum required disk space needed for logging is not available.
//
#define ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE ((ULONG)0x000013A9L)

//
// MessageId: ERROR_QUORUM_OWNER_ALIVE
//
// MessageText:
//
// The cluster node failed to take control of the quorum resource because the resource is owned by another active node.
//
#define ERROR_QUORUM_OWNER_ALIVE         ((ULONG)0x000013AAL)

//
// MessageId: ERROR_NETWORK_NOT_AVAILABLE
//
// MessageText:
//
// A cluster network is not available for this operation.
//
#define ERROR_NETWORK_NOT_AVAILABLE      ((ULONG)0x000013ABL)

//
// MessageId: ERROR_NODE_NOT_AVAILABLE
//
// MessageText:
//
// A cluster node is not available for this operation.
//
#define ERROR_NODE_NOT_AVAILABLE         ((ULONG)0x000013ACL)

//
// MessageId: ERROR_ALL_NODES_NOT_AVAILABLE
//
// MessageText:
//
// All cluster nodes must be running to perform this operation.
//
#define ERROR_ALL_NODES_NOT_AVAILABLE    ((ULONG)0x000013ADL)

//
// MessageId: ERROR_RESOURCE_FAILED
//
// MessageText:
//
// A cluster resource failed.
//
#define ERROR_RESOURCE_FAILED            ((ULONG)0x000013AEL)

//
// MessageId: ERROR_CLUSTER_INVALID_NODE
//
// MessageText:
//
// The cluster node is not valid.
//
#define ERROR_CLUSTER_INVALID_NODE       ((ULONG)0x000013AFL)

//
// MessageId: ERROR_CLUSTER_NODE_EXISTS
//
// MessageText:
//
// The cluster node already exists.
//
#define ERROR_CLUSTER_NODE_EXISTS        ((ULONG)0x000013B0L)

//
// MessageId: ERROR_CLUSTER_JOIN_IN_PROGRESS
//
// MessageText:
//
// A node is in the process of joining the cluster.
//
#define ERROR_CLUSTER_JOIN_IN_PROGRESS   ((ULONG)0x000013B1L)

//
// MessageId: ERROR_CLUSTER_NODE_NOT_FOUND
//
// MessageText:
//
// The cluster node was not found.
//
#define ERROR_CLUSTER_NODE_NOT_FOUND     ((ULONG)0x000013B2L)

//
// MessageId: ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND
//
// MessageText:
//
// The cluster local node information was not found.
//
#define ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND ((ULONG)0x000013B3L)

//
// MessageId: ERROR_CLUSTER_NETWORK_EXISTS
//
// MessageText:
//
// The cluster network already exists.
//
#define ERROR_CLUSTER_NETWORK_EXISTS     ((ULONG)0x000013B4L)

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_FOUND
//
// MessageText:
//
// The cluster network was not found.
//
#define ERROR_CLUSTER_NETWORK_NOT_FOUND  ((ULONG)0x000013B5L)

//
// MessageId: ERROR_CLUSTER_NETINTERFACE_EXISTS
//
// MessageText:
//
// The cluster network interface already exists.
//
#define ERROR_CLUSTER_NETINTERFACE_EXISTS ((ULONG)0x000013B6L)

//
// MessageId: ERROR_CLUSTER_NETINTERFACE_NOT_FOUND
//
// MessageText:
//
// The cluster network interface was not found.
//
#define ERROR_CLUSTER_NETINTERFACE_NOT_FOUND ((ULONG)0x000013B7L)

//
// MessageId: ERROR_CLUSTER_INVALID_REQUEST
//
// MessageText:
//
// The cluster request is not valid for this object.
//
#define ERROR_CLUSTER_INVALID_REQUEST    ((ULONG)0x000013B8L)

//
// MessageId: ERROR_CLUSTER_INVALID_NETWORK_PROVIDER
//
// MessageText:
//
// The cluster network provider is not valid.
//
#define ERROR_CLUSTER_INVALID_NETWORK_PROVIDER ((ULONG)0x000013B9L)

//
// MessageId: ERROR_CLUSTER_NODE_DOWN
//
// MessageText:
//
// The cluster node is down.
//
#define ERROR_CLUSTER_NODE_DOWN          ((ULONG)0x000013BAL)

//
// MessageId: ERROR_CLUSTER_NODE_UNREACHABLE
//
// MessageText:
//
// The cluster node is not reachable.
//
#define ERROR_CLUSTER_NODE_UNREACHABLE   ((ULONG)0x000013BBL)

//
// MessageId: ERROR_CLUSTER_NODE_NOT_MEMBER
//
// MessageText:
//
// The cluster node is not a member of the cluster.
//
#define ERROR_CLUSTER_NODE_NOT_MEMBER    ((ULONG)0x000013BCL)

//
// MessageId: ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS
//
// MessageText:
//
// A cluster join operation is not in progress.
//
#define ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS ((ULONG)0x000013BDL)

//
// MessageId: ERROR_CLUSTER_INVALID_NETWORK
//
// MessageText:
//
// The cluster network is not valid.
//
#define ERROR_CLUSTER_INVALID_NETWORK    ((ULONG)0x000013BEL)

//
// MessageId: ERROR_CLUSTER_NODE_UP
//
// MessageText:
//
// The cluster node is up.
//
#define ERROR_CLUSTER_NODE_UP            ((ULONG)0x000013C0L)

//
// MessageId: ERROR_CLUSTER_IPADDR_IN_USE
//
// MessageText:
//
// The cluster IP address is already in use.
//
#define ERROR_CLUSTER_IPADDR_IN_USE      ((ULONG)0x000013C1L)

//
// MessageId: ERROR_CLUSTER_NODE_NOT_PAUSED
//
// MessageText:
//
// The cluster node is not paused.
//
#define ERROR_CLUSTER_NODE_NOT_PAUSED    ((ULONG)0x000013C2L)

//
// MessageId: ERROR_CLUSTER_NO_SECURITY_CONTEXT
//
// MessageText:
//
// No cluster security context is available.
//
#define ERROR_CLUSTER_NO_SECURITY_CONTEXT ((ULONG)0x000013C3L)

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_INTERNAL
//
// MessageText:
//
// The cluster network is not configured for internal cluster communication.
//
#define ERROR_CLUSTER_NETWORK_NOT_INTERNAL ((ULONG)0x000013C4L)

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_UP
//
// MessageText:
//
// The cluster node is already up.
//
#define ERROR_CLUSTER_NODE_ALREADY_UP    ((ULONG)0x000013C5L)

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_DOWN
//
// MessageText:
//
// The cluster node is already down.
//
#define ERROR_CLUSTER_NODE_ALREADY_DOWN  ((ULONG)0x000013C6L)

//
// MessageId: ERROR_CLUSTER_NETWORK_ALREADY_ONLINE
//
// MessageText:
//
// The cluster network is already online.
//
#define ERROR_CLUSTER_NETWORK_ALREADY_ONLINE ((ULONG)0x000013C7L)

//
// MessageId: ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE
//
// MessageText:
//
// The cluster network is already offline.
//
#define ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE ((ULONG)0x000013C8L)

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_MEMBER
//
// MessageText:
//
// The cluster node is already a member of the cluster.
//
#define ERROR_CLUSTER_NODE_ALREADY_MEMBER ((ULONG)0x000013C9L)

//
// MessageId: ERROR_CLUSTER_LAST_INTERNAL_NETWORK
//
// MessageText:
//
// The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.
//
#define ERROR_CLUSTER_LAST_INTERNAL_NETWORK ((ULONG)0x000013CAL)

//
// MessageId: ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS
//
// MessageText:
//
// One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.
//
#define ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS ((ULONG)0x000013CBL)

//
// MessageId: ERROR_INVALID_OPERATION_ON_QUORUM
//
// MessageText:
//
// This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.
//
#define ERROR_INVALID_OPERATION_ON_QUORUM ((ULONG)0x000013CCL)

//
// MessageId: ERROR_DEPENDENCY_NOT_ALLOWED
//
// MessageText:
//
// The cluster quorum resource is not allowed to have any dependencies.
//
#define ERROR_DEPENDENCY_NOT_ALLOWED     ((ULONG)0x000013CDL)

//
// MessageId: ERROR_CLUSTER_NODE_PAUSED
//
// MessageText:
//
// The cluster node is paused.
//
#define ERROR_CLUSTER_NODE_PAUSED        ((ULONG)0x000013CEL)

//
// MessageId: ERROR_NODE_CANT_HOST_RESOURCE
//
// MessageText:
//
// The cluster resource cannot be brought online. The owner node cannot run this resource.
//
#define ERROR_NODE_CANT_HOST_RESOURCE    ((ULONG)0x000013CFL)

//
// MessageId: ERROR_CLUSTER_NODE_NOT_READY
//
// MessageText:
//
// The cluster node is not ready to perform the requested operation.
//
#define ERROR_CLUSTER_NODE_NOT_READY     ((ULONG)0x000013D0L)

//
// MessageId: ERROR_CLUSTER_NODE_SHUTTING_DOWN
//
// MessageText:
//
// The cluster node is shutting down.
//
#define ERROR_CLUSTER_NODE_SHUTTING_DOWN ((ULONG)0x000013D1L)

//
// MessageId: ERROR_CLUSTER_JOIN_ABORTED
//
// MessageText:
//
// The cluster join operation was aborted.
//
#define ERROR_CLUSTER_JOIN_ABORTED       ((ULONG)0x000013D2L)

//
// MessageId: ERROR_CLUSTER_INCOMPATIBLE_VERSIONS
//
// MessageText:
//
// The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.
//
#define ERROR_CLUSTER_INCOMPATIBLE_VERSIONS ((ULONG)0x000013D3L)

//
// MessageId: ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED
//
// MessageText:
//
// This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.
//
#define ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED ((ULONG)0x000013D4L)

//
// MessageId: ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED
//
// MessageText:
//
// The system configuration changed during the cluster join or form operation. The join or form operation was aborted.
//
#define ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED ((ULONG)0x000013D5L)

//
// MessageId: ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND
//
// MessageText:
//
// The specified resource type was not found.
//
#define ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND ((ULONG)0x000013D6L)

//
// MessageId: ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED
//
// MessageText:
//
// The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.
//
#define ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED ((ULONG)0x000013D7L)

//
// MessageId: ERROR_CLUSTER_RESNAME_NOT_FOUND
//
// MessageText:
//
// The specified resource name is supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.
//
#define ERROR_CLUSTER_RESNAME_NOT_FOUND  ((ULONG)0x000013D8L)

//
// MessageId: ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED
//
// MessageText:
//
// No authentication package could be registered with the RPC server.
//
#define ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED ((ULONG)0x000013D9L)

//
// MessageId: ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST
//
// MessageText:
//
// You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.
//
#define ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST ((ULONG)0x000013DAL)

//
// MessageId: ERROR_CLUSTER_DATABASE_SEQMISMATCH
//
// MessageText:
//
// The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.
//
#define ERROR_CLUSTER_DATABASE_SEQMISMATCH ((ULONG)0x000013DBL)

//
// MessageId: ERROR_RESMON_INVALID_STATE
//
// MessageText:
//
// The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.
//
#define ERROR_RESMON_INVALID_STATE       ((ULONG)0x000013DCL)

//
// MessageId: ERROR_CLUSTER_GUM_NOT_LOCKER
//
// MessageText:
//
// A non locker code got a request to reserve the lock for making global updates.
//
#define ERROR_CLUSTER_GUM_NOT_LOCKER     ((ULONG)0x000013DDL)

//
// MessageId: ERROR_QUORUM_DISK_NOT_FOUND
//
// MessageText:
//
// The quorum disk could not be located by the cluster service.
//
#define ERROR_QUORUM_DISK_NOT_FOUND      ((ULONG)0x000013DEL)

//
// MessageId: ERROR_DATABASE_BACKUP_CORRUPT
//
// MessageText:
//
// The backup up cluster database is possibly corrupt.
//
#define ERROR_DATABASE_BACKUP_CORRUPT    ((ULONG)0x000013DFL)

//
// MessageId: ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT
//
// MessageText:
//
// A DFS root already exists in this cluster node.
//
#define ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT ((ULONG)0x000013E0L)

//
// MessageId: ERROR_RESOURCE_PROPERTY_UNCHANGEABLE
//
// MessageText:
//
// An attempt to modify a resource property failed because it conflicts with another existing property.
//
#define ERROR_RESOURCE_PROPERTY_UNCHANGEABLE ((ULONG)0x000013E1L)

//
// MessageId: ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE
//
// MessageText:
//
// An operation was attempted that is incompatible with the current membership state of the node.
//
#define ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE ((ULONG)0x00001702L)

//
// MessageId: ERROR_CLUSTER_QUORUMLOG_NOT_FOUND
//
// MessageText:
//
// The quorum resource does not contain the quorum log.
//
#define ERROR_CLUSTER_QUORUMLOG_NOT_FOUND ((ULONG)0x00001703L)

//
// MessageId: ERROR_CLUSTER_MEMBERSHIP_HALT
//
// MessageText:
//
// The membership engine requested shutdown of the cluster service on this node.
//
#define ERROR_CLUSTER_MEMBERSHIP_HALT    ((ULONG)0x00001704L)

//
// MessageId: ERROR_CLUSTER_INSTANCE_ID_MISMATCH
//
// MessageText:
//
// The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.
//
#define ERROR_CLUSTER_INSTANCE_ID_MISMATCH ((ULONG)0x00001705L)

//
// MessageId: ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP
//
// MessageText:
//
// A matching network for the specified IP address could not be found. Please also specify a subnet mask and a cluster network.
//
#define ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP ((ULONG)0x00001706L)

//
// MessageId: ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH
//
// MessageText:
//
// The actual data type of the property did not match the expected data type of the property.
//
#define ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH ((ULONG)0x00001707L)

//
// MessageId: ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP
//
// MessageText:
//
// The cluster node was evicted from the cluster successfully, but the node was not cleaned up. Extended status information explaining why the node was not cleaned up is available.
//
#define ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP ((ULONG)0x00001708L)

//
// MessageId: ERROR_CLUSTER_PARAMETER_MISMATCH
//
// MessageText:
//
// Two or more parameter values specified for a resource's properties are in conflict.
//
#define ERROR_CLUSTER_PARAMETER_MISMATCH ((ULONG)0x00001709L)

//
// MessageId: ERROR_NODE_CANNOT_BE_CLUSTERED
//
// MessageText:
//
// This computer cannot be made a member of a cluster.
//
#define ERROR_NODE_CANNOT_BE_CLUSTERED   ((ULONG)0x0000170AL)

//
// MessageId: ERROR_CLUSTER_WRONG_OS_VERSION
//
// MessageText:
//
// This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.
//
#define ERROR_CLUSTER_WRONG_OS_VERSION   ((ULONG)0x0000170BL)

//
// MessageId: ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME
//
// MessageText:
//
// A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.
//
#define ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME ((ULONG)0x0000170CL)

//
// MessageId: ERROR_CLUSCFG_ALREADY_COMMITTED
//
// MessageText:
//
// The cluster configuration action has already been committed.
//
#define ERROR_CLUSCFG_ALREADY_COMMITTED  ((ULONG)0x0000170DL)

//
// MessageId: ERROR_CLUSCFG_ROLLBACK_FAILED
//
// MessageText:
//
// The cluster configuration action could not be rolled back.
//
#define ERROR_CLUSCFG_ROLLBACK_FAILED    ((ULONG)0x0000170EL)

//
// MessageId: ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT
//
// MessageText:
//
// The drive letter assigned to a system disk on one node conflicted with the driver letter assigned to a disk on another node.
//
#define ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT ((ULONG)0x0000170FL)

//
// MessageId: ERROR_CLUSTER_OLD_VERSION
//
// MessageText:
//
// One or more nodes in the cluster are running a version of Windows that does not support this operation.
//
#define ERROR_CLUSTER_OLD_VERSION        ((ULONG)0x00001710L)

//
// MessageId: ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME
//
// MessageText:
//
// The name of the corresponding computer account doesn't match the Network Name for this resource.
//
#define ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME ((ULONG)0x00001711L)

//
// MessageId: ERROR_CLUSTER_NO_NET_ADAPTERS
//
// MessageText:
//
// No network adapters are available.
//
#define ERROR_CLUSTER_NO_NET_ADAPTERS    ((ULONG)0x00001712L)

//
// MessageId: ERROR_CLUSTER_POISONED
//
// MessageText:
//
// The cluster node has been poisoned.
//
#define ERROR_CLUSTER_POISONED           ((ULONG)0x00001713L)

//
// MessageId: ERROR_ENCRYPTION_FAILED
//
// MessageText:
//
// The specified file could not be encrypted.
//
#define ERROR_ENCRYPTION_FAILED          ((ULONG)0x00001770L)

//
// MessageId: ERROR_DECRYPTION_FAILED
//
// MessageText:
//
// The specified file could not be decrypted.
//
#define ERROR_DECRYPTION_FAILED          ((ULONG)0x00001771L)

//
// MessageId: ERROR_FILE_ENCRYPTED
//
// MessageText:
//
// The specified file is encrypted and the user does not have the ability to decrypt it.
//
#define ERROR_FILE_ENCRYPTED             ((ULONG)0x00001772L)

//
// MessageId: ERROR_NO_RECOVERY_POLICY
//
// MessageText:
//
// There is no valid encryption recovery policy configured for this system.
//
#define ERROR_NO_RECOVERY_POLICY         ((ULONG)0x00001773L)

//
// MessageId: ERROR_NO_EFS
//
// MessageText:
//
// The required encryption driver is not loaded for this system.
//
#define ERROR_NO_EFS                     ((ULONG)0x00001774L)

//
// MessageId: ERROR_WRONG_EFS
//
// MessageText:
//
// The file was encrypted with a different encryption driver than is currently loaded.
//
#define ERROR_WRONG_EFS                  ((ULONG)0x00001775L)

//
// MessageId: ERROR_NO_USER_KEYS
//
// MessageText:
//
// There are no EFS keys defined for the user.
//
#define ERROR_NO_USER_KEYS               ((ULONG)0x00001776L)

//
// MessageId: ERROR_FILE_NOT_ENCRYPTED
//
// MessageText:
//
// The specified file is not encrypted.
//
#define ERROR_FILE_NOT_ENCRYPTED         ((ULONG)0x00001777L)

//
// MessageId: ERROR_NOT_EXPORT_FORMAT
//
// MessageText:
//
// The specified file is not in the defined EFS export format.
//
#define ERROR_NOT_EXPORT_FORMAT          ((ULONG)0x00001778L)

//
// MessageId: ERROR_FILE_READ_ONLY
//
// MessageText:
//
// The specified file is read-only.
//
#define ERROR_FILE_READ_ONLY             ((ULONG)0x00001779L)

//
// MessageId: ERROR_DIR_EFS_DISALLOWED
//
// MessageText:
//
// The directory has been disabled for encryption.
//
#define ERROR_DIR_EFS_DISALLOWED         ((ULONG)0x0000177AL)

//
// MessageId: ERROR_EFS_SERVER_NOT_TRUSTED
//
// MessageText:
//
// The server is not trusted for remote encryption operation.
//
#define ERROR_EFS_SERVER_NOT_TRUSTED     ((ULONG)0x0000177BL)

//
// MessageId: ERROR_BAD_RECOVERY_POLICY
//
// MessageText:
//
// Recovery policy configured for this system contains invalid recovery certificate.
//
#define ERROR_BAD_RECOVERY_POLICY        ((ULONG)0x0000177CL)

//
// MessageId: ERROR_EFS_ALG_BLOB_TOO_BIG
//
// MessageText:
//
// The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.
//
#define ERROR_EFS_ALG_BLOB_TOO_BIG       ((ULONG)0x0000177DL)

//
// MessageId: ERROR_VOLUME_NOT_SUPPORT_EFS
//
// MessageText:
//
// The disk partition does not support file encryption.
//
#define ERROR_VOLUME_NOT_SUPPORT_EFS     ((ULONG)0x0000177EL)

//
// MessageId: ERROR_EFS_DISABLED
//
// MessageText:
//
// This machine is disabled for file encryption.
//
#define ERROR_EFS_DISABLED               ((ULONG)0x0000177FL)

//
// MessageId: ERROR_EFS_VERSION_NOT_SUPPORT
//
// MessageText:
//
// A newer system is required to decrypt this encrypted file.
//
#define ERROR_EFS_VERSION_NOT_SUPPORT    ((ULONG)0x00001780L)

//
// MessageId: ERROR_NO_BROWSER_SERVERS_FOUND
//
// MessageText:
//
// The list of servers for this workgroup is not currently available.
//
#define ERROR_NO_BROWSER_SERVERS_FOUND   ((ULONG)0x000017E6L)

//
// MessageId: SCHED_E_SERVICE_NOT_LOCALSYSTEM
//
// MessageText:
//
// The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.
//
#define SCHED_E_SERVICE_NOT_LOCALSYSTEM  ((ULONG)0x00001838L)

//
// MessageId: ERROR_CTX_WINSTATION_NAME_INVALID
//
// MessageText:
//
// The specified session name is invalid.
//
#define ERROR_CTX_WINSTATION_NAME_INVALID ((ULONG)0x00001B59L)

//
// MessageId: ERROR_CTX_INVALID_PD
//
// MessageText:
//
// The specified protocol driver is invalid.
//
#define ERROR_CTX_INVALID_PD             ((ULONG)0x00001B5AL)

//
// MessageId: ERROR_CTX_PD_NOT_FOUND
//
// MessageText:
//
// The specified protocol driver was not found in the system path.
//
#define ERROR_CTX_PD_NOT_FOUND           ((ULONG)0x00001B5BL)

//
// MessageId: ERROR_CTX_WD_NOT_FOUND
//
// MessageText:
//
// The specified terminal connection driver was not found in the system path.
//
#define ERROR_CTX_WD_NOT_FOUND           ((ULONG)0x00001B5CL)

//
// MessageId: ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY
//
// MessageText:
//
// A registry key for event logging could not be created for this session.
//
#define ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY ((ULONG)0x00001B5DL)

//
// MessageId: ERROR_CTX_SERVICE_NAME_COLLISION
//
// MessageText:
//
// A service with the same name already exists on the system.
//
#define ERROR_CTX_SERVICE_NAME_COLLISION ((ULONG)0x00001B5EL)

//
// MessageId: ERROR_CTX_CLOSE_PENDING
//
// MessageText:
//
// A close operation is pending on the session.
//
#define ERROR_CTX_CLOSE_PENDING          ((ULONG)0x00001B5FL)

//
// MessageId: ERROR_CTX_NO_OUTBUF
//
// MessageText:
//
// There are no free output buffers available.
//
#define ERROR_CTX_NO_OUTBUF              ((ULONG)0x00001B60L)

//
// MessageId: ERROR_CTX_MODEM_INF_NOT_FOUND
//
// MessageText:
//
// The MODEM.INF file was not found.
//
#define ERROR_CTX_MODEM_INF_NOT_FOUND    ((ULONG)0x00001B61L)

//
// MessageId: ERROR_CTX_INVALID_MODEMNAME
//
// MessageText:
//
// The modem name was not found in MODEM.INF.
//
#define ERROR_CTX_INVALID_MODEMNAME      ((ULONG)0x00001B62L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_ERROR
//
// MessageText:
//
// The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.
//
#define ERROR_CTX_MODEM_RESPONSE_ERROR   ((ULONG)0x00001B63L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_TIMEOUT
//
// MessageText:
//
// The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.
//
#define ERROR_CTX_MODEM_RESPONSE_TIMEOUT ((ULONG)0x00001B64L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_NO_CARRIER
//
// MessageText:
//
// Carrier detect has failed or carrier has been dropped due to disconnect.
//
#define ERROR_CTX_MODEM_RESPONSE_NO_CARRIER ((ULONG)0x00001B65L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE
//
// MessageText:
//
// Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.
//
#define ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE ((ULONG)0x00001B66L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_BUSY
//
// MessageText:
//
// Busy signal detected at remote site on callback.
//
#define ERROR_CTX_MODEM_RESPONSE_BUSY    ((ULONG)0x00001B67L)

//
// MessageId: ERROR_CTX_MODEM_RESPONSE_VOICE
//
// MessageText:
//
// Voice detected at remote site on callback.
//
#define ERROR_CTX_MODEM_RESPONSE_VOICE   ((ULONG)0x00001B68L)

//
// MessageId: ERROR_CTX_TD_ERROR
//
// MessageText:
//
// Transport driver error
//
#define ERROR_CTX_TD_ERROR               ((ULONG)0x00001B69L)

//
// MessageId: ERROR_CTX_WINSTATION_NOT_FOUND
//
// MessageText:
//
// The specified session cannot be found.
//
#define ERROR_CTX_WINSTATION_NOT_FOUND   ((ULONG)0x00001B6EL)

//
// MessageId: ERROR_CTX_WINSTATION_ALREADY_EXISTS
//
// MessageText:
//
// The specified session name is already in use.
//
#define ERROR_CTX_WINSTATION_ALREADY_EXISTS ((ULONG)0x00001B6FL)

//
// MessageId: ERROR_CTX_WINSTATION_BUSY
//
// MessageText:
//
// The requested operation cannot be completed because the terminal connection is currently busy processing a connect, disconnect, reset, or delete operation.
//
#define ERROR_CTX_WINSTATION_BUSY        ((ULONG)0x00001B70L)

//
// MessageId: ERROR_CTX_BAD_VIDEO_MODE
//
// MessageText:
//
// An attempt has been made to connect to a session whose video mode is not supported by the current client.
//
#define ERROR_CTX_BAD_VIDEO_MODE         ((ULONG)0x00001B71L)

//
// MessageId: ERROR_CTX_GRAPHICS_INVALID
//
// MessageText:
//
// The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.
//
#define ERROR_CTX_GRAPHICS_INVALID       ((ULONG)0x00001B7BL)

//
// MessageId: ERROR_CTX_LOGON_DISABLED
//
// MessageText:
//
// Your interactive logon privilege has been disabled. Please contact your administrator.
//
#define ERROR_CTX_LOGON_DISABLED         ((ULONG)0x00001B7DL)

//
// MessageId: ERROR_CTX_NOT_CONSOLE
//
// MessageText:
//
// The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.
//
#define ERROR_CTX_NOT_CONSOLE            ((ULONG)0x00001B7EL)

//
// MessageId: ERROR_CTX_CLIENT_QUERY_TIMEOUT
//
// MessageText:
//
// The client failed to respond to the server connect message.
//
#define ERROR_CTX_CLIENT_QUERY_TIMEOUT   ((ULONG)0x00001B80L)

//
// MessageId: ERROR_CTX_CONSOLE_DISCONNECT
//
// MessageText:
//
// Disconnecting the console session is not supported.
//
#define ERROR_CTX_CONSOLE_DISCONNECT     ((ULONG)0x00001B81L)

//
// MessageId: ERROR_CTX_CONSOLE_CONNECT
//
// MessageText:
//
// Reconnecting a disconnected session to the console is not supported.
//
#define ERROR_CTX_CONSOLE_CONNECT        ((ULONG)0x00001B82L)

//
// MessageId: ERROR_CTX_SHADOW_DENIED
//
// MessageText:
//
// The request to control another session remotely was denied.
//
#define ERROR_CTX_SHADOW_DENIED          ((ULONG)0x00001B84L)

//
// MessageId: ERROR_CTX_WINSTATION_ACCESS_DENIED
//
// MessageText:
//
// The requested session access is denied.
//
#define ERROR_CTX_WINSTATION_ACCESS_DENIED ((ULONG)0x00001B85L)

//
// MessageId: ERROR_CTX_INVALID_WD
//
// MessageText:
//
// The specified terminal connection driver is invalid.
//
#define ERROR_CTX_INVALID_WD             ((ULONG)0x00001B89L)

//
// MessageId: ERROR_CTX_SHADOW_INVALID
//
// MessageText:
//
// The requested session cannot be controlled remotely. This may be because the session is disconnected or does not currently have a user logged on.
//
#define ERROR_CTX_SHADOW_INVALID         ((ULONG)0x00001B8AL)

//
// MessageId: ERROR_CTX_SHADOW_DISABLED
//
// MessageText:
//
// The requested session is not configured to allow remote control.
//
#define ERROR_CTX_SHADOW_DISABLED        ((ULONG)0x00001B8BL)

//
// MessageId: ERROR_CTX_CLIENT_LICENSE_IN_USE
//
// MessageText:
//
// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.
//
#define ERROR_CTX_CLIENT_LICENSE_IN_USE  ((ULONG)0x00001B8CL)

//
// MessageId: ERROR_CTX_CLIENT_LICENSE_NOT_SET
//
// MessageText:
//
// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.
//
#define ERROR_CTX_CLIENT_LICENSE_NOT_SET ((ULONG)0x00001B8DL)

//
// MessageId: ERROR_CTX_LICENSE_NOT_AVAILABLE
//
// MessageText:
//
// The system has reached its licensed logon limit. Please try again later.
//
#define ERROR_CTX_LICENSE_NOT_AVAILABLE  ((ULONG)0x00001B8EL)

//
// MessageId: ERROR_CTX_LICENSE_CLIENT_INVALID
//
// MessageText:
//
// The client you are using is not licensed to use this system. Your logon request is denied.
//
#define ERROR_CTX_LICENSE_CLIENT_INVALID ((ULONG)0x00001B8FL)

//
// MessageId: ERROR_CTX_LICENSE_EXPIRED
//
// MessageText:
//
// The system license has expired. Your logon request is denied.
//
#define ERROR_CTX_LICENSE_EXPIRED        ((ULONG)0x00001B90L)

//
// MessageId: ERROR_CTX_SHADOW_NOT_RUNNING
//
// MessageText:
//
// Remote control could not be terminated because the specified session is not currently being remotely controlled.
//
#define ERROR_CTX_SHADOW_NOT_RUNNING     ((ULONG)0x00001B91L)

//
// MessageId: ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE
//
// MessageText:
//
// The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.
//
#define ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE ((ULONG)0x00001B92L)

//
// MessageId: ERROR_ACTIVATION_COUNT_EXCEEDED
//
// MessageText:
//
// Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.
//
#define ERROR_ACTIVATION_COUNT_EXCEEDED  ((ULONG)0x00001B93L)

//
// MessageId: ERROR_CTX_WINSTATIONS_DISABLED
//
// MessageText:
//
// Remote logins are currently disabled.
//
#define ERROR_CTX_WINSTATIONS_DISABLED   ((ULONG)0x00001B94L)

//
// MessageId: ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED
//
// MessageText:
//
// You do not have the proper encryption level to access this Session.
//
#define ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED ((ULONG)0x00001B95L)

//
// MessageId: ERROR_CTX_SESSION_IN_USE
//
// MessageText:
//
// The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.
//
#define ERROR_CTX_SESSION_IN_USE         ((ULONG)0x00001B96L)

//
// MessageId: ERROR_CTX_NO_FORCE_LOGOFF
//
// MessageText:
//
// The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.
//
#define ERROR_CTX_NO_FORCE_LOGOFF        ((ULONG)0x00001B97L)

//
// MessageId: ERROR_CTX_ACCOUNT_RESTRICTION
//
// MessageText:
//
// Unable to log you on because of an account restriction.
//
#define ERROR_CTX_ACCOUNT_RESTRICTION    ((ULONG)0x00001B98L)

//
// MessageId: ERROR_RDP_PROTOCOL_ERROR
//
// MessageText:
//
// The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.
//
#define ERROR_RDP_PROTOCOL_ERROR         ((ULONG)0x00001B99L)

//
// MessageId: ERROR_CTX_CDM_CONNECT
//
// MessageText:
//
// The Client Drive Mapping Service Has Connected on Terminal Connection.
//
#define ERROR_CTX_CDM_CONNECT            ((ULONG)0x00001B9AL)

//
// MessageId: ERROR_CTX_CDM_DISCONNECT
//
// MessageText:
//
// The Client Drive Mapping Service Has Disconnected on Terminal Connection.
//
#define ERROR_CTX_CDM_DISCONNECT         ((ULONG)0x00001B9BL)

//
// MessageId: FRS_ERR_INVALID_API_SEQUENCE
//
// MessageText:
//
// The file replication service API was called incorrectly.
//
#define FRS_ERR_INVALID_API_SEQUENCE     ((ULONG)0x00001F41L)

//
// MessageId: FRS_ERR_STARTING_SERVICE
//
// MessageText:
//
// The file replication service cannot be started.
//
#define FRS_ERR_STARTING_SERVICE         ((ULONG)0x00001F42L)

//
// MessageId: FRS_ERR_STOPPING_SERVICE
//
// MessageText:
//
// The file replication service cannot be stopped.
//
#define FRS_ERR_STOPPING_SERVICE         ((ULONG)0x00001F43L)

//
// MessageId: FRS_ERR_INTERNAL_API
//
// MessageText:
//
// The file replication service API terminated the request. The event log may have more information.
//
#define FRS_ERR_INTERNAL_API             ((ULONG)0x00001F44L)

//
// MessageId: FRS_ERR_INTERNAL
//
// MessageText:
//
// The file replication service terminated the request. The event log may have more information.
//
#define FRS_ERR_INTERNAL                 ((ULONG)0x00001F45L)

//
// MessageId: FRS_ERR_SERVICE_COMM
//
// MessageText:
//
// The file replication service cannot be contacted. The event log may have more information.
//
#define FRS_ERR_SERVICE_COMM             ((ULONG)0x00001F46L)

//
// MessageId: FRS_ERR_INSUFFICIENT_PRIV
//
// MessageText:
//
// The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information.
//
#define FRS_ERR_INSUFFICIENT_PRIV        ((ULONG)0x00001F47L)

//
// MessageId: FRS_ERR_AUTHENTICATION
//
// MessageText:
//
// The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information.
//
#define FRS_ERR_AUTHENTICATION           ((ULONG)0x00001F48L)

//
// MessageId: FRS_ERR_PARENT_INSUFFICIENT_PRIV
//
// MessageText:
//
// The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information.
//
#define FRS_ERR_PARENT_INSUFFICIENT_PRIV ((ULONG)0x00001F49L)

//
// MessageId: FRS_ERR_PARENT_AUTHENTICATION
//
// MessageText:
//
// The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information.
//
#define FRS_ERR_PARENT_AUTHENTICATION    ((ULONG)0x00001F4AL)

//
// MessageId: FRS_ERR_CHILD_TO_PARENT_COMM
//
// MessageText:
//
// The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information.
//
#define FRS_ERR_CHILD_TO_PARENT_COMM     ((ULONG)0x00001F4BL)

//
// MessageId: FRS_ERR_PARENT_TO_CHILD_COMM
//
// MessageText:
//
// The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information.
//
#define FRS_ERR_PARENT_TO_CHILD_COMM     ((ULONG)0x00001F4CL)

//
// MessageId: FRS_ERR_SYSVOL_POPULATE
//
// MessageText:
//
// The file replication service cannot populate the system volume because of an internal error. The event log may have more information.
//
#define FRS_ERR_SYSVOL_POPULATE          ((ULONG)0x00001F4DL)

//
// MessageId: FRS_ERR_SYSVOL_POPULATE_TIMEOUT
//
// MessageText:
//
// The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information.
//
#define FRS_ERR_SYSVOL_POPULATE_TIMEOUT  ((ULONG)0x00001F4EL)

//
// MessageId: FRS_ERR_SYSVOL_IS_BUSY
//
// MessageText:
//
// The file replication service cannot process the request. The system volume is busy with a previous request.
//
#define FRS_ERR_SYSVOL_IS_BUSY           ((ULONG)0x00001F4FL)

//
// MessageId: FRS_ERR_SYSVOL_DEMOTE
//
// MessageText:
//
// The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information.
//
#define FRS_ERR_SYSVOL_DEMOTE            ((ULONG)0x00001F50L)

//
// MessageId: FRS_ERR_INVALID_SERVICE_PARAMETER
//
// MessageText:
//
// The file replication service detected an invalid parameter.
//
#define FRS_ERR_INVALID_SERVICE_PARAMETER ((ULONG)0x00001F51L)

//
// MessageId: ERROR_DS_NOT_INSTALLED
//
// MessageText:
//
// An error occurred while installing the directory service. For more information, see the event log.
//
#define ERROR_DS_NOT_INSTALLED           ((ULONG)0x00002008L)

//
// MessageId: ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY
//
// MessageText:
//
// The directory service evaluated group memberships locally.
//
#define ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY ((ULONG)0x00002009L)

//
// MessageId: ERROR_DS_NO_ATTRIBUTE_OR_VALUE
//
// MessageText:
//
// The specified directory service attribute or value does not exist.
//
#define ERROR_DS_NO_ATTRIBUTE_OR_VALUE   ((ULONG)0x0000200AL)

//
// MessageId: ERROR_DS_INVALID_ATTRIBUTE_SYNTAX
//
// MessageText:
//
// The attribute syntax specified to the directory service is invalid.
//
#define ERROR_DS_INVALID_ATTRIBUTE_SYNTAX ((ULONG)0x0000200BL)

//
// MessageId: ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED
//
// MessageText:
//
// The attribute type specified to the directory service is not defined.
//
#define ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED ((ULONG)0x0000200CL)

//
// MessageId: ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS
//
// MessageText:
//
// The specified directory service attribute or value already exists.
//
#define ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS ((ULONG)0x0000200DL)

//
// MessageId: ERROR_DS_BUSY
//
// MessageText:
//
// The directory service is busy.
//
#define ERROR_DS_BUSY                    ((ULONG)0x0000200EL)

//
// MessageId: ERROR_DS_UNAVAILABLE
//
// MessageText:
//
// The directory service is unavailable.
//
#define ERROR_DS_UNAVAILABLE             ((ULONG)0x0000200FL)

//
// MessageId: ERROR_DS_NO_RIDS_ALLOCATED
//
// MessageText:
//
// The directory service was unable to allocate a relative identifier.
//
#define ERROR_DS_NO_RIDS_ALLOCATED       ((ULONG)0x00002010L)

//
// MessageId: ERROR_DS_NO_MORE_RIDS
//
// MessageText:
//
// The directory service has exhausted the pool of relative identifiers.
//
#define ERROR_DS_NO_MORE_RIDS            ((ULONG)0x00002011L)

//
// MessageId: ERROR_DS_INCORRECT_ROLE_OWNER
//
// MessageText:
//
// The requested operation could not be performed because the directory service is not the master for that type of operation.
//
#define ERROR_DS_INCORRECT_ROLE_OWNER    ((ULONG)0x00002012L)

//
// MessageId: ERROR_DS_RIDMGR_INIT_ERROR
//
// MessageText:
//
// The directory service was unable to initialize the subsystem that allocates relative identifiers.
//
#define ERROR_DS_RIDMGR_INIT_ERROR       ((ULONG)0x00002013L)

//
// MessageId: ERROR_DS_OBJ_CLASS_VIOLATION
//
// MessageText:
//
// The requested operation did not satisfy one or more constraints associated with the class of the object.
//
#define ERROR_DS_OBJ_CLASS_VIOLATION     ((ULONG)0x00002014L)

//
// MessageId: ERROR_DS_CANT_ON_NON_LEAF
//
// MessageText:
//
// The directory service can perform the requested operation only on a leaf object.
//
#define ERROR_DS_CANT_ON_NON_LEAF        ((ULONG)0x00002015L)

//
// MessageId: ERROR_DS_CANT_ON_RDN
//
// MessageText:
//
// The directory service cannot perform the requested operation on the RDN attribute of an object.
//
#define ERROR_DS_CANT_ON_RDN             ((ULONG)0x00002016L)

//
// MessageId: ERROR_DS_CANT_MOD_OBJ_CLASS
//
// MessageText:
//
// The directory service detected an attempt to modify the object class of an object.
//
#define ERROR_DS_CANT_MOD_OBJ_CLASS      ((ULONG)0x00002017L)

//
// MessageId: ERROR_DS_CROSS_DOM_MOVE_ERROR
//
// MessageText:
//
// The requested cross-domain move operation could not be performed.
//
#define ERROR_DS_CROSS_DOM_MOVE_ERROR    ((ULONG)0x00002018L)

//
// MessageId: ERROR_DS_GC_NOT_AVAILABLE
//
// MessageText:
//
// Unable to contact the global catalog server.
//
#define ERROR_DS_GC_NOT_AVAILABLE        ((ULONG)0x00002019L)

//
// MessageId: ERROR_SHARED_POLICY
//
// MessageText:
//
// The policy object is shared and can only be modified at the root.
//
#define ERROR_SHARED_POLICY              ((ULONG)0x0000201AL)

//
// MessageId: ERROR_POLICY_OBJECT_NOT_FOUND
//
// MessageText:
//
// The policy object does not exist.
//
#define ERROR_POLICY_OBJECT_NOT_FOUND    ((ULONG)0x0000201BL)

//
// MessageId: ERROR_POLICY_ONLY_IN_DS
//
// MessageText:
//
// The requested policy information is only in the directory service.
//
#define ERROR_POLICY_ONLY_IN_DS          ((ULONG)0x0000201CL)

//
// MessageId: ERROR_PROMOTION_ACTIVE
//
// MessageText:
//
// A domain controller promotion is currently active.
//
#define ERROR_PROMOTION_ACTIVE           ((ULONG)0x0000201DL)

//
// MessageId: ERROR_NO_PROMOTION_ACTIVE
//
// MessageText:
//
// A domain controller promotion is not currently active
//
#define ERROR_NO_PROMOTION_ACTIVE        ((ULONG)0x0000201EL)

//
// MessageId: ERROR_DS_OPERATIONS_ERROR
//
// MessageText:
//
// An operations error occurred.
//
#define ERROR_DS_OPERATIONS_ERROR        ((ULONG)0x00002020L)

//
// MessageId: ERROR_DS_PROTOCOL_ERROR
//
// MessageText:
//
// A protocol error occurred.
//
#define ERROR_DS_PROTOCOL_ERROR          ((ULONG)0x00002021L)

//
// MessageId: ERROR_DS_TIMELIMIT_EXCEEDED
//
// MessageText:
//
// The time limit for this request was exceeded.
//
#define ERROR_DS_TIMELIMIT_EXCEEDED      ((ULONG)0x00002022L)

//
// MessageId: ERROR_DS_SIZELIMIT_EXCEEDED
//
// MessageText:
//
// The size limit for this request was exceeded.
//
#define ERROR_DS_SIZELIMIT_EXCEEDED      ((ULONG)0x00002023L)

//
// MessageId: ERROR_DS_ADMIN_LIMIT_EXCEEDED
//
// MessageText:
//
// The administrative limit for this request was exceeded.
//
#define ERROR_DS_ADMIN_LIMIT_EXCEEDED    ((ULONG)0x00002024L)

//
// MessageId: ERROR_DS_COMPARE_FALSE
//
// MessageText:
//
// The compare response was false.
//
#define ERROR_DS_COMPARE_FALSE           ((ULONG)0x00002025L)

//
// MessageId: ERROR_DS_COMPARE_TRUE
//
// MessageText:
//
// The compare response was true.
//
#define ERROR_DS_COMPARE_TRUE            ((ULONG)0x00002026L)

//
// MessageId: ERROR_DS_AUTH_METHOD_NOT_SUPPORTED
//
// MessageText:
//
// The requested authentication method is not supported by the server.
//
#define ERROR_DS_AUTH_METHOD_NOT_SUPPORTED ((ULONG)0x00002027L)

//
// MessageId: ERROR_DS_STRONG_AUTH_REQUIRED
//
// MessageText:
//
// A more secure authentication method is required for this server.
//
#define ERROR_DS_STRONG_AUTH_REQUIRED    ((ULONG)0x00002028L)

//
// MessageId: ERROR_DS_INAPPROPRIATE_AUTH
//
// MessageText:
//
// Inappropriate authentication.
//
#define ERROR_DS_INAPPROPRIATE_AUTH      ((ULONG)0x00002029L)

//
// MessageId: ERROR_DS_AUTH_UNKNOWN
//
// MessageText:
//
// The authentication mechanism is unknown.
//
#define ERROR_DS_AUTH_UNKNOWN            ((ULONG)0x0000202AL)

//
// MessageId: ERROR_DS_REFERRAL
//
// MessageText:
//
// A referral was returned from the server.
//
#define ERROR_DS_REFERRAL                ((ULONG)0x0000202BL)

//
// MessageId: ERROR_DS_UNAVAILABLE_CRIT_EXTENSION
//
// MessageText:
//
// The server does not support the requested critical extension.
//
#define ERROR_DS_UNAVAILABLE_CRIT_EXTENSION ((ULONG)0x0000202CL)

//
// MessageId: ERROR_DS_CONFIDENTIALITY_REQUIRED
//
// MessageText:
//
// This request requires a secure connection.
//
#define ERROR_DS_CONFIDENTIALITY_REQUIRED ((ULONG)0x0000202DL)

//
// MessageId: ERROR_DS_INAPPROPRIATE_MATCHING
//
// MessageText:
//
// Inappropriate matching.
//
#define ERROR_DS_INAPPROPRIATE_MATCHING  ((ULONG)0x0000202EL)

//
// MessageId: ERROR_DS_CONSTRAINT_VIOLATION
//
// MessageText:
//
// A constraint violation occurred.
//
#define ERROR_DS_CONSTRAINT_VIOLATION    ((ULONG)0x0000202FL)

//
// MessageId: ERROR_DS_NO_SUCH_OBJECT
//
// MessageText:
//
// There is no such object on the server.
//
#define ERROR_DS_NO_SUCH_OBJECT          ((ULONG)0x00002030L)

//
// MessageId: ERROR_DS_ALIAS_PROBLEM
//
// MessageText:
//
// There is an alias problem.
//
#define ERROR_DS_ALIAS_PROBLEM           ((ULONG)0x00002031L)

//
// MessageId: ERROR_DS_INVALID_DN_SYNTAX
//
// MessageText:
//
// An invalid dn syntax has been specified.
//
#define ERROR_DS_INVALID_DN_SYNTAX       ((ULONG)0x00002032L)

//
// MessageId: ERROR_DS_IS_LEAF
//
// MessageText:
//
// The object is a leaf object.
//
#define ERROR_DS_IS_LEAF                 ((ULONG)0x00002033L)

//
// MessageId: ERROR_DS_ALIAS_DEREF_PROBLEM
//
// MessageText:
//
// There is an alias dereferencing problem.
//
#define ERROR_DS_ALIAS_DEREF_PROBLEM     ((ULONG)0x00002034L)

//
// MessageId: ERROR_DS_UNWILLING_TO_PERFORM
//
// MessageText:
//
// The server is unwilling to process the request.
//
#define ERROR_DS_UNWILLING_TO_PERFORM    ((ULONG)0x00002035L)

//
// MessageId: ERROR_DS_LOOP_DETECT
//
// MessageText:
//
// A loop has been detected.
//
#define ERROR_DS_LOOP_DETECT             ((ULONG)0x00002036L)

//
// MessageId: ERROR_DS_NAMING_VIOLATION
//
// MessageText:
//
// There is a naming violation.
//
#define ERROR_DS_NAMING_VIOLATION        ((ULONG)0x00002037L)

//
// MessageId: ERROR_DS_OBJECT_RESULTS_TOO_LARGE
//
// MessageText:
//
// The result set is too large.
//
#define ERROR_DS_OBJECT_RESULTS_TOO_LARGE ((ULONG)0x00002038L)

//
// MessageId: ERROR_DS_AFFECTS_MULTIPLE_DSAS
//
// MessageText:
//
// The operation affects multiple DSAs
//
#define ERROR_DS_AFFECTS_MULTIPLE_DSAS   ((ULONG)0x00002039L)

//
// MessageId: ERROR_DS_SERVER_DOWN
//
// MessageText:
//
// The server is not operational.
//
#define ERROR_DS_SERVER_DOWN             ((ULONG)0x0000203AL)

//
// MessageId: ERROR_DS_LOCAL_ERROR
//
// MessageText:
//
// A local error has occurred.
//
#define ERROR_DS_LOCAL_ERROR             ((ULONG)0x0000203BL)

//
// MessageId: ERROR_DS_ENCODING_ERROR
//
// MessageText:
//
// An encoding error has occurred.
//
#define ERROR_DS_ENCODING_ERROR          ((ULONG)0x0000203CL)

//
// MessageId: ERROR_DS_DECODING_ERROR
//
// MessageText:
//
// A decoding error has occurred.
//
#define ERROR_DS_DECODING_ERROR          ((ULONG)0x0000203DL)

//
// MessageId: ERROR_DS_FILTER_UNKNOWN
//
// MessageText:
//
// The search filter cannot be recognized.
//
#define ERROR_DS_FILTER_UNKNOWN          ((ULONG)0x0000203EL)

//
// MessageId: ERROR_DS_PARAM_ERROR
//
// MessageText:
//
// One or more parameters are illegal.
//
#define ERROR_DS_PARAM_ERROR             ((ULONG)0x0000203FL)

//
// MessageId: ERROR_DS_NOT_SUPPORTED
//
// MessageText:
//
// The specified method is not supported.
//
#define ERROR_DS_NOT_SUPPORTED           ((ULONG)0x00002040L)

//
// MessageId: ERROR_DS_NO_RESULTS_RETURNED
//
// MessageText:
//
// No results were returned.
//
#define ERROR_DS_NO_RESULTS_RETURNED     ((ULONG)0x00002041L)

//
// MessageId: ERROR_DS_CONTROL_NOT_FOUND
//
// MessageText:
//
// The specified control is not supported by the server.
//
#define ERROR_DS_CONTROL_NOT_FOUND       ((ULONG)0x00002042L)

//
// MessageId: ERROR_DS_CLIENT_LOOP
//
// MessageText:
//
// A referral loop was detected by the client.
//
#define ERROR_DS_CLIENT_LOOP             ((ULONG)0x00002043L)

//
// MessageId: ERROR_DS_REFERRAL_LIMIT_EXCEEDED
//
// MessageText:
//
// The preset referral limit was exceeded.
//
#define ERROR_DS_REFERRAL_LIMIT_EXCEEDED ((ULONG)0x00002044L)

//
// MessageId: ERROR_DS_SORT_CONTROL_MISSING
//
// MessageText:
//
// The search requires a SORT control.
//
#define ERROR_DS_SORT_CONTROL_MISSING    ((ULONG)0x00002045L)

//
// MessageId: ERROR_DS_OFFSET_RANGE_ERROR
//
// MessageText:
//
// The search results exceed the offset range specified.
//
#define ERROR_DS_OFFSET_RANGE_ERROR      ((ULONG)0x00002046L)

//
// MessageId: ERROR_DS_ROOT_MUST_BE_NC
//
// MessageText:
//
// The root object must be the head of a naming context. The root object cannot have an instantiated parent.
//
#define ERROR_DS_ROOT_MUST_BE_NC         ((ULONG)0x0000206DL)

//
// MessageId: ERROR_DS_ADD_REPLICA_INHIBITED
//
// MessageText:
//
// The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.
//
#define ERROR_DS_ADD_REPLICA_INHIBITED   ((ULONG)0x0000206EL)

//
// MessageId: ERROR_DS_ATT_NOT_DEF_IN_SCHEMA
//
// MessageText:
//
// A reference to an attribute that is not defined in the schema occurred.
//
#define ERROR_DS_ATT_NOT_DEF_IN_SCHEMA   ((ULONG)0x0000206FL)

//
// MessageId: ERROR_DS_MAX_OBJ_SIZE_EXCEEDED
//
// MessageText:
//
// The maximum size of an object has been exceeded.
//
#define ERROR_DS_MAX_OBJ_SIZE_EXCEEDED   ((ULONG)0x00002070L)

//
// MessageId: ERROR_DS_OBJ_STRING_NAME_EXISTS
//
// MessageText:
//
// An attempt was made to add an object to the directory with a name that is already in use.
//
#define ERROR_DS_OBJ_STRING_NAME_EXISTS  ((ULONG)0x00002071L)

//
// MessageId: ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA
//
// MessageText:
//
// An attempt was made to add an object of a class that does not have an RDN defined in the schema.
//
#define ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA ((ULONG)0x00002072L)

//
// MessageId: ERROR_DS_RDN_DOESNT_MATCH_SCHEMA
//
// MessageText:
//
// An attempt was made to add an object using an RDN that is not the RDN defined in the schema.
//
#define ERROR_DS_RDN_DOESNT_MATCH_SCHEMA ((ULONG)0x00002073L)

//
// MessageId: ERROR_DS_NO_REQUESTED_ATTS_FOUND
//
// MessageText:
//
// None of the requested attributes were found on the objects.
//
#define ERROR_DS_NO_REQUESTED_ATTS_FOUND ((ULONG)0x00002074L)

//
// MessageId: ERROR_DS_USER_BUFFER_TO_SMALL
//
// MessageText:
//
// The user buffer is too small.
//
#define ERROR_DS_USER_BUFFER_TO_SMALL    ((ULONG)0x00002075L)

//
// MessageId: ERROR_DS_ATT_IS_NOT_ON_OBJ
//
// MessageText:
//
// The attribute specified in the operation is not present on the object.
//
#define ERROR_DS_ATT_IS_NOT_ON_OBJ       ((ULONG)0x00002076L)

//
// MessageId: ERROR_DS_ILLEGAL_MOD_OPERATION
//
// MessageText:
//
// Illegal modify operation. Some aspect of the modification is not permitted.
//
#define ERROR_DS_ILLEGAL_MOD_OPERATION   ((ULONG)0x00002077L)

//
// MessageId: ERROR_DS_OBJ_TOO_LARGE
//
// MessageText:
//
// The specified object is too large.
//
#define ERROR_DS_OBJ_TOO_LARGE           ((ULONG)0x00002078L)

//
// MessageId: ERROR_DS_BAD_INSTANCE_TYPE
//
// MessageText:
//
// The specified instance type is not valid.
//
#define ERROR_DS_BAD_INSTANCE_TYPE       ((ULONG)0x00002079L)

//
// MessageId: ERROR_DS_MASTERDSA_REQUIRED
//
// MessageText:
//
// The operation must be performed at a master DSA.
//
#define ERROR_DS_MASTERDSA_REQUIRED      ((ULONG)0x0000207AL)

//
// MessageId: ERROR_DS_OBJECT_CLASS_REQUIRED
//
// MessageText:
//
// The object class attribute must be specified.
//
#define ERROR_DS_OBJECT_CLASS_REQUIRED   ((ULONG)0x0000207BL)

//
// MessageId: ERROR_DS_MISSING_REQUIRED_ATT
//
// MessageText:
//
// A required attribute is missing.
//
#define ERROR_DS_MISSING_REQUIRED_ATT    ((ULONG)0x0000207CL)

//
// MessageId: ERROR_DS_ATT_NOT_DEF_FOR_CLASS
//
// MessageText:
//
// An attempt was made to modify an object to include an attribute that is not legal for its class
//
#define ERROR_DS_ATT_NOT_DEF_FOR_CLASS   ((ULONG)0x0000207DL)

//
// MessageId: ERROR_DS_ATT_ALREADY_EXISTS
//
// MessageText:
//
// The specified attribute is already present on the object.
//
#define ERROR_DS_ATT_ALREADY_EXISTS      ((ULONG)0x0000207EL)

//
// MessageId: ERROR_DS_CANT_ADD_ATT_VALUES
//
// MessageText:
//
// The specified attribute is not present, or has no values.
//
#define ERROR_DS_CANT_ADD_ATT_VALUES     ((ULONG)0x00002080L)

//
// MessageId: ERROR_DS_SINGLE_VALUE_CONSTRAINT
//
// MessageText:
//
// Multiple values were specified for an attribute that can have only one value.
//
#define ERROR_DS_SINGLE_VALUE_CONSTRAINT ((ULONG)0x00002081L)

//
// MessageId: ERROR_DS_RANGE_CONSTRAINT
//
// MessageText:
//
// A value for the attribute was not in the acceptable range of values.
//
#define ERROR_DS_RANGE_CONSTRAINT        ((ULONG)0x00002082L)

//
// MessageId: ERROR_DS_ATT_VAL_ALREADY_EXISTS
//
// MessageText:
//
// The specified value already exists.
//
#define ERROR_DS_ATT_VAL_ALREADY_EXISTS  ((ULONG)0x00002083L)

//
// MessageId: ERROR_DS_CANT_REM_MISSING_ATT
//
// MessageText:
//
// The attribute cannot be removed because it is not present on the object.
//
#define ERROR_DS_CANT_REM_MISSING_ATT    ((ULONG)0x00002084L)

//
// MessageId: ERROR_DS_CANT_REM_MISSING_ATT_VAL
//
// MessageText:
//
// The attribute value cannot be removed because it is not present on the object.
//
#define ERROR_DS_CANT_REM_MISSING_ATT_VAL ((ULONG)0x00002085L)

//
// MessageId: ERROR_DS_ROOT_CANT_BE_SUBREF
//
// MessageText:
//
// The specified root object cannot be a subref.
//
#define ERROR_DS_ROOT_CANT_BE_SUBREF     ((ULONG)0x00002086L)

//
// MessageId: ERROR_DS_NO_CHAINING
//
// MessageText:
//
// Chaining is not permitted.
//
#define ERROR_DS_NO_CHAINING             ((ULONG)0x00002087L)

//
// MessageId: ERROR_DS_NO_CHAINED_EVAL
//
// MessageText:
//
// Chained evaluation is not permitted.
//
#define ERROR_DS_NO_CHAINED_EVAL         ((ULONG)0x00002088L)

//
// MessageId: ERROR_DS_NO_PARENT_OBJECT
//
// MessageText:
//
// The operation could not be performed because the object's parent is either uninstantiated or deleted.
//
#define ERROR_DS_NO_PARENT_OBJECT        ((ULONG)0x00002089L)

//
// MessageId: ERROR_DS_PARENT_IS_AN_ALIAS
//
// MessageText:
//
// Having a parent that is an alias is not permitted. Aliases are leaf objects.
//
#define ERROR_DS_PARENT_IS_AN_ALIAS      ((ULONG)0x0000208AL)

//
// MessageId: ERROR_DS_CANT_MIX_MASTER_AND_REPS
//
// MessageText:
//
// The object and parent must be of the same type, either both masters or both replicas.
//
#define ERROR_DS_CANT_MIX_MASTER_AND_REPS ((ULONG)0x0000208BL)

//
// MessageId: ERROR_DS_CHILDREN_EXIST
//
// MessageText:
//
// The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.
//
#define ERROR_DS_CHILDREN_EXIST          ((ULONG)0x0000208CL)

//
// MessageId: ERROR_DS_OBJ_NOT_FOUND
//
// MessageText:
//
// Directory object not found.
//
#define ERROR_DS_OBJ_NOT_FOUND           ((ULONG)0x0000208DL)

//
// MessageId: ERROR_DS_ALIASED_OBJ_MISSING
//
// MessageText:
//
// The aliased object is missing.
//
#define ERROR_DS_ALIASED_OBJ_MISSING     ((ULONG)0x0000208EL)

//
// MessageId: ERROR_DS_BAD_NAME_SYNTAX
//
// MessageText:
//
// The object name has bad syntax.
//
#define ERROR_DS_BAD_NAME_SYNTAX         ((ULONG)0x0000208FL)

//
// MessageId: ERROR_DS_ALIAS_POINTS_TO_ALIAS
//
// MessageText:
//
// It is not permitted for an alias to refer to another alias.
//
#define ERROR_DS_ALIAS_POINTS_TO_ALIAS   ((ULONG)0x00002090L)

//
// MessageId: ERROR_DS_CANT_DEREF_ALIAS
//
// MessageText:
//
// The alias cannot be dereferenced.
//
#define ERROR_DS_CANT_DEREF_ALIAS        ((ULONG)0x00002091L)

//
// MessageId: ERROR_DS_OUT_OF_SCOPE
//
// MessageText:
//
// The operation is out of scope.
//
#define ERROR_DS_OUT_OF_SCOPE            ((ULONG)0x00002092L)

//
// MessageId: ERROR_DS_OBJECT_BEING_REMOVED
//
// MessageText:
//
// The operation cannot continue because the object is in the process of being removed.
//
#define ERROR_DS_OBJECT_BEING_REMOVED    ((ULONG)0x00002093L)

//
// MessageId: ERROR_DS_CANT_DELETE_DSA_OBJ
//
// MessageText:
//
// The DSA object cannot be deleted.
//
#define ERROR_DS_CANT_DELETE_DSA_OBJ     ((ULONG)0x00002094L)

//
// MessageId: ERROR_DS_GENERIC_ERROR
//
// MessageText:
//
// A directory service error has occurred.
//
#define ERROR_DS_GENERIC_ERROR           ((ULONG)0x00002095L)

//
// MessageId: ERROR_DS_DSA_MUST_BE_INT_MASTER
//
// MessageText:
//
// The operation can only be performed on an internal master DSA object.
//
#define ERROR_DS_DSA_MUST_BE_INT_MASTER  ((ULONG)0x00002096L)

//
// MessageId: ERROR_DS_CLASS_NOT_DSA
//
// MessageText:
//
// The object must be of class DSA.
//
#define ERROR_DS_CLASS_NOT_DSA           ((ULONG)0x00002097L)

//
// MessageId: ERROR_DS_INSUFF_ACCESS_RIGHTS
//
// MessageText:
//
// Insufficient access rights to perform the operation.
//
#define ERROR_DS_INSUFF_ACCESS_RIGHTS    ((ULONG)0x00002098L)

//
// MessageId: ERROR_DS_ILLEGAL_SUPERIOR
//
// MessageText:
//
// The object cannot be added because the parent is not on the list of possible superiors.
//
#define ERROR_DS_ILLEGAL_SUPERIOR        ((ULONG)0x00002099L)

//
// MessageId: ERROR_DS_ATTRIBUTE_OWNED_BY_SAM
//
// MessageText:
//
// Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).
//
#define ERROR_DS_ATTRIBUTE_OWNED_BY_SAM  ((ULONG)0x0000209AL)

//
// MessageId: ERROR_DS_NAME_TOO_MANY_PARTS
//
// MessageText:
//
// The name has too many parts.
//
#define ERROR_DS_NAME_TOO_MANY_PARTS     ((ULONG)0x0000209BL)

//
// MessageId: ERROR_DS_NAME_TOO_LONG
//
// MessageText:
//
// The name is too long.
//
#define ERROR_DS_NAME_TOO_LONG           ((ULONG)0x0000209CL)

//
// MessageId: ERROR_DS_NAME_VALUE_TOO_LONG
//
// MessageText:
//
// The name value is too long.
//
#define ERROR_DS_NAME_VALUE_TOO_LONG     ((ULONG)0x0000209DL)

//
// MessageId: ERROR_DS_NAME_UNPARSEABLE
//
// MessageText:
//
// The directory service encountered an error parsing a name.
//
#define ERROR_DS_NAME_UNPARSEABLE        ((ULONG)0x0000209EL)

//
// MessageId: ERROR_DS_NAME_TYPE_UNKNOWN
//
// MessageText:
//
// The directory service cannot get the attribute type for a name.
//
#define ERROR_DS_NAME_TYPE_UNKNOWN       ((ULONG)0x0000209FL)

//
// MessageId: ERROR_DS_NOT_AN_OBJECT
//
// MessageText:
//
// The name does not identify an object; the name identifies a phantom.
//
#define ERROR_DS_NOT_AN_OBJECT           ((ULONG)0x000020A0L)

//
// MessageId: ERROR_DS_SEC_DESC_TOO_SHORT
//
// MessageText:
//
// The security descriptor is too short.
//
#define ERROR_DS_SEC_DESC_TOO_SHORT      ((ULONG)0x000020A1L)

//
// MessageId: ERROR_DS_SEC_DESC_INVALID
//
// MessageText:
//
// The security descriptor is invalid.
//
#define ERROR_DS_SEC_DESC_INVALID        ((ULONG)0x000020A2L)

//
// MessageId: ERROR_DS_NO_DELETED_NAME
//
// MessageText:
//
// Failed to create name for deleted object.
//
#define ERROR_DS_NO_DELETED_NAME         ((ULONG)0x000020A3L)

//
// MessageId: ERROR_DS_SUBREF_MUST_HAVE_PARENT
//
// MessageText:
//
// The parent of a new subref must exist.
//
#define ERROR_DS_SUBREF_MUST_HAVE_PARENT ((ULONG)0x000020A4L)

//
// MessageId: ERROR_DS_NCNAME_MUST_BE_NC
//
// MessageText:
//
// The object must be a naming context.
//
#define ERROR_DS_NCNAME_MUST_BE_NC       ((ULONG)0x000020A5L)

//
// MessageId: ERROR_DS_CANT_ADD_SYSTEM_ONLY
//
// MessageText:
//
// It is not permitted to add an attribute which is owned by the system.
//
#define ERROR_DS_CANT_ADD_SYSTEM_ONLY    ((ULONG)0x000020A6L)

//
// MessageId: ERROR_DS_CLASS_MUST_BE_CONCRETE
//
// MessageText:
//
// The class of the object must be structural; you cannot instantiate an abstract class.
//
#define ERROR_DS_CLASS_MUST_BE_CONCRETE  ((ULONG)0x000020A7L)

//
// MessageId: ERROR_DS_INVALID_DMD
//
// MessageText:
//
// The schema object could not be found.
//
#define ERROR_DS_INVALID_DMD             ((ULONG)0x000020A8L)

//
// MessageId: ERROR_DS_OBJ_GUID_EXISTS
//
// MessageText:
//
// A local object with this GUID (dead or alive) already exists.
//
#define ERROR_DS_OBJ_GUID_EXISTS         ((ULONG)0x000020A9L)

//
// MessageId: ERROR_DS_NOT_ON_BACKLINK
//
// MessageText:
//
// The operation cannot be performed on a back link.
//
#define ERROR_DS_NOT_ON_BACKLINK         ((ULONG)0x000020AAL)

//
// MessageId: ERROR_DS_NO_CROSSREF_FOR_NC
//
// MessageText:
//
// The cross reference for the specified naming context could not be found.
//
#define ERROR_DS_NO_CROSSREF_FOR_NC      ((ULONG)0x000020ABL)

//
// MessageId: ERROR_DS_SHUTTING_DOWN
//
// MessageText:
//
// The operation could not be performed because the directory service is shutting down.
//
#define ERROR_DS_SHUTTING_DOWN           ((ULONG)0x000020ACL)

//
// MessageId: ERROR_DS_UNKNOWN_OPERATION
//
// MessageText:
//
// The directory service request is invalid.
//
#define ERROR_DS_UNKNOWN_OPERATION       ((ULONG)0x000020ADL)

//
// MessageId: ERROR_DS_INVALID_ROLE_OWNER
//
// MessageText:
//
// The role owner attribute could not be read.
//
#define ERROR_DS_INVALID_ROLE_OWNER      ((ULONG)0x000020AEL)

//
// MessageId: ERROR_DS_COULDNT_CONTACT_FSMO
//
// MessageText:
//
// The requested FSMO operation failed. The current FSMO holder could not be reached.
//
#define ERROR_DS_COULDNT_CONTACT_FSMO    ((ULONG)0x000020AFL)

//
// MessageId: ERROR_DS_CROSS_NC_DN_RENAME
//
// MessageText:
//
// Modification of a DN across a naming context is not permitted.
//
#define ERROR_DS_CROSS_NC_DN_RENAME      ((ULONG)0x000020B0L)

//
// MessageId: ERROR_DS_CANT_MOD_SYSTEM_ONLY
//
// MessageText:
//
// The attribute cannot be modified because it is owned by the system.
//
#define ERROR_DS_CANT_MOD_SYSTEM_ONLY    ((ULONG)0x000020B1L)

//
// MessageId: ERROR_DS_REPLICATOR_ONLY
//
// MessageText:
//
// Only the replicator can perform this function.
//
#define ERROR_DS_REPLICATOR_ONLY         ((ULONG)0x000020B2L)

//
// MessageId: ERROR_DS_OBJ_CLASS_NOT_DEFINED
//
// MessageText:
//
// The specified class is not defined.
//
#define ERROR_DS_OBJ_CLASS_NOT_DEFINED   ((ULONG)0x000020B3L)

//
// MessageId: ERROR_DS_OBJ_CLASS_NOT_SUBCLASS
//
// MessageText:
//
// The specified class is not a subclass.
//
#define ERROR_DS_OBJ_CLASS_NOT_SUBCLASS  ((ULONG)0x000020B4L)

//
// MessageId: ERROR_DS_NAME_REFERENCE_INVALID
//
// MessageText:
//
// The name reference is invalid.
//
#define ERROR_DS_NAME_REFERENCE_INVALID  ((ULONG)0x000020B5L)

//
// MessageId: ERROR_DS_CROSS_REF_EXISTS
//
// MessageText:
//
// A cross reference already exists.
//
#define ERROR_DS_CROSS_REF_EXISTS        ((ULONG)0x000020B6L)

//
// MessageId: ERROR_DS_CANT_DEL_MASTER_CROSSREF
//
// MessageText:
//
// It is not permitted to delete a master cross reference.
//
#define ERROR_DS_CANT_DEL_MASTER_CROSSREF ((ULONG)0x000020B7L)

//
// MessageId: ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD
//
// MessageText:
//
// Subtree notifications are only supported on NC heads.
//
#define ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD ((ULONG)0x000020B8L)

//
// MessageId: ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX
//
// MessageText:
//
// Notification filter is too complex.
//
#define ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX ((ULONG)0x000020B9L)

//
// MessageId: ERROR_DS_DUP_RDN
//
// MessageText:
//
// Schema update failed: duplicate RDN.
//
#define ERROR_DS_DUP_RDN                 ((ULONG)0x000020BAL)

//
// MessageId: ERROR_DS_DUP_OID
//
// MessageText:
//
// Schema update failed: duplicate OID
//
#define ERROR_DS_DUP_OID                 ((ULONG)0x000020BBL)

//
// MessageId: ERROR_DS_DUP_MAPI_ID
//
// MessageText:
//
// Schema update failed: duplicate MAPI identifier.
//
#define ERROR_DS_DUP_MAPI_ID             ((ULONG)0x000020BCL)

//
// MessageId: ERROR_DS_DUP_SCHEMA_ID_GUID
//
// MessageText:
//
// Schema update failed: duplicate schema-id GUID.
//
#define ERROR_DS_DUP_SCHEMA_ID_GUID      ((ULONG)0x000020BDL)

//
// MessageId: ERROR_DS_DUP_LDAP_DISPLAY_NAME
//
// MessageText:
//
// Schema update failed: duplicate LDAP display name.
//
#define ERROR_DS_DUP_LDAP_DISPLAY_NAME   ((ULONG)0x000020BEL)

//
// MessageId: ERROR_DS_SEMANTIC_ATT_TEST
//
// MessageText:
//
// Schema update failed: range-lower less than range upper
//
#define ERROR_DS_SEMANTIC_ATT_TEST       ((ULONG)0x000020BFL)

//
// MessageId: ERROR_DS_SYNTAX_MISMATCH
//
// MessageText:
//
// Schema update failed: syntax mismatch
//
#define ERROR_DS_SYNTAX_MISMATCH         ((ULONG)0x000020C0L)

//
// MessageId: ERROR_DS_EXISTS_IN_MUST_HAVE
//
// MessageText:
//
// Schema deletion failed: attribute is used in must-contain
//
#define ERROR_DS_EXISTS_IN_MUST_HAVE     ((ULONG)0x000020C1L)

//
// MessageId: ERROR_DS_EXISTS_IN_MAY_HAVE
//
// MessageText:
//
// Schema deletion failed: attribute is used in may-contain
//
#define ERROR_DS_EXISTS_IN_MAY_HAVE      ((ULONG)0x000020C2L)

//
// MessageId: ERROR_DS_NONEXISTENT_MAY_HAVE
//
// MessageText:
//
// Schema update failed: attribute in may-contain does not exist
//
#define ERROR_DS_NONEXISTENT_MAY_HAVE    ((ULONG)0x000020C3L)

//
// MessageId: ERROR_DS_NONEXISTENT_MUST_HAVE
//
// MessageText:
//
// Schema update failed: attribute in must-contain does not exist
//
#define ERROR_DS_NONEXISTENT_MUST_HAVE   ((ULONG)0x000020C4L)

//
// MessageId: ERROR_DS_AUX_CLS_TEST_FAIL
//
// MessageText:
//
// Schema update failed: class in aux-class list does not exist or is not an auxiliary class
//
#define ERROR_DS_AUX_CLS_TEST_FAIL       ((ULONG)0x000020C5L)

//
// MessageId: ERROR_DS_NONEXISTENT_POSS_SUP
//
// MessageText:
//
// Schema update failed: class in poss-superiors does not exist
//
#define ERROR_DS_NONEXISTENT_POSS_SUP    ((ULONG)0x000020C6L)

//
// MessageId: ERROR_DS_SUB_CLS_TEST_FAIL
//
// MessageText:
//
// Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules
//
#define ERROR_DS_SUB_CLS_TEST_FAIL       ((ULONG)0x000020C7L)

//
// MessageId: ERROR_DS_BAD_RDN_ATT_ID_SYNTAX
//
// MessageText:
//
// Schema update failed: Rdn-Att-Id has wrong syntax
//
#define ERROR_DS_BAD_RDN_ATT_ID_SYNTAX   ((ULONG)0x000020C8L)

//
// MessageId: ERROR_DS_EXISTS_IN_AUX_CLS
//
// MessageText:
//
// Schema deletion failed: class is used as auxiliary class
//
#define ERROR_DS_EXISTS_IN_AUX_CLS       ((ULONG)0x000020C9L)

//
// MessageId: ERROR_DS_EXISTS_IN_SUB_CLS
//
// MessageText:
//
// Schema deletion failed: class is used as sub class
//
#define ERROR_DS_EXISTS_IN_SUB_CLS       ((ULONG)0x000020CAL)

//
// MessageId: ERROR_DS_EXISTS_IN_POSS_SUP
//
// MessageText:
//
// Schema deletion failed: class is used as poss superior
//
#define ERROR_DS_EXISTS_IN_POSS_SUP      ((ULONG)0x000020CBL)

//
// MessageId: ERROR_DS_RECALCSCHEMA_FAILED
//
// MessageText:
//
// Schema update failed in recalculating validation cache.
//
#define ERROR_DS_RECALCSCHEMA_FAILED     ((ULONG)0x000020CCL)

//
// MessageId: ERROR_DS_TREE_DELETE_NOT_FINISHED
//
// MessageText:
//
// The tree deletion is not finished.
//
#define ERROR_DS_TREE_DELETE_NOT_FINISHED ((ULONG)0x000020CDL)

//
// MessageId: ERROR_DS_CANT_DELETE
//
// MessageText:
//
// The requested delete operation could not be performed.
//
#define ERROR_DS_CANT_DELETE             ((ULONG)0x000020CEL)

//
// MessageId: ERROR_DS_ATT_SCHEMA_REQ_ID
//
// MessageText:
//
// Cannot read the governs class identifier for the schema record.
//
#define ERROR_DS_ATT_SCHEMA_REQ_ID       ((ULONG)0x000020CFL)

//
// MessageId: ERROR_DS_BAD_ATT_SCHEMA_SYNTAX
//
// MessageText:
//
// The attribute schema has bad syntax.
//
#define ERROR_DS_BAD_ATT_SCHEMA_SYNTAX   ((ULONG)0x000020D0L)

//
// MessageId: ERROR_DS_CANT_CACHE_ATT
//
// MessageText:
//
// The attribute could not be cached.
//
#define ERROR_DS_CANT_CACHE_ATT          ((ULONG)0x000020D1L)

//
// MessageId: ERROR_DS_CANT_CACHE_CLASS
//
// MessageText:
//
// The class could not be cached.
//
#define ERROR_DS_CANT_CACHE_CLASS        ((ULONG)0x000020D2L)

//
// MessageId: ERROR_DS_CANT_REMOVE_ATT_CACHE
//
// MessageText:
//
// The attribute could not be removed from the cache.
//
#define ERROR_DS_CANT_REMOVE_ATT_CACHE   ((ULONG)0x000020D3L)

//
// MessageId: ERROR_DS_CANT_REMOVE_CLASS_CACHE
//
// MessageText:
//
// The class could not be removed from the cache.
//
#define ERROR_DS_CANT_REMOVE_CLASS_CACHE ((ULONG)0x000020D4L)

//
// MessageId: ERROR_DS_CANT_RETRIEVE_DN
//
// MessageText:
//
// The distinguished name attribute could not be read.
//
#define ERROR_DS_CANT_RETRIEVE_DN        ((ULONG)0x000020D5L)

//
// MessageId: ERROR_DS_MISSING_SUPREF
//
// MessageText:
//
// No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.
//
#define ERROR_DS_MISSING_SUPREF          ((ULONG)0x000020D6L)

//
// MessageId: ERROR_DS_CANT_RETRIEVE_INSTANCE
//
// MessageText:
//
// The instance type attribute could not be retrieved.
//
#define ERROR_DS_CANT_RETRIEVE_INSTANCE  ((ULONG)0x000020D7L)

//
// MessageId: ERROR_DS_CODE_INCONSISTENCY
//
// MessageText:
//
// An internal error has occurred.
//
#define ERROR_DS_CODE_INCONSISTENCY      ((ULONG)0x000020D8L)

//
// MessageId: ERROR_DS_DATABASE_ERROR
//
// MessageText:
//
// A database error has occurred.
//
#define ERROR_DS_DATABASE_ERROR          ((ULONG)0x000020D9L)

//
// MessageId: ERROR_DS_GOVERNSID_MISSING
//
// MessageText:
//
// The attribute GOVERNSID is missing.
//
#define ERROR_DS_GOVERNSID_MISSING       ((ULONG)0x000020DAL)

//
// MessageId: ERROR_DS_MISSING_EXPECTED_ATT
//
// MessageText:
//
// An expected attribute is missing.
//
#define ERROR_DS_MISSING_EXPECTED_ATT    ((ULONG)0x000020DBL)

//
// MessageId: ERROR_DS_NCNAME_MISSING_CR_REF
//
// MessageText:
//
// The specified naming context is missing a cross reference.
//
#define ERROR_DS_NCNAME_MISSING_CR_REF   ((ULONG)0x000020DCL)

//
// MessageId: ERROR_DS_SECURITY_CHECKING_ERROR
//
// MessageText:
//
// A security checking error has occurred.
//
#define ERROR_DS_SECURITY_CHECKING_ERROR ((ULONG)0x000020DDL)

//
// MessageId: ERROR_DS_SCHEMA_NOT_LOADED
//
// MessageText:
//
// The schema is not loaded.
//
#define ERROR_DS_SCHEMA_NOT_LOADED       ((ULONG)0x000020DEL)

//
// MessageId: ERROR_DS_SCHEMA_ALLOC_FAILED
//
// MessageText:
//
// Schema allocation failed. Please check if the machine is running low on memory.
//
#define ERROR_DS_SCHEMA_ALLOC_FAILED     ((ULONG)0x000020DFL)

//
// MessageId: ERROR_DS_ATT_SCHEMA_REQ_SYNTAX
//
// MessageText:
//
// Failed to obtain the required syntax for the attribute schema.
//
#define ERROR_DS_ATT_SCHEMA_REQ_SYNTAX   ((ULONG)0x000020E0L)

//
// MessageId: ERROR_DS_GCVERIFY_ERROR
//
// MessageText:
//
// The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.
//
#define ERROR_DS_GCVERIFY_ERROR          ((ULONG)0x000020E1L)

//
// MessageId: ERROR_DS_DRA_SCHEMA_MISMATCH
//
// MessageText:
//
// The replication operation failed because of a schema mismatch between the servers involved.
//
#define ERROR_DS_DRA_SCHEMA_MISMATCH     ((ULONG)0x000020E2L)

//
// MessageId: ERROR_DS_CANT_FIND_DSA_OBJ
//
// MessageText:
//
// The DSA object could not be found.
//
#define ERROR_DS_CANT_FIND_DSA_OBJ       ((ULONG)0x000020E3L)

//
// MessageId: ERROR_DS_CANT_FIND_EXPECTED_NC
//
// MessageText:
//
// The naming context could not be found.
//
#define ERROR_DS_CANT_FIND_EXPECTED_NC   ((ULONG)0x000020E4L)

//
// MessageId: ERROR_DS_CANT_FIND_NC_IN_CACHE
//
// MessageText:
//
// The naming context could not be found in the cache.
//
#define ERROR_DS_CANT_FIND_NC_IN_CACHE   ((ULONG)0x000020E5L)

//
// MessageId: ERROR_DS_CANT_RETRIEVE_CHILD
//
// MessageText:
//
// The child object could not be retrieved.
//
#define ERROR_DS_CANT_RETRIEVE_CHILD     ((ULONG)0x000020E6L)

//
// MessageId: ERROR_DS_SECURITY_ILLEGAL_MODIFY
//
// MessageText:
//
// The modification was not permitted for security reasons.
//
#define ERROR_DS_SECURITY_ILLEGAL_MODIFY ((ULONG)0x000020E7L)

//
// MessageId: ERROR_DS_CANT_REPLACE_HIDDEN_REC
//
// MessageText:
//
// The operation cannot replace the hidden record.
//
#define ERROR_DS_CANT_REPLACE_HIDDEN_REC ((ULONG)0x000020E8L)

//
// MessageId: ERROR_DS_BAD_HIERARCHY_FILE
//
// MessageText:
//
// The hierarchy file is invalid.
//
#define ERROR_DS_BAD_HIERARCHY_FILE      ((ULONG)0x000020E9L)

//
// MessageId: ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED
//
// MessageText:
//
// The attempt to build the hierarchy table failed.
//
#define ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED ((ULONG)0x000020EAL)

//
// MessageId: ERROR_DS_CONFIG_PARAM_MISSING
//
// MessageText:
//
// The directory configuration parameter is missing from the registry.
//
#define ERROR_DS_CONFIG_PARAM_MISSING    ((ULONG)0x000020EBL)

//
// MessageId: ERROR_DS_COUNTING_AB_INDICES_FAILED
//
// MessageText:
//
// The attempt to count the address book indices failed.
//
#define ERROR_DS_COUNTING_AB_INDICES_FAILED ((ULONG)0x000020ECL)

//
// MessageId: ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED
//
// MessageText:
//
// The allocation of the hierarchy table failed.
//
#define ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED ((ULONG)0x000020EDL)

//
// MessageId: ERROR_DS_INTERNAL_FAILURE
//
// MessageText:
//
// The directory service encountered an internal failure.
//
#define ERROR_DS_INTERNAL_FAILURE        ((ULONG)0x000020EEL)

//
// MessageId: ERROR_DS_UNKNOWN_ERROR
//
// MessageText:
//
// The directory service encountered an unknown failure.
//
#define ERROR_DS_UNKNOWN_ERROR           ((ULONG)0x000020EFL)

//
// MessageId: ERROR_DS_ROOT_REQUIRES_CLASS_TOP
//
// MessageText:
//
// A root object requires a class of 'top'.
//
#define ERROR_DS_ROOT_REQUIRES_CLASS_TOP ((ULONG)0x000020F0L)

//
// MessageId: ERROR_DS_REFUSING_FSMO_ROLES
//
// MessageText:
//
// This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.
//
#define ERROR_DS_REFUSING_FSMO_ROLES     ((ULONG)0x000020F1L)

//
// MessageId: ERROR_DS_MISSING_FSMO_SETTINGS
//
// MessageText:
//
// The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.
//
#define ERROR_DS_MISSING_FSMO_SETTINGS   ((ULONG)0x000020F2L)

//
// MessageId: ERROR_DS_UNABLE_TO_SURRENDER_ROLES
//
// MessageText:
//
// The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.
//
#define ERROR_DS_UNABLE_TO_SURRENDER_ROLES ((ULONG)0x000020F3L)

//
// MessageId: ERROR_DS_DRA_GENERIC
//
// MessageText:
//
// The replication operation failed.
//
#define ERROR_DS_DRA_GENERIC             ((ULONG)0x000020F4L)

//
// MessageId: ERROR_DS_DRA_INVALID_PARAMETER
//
// MessageText:
//
// An invalid parameter was specified for this replication operation.
//
#define ERROR_DS_DRA_INVALID_PARAMETER   ((ULONG)0x000020F5L)

//
// MessageId: ERROR_DS_DRA_BUSY
//
// MessageText:
//
// The directory service is too busy to complete the replication operation at this time.
//
#define ERROR_DS_DRA_BUSY                ((ULONG)0x000020F6L)

//
// MessageId: ERROR_DS_DRA_BAD_DN
//
// MessageText:
//
// The distinguished name specified for this replication operation is invalid.
//
#define ERROR_DS_DRA_BAD_DN              ((ULONG)0x000020F7L)

//
// MessageId: ERROR_DS_DRA_BAD_NC
//
// MessageText:
//
// The naming context specified for this replication operation is invalid.
//
#define ERROR_DS_DRA_BAD_NC              ((ULONG)0x000020F8L)

//
// MessageId: ERROR_DS_DRA_DN_EXISTS
//
// MessageText:
//
// The distinguished name specified for this replication operation already exists.
//
#define ERROR_DS_DRA_DN_EXISTS           ((ULONG)0x000020F9L)

//
// MessageId: ERROR_DS_DRA_INTERNAL_ERROR
//
// MessageText:
//
// The replication system encountered an internal error.
//
#define ERROR_DS_DRA_INTERNAL_ERROR      ((ULONG)0x000020FAL)

//
// MessageId: ERROR_DS_DRA_INCONSISTENT_DIT
//
// MessageText:
//
// The replication operation encountered a database inconsistency.
//
#define ERROR_DS_DRA_INCONSISTENT_DIT    ((ULONG)0x000020FBL)

//
// MessageId: ERROR_DS_DRA_CONNECTION_FAILED
//
// MessageText:
//
// The server specified for this replication operation could not be contacted.
//
#define ERROR_DS_DRA_CONNECTION_FAILED   ((ULONG)0x000020FCL)

//
// MessageId: ERROR_DS_DRA_BAD_INSTANCE_TYPE
//
// MessageText:
//
// The replication operation encountered an object with an invalid instance type.
//
#define ERROR_DS_DRA_BAD_INSTANCE_TYPE   ((ULONG)0x000020FDL)

//
// MessageId: ERROR_DS_DRA_OUT_OF_MEM
//
// MessageText:
//
// The replication operation failed to allocate memory.
//
#define ERROR_DS_DRA_OUT_OF_MEM          ((ULONG)0x000020FEL)

//
// MessageId: ERROR_DS_DRA_MAIL_PROBLEM
//
// MessageText:
//
// The replication operation encountered an error with the mail system.
//
#define ERROR_DS_DRA_MAIL_PROBLEM        ((ULONG)0x000020FFL)

//
// MessageId: ERROR_DS_DRA_REF_ALREADY_EXISTS
//
// MessageText:
//
// The replication reference information for the target server already exists.
//
#define ERROR_DS_DRA_REF_ALREADY_EXISTS  ((ULONG)0x00002100L)

//
// MessageId: ERROR_DS_DRA_REF_NOT_FOUND
//
// MessageText:
//
// The replication reference information for the target server does not exist.
//
#define ERROR_DS_DRA_REF_NOT_FOUND       ((ULONG)0x00002101L)

//
// MessageId: ERROR_DS_DRA_OBJ_IS_REP_SOURCE
//
// MessageText:
//
// The naming context cannot be removed because it is replicated to another server.
//
#define ERROR_DS_DRA_OBJ_IS_REP_SOURCE   ((ULONG)0x00002102L)

//
// MessageId: ERROR_DS_DRA_DB_ERROR
//
// MessageText:
//
// The replication operation encountered a database error.
//
#define ERROR_DS_DRA_DB_ERROR            ((ULONG)0x00002103L)

//
// MessageId: ERROR_DS_DRA_NO_REPLICA
//
// MessageText:
//
// The naming context is in the process of being removed or is not replicated from the specified server.
//
#define ERROR_DS_DRA_NO_REPLICA          ((ULONG)0x00002104L)

//
// MessageId: ERROR_DS_DRA_ACCESS_DENIED
//
// MessageText:
//
// Replication access was denied.
//
#define ERROR_DS_DRA_ACCESS_DENIED       ((ULONG)0x00002105L)

//
// MessageId: ERROR_DS_DRA_NOT_SUPPORTED
//
// MessageText:
//
// The requested operation is not supported by this version of the directory service.
//
#define ERROR_DS_DRA_NOT_SUPPORTED       ((ULONG)0x00002106L)

//
// MessageId: ERROR_DS_DRA_RPC_CANCELLED
//
// MessageText:
//
// The replication remote procedure call was cancelled.
//
#define ERROR_DS_DRA_RPC_CANCELLED       ((ULONG)0x00002107L)

//
// MessageId: ERROR_DS_DRA_SOURCE_DISABLED
//
// MessageText:
//
// The source server is currently rejecting replication requests.
//
#define ERROR_DS_DRA_SOURCE_DISABLED     ((ULONG)0x00002108L)

//
// MessageId: ERROR_DS_DRA_SINK_DISABLED
//
// MessageText:
//
// The destination server is currently rejecting replication requests.
//
#define ERROR_DS_DRA_SINK_DISABLED       ((ULONG)0x00002109L)

//
// MessageId: ERROR_DS_DRA_NAME_COLLISION
//
// MessageText:
//
// The replication operation failed due to a collision of object names.
//
#define ERROR_DS_DRA_NAME_COLLISION      ((ULONG)0x0000210AL)

//
// MessageId: ERROR_DS_DRA_SOURCE_REINSTALLED
//
// MessageText:
//
// The replication source has been reinstalled.
//
#define ERROR_DS_DRA_SOURCE_REINSTALLED  ((ULONG)0x0000210BL)

//
// MessageId: ERROR_DS_DRA_MISSING_PARENT
//
// MessageText:
//
// The replication operation failed because a required parent object is missing.
//
#define ERROR_DS_DRA_MISSING_PARENT      ((ULONG)0x0000210CL)

//
// MessageId: ERROR_DS_DRA_PREEMPTED
//
// MessageText:
//
// The replication operation was preempted.
//
#define ERROR_DS_DRA_PREEMPTED           ((ULONG)0x0000210DL)

//
// MessageId: ERROR_DS_DRA_ABANDON_SYNC
//
// MessageText:
//
// The replication synchronization attempt was abandoned because of a lack of updates.
//
#define ERROR_DS_DRA_ABANDON_SYNC        ((ULONG)0x0000210EL)

//
// MessageId: ERROR_DS_DRA_SHUTDOWN
//
// MessageText:
//
// The replication operation was terminated because the system is shutting down.
//
#define ERROR_DS_DRA_SHUTDOWN            ((ULONG)0x0000210FL)

//
// MessageId: ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET
//
// MessageText:
//
// Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of the source partial attribute set.
//
#define ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET ((ULONG)0x00002110L)

//
// MessageId: ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA
//
// MessageText:
//
// The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.
//
#define ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA ((ULONG)0x00002111L)

//
// MessageId: ERROR_DS_DRA_EXTN_CONNECTION_FAILED
//
// MessageText:
//
// The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.
//
#define ERROR_DS_DRA_EXTN_CONNECTION_FAILED ((ULONG)0x00002112L)

//
// MessageId: ERROR_DS_INSTALL_SCHEMA_MISMATCH
//
// MessageText:
//
// The version of the Active Directory schema of the source forest is not compatible with the version of Active Directory on this computer.
//
#define ERROR_DS_INSTALL_SCHEMA_MISMATCH ((ULONG)0x00002113L)

//
// MessageId: ERROR_DS_DUP_LINK_ID
//
// MessageText:
//
// Schema update failed: An attribute with the same link identifier already exists.
//
#define ERROR_DS_DUP_LINK_ID             ((ULONG)0x00002114L)

//
// MessageId: ERROR_DS_NAME_ERROR_RESOLVING
//
// MessageText:
//
// Name translation: Generic processing error.
//
#define ERROR_DS_NAME_ERROR_RESOLVING    ((ULONG)0x00002115L)

//
// MessageId: ERROR_DS_NAME_ERROR_NOT_FOUND
//
// MessageText:
//
// Name translation: Could not find the name or insufficient right to see name.
//
#define ERROR_DS_NAME_ERROR_NOT_FOUND    ((ULONG)0x00002116L)

//
// MessageId: ERROR_DS_NAME_ERROR_NOT_UNIQUE
//
// MessageText:
//
// Name translation: Input name mapped to more than one output name.
//
#define ERROR_DS_NAME_ERROR_NOT_UNIQUE   ((ULONG)0x00002117L)

//
// MessageId: ERROR_DS_NAME_ERROR_NO_MAPPING
//
// MessageText:
//
// Name translation: Input name found, but not the associated output format.
//
#define ERROR_DS_NAME_ERROR_NO_MAPPING   ((ULONG)0x00002118L)

//
// MessageId: ERROR_DS_NAME_ERROR_DOMAIN_ONLY
//
// MessageText:
//
// Name translation: Unable to resolve completely, only the domain was found.
//
#define ERROR_DS_NAME_ERROR_DOMAIN_ONLY  ((ULONG)0x00002119L)

//
// MessageId: ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING
//
// MessageText:
//
// Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.
//
#define ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING ((ULONG)0x0000211AL)

//
// MessageId: ERROR_DS_CONSTRUCTED_ATT_MOD
//
// MessageText:
//
// Modification of a constructed attribute is not allowed.
//
#define ERROR_DS_CONSTRUCTED_ATT_MOD     ((ULONG)0x0000211BL)

//
// MessageId: ERROR_DS_WRONG_OM_OBJ_CLASS
//
// MessageText:
//
// The OM-Object-Class specified is incorrect for an attribute with the specified syntax.
//
#define ERROR_DS_WRONG_OM_OBJ_CLASS      ((ULONG)0x0000211CL)

//
// MessageId: ERROR_DS_DRA_REPL_PENDING
//
// MessageText:
//
// The replication request has been posted; waiting for reply.
//
#define ERROR_DS_DRA_REPL_PENDING        ((ULONG)0x0000211DL)

//
// MessageId: ERROR_DS_DS_REQUIRED
//
// MessageText:
//
// The requested operation requires a directory service, and none was available.
//
#define ERROR_DS_DS_REQUIRED             ((ULONG)0x0000211EL)

//
// MessageId: ERROR_DS_INVALID_LDAP_DISPLAY_NAME
//
// MessageText:
//
// The LDAP display name of the class or attribute contains non-ASCII characters.
//
#define ERROR_DS_INVALID_LDAP_DISPLAY_NAME ((ULONG)0x0000211FL)

//
// MessageId: ERROR_DS_NON_BASE_SEARCH
//
// MessageText:
//
// The requested search operation is only supported for base searches.
//
#define ERROR_DS_NON_BASE_SEARCH         ((ULONG)0x00002120L)

//
// MessageId: ERROR_DS_CANT_RETRIEVE_ATTS
//
// MessageText:
//
// The search failed to retrieve attributes from the database.
//
#define ERROR_DS_CANT_RETRIEVE_ATTS      ((ULONG)0x00002121L)

//
// MessageId: ERROR_DS_BACKLINK_WITHOUT_LINK
//
// MessageText:
//
// The schema update operation tried to add a backward link attribute that has no corresponding forward link.
//
#define ERROR_DS_BACKLINK_WITHOUT_LINK   ((ULONG)0x00002122L)

//
// MessageId: ERROR_DS_EPOCH_MISMATCH
//
// MessageText:
//
// Source and destination of a cross domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.
//
#define ERROR_DS_EPOCH_MISMATCH          ((ULONG)0x00002123L)

//
// MessageId: ERROR_DS_SRC_NAME_MISMATCH
//
// MessageText:
//
// Source and destination of a cross domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.
//
#define ERROR_DS_SRC_NAME_MISMATCH       ((ULONG)0x00002124L)

//
// MessageId: ERROR_DS_SRC_AND_DST_NC_IDENTICAL
//
// MessageText:
//
// Source and destination of a cross domain move operation are identical. Caller should use local move operation instead of cross domain move operation.
//
#define ERROR_DS_SRC_AND_DST_NC_IDENTICAL ((ULONG)0x00002125L)

//
// MessageId: ERROR_DS_DST_NC_MISMATCH
//
// MessageText:
//
// Source and destination for a cross domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.
//
#define ERROR_DS_DST_NC_MISMATCH         ((ULONG)0x00002126L)

//
// MessageId: ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC
//
// MessageText:
//
// Destination of a cross domain move is not authoritative for the destination naming context.
//
#define ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC ((ULONG)0x00002127L)

//
// MessageId: ERROR_DS_SRC_GUID_MISMATCH
//
// MessageText:
//
// Source and destination of a cross domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.
//
#define ERROR_DS_SRC_GUID_MISMATCH       ((ULONG)0x00002128L)

//
// MessageId: ERROR_DS_CANT_MOVE_DELETED_OBJECT
//
// MessageText:
//
// Object being moved across domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.
//
#define ERROR_DS_CANT_MOVE_DELETED_OBJECT ((ULONG)0x00002129L)

//
// MessageId: ERROR_DS_PDC_OPERATION_IN_PROGRESS
//
// MessageText:
//
// Another operation, which requires exclusive access to the PDC PSMO, is already in progress.
//
#define ERROR_DS_PDC_OPERATION_IN_PROGRESS ((ULONG)0x0000212AL)

//
// MessageId: ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD
//
// MessageText:
//
// A cross domain move operation failed such that the two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.
//
#define ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD ((ULONG)0x0000212BL)

//
// MessageId: ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION
//
// MessageText:
//
// This object may not be moved across domain boundaries either because cross domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.
//
#define ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION ((ULONG)0x0000212CL)

//
// MessageId: ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS
//
// MessageText:
//
// Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.
//
#define ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS ((ULONG)0x0000212DL)

//
// MessageId: ERROR_DS_NC_MUST_HAVE_NC_PARENT
//
// MessageText:
//
// A naming context head must be the immediate child of another naming context head, not of an interior node.
//
#define ERROR_DS_NC_MUST_HAVE_NC_PARENT  ((ULONG)0x0000212EL)

//
// MessageId: ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE
//
// MessageText:
//
// The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters)
//
#define ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE ((ULONG)0x0000212FL)

//
// MessageId: ERROR_DS_DST_DOMAIN_NOT_NATIVE
//
// MessageText:
//
// Destination domain must be in native mode.
//
#define ERROR_DS_DST_DOMAIN_NOT_NATIVE   ((ULONG)0x00002130L)

//
// MessageId: ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER
//
// MessageText:
//
// The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.
//
#define ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER ((ULONG)0x00002131L)

//
// MessageId: ERROR_DS_CANT_MOVE_ACCOUNT_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty account groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_ACCOUNT_GROUP ((ULONG)0x00002132L)

//
// MessageId: ERROR_DS_CANT_MOVE_RESOURCE_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty resource groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_RESOURCE_GROUP ((ULONG)0x00002133L)

//
// MessageId: ERROR_DS_INVALID_SEARCH_FLAG
//
// MessageText:
//
// The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.
//
#define ERROR_DS_INVALID_SEARCH_FLAG     ((ULONG)0x00002134L)

//
// MessageId: ERROR_DS_NO_TREE_DELETE_ABOVE_NC
//
// MessageText:
//
// Tree deletions starting at an object which has an NC head as a descendant are not allowed.
//
#define ERROR_DS_NO_TREE_DELETE_ABOVE_NC ((ULONG)0x00002135L)

//
// MessageId: ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE
//
// MessageText:
//
// The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.
//
#define ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE ((ULONG)0x00002136L)

//
// MessageId: ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE
//
// MessageText:
//
// The directory service failed to identify the list of objects to delete while attempting a tree deletion.
//
#define ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE ((ULONG)0x00002137L)

//
// MessageId: ERROR_DS_SAM_INIT_FAILURE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Click OK to shut down the system and reboot into Directory Services Restore Mode. Check the event log for detailed information.
//
#define ERROR_DS_SAM_INIT_FAILURE        ((ULONG)0x00002138L)

//
// MessageId: ERROR_DS_SENSITIVE_GROUP_VIOLATION
//
// MessageText:
//
// Only an administrator can modify the membership list of an administrative group.
//
#define ERROR_DS_SENSITIVE_GROUP_VIOLATION ((ULONG)0x00002139L)

//
// MessageId: ERROR_DS_CANT_MOD_PRIMARYGROUPID
//
// MessageText:
//
// Cannot change the primary group ID of a domain controller account.
//
#define ERROR_DS_CANT_MOD_PRIMARYGROUPID ((ULONG)0x0000213AL)

//
// MessageId: ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD
//
// MessageText:
//
// An attempt is made to modify the base schema.
//
#define ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD ((ULONG)0x0000213BL)

//
// MessageId: ERROR_DS_NONSAFE_SCHEMA_CHANGE
//
// MessageText:
//
// Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.
//
#define ERROR_DS_NONSAFE_SCHEMA_CHANGE   ((ULONG)0x0000213CL)

//
// MessageId: ERROR_DS_SCHEMA_UPDATE_DISALLOWED
//
// MessageText:
//
// Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.
//
#define ERROR_DS_SCHEMA_UPDATE_DISALLOWED ((ULONG)0x0000213DL)

//
// MessageId: ERROR_DS_CANT_CREATE_UNDER_SCHEMA
//
// MessageText:
//
// An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.
//
#define ERROR_DS_CANT_CREATE_UNDER_SCHEMA ((ULONG)0x0000213EL)

//
// MessageId: ERROR_DS_INSTALL_NO_SRC_SCH_VERSION
//
// MessageText:
//
// The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.
//
#define ERROR_DS_INSTALL_NO_SRC_SCH_VERSION ((ULONG)0x0000213FL)

//
// MessageId: ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE
//
// MessageText:
//
// The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.
//
#define ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE ((ULONG)0x00002140L)

//
// MessageId: ERROR_DS_INVALID_GROUP_TYPE
//
// MessageText:
//
// The specified group type is invalid.
//
#define ERROR_DS_INVALID_GROUP_TYPE      ((ULONG)0x00002141L)

//
// MessageId: ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN
//
// MessageText:
//
// Cannot nest global groups in a mixed domain if the group is security-enabled.
//
#define ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN ((ULONG)0x00002142L)

//
// MessageId: ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN
//
// MessageText:
//
// Cannot nest local groups in a mixed domain if the group is security-enabled.
//
#define ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN ((ULONG)0x00002143L)

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER
//
// MessageText:
//
// A global group cannot have a local group as a member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER ((ULONG)0x00002144L)

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER
//
// MessageText:
//
// A global group cannot have a universal group as a member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER ((ULONG)0x00002145L)

//
// MessageId: ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER
//
// MessageText:
//
// A universal group cannot have a local group as a member.
//
#define ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER ((ULONG)0x00002146L)

//
// MessageId: ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER
//
// MessageText:
//
// A global group cannot have a cross-domain member.
//
#define ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER ((ULONG)0x00002147L)

//
// MessageId: ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER
//
// MessageText:
//
// A local group cannot have another cross-domain local group as a member.
//
#define ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER ((ULONG)0x00002148L)

//
// MessageId: ERROR_DS_HAVE_PRIMARY_MEMBERS
//
// MessageText:
//
// A group with primary members cannot change to a security-disabled group.
//
#define ERROR_DS_HAVE_PRIMARY_MEMBERS    ((ULONG)0x00002149L)

//
// MessageId: ERROR_DS_STRING_SD_CONVERSION_FAILED
//
// MessageText:
//
// The schema cache load failed to convert the string default SD on a class-schema object.
//
#define ERROR_DS_STRING_SD_CONVERSION_FAILED ((ULONG)0x0000214AL)

//
// MessageId: ERROR_DS_NAMING_MASTER_GC
//
// MessageText:
//
// Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers)
//
#define ERROR_DS_NAMING_MASTER_GC        ((ULONG)0x0000214BL)

//
// MessageId: ERROR_DS_LOOKUP_FAILURE
//
// MessageText:
//
// The DSA operation is unable to proceed because of a DNS lookup failure.
//
#define ERROR_DS_LOOKUP_FAILURE          ((ULONG)0x0000214CL)

//
// MessageId: ERROR_DS_COULDNT_UPDATE_SPNS
//
// MessageText:
//
// While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.
//
#define ERROR_DS_COULDNT_UPDATE_SPNS     ((ULONG)0x0000214DL)

//
// MessageId: ERROR_DS_CANT_RETRIEVE_SD
//
// MessageText:
//
// The Security Descriptor attribute could not be read.
//
#define ERROR_DS_CANT_RETRIEVE_SD        ((ULONG)0x0000214EL)

//
// MessageId: ERROR_DS_KEY_NOT_UNIQUE
//
// MessageText:
//
// The object requested was not found, but an object with that key was found.
//
#define ERROR_DS_KEY_NOT_UNIQUE          ((ULONG)0x0000214FL)

//
// MessageId: ERROR_DS_WRONG_LINKED_ATT_SYNTAX
//
// MessageText:
//
// The syntax of the linked attributed being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1.
//
#define ERROR_DS_WRONG_LINKED_ATT_SYNTAX ((ULONG)0x00002150L)

//
// MessageId: ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD
//
// MessageText:
//
// Security Account Manager needs to get the boot password.
//
#define ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD ((ULONG)0x00002151L)

//
// MessageId: ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY
//
// MessageText:
//
// Security Account Manager needs to get the boot key from floppy disk.
//
#define ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY ((ULONG)0x00002152L)

//
// MessageId: ERROR_DS_CANT_START
//
// MessageText:
//
// Directory Service cannot start.
//
#define ERROR_DS_CANT_START              ((ULONG)0x00002153L)

//
// MessageId: ERROR_DS_INIT_FAILURE
//
// MessageText:
//
// Directory Services could not start.
//
#define ERROR_DS_INIT_FAILURE            ((ULONG)0x00002154L)

//
// MessageId: ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION
//
// MessageText:
//
// The connection between client and server requires packet privacy or better.
//
#define ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION ((ULONG)0x00002155L)

//
// MessageId: ERROR_DS_SOURCE_DOMAIN_IN_FOREST
//
// MessageText:
//
// The source domain may not be in the same forest as destination.
//
#define ERROR_DS_SOURCE_DOMAIN_IN_FOREST ((ULONG)0x00002156L)

//
// MessageId: ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST
//
// MessageText:
//
// The destination domain must be in the forest.
//
#define ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST ((ULONG)0x00002157L)

//
// MessageId: ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED
//
// MessageText:
//
// The operation requires that destination domain auditing be enabled.
//
#define ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED ((ULONG)0x00002158L)

//
// MessageId: ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN
//
// MessageText:
//
// The operation couldn't locate a DC for the source domain.
//
#define ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN ((ULONG)0x00002159L)

//
// MessageId: ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER
//
// MessageText:
//
// The source object must be a group or user.
//
#define ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER ((ULONG)0x0000215AL)

//
// MessageId: ERROR_DS_SRC_SID_EXISTS_IN_FOREST
//
// MessageText:
//
// The source object's SID already exists in destination forest.
//
#define ERROR_DS_SRC_SID_EXISTS_IN_FOREST ((ULONG)0x0000215BL)

//
// MessageId: ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH
//
// MessageText:
//
// The source and destination object must be of the same type.
//
#define ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH ((ULONG)0x0000215CL)

//
// MessageId: ERROR_SAM_INIT_FAILURE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.
//
#define ERROR_SAM_INIT_FAILURE           ((ULONG)0x0000215DL)

//
// MessageId: ERROR_DS_DRA_SCHEMA_INFO_SHIP
//
// MessageText:
//
// Schema information could not be included in the replication request.
//
#define ERROR_DS_DRA_SCHEMA_INFO_SHIP    ((ULONG)0x0000215EL)

//
// MessageId: ERROR_DS_DRA_SCHEMA_CONFLICT
//
// MessageText:
//
// The replication operation could not be completed due to a schema incompatibility.
//
#define ERROR_DS_DRA_SCHEMA_CONFLICT     ((ULONG)0x0000215FL)

//
// MessageId: ERROR_DS_DRA_EARLIER_SCHEMA_CONLICT
//
// MessageText:
//
// The replication operation could not be completed due to a previous schema incompatibility.
//
#define ERROR_DS_DRA_EARLIER_SCHEMA_CONLICT ((ULONG)0x00002160L)

//
// MessageId: ERROR_DS_DRA_OBJ_NC_MISMATCH
//
// MessageText:
//
// The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.
//
#define ERROR_DS_DRA_OBJ_NC_MISMATCH     ((ULONG)0x00002161L)

//
// MessageId: ERROR_DS_NC_STILL_HAS_DSAS
//
// MessageText:
//
// The requested domain could not be deleted because there exist domain controllers that still host this domain.
//
#define ERROR_DS_NC_STILL_HAS_DSAS       ((ULONG)0x00002162L)

//
// MessageId: ERROR_DS_GC_REQUIRED
//
// MessageText:
//
// The requested operation can be performed only on a global catalog server.
//
#define ERROR_DS_GC_REQUIRED             ((ULONG)0x00002163L)

//
// MessageId: ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY
//
// MessageText:
//
// A local group can only be a member of other local groups in the same domain.
//
#define ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY ((ULONG)0x00002164L)

//
// MessageId: ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS
//
// MessageText:
//
// Foreign security principals cannot be members of universal groups.
//
#define ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS ((ULONG)0x00002165L)

//
// MessageId: ERROR_DS_CANT_ADD_TO_GC
//
// MessageText:
//
// The attribute is not allowed to be replicated to the GC because of security reasons.
//
#define ERROR_DS_CANT_ADD_TO_GC          ((ULONG)0x00002166L)

//
// MessageId: ERROR_DS_NO_CHECKPOINT_WITH_PDC
//
// MessageText:
//
// The checkpoint with the PDC could not be taken because there are too many modifications being processed currently.
//
#define ERROR_DS_NO_CHECKPOINT_WITH_PDC  ((ULONG)0x00002167L)

//
// MessageId: ERROR_DS_SOURCE_AUDITING_NOT_ENABLED
//
// MessageText:
//
// The operation requires that source domain auditing be enabled.
//
#define ERROR_DS_SOURCE_AUDITING_NOT_ENABLED ((ULONG)0x00002168L)

//
// MessageId: ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC
//
// MessageText:
//
// Security principal objects can only be created inside domain naming contexts.
//
#define ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC ((ULONG)0x00002169L)

//
// MessageId: ERROR_DS_INVALID_NAME_FOR_SPN
//
// MessageText:
//
// A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.
//
#define ERROR_DS_INVALID_NAME_FOR_SPN    ((ULONG)0x0000216AL)

//
// MessageId: ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS
//
// MessageText:
//
// A Filter was passed that uses constructed attributes.
//
#define ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS ((ULONG)0x0000216BL)

//
// MessageId: ERROR_DS_UNICODEPWD_NOT_IN_QUOTES
//
// MessageText:
//
// The unicodePwd attribute value must be enclosed in double quotes.
//
#define ERROR_DS_UNICODEPWD_NOT_IN_QUOTES ((ULONG)0x0000216CL)

//
// MessageId: ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED
//
// MessageText:
//
// Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.
//
#define ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED ((ULONG)0x0000216DL)

//
// MessageId: ERROR_DS_MUST_BE_RUN_ON_DST_DC
//
// MessageText:
//
// For security reasons, the operation must be run on the destination DC.
//
#define ERROR_DS_MUST_BE_RUN_ON_DST_DC   ((ULONG)0x0000216EL)

//
// MessageId: ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER
//
// MessageText:
//
// For security reasons, the source DC must be NT4SP4 or greater.
//
#define ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER ((ULONG)0x0000216FL)

//
// MessageId: ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ
//
// MessageText:
//
// Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.
//
#define ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ ((ULONG)0x00002170L)

//
// MessageId: ERROR_DS_INIT_FAILURE_CONSOLE
//
// MessageText:
//
// Directory Services could not start because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
//
#define ERROR_DS_INIT_FAILURE_CONSOLE    ((ULONG)0x00002171L)

//
// MessageId: ERROR_DS_SAM_INIT_FAILURE_CONSOLE
//
// MessageText:
//
// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
//
#define ERROR_DS_SAM_INIT_FAILURE_CONSOLE ((ULONG)0x00002172L)

//
// MessageId: ERROR_DS_FOREST_VERSION_TOO_HIGH
//
// MessageText:
//
// The version of the operating system installed is incompatible with the current forest functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this forest.
//
#define ERROR_DS_FOREST_VERSION_TOO_HIGH ((ULONG)0x00002173L)

//
// MessageId: ERROR_DS_DOMAIN_VERSION_TOO_HIGH
//
// MessageText:
//
// The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.
//
#define ERROR_DS_DOMAIN_VERSION_TOO_HIGH ((ULONG)0x00002174L)

//
// MessageId: ERROR_DS_FOREST_VERSION_TOO_LOW
//
// MessageText:
//
// This version of the operating system installed on this server no longer supports the current forest functional level. You must raise the forest functional level before this server can become a domain controller in this forest.
//
#define ERROR_DS_FOREST_VERSION_TOO_LOW  ((ULONG)0x00002175L)

//
// MessageId: ERROR_DS_DOMAIN_VERSION_TOO_LOW
//
// MessageText:
//
// This version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.
//
#define ERROR_DS_DOMAIN_VERSION_TOO_LOW  ((ULONG)0x00002176L)

//
// MessageId: ERROR_DS_INCOMPATIBLE_VERSION
//
// MessageText:
//
// The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.
//
#define ERROR_DS_INCOMPATIBLE_VERSION    ((ULONG)0x00002177L)

//
// MessageId: ERROR_DS_LOW_DSA_VERSION
//
// MessageText:
//
// The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.
//
#define ERROR_DS_LOW_DSA_VERSION         ((ULONG)0x00002178L)

//
// MessageId: ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN
//
// MessageText:
//
// The forest functional level cannot be raised to the requested level since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode before you can raise the forest functional level.
//
#define ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN ((ULONG)0x00002179L)

//
// MessageId: ERROR_DS_NOT_SUPPORTED_SORT_ORDER
//
// MessageText:
//
// The sort order requested is not supported.
//
#define ERROR_DS_NOT_SUPPORTED_SORT_ORDER ((ULONG)0x0000217AL)

//
// MessageId: ERROR_DS_NAME_NOT_UNIQUE
//
// MessageText:
//
// The requested name already exists as a unique identifier.
//
#define ERROR_DS_NAME_NOT_UNIQUE         ((ULONG)0x0000217BL)

//
// MessageId: ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4
//
// MessageText:
//
// The machine account was created pre-NT4. The account needs to be recreated.
//
#define ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4 ((ULONG)0x0000217CL)

//
// MessageId: ERROR_DS_OUT_OF_VERSION_STORE
//
// MessageText:
//
// The database is out of version store.
//
#define ERROR_DS_OUT_OF_VERSION_STORE    ((ULONG)0x0000217DL)

//
// MessageId: ERROR_DS_INCOMPATIBLE_CONTROLS_USED
//
// MessageText:
//
// Unable to continue operation because multiple conflicting controls were used.
//
#define ERROR_DS_INCOMPATIBLE_CONTROLS_USED ((ULONG)0x0000217EL)

//
// MessageId: ERROR_DS_NO_REF_DOMAIN
//
// MessageText:
//
// Unable to find a valid security descriptor reference domain for this partition.
//
#define ERROR_DS_NO_REF_DOMAIN           ((ULONG)0x0000217FL)

//
// MessageId: ERROR_DS_RESERVED_LINK_ID
//
// MessageText:
//
// Schema update failed: The link identifier is reserved.
//
#define ERROR_DS_RESERVED_LINK_ID        ((ULONG)0x00002180L)

//
// MessageId: ERROR_DS_LINK_ID_NOT_AVAILABLE
//
// MessageText:
//
// Schema update failed: There are no link identifiers available.
//
#define ERROR_DS_LINK_ID_NOT_AVAILABLE   ((ULONG)0x00002181L)

//
// MessageId: ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER
//
// MessageText:
//
// An account group cannot have a universal group as a member.
//
#define ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER ((ULONG)0x00002182L)

//
// MessageId: ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE
//
// MessageText:
//
// Rename or move operations on naming context heads or read-only objects are not allowed.
//
#define ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE ((ULONG)0x00002183L)

//
// MessageId: ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC
//
// MessageText:
//
// Move operations on objects in the schema naming context are not allowed.
//
#define ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC ((ULONG)0x00002184L)

//
// MessageId: ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG
//
// MessageText:
//
// A system flag has been set on the object and does not allow the object to be moved or renamed.
//
#define ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG ((ULONG)0x00002185L)

//
// MessageId: ERROR_DS_MODIFYDN_WRONG_GRANDPARENT
//
// MessageText:
//
// This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.
//
#define ERROR_DS_MODIFYDN_WRONG_GRANDPARENT ((ULONG)0x00002186L)

//
// MessageId: ERROR_DS_NAME_ERROR_TRUST_REFERRAL
//
// MessageText:
//
// Unable to resolve completely, a referral to another forest is generated.
//
#define ERROR_DS_NAME_ERROR_TRUST_REFERRAL ((ULONG)0x00002187L)

//
// MessageId: ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER
//
// MessageText:
//
// The requested action is not supported on standard server.
//
#define ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER ((ULONG)0x00002188L)

//
// MessageId: ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD
//
// MessageText:
//
// Could not access a partition of the Active Directory located on a remote server. Make sure at least one server is running for the partition in question.
//
#define ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD ((ULONG)0x00002189L)

//
// MessageId: ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2
//
// MessageText:
//
// The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.
//
#define ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 ((ULONG)0x0000218AL)

//
// MessageId: ERROR_DS_THREAD_LIMIT_EXCEEDED
//
// MessageText:
//
// The thread limit for this request was exceeded.
//
#define ERROR_DS_THREAD_LIMIT_EXCEEDED   ((ULONG)0x0000218BL)

//
// MessageId: ERROR_DS_NOT_CLOSEST
//
// MessageText:
//
// The Global catalog server is not in the closet site.
//
#define ERROR_DS_NOT_CLOSEST             ((ULONG)0x0000218CL)

//
// MessageId: ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF
//
// MessageText:
//
// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.
//
#define ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF ((ULONG)0x0000218DL)

//
// MessageId: ERROR_DS_SINGLE_USER_MODE_FAILED
//
// MessageText:
//
// The Directory Service failed to enter single user mode.
//
#define ERROR_DS_SINGLE_USER_MODE_FAILED ((ULONG)0x0000218EL)

//
// MessageId: ERROR_DS_NTDSCRIPT_SYNTAX_ERROR
//
// MessageText:
//
// The Directory Service cannot parse the script because of a syntax error.
//
#define ERROR_DS_NTDSCRIPT_SYNTAX_ERROR  ((ULONG)0x0000218FL)

//
// MessageId: ERROR_DS_NTDSCRIPT_PROCESS_ERROR
//
// MessageText:
//
// The Directory Service cannot process the script because of an error.
//
#define ERROR_DS_NTDSCRIPT_PROCESS_ERROR ((ULONG)0x00002190L)

//
// MessageId: ERROR_DS_DIFFERENT_REPL_EPOCHS
//
// MessageText:
//
// The directory service cannot perform the requested operation because the servers involved are of different replication epochs (which is usually related to a domain rename that is in progress).
//
#define ERROR_DS_DIFFERENT_REPL_EPOCHS   ((ULONG)0x00002191L)

//
// MessageId: ERROR_DS_DRS_EXTENSIONS_CHANGED
//
// MessageText:
//
// The directory service binding must be renegotiated due to a change in the server extensions information.
//
#define ERROR_DS_DRS_EXTENSIONS_CHANGED  ((ULONG)0x00002192L)

//
// MessageId: ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR
//
// MessageText:
//
// Operation not allowed on a disabled cross ref.
//
#define ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR ((ULONG)0x00002193L)

//
// MessageId: ERROR_DS_NO_MSDS_INTID
//
// MessageText:
//
// Schema update failed: No values for msDS-IntId are available.
//
#define ERROR_DS_NO_MSDS_INTID           ((ULONG)0x00002194L)

//
// MessageId: ERROR_DS_DUP_MSDS_INTID
//
// MessageText:
//
// Schema update failed: Duplicate msDS-IntId. Retry the operation.
//
#define ERROR_DS_DUP_MSDS_INTID          ((ULONG)0x00002195L)

//
// MessageId: ERROR_DS_EXISTS_IN_RDNATTID
//
// MessageText:
//
// Schema deletion failed: attribute is used in rDNAttID.
//
#define ERROR_DS_EXISTS_IN_RDNATTID      ((ULONG)0x00002196L)

//
// MessageId: ERROR_DS_AUTHORIZATION_FAILED
//
// MessageText:
//
// The directory service failed to authorize the request.
//
#define ERROR_DS_AUTHORIZATION_FAILED    ((ULONG)0x00002197L)

//
// MessageId: ERROR_DS_INVALID_SCRIPT
//
// MessageText:
//
// The Directory Service cannot process the script because it is invalid.
//
#define ERROR_DS_INVALID_SCRIPT          ((ULONG)0x00002198L)

//
// MessageId: ERROR_DS_REMOTE_CROSSREF_OP_FAILED
//
// MessageText:
//
// The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.
//
#define ERROR_DS_REMOTE_CROSSREF_OP_FAILED ((ULONG)0x00002199L)

//
// MessageId: ERROR_DS_CROSS_REF_BUSY
//
// MessageText:
//
// A cross reference is in use locally with the same name.
//
#define ERROR_DS_CROSS_REF_BUSY          ((ULONG)0x0000219AL)

//
// MessageId: ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN
//
// MessageText:
//
// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.
//
#define ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN ((ULONG)0x0000219BL)

//
// MessageId: ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC
//
// MessageText:
//
// Writeable NCs prevent this DC from demoting.
//
#define ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC ((ULONG)0x0000219CL)

//
// MessageId: ERROR_DS_DUPLICATE_ID_FOUND
//
// MessageText:
//
// The requested object has a non-unique identifier and cannot be retrieved.
//
#define ERROR_DS_DUPLICATE_ID_FOUND      ((ULONG)0x0000219DL)

//
// MessageId: ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT
//
// MessageText:
//
// Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.
//
#define ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT ((ULONG)0x0000219EL)

//
// MessageId: ERROR_DS_GROUP_CONVERSION_ERROR
//
// MessageText:
//
// The group cannot be converted due to attribute restrictions on the requested group type.
//
#define ERROR_DS_GROUP_CONVERSION_ERROR  ((ULONG)0x0000219FL)

//
// MessageId: ERROR_DS_CANT_MOVE_APP_BASIC_GROUP
//
// MessageText:
//
// Cross-domain move of non-empty basic application groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_APP_BASIC_GROUP ((ULONG)0x000021A0L)

//
// MessageId: ERROR_DS_CANT_MOVE_APP_QUERY_GROUP
//
// MessageText:
//
// Cross-domain move on non-empty query based application groups is not allowed.
//
#define ERROR_DS_CANT_MOVE_APP_QUERY_GROUP ((ULONG)0x000021A1L)

//
// MessageId: ERROR_DS_ROLE_NOT_VERIFIED
//
// MessageText:
//
// The role owner could not be verified because replication of its partition has not occurred recently.
//
#define ERROR_DS_ROLE_NOT_VERIFIED       ((ULONG)0x000021A2L)

//
// MessageId: ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL
//
// MessageText:
//
// The target container for a redirection of a well-known object container cannot already be a special container.
//
#define ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL ((ULONG)0x000021A3L)

//
// MessageId: ERROR_DS_DOMAIN_RENAME_IN_PROGRESS
//
// MessageText:
//
// The Directory Service cannot perform the requested operation because a domain rename operation is in progress.
//
#define ERROR_DS_DOMAIN_RENAME_IN_PROGRESS ((ULONG)0x000021A4L)

//
// MessageId: ERROR_DS_EXISTING_AD_CHILD_NC
//
// MessageText:
//
// The Active Directory detected an Active Directory child partition below the requested new partition name. The Active Directory's partition hierarchy must be created in a top-down method.
//
#define ERROR_DS_EXISTING_AD_CHILD_NC    ((ULONG)0x000021A5L)

//
// MessageId: ERROR_DS_REPL_LIFETIME_EXCEEDED
//
// MessageText:
//
// The Active Directory cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.
//
#define ERROR_DS_REPL_LIFETIME_EXCEEDED  ((ULONG)0x000021A6L)

//
// MessageId: ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER
//
// MessageText:
//
// The requested operation is not allowed on an object under the system container.
//
#define ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER ((ULONG)0x000021A7L)

//
// MessageId: ERROR_DS_LDAP_SEND_QUEUE_FULL
//
// MessageText:
//
// The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.
//
#define ERROR_DS_LDAP_SEND_QUEUE_FULL    ((ULONG)0x000021A8L)

//
// MessageId: ERROR_DS_DRA_OUT_SCHEDULE_WINDOW
//
// MessageText:
//
// The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.
//
#define ERROR_DS_DRA_OUT_SCHEDULE_WINDOW ((ULONG)0x000021A9L)

//
// MessageId: DNS_ERROR_RCODE_FORMAT_ERROR
//
// MessageText:
//
// DNS server unable to interpret format.
//
#define DNS_ERROR_RCODE_FORMAT_ERROR     ((ULONG)0x00002329L)

//
// MessageId: DNS_ERROR_RCODE_SERVER_FAILURE
//
// MessageText:
//
// DNS server failure.
//
#define DNS_ERROR_RCODE_SERVER_FAILURE   ((ULONG)0x0000232AL)

//
// MessageId: DNS_ERROR_RCODE_NAME_ERROR
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_RCODE_NAME_ERROR       ((ULONG)0x0000232BL)

//
// MessageId: DNS_ERROR_RCODE_NOT_IMPLEMENTED
//
// MessageText:
//
// DNS request not supported by name server.
//
#define DNS_ERROR_RCODE_NOT_IMPLEMENTED  ((ULONG)0x0000232CL)

//
// MessageId: DNS_ERROR_RCODE_REFUSED
//
// MessageText:
//
// DNS operation refused.
//
#define DNS_ERROR_RCODE_REFUSED          ((ULONG)0x0000232DL)

//
// MessageId: DNS_ERROR_RCODE_YXDOMAIN
//
// MessageText:
//
// DNS name that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXDOMAIN         ((ULONG)0x0000232EL)

//
// MessageId: DNS_ERROR_RCODE_YXRRSET
//
// MessageText:
//
// DNS RR set that ought not exist, does exist.
//
#define DNS_ERROR_RCODE_YXRRSET          ((ULONG)0x0000232FL)

//
// MessageId: DNS_ERROR_RCODE_NXRRSET
//
// MessageText:
//
// DNS RR set that ought to exist, does not exist.
//
#define DNS_ERROR_RCODE_NXRRSET          ((ULONG)0x00002330L)

//
// MessageId: DNS_ERROR_RCODE_NOTAUTH
//
// MessageText:
//
// DNS server not authoritative for zone.
//
#define DNS_ERROR_RCODE_NOTAUTH          ((ULONG)0x00002331L)

//
// MessageId: DNS_ERROR_RCODE_NOTZONE
//
// MessageText:
//
// DNS name in update or prereq is not in zone.
//
#define DNS_ERROR_RCODE_NOTZONE          ((ULONG)0x00002332L)

//
// MessageId: DNS_ERROR_RCODE_BADSIG
//
// MessageText:
//
// DNS signature failed to verify.
//
#define DNS_ERROR_RCODE_BADSIG           ((ULONG)0x00002338L)

//
// MessageId: DNS_ERROR_RCODE_BADKEY
//
// MessageText:
//
// DNS bad key.
//
#define DNS_ERROR_RCODE_BADKEY           ((ULONG)0x00002339L)

//
// MessageId: DNS_ERROR_RCODE_BADTIME
//
// MessageText:
//
// DNS signature validity expired.
//
#define DNS_ERROR_RCODE_BADTIME          ((ULONG)0x0000233AL)

//
// MessageId: DNS_INFO_NO_RECORDS
//
// MessageText:
//
// No records found for given DNS query.
//
#define DNS_INFO_NO_RECORDS              ((ULONG)0x0000251DL)

//
// MessageId: DNS_ERROR_BAD_PACKET
//
// MessageText:
//
// Bad DNS packet.
//
#define DNS_ERROR_BAD_PACKET             ((ULONG)0x0000251EL)

//
// MessageId: DNS_ERROR_NO_PACKET
//
// MessageText:
//
// No DNS packet.
//
#define DNS_ERROR_NO_PACKET              ((ULONG)0x0000251FL)

//
// MessageId: DNS_ERROR_RCODE
//
// MessageText:
//
// DNS error, check rcode.
//
#define DNS_ERROR_RCODE                  ((ULONG)0x00002520L)

//
// MessageId: DNS_ERROR_UNSECURE_PACKET
//
// MessageText:
//
// Unsecured DNS packet.
//
#define DNS_ERROR_UNSECURE_PACKET        ((ULONG)0x00002521L)

//
// MessageId: DNS_ERROR_INVALID_TYPE
//
// MessageText:
//
// Invalid DNS type.
//
#define DNS_ERROR_INVALID_TYPE           ((ULONG)0x0000254FL)

//
// MessageId: DNS_ERROR_INVALID_IP_ADDRESS
//
// MessageText:
//
// Invalid IP address.
//
#define DNS_ERROR_INVALID_IP_ADDRESS     ((ULONG)0x00002550L)

//
// MessageId: DNS_ERROR_INVALID_PROPERTY
//
// MessageText:
//
// Invalid property.
//
#define DNS_ERROR_INVALID_PROPERTY       ((ULONG)0x00002551L)

//
// MessageId: DNS_ERROR_TRY_AGAIN_LATER
//
// MessageText:
//
// Try DNS operation again later.
//
#define DNS_ERROR_TRY_AGAIN_LATER        ((ULONG)0x00002552L)

//
// MessageId: DNS_ERROR_NOT_UNIQUE
//
// MessageText:
//
// Record for given name and type is not unique.
//
#define DNS_ERROR_NOT_UNIQUE             ((ULONG)0x00002553L)

//
// MessageId: DNS_ERROR_NON_RFC_NAME
//
// MessageText:
//
// DNS name does not comply with RFC specifications.
//
#define DNS_ERROR_NON_RFC_NAME           ((ULONG)0x00002554L)

//
// MessageId: DNS_STATUS_FQDN
//
// MessageText:
//
// DNS name is a fully-qualified DNS name.
//
#define DNS_STATUS_FQDN                  ((ULONG)0x00002555L)

//
// MessageId: DNS_STATUS_DOTTED_NAME
//
// MessageText:
//
// DNS name is dotted (multi-label).
//
#define DNS_STATUS_DOTTED_NAME           ((ULONG)0x00002556L)

//
// MessageId: DNS_STATUS_SINGLE_PART_NAME
//
// MessageText:
//
// DNS name is a single-part name.
//
#define DNS_STATUS_SINGLE_PART_NAME      ((ULONG)0x00002557L)

//
// MessageId: DNS_ERROR_INVALID_NAME_CHAR
//
// MessageText:
//
// DSN name contains an invalid character.
//
#define DNS_ERROR_INVALID_NAME_CHAR      ((ULONG)0x00002558L)

//
// MessageId: DNS_ERROR_NUMERIC_NAME
//
// MessageText:
//
// DNS name is entirely numeric.
//
#define DNS_ERROR_NUMERIC_NAME           ((ULONG)0x00002559L)

//
// MessageId: DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER
//
// MessageText:
//
// The operation requested is not permitted on a DNS root server.
//
#define DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER ((ULONG)0x0000255AL)

//
// MessageId: DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION
//
// MessageText:
//
// The record could not be created because this part of the DNS namespace has been delegated to another server.
//
#define DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION ((ULONG)0x0000255BL)

//
// MessageId: DNS_ERROR_CANNOT_FIND_ROOT_HINTS
//
// MessageText:
//
// The DNS server could not find a set of root hints.
//
#define DNS_ERROR_CANNOT_FIND_ROOT_HINTS ((ULONG)0x0000255CL)

//
// MessageId: DNS_ERROR_INCONSISTENT_ROOT_HINTS
//
// MessageText:
//
// The DNS server found root hints but they were not consistent across all adapters.
//
#define DNS_ERROR_INCONSISTENT_ROOT_HINTS ((ULONG)0x0000255DL)

//
// MessageId: DNS_ERROR_ZONE_DOES_NOT_EXIST
//
// MessageText:
//
// DNS zone does not exist.
//
#define DNS_ERROR_ZONE_DOES_NOT_EXIST    ((ULONG)0x00002581L)

//
// MessageId: DNS_ERROR_NO_ZONE_INFO
//
// MessageText:
//
// DNS zone information not available.
//
#define DNS_ERROR_NO_ZONE_INFO           ((ULONG)0x00002582L)

//
// MessageId: DNS_ERROR_INVALID_ZONE_OPERATION
//
// MessageText:
//
// Invalid operation for DNS zone.
//
#define DNS_ERROR_INVALID_ZONE_OPERATION ((ULONG)0x00002583L)

//
// MessageId: DNS_ERROR_ZONE_CONFIGURATION_ERROR
//
// MessageText:
//
// Invalid DNS zone configuration.
//
#define DNS_ERROR_ZONE_CONFIGURATION_ERROR ((ULONG)0x00002584L)

//
// MessageId: DNS_ERROR_ZONE_HAS_NO_SOA_RECORD
//
// MessageText:
//
// DNS zone has no start of authority (SOA) record.
//
#define DNS_ERROR_ZONE_HAS_NO_SOA_RECORD ((ULONG)0x00002585L)

//
// MessageId: DNS_ERROR_ZONE_HAS_NO_NS_RECORDS
//
// MessageText:
//
// DNS zone has no name server (NS) record.
//
#define DNS_ERROR_ZONE_HAS_NO_NS_RECORDS ((ULONG)0x00002586L)

//
// MessageId: DNS_ERROR_ZONE_LOCKED
//
// MessageText:
//
// DNS zone is locked.
//
#define DNS_ERROR_ZONE_LOCKED            ((ULONG)0x00002587L)

//
// MessageId: DNS_ERROR_ZONE_CREATION_FAILED
//
// MessageText:
//
// DNS zone creation failed.
//
#define DNS_ERROR_ZONE_CREATION_FAILED   ((ULONG)0x00002588L)

//
// MessageId: DNS_ERROR_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists.
//
#define DNS_ERROR_ZONE_ALREADY_EXISTS    ((ULONG)0x00002589L)

//
// MessageId: DNS_ERROR_AUTOZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS automatic zone already exists.
//
#define DNS_ERROR_AUTOZONE_ALREADY_EXISTS ((ULONG)0x0000258AL)

//
// MessageId: DNS_ERROR_INVALID_ZONE_TYPE
//
// MessageText:
//
// Invalid DNS zone type.
//
#define DNS_ERROR_INVALID_ZONE_TYPE      ((ULONG)0x0000258BL)

//
// MessageId: DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP
//
// MessageText:
//
// Secondary DNS zone requires master IP address.
//
#define DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP ((ULONG)0x0000258CL)

//
// MessageId: DNS_ERROR_ZONE_NOT_SECONDARY
//
// MessageText:
//
// DNS zone not secondary.
//
#define DNS_ERROR_ZONE_NOT_SECONDARY     ((ULONG)0x0000258DL)

//
// MessageId: DNS_ERROR_NEED_SECONDARY_ADDRESSES
//
// MessageText:
//
// Need secondary IP address.
//
#define DNS_ERROR_NEED_SECONDARY_ADDRESSES ((ULONG)0x0000258EL)

//
// MessageId: DNS_ERROR_WINS_INIT_FAILED
//
// MessageText:
//
// WINS initialization failed.
//
#define DNS_ERROR_WINS_INIT_FAILED       ((ULONG)0x0000258FL)

//
// MessageId: DNS_ERROR_NEED_WINS_SERVERS
//
// MessageText:
//
// Need WINS servers.
//
#define DNS_ERROR_NEED_WINS_SERVERS      ((ULONG)0x00002590L)

//
// MessageId: DNS_ERROR_NBSTAT_INIT_FAILED
//
// MessageText:
//
// NBTSTAT initialization call failed.
//
#define DNS_ERROR_NBSTAT_INIT_FAILED     ((ULONG)0x00002591L)

//
// MessageId: DNS_ERROR_SOA_DELETE_INVALID
//
// MessageText:
//
// Invalid delete of start of authority (SOA)
//
#define DNS_ERROR_SOA_DELETE_INVALID     ((ULONG)0x00002592L)

//
// MessageId: DNS_ERROR_FORWARDER_ALREADY_EXISTS
//
// MessageText:
//
// A conditional forwarding zone already exists for that name.
//
#define DNS_ERROR_FORWARDER_ALREADY_EXISTS ((ULONG)0x00002593L)

//
// MessageId: DNS_ERROR_ZONE_REQUIRES_MASTER_IP
//
// MessageText:
//
// This zone must be configured with one or more master DNS server IP addresses.
//
#define DNS_ERROR_ZONE_REQUIRES_MASTER_IP ((ULONG)0x00002594L)

//
// MessageId: DNS_ERROR_ZONE_IS_SHUTDOWN
//
// MessageText:
//
// The operation cannot be performed because this zone is shutdown.
//
#define DNS_ERROR_ZONE_IS_SHUTDOWN       ((ULONG)0x00002595L)

//
// MessageId: DNS_ERROR_PRIMARY_REQUIRES_DATAFILE
//
// MessageText:
//
// Primary DNS zone requires datafile.
//
#define DNS_ERROR_PRIMARY_REQUIRES_DATAFILE ((ULONG)0x000025B3L)

//
// MessageId: DNS_ERROR_INVALID_DATAFILE_NAME
//
// MessageText:
//
// Invalid datafile name for DNS zone.
//
#define DNS_ERROR_INVALID_DATAFILE_NAME  ((ULONG)0x000025B4L)

//
// MessageId: DNS_ERROR_DATAFILE_OPEN_FAILURE
//
// MessageText:
//
// Failed to open datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_OPEN_FAILURE  ((ULONG)0x000025B5L)

//
// MessageId: DNS_ERROR_FILE_WRITEBACK_FAILED
//
// MessageText:
//
// Failed to write datafile for DNS zone.
//
#define DNS_ERROR_FILE_WRITEBACK_FAILED  ((ULONG)0x000025B6L)

//
// MessageId: DNS_ERROR_DATAFILE_PARSING
//
// MessageText:
//
// Failure while reading datafile for DNS zone.
//
#define DNS_ERROR_DATAFILE_PARSING       ((ULONG)0x000025B7L)

//
// MessageId: DNS_ERROR_RECORD_DOES_NOT_EXIST
//
// MessageText:
//
// DNS record does not exist.
//
#define DNS_ERROR_RECORD_DOES_NOT_EXIST  ((ULONG)0x000025E5L)

//
// MessageId: DNS_ERROR_RECORD_FORMAT
//
// MessageText:
//
// DNS record format error.
//
#define DNS_ERROR_RECORD_FORMAT          ((ULONG)0x000025E6L)

//
// MessageId: DNS_ERROR_NODE_CREATION_FAILED
//
// MessageText:
//
// Node creation failure in DNS.
//
#define DNS_ERROR_NODE_CREATION_FAILED   ((ULONG)0x000025E7L)

//
// MessageId: DNS_ERROR_UNKNOWN_RECORD_TYPE
//
// MessageText:
//
// Unknown DNS record type.
//
#define DNS_ERROR_UNKNOWN_RECORD_TYPE    ((ULONG)0x000025E8L)

//
// MessageId: DNS_ERROR_RECORD_TIMED_OUT
//
// MessageText:
//
// DNS record timed out.
//
#define DNS_ERROR_RECORD_TIMED_OUT       ((ULONG)0x000025E9L)

//
// MessageId: DNS_ERROR_NAME_NOT_IN_ZONE
//
// MessageText:
//
// Name not in DNS zone.
//
#define DNS_ERROR_NAME_NOT_IN_ZONE       ((ULONG)0x000025EAL)

//
// MessageId: DNS_ERROR_CNAME_LOOP
//
// MessageText:
//
// CNAME loop detected.
//
#define DNS_ERROR_CNAME_LOOP             ((ULONG)0x000025EBL)

//
// MessageId: DNS_ERROR_NODE_IS_CNAME
//
// MessageText:
//
// Node is a CNAME DNS record.
//
#define DNS_ERROR_NODE_IS_CNAME          ((ULONG)0x000025ECL)

//
// MessageId: DNS_ERROR_CNAME_COLLISION
//
// MessageText:
//
// A CNAME record already exists for given name.
//
#define DNS_ERROR_CNAME_COLLISION        ((ULONG)0x000025EDL)

//
// MessageId: DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT
//
// MessageText:
//
// Record only at DNS zone root.
//
#define DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT ((ULONG)0x000025EEL)

//
// MessageId: DNS_ERROR_RECORD_ALREADY_EXISTS
//
// MessageText:
//
// DNS record already exists.
//
#define DNS_ERROR_RECORD_ALREADY_EXISTS  ((ULONG)0x000025EFL)

//
// MessageId: DNS_ERROR_SECONDARY_DATA
//
// MessageText:
//
// Secondary DNS zone data error.
//
#define DNS_ERROR_SECONDARY_DATA         ((ULONG)0x000025F0L)

//
// MessageId: DNS_ERROR_NO_CREATE_CACHE_DATA
//
// MessageText:
//
// Could not create DNS cache data.
//
#define DNS_ERROR_NO_CREATE_CACHE_DATA   ((ULONG)0x000025F1L)

//
// MessageId: DNS_ERROR_NAME_DOES_NOT_EXIST
//
// MessageText:
//
// DNS name does not exist.
//
#define DNS_ERROR_NAME_DOES_NOT_EXIST    ((ULONG)0x000025F2L)

//
// MessageId: DNS_WARNING_PTR_CREATE_FAILED
//
// MessageText:
//
// Could not create pointer (PTR) record.
//
#define DNS_WARNING_PTR_CREATE_FAILED    ((ULONG)0x000025F3L)

//
// MessageId: DNS_WARNING_DOMAIN_UNDELETED
//
// MessageText:
//
// DNS domain was undeleted.
//
#define DNS_WARNING_DOMAIN_UNDELETED     ((ULONG)0x000025F4L)

//
// MessageId: DNS_ERROR_DS_UNAVAILABLE
//
// MessageText:
//
// The directory service is unavailable.
//
#define DNS_ERROR_DS_UNAVAILABLE         ((ULONG)0x000025F5L)

//
// MessageId: DNS_ERROR_DS_ZONE_ALREADY_EXISTS
//
// MessageText:
//
// DNS zone already exists in the directory service.
//
#define DNS_ERROR_DS_ZONE_ALREADY_EXISTS ((ULONG)0x000025F6L)

//
// MessageId: DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE
//
// MessageText:
//
// DNS server not creating or reading the boot file for the directory service integrated DNS zone.
//
#define DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE ((ULONG)0x000025F7L)

//
// MessageId: DNS_INFO_AXFR_COMPLETE
//
// MessageText:
//
// DNS AXFR (zone transfer) complete.
//
#define DNS_INFO_AXFR_COMPLETE           ((ULONG)0x00002617L)

//
// MessageId: DNS_ERROR_AXFR
//
// MessageText:
//
// DNS zone transfer failed.
//
#define DNS_ERROR_AXFR                   ((ULONG)0x00002618L)

//
// MessageId: DNS_INFO_ADDED_LOCAL_WINS
//
// MessageText:
//
// Added local WINS server.
//
#define DNS_INFO_ADDED_LOCAL_WINS        ((ULONG)0x00002619L)

//
// MessageId: DNS_STATUS_CONTINUE_NEEDED
//
// MessageText:
//
// Secure update call needs to continue update request.
//
#define DNS_STATUS_CONTINUE_NEEDED       ((ULONG)0x00002649L)

//
// MessageId: DNS_ERROR_NO_TCPIP
//
// MessageText:
//
// TCP/IP network protocol not installed.
//
#define DNS_ERROR_NO_TCPIP               ((ULONG)0x0000267BL)

//
// MessageId: DNS_ERROR_NO_DNS_SERVERS
//
// MessageText:
//
// No DNS servers configured for local system.
//
#define DNS_ERROR_NO_DNS_SERVERS         ((ULONG)0x0000267CL)

//
// MessageId: DNS_ERROR_DP_DOES_NOT_EXIST
//
// MessageText:
//
// The specified directory partition does not exist.
//
#define DNS_ERROR_DP_DOES_NOT_EXIST      ((ULONG)0x000026ADL)

//
// MessageId: DNS_ERROR_DP_ALREADY_EXISTS
//
// MessageText:
//
// The specified directory partition already exists.
//
#define DNS_ERROR_DP_ALREADY_EXISTS      ((ULONG)0x000026AEL)

//
// MessageId: DNS_ERROR_DP_NOT_ENLISTED
//
// MessageText:
//
// The DNS server is not enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_NOT_ENLISTED        ((ULONG)0x000026AFL)

//
// MessageId: DNS_ERROR_DP_ALREADY_ENLISTED
//
// MessageText:
//
// The DNS server is already enlisted in the specified directory partition.
//
#define DNS_ERROR_DP_ALREADY_ENLISTED    ((ULONG)0x000026B0L)

//
// MessageId: DNS_ERROR_DP_NOT_AVAILABLE
//
// MessageText:
//
// The directory partition is not available at this time. Please wait a few minutes and try again.
//
#define DNS_ERROR_DP_NOT_AVAILABLE       ((ULONG)0x000026B1L)

//
// MessageId: DNS_ERROR_DP_FSMO_ERROR
//
// MessageText:
//
// The application directory partition operation failed. The domain controller holding the domain naming master role is down or unable to service the request or is not running Windows Server 2003.
//
#define DNS_ERROR_DP_FSMO_ERROR          ((ULONG)0x000026B2L)

//
// MessageId: WSAEINTR
//
// MessageText:
//
// A blocking operation was interrupted by a call to WSACancelBlockingCall.
//
#define WSAEINTR                         ((ULONG)0x00002714L)

//
// MessageId: WSAEBADF
//
// MessageText:
//
// The file handle supplied is not valid.
//
#define WSAEBADF                         ((ULONG)0x00002719L)

//
// MessageId: WSAEACCES
//
// MessageText:
//
// An attempt was made to access a socket in a way forbidden by its access permissions.
//
#define WSAEACCES                        ((ULONG)0x0000271DL)

//
// MessageId: WSAEFAULT
//
// MessageText:
//
// The system detected an invalid pointer address in attempting to use a pointer argument in a call.
//
#define WSAEFAULT                        ((ULONG)0x0000271EL)

//
// MessageId: WSAEINVAL
//
// MessageText:
//
// An invalid argument was supplied.
//
#define WSAEINVAL                        ((ULONG)0x00002726L)

//
// MessageId: WSAEMFILE
//
// MessageText:
//
// Too many open sockets.
//
#define WSAEMFILE                        ((ULONG)0x00002728L)

//
// MessageId: WSAEWOULDBLOCK
//
// MessageText:
//
// A non-blocking socket operation could not be completed immediately.
//
#define WSAEWOULDBLOCK                   ((ULONG)0x00002733L)

//
// MessageId: WSAEINPROGRESS
//
// MessageText:
//
// A blocking operation is currently executing.
//
#define WSAEINPROGRESS                   ((ULONG)0x00002734L)

//
// MessageId: WSAEALREADY
//
// MessageText:
//
// An operation was attempted on a non-blocking socket that already had an operation in progress.
//
#define WSAEALREADY                      ((ULONG)0x00002735L)

//
// MessageId: WSAENOTSOCK
//
// MessageText:
//
// An operation was attempted on something that is not a socket.
//
#define WSAENOTSOCK                      ((ULONG)0x00002736L)

//
// MessageId: WSAEDESTADDRREQ
//
// MessageText:
//
// A required address was omitted from an operation on a socket.
//
#define WSAEDESTADDRREQ                  ((ULONG)0x00002737L)

//
// MessageId: WSAEMSGSIZE
//
// MessageText:
//
// A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.
//
#define WSAEMSGSIZE                      ((ULONG)0x00002738L)

//
// MessageId: WSAEPROTOTYPE
//
// MessageText:
//
// A protocol was specified in the socket function call that does not support the semantics of the socket type requested.
//
#define WSAEPROTOTYPE                    ((ULONG)0x00002739L)

//
// MessageId: WSAENOPROTOOPT
//
// MessageText:
//
// An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.
//
#define WSAENOPROTOOPT                   ((ULONG)0x0000273AL)

//
// MessageId: WSAEPROTONOSUPPORT
//
// MessageText:
//
// The requested protocol has not been configured into the system, or no implementation for it exists.
//
#define WSAEPROTONOSUPPORT               ((ULONG)0x0000273BL)

//
// MessageId: WSAESOCKTNOSUPPORT
//
// MessageText:
//
// The support for the specified socket type does not exist in this address family.
//
#define WSAESOCKTNOSUPPORT               ((ULONG)0x0000273CL)

//
// MessageId: WSAEOPNOTSUPP
//
// MessageText:
//
// The attempted operation is not supported for the type of object referenced.
//
#define WSAEOPNOTSUPP                    ((ULONG)0x0000273DL)

//
// MessageId: WSAEPFNOSUPPORT
//
// MessageText:
//
// The protocol family has not been configured into the system or no implementation for it exists.
//
#define WSAEPFNOSUPPORT                  ((ULONG)0x0000273EL)

//
// MessageId: WSAEAFNOSUPPORT
//
// MessageText:
//
// An address incompatible with the requested protocol was used.
//
#define WSAEAFNOSUPPORT                  ((ULONG)0x0000273FL)

//
// MessageId: WSAEADDRINUSE
//
// MessageText:
//
// Only one usage of each socket address (protocol/network address/port) is normally permitted.
//
#define WSAEADDRINUSE                    ((ULONG)0x00002740L)

//
// MessageId: WSAEADDRNOTAVAIL
//
// MessageText:
//
// The requested address is not valid in its context.
//
#define WSAEADDRNOTAVAIL                 ((ULONG)0x00002741L)

//
// MessageId: WSAENETDOWN
//
// MessageText:
//
// A socket operation encountered a dead network.
//
#define WSAENETDOWN                      ((ULONG)0x00002742L)

//
// MessageId: WSAENETUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable network.
//
#define WSAENETUNREACH                   ((ULONG)0x00002743L)

//
// MessageId: WSAENETRESET
//
// MessageText:
//
// The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.
//
#define WSAENETRESET                     ((ULONG)0x00002744L)

//
// MessageId: WSAECONNABORTED
//
// MessageText:
//
// An established connection was aborted by the software in your host machine.
//
#define WSAECONNABORTED                  ((ULONG)0x00002745L)

//
// MessageId: WSAECONNRESET
//
// MessageText:
//
// An existing connection was forcibly closed by the remote host.
//
#define WSAECONNRESET                    ((ULONG)0x00002746L)

//
// MessageId: WSAENOBUFS
//
// MessageText:
//
// An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
//
#define WSAENOBUFS                       ((ULONG)0x00002747L)

//
// MessageId: WSAEISCONN
//
// MessageText:
//
// A connect request was made on an already connected socket.
//
#define WSAEISCONN                       ((ULONG)0x00002748L)

//
// MessageId: WSAENOTCONN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.
//
#define WSAENOTCONN                      ((ULONG)0x00002749L)

//
// MessageId: WSAESHUTDOWN
//
// MessageText:
//
// A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.
//
#define WSAESHUTDOWN                     ((ULONG)0x0000274AL)

//
// MessageId: WSAETOOMANYREFS
//
// MessageText:
//
// Too many references to some kernel object.
//
#define WSAETOOMANYREFS                  ((ULONG)0x0000274BL)

//
// MessageId: WSAETIMEDOUT
//
// MessageText:
//
// A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
//
#define WSAETIMEDOUT                     ((ULONG)0x0000274CL)

//
// MessageId: WSAECONNREFUSED
//
// MessageText:
//
// No connection could be made because the target machine actively refused it.
//
#define WSAECONNREFUSED                  ((ULONG)0x0000274DL)

//
// MessageId: WSAELOOP
//
// MessageText:
//
// Cannot translate name.
//
#define WSAELOOP                         ((ULONG)0x0000274EL)

//
// MessageId: WSAENAMETOOLONG
//
// MessageText:
//
// Name component or name was too long.
//
#define WSAENAMETOOLONG                  ((ULONG)0x0000274FL)

//
// MessageId: WSAEHOSTDOWN
//
// MessageText:
//
// A socket operation failed because the destination host was down.
//
#define WSAEHOSTDOWN                     ((ULONG)0x00002750L)

//
// MessageId: WSAEHOSTUNREACH
//
// MessageText:
//
// A socket operation was attempted to an unreachable host.
//
#define WSAEHOSTUNREACH                  ((ULONG)0x00002751L)

//
// MessageId: WSAENOTEMPTY
//
// MessageText:
//
// Cannot remove a directory that is not empty.
//
#define WSAENOTEMPTY                     ((ULONG)0x00002752L)

//
// MessageId: WSAEPROCLIM
//
// MessageText:
//
// A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.
//
#define WSAEPROCLIM                      ((ULONG)0x00002753L)

//
// MessageId: WSAEUSERS
//
// MessageText:
//
// Ran out of quota.
//
#define WSAEUSERS                        ((ULONG)0x00002754L)

//
// MessageId: WSAEDQUOT
//
// MessageText:
//
// Ran out of disk quota.
//
#define WSAEDQUOT                        ((ULONG)0x00002755L)

//
// MessageId: WSAESTALE
//
// MessageText:
//
// File handle reference is no longer available.
//
#define WSAESTALE                        ((ULONG)0x00002756L)

//
// MessageId: WSAEREMOTE
//
// MessageText:
//
// Item is not available locally.
//
#define WSAEREMOTE                       ((ULONG)0x00002757L)

//
// MessageId: WSASYSNOTREADY
//
// MessageText:
//
// WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.
//
#define WSASYSNOTREADY                   ((ULONG)0x0000276BL)

//
// MessageId: WSAVERNOTSUPPORTED
//
// MessageText:
//
// The Windows Sockets version requested is not supported.
//
#define WSAVERNOTSUPPORTED               ((ULONG)0x0000276CL)

//
// MessageId: WSANOTINITIALISED
//
// MessageText:
//
// Either the application has not called WSAStartup, or WSAStartup failed.
//
#define WSANOTINITIALISED                ((ULONG)0x0000276DL)

//
// MessageId: WSAEDISCON
//
// MessageText:
//
// Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.
//
#define WSAEDISCON                       ((ULONG)0x00002775L)

//
// MessageId: WSAENOMORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSAENOMORE                       ((ULONG)0x00002776L)

//
// MessageId: WSAECANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSAECANCELLED                    ((ULONG)0x00002777L)

//
// MessageId: WSAEINVALIDPROCTABLE
//
// MessageText:
//
// The procedure call table is invalid.
//
#define WSAEINVALIDPROCTABLE             ((ULONG)0x00002778L)

//
// MessageId: WSAEINVALIDPROVIDER
//
// MessageText:
//
// The requested service provider is invalid.
//
#define WSAEINVALIDPROVIDER              ((ULONG)0x00002779L)

//
// MessageId: WSAEPROVIDERFAILEDINIT
//
// MessageText:
//
// The requested service provider could not be loaded or initialized.
//
#define WSAEPROVIDERFAILEDINIT           ((ULONG)0x0000277AL)

//
// MessageId: WSASYSCALLFAILURE
//
// MessageText:
//
// A system call that should never fail has failed.
//
#define WSASYSCALLFAILURE                ((ULONG)0x0000277BL)

//
// MessageId: WSASERVICE_NOT_FOUND
//
// MessageText:
//
// No such service is known. The service cannot be found in the specified name space.
//
#define WSASERVICE_NOT_FOUND             ((ULONG)0x0000277CL)

//
// MessageId: WSATYPE_NOT_FOUND
//
// MessageText:
//
// The specified class was not found.
//
#define WSATYPE_NOT_FOUND                ((ULONG)0x0000277DL)

//
// MessageId: WSA_E_NO_MORE
//
// MessageText:
//
// No more results can be returned by WSALookupServiceNext.
//
#define WSA_E_NO_MORE                    ((ULONG)0x0000277EL)

//
// MessageId: WSA_E_CANCELLED
//
// MessageText:
//
// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
//
#define WSA_E_CANCELLED                  ((ULONG)0x0000277FL)

//
// MessageId: WSAEREFUSED
//
// MessageText:
//
// A database query failed because it was actively refused.
//
#define WSAEREFUSED                      ((ULONG)0x00002780L)

//
// MessageId: WSAHOST_NOT_FOUND
//
// MessageText:
//
// No such host is known.
//
#define WSAHOST_NOT_FOUND                ((ULONG)0x00002AF9L)

//
// MessageId: WSATRY_AGAIN
//
// MessageText:
//
// This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.
//
#define WSATRY_AGAIN                     ((ULONG)0x00002AFAL)

//
// MessageId: WSANO_RECOVERY
//
// MessageText:
//
// A non-recoverable error occurred during a database lookup.
//
#define WSANO_RECOVERY                   ((ULONG)0x00002AFBL)

//
// MessageId: WSANO_DATA
//
// MessageText:
//
// The requested name is valid, but no data of the requested type was found.
//
#define WSANO_DATA                       ((ULONG)0x00002AFCL)

//
// MessageId: WSA_QOS_RECEIVERS
//
// MessageText:
//
// At least one reserve has arrived.
//
#define WSA_QOS_RECEIVERS                ((ULONG)0x00002AFDL)

//
// MessageId: WSA_QOS_SENDERS
//
// MessageText:
//
// At least one path has arrived.
//
#define WSA_QOS_SENDERS                  ((ULONG)0x00002AFEL)

//
// MessageId: WSA_QOS_NO_SENDERS
//
// MessageText:
//
// There are no senders.
//
#define WSA_QOS_NO_SENDERS               ((ULONG)0x00002AFFL)

//
// MessageId: WSA_QOS_NO_RECEIVERS
//
// MessageText:
//
// There are no receivers.
//
#define WSA_QOS_NO_RECEIVERS             ((ULONG)0x00002B00L)

//
// MessageId: WSA_QOS_REQUEST_CONFIRMED
//
// MessageText:
//
// Reserve has been confirmed.
//
#define WSA_QOS_REQUEST_CONFIRMED        ((ULONG)0x00002B01L)

//
// MessageId: WSA_QOS_ADMISSION_FAILURE
//
// MessageText:
//
// Error due to lack of resources.
//
#define WSA_QOS_ADMISSION_FAILURE        ((ULONG)0x00002B02L)

//
// MessageId: WSA_QOS_POLICY_FAILURE
//
// MessageText:
//
// Rejected for administrative reasons - bad credentials.
//
#define WSA_QOS_POLICY_FAILURE           ((ULONG)0x00002B03L)

//
// MessageId: WSA_QOS_BAD_STYLE
//
// MessageText:
//
// Unknown or conflicting style.
//
#define WSA_QOS_BAD_STYLE                ((ULONG)0x00002B04L)

//
// MessageId: WSA_QOS_BAD_OBJECT
//
// MessageText:
//
// Problem with some part of the filterspec or providerspecific buffer in general.
//
#define WSA_QOS_BAD_OBJECT               ((ULONG)0x00002B05L)

//
// MessageId: WSA_QOS_TRAFFIC_CTRL_ERROR
//
// MessageText:
//
// Problem with some part of the flowspec.
//
#define WSA_QOS_TRAFFIC_CTRL_ERROR       ((ULONG)0x00002B06L)

//
// MessageId: WSA_QOS_GENERIC_ERROR
//
// MessageText:
//
// General QOS error.
//
#define WSA_QOS_GENERIC_ERROR            ((ULONG)0x00002B07L)

//
// MessageId: WSA_QOS_ESERVICETYPE
//
// MessageText:
//
// An invalid or unrecognized service type was found in the flowspec.
//
#define WSA_QOS_ESERVICETYPE             ((ULONG)0x00002B08L)

//
// MessageId: WSA_QOS_EFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS structure.
//
#define WSA_QOS_EFLOWSPEC                ((ULONG)0x00002B09L)

//
// MessageId: WSA_QOS_EPROVSPECBUF
//
// MessageText:
//
// Invalid QOS provider-specific buffer.
//
#define WSA_QOS_EPROVSPECBUF             ((ULONG)0x00002B0AL)

//
// MessageId: WSA_QOS_EFILTERSTYLE
//
// MessageText:
//
// An invalid QOS filter style was used.
//
#define WSA_QOS_EFILTERSTYLE             ((ULONG)0x00002B0BL)

//
// MessageId: WSA_QOS_EFILTERTYPE
//
// MessageText:
//
// An invalid QOS filter type was used.
//
#define WSA_QOS_EFILTERTYPE              ((ULONG)0x00002B0CL)

//
// MessageId: WSA_QOS_EFILTERCOUNT
//
// MessageText:
//
// An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
//
#define WSA_QOS_EFILTERCOUNT             ((ULONG)0x00002B0DL)

//
// MessageId: WSA_QOS_EOBJLENGTH
//
// MessageText:
//
// An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
//
#define WSA_QOS_EOBJLENGTH               ((ULONG)0x00002B0EL)

//
// MessageId: WSA_QOS_EFLOWCOUNT
//
// MessageText:
//
// An incorrect number of flow descriptors was specified in the QOS structure.
//
#define WSA_QOS_EFLOWCOUNT               ((ULONG)0x00002B0FL)

//
// MessageId: WSA_QOS_EUNKNOWNPSOBJ
//
// MessageText:
//
// An unrecognized object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EUNKNOWNPSOBJ            ((ULONG)0x00002B10L)

//
// MessageId: WSA_QOS_EPOLICYOBJ
//
// MessageText:
//
// An invalid policy object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPOLICYOBJ               ((ULONG)0x00002B11L)

//
// MessageId: WSA_QOS_EFLOWDESC
//
// MessageText:
//
// An invalid QOS flow descriptor was found in the flow descriptor list.
//
#define WSA_QOS_EFLOWDESC                ((ULONG)0x00002B12L)

//
// MessageId: WSA_QOS_EPSFLOWSPEC
//
// MessageText:
//
// An invalid or inconsistent flowspec was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPSFLOWSPEC              ((ULONG)0x00002B13L)

//
// MessageId: WSA_QOS_EPSFILTERSPEC
//
// MessageText:
//
// An invalid FILTERSPEC was found in the QOS provider-specific buffer.
//
#define WSA_QOS_EPSFILTERSPEC            ((ULONG)0x00002B14L)

//
// MessageId: WSA_QOS_ESDMODEOBJ
//
// MessageText:
//
// An invalid shape discard mode object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_ESDMODEOBJ               ((ULONG)0x00002B15L)

//
// MessageId: WSA_QOS_ESHAPERATEOBJ
//
// MessageText:
//
// An invalid shaping rate object was found in the QOS provider-specific buffer.
//
#define WSA_QOS_ESHAPERATEOBJ            ((ULONG)0x00002B16L)

//
// MessageId: WSA_QOS_RESERVED_PETYPE
//
// MessageText:
//
// A reserved policy element was found in the QOS provider-specific buffer.
//
#define WSA_QOS_RESERVED_PETYPE          ((ULONG)0x00002B17L)

//
// MessageId: ERROR_FLT_IO_COMPLETE
//
// MessageText:
//
// The IO was completed by a filter.
//
#define ERROR_FLT_IO_COMPLETE            ((ULONG)0x00002EE0L)

//
// MessageId: ERROR_FLT_BUFFER_TOO_SMALL
//
// MessageText:
//
// The buffer is too small to contain the entry. No information has been written to the buffer.
//
#define ERROR_FLT_BUFFER_TOO_SMALL       ((ULONG)0x00002EE1L)

//
// MessageId: ERROR_FLT_NO_HANDLER_DEFINED
//
// MessageText:
//
// A handler was not defined by the filter for this operation.
//
#define ERROR_FLT_NO_HANDLER_DEFINED     ((ULONG)0x00002EE2L)

//
// MessageId: ERROR_FLT_CONTEXT_ALREADY_DEFINED
//
// MessageText:
//
// A context is already defined for this object.
//
#define ERROR_FLT_CONTEXT_ALREADY_DEFINED ((ULONG)0x00002EE3L)

//
// MessageId: ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST
//
// MessageText:
//
// Asynchronous requests are not valid for this operation.
//
#define ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST ((ULONG)0x00002EE4L)

//
// MessageId: ERROR_FLT_DISALLOW_FAST_IO
//
// MessageText:
//
// Disallow the Fast IO path for this operation.
//
#define ERROR_FLT_DISALLOW_FAST_IO       ((ULONG)0x00002EE5L)

//
// MessageId: ERROR_FLT_INVALID_NAME_REQUEST
//
// MessageText:
//
// An invalid name request was made. The name requested cannot be retrieved at this time.
//
#define ERROR_FLT_INVALID_NAME_REQUEST   ((ULONG)0x00002EE6L)

//
// MessageId: ERROR_FLT_NOT_SAFE_TO_POST_OPERATION
//
// MessageText:
//
// Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock.
//
#define ERROR_FLT_NOT_SAFE_TO_POST_OPERATION ((ULONG)0x00002EE7L)

//
// MessageId: ERROR_FLT_NOT_INITIALIZED
//
// MessageText:
//
// The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is getting loaded as a driver.
//
#define ERROR_FLT_NOT_INITIALIZED        ((ULONG)0x00002EE8L)

//
// MessageId: ERROR_FLT_FILTER_NOT_READY
//
// MessageText:
//
// The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called).
//
#define ERROR_FLT_FILTER_NOT_READY       ((ULONG)0x00002EE9L)

//
// MessageId: ERROR_FLT_POST_OPERATION_CLEANUP
//
// MessageText:
//
// The filter must cleanup any operation specific context at this time because it is being removed from the system before the operation is completed by the lower drivers.
//
#define ERROR_FLT_POST_OPERATION_CLEANUP ((ULONG)0x00002EEAL)

//
// MessageId: ERROR_FLT_INTERNAL_ERROR
//
// MessageText:
//
// The Filter Manager had an internal error from which it cannot recover, therefore the operation has been failed. This is usually the result of a filter returning an invalid value from a pre-operation callback.
//
#define ERROR_FLT_INTERNAL_ERROR         ((ULONG)0x00002EEBL)

//
// MessageId: ERROR_FLT_DELETING_OBJECT
//
// MessageText:
//
// The object specified for this action is in the process of being deleted, therefore the action requested cannot be completed at this time.
//
#define ERROR_FLT_DELETING_OBJECT        ((ULONG)0x00002EECL)

//
// MessageId: ERROR_FLT_MUST_BE_NONPAGED_POOL
//
// MessageText:
//
// Non-paged pool must be used for this type of context.
//
#define ERROR_FLT_MUST_BE_NONPAGED_POOL  ((ULONG)0x00002EEDL)

//
// MessageId: ERROR_FLT_DUPLICATE_ENTRY
//
// MessageText:
//
// A duplicate handler definition has been provided for an operation.
//
#define ERROR_FLT_DUPLICATE_ENTRY        ((ULONG)0x00002EEEL)

//
// MessageId: ERROR_FLT_CBDQ_DISABLED
//
// MessageText:
//
// The callback data queue has been disabled.
//
#define ERROR_FLT_CBDQ_DISABLED          ((ULONG)0x00002EEFL)

//
// MessageId: ERROR_FLT_DO_NOT_ATTACH
//
// MessageText:
//
// Do not attach the filter to the volume at this time.
//
#define ERROR_FLT_DO_NOT_ATTACH          ((ULONG)0x00002EF0L)

//
// MessageId: ERROR_FLT_DO_NOT_DETACH
//
// MessageText:
//
// Do not detach the filter from the volume at this time.
//
#define ERROR_FLT_DO_NOT_DETACH          ((ULONG)0x00002EF1L)

//
// MessageId: ERROR_FLT_INSTANCE_ALTITUDE_COLLISION
//
// MessageText:
//
// An instance already exists at this altitude on the volume specified.
//
#define ERROR_FLT_INSTANCE_ALTITUDE_COLLISION ((ULONG)0x00002EF2L)

//
// MessageId: ERROR_FLT_INSTANCE_NAME_COLLISION
//
// MessageText:
//
// An instance already exists with this name on the volume specified.
//
#define ERROR_FLT_INSTANCE_NAME_COLLISION ((ULONG)0x00002EF3L)

//
// MessageId: ERROR_FLT_FILTER_NOT_FOUND
//
// MessageText:
//
// The system could not find the filter specified.
//
#define ERROR_FLT_FILTER_NOT_FOUND       ((ULONG)0x00002EF4L)

//
// MessageId: ERROR_FLT_VOLUME_NOT_FOUND
//
// MessageText:
//
// The system could not find the volume specified.
//
#define ERROR_FLT_VOLUME_NOT_FOUND       ((ULONG)0x00002EF5L)

//
// MessageId: ERROR_FLT_INSTANCE_NOT_FOUND
//
// MessageText:
//
// The system could not find the instance specified.
//
#define ERROR_FLT_INSTANCE_NOT_FOUND     ((ULONG)0x00002EF6L)

//
// MessageId: ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND
//
// MessageText:
//
// No registered context allocation definition was found for the given request.
//
#define ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND ((ULONG)0x00002EF7L)

//
// MessageId: ERROR_FLT_INVALID_CONTEXT_REGISTRATION
//
// MessageText:
//
// An invalid parameter was specified during context registration.
//
#define ERROR_FLT_INVALID_CONTEXT_REGISTRATION ((ULONG)0x00002EF8L)

//
// MessageId: ERROR_FLT_NAME_CACHE_MISS
//
// MessageText:
//
// The name requested was not found in Filter Manager's name cache and could not be retrieved from the file system.
//
#define ERROR_FLT_NAME_CACHE_MISS        ((ULONG)0x00002EF9L)

//
// MessageId: ERROR_FLT_NO_DEVICE_OBJECT
//
// MessageText:
//
// The requested device object does not exist for the given volume.
//
#define ERROR_FLT_NO_DEVICE_OBJECT       ((ULONG)0x00002EFAL)

//
// MessageId: ERROR_FLT_VOLUME_ALREADY_MOUNTED
//
// MessageText:
//
// The specified volume is already mounted.
//
#define ERROR_FLT_VOLUME_ALREADY_MOUNTED ((ULONG)0x00002EFBL)

//
// MessageId: ERROR_FLT_NO_WAITER_FOR_REPLY
//
// MessageText:
//
// No waiter is present for the filter's reply to this message.
//
#define ERROR_FLT_NO_WAITER_FOR_REPLY    ((ULONG)0x00002EFCL)

//
// MessageId: ERROR_IPSEC_QM_POLICY_EXISTS
//
// MessageText:
//
// The specified quick mode policy already exists.
//
#define ERROR_IPSEC_QM_POLICY_EXISTS     ((ULONG)0x000032C8L)

//
// MessageId: ERROR_IPSEC_QM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified quick mode policy was not found.
//
#define ERROR_IPSEC_QM_POLICY_NOT_FOUND  ((ULONG)0x000032C9L)

//
// MessageId: ERROR_IPSEC_QM_POLICY_IN_USE
//
// MessageText:
//
// The specified quick mode policy is being used.
//
#define ERROR_IPSEC_QM_POLICY_IN_USE     ((ULONG)0x000032CAL)

//
// MessageId: ERROR_IPSEC_MM_POLICY_EXISTS
//
// MessageText:
//
// The specified main mode policy already exists.
//
#define ERROR_IPSEC_MM_POLICY_EXISTS     ((ULONG)0x000032CBL)

//
// MessageId: ERROR_IPSEC_MM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified main mode policy was not found.
//
#define ERROR_IPSEC_MM_POLICY_NOT_FOUND  ((ULONG)0x000032CCL)

//
// MessageId: ERROR_IPSEC_MM_POLICY_IN_USE
//
// MessageText:
//
// The specified main mode policy is being used.
//
#define ERROR_IPSEC_MM_POLICY_IN_USE     ((ULONG)0x000032CDL)

//
// MessageId: ERROR_IPSEC_MM_FILTER_EXISTS
//
// MessageText:
//
// The specified main mode filter already exists.
//
#define ERROR_IPSEC_MM_FILTER_EXISTS     ((ULONG)0x000032CEL)

//
// MessageId: ERROR_IPSEC_MM_FILTER_NOT_FOUND
//
// MessageText:
//
// The specified main mode filter was not found.
//
#define ERROR_IPSEC_MM_FILTER_NOT_FOUND  ((ULONG)0x000032CFL)

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_EXISTS
//
// MessageText:
//
// The specified transport mode filter already exists.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_EXISTS ((ULONG)0x000032D0L)

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND
//
// MessageText:
//
// The specified transport mode filter does not exist.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND ((ULONG)0x000032D1L)

//
// MessageId: ERROR_IPSEC_MM_AUTH_EXISTS
//
// MessageText:
//
// The specified main mode authentication list exists.
//
#define ERROR_IPSEC_MM_AUTH_EXISTS       ((ULONG)0x000032D2L)

//
// MessageId: ERROR_IPSEC_MM_AUTH_NOT_FOUND
//
// MessageText:
//
// The specified main mode authentication list was not found.
//
#define ERROR_IPSEC_MM_AUTH_NOT_FOUND    ((ULONG)0x000032D3L)

//
// MessageId: ERROR_IPSEC_MM_AUTH_IN_USE
//
// MessageText:
//
// The specified quick mode policy is being used.
//
#define ERROR_IPSEC_MM_AUTH_IN_USE       ((ULONG)0x000032D4L)

//
// MessageId: ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND
//
// MessageText:
//
// The specified main mode policy was not found.
//
#define ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND ((ULONG)0x000032D5L)

//
// MessageId: ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND
//
// MessageText:
//
// The specified quick mode policy was not found.
//
#define ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND ((ULONG)0x000032D6L)

//
// MessageId: ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND
//
// MessageText:
//
// The manifest file contains one or more syntax errors.
//
#define ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND ((ULONG)0x000032D7L)

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_EXISTS
//
// MessageText:
//
// The application attempted to activate a disabled activation context.
//
#define ERROR_IPSEC_TUNNEL_FILTER_EXISTS ((ULONG)0x000032D8L)

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND
//
// MessageText:
//
// The requested lookup key was not found in any active activation context.
//
#define ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND ((ULONG)0x000032D9L)

//
// MessageId: ERROR_IPSEC_MM_FILTER_PENDING_DELETION
//
// MessageText:
//
// The Main Mode filter is pending deletion.
//
#define ERROR_IPSEC_MM_FILTER_PENDING_DELETION ((ULONG)0x000032DAL)

//
// MessageId: ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION
//
// MessageText:
//
// The transport filter is pending deletion.
//
#define ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION ((ULONG)0x000032DBL)

//
// MessageId: ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION
//
// MessageText:
//
// The tunnel filter is pending deletion.
//
#define ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION ((ULONG)0x000032DCL)

//
// MessageId: ERROR_IPSEC_MM_POLICY_PENDING_DELETION
//
// MessageText:
//
// The Main Mode policy is pending deletion.
//
#define ERROR_IPSEC_MM_POLICY_PENDING_DELETION ((ULONG)0x000032DDL)

//
// MessageId: ERROR_IPSEC_MM_AUTH_PENDING_DELETION
//
// MessageText:
//
// The Main Mode authentication bundle is pending deletion.
//
#define ERROR_IPSEC_MM_AUTH_PENDING_DELETION ((ULONG)0x000032DEL)

//
// MessageId: ERROR_IPSEC_QM_POLICY_PENDING_DELETION
//
// MessageText:
//
// The Quick Mode policy is pending deletion.
//
#define ERROR_IPSEC_QM_POLICY_PENDING_DELETION ((ULONG)0x000032DFL)

//
// MessageId: WARNING_IPSEC_MM_POLICY_PRUNED
//
// MessageText:
//
// The Main Mode policy was successfully added, but some of the requested offers are not supported.
//
#define WARNING_IPSEC_MM_POLICY_PRUNED   ((ULONG)0x000032E0L)

//
// MessageId: WARNING_IPSEC_QM_POLICY_PRUNED
//
// MessageText:
//
// The Quick Mode policy was successfully added, but some of the requested offers are not supported.
//
#define WARNING_IPSEC_QM_POLICY_PRUNED   ((ULONG)0x000032E1L)

//
// MessageId: ERROR_IPSEC_IKE_AUTH_FAIL
//
// MessageText:
//
// IKE authentication credentials are unacceptable.
//
#define ERROR_IPSEC_IKE_AUTH_FAIL        ((ULONG)0x000035E9L)

//
// MessageId: ERROR_IPSEC_IKE_ATTRIB_FAIL
//
// MessageText:
//
// IKE security attributes are unacceptable.
//
#define ERROR_IPSEC_IKE_ATTRIB_FAIL      ((ULONG)0x000035EAL)

//
// MessageId: ERROR_IPSEC_IKE_NEGOTIATION_PENDING
//
// MessageText:
//
// IKE Negotiation in progress.
//
#define ERROR_IPSEC_IKE_NEGOTIATION_PENDING ((ULONG)0x000035EBL)

//
// MessageId: ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR
//
// MessageText:
//
// General processing error.
//
#define ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR ((ULONG)0x000035ECL)

//
// MessageId: ERROR_IPSEC_IKE_TIMED_OUT
//
// MessageText:
//
// Negotiation timed out.
//
#define ERROR_IPSEC_IKE_TIMED_OUT        ((ULONG)0x000035EDL)

//
// MessageId: ERROR_IPSEC_IKE_NO_CERT
//
// MessageText:
//
// IKE failed to find valid machine certificate.
//
#define ERROR_IPSEC_IKE_NO_CERT          ((ULONG)0x000035EEL)

//
// MessageId: ERROR_IPSEC_IKE_SA_DELETED
//
// MessageText:
//
// IKE SA deleted by peer before establishment completed.
//
#define ERROR_IPSEC_IKE_SA_DELETED       ((ULONG)0x000035EFL)

//
// MessageId: ERROR_IPSEC_IKE_SA_REAPED
//
// MessageText:
//
// IKE SA deleted before establishment completed.
//
#define ERROR_IPSEC_IKE_SA_REAPED        ((ULONG)0x000035F0L)

//
// MessageId: ERROR_IPSEC_IKE_MM_ACQUIRE_DROP
//
// MessageText:
//
// Negotiation request sat in Queue too long.
//
#define ERROR_IPSEC_IKE_MM_ACQUIRE_DROP  ((ULONG)0x000035F1L)

//
// MessageId: ERROR_IPSEC_IKE_QM_ACQUIRE_DROP
//
// MessageText:
//
// Negotiation request sat in Queue too long.
//
#define ERROR_IPSEC_IKE_QM_ACQUIRE_DROP  ((ULONG)0x000035F2L)

//
// MessageId: ERROR_IPSEC_IKE_QUEUE_DROP_MM
//
// MessageText:
//
// Negotiation request sat in Queue too long.
//
#define ERROR_IPSEC_IKE_QUEUE_DROP_MM    ((ULONG)0x000035F3L)

//
// MessageId: ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM
//
// MessageText:
//
// Negotiation request sat in Queue too long.
//
#define ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM ((ULONG)0x000035F4L)

//
// MessageId: ERROR_IPSEC_IKE_DROP_NO_RESPONSE
//
// MessageText:
//
// No response from peer.
//
#define ERROR_IPSEC_IKE_DROP_NO_RESPONSE ((ULONG)0x000035F5L)

//
// MessageId: ERROR_IPSEC_IKE_MM_DELAY_DROP
//
// MessageText:
//
// Negotiation took too long.
//
#define ERROR_IPSEC_IKE_MM_DELAY_DROP    ((ULONG)0x000035F6L)

//
// MessageId: ERROR_IPSEC_IKE_QM_DELAY_DROP
//
// MessageText:
//
// Negotiation took too long.
//
#define ERROR_IPSEC_IKE_QM_DELAY_DROP    ((ULONG)0x000035F7L)

//
// MessageId: ERROR_IPSEC_IKE_ERROR
//
// MessageText:
//
// Unknown error occurred.
//
#define ERROR_IPSEC_IKE_ERROR            ((ULONG)0x000035F8L)

//
// MessageId: ERROR_IPSEC_IKE_CRL_FAILED
//
// MessageText:
//
// Certificate Revocation Check failed.
//
#define ERROR_IPSEC_IKE_CRL_FAILED       ((ULONG)0x000035F9L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_KEY_USAGE
//
// MessageText:
//
// Invalid certificate key usage.
//
#define ERROR_IPSEC_IKE_INVALID_KEY_USAGE ((ULONG)0x000035FAL)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_CERT_TYPE
//
// MessageText:
//
// Invalid certificate type.
//
#define ERROR_IPSEC_IKE_INVALID_CERT_TYPE ((ULONG)0x000035FBL)

//
// MessageId: ERROR_IPSEC_IKE_NO_PRIVATE_KEY
//
// MessageText:
//
// No private key associated with machine certificate.
//
#define ERROR_IPSEC_IKE_NO_PRIVATE_KEY   ((ULONG)0x000035FCL)

//
// MessageId: ERROR_IPSEC_IKE_DH_FAIL
//
// MessageText:
//
// Failure in Diffie-Hellman computation.
//
#define ERROR_IPSEC_IKE_DH_FAIL          ((ULONG)0x000035FEL)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HEADER
//
// MessageText:
//
// Invalid header.
//
#define ERROR_IPSEC_IKE_INVALID_HEADER   ((ULONG)0x00003600L)

//
// MessageId: ERROR_IPSEC_IKE_NO_POLICY
//
// MessageText:
//
// No policy configured.
//
#define ERROR_IPSEC_IKE_NO_POLICY        ((ULONG)0x00003601L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SIGNATURE
//
// MessageText:
//
// Failed to verify signature.
//
#define ERROR_IPSEC_IKE_INVALID_SIGNATURE ((ULONG)0x00003602L)

//
// MessageId: ERROR_IPSEC_IKE_KERBEROS_ERROR
//
// MessageText:
//
// Failed to authenticate using Kerberos.
//
#define ERROR_IPSEC_IKE_KERBEROS_ERROR   ((ULONG)0x00003603L)

//
// MessageId: ERROR_IPSEC_IKE_NO_PUBLIC_KEY
//
// MessageText:
//
// Peer's certificate did not have a public key.
//
#define ERROR_IPSEC_IKE_NO_PUBLIC_KEY    ((ULONG)0x00003604L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR
//
// MessageText:
//
// Error processing error payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR      ((ULONG)0x00003605L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_SA
//
// MessageText:
//
// Error processing SA payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_SA   ((ULONG)0x00003606L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_PROP
//
// MessageText:
//
// Error processing Proposal payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_PROP ((ULONG)0x00003607L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_TRANS
//
// MessageText:
//
// Error processing Transform payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_TRANS ((ULONG)0x00003608L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_KE
//
// MessageText:
//
// Error processing KE payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_KE   ((ULONG)0x00003609L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_ID
//
// MessageText:
//
// Error processing ID payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_ID   ((ULONG)0x0000360AL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_CERT
//
// MessageText:
//
// Error processing Cert payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_CERT ((ULONG)0x0000360BL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ
//
// MessageText:
//
// Error processing Certificate Request payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ ((ULONG)0x0000360CL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_HASH
//
// MessageText:
//
// Error processing Hash payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_HASH ((ULONG)0x0000360DL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_SIG
//
// MessageText:
//
// Error processing Signature payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_SIG  ((ULONG)0x0000360EL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_NONCE
//
// MessageText:
//
// Error processing Nonce payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_NONCE ((ULONG)0x0000360FL)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY
//
// MessageText:
//
// Error processing Notify payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY ((ULONG)0x00003610L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_DELETE
//
// MessageText:
//
// Error processing Delete Payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_DELETE ((ULONG)0x00003611L)

//
// MessageId: ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR
//
// MessageText:
//
// Error processing VendorId payload.
//
#define ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR ((ULONG)0x00003612L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_PAYLOAD
//
// MessageText:
//
// Invalid payload received.
//
#define ERROR_IPSEC_IKE_INVALID_PAYLOAD  ((ULONG)0x00003613L)

//
// MessageId: ERROR_IPSEC_IKE_LOAD_SOFT_SA
//
// MessageText:
//
// Soft SA loaded.
//
#define ERROR_IPSEC_IKE_LOAD_SOFT_SA     ((ULONG)0x00003614L)

//
// MessageId: ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN
//
// MessageText:
//
// Soft SA torn down.
//
#define ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN ((ULONG)0x00003615L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_COOKIE
//
// MessageText:
//
// Invalid cookie received.
//
#define ERROR_IPSEC_IKE_INVALID_COOKIE   ((ULONG)0x00003616L)

//
// MessageId: ERROR_IPSEC_IKE_NO_PEER_CERT
//
// MessageText:
//
// Peer failed to send valid machine certificate.
//
#define ERROR_IPSEC_IKE_NO_PEER_CERT     ((ULONG)0x00003617L)

//
// MessageId: ERROR_IPSEC_IKE_PEER_CRL_FAILED
//
// MessageText:
//
// Certification Revocation check of peer's certificate failed.
//
#define ERROR_IPSEC_IKE_PEER_CRL_FAILED  ((ULONG)0x00003618L)

//
// MessageId: ERROR_IPSEC_IKE_POLICY_CHANGE
//
// MessageText:
//
// New policy invalidated SAs formed with old policy.
//
#define ERROR_IPSEC_IKE_POLICY_CHANGE    ((ULONG)0x00003619L)

//
// MessageId: ERROR_IPSEC_IKE_NO_MM_POLICY
//
// MessageText:
//
// There is no available Main Mode IKE policy.
//
#define ERROR_IPSEC_IKE_NO_MM_POLICY     ((ULONG)0x0000361AL)

//
// MessageId: ERROR_IPSEC_IKE_NOTCBPRIV
//
// MessageText:
//
// Failed to enabled TCB privilege.
//
#define ERROR_IPSEC_IKE_NOTCBPRIV        ((ULONG)0x0000361BL)

//
// MessageId: ERROR_IPSEC_IKE_SECLOADFAIL
//
// MessageText:
//
// Failed to load SECURITY.DLL.
//
#define ERROR_IPSEC_IKE_SECLOADFAIL      ((ULONG)0x0000361CL)

//
// MessageId: ERROR_IPSEC_IKE_FAILSSPINIT
//
// MessageText:
//
// Failed to obtain security function table dispatch address from SSPI.
//
#define ERROR_IPSEC_IKE_FAILSSPINIT      ((ULONG)0x0000361DL)

//
// MessageId: ERROR_IPSEC_IKE_FAILQUERYSSP
//
// MessageText:
//
// Failed to query Kerberos package to obtain max token size.
//
#define ERROR_IPSEC_IKE_FAILQUERYSSP     ((ULONG)0x0000361EL)

//
// MessageId: ERROR_IPSEC_IKE_SRVACQFAIL
//
// MessageText:
//
// Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.
//
#define ERROR_IPSEC_IKE_SRVACQFAIL       ((ULONG)0x0000361FL)

//
// MessageId: ERROR_IPSEC_IKE_SRVQUERYCRED
//
// MessageText:
//
// Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).
//
#define ERROR_IPSEC_IKE_SRVQUERYCRED     ((ULONG)0x00003620L)

//
// MessageId: ERROR_IPSEC_IKE_GETSPIFAIL
//
// MessageText:
//
// Failed to obtain new SPI for the inbound SA from IPSec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.
//
#define ERROR_IPSEC_IKE_GETSPIFAIL       ((ULONG)0x00003621L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_FILTER
//
// MessageText:
//
// Given filter is invalid.
//
#define ERROR_IPSEC_IKE_INVALID_FILTER   ((ULONG)0x00003622L)

//
// MessageId: ERROR_IPSEC_IKE_OUT_OF_MEMORY
//
// MessageText:
//
// Memory allocation failed.
//
#define ERROR_IPSEC_IKE_OUT_OF_MEMORY    ((ULONG)0x00003623L)

//
// MessageId: ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED
//
// MessageText:
//
// Failed to add Security Association to IPSec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.
//
#define ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED ((ULONG)0x00003624L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_POLICY
//
// MessageText:
//
// Invalid policy.
//
#define ERROR_IPSEC_IKE_INVALID_POLICY   ((ULONG)0x00003625L)

//
// MessageId: ERROR_IPSEC_IKE_UNKNOWN_DOI
//
// MessageText:
//
// Invalid DOI.
//
#define ERROR_IPSEC_IKE_UNKNOWN_DOI      ((ULONG)0x00003626L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SITUATION
//
// MessageText:
//
// Invalid situation.
//
#define ERROR_IPSEC_IKE_INVALID_SITUATION ((ULONG)0x00003627L)

//
// MessageId: ERROR_IPSEC_IKE_DH_FAILURE
//
// MessageText:
//
// Diffie-Hellman failure.
//
#define ERROR_IPSEC_IKE_DH_FAILURE       ((ULONG)0x00003628L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_GROUP
//
// MessageText:
//
// Invalid Diffie-Hellman group.
//
#define ERROR_IPSEC_IKE_INVALID_GROUP    ((ULONG)0x00003629L)

//
// MessageId: ERROR_IPSEC_IKE_ENCRYPT
//
// MessageText:
//
// Error encrypting payload.
//
#define ERROR_IPSEC_IKE_ENCRYPT          ((ULONG)0x0000362AL)

//
// MessageId: ERROR_IPSEC_IKE_DECRYPT
//
// MessageText:
//
// Error decrypting payload.
//
#define ERROR_IPSEC_IKE_DECRYPT          ((ULONG)0x0000362BL)

//
// MessageId: ERROR_IPSEC_IKE_POLICY_MATCH
//
// MessageText:
//
// Policy match error.
//
#define ERROR_IPSEC_IKE_POLICY_MATCH     ((ULONG)0x0000362CL)

//
// MessageId: ERROR_IPSEC_IKE_UNSUPPORTED_ID
//
// MessageText:
//
// Unsupported ID.
//
#define ERROR_IPSEC_IKE_UNSUPPORTED_ID   ((ULONG)0x0000362DL)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH
//
// MessageText:
//
// Hash verification failed.
//
#define ERROR_IPSEC_IKE_INVALID_HASH     ((ULONG)0x0000362EL)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH_ALG
//
// MessageText:
//
// Invalid hash algorithm.
//
#define ERROR_IPSEC_IKE_INVALID_HASH_ALG ((ULONG)0x0000362FL)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_HASH_SIZE
//
// MessageText:
//
// Invalid hash size.
//
#define ERROR_IPSEC_IKE_INVALID_HASH_SIZE ((ULONG)0x00003630L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG
//
// MessageText:
//
// Invalid encryption algorithm.
//
#define ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG ((ULONG)0x00003631L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_AUTH_ALG
//
// MessageText:
//
// Invalid authentication algorithm.
//
#define ERROR_IPSEC_IKE_INVALID_AUTH_ALG ((ULONG)0x00003632L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_SIG
//
// MessageText:
//
// Invalid certificate signature.
//
#define ERROR_IPSEC_IKE_INVALID_SIG      ((ULONG)0x00003633L)

//
// MessageId: ERROR_IPSEC_IKE_LOAD_FAILED
//
// MessageText:
//
// Load failed.
//
#define ERROR_IPSEC_IKE_LOAD_FAILED      ((ULONG)0x00003634L)

//
// MessageId: ERROR_IPSEC_IKE_RPC_DELETE
//
// MessageText:
//
// Deleted via RPC call.
//
#define ERROR_IPSEC_IKE_RPC_DELETE       ((ULONG)0x00003635L)

//
// MessageId: ERROR_IPSEC_IKE_BENIGN_REINIT
//
// MessageText:
//
// Temporary state created to perform reinit. This is not a real failure.
//
#define ERROR_IPSEC_IKE_BENIGN_REINIT    ((ULONG)0x00003636L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY
//
// MessageText:
//
// The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.
//
#define ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY ((ULONG)0x00003637L)

//
// MessageId: ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN
//
// MessageText:
//
// Key length in certificate is too small for configured security requirements.
//
#define ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN ((ULONG)0x00003639L)

//
// MessageId: ERROR_IPSEC_IKE_MM_LIMIT
//
// MessageText:
//
// Max number of established MM SAs to peer exceeded.
//
#define ERROR_IPSEC_IKE_MM_LIMIT         ((ULONG)0x0000363AL)

//
// MessageId: ERROR_IPSEC_IKE_NEGOTIATION_DISABLED
//
// MessageText:
//
// IKE received a policy that disables negotiation.
//
#define ERROR_IPSEC_IKE_NEGOTIATION_DISABLED ((ULONG)0x0000363BL)

//
// MessageId: ERROR_IPSEC_IKE_NEG_STATUS_END
//
// MessageText:
//
// ERROR_IPSEC_IKE_NEG_STATUS_END
//
#define ERROR_IPSEC_IKE_NEG_STATUS_END   ((ULONG)0x0000363CL)

//
// MessageId: ERROR_SXS_SECTION_NOT_FOUND
//
// MessageText:
//
// The requested section was not present in the activation context.
//
#define ERROR_SXS_SECTION_NOT_FOUND      ((ULONG)0x000036B0L)

//
// MessageId: ERROR_SXS_CANT_GEN_ACTCTX
//
// MessageText:
//
// This application has failed to start because the application configuration is incorrect. Reinstalling the application may fix this problem.
//
#define ERROR_SXS_CANT_GEN_ACTCTX        ((ULONG)0x000036B1L)

//
// MessageId: ERROR_SXS_INVALID_ACTCTXDATA_FORMAT
//
// MessageText:
//
// The application binding data format is invalid.
//
#define ERROR_SXS_INVALID_ACTCTXDATA_FORMAT ((ULONG)0x000036B2L)

//
// MessageId: ERROR_SXS_ASSEMBLY_NOT_FOUND
//
// MessageText:
//
// The referenced assembly is not installed on your system.
//
#define ERROR_SXS_ASSEMBLY_NOT_FOUND     ((ULONG)0x000036B3L)

//
// MessageId: ERROR_SXS_MANIFEST_FORMAT_ERROR
//
// MessageText:
//
// The manifest file does not begin with the required tag and format information.
//
#define ERROR_SXS_MANIFEST_FORMAT_ERROR  ((ULONG)0x000036B4L)

//
// MessageId: ERROR_SXS_MANIFEST_PARSE_ERROR
//
// MessageText:
//
// The manifest file contains one or more syntax errors.
//
#define ERROR_SXS_MANIFEST_PARSE_ERROR   ((ULONG)0x000036B5L)

//
// MessageId: ERROR_SXS_ACTIVATION_CONTEXT_DISABLED
//
// MessageText:
//
// The application attempted to activate a disabled activation context.
//
#define ERROR_SXS_ACTIVATION_CONTEXT_DISABLED ((ULONG)0x000036B6L)

//
// MessageId: ERROR_SXS_KEY_NOT_FOUND
//
// MessageText:
//
// The requested lookup key was not found in any active activation context.
//
#define ERROR_SXS_KEY_NOT_FOUND          ((ULONG)0x000036B7L)

//
// MessageId: ERROR_SXS_VERSION_CONFLICT
//
// MessageText:
//
// A component version required by the application conflicts with another component version already active.
//
#define ERROR_SXS_VERSION_CONFLICT       ((ULONG)0x000036B8L)

//
// MessageId: ERROR_SXS_WRONG_SECTION_TYPE
//
// MessageText:
//
// The type requested activation context section does not match the query API used.
//
#define ERROR_SXS_WRONG_SECTION_TYPE     ((ULONG)0x000036B9L)

//
// MessageId: ERROR_SXS_THREAD_QUERIES_DISABLED
//
// MessageText:
//
// Lack of system resources has required isolated activation to be disabled for the current thread of execution.
//
#define ERROR_SXS_THREAD_QUERIES_DISABLED ((ULONG)0x000036BAL)

//
// MessageId: ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET
//
// MessageText:
//
// An attempt to set the process default activation context failed because the process default activation context was already set.
//
#define ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET ((ULONG)0x000036BBL)

//
// MessageId: ERROR_SXS_UNKNOWN_ENCODING_GROUP
//
// MessageText:
//
// The encoding group identifier specified is not recognized.
//
#define ERROR_SXS_UNKNOWN_ENCODING_GROUP ((ULONG)0x000036BCL)

//
// MessageId: ERROR_SXS_UNKNOWN_ENCODING
//
// MessageText:
//
// The encoding requested is not recognized.
//
#define ERROR_SXS_UNKNOWN_ENCODING       ((ULONG)0x000036BDL)

//
// MessageId: ERROR_SXS_INVALID_XML_NAMESPACE_URI
//
// MessageText:
//
// The manifest contains a reference to an invalid URI.
//
#define ERROR_SXS_INVALID_XML_NAMESPACE_URI ((ULONG)0x000036BEL)

//
// MessageId: ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED
//
// MessageText:
//
// The application manifest contains a reference to a dependent assembly which is not installed.
//
#define ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED ((ULONG)0x000036BFL)

//
// MessageId: ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED
//
// MessageText:
//
// The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed.
//
#define ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED ((ULONG)0x000036C0L)

//
// MessageId: ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE
//
// MessageText:
//
// The manifest contains an attribute for the assembly identity which is not valid.
//
#define ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE ((ULONG)0x000036C1L)

//
// MessageId: ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE
//
// MessageText:
//
// The manifest is missing the required default namespace specification on the assembly element.
//
#define ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE ((ULONG)0x000036C2L)

//
// MessageId: ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE
//
// MessageText:
//
// The manifest has a default namespace specified on the assembly element but its value is not \"urn:schemas-microsoft-com:asm.v1\".
//
#define ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE ((ULONG)0x000036C3L)

//
// MessageId: ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT
//
// MessageText:
//
// The private manifest probe has crossed the reparse-point-associated path.
//
#define ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT ((ULONG)0x000036C4L)

//
// MessageId: ERROR_SXS_DUPLICATE_DLL_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have files by the same name.
//
#define ERROR_SXS_DUPLICATE_DLL_NAME     ((ULONG)0x000036C5L)

//
// MessageId: ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.
//
#define ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME ((ULONG)0x000036C6L)

//
// MessageId: ERROR_SXS_DUPLICATE_CLSID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.
//
#define ERROR_SXS_DUPLICATE_CLSID        ((ULONG)0x000036C7L)

//
// MessageId: ERROR_SXS_DUPLICATE_IID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.
//
#define ERROR_SXS_DUPLICATE_IID          ((ULONG)0x000036C8L)

//
// MessageId: ERROR_SXS_DUPLICATE_TLBID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.
//
#define ERROR_SXS_DUPLICATE_TLBID        ((ULONG)0x000036C9L)

//
// MessageId: ERROR_SXS_DUPLICATE_PROGID
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.
//
#define ERROR_SXS_DUPLICATE_PROGID       ((ULONG)0x000036CAL)

//
// MessageId: ERROR_SXS_DUPLICATE_ASSEMBLY_NAME
//
// MessageText:
//
// Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.
//
#define ERROR_SXS_DUPLICATE_ASSEMBLY_NAME ((ULONG)0x000036CBL)

//
// MessageId: ERROR_SXS_FILE_HASH_MISMATCH
//
// MessageText:
//
// A component's file does not match the verification information present in the component manifest.
//
#define ERROR_SXS_FILE_HASH_MISMATCH     ((ULONG)0x000036CCL)

//
// MessageId: ERROR_SXS_POLICY_PARSE_ERROR
//
// MessageText:
//
// The policy manifest contains one or more syntax errors.
//
#define ERROR_SXS_POLICY_PARSE_ERROR     ((ULONG)0x000036CDL)

//
// MessageId: ERROR_SXS_XML_E_MISSINGQUOTE
//
// MessageText:
//
// Manifest Parse Error : A string literal was expected, but no opening quote character was found.
//
#define ERROR_SXS_XML_E_MISSINGQUOTE     ((ULONG)0x000036CEL)

//
// MessageId: ERROR_SXS_XML_E_COMMENTSYNTAX
//
// MessageText:
//
// Manifest Parse Error : Incorrect syntax was used in a comment.
//
#define ERROR_SXS_XML_E_COMMENTSYNTAX    ((ULONG)0x000036CFL)

//
// MessageId: ERROR_SXS_XML_E_BADSTARTNAMECHAR
//
// MessageText:
//
// Manifest Parse Error : A name was started with an invalid character.
//
#define ERROR_SXS_XML_E_BADSTARTNAMECHAR ((ULONG)0x000036D0L)

//
// MessageId: ERROR_SXS_XML_E_BADNAMECHAR
//
// MessageText:
//
// Manifest Parse Error : A name contained an invalid character.
//
#define ERROR_SXS_XML_E_BADNAMECHAR      ((ULONG)0x000036D1L)

//
// MessageId: ERROR_SXS_XML_E_BADCHARINSTRING
//
// MessageText:
//
// Manifest Parse Error : A string literal contained an invalid character.
//
#define ERROR_SXS_XML_E_BADCHARINSTRING  ((ULONG)0x000036D2L)

//
// MessageId: ERROR_SXS_XML_E_XMLDECLSYNTAX
//
// MessageText:
//
// Manifest Parse Error : Invalid syntax for an XML declaration.
//
#define ERROR_SXS_XML_E_XMLDECLSYNTAX    ((ULONG)0x000036D3L)

//
// MessageId: ERROR_SXS_XML_E_BADCHARDATA
//
// MessageText:
//
// Manifest Parse Error : An invalid character was found in text content.
//
#define ERROR_SXS_XML_E_BADCHARDATA      ((ULONG)0x000036D4L)

//
// MessageId: ERROR_SXS_XML_E_MISSINGWHITESPACE
//
// MessageText:
//
// Manifest Parse Error : Required white space was missing.
//
#define ERROR_SXS_XML_E_MISSINGWHITESPACE ((ULONG)0x000036D5L)

//
// MessageId: ERROR_SXS_XML_E_EXPECTINGTAGEND
//
// MessageText:
//
// Manifest Parse Error : The character '>' was expected.
//
#define ERROR_SXS_XML_E_EXPECTINGTAGEND  ((ULONG)0x000036D6L)

//
// MessageId: ERROR_SXS_XML_E_MISSINGSEMICOLON
//
// MessageText:
//
// Manifest Parse Error : A semi colon character was expected.
//
#define ERROR_SXS_XML_E_MISSINGSEMICOLON ((ULONG)0x000036D7L)

//
// MessageId: ERROR_SXS_XML_E_UNBALANCEDPAREN
//
// MessageText:
//
// Manifest Parse Error : Unbalanced parentheses.
//
#define ERROR_SXS_XML_E_UNBALANCEDPAREN  ((ULONG)0x000036D8L)

//
// MessageId: ERROR_SXS_XML_E_INTERNALERROR
//
// MessageText:
//
// Manifest Parse Error : Internal error.
//
#define ERROR_SXS_XML_E_INTERNALERROR    ((ULONG)0x000036D9L)

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE
//
// MessageText:
//
// Manifest Parse Error : White space is not allowed at this location.
//
#define ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE ((ULONG)0x000036DAL)

//
// MessageId: ERROR_SXS_XML_E_INCOMPLETE_ENCODING
//
// MessageText:
//
// Manifest Parse Error : End of file reached in invalid state for current encoding.
//
#define ERROR_SXS_XML_E_INCOMPLETE_ENCODING ((ULONG)0x000036DBL)

//
// MessageId: ERROR_SXS_XML_E_MISSING_PAREN
//
// MessageText:
//
// Manifest Parse Error : Missing parenthesis.
//
#define ERROR_SXS_XML_E_MISSING_PAREN    ((ULONG)0x000036DCL)

//
// MessageId: ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE
//
// MessageText:
//
// Manifest Parse Error : A single or double closing quote character (\' or \") is missing.
//
#define ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE ((ULONG)0x000036DDL)

//
// MessageId: ERROR_SXS_XML_E_MULTIPLE_COLONS
//
// MessageText:
//
// Manifest Parse Error : Multiple colons are not allowed in a name.
//
#define ERROR_SXS_XML_E_MULTIPLE_COLONS  ((ULONG)0x000036DEL)

//
// MessageId: ERROR_SXS_XML_E_INVALID_DECIMAL
//
// MessageText:
//
// Manifest Parse Error : Invalid character for decimal digit.
//
#define ERROR_SXS_XML_E_INVALID_DECIMAL  ((ULONG)0x000036DFL)

//
// MessageId: ERROR_SXS_XML_E_INVALID_HEXIDECIMAL
//
// MessageText:
//
// Manifest Parse Error : Invalid character for hexadecimal digit.
//
#define ERROR_SXS_XML_E_INVALID_HEXIDECIMAL ((ULONG)0x000036E0L)

//
// MessageId: ERROR_SXS_XML_E_INVALID_UNICODE
//
// MessageText:
//
// Manifest Parse Error : Invalid Unicode character value for this platform.
//
#define ERROR_SXS_XML_E_INVALID_UNICODE  ((ULONG)0x000036E1L)

//
// MessageId: ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK
//
// MessageText:
//
// Manifest Parse Error : Expecting white space or '?'.
//
#define ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK ((ULONG)0x000036E2L)

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTEDENDTAG
//
// MessageText:
//
// Manifest Parse Error : End tag was not expected at this location.
//
#define ERROR_SXS_XML_E_UNEXPECTEDENDTAG ((ULONG)0x000036E3L)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDTAG
//
// MessageText:
//
// Manifest Parse Error : The following tags were not closed: %1.
//
#define ERROR_SXS_XML_E_UNCLOSEDTAG      ((ULONG)0x000036E4L)

//
// MessageId: ERROR_SXS_XML_E_DUPLICATEATTRIBUTE
//
// MessageText:
//
// Manifest Parse Error : Duplicate attribute.
//
#define ERROR_SXS_XML_E_DUPLICATEATTRIBUTE ((ULONG)0x000036E5L)

//
// MessageId: ERROR_SXS_XML_E_MULTIPLEROOTS
//
// MessageText:
//
// Manifest Parse Error : Only one top level element is allowed in an XML document.
//
#define ERROR_SXS_XML_E_MULTIPLEROOTS    ((ULONG)0x000036E6L)

//
// MessageId: ERROR_SXS_XML_E_INVALIDATROOTLEVEL
//
// MessageText:
//
// Manifest Parse Error : Invalid at the top level of the document.
//
#define ERROR_SXS_XML_E_INVALIDATROOTLEVEL ((ULONG)0x000036E7L)

//
// MessageId: ERROR_SXS_XML_E_BADXMLDECL
//
// MessageText:
//
// Manifest Parse Error : Invalid XML declaration.
//
#define ERROR_SXS_XML_E_BADXMLDECL       ((ULONG)0x000036E8L)

//
// MessageId: ERROR_SXS_XML_E_MISSINGROOT
//
// MessageText:
//
// Manifest Parse Error : XML document must have a top level element.
//
#define ERROR_SXS_XML_E_MISSINGROOT      ((ULONG)0x000036E9L)

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTEDEOF
//
// MessageText:
//
// Manifest Parse Error : Unexpected end of file.
//
#define ERROR_SXS_XML_E_UNEXPECTEDEOF    ((ULONG)0x000036EAL)

//
// MessageId: ERROR_SXS_XML_E_BADPEREFINSUBSET
//
// MessageText:
//
// Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.
//
#define ERROR_SXS_XML_E_BADPEREFINSUBSET ((ULONG)0x000036EBL)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDSTARTTAG
//
// MessageText:
//
// Manifest Parse Error : Element was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDSTARTTAG ((ULONG)0x000036ECL)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDENDTAG
//
// MessageText:
//
// Manifest Parse Error : End element was missing the character '>'.
//
#define ERROR_SXS_XML_E_UNCLOSEDENDTAG   ((ULONG)0x000036EDL)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDSTRING
//
// MessageText:
//
// Manifest Parse Error : A string literal was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDSTRING   ((ULONG)0x000036EEL)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDCOMMENT
//
// MessageText:
//
// Manifest Parse Error : A comment was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDCOMMENT  ((ULONG)0x000036EFL)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDDECL
//
// MessageText:
//
// Manifest Parse Error : A declaration was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDDECL     ((ULONG)0x000036F0L)

//
// MessageId: ERROR_SXS_XML_E_UNCLOSEDCDATA
//
// MessageText:
//
// Manifest Parse Error : A CDATA section was not closed.
//
#define ERROR_SXS_XML_E_UNCLOSEDCDATA    ((ULONG)0x000036F1L)

//
// MessageId: ERROR_SXS_XML_E_RESERVEDNAMESPACE
//
// MessageText:
//
// Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string \"xml\".
//
#define ERROR_SXS_XML_E_RESERVEDNAMESPACE ((ULONG)0x000036F2L)

//
// MessageId: ERROR_SXS_XML_E_INVALIDENCODING
//
// MessageText:
//
// Manifest Parse Error : System does not support the specified encoding.
//
#define ERROR_SXS_XML_E_INVALIDENCODING  ((ULONG)0x000036F3L)

//
// MessageId: ERROR_SXS_XML_E_INVALIDSWITCH
//
// MessageText:
//
// Manifest Parse Error : Switch from current encoding to specified encoding not supported.
//
#define ERROR_SXS_XML_E_INVALIDSWITCH    ((ULONG)0x000036F4L)

//
// MessageId: ERROR_SXS_XML_E_BADXMLCASE
//
// MessageText:
//
// Manifest Parse Error : The name 'xml' is reserved and must be lower case.
//
#define ERROR_SXS_XML_E_BADXMLCASE       ((ULONG)0x000036F5L)

//
// MessageId: ERROR_SXS_XML_E_INVALID_STANDALONE
//
// MessageText:
//
// Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.
//
#define ERROR_SXS_XML_E_INVALID_STANDALONE ((ULONG)0x000036F6L)

//
// MessageId: ERROR_SXS_XML_E_UNEXPECTED_STANDALONE
//
// MessageText:
//
// Manifest Parse Error : The standalone attribute cannot be used in external entities.
//
#define ERROR_SXS_XML_E_UNEXPECTED_STANDALONE ((ULONG)0x000036F7L)

//
// MessageId: ERROR_SXS_XML_E_INVALID_VERSION
//
// MessageText:
//
// Manifest Parse Error : Invalid version number.
//
#define ERROR_SXS_XML_E_INVALID_VERSION  ((ULONG)0x000036F8L)

//
// MessageId: ERROR_SXS_XML_E_MISSINGEQUALS
//
// MessageText:
//
// Manifest Parse Error : Missing equals sign between attribute and attribute value.
//
#define ERROR_SXS_XML_E_MISSINGEQUALS    ((ULONG)0x000036F9L)

//
// MessageId: ERROR_SXS_PROTECTION_RECOVERY_FAILED
//
// MessageText:
//
// Assembly Protection Error: Unable to recover the specified assembly.
//
#define ERROR_SXS_PROTECTION_RECOVERY_FAILED ((ULONG)0x000036FAL)

//
// MessageId: ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT
//
// MessageText:
//
// Assembly Protection Error: The public key for an assembly was too short to be allowed.
//
#define ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT ((ULONG)0x000036FBL)

//
// MessageId: ERROR_SXS_PROTECTION_CATALOG_NOT_VALID
//
// MessageText:
//
// Assembly Protection Error: The catalog for an assembly is not valid, or does not match the assembly's manifest.
//
#define ERROR_SXS_PROTECTION_CATALOG_NOT_VALID ((ULONG)0x000036FCL)

//
// MessageId: ERROR_SXS_UNTRANSLATABLE_HRESULT
//
// MessageText:
//
// An HRESULT could not be translated to a corresponding Win32 error code.
//
#define ERROR_SXS_UNTRANSLATABLE_HRESULT ((ULONG)0x000036FDL)

//
// MessageId: ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING
//
// MessageText:
//
// Assembly Protection Error: The catalog for an assembly is missing.
//
#define ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING ((ULONG)0x000036FEL)

//
// MessageId: ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE
//
// MessageText:
//
// The supplied assembly identity is missing one or more attributes which must be present in this context.
//
#define ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE ((ULONG)0x000036FFL)

//
// MessageId: ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME
//
// MessageText:
//
// The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.
//
#define ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME ((ULONG)0x00003700L)

//
// MessageId: ERROR_SXS_ASSEMBLY_MISSING
//
// MessageText:
//
// The referenced assembly could not be found.
//
#define ERROR_SXS_ASSEMBLY_MISSING       ((ULONG)0x00003701L)

//
// MessageId: ERROR_SXS_CORRUPT_ACTIVATION_STACK
//
// MessageText:
//
// The activation context activation stack for the running thread of execution is corrupt.
//
#define ERROR_SXS_CORRUPT_ACTIVATION_STACK ((ULONG)0x00003702L)

//
// MessageId: ERROR_SXS_CORRUPTION
//
// MessageText:
//
// The application isolation metadata for this process or thread has become corrupt.
//
#define ERROR_SXS_CORRUPTION             ((ULONG)0x00003703L)

//
// MessageId: ERROR_SXS_EARLY_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated is not the most recently activated one.
//
#define ERROR_SXS_EARLY_DEACTIVATION     ((ULONG)0x00003704L)

//
// MessageId: ERROR_SXS_INVALID_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated is not active for the current thread of execution.
//
#define ERROR_SXS_INVALID_DEACTIVATION   ((ULONG)0x00003705L)

//
// MessageId: ERROR_SXS_MULTIPLE_DEACTIVATION
//
// MessageText:
//
// The activation context being deactivated has already been deactivated.
//
#define ERROR_SXS_MULTIPLE_DEACTIVATION  ((ULONG)0x00003706L)

//
// MessageId: ERROR_SXS_PROCESS_TERMINATION_REQUESTED
//
// MessageText:
//
// A component used by the isolation facility has requested to terminate the process.
//
#define ERROR_SXS_PROCESS_TERMINATION_REQUESTED ((ULONG)0x00003707L)

//
// MessageId: ERROR_SXS_RELEASE_ACTIVATION_CONTEXT
//
// MessageText:
//
// A kernel mode component is releasing a reference on an activation context.
//
#define ERROR_SXS_RELEASE_ACTIVATION_CONTEXT ((ULONG)0x00003708L)

//
// MessageId: ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY
//
// MessageText:
//
// The activation context of system default assembly could not be generated.
//
#define ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY ((ULONG)0x00003709L)

//
// MessageId: ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE
//
// MessageText:
//
// The value of an attribute in an identity is not within the legal range.
//
#define ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE ((ULONG)0x0000370AL)

//
// MessageId: ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME
//
// MessageText:
//
// The name of an attribute in an identity is not within the legal range.
//
#define ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME ((ULONG)0x0000370BL)

//
// MessageId: ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE
//
// MessageText:
//
// An identity contains two definitions for the same attribute.
//
#define ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE ((ULONG)0x0000370CL)

//
// MessageId: ERROR_SXS_IDENTITY_PARSE_ERROR
//
// MessageText:
//
// The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.
//
#define ERROR_SXS_IDENTITY_PARSE_ERROR   ((ULONG)0x0000370DL)

//
// MessageId: ERROR_EVT_INVALID_CHANNEL_PATH
//
// MessageText:
//
// The specified channel path is invalid. See extended error info for more details.
//
#define ERROR_EVT_INVALID_CHANNEL_PATH   ((ULONG)0x00003A98L)

//
// MessageId: ERROR_EVT_INVALID_QUERY
//
// MessageText:
//
// The specified query is invalid. See extended error info for more details.
//
#define ERROR_EVT_INVALID_QUERY          ((ULONG)0x00003A99L)

//
// MessageId: ERROR_EVT_PUBLISHER_MANIFEST_NOT_FOUND
//
// MessageText:
//
// The publisher did indicate they have a manifest/resource but a manifest/resource could not be found.
//
#define ERROR_EVT_PUBLISHER_MANIFEST_NOT_FOUND ((ULONG)0x00003A9AL)

//
// MessageId: ERROR_EVT_PUBLISHER_MANIFEST_NOT_SPECIFIED
//
// MessageText:
//
// The publisher does not have a manifest and is performing an operation which requires they have a manifest.
//
#define ERROR_EVT_PUBLISHER_MANIFEST_NOT_SPECIFIED ((ULONG)0x00003A9BL)

//
// MessageId: ERROR_EVT_NO_REGISTERED_TEMPLATE
//
// MessageText:
//
// There is no registered template for specified event id.
//
#define ERROR_EVT_NO_REGISTERED_TEMPLATE ((ULONG)0x00003A9CL)

//
// MessageId: ERROR_EVT_EVENT_CHANNEL_MISMATCH
//
// MessageText:
//
// The specified event was declared in the manifest to go a different channel than the one this publisher handle is bound to.
//
#define ERROR_EVT_EVENT_CHANNEL_MISMATCH ((ULONG)0x00003A9DL)

//
// MessageId: ERROR_EVT_UNEXPECTED_VALUE_TYPE
//
// MessageText:
//
// The type of a specified substitution value does not match the type expected from the template definition.
//
#define ERROR_EVT_UNEXPECTED_VALUE_TYPE  ((ULONG)0x00003A9EL)

//
// MessageId: ERROR_EVT_UNEXPECTED_NUM_VALUES
//
// MessageText:
//
// The number of specified substitution values does not match the number expected from the template definition.
//
#define ERROR_EVT_UNEXPECTED_NUM_VALUES  ((ULONG)0x00003A9FL)

//
// MessageId: ERROR_EVT_CHANNEL_NOT_FOUND
//
// MessageText:
//
// The specified channel could not be found. Check channel configuration.
//
#define ERROR_EVT_CHANNEL_NOT_FOUND      ((ULONG)0x00003AA0L)

//
// MessageId: ERROR_EVT_MALFORMED_XML_TEXT
//
// MessageText:
//
// The specified xml text was not well-formed. See Extended Error for more details.
//
#define ERROR_EVT_MALFORMED_XML_TEXT     ((ULONG)0x00003AA1L)

//
// MessageId: ERROR_EVT_CHANNEL_PATH_TOO_GENERAL
//
// MessageText:
//
// The specified channel path selects more than one instance of a channel. The operation requires that only one channel be selected. It may be necessary to scope channel path to version / publicKeyToken to select only one instance.
//
#define ERROR_EVT_CHANNEL_PATH_TOO_GENERAL ((ULONG)0x00003AA2L)

//
// MessageId: E_NOTIMPL
//
// MessageText:
//
// Not implemented
//
#define E_NOTIMPL                        ((ULONG)0x80000001L)

//
// MessageId: E_ABORT
//
// MessageText:
//
// Operation aborted
//
#define E_ABORT                          ((ULONG)0x80004004L)

//
// MessageId: E_FAIL
//
// MessageText:
//
// Unspecified error
//
#define E_FAIL                           ((ULONG)0x80004005L)

//
// MessageId: E_UNEXPECTED
//
// MessageText:
//
// Catastrophic failure
//
#define E_UNEXPECTED                     ((ULONG)0x8000FFFFL)

//
// MessageId: E_OUTOFMEMORY
//
// MessageText:
//
// Out of memory
//
#define E_OUTOFMEMORY                    ((ULONG)0x8007000EL)

//
// MessageId: E_INVALIDARG
//
// MessageText:
//
// One or more arguments are invalid
//
#define E_INVALIDARG                     ((ULONG)0x80070057L)

//
// MessageId: E_HANDLE
//
// MessageText:
//
// Invalid handle
//
#define E_HANDLE                         ((ULONG)0x80070006L)

//
// MessageId: E_ACCESSDENIED
//
// MessageText:
//
// General access denied error
//
#define E_ACCESSDENIED                   ((ULONG)0x80070005L)

//
// MessageId: OLE_E_OLEVERB
//
// MessageText:
//
// Invalid OLEVERB structure
//
#define OLE_E_OLEVERB                    ((ULONG)0x80040000L)

//
// MessageId: OLE_E_ADVF
//
// MessageText:
//
// Invalid advise flags
//
#define OLE_E_ADVF                       ((ULONG)0x80040001L)

//
// MessageId: OLE_E_ENUM_NOMORE
//
// MessageText:
//
// Can't enumerate any more, because the associated data is missing
//
#define OLE_E_ENUM_NOMORE                ((ULONG)0x80040002L)

//
// MessageId: OLE_E_ADVISENOTSUPPORTED
//
// MessageText:
//
// This implementation doesn't take advises
//
#define OLE_E_ADVISENOTSUPPORTED         ((ULONG)0x80040003L)

//
// MessageId: OLE_E_NOCONNECTION
//
// MessageText:
//
// There is no connection for this connection ID
//
#define OLE_E_NOCONNECTION               ((ULONG)0x80040004L)

//
// MessageId: OLE_E_NOTRUNNING
//
// MessageText:
//
// Need to run the object to perform this operation
//
#define OLE_E_NOTRUNNING                 ((ULONG)0x80040005L)

//
// MessageId: OLE_E_NOCACHE
//
// MessageText:
//
// There is no cache to operate on
//
#define OLE_E_NOCACHE                    ((ULONG)0x80040006L)

//
// MessageId: OLE_E_BLANK
//
// MessageText:
//
// Uninitialized object
//
#define OLE_E_BLANK                      ((ULONG)0x80040007L)

//
// MessageId: OLE_E_CLASSDIFF
//
// MessageText:
//
// Linked object's source class has changed
//
#define OLE_E_CLASSDIFF                  ((ULONG)0x80040008L)

//
// MessageId: OLE_E_CANT_GETMONIKER
//
// MessageText:
//
// Not able to get the moniker of the object
//
#define OLE_E_CANT_GETMONIKER            ((ULONG)0x80040009L)

//
// MessageId: OLE_E_CANT_BINDTOSOURCE
//
// MessageText:
//
// Not able to bind to the source
//
#define OLE_E_CANT_BINDTOSOURCE          ((ULONG)0x8004000AL)

//
// MessageId: OLE_E_STATIC
//
// MessageText:
//
// Object is static; operation not allowed
//
#define OLE_E_STATIC                     ((ULONG)0x8004000BL)

//
// MessageId: OLE_E_PROMPTSAVECANCELLED
//
// MessageText:
//
// User canceled out of save dialog
//
#define OLE_E_PROMPTSAVECANCELLED        ((ULONG)0x8004000CL)

//
// MessageId: OLE_E_INVALIDRECT
//
// MessageText:
//
// Invalid rectangle
//
#define OLE_E_INVALIDRECT                ((ULONG)0x8004000DL)

//
// MessageId: OLE_E_WRONGCOMPOBJ
//
// MessageText:
//
// compobj.dll is too old for the ole2.dll initialized
//
#define OLE_E_WRONGCOMPOBJ               ((ULONG)0x8004000EL)

//
// MessageId: OLE_E_INVALIDHWND
//
// MessageText:
//
// Invalid window handle
//
#define OLE_E_INVALIDHWND                ((ULONG)0x8004000FL)

//
// MessageId: OLE_E_NOT_INPLACEACTIVE
//
// MessageText:
//
// Object is not in any of the inplace active states
//
#define OLE_E_NOT_INPLACEACTIVE          ((ULONG)0x80040010L)

//
// MessageId: OLE_E_CANTCONVERT
//
// MessageText:
//
// Not able to convert object
//
#define OLE_E_CANTCONVERT                ((ULONG)0x80040011L)

//
// MessageId: OLE_E_NOSTORAGE
//
// MessageText:
//
// Not able to perform the operation because object is not given storage yet
//
#define OLE_E_NOSTORAGE                  ((ULONG)0x80040012L)

//
// MessageId: DV_E_FORMATETC
//
// MessageText:
//
// Invalid FORMATETC structure
//
#define DV_E_FORMATETC                   ((ULONG)0x80040064L)

//
// MessageId: DV_E_DVTARGETDEVICE
//
// MessageText:
//
// Invalid DVTARGETDEVICE structure
//
#define DV_E_DVTARGETDEVICE              ((ULONG)0x80040065L)

//
// MessageId: DV_E_STGMEDIUM
//
// MessageText:
//
// Invalid STDGMEDIUM structure
//
#define DV_E_STGMEDIUM                   ((ULONG)0x80040066L)

//
// MessageId: DV_E_STATDATA
//
// MessageText:
//
// Invalid STATDATA structure
//
#define DV_E_STATDATA                    ((ULONG)0x80040067L)

//
// MessageId: DV_E_LINDEX
//
// MessageText:
//
// Invalid lindex
//
#define DV_E_LINDEX                      ((ULONG)0x80040068L)

//
// MessageId: DV_E_TYMED
//
// MessageText:
//
// Invalid tymed
//
#define DV_E_TYMED                       ((ULONG)0x80040069L)

//
// MessageId: DV_E_CLIPFORMAT
//
// MessageText:
//
// Invalid clipboard format
//
#define DV_E_CLIPFORMAT                  ((ULONG)0x8004006AL)

//
// MessageId: DV_E_DVASPECT
//
// MessageText:
//
// Invalid aspect(s)
//
#define DV_E_DVASPECT                    ((ULONG)0x8004006BL)

//
// MessageId: DV_E_DVTARGETDEVICE_SIZE
//
// MessageText:
//
// tdSize parameter of the DVTARGETDEVICE structure is invalid
//
#define DV_E_DVTARGETDEVICE_SIZE         ((ULONG)0x8004006CL)

//
// MessageId: DV_E_NOIVIEWOBJECT
//
// MessageText:
//
// Object doesn't support IViewObject interface
//
#define DV_E_NOIVIEWOBJECT               ((ULONG)0x8004006DL)

//
// MessageId: DRAGDROP_E_NOTREGISTERED
//
// MessageText:
//
// Trying to revoke a drop target that has not been registered
//
#define DRAGDROP_E_NOTREGISTERED         ((ULONG)0x80040100L)

//
// MessageId: DRAGDROP_E_ALREADYREGISTERED
//
// MessageText:
//
// This window has already been registered as a drop target
//
#define DRAGDROP_E_ALREADYREGISTERED     ((ULONG)0x80040101L)

//
// MessageId: DRAGDROP_E_INVALIDHWND
//
// MessageText:
//
// Invalid window handle
//
#define DRAGDROP_E_INVALIDHWND           ((ULONG)0x80040102L)

//
// MessageId: CLASS_E_NOAGGREGATION
//
// MessageText:
//
// Class does not support aggregation (or class object is remote)
//
#define CLASS_E_NOAGGREGATION            ((ULONG)0x80040110L)

//
// MessageId: CLASS_E_CLASSNOTAVAILABLE
//
// MessageText:
//
// ClassFactory cannot supply requested class
//
#define CLASS_E_CLASSNOTAVAILABLE        ((ULONG)0x80040111L)

//
// MessageId: CLASS_E_NOTLICENSED
//
// MessageText:
//
// Class is not licensed for use
//
#define CLASS_E_NOTLICENSED              ((ULONG)0x80040112L)

