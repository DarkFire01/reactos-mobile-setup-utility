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
// MessageId: NONE
//
// MessageText:
//
// PCI Device
//
#define NONE                             0x00000000L

//
// MessageId: NONE
//
// MessageText:
//
// VGA Device
//
#define NONE                             0x00000001L

//
// MessageId: NONE
//
// MessageText:
//
// SCSI Controller
//
#define NONE                             0x00000100L

//
// MessageId: NONE
//
// MessageText:
//
// IDE Controller
//
#define NONE                             0x00000101L

//
// MessageId: NONE
//
// MessageText:
//
// Floppy Controller
//
#define NONE                             0x00000102L

//
// MessageId: NONE
//
// MessageText:
//
// IPI Controller
//
#define NONE                             0x00000103L

//
// MessageId: NONE
//
// MessageText:
//
// RAID Controller
//
#define NONE                             0x00000104L

//
// MessageId: NONE
//
// MessageText:
//
// ATA Controller
//
#define NONE                             0x00000105L

//
// MessageId: NONE
//
// MessageText:
//
// Serial ATA Controller
//
#define NONE                             0x00000106L

//
// MessageId: NONE
//
// MessageText:
//
// SAS Controller
//
#define NONE                             0x00000107L

//
// MessageId: NONE
//
// MessageText:
//
// Mass Storage Controller
//
#define NONE                             0x00000180L

//
// MessageId: NONE
//
// MessageText:
//
// Ethernet Controller
//
#define NONE                             0x00000200L

//
// MessageId: NONE
//
// MessageText:
//
// Token Ring Network Controller
//
#define NONE                             0x00000201L

//
// MessageId: NONE
//
// MessageText:
//
// FDDI Network Controller
//
#define NONE                             0x00000202L

//
// MessageId: NONE
//
// MessageText:
//
// ATM Network Controller
//
#define NONE                             0x00000203L

//
// MessageId: NONE
//
// MessageText:
//
// ISDN Controller
//
#define NONE                             0x00000204L

//
// MessageId: NONE
//
// MessageText:
//
// WorldFip Controller
//
#define NONE                             0x00000205L

//
// MessageId: NONE
//
// MessageText:
//
// Network Controller
//
#define NONE                             0x00000280L

//
// MessageId: NONE
//
// MessageText:
//
// Video Controller (VGA Compatible)
//
#define NONE                             0x00000300L

//
// MessageId: NONE
//
// MessageText:
//
// Video Controller (VGA Compatible)
//
#define NONE                             0x00000301L

//
// MessageId: NONE
//
// MessageText:
//
// 3D Video Controller
//
#define NONE                             0x00000302L

//
// MessageId: NONE
//
// MessageText:
//
// Video Controller
//
#define NONE                             0x00000380L

//
// MessageId: NONE
//
// MessageText:
//
// Multimedia Video Controller
//
#define NONE                             0x00000400L

//
// MessageId: NONE
//
// MessageText:
//
// Multimedia Audio Controller
//
#define NONE                             0x00000401L

//
// MessageId: NONE
//
// MessageText:
//
// Computer Telephony Device
//
#define NONE                             0x00000402L

//
// MessageId: NONE
//
// MessageText:
//
// Multimedia Controller
//
#define NONE                             0x00000480L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Memory
//
#define NONE                             0x00000500L

//
// MessageId: NONE
//
// MessageText:
//
// PCI FLASH Memory
//
#define NONE                             0x00000501L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Memory Controller
//
#define NONE                             0x00000580L

//
// MessageId: NONE
//
// MessageText:
//
// PCI HOST Bridge
//
#define NONE                             0x00000600L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to ISA Bridge
//
#define NONE                             0x00000601L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to EISA Bridge
//
#define NONE                             0x00000602L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to Micro Channel Bridge
//
#define NONE                             0x00000603L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to PCI Bridge
//
#define NONE                             0x00000604L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to PCMCIA Bridge
//
#define NONE                             0x00000605L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to NUBUS Bridge
//
#define NONE                             0x00000606L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to CARDBUS Bridge
//
#define NONE                             0x00000607L

//
// MessageId: NONE
//
// MessageText:
//
// PCI to RACEway Bridge
//
#define NONE                             0x00000608L

//
// MessageId: NONE
//
// MessageText:
//
// Semi-transparent PCI to PCI Bridge
//
#define NONE                             0x00000609L

//
// MessageId: NONE
//
// MessageText:
//
// Infiniband to PCI Host Bridge
//
#define NONE                             0x0000060AL

//
// MessageId: NONE
//
// MessageText:
//
// Other PCI Bridge Device
//
#define NONE                             0x00000680L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Serial Port
//
#define NONE                             0x00000700L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Parallel Port
//
#define NONE                             0x00000701L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Multiport Serial Controller
//
#define NONE                             0x00000702L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Modem
//
#define NONE                             0x00000703L

//
// MessageId: NONE
//
// MessageText:
//
// PCI GBIB Controller
//
#define NONE                             0x00000704L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Smart Card
//
#define NONE                             0x00000705L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Simple Communications Controller
//
#define NONE                             0x00000780L

//
// MessageId: NONE
//
// MessageText:
//
// System Interrupt Controller
//
#define NONE                             0x00000800L

//
// MessageId: NONE
//
// MessageText:
//
// System DMA Controller
//
#define NONE                             0x00000801L

//
// MessageId: NONE
//
// MessageText:
//
// System Timer
//
#define NONE                             0x00000802L

//
// MessageId: NONE
//
// MessageText:
//
// Real Time Clock
//
#define NONE                             0x00000803L

//
// MessageId: NONE
//
// MessageText:
//
// Generic PCI Hot-Plug Controller
//
#define NONE                             0x00000804L

//
// MessageId: NONE
//
// MessageText:
//
// SD Host Controller
//
#define NONE                             0x00000805L

//
// MessageId: NONE
//
// MessageText:
//
// Base System Device
//
#define NONE                             0x0000087DL

//
// MessageId: NONE
//
// MessageText:
//
// PCI Keyboard Controller
//
#define NONE                             0x00000900L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Digitizer
//
#define NONE                             0x00000901L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Mouse Controller
//
#define NONE                             0x00000902L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Scanner Controller
//
#define NONE                             0x00000903L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Gameport Controller
//
#define NONE                             0x00000904L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Input Device
//
#define NONE                             0x00000980L

//
// MessageId: NONE
//
// MessageText:
//
// Docking Station
//
#define NONE                             0x00000A00L

//
// MessageId: NONE
//
// MessageText:
//
// Docking Station (Unknown type)
//
#define NONE                             0x00000A80L

//
// MessageId: NONE
//
// MessageText:
//
// 386 Processor
//
#define NONE                             0x00000B00L

//
// MessageId: NONE
//
// MessageText:
//
// 486 Processor
//
#define NONE                             0x00000B01L

//
// MessageId: NONE
//
// MessageText:
//
// Pentium Processor
//
#define NONE                             0x00000B02L

//
// MessageId: NONE
//
// MessageText:
//
// ALPHA Processor
//
#define NONE                             0x00000B10L

//
// MessageId: NONE
//
// MessageText:
//
// PowerPC Processor
//
#define NONE                             0x00000B20L

//
// MessageId: NONE
//
// MessageText:
//
// Coprocessor
//
#define NONE                             0x00000B40L

//
// MessageId: NONE
//
// MessageText:
//
// IEEE 1394 Controller
//
#define NONE                             0x00000C00L

//
// MessageId: NONE
//
// MessageText:
//
// ACCESS Bus Controller
//
#define NONE                             0x00000C01L

//
// MessageId: NONE
//
// MessageText:
//
// SSA Controller
//
#define NONE                             0x00000C02L

//
// MessageId: NONE
//
// MessageText:
//
// Universal Serial Bus (USB) Controller
//
#define NONE                             0x00000C03L

//
// MessageId: NONE
//
// MessageText:
//
// Fibre Channel Controller
//
#define NONE                             0x00000C04L

//
// MessageId: NONE
//
// MessageText:
//
// SM Bus Controller
//
#define NONE                             0x00000C05L

//
// MessageId: NONE
//
// MessageText:
//
// Infiniband Controller
//
#define NONE                             0x00000C06L

//
// MessageId: NONE
//
// MessageText:
//
// IPMI Interface
//
#define NONE                             0x00000C07L

//
// MessageId: NONE
//
// MessageText:
//
// SERCOS Interface
//
#define NONE                             0x00000C08L

//
// MessageId: NONE
//
// MessageText:
//
// CANbus Controller
//
#define NONE                             0x00000C09L

//
// MessageId: NONE
//
// MessageText:
//
// iRDA Compatible Controller
//
#define NONE                             0x00000D00L

//
// MessageId: NONE
//
// MessageText:
//
// Consumer IR Controller
//
#define NONE                             0x00000D01L

//
// MessageId: NONE
//
// MessageText:
//
// RF Controller
//
#define NONE                             0x00000D10L

//
// MessageId: NONE
//
// MessageText:
//
// Bluetooth Controller
//
#define NONE                             0x00000D11L

//
// MessageId: NONE
//
// MessageText:
//
// Broadband Controller
//
#define NONE                             0x00000D12L

//
// MessageId: NONE
//
// MessageText:
//
// Ethernet 802.11a Controller
//
#define NONE                             0x00000D20L

//
// MessageId: NONE
//
// MessageText:
//
// Ethernet 802.11b Controller
//
#define NONE                             0x00000D21L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Wireless Controller
//
#define NONE                             0x00000D80L

//
// MessageId: NONE
//
// MessageText:
//
// Intelligent I/O (I2O) Controller
//
#define NONE                             0x00000E00L

//
// MessageId: NONE
//
// MessageText:
//
// Satellite Communications Television Controller
//
#define NONE                             0x00000F01L

//
// MessageId: NONE
//
// MessageText:
//
// Satellite Communications Audio Controller
//
#define NONE                             0x00000F02L

//
// MessageId: NONE
//
// MessageText:
//
// Satellite Communications Voice Controller
//
#define NONE                             0x00000F03L

//
// MessageId: NONE
//
// MessageText:
//
// Satellite Communications Data Controller
//
#define NONE                             0x00000F04L

//
// MessageId: NONE
//
// MessageText:
//
// Network and Computing Encryption/Decryption Controller
//
#define NONE                             0x00001000L

//
// MessageId: NONE
//
// MessageText:
//
// Entertainment Encryption/Decryption Controller
//
#define NONE                             0x00001010L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Encryption/Decryption Controller
//
#define NONE                             0x00001080L

//
// MessageId: NONE
//
// MessageText:
//
// DPIO Module
//
#define NONE                             0x00001100L

//
// MessageId: NONE
//
// MessageText:
//
// Performance Counters
//
#define NONE                             0x00001101L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Communications Synchronization plus Time and Frequency Test/Measurement Controller
//
#define NONE                             0x00001110L

//
// MessageId: NONE
//
// MessageText:
//
// Management Card
//
#define NONE                             0x00001120L

//
// MessageId: NONE
//
// MessageText:
//
// PCI Data Acquisition and Signal Processing Controller
//
#define NONE                             0x00001180L

