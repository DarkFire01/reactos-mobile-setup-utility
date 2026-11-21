
#include <kxarm64.h>


; CONTEXT Offsets
CxContextFlags equ 0x0
CxCpsr equ 0x4
CxX0 equ 0x8
CxX1 equ 0x10
CxX2 equ 0x18
CxX3 equ 0x20
CxX4 equ 0x28
CxX5 equ 0x30
CxX6 equ 0x38
CxX7 equ 0x40
CxX8 equ 0x48
CxX9 equ 0x50
CxX10 equ 0x58
CxX11 equ 0x60
CxX12 equ 0x68
CxX13 equ 0x70
CxX14 equ 0x78
CxX15 equ 0x80
CxX16 equ 0x88
CxX17 equ 0x90
CxX18 equ 0x98
CxX19 equ 0xa0
CxX20 equ 0xa8
CxX21 equ 0xb0
CxX22 equ 0xb8
CxX23 equ 0xc0
CxX24 equ 0xc8
CxX25 equ 0xd0
CxX26 equ 0xd8
CxX27 equ 0xe0
CxX28 equ 0xe8
CxFp equ 0xf0
CxLr equ 0xf8
CxSp equ 0x100
CxPc equ 0x108
CxV equ 0x110
CxFpcr equ 0x310
CxFpsr equ 0x314
CxBcr equ 0x318
CxBvr equ 0x338
CxWcr equ 0x378
CxWvr equ 0x380
CONTEXT_FRAME_LENGTH equ 0x390

; DISPATCHER_CONTEXT
DcControlPc equ 0x0
DcImageBase equ 0x8
DcFunctionEntry equ 0x10
DcEstablisherFrame equ 0x18
DcTargetPc equ 0x20
DcContextRecord equ 0x28
DcLanguageHandler equ 0x30
DcHandlerData equ 0x38
DcHistoryTable equ 0x40
DcScopeIndex equ 0x48
DcControlPcIsUnwound equ 0x4c
DcNonVolatileRegisters equ 0x50

; JUMP_BUFFER
JbFrame equ 0x0
JbReserved equ 0x8
JbX19 equ 0x10
JbX20 equ 0x18
JbX21 equ 0x20
JbX22 equ 0x28
JbX23 equ 0x30
JbX24 equ 0x38
JbX25 equ 0x40
JbX26 equ 0x48
JbX27 equ 0x50
JbX28 equ 0x58
JbFp equ 0x60
JbLr equ 0x68
JbSp equ 0x70
JbFpcr equ 0x78
JbFpsr equ 0x7c
JbD8 equ 0x80
JbD9 equ 0x88
JbD10 equ 0x90
JbD11 equ 0x98
JbD12 equ 0xa0
JbD13 equ 0xa8
JbD14 equ 0xb0
JbD15 equ 0xb8

; KTRAP_FRAME
TrPreviousMode equ 0x3
TrFaultAddress equ 0x8
TrTrapFrame equ 0x8
TrVfpState equ 0x10
TrSpsr equ 0x90
TrEsr equ 0x94
TrSp equ 0x98
TrX0 equ 0xa0
TrX1 equ 0xa8
TrX2 equ 0xb0
TrX3 equ 0xb8
TrX4 equ 0xc0
TrX5 equ 0xc8
TrX6 equ 0xd0
TrX7 equ 0xd8
TrX8 equ 0xe0
TrX9 equ 0xe8
TrX10 equ 0xf0
TrX11 equ 0xf8
TrX12 equ 0x100
TrX13 equ 0x108
TrX14 equ 0x110
TrX15 equ 0x118
TrX16 equ 0x120
TrX17 equ 0x128
TrX18 equ 0x130
TrLr equ 0x138
TrFp equ 0x140
TrPc equ 0x148
KTRAP_FRAME_LENGTH equ 0x150

; KARM64_VFP_STATE
VfFpcr equ 0x8
VfFpsr equ 0xc
VfV equ 0x10
KARM64_VFP_STATE_LENGTH equ 0x210

; KEXCEPTION_FRAME
ExTrapFrame equ 0x0
ExOutputBuffer equ 0x8
ExOutputLength equ 0x10
ExD8 equ 0x20
ExD9 equ 0x28
ExD10 equ 0x30
ExD11 equ 0x38
ExD12 equ 0x40
ExD13 equ 0x48
ExD14 equ 0x50
ExD15 equ 0x58
ExX19 equ 0x60
ExX20 equ 0x68
ExX21 equ 0x70
ExX22 equ 0x78
ExX23 equ 0x80
ExX24 equ 0x88
ExX25 equ 0x90
ExX26 equ 0x98
ExX27 equ 0xa0
ExX28 equ 0xa8
ExFp equ 0xb0
ExReturn equ 0xb8
KEXCEPTION_FRAME_LENGTH equ 0xc0

; KSWITCH_FRAME
SwApcBypass equ 0x0
SwD8 equ 0x10
SwD9 equ 0x18
SwD10 equ 0x20
SwD11 equ 0x28
SwD12 equ 0x30
SwD13 equ 0x38
SwD14 equ 0x40
SwD15 equ 0x48
SwX19 equ 0x50
SwX20 equ 0x58
SwX21 equ 0x60
SwX22 equ 0x68
SwX23 equ 0x70
SwX24 equ 0x78
SwX25 equ 0x80
SwX26 equ 0x88
SwX27 equ 0x90
SwX28 equ 0x98
SwFp equ 0xa0
SwReturn equ 0xa8
KSWITCH_FRAME_LENGTH equ 0xb0

; KSTART_FRAME
SfSystemRoutine equ 0x0
SfStartRoutine equ 0x8
SfStartContext equ 0x10
SfUserThread equ 0x18
KSTART_FRAME_LENGTH equ 0x20

; KPCR
PcSelf equ 0x18
PcCurrentIrql equ 0x38
PcPrcb equ 0x980
PcCurrentThread equ 0x988
PcNextThread equ 0x990
PcIdleThread equ 0x998
PcDpcStack equ 0x18c0
PcSavedSp equ 0x18c8

; Pointer size
SizeofPointer equ 0x8

; Bug Check Codes
APC_INDEX_MISMATCH equ 0x1
INVALID_AFFINITY_SET equ 0x3
INVALID_DATA_ACCESS_TRAP equ 0x4
IRQL_NOT_GREATER_OR_EQUAL equ 0x9
IRQL_NOT_LESS_OR_EQUAL equ 0xa
NO_USER_MODE_CONTEXT equ 0xe
SPIN_LOCK_ALREADY_OWNED equ 0xf
SPIN_LOCK_NOT_OWNED equ 0x10
THREAD_NOT_MUTEX_OWNER equ 0x11
TRAP_CAUSE_UNKNOWN equ 0x12
KMODE_EXCEPTION_NOT_HANDLED equ 0x1e
KERNEL_APC_PENDING_DURING_EXIT equ 0x20
PANIC_STACK_SWITCH equ 0x2b
DATA_BUS_ERROR equ 0x2e
INSTRUCTION_BUS_ERROR equ 0x2f
SYSTEM_EXIT_OWNED_MUTEX equ 0x39
PAGE_FAULT_WITH_INTERRUPTS_OFF equ 0x49
IRQL_GT_ZERO_AT_SYSTEM_SERVICE equ 0x4a
DATA_COHERENCY_EXCEPTION equ 0x55
INSTRUCTION_COHERENCY_EXCEPTION equ 0x56
HAL1_INITIALIZATION_FAILED equ 0x61
UNEXPECTED_KERNEL_MODE_TRAP equ 0x7f
NMI_HARDWARE_FAILURE equ 0x80
SPIN_LOCK_INIT_FAILURE equ 0x81
ATTEMPTED_SWITCH_FROM_DPC equ 0xb8
KERNEL_SECURITY_CHECK_FAILURE equ 0x139

; Breakpoints
BREAKPOINT_BREAK equ 0x0
BREAKPOINT_PRINT equ 0x1
BREAKPOINT_PROMPT equ 0x2
BREAKPOINT_LOAD_SYMBOLS equ 0x3
BREAKPOINT_UNLOAD_SYMBOLS equ 0x4
BREAKPOINT_COMMAND_STRING equ 0x5

; Context Frame Flags
CONTEXT_FULL equ 0x400007
CONTEXT_CONTROL equ 0x400001
CONTEXT_INTEGER equ 0x400002
CONTEXT_FLOATING_POINT equ 0x400004
CONTEXT_DEBUG_REGISTERS equ 0x400008

; Exception flags
EXCEPTION_NONCONTINUABLE equ 0x1
EXCEPTION_UNWINDING equ 0x2
EXCEPTION_EXIT_UNWIND equ 0x4
EXCEPTION_STACK_INVALID equ 0x8
EXCEPTION_NESTED_CALL equ 0x10
EXCEPTION_TARGET_UNWIND equ 0x20
EXCEPTION_COLLIDED_UNWIND equ 0x40
EXCEPTION_UNWIND equ 0x66
EXCEPTION_EXECUTE_HANDLER equ 0x1
EXCEPTION_CONTINUE_SEARCH equ 0x0
EXCEPTION_CONTINUE_EXECUTION equ 0xffffffff

; Exception types
ExceptionContinueExecution equ 0x0
ExceptionContinueSearch equ 0x1
ExceptionNestedException equ 0x2
ExceptionCollidedUnwind equ 0x3

; Fast Fail Constants
FAST_FAIL_GUARD_ICALL_CHECK_FAILURE equ 0xa

; Interrupt object types
InLevelSensitive equ 0x0
InLatched equ 0x1

; IPI
IPI_APC equ 0x1
IPI_DPC equ 0x2
IPI_FREEZE equ 0x4
IPI_PACKET_READY equ 0x6

; IRQL
PASSIVE_LEVEL equ 0x0
APC_LEVEL equ 0x1
DISPATCH_LEVEL equ 0x2
IPI_LEVEL equ 0xe
POWER_LEVEL equ 0xe
PROFILE_LEVEL equ 0xf
HIGH_LEVEL equ 0xf
#ifndef CONFIG_SMP
SYNCH_LEVEL equ 0x2
#else
SYNCH_LEVEL equ 0xc
#endif

; Lock Queue
LOCK_QUEUE_WAIT equ 0x1
LOCK_QUEUE_OWNER equ 0x2
LockQueueDispatcherLock equ 0x0

; Process states
ProcessInMemory equ 0x0
ProcessOutOfMemory equ 0x1
ProcessInTransition equ 0x2

; Processor mode
KernelMode equ 0x0
UserMode equ 0x1

; Service Table Constants
NUMBER_SERVICE_TABLES equ 0x2
SERVICE_NUMBER_MASK equ 0xfff
SERVICE_TABLE_SHIFT equ 0x7
SERVICE_TABLE_MASK equ 0x20
SERVICE_TABLE_TEST equ 0x20

; Status codes
STATUS_ACCESS_VIOLATION equ 0xc0000005
STATUS_ASSERTION_FAILURE equ 0xc0000420
STATUS_ARRAY_BOUNDS_EXCEEDED equ 0xc000008c
STATUS_BAD_COMPRESSION_BUFFER equ 0xc0000242
STATUS_BREAKPOINT equ 0x80000003
STATUS_CALLBACK_POP_STACK equ 0xc0000423
STATUS_DATATYPE_MISALIGNMENT equ 0x80000002
STATUS_FLOAT_DENORMAL_OPERAND equ 0xc000008d
STATUS_FLOAT_DIVIDE_BY_ZERO equ 0xc000008e
STATUS_FLOAT_INEXACT_RESULT equ 0xc000008f
STATUS_FLOAT_INVALID_OPERATION equ 0xc0000090
STATUS_FLOAT_OVERFLOW equ 0xc0000091
STATUS_FLOAT_STACK_CHECK equ 0xc0000092
STATUS_FLOAT_UNDERFLOW equ 0xc0000093
STATUS_FLOAT_MULTIPLE_FAULTS equ 0xc00002b4
STATUS_FLOAT_MULTIPLE_TRAPS equ 0xc00002b5
STATUS_GUARD_PAGE_VIOLATION equ 0x80000001
STATUS_ILLEGAL_FLOAT_CONTEXT equ 0xc000014a
STATUS_ILLEGAL_INSTRUCTION equ 0xc000001d
STATUS_INSTRUCTION_MISALIGNMENT equ 0xc00000aa
STATUS_INVALID_HANDLE equ 0xc0000008
STATUS_INVALID_LOCK_SEQUENCE equ 0xc000001e
STATUS_INVALID_OWNER equ 0xc000005a
STATUS_INVALID_PARAMETER equ 0xc000000d
STATUS_INVALID_PARAMETER_1 equ 0xc00000ef
STATUS_INVALID_SYSTEM_SERVICE equ 0xc000001c
STATUS_INTEGER_DIVIDE_BY_ZERO equ 0xc0000094
STATUS_INTEGER_OVERFLOW equ 0xc0000095
STATUS_IN_PAGE_ERROR equ 0xc0000006
STATUS_KERNEL_APC equ 0x100
STATUS_LONGJUMP equ 0x80000026
STATUS_NO_CALLBACK_ACTIVE equ 0xc0000258
STATUS_NO_EVENT_PAIR equ 0xc000014e
STATUS_PRIVILEGED_INSTRUCTION equ 0xc0000096
STATUS_SINGLE_STEP equ 0x80000004
STATUS_STACK_BUFFER_OVERRUN equ 0xc0000409
STATUS_STACK_OVERFLOW equ 0xc00000fd
STATUS_SUCCESS equ 0x0
STATUS_THREAD_IS_TERMINATING equ 0xc000004b
STATUS_TIMEOUT equ 0x102
STATUS_UNWIND equ 0xc0000027
STATUS_UNWIND_CONSOLIDATE equ 0x80000029
STATUS_USER_APC equ 0xc0
STATUS_WAKE_SYSTEM equ 0x40000294
STATUS_WAKE_SYSTEM_DEBUGGER equ 0x80000007

; TLS defines
TLS_MINIMUM_AVAILABLE equ 0x40
TLS_EXPANSION_SLOTS equ 0x400

; Thread states
Initialized equ 0x0
Ready equ 0x1
Running equ 0x2
Standby equ 0x3
Terminated equ 0x4
Waiting equ 0x5

; Wait type / reason
WrExecutive equ 0x7
WrMutex equ 0x1d
WrDispatchInt equ 0x1f
WrQuantumEnd equ 0x1e
WrEventPair equ 0xe
WaitAny equ 0x1
WaitAll equ 0x0

; Stack sizes
KERNEL_STACK_SIZE equ 0x8000
KERNEL_LARGE_STACK_SIZE equ 0x12000
KERNEL_LARGE_STACK_COMMIT equ 0x8000
DOUBLE_FAULT_STACK_SIZE equ 0x8000

; Miscellaneous Definitions
TRUE equ 0x1
FALSE equ 0x0
PAGE_SIZE equ 0x1000
Executive equ 0x0
LOW_REALTIME_PRIORITY equ 0x10
CLOCK_QUANTUM_DECREMENT equ 0x3
WAIT_QUANTUM_DECREMENT equ 0x1
MAXIMUM_PROCESSORS equ 0x40
INITIAL_STALL_COUNT equ 0x64
KI_EXCEPTION_ACCESS_VIOLATION equ 0x10000004
DBG_STATUS_CONTROL_C equ 0x1

; KAFFINITY_EX
AfCount equ 0x0
AfBitmap equ 0x8
AffinityExLength equ 0x28

; KAPC
ApType equ 0x0
ApSize equ 0x2
ApThread equ 0x8
ApApcListEntry equ 0x10
ApKernelRoutine equ 0x20
ApRundownRoutine equ 0x28
ApNormalRoutine equ 0x30
ApNormalContext equ 0x38
ApSystemArgument1 equ 0x40
ApSystemArgument2 equ 0x48
ApApcStateIndex equ 0x50
ApApcMode equ 0x51
ApInserted equ 0x52
ApcObjectLength equ 0x58

; KAPC offsets (relative to NormalRoutine)
ArNormalRoutine equ 0x0
ArNormalContext equ 0x8
ArSystemArgument1 equ 0x10
ArSystemArgument2 equ 0x18
ApcRecordLength equ 0x20

; KAPC_STATE
AsApcListHead equ 0x0
AsProcess equ 0x20
AsKernelApcInProgress equ 0x28
AsKernelApcPending equ 0x29
AsUserApcPending equ 0x2a

; CLIENT_ID
CidUniqueProcess equ 0x0
CidUniqueThread equ 0x8

; RTL_CRITICAL_SECTION
CsDebugInfo equ 0x0
CsLockCount equ 0x8
CsRecursionCount equ 0xc
CsOwningThread equ 0x10
CsLockSemaphore equ 0x18
CsSpinCount equ 0x20

; RTL_CRITICAL_SECTION_DEBUG
CsType equ 0x0
CsCreatorBackTraceIndex equ 0x2
CsCriticalSection equ 0x8
CsProcessLocksList equ 0x10
CsEntryCount equ 0x20
CsContentionCount equ 0x24

; KDEVICE_QUEUE_ENTRY
DeDeviceListEntry equ 0x0
DeSortKey equ 0x10
DeInserted equ 0x14
DeviceQueueEntryLength equ 0x18

; KDPC
DpType equ 0x0
DpImportance equ 0x1
DpNumber equ 0x2
DpDpcListEntry equ 0x8
DpDeferredRoutine equ 0x18
DpDeferredContext equ 0x20
DpSystemArgument1 equ 0x28
DpSystemArgument2 equ 0x30
DpDpcData equ 0x38
DpcObjectLength equ 0x40

; KDEVICE_QUEUE
DvType equ 0x0
DvSize equ 0x2
DvDeviceListHead equ 0x8
DvSpinLock equ 0x18
DvBusy equ 0x20
DeviceQueueObjectLength equ 0x28

; EXCEPTION_RECORD
ErExceptionCode equ 0x0
ErExceptionFlags equ 0x4
ErExceptionRecord equ 0x8
ErExceptionAddress equ 0x10
ErNumberParameters equ 0x18
ErExceptionInformation equ 0x20
ExceptionRecordLength equ 0x98
EXCEPTION_RECORD_LENGTH equ 0x98

; EPROCESS
EpDebugPort equ 0x140
ExecutiveProcessObjectLength equ 0x3f0

; ETHREAD offsets
EtCid equ 0x340
ExecutiveThreadObjectLength equ 0x428

; KEVENT
EvType equ 0x0
EvSize equ 0x2
EvSignalState equ 0x4
EvWaitListHead equ 0x8
EventObjectLength equ 0x18

; FIBER
FbFiberData equ 0x0
FbExceptionList equ 0x8
FbStackBase equ 0x10
FbStackLimit equ 0x18
FbDeallocationStack equ 0x20
FbFiberContext equ 0x30
FbFlsData equ 0x3c8
FbGuaranteedStackBytes equ 0x3c0

; FAST_MUTEX
FmCount equ 0x0
FmOwner equ 0x8
FmContention equ 0x10
FmOldIrql equ 0x30

; GETSETCONTEXT offsets
GetSetCtxContextPtr equ 0x80

; KINTERRUPT
InType equ 0x0
InSize equ 0x2
InInterruptListEntry equ 0x8
InServiceRoutine equ 0x18
InServiceContext equ 0x20
InSpinLock equ 0x28
InTickCount equ 0x30
InActualLock equ 0x38
InDispatchAddress equ 0x40
InVector equ 0x48
InIrql equ 0x4c
InSynchronizeIrql equ 0x4d
InFloatingSave equ 0x4e
InConnected equ 0x4f
InNumber equ 0x50
InShareVector equ 0x51
InMode equ 0x54
InServiceCount equ 0x58
InDispatchCount equ 0x5c
InDispatchCode equ 0x70
InterruptObjectLength equ 0x80

; KSPIN_LOCK_QUEUE
LqNext equ 0x0
LqLock equ 0x8
LOCK_QUEUE_HEADER_SIZE equ 0x10

; KLOCK_QUEUE_HANDLE
LqhLockQueue equ 0x0
LqhNext equ 0x0
LqhLock equ 0x8
LqhOldIrql equ 0x10

; LARGE_INTEGER
LiLowPart equ 0x0
LiHighPart equ 0x4

; LOADER_PARAMETER_BLOCK (rel. to LoadOrderListHead)
LpbKernelStack equ 0x30
LpbPrcb equ 0x38
LpbProcess equ 0x40
LpbThread equ 0x48

; LIST_ENTRY
LsFlink equ 0x0
LsBlink equ 0x8

; PEB
PeBeingDebugged equ 0x2
PeProcessParameters equ 0x20
PeKernelCallbackTable equ 0x58
ProcessEnvironmentBlockLength equ 0x358

; KPROFILE
PfType equ 0x0
PfSize equ 0x2
PfProfileListEntry equ 0x8
PfProcess equ 0x18
PfRangeBase equ 0x20
PfRangeLimit equ 0x28
PfBucketShift equ 0x30
PfBuffer equ 0x38
PfSegment equ 0x40
PfAffinity equ 0x48
PfSource equ 0x50
PfStarted equ 0x54
ProfileObjectLength equ 0x58

; PORT_MESSAGE
PmLength equ 0x0
PmZeroInit equ 0x4
PmClientId equ 0x8
PmProcess equ 0x8
PmThread equ 0x10
PmMessageId equ 0x18
PmClientViewSize equ 0x20
PortMessageLength equ 0x28

; KPROCESS
PrType equ 0x0
PrSize equ 0x2
PrSignalState equ 0x4
PrProfileListHead equ 0x18
PrDirectoryTableBase equ 0x28
PrThreadListHead equ 0x70
PrAffinity equ 0x88
PrReadyListHead equ 0x50
PrSwapListEntry equ 0x60
PrActiveProcessors equ 0x40
PrProcessFlags equ 0x90
PrBasePriority equ 0x94
PrQuantumReset equ 0x95
PrKernelTime equ 0x48
PrUserTime equ 0x4c
KernelProcessObjectLength equ 0xb0

; KQUEUE
QuType equ 0x0
QuSize equ 0x2
QuSignalState equ 0x4
QuEntryListHead equ 0x18
QuCurrentCount equ 0x28
QuMaximumCount equ 0x2c
QuThreadListHead equ 0x30
QueueObjectLength equ 0x40

; KSERVICE_TABLE_DESCRIPTOR offsets
SdBase equ 0x0
SdCount equ 0x8
SdLimit equ 0x10
SdNumber equ 0x18
SdLength equ 0x20

; STRING
StrLength equ 0x0
StrMaximumLength equ 0x2
StrBuffer equ 0x8

; TEB
TeStackBase equ 0x8
TeStackLimit equ 0x10
TeFiberData equ 0x20
TeSelf equ 0x30
TeEnvironmentPointer equ 0x38
TeClientId equ 0x40
TeActiveRpcHandle equ 0x50
TeThreadLocalStoragePointer equ 0x58
TePeb equ 0x60
TeLastErrorValue equ 0x68
TeCountOfOwnedCriticalSections equ 0x6c
TeCsrClientThread equ 0x70
TeWOW32Reserved equ 0x100
TeExceptionCode equ 0x2c0
TeActivationContextStackPointer equ 0x2c8
TeGdiClientPID equ 0x7f0
TeGdiClientTID equ 0x7f4
TeGdiThreadLocalInfo equ 0x7f8
TeglDispatchTable equ 0x9f0
TeglReserved1 equ 0x1138
TeglReserved2 equ 0x1220
TeglSectionInfo equ 0x1228
TeglSection equ 0x1230
TeglTable equ 0x1238
TeglCurrentRC equ 0x1240
TeglContext equ 0x1248
TeDeallocationStack equ 0x1478
TeTlsSlots equ 0x1480
TeVdm equ 0x1690
TeInstrumentation equ 0x16b8
TeGdiBatchCount equ 0x1740
TeGuaranteedStackBytes equ 0x1748
TeTlsExpansionSlots equ 0x1780
TeFlsData equ 0x17c8
ThreadEnvironmentBlockLength equ 0x1810

; TIME_FIELDS
TfYear equ 0x0
TfMonth equ 0x2
TfDay equ 0x4
TfHour equ 0x6
TfMinute equ 0x8
TfSecond equ 0xa
TfMilliseconds equ 0xc
TfWeekday equ 0xe

; KTHREAD
ThType equ 0x0
ThLock equ 0x0
ThSize equ 0x2
ThThreadControlFlags equ 0x2
ThDebugActive equ 0x3
ThSignalState equ 0x4
ThInitialStack equ 0x28
ThStackLimit equ 0x30
ThStackBase equ 0x258
ThThreadLock equ 0x40
ThKernelStack equ 0x38
ThAlerted equ 0x96
ThThreadFlags equ 0xf4
ThTrapFrame equ 0x1c8
ThApcState equ 0x48
ThPriority equ 0x93
ThSwapBusy equ 0x95
ThContextSwitches equ 0x124
ThState equ 0x154
ThProcess equ 0x200
ThNpxState equ 0x155
ThWaitIrql equ 0x156
ThWaitMode equ 0x157
ThTeb equ 0xb0
ThTimer equ 0xb8
ThWin32Thread equ 0x250
ThWaitTime equ 0x184
ThCombinedApcDisable equ 0x1b4
ThKernelApcDisable equ 0x1b4
ThSpecialApcDisable equ 0x1b6
ThNextProcessor equ 0x74
ThPreviousMode equ 0x153
ThPriorityDecrement equ 0x1f6
ThAdjustReason equ 0x76
ThAdjustIncrement equ 0x77
ThAffinity equ 0x208
ThApcStateIndex equ 0x1e4
ThIdealProcessor equ 0x1e5
ThApcStatePointer equ 0x210
ThSavedApcState equ 0x220
ThWaitReason equ 0x92
ThSaturation equ 0x1f7
ThLegoData equ 0x2a8
KernelThreadObjectLength equ 0x2f0

; ETHREAD

; KTIMER
TiType equ 0x0
TiSize equ 0x2
TiInserted equ 0x3
TiSignalState equ 0x4
TiDueTime equ 0x18
TiTimerListEntry equ 0x20
TiDpc equ 0x30
TiPeriod equ 0x38
TimerObjectLength equ 0x40

; TIME
TmLowTime equ 0x0
TmHighTime equ 0x4

; SYSTEM_CONTEXT_SWITCH_INFORMATION (relative to FindAny)
TwFindAny equ 0x0
TwFindIdeal equ 0x8
TwFindLast equ 0x4
TwIdleAny equ 0xc
TwIdleCurrent equ 0x10
TwIdleIdeal equ 0x18
TwIdleLast equ 0x14
TwPreemptAny equ 0x1c
TwPreemptCurrent equ 0x20
TwPreemptLast equ 0x24
TwSwitchToIdle equ 0x28

; KUSER_SHARED_DATA
UsTickCountMultiplier equ 0x4
UsInterruptTime equ 0x8
UsSystemTime equ 0x14
UsTimeZoneBias equ 0x20
UsImageNumberLow equ 0x2c
UsImageNumberHigh equ 0x2e
UsNtSystemRoot equ 0x30
UsMaxStackTraceDepth equ 0x238
UsCryptoExponent equ 0x23c
UsTimeZoneId equ 0x240
UsLargePageMinimum equ 0x244
UsReserved2 equ 0x248
UsNtProductType equ 0x264
UsProductTypeIsValid equ 0x268
UsNtMajorVersion equ 0x26c
UsNtMinorVersion equ 0x270
UsProcessorFeatures equ 0x274
UsReserved1 equ 0x2b4
UsReserved3 equ 0x2b8
UsTimeSlip equ 0x2bc
UsAlternativeArchitecture equ 0x2c0
UsSystemExpirationDate equ 0x2c8
UsSuiteMask equ 0x2d0
UsKdDebuggerEnabled equ 0x2d4
UsActiveConsoleId equ 0x2d8
UsDismountCount equ 0x2dc
UsComPlusPackage equ 0x2e0
UsLastSystemRITEventTickCount equ 0x2e4
UsNumberOfPhysicalPages equ 0x2e8
UsSafeBootMode equ 0x2ec
UsTestRetInstruction equ 0x2f8
UsSystemCall equ 0x300
UsSystemCallReturn equ 0x304
UsSystemCallPad equ 0x308
UsTickCount equ 0x320
UsTickCountQuad equ 0x320
UsWow64SharedInformation equ 0x340

; KWAIT_BLOCK offsets
WbWaitListEntry equ 0x0
WbThread equ 0x10
WbObject equ 0x18
WbNextWaitBlock equ 0x20
WbWaitKey equ 0x28
WbWaitType equ 0x2a
