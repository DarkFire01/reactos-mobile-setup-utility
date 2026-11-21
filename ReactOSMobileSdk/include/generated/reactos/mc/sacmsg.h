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


//
// Define the severity codes
//


//
// MessageId: SAC_INIT_STATUS
//
// MessageText:
//
// 
// Computer is booting, SAC started and initialized.
// 
// Use the "ch -?" command for information about using channels.
// Use the "?" command for general help.
// 
//
#define SAC_INIT_STATUS                  0x00000001L

//
// MessageId: SAC_NEWLINE
//
// MessageText:
//
// 
//
#define SAC_NEWLINE                      0x00000002L

//
// MessageId: SAC_PROMPT
//
// MessageText:
//
// SAC>%0
//
#define SAC_PROMPT                       0x00000003L

//
// MessageId: SACDRV_4
//
// MessageText:
//
// The SAC is unavailable, it was directly unloaded.
//
#define SACDRV_4                         0x00000004L

//
// MessageId: SACDRV_5
//
// MessageText:
//
// The SAC will become unavailable soon.  The computer is shutting down.
// 
//
#define SACDRV_5                         0x00000005L

//
// MessageId: SACDRV_6
//
// MessageText:
//
// A parameter was incorrect or missing.  Try the 'help' command for more details.
//
#define SACDRV_6                         0x00000006L

//
// MessageId: SACDRV_7
//
// MessageText:
//
// Thread information is now ON.
//
#define SACDRV_7                         0x00000007L

//
// MessageId: SACDRV_8
//
// MessageText:
//
// Thread information is now OFF.
//
#define SACDRV_8                         0x00000008L

//
// MessageId: SACDRV_9
//
// MessageText:
//
// Paging is now ON.
//
#define SACDRV_9                         0x00000009L

//
// MessageId: SACDRV_10
//
// MessageText:
//
// Paging is now OFF.
//
#define SACDRV_10                        0x0000000AL

//
// MessageId: SAC_OUT_OF_MEMORY_PROMPT
//
// MessageText:
//
// THIS LOOKS LIKE A BUG???
//
#define SAC_OUT_OF_MEMORY_PROMPT         0x0000000BL

//
// MessageId: SACDRV_12
//
// MessageText:
//
// d                    Dump the current kernel log.
//
#define SACDRV_12                        0x0000000CL

//
// MessageId: SACDRV_13
//
// MessageText:
//
// f                    Toggle detailed or abbreviated tlist info.
//
#define SACDRV_13                        0x0000000DL

//
// MessageId: SACDRV_14
//
// MessageText:
//
// ? or help            Display this list.
//
#define SACDRV_14                        0x0000000EL

//
// MessageId: SACDRV_15
//
// MessageText:
//
// i                    List all IP network numbers and their IP addresses.
//
#define SACDRV_15                        0x0000000FL

//
// MessageId: SACDRV_16
//
// MessageText:
//
// i <#> <ip> <subnet> <gateway> Set IP addr., subnet and gateway.
//
#define SACDRV_16                        0x00000010L

//
// MessageId: SACDRV_18
//
// MessageText:
//
// k <pid>              Kill the given process.
//
#define SACDRV_18                        0x00000012L

//
// MessageId: SACDRV_19
//
// MessageText:
//
// l <pid>              Lower the priority of a process to the lowest possible.
//
#define SACDRV_19                        0x00000013L

//
// MessageId: SACDRV_20
//
// MessageText:
//
// m <pid> <MB-allow>   Limit the memory usage of a process to <MB-allow>.
//
#define SACDRV_20                        0x00000014L

//
// MessageId: SACDRV_21
//
// MessageText:
//
// p                    Toggle paging the display.
//
#define SACDRV_21                        0x00000015L

//
// MessageId: SACDRV_22
//
// MessageText:
//
// r <pid>              Raise the priority of a process by one.
//
#define SACDRV_22                        0x00000016L

//
// MessageId: SACDRV_23
//
// MessageText:
//
// s                    Display the current time and date (24 hour clock used).
//
#define SACDRV_23                        0x00000017L

//
// MessageId: SACDRV_24
//
// MessageText:
//
// s mm/dd/yyyy hh:mm   Set the current time and date (24 hour clock used).
//
#define SACDRV_24                        0x00000018L

//
// MessageId: SACDRV_25
//
// MessageText:
//
// t                    Tlist.
//
#define SACDRV_25                        0x00000019L

//
// MessageId: SACDRV_27
//
// MessageText:
//
// restart              Restart the system immediately.
//
#define SACDRV_27                        0x0000001BL

//
// MessageId: SACDRV_28
//
// MessageText:
//
// shutdown             Shutdown the system immediately.
//
#define SACDRV_28                        0x0000001CL

//
// MessageId: SACDRV_29
//
// MessageText:
//
// crashdump            Crash the system. You must have crash dump enabled.
//
#define SACDRV_29                        0x0000001DL

//
// MessageId: SACDRV_31
//
// MessageText:
//
// id                   Display the computer identification information.
//
#define SACDRV_31                        0x0000001FL

//
// MessageId: SACDRV_32
//
// MessageText:
//
// lock                 Lock access to Command Prompt channels.
//
#define SACDRV_32                        0x00000020L

//
// MessageId: SAC_FAIL_PROMPT
//
// MessageText:
//
// Failed with status 0x%%X.
//
#define SAC_FAIL_PROMPT                  0x00000030L

//
// MessageId: SACDRV_49
//
// MessageText:
//
// Date: %%02d/%%02d/%%02d  Time (GMT): %%02d:%%02d:%%02d:%%04d
//
#define SACDRV_49                        0x00000031L

//
// MessageId: SACDRV_50
//
// MessageText:
//
// SAC could not retrieve the IP Address.
//
#define SACDRV_50                        0x00000032L

//
// MessageId: SACDRV_51
//
// MessageText:
//
// SAC could not clear the existing IP Address.
//
#define SACDRV_51                        0x00000033L

//
// MessageId: SACDRV_52
//
// MessageText:
//
// SAC could not set the IP Address.
//
#define SACDRV_52                        0x00000034L

//
// MessageId: SACDRV_54
//
// MessageText:
//
// SAC successfully set the IP Address, subnet mask, and gateway.
//
#define SACDRV_54                        0x00000036L

//
// MessageId: SACDRV_55
//
// MessageText:
//
// SAC failed to terminate the process.
//
#define SACDRV_55                        0x00000037L

//
// MessageId: SACDRV_56
//
// MessageText:
//
// SAC successfully terminated the process.
//
#define SACDRV_56                        0x00000038L

//
// MessageId: SACDRV_57
//
// MessageText:
//
// SAC failed to lower the process priority.
//
#define SACDRV_57                        0x00000039L

//
// MessageId: SACDRV_58
//
// MessageText:
//
// SAC successfully lowered the process priority.
//
#define SACDRV_58                        0x0000003AL

//
// MessageId: SACDRV_59
//
// MessageText:
//
// SAC failed to raise the process priority.
//
#define SACDRV_59                        0x0000003BL

//
// MessageId: SACDRV_60
//
// MessageText:
//
// SAC successfully raised the process priority.
//
#define SACDRV_60                        0x0000003CL

//
// MessageId: SACDRV_61
//
// MessageText:
//
// SAC failed to limit the available process memory.
//
#define SACDRV_61                        0x0000003DL

//
// MessageId: SACDRV_62
//
// MessageText:
//
// SAC successfully limited the available process memory.
//
#define SACDRV_62                        0x0000003EL

//
// MessageId: SACDRV_63
//
// MessageText:
//
// SAC cannot raise the priority of a process that was not previously lowered.
//
#define SACDRV_63                        0x0000003FL

//
// MessageId: SACDRV_64
//
// MessageText:
//
// SAC cannot raise the process priority any higher.
//
#define SACDRV_64                        0x00000040L

//
// MessageId: SAC_SHUTDOWN_FAIL_PROMPT
//
// MessageText:
//
// SAC failed to shutdown the system.
//
#define SAC_SHUTDOWN_FAIL_PROMPT         0x00000041L

//
// MessageId: SAC_RESTART_FAIL_PROMPT
//
// MessageText:
//
// SAC failed to restart the system.
//
#define SAC_RESTART_FAIL_PROMPT          0x00000042L

//
// MessageId: SACDRV_67
//
// MessageText:
//
// SAC failed to crashdump the system.
//
#define SACDRV_67                        0x00000043L

//
// MessageId: SACDRV_68
//
// MessageText:
//
// SAC failed to retrieve the task list.
//
#define SACDRV_68                        0x00000044L

//
// MessageId: SACDRV_69
//
// MessageText:
//
// memory: %%4ld kb  uptime:%%3ld %%2ld:%%02ld:%%02ld.%%03ld
// 
// 
//
#define SACDRV_69                        0x00000045L

//
// MessageId: SACDRV_70
//
// MessageText:
//
// No pagefile in use.
//
#define SACDRV_70                        0x00000046L

//
// MessageId: SACDRV_71
//
// MessageText:
//
// PageFile: %%wZ
//
#define SACDRV_71                        0x00000047L

//
// MessageId: SACDRV_72
//
// MessageText:
//
//         Current Size: %%6ld kb  Total Used: %%6ld kb   Peak Used %%6ld kb
//
#define SACDRV_72                        0x00000048L

//
// MessageId: SACDRV_73
//
// MessageText:
//
// 
//  Memory:%%7ldK Avail:%%7ldK  TotalWs:%%7ldK InRam Kernel:%%5ldK P:%%5ldK
//
#define SACDRV_73                        0x00000049L

//
// MessageId: SACDRV_74
//
// MessageText:
//
//  Commit:%%7ldK/%%7ldK Limit:%%7ldK Peak:%%7ldK  Pool N:%%5ldK P:%%5ldK
//
#define SACDRV_74                        0x0000004AL

//
// MessageId: SACDRV_75
//
// MessageText:
//
//     User Time   Kernel Time    Ws   Faults  Commit Pri Hnd Thd  Pid Name
//
#define SACDRV_75                        0x0000004BL

//
// MessageId: SACDRV_76
//
// MessageText:
//
//                            %%6ld %%8ld                          File Cache
//
#define SACDRV_76                        0x0000004CL

//
// MessageId: SACDRV_77
//
// MessageText:
//
// %%3ld:%%02ld:%%02ld.%%03ld %%3ld:%%02ld:%%02ld.%%03ld%%6ld %%8ld %%7ld %%2ld %%4ld %%3ld %%4ld %%wZ
//
#define SACDRV_77                        0x0000004DL

//
// MessageId: SACDRV_78
//
// MessageText:
//
// %%3ld:%%02ld:%%02ld.%%03ld %%3ld:%%02ld:%%02ld.%%03ld
//
#define SACDRV_78                        0x0000004EL

//
// MessageId: SACDRV_79
//
// MessageText:
//
// pid:%%3lx pri:%%2ld Hnd:%%5ld Pf:%%7ld Ws:%%7ldK %%wZ
//
#define SACDRV_79                        0x0000004FL

//
// MessageId: SACDRV_80
//
// MessageText:
//
//  tid pri Ctx Swtch StrtAddr    User Time  Kernel Time  State
//
#define SACDRV_80                        0x00000050L

//
// MessageId: SACDRV_81
//
// MessageText:
//
//  %%3lx  %%2ld %%9ld %%p %%2ld:%%02ld:%%02ld.%%03ld %%2ld:%%02ld:%%02ld.%%03ld %%s%%s
//
#define SACDRV_81                        0x00000051L

//
// MessageId: SACDRV_82
//
// MessageText:
//
// ----Press <Enter> for more----
//
#define SACDRV_82                        0x00000052L

//
// MessageId: SACDRV_83
//
// MessageText:
//
// SAC is retrieving IP Addresses...
//
#define SACDRV_83                        0x00000053L

//
// MessageId: SACDRV_84
//
// MessageText:
//
// Could not retrieve IP Address(es).
//
#define SACDRV_84                        0x00000054L

//
// MessageId: SACDRV_85
//
// MessageText:
//
// There are no IP Addresses available.
//
#define SACDRV_85                        0x00000055L

//
// MessageId: SACDRV_86
//
// MessageText:
//
// Net: %%d, Ip=%%d.%%d.%%d.%%d  Subnet=%%d.%%d.%%d.%%d  Gateway=%%d.%%d.%%d.%%d
//
#define SACDRV_86                        0x00000056L

//
// MessageId: SACDRV_87
//
// MessageText:
//
// Date: %%02d/%%02d/%%02d  Time (GMT): %%02d:%%02d
//
#define SACDRV_87                        0x00000057L

//
// MessageId: SACDRV_88
//
// MessageText:
//
// The year is restricted from 1980 to 2099.
//
#define SACDRV_88                        0x00000058L

//
// MessageId: SACDRV_89
//
// MessageText:
//
// That process has been killed and is being cleaned up by the system.
//
#define SACDRV_89                        0x00000059L

//
// MessageId: SACDRV_90
//
// MessageText:
//
// A duplicate process id is being cleaned up by the system.  Try the
// command again in a few seconds.
//
#define SACDRV_90                        0x0000005AL

//
// MessageId: SACDRV_92
//
// MessageText:
//
//            Computer Name: %%ws
//
#define SACDRV_92                        0x0000005CL

//
// MessageId: SACDRV_93
//
// MessageText:
//
//            Computer GUID: %%ws
//
#define SACDRV_93                        0x0000005DL

//
// MessageId: SACDRV_94
//
// MessageText:
//
//   Processor Architecture: %%ws
//
#define SACDRV_94                        0x0000005EL

//
// MessageId: SACDRV_95
//
// MessageText:
//
//             Build Number: %%ws
//
#define SACDRV_95                        0x0000005FL

//
// MessageId: SACDRV_96
//
// MessageText:
//
//                  Product: %%ws
//
#define SACDRV_96                        0x00000060L

//
// MessageId: SACDRV_97
//
// MessageText:
//
//     Applied Service Pack: %%ws
//
#define SACDRV_97                        0x00000061L

//
// MessageId: SAC_NO_DATA_MSG
//
// MessageText:
//
// None%0
//
#define SAC_NO_DATA_MSG                  0x00000062L

//
// MessageId: SACDRV_99
//
// MessageText:
//
//           Version Number: %%ws
//
#define SACDRV_99                        0x00000063L

//
// MessageId: SAC_DATACENTER_SUITE_MSG
//
// MessageText:
//
// Windows Server 2003 Datacenter Edition%0
//
#define SAC_DATACENTER_SUITE_MSG         0x00000064L

//
// MessageId: SAC_EMBEDDED_SUITE_MSG
//
// MessageText:
//
// Windows Server 2003 Embedded%0
//
#define SAC_EMBEDDED_SUITE_MSG           0x00000065L

//
// MessageId: SAC_ENTERPRISE_SUITE_MSG
//
// MessageText:
//
// Windows Server 2003 Enterprise Edition%0
//
#define SAC_ENTERPRISE_SUITE_MSG         0x00000066L

//
// MessageId: SAC_NO_SUITE_MSG
//
// MessageText:
//
// Windows Server 2003%0
//
#define SAC_NO_SUITE_MSG                 0x00000067L

//
// MessageId: SACDRV_104
//
// MessageText:
//
// Computer identification information is unavailable.
//
#define SACDRV_104                       0x00000068L

//
// MessageId: SAC_UNKNOWN_COMMAND
//
// MessageText:
//
// Unrecognized command.  Try the 'help' command for more details.
//
#define SAC_UNKNOWN_COMMAND              0x00000069L

//
// MessageId: SACDRV_106
//
// MessageText:
//
// Error: The SAC channel cannot be closed.
//
#define SACDRV_106                       0x0000006AL

//
// MessageId: SACDRV_107
//
// MessageText:
//
// Error: Could not find a channel with that name.
//
#define SACDRV_107                       0x0000006BL

//
// MessageId: SACDRV_108
//
// MessageText:
//
// Channel List
// 
// (Use "ch -?" for information on using channels)
// 
// # Status  Channel Name
//
#define SACDRV_108                       0x0000006CL

//
// MessageId: SACDRV_109
//
// MessageText:
//
// EVENT:   A new channel has been created.  Use "ch -?" for channel help.
// Channel: %%s
//
#define SACDRV_109                       0x0000006DL

//
// MessageId: SACDRV_110
//
// MessageText:
//
// EVENT:   A channel has been closed.
// Channel: %%s
//
#define SACDRV_110                       0x0000006EL

//
// MessageId: SACDRV_111
//
// MessageText:
//
// Name:                  %%s
// Description:           %%s
// Type:                  %%s
// Channel GUID:          %%08lx-%%04x-%%04x-%%02x%%02x-%%02x%%02x%%02x%%02x%%02x%%02x
// Application Type GUID: %%08lx-%%04x-%%04x-%%02x%%02x-%%02x%%02x%%02x%%02x%%02x%%02x
// 
// Press <esc><tab> for next channel.
// Press <esc><tab>0 to return to the SAC channel.
// Use any other key to view this channel.
// 
//
#define SACDRV_111                       0x0000006FL

//
// MessageId: SACDRV_112
//
// MessageText:
//
// ch                   Channel management commands.  Use ch -? for more help.
//
#define SACDRV_112                       0x00000070L

//
// MessageId: SAC_RESTART_TIME_PROMPT
//
// MessageText:
//
//   Time since last reboot: %%d:%%02d:%%02d
//
#define SAC_RESTART_TIME_PROMPT          0x00000071L

//
// MessageId: SAC_RESTART_PROMPT
//
// MessageText:
//
// SAC preparing to restart the system.
//
#define SAC_RESTART_PROMPT               0x00000072L

//
// MessageId: SAC_SHUTDOWN_PROMPT
//
// MessageText:
//
// SAC preparing to shutdown the system.
//
#define SAC_SHUTDOWN_PROMPT              0x00000073L

//
// MessageId: SACDRV_116
//
// MessageText:
//
// Error! Failed to remove channel!
// 
// Please contact your system administrator.
// 
//
#define SACDRV_116                       0x00000074L

//
// MessageId: SACDRV_119
//
// MessageText:
//
// cmd                  Create a Command Prompt channel.
//
#define SACDRV_119                       0x00000077L

//
// MessageId: SACDRV_120
//
// MessageText:
//
// Timeout: Unable to launch a Command Prompt.  The service responsible for
//          launching Command Prompt channels has timed out.  This may be
//          because the service is malfunctioning or is unresponsive.
//
#define SACDRV_120                       0x00000078L

//
// MessageId: SACDRV_121
//
// MessageText:
//
// The Command Prompt session was successfully launched.
//
#define SACDRV_121                       0x00000079L

//
// MessageId: SACDRV_128
//
// MessageText:
//
// Error: The SAC Command Console session failed to be created.
//
#define SACDRV_128                       0x00000080L

//
// MessageId: SACDRV_131
//
// MessageText:
//
// Error: Unable to launch a Command Prompt.  The service responsible for launching
//        Command Prompt channels has not yet registered.  This may be because the
//        service is not yet started, is disabled by the administrator, is
//        malfunctioning or is unresponsive.
//
#define SACDRV_131                       0x00000083L

//
// MessageId: SACDRV_132
//
// MessageText:
//
// EVENT: The CMD command is now available.
//
#define SACDRV_132                       0x00000084L

//
// MessageId: SACDRV_133
//
// MessageText:
//
// EVENT: The CMD command is unavailable.
//
#define SACDRV_133                       0x00000085L

//
// MessageId: SACDRV_134
//
// MessageText:
//
// EVENT:   An attempt was made to close a channel but failed.
// Channel: %%s
//
#define SACDRV_134                       0x00000086L

//
// MessageId: SACDRV_135
//
// MessageText:
//
// EVENT:   An attempt to close a channel failed because it is already closed.
// Channel: %%s
//
#define SACDRV_135                       0x00000087L

//
// MessageId: SACDRV_136
//
// MessageText:
//
// Channel management commands:
// 
// ch                   List all channels.
// 
// Status Legend: (AB)
// A: Channel operational status
//     'A' = Channel is active.
//     'I' = Channel is inactive.
// B: Channel Type
//     'V' = VT-UTF8 emulation.
//     'R' = Raw - no emulation.
// 
// ch -si <#>           Switch to a channel by its number.
// ch -sn <name>        Switch to a channel by its name.
// ch -ci <#>           Close a channel by its number.
// ch -cn <name>        Close a channel by its name.
// 
// Press <esc><tab> to select a channel.
// Press <esc><tab>0 to return to the SAC channel.
//
#define SACDRV_136                       0x00000088L

//
// MessageId: SACDRV_137
//
// MessageText:
//
// Error: There is no channel present at the specified index.
//
#define SACDRV_137                       0x00000089L

//
// MessageId: SAC_CHANNEL_NAME
//
// MessageText:
//
// SAC%0
//
#define SAC_CHANNEL_NAME                 0x00000090L

//
// MessageId: SAC_CHANNEL_DESCRIPTION
//
// MessageText:
//
// Special Administration Console%0
//
#define SAC_CHANNEL_DESCRIPTION          0x00000091L

//
// MessageId: SACDRV_146
//
// MessageText:
//
// Command Prompt%0
//
#define SACDRV_146                       0x00000092L

//
// MessageId: SACDRV_147
//
// MessageText:
//
// Locked access to all Command Prompt channels.
//
#define SACDRV_147                       0x00000093L

//
// MessageId: SACDRV_148
//
// MessageText:
//
// Launching of Command Prompt channels is disabled.
//
#define SACDRV_148                       0x00000094L

//
// MessageId: SACDRV_149
//
// MessageText:
//
// The specified subnet mask is invalid.
//
#define SACDRV_149                       0x00000095L

//
// MessageId: SACDRV_150
//
// MessageText:
//
// Error, missing network interface number.
//
#define SACDRV_150                       0x00000096L

//
// MessageId: SACDRV_151
//
// MessageText:
//
// The specified IP address is invalid.
//
#define SACDRV_151                       0x00000097L

//
// MessageId: SACDRV_152
//
// MessageText:
//
// The specified gateway IP address is invalid.
//
#define SACDRV_152                       0x00000098L

//
// MessageId: SAC_UNINITIALIZED_MSG
//
// MessageText:
//
// not yet initialized%0
//
#define SAC_UNINITIALIZED_MSG            0x00000099L

//
// MessageId: SACDRV_154
//
// MessageText:
//
// The maximum number of channels has been reached.
//
#define SACDRV_154                       0x0000009AL

