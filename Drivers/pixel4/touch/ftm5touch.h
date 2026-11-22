/*
 * PROJECT:     ReactOS Qualcomm platform drivers
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     ST FTM5 SPI touch controller as a HID digitizer under mshidkmdf
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

#pragma once

#define RESHUB_USE_HELPER_ROUTINES

#include <ntddk.h>
#include <wdf.h>
#include <hidport.h>
#include <spb.h>
#include <gpio.h>
#include <reshub.h>

#define FTM5_POOL_TAG               '5mtF'

/* Op codes on the SPI interface. Reads return one dummy byte ahead of the data. */
#define FTM5_OP_HW_REG_WRITE        0xFA
#define FTM5_OP_HW_REG_READ         0xFB
#define FTM5_OP_FIFO_READ           0x87
#define FTM5_OP_SCAN_MODE           0xA0
#define FTM5_SPI_DUMMY_BYTES        1

/* Hardware registers take a 32 bit big endian address */
#define FTM5_REG_CHIP_ID            0x20000000
#define FTM5_REG_SYSTEM_RESET       0x20000024
#define FTM5_SYSTEM_RESET_VALUE     0x81

#define FTM5_CHIP_ID_0              0x36
#define FTM5_CHIP_ID_1              0x39

#define FTM5_SCAN_MODE_ACTIVE       0x00
#define FTM5_SCAN_MODE_LOCKED       0x03
#define FTM5_SCAN_ALL               0xFF
#define FTM5_SCAN_NONE              0x00

/* Event FIFO: 8 byte records, the high nibble of byte 0 says what it is */
#define FTM5_EVENT_SIZE             8
#define FTM5_FIFO_DEPTH             32
#define FTM5_EVENT_REMAINING_MASK   0x1F

#define FTM5_EVENT_NONE             0x00
#define FTM5_EVENT_CONTROLLER_READY 0x03
#define FTM5_EVENT_ERROR            0xF3

#define FTM5_EVENT_CLASS_ENTER      0x1
#define FTM5_EVENT_CLASS_MOTION     0x2
#define FTM5_EVENT_CLASS_LEAVE      0x3

#define FTM5_TOUCH_TYPE_HOVER       0x00
#define FTM5_TOUCH_TYPE_FINGER      0x01
#define FTM5_TOUCH_TYPE_GLOVE       0x02
#define FTM5_TOUCH_TYPE_STYLUS      0x03
#define FTM5_TOUCH_TYPE_PALM        0x04

/* Reset pulse and how long the firmware may take to report ready */
#define FTM5_RESET_PULSE_MS         10
#define FTM5_READY_TIMEOUT_MS       750
#define FTM5_READY_POLL_MS          5

/* The firmware reports panel pixels, the Pixel 4 panel is 1080x2280 */
#define FTM5_MAX_X                  1079
#define FTM5_MAX_Y                  2279

/* HID layout, see hid.c */
#define FTM5_MAX_CONTACTS           10
#define FTM5_LOGICAL_MAX            0x7FFF

#define FTM5_REPORT_ID_TOUCH        0x01
#define FTM5_REPORT_ID_MAXCOUNT     0x03
#define FTM5_REPORT_ID_CONFIG       0x04

#include <pshpack1.h>
typedef struct _FTM5_CONTACT_REPORT
{
    UCHAR Flags;
    UCHAR ContactId;
    USHORT X;
    USHORT Y;
} FTM5_CONTACT_REPORT, *PFTM5_CONTACT_REPORT;

typedef struct _FTM5_TOUCH_REPORT
{
    UCHAR ReportId;
    FTM5_CONTACT_REPORT Contacts[FTM5_MAX_CONTACTS];
    UCHAR ContactCount;
} FTM5_TOUCH_REPORT, *PFTM5_TOUCH_REPORT;
#include <poppack.h>

#define FTM5_CONTACT_TIP            0x01
#define FTM5_CONTACT_IN_RANGE       0x02

/* Input reports wait here until hidclass has a read pending */
#define FTM5_REPORT_RING            32

/* Events per stage reported before the trace goes quiet */
#define FTM5_TRACE_LIMIT            16

typedef struct _FTM5_PENDING_REPORT
{
    ULONG Length;
    UCHAR Data[sizeof(FTM5_TOUCH_REPORT)];
} FTM5_PENDING_REPORT, *PFTM5_PENDING_REPORT;

typedef struct _FTM5_DEVICE
{
    WDFDEVICE Device;

    /* Resource hub connections from the _CRS */
    LARGE_INTEGER SpiId;
    LARGE_INTEGER ResetId;
    BOOLEAN HasSpi;
    BOOLEAN HasReset;
    WDFIOTARGET Spi;
    WDFIOTARGET Reset;

    WDFINTERRUPT Interrupt;
    WDFWAITLOCK BusLock;
    BOOLEAN Ready;

    /* Contacts the firmware has reported down, by its slot id, and the ones lifted since the last report */
    ULONG ContactMask;
    ULONG LiftMask;
    BOOLEAN Changed;
    USHORT ContactX[FTM5_MAX_CONTACTS];
    USHORT ContactY[FTM5_MAX_CONTACTS];
    UCHAR InputMode;

    /* hidclass reads and the reports waiting for them */
    WDFQUEUE ReadQueue;
    WDFSPINLOCK ReportLock;
    ULONG ReportHead;
    ULONG ReportCount;
    FTM5_PENDING_REPORT Reports[FTM5_REPORT_RING];
} FTM5_DEVICE, *PFTM5_DEVICE;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(FTM5_DEVICE, Ftm5GetDevice)

/* spb.c */

NTSTATUS
NTAPI
Ftm5OpenConnection(
    _In_ PFTM5_DEVICE Device,
    _In_ LARGE_INTEGER Id,
    _Out_ WDFIOTARGET *Target);

NTSTATUS
NTAPI
Ftm5SpiWrite(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length);

NTSTATUS
NTAPI
Ftm5SpiWriteRead(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(WriteLength) PVOID WriteBuffer,
    _In_ ULONG WriteLength,
    _Out_writes_bytes_(ReadLength) PVOID ReadBuffer,
    _In_ ULONG ReadLength);

NTSTATUS
NTAPI
Ftm5GpioWrite(
    _In_ WDFIOTARGET Target,
    _In_ BOOLEAN High);

/* ftm5.c */

VOID
NTAPI
Ftm5Delay(
    _In_ ULONG Milliseconds);

NTSTATUS
NTAPI
Ftm5Start(
    _In_ PFTM5_DEVICE Device);

NTSTATUS
NTAPI
Ftm5Stop(
    _In_ PFTM5_DEVICE Device);

NTSTATUS
NTAPI
Ftm5ServiceFifo(
    _In_ PFTM5_DEVICE Device);

/* hid.c */

VOID
NTAPI
Ftm5HidInternalIoctl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode);

VOID
NTAPI
Ftm5ContactDown(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Slot,
    _In_ ULONG X,
    _In_ ULONG Y);

VOID
NTAPI
Ftm5ContactUp(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Slot);

VOID
NTAPI
Ftm5FlushContacts(
    _In_ PFTM5_DEVICE Device);

VOID
NTAPI
Ftm5ReleaseAll(
    _In_ PFTM5_DEVICE Device);
