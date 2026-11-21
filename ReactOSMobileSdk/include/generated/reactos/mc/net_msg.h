// Romanian translation by 2011-2019 // Romanian translation by 2023-2024 Andrei Miloiu (miloiuandrei@gmail.com)
// Russian translation by Kudratov Olimjon (olim98@bk.ru)
// Spanish translation by Ismael Ferreras Morezuelas <2014-11-07>
// Turkish translation by 2015 Erdem Ersoy (eersoy93) (erdemersoy [at] erdemersoy [dot] net)
// Simplified Chinese translation by Henry Tang Ih 2016 (henrytang2@hotmail.com)
// Traditional Chinese translation by Henry Tang Ih 2016 (henrytang2@hotmail.com)
// Polish translation Updated by pithwz - Piotr Hetnarowicz (piotrhwz@gmail.com) (April, 2020)
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
// MessageId: MSG_ACCOUNTS_SYNTAX
//
// MessageText:
//
// NET ACCOUNTS [/FORCELOGOFF:{Minutes|NO}] [/MINPWLEN:Length]
//              [/MAXPWAGE:{Days|UNLIMITED}] [/MINPWAGE:Days]
//              [/UNIQUEPW:Count] [/DOMAIN]
//
#define MSG_ACCOUNTS_SYNTAX              ((DWORD)0x00002710L)

//
// MessageId: MSG_ACCOUNTS_HELP
//
// MessageText:
//
// NET ACCOUNTS updates the user accounts database and modifies password
// and logon requirements for all accounts.
// When used without parameters, NET ACCOUNTS displays the current settings for
// passwords, logon limitations, and domain information.
// 
// Two conditions are required in order for options used with
// NET ACCOUNTS to take effect.
// 
// - The password and logon requirements are only effective if user
//   accounts have been set up (user User Manager or the NET USER command).
// 
// - The Net Logon service must be running on all servers in the domain
//   that verify logon. Net Logon is started automatically when the
//   operating system starts.
// 
// /FORECELOGOFF:{minutes | NO}   Sets the number of minutes a user has before
//                                being forced to log off when the
//                                account expires or valid logon hours expire.
//                                NO, the default, prevents forced logoff.
// /MINPWLEN:length               Sets the minimum number of characters for
//                                a password. The range is 0-14 characters;
//                                the default is 6 characters.
// /MAXPWAGE:{days | UNLIMITED}   Sets the maximum numer of days that a
//                                password is valid. No limit is specified
//                                by using UNLIMITED. /MAXPWAGE cannot be less
//                                than /MINPWAGE. The range is 1-999; the
//                                default is to leave the value unchanged.
// /MINPWAGE:days                 Sets the minimum number of days that must
//                                pass before a user can change a password.
//                                A value of 0 sets no minimum time. The range
//                                is 0-999; the default is 0 days. /MINPWAGE
//                                cannot be more than /MAXPWAGE.
// /UNIQUEPW:number               Requires that a users passwords be unique
//                                through the specified number of password
//                                changes. The maximum value is 24.
// /DOMAIN                        Performs the operation on a domain
//                                controller of the current domain. Otherwise,
//                                the operation is performed on the local
//                                computer.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_ACCOUNTS_HELP                ((DWORD)0x00002711L)

//
// MessageId: MSG_COMPUTER_SYNTAX
//
// MessageText:
//
// NET COMPUTER \\computername {/ADD | /DEL}
//
#define MSG_COMPUTER_SYNTAX              ((DWORD)0x00002712L)

//
// MessageId: MSG_COMPUTER_HELP
//
// MessageText:
//
// NET COMPUTER adds or deletes computers from a domain database. This
// command is available only on server operating systems.
// 
// \\computername   Specifies the computer to add or delete from
//                  the domain.
// /ADD             Adds the specified computer to the domain.
// /DEL             Removes the specified computer from the domain.
//
#define MSG_COMPUTER_HELP                ((DWORD)0x00002713L)

//
// MessageId: MSG_CONFIG_SYNTAX
//
// MessageText:
//
// NET CONFIG [SERVER | WORKSTATION]
//
#define MSG_CONFIG_SYNTAX                ((DWORD)0x00002714L)

//
// MessageId: MSG_CONFIG_HELP
//
// MessageText:
//
// NET CONFIG displays coniguration information of the Workstation or
// Server service. When used without the WORKSTATION or SERVER switch,
// it displays a list of configurable services. To get help with
// configuring a service, type NET HELP CONFIG service.
// 
// SERVER        Displays information about the configuration of the
//               Server service.
// WORKSTATION   Displays information about the configuration of the
//               Workstation service.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_CONFIG_HELP                  ((DWORD)0x00002715L)

//
// MessageId: MSG_CONFIG_SERVER_SYNTAX
//
// MessageText:
//
// NET CONFIG SERVER [/AUTODISCONNECT:time] [/SRVCOMMENT:"text"]
//                   [/HIDDEN:{YES | NO}]
//
#define MSG_CONFIG_SERVER_SYNTAX         ((DWORD)0x00002716L)

//
// MessageId: MSG_CONFIG_SERVER_HELP
//
// MessageText:
//
// NET CONFIG SERVER displays or changes settings for the Server service.
// 
// /AUTODISCONNECT:time    Sets the maximum number of minutes a user's
//                         session can be inactive before it is disconected.
//                         You can specify -1 to never disconnect. The range
//                         is -1-65535 minutes; the default is 15.
// /SRVCOMMENT:"text"      Adds a comment for the server that is displayed on
//                         screen and with the NET VIEW command.
//                         Enclose the text in quotation marks.
// /HIDDEN:{YES | NO}      Specifies whether the server's computer name
//                         appears on displays listings of servers. Note that
//                         hiding a serverdoes not alter the permissions
//                         on that server. The default is NO.
// 
// To display the current configuration for the Server service,
// type NET CONFIG SERVER without parameters.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_CONFIG_SERVER_HELP           ((DWORD)0x00002717L)

//
// MessageId: MSG_CONTINUE_SYNTAX
//
// MessageText:
//
// NET CONTINUE service
//
#define MSG_CONTINUE_SYNTAX              ((DWORD)0x00002718L)

//
// MessageId: MSG_CONTINUE_HELP
//
// MessageText:
//
// NET CONTINUE reactivates a service that has been suspended by NET PAUSE.
// 
// service             Is the paused service
//                     For example, one of the following:
//                     NET LOGON
//                     NT LM SECURITY SUPPORT PROVIDER
//                     SCHEDULE
//                     SERVER
//                     WORKSTATION
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_CONTINUE_HELP                ((DWORD)0x00002719L)

//
// MessageId: MSG_FILE_SYNTAX
//
// MessageText:
//
// NET FILE [id [/CLOSE]]
//
#define MSG_FILE_SYNTAX                  ((DWORD)0x0000271AL)

//
// MessageId: MSG_FILE_HELP
//
// MessageText:
//
// NET FILE
// ...
//
#define MSG_FILE_HELP                    ((DWORD)0x0000271BL)

//
// MessageId: MSG_GROUP_SYNTAX
//
// MessageText:
//
// NET GROUP [groupname [/COMMENT:"text"]] [/DOMAIN]
//           groupname {/ADD [/COMMENT:"text"] | /DELETE} [/DOMAIN]
//           groupname username [...] {/ADD | /DELETE} [/DOMAIN]
//
#define MSG_GROUP_SYNTAX                 ((DWORD)0x0000271CL)

//
// MessageId: MSG_GROUP_HELP
//
// MessageText:
//
// NET GROUP adds, displays or modifies global groups on servers. When
// used without parameters, it displays the groupnames on the server.
// 
// groupname        Is the name of the group to add, expand, or delete.
//                  Supply only a groupname to view a list of users
//                  in a group.
// /COMMENT:"text"  Adds a comment for a new or existing group.
//                  Enclose the text in quotation marks.
// /DOMAIN          Performs the operation on a domain controller
//                  of the current domain. Otherwise, the operation is
//                  performed on the local computer.
// username[ ...]   List one or more usernames to add to or remove from
//                  a group. Separate multiple username entries with a space.
// /ADD             Adds a group, or adds a username to a group.
// /DELETE          Removes a group, or removes a username from a group.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_GROUP_HELP                   ((DWORD)0x0000271DL)

//
// MessageId: MSG_HELP_SYNTAX
//
// MessageText:
//
// NET HELP command
//    - or -
// NET command /HELP
//
#define MSG_HELP_SYNTAX                  ((DWORD)0x0000271EL)

//
// MessageId: MSG_HELP_HELP
//
// MessageText:
//
//    The following commands are available:
// 
//    NET ACCOUNTS             NET HELP                 NET STOP
//    NET COMPUTER             NET HELPMSG              NET TIME
//    NET CONFIG               NET LOCALGROUP           NET USE
//    NET CONFIG SERVER        NET PAUSE                NET USER
//    NET CONFIG WORKSTATION   NET SESSION              NET VIEW
//    NET CONTINUE             NET SHARE
//    NET FILE                 NET START
//    NET GROUP                NET STATISTCS
// 
//    NET HELP SYNTAX explains how to read NET HELP syntax lines.
//    NET HELP command | MORE displays Help one screen at a time.
//
#define MSG_HELP_HELP                    ((DWORD)0x0000271FL)

//
// MessageId: MSG_HELPMSG_SYNTAX
//
// MessageText:
//
// NET HELPMSG message#
//
#define MSG_HELPMSG_SYNTAX               ((DWORD)0x00002720L)

//
// MessageId: MSG_HELPMSG_HELP
//
// MessageText:
//
// NET HELPMSG displays information about network messages (such as
// error, warning and alert messages). When you type NET HELPMSG and the numeric
// error (for example, "net helpmsg 2182"), you will get information about the
// message and suggested actions you can take to solve the problem.
// 
// message#   Is the numerical error with which you need help.
//
#define MSG_HELPMSG_HELP                 ((DWORD)0x00002721L)

//
// MessageId: MSG_LOCALGROUP_SYNTAX
//
// MessageText:
//
// NET LOCALGROUP [groupname [/COMMENT:"text"]] [/DOMAIN]
//                groupname {/ADD [/COMMENT:"text"] | /DELETE} [/DOMAIN]
//                groupname name [...] {/ADD | /DELETE} [/DOMAIN]
//
#define MSG_LOCALGROUP_SYNTAX            ((DWORD)0x00002722L)

//
// MessageId: MSG_LOCALGROUP_HELP
//
// MessageText:
//
// NET LOCALGROUP adds, displays or modifies local groups on computers. When
// used without parameters, it displays the local groups on the computer.
// 
// groupname        Is the name of the local group to add, expand, or
//                  delete. Supply only a groupname to view a list of
//                  users or global groups in a local group.
// /COMMENT:"text"  Adds a comment for a new or existing group.
//                  Enclose the text in quotation marks.
// /DOMAIN          Performs the operation on a domain controller
//                  of the current domain. Otherwise, the operation is
//                  performed on the local computer.
// name[ ...]       List one or more usernames or groupnams to add to or
//                  remove from a local group. Separate multiple entries with
//                  a space. Names may be users or global groups, but not
//                  other local groups. If a user is from another doamin,
//                  preface the username with the domain name (for
//                  example, SALES\RALPHR).
// /ADD             Adds a groupname or username to a local group. An account
//                  must be established for users or global groups added to a
//                  local group with this command.
// /DELETE          Removes a groupname or username from a local group.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_LOCALGROUP_HELP              ((DWORD)0x00002723L)

//
// MessageId: MSG_PAUSE_SYNTAX
//
// MessageText:
//
// NET PAUSE service
//
#define MSG_PAUSE_SYNTAX                 ((DWORD)0x00002724L)

//
// MessageId: MSG_PAUSE_HELP
//
// MessageText:
//
// NET PAUSE suspends a service. Pausing a service puts it on hold.
// 
// service   The name of the service to be paused.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_PAUSE_HELP                   ((DWORD)0x00002725L)

//
// MessageId: MSG_SESSION_SYNTAX
//
// MessageText:
//
// NET SESSION ...
//
#define MSG_SESSION_SYNTAX               ((DWORD)0x00002726L)

//
// MessageId: MSG_SESSION_HELP
//
// MessageText:
//
// SESSION
// ...
//
#define MSG_SESSION_HELP                 ((DWORD)0x00002727L)

//
// MessageId: MSG_SHARE_SYNTAX
//
// MessageText:
//
// NET SHARE sharename=drive:path [/GRANT:user,[READ | CHANGE | FULL]]
//                                [/USERS:number | /UNLIMITED]
//                                [/REMARK:"text"]
//                                [/CACHE:Manual | Documents| Programs | None]
//           sharename [/USERS:number | /UNLIMITED]
//                     [/REMARK:"text"]
//                     [/CACHE:Manual | Documents | Programs | None]
//           {sharename | devicename | drive:path} /DELETE
//
#define MSG_SHARE_SYNTAX                 ((DWORD)0x00002728L)

//
// MessageId: MSG_SHARE_HELP
//
// MessageText:
//
// NET SHARE makes a server's resources available to network users. When
// used without options, it lists information about all resources being
// shared on the computer. For each resource, Windows reports the
// devicename(s) or pathname(s) and a descriptive comment associated with it.
// 
// sharename          Is the network name of the shared resource. Type
//                    NET SHARE with a sharename only to display information
//                    about that share.
// drive:path         Specifies the absolute path of the directory to
//                    be shared.
// /GRANT:user,perm   Creates the share with a security descriptor that gives
//                    the requested permissions to the specified user. This
//                    option may be used more than once to give share permissions
//                    to multiple users.
// /USERS:number      Sets the maximum number of users who can
//                    simultaneously access the shared resource.
// /UNLIMITED         Specifies an unlimited number of users can
//                    simultaneously access the shared resource.
// /REMARK:"text"     Adds a descriptive comment about the resource.
//                    Enclose the text in quotation marks.
// devicename         Is one or more printers (LPT1: through LPT9:)
//                    shared by sharename.
// /DELETE            Stops sharing the resource.
// /CACHE:Manual      Enables manual client caching of programs and documents
//                    from this share.
// /CACHE:Documents   Enables automatic caching of documents from this share.
// /CACHE:Programs    Enables automatic caching of documents and programs
//                    from this share.
// /CACHE:None        Disables caching from this share.
// 
// NET HELP command | MORE displays Help one screen at a time.
//
#define MSG_SHARE_HELP                   ((DWORD)0x00002729L)

//
// MessageId: MSG_START_SYNTAX
//
// MessageText:
//
// NET START [service]
//
#define MSG_START_SYNTAX                 ((DWORD)0x0000272AL)

//
// MessageId: MSG_START_HELP
//
// MessageText:
//
// NET START starts services or lists running services.
// 
// service   The name of the service to be started.
// 
// When typed at the command prompt, service name of two words or more must
// be enclosed in quotation marks. For example, NET START "NET LOGON"
// starts the net logon service.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_START_HELP                   ((DWORD)0x0000272BL)

//
// MessageId: MSG_STATISTICS_SYNTAX
//
// MessageText:
//
// NET STATISTICS [SERVER | WORKSTATION]
//
#define MSG_STATISTICS_SYNTAX            ((DWORD)0x0000272CL)

//
// MessageId: MSG_STATISTICS_HELP
//
// MessageText:
//
// NET STATISTICS displays the statisticslog for the local Workstation or
// Server service. Used without parameters, NET STATISTICS displays
// the services for which statistics are available.
// 
// SERVER        Displays the Server service statistics.
// WORKSTATION   Displays the Workstation service statistics.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_STATISTICS_HELP              ((DWORD)0x0000272DL)

//
// MessageId: MSG_STOP_SYNTAX
//
// MessageText:
//
// NET STOP service
//
#define MSG_STOP_SYNTAX                  ((DWORD)0x0000272EL)

//
// MessageId: MSG_STOP_HELP
//
// MessageText:
//
// NET STOP stops services.
// 
// service   The name of the service to be stopped.
// 
// Stopping a service cancels any network connection the service is
// using. Also, some services are dependent on others. Stopping one
// service can stop others. Some services cannot be stopped.
// 
// NET HELP command | MORE displays one screen at a time.
//
#define MSG_STOP_HELP                    ((DWORD)0x0000272FL)

//
// MessageId: MSG_TIME_SYNTAX
//
// MessageText:
//
// NET TIME ...
//
#define MSG_TIME_SYNTAX                  ((DWORD)0x00002730L)

//
// MessageId: MSG_TIME_HELP
//
// MessageText:
//
// TIME
// ...
//
#define MSG_TIME_HELP                    ((DWORD)0x00002731L)

//
// MessageId: MSG_USE_SYNTAX
//
// MessageText:
//
// NET USE ...
//
#define MSG_USE_SYNTAX                   ((DWORD)0x00002732L)

//
// MessageId: MSG_USE_HELP
//
// MessageText:
//
// USE
// ...
//
#define MSG_USE_HELP                     ((DWORD)0x00002733L)

//
// MessageId: MSG_USER_SYNTAX
//
// MessageText:
//
// NET USER [username [password | *] [options]] [/DOMAIN]
//          username {password | *} /ADD [options] [/DOMAIN]
//          username [/DELETE] [/DOMAIN]
//
#define MSG_USER_SYNTAX                  ((DWORD)0x00002734L)

//
// MessageId: MSG_USER_HELP
//
// MessageText:
//
// NET USER creates and modifies user accounts on computers. When used
// without switches, it lists the user accounts for the computer. The
// user account information is stored in the user accounts database.
// 
// username     Is the name of the user account to add, delete, modify, or
//              view. The name of the user account can have as many as
//              20 characters.
// password     Assigns or changes a password for the user's account.
//              A password must satisfy the minimum length set with the
//              /MINPWLEN option of the NET ACCOUNTS command. It can have as
//              many as 14 characters.
// *            Produces a prompt for the password. The password is not
//              displayed when you type it at a password prompt.
// /DOMAIN      Performs the operation on a domain controller of
//              the current domain.
// /ADD         Adds a user account to the user accounts database.
// /DELETE      Removes a user account from the user accounts database.
// 
// Options      Are as follows:
// 
//    Options                    Description
//    --------------------------------------------------------------------
//    /ACTIVE:{YES | NO}         Activates or deactivates the account. If
//                               the account is not active, the user cannot
//                               access the server. The default is YES.
//    /COMMENT:"text"            Provides a descriptive comment about the
//                               user's account.  Enclose the text in
//                               quotation marks.
//    /COUNTRYCODE:nnn           Uses the operating system country code to
//                               implement the specified language files for a
//                               user's help and error messages. A value of
//                               0 signifies the default country code.
//    /EXPIRES:{date | NEVER}    Causes the account to expire if date is
//                               set. NEVER sets no time limit on the
//                               account. An expiration date is in the
//                               form mm/dd/yy(yy). Months can be a number,
//                               spelled out, or abbreviated with three
//                               letters. Year can be two or four numbers.
//                               Use slashes(/) (no spaces) to separate
//                               parts of the date.
//    /FULLNAME:"name"           Is a user's full name (rather than a
//                               username). Enclose the name in quotation
//                               marks.
//    /HOMEDIR:pathname          Sets the path for the user's home directory.
//                               The path must exist.
//    /PASSWORDCHG:{YES | NO}    Specifies whether users can change their
//                               own password. The default is YES.
//    /PASSWORDREQ:{YES | NO}    Specifies whether a user account must have
//                               a password. The default is YES.
//    /PROFILEPATH[:path]        Sets a path for the user's logon profile.
//    /SCRIPTPATH:pathname       Is the location of the user's logon
//                               script.
//    /TIMES:{times | ALL}       Is the logon hours. TIMES is expressed as
//                               day[-day][,day[-day]],time[-time][,time
//                               [-time]], limited to 1-hour increments.
//                               Days can be spelled out or abbreviated.
//                               Hours can be 12- or 24-hour notation. For
//                               12-hour notation, use am, pm, a.m., or
//                               p.m. ALL means a user can always log on,
//                               and a blank value means a user can never
//                               log on. Separate day and time entries with
//                               a comma, and separate multiple day and time
//                               entries with a semicolon.
//    /USERCOMMENT:"text"        Lets an administrator add or change the User
//                               Comment for the account.
//    /WORKSTATIONS:{computername[,...] | *}
//                               Lists as many as eight computers from
//                               which a user can log on to the network. If
//                               /WORKSTATIONS has no list or if the list is *,
//                               the user can log on from any computer.
// 
// NET HELP command | MORE displays Help one screen at a time.
//
#define MSG_USER_HELP                    ((DWORD)0x00002735L)

//
// MessageId: MSG_VIEW_SYNTAX
//
// MessageText:
//
// NET VIEW ...
//
#define MSG_VIEW_SYNTAX                  ((DWORD)0x00002736L)

//
// MessageId: MSG_VIEW_HELP
//
// MessageText:
//
// VIEW
// ...
//
#define MSG_VIEW_HELP                    ((DWORD)0x00002737L)

//
// MessageId: MSG_NET_SYNTAX
//
// MessageText:
//
// NET [ ACCOUNTS | COMPUTER | CONFIG | CONTINUE | FILE | GROUP | HELP |
//       HELPMSG | LOCALGROUP | PAUSE | SESSION | SHARE | START |
//       STATISTICS | STOP | TIME | USE | USER | VIEW ]
//
#define MSG_NET_SYNTAX                   ((DWORD)0x00002738L)

//
// MessageId: MSG_SYNTAX_HELP
//
// MessageText:
//
// SYNTAX
// The following conventions are used to indicate command syntax:
// 
// -  Capital letters represent words that must be typed as shown. Lower-
//    case letters represent names of items that may vary, such as filenames.
// 
// -  The [ and ] characters surround optional items that can be supplied
//    with the command.
// 
// -  The { and } characters surround lists of items. You must supply one
//    of the items with the command.
// 
// -  The | character separates items in a list. Only one of the items can
//    be supplied with the command.
// 
//    For example, in the following syntax, you must type NET COMMAND and
//    either SWITCH1 or SWITCH2. Supplying a name is optional.
//        NET COMMAND [name] {SWITCH1 | SWITCH2}
// 
// -  The [...] characters mean you can repeat the previous item.
//    Separate items with spaces.
// 
// -  The [,...] characters mean you can repeat the previous item, but
//    you must separate items with commas or semicolons, not spaces.
// 
// -  When typed at the command prompt, service names of two words or
//    more must be enclosed in quotation marks. For example,
//    NET START "COMPUTER BROWSER" starts the computer browser service.
//
#define MSG_SYNTAX_HELP                  ((DWORD)0x00002739L)

