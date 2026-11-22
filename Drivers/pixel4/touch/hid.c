/*
 * PROJECT:     ReactOS Qualcomm platform drivers
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     HID minidriver requests and touch reports
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

#include "ftm5touch.h"

#include <debug.h>

/* Physical panel size in 0.1 mm, 1080x2280 at 444 ppi */
#define FTM5_PHYSICAL_X         618
#define FTM5_PHYSICAL_Y         1304

#define FTM5_HID_VENDOR         0x0483
#define FTM5_HID_PRODUCT        0x3639

#define FTM5_FINGER_COLLECTION \
    0x05, 0x0D,                     /* Usage Page (Digitizer) */ \
    0x09, 0x22,                     /* Usage (Finger) */ \
    0xA1, 0x02,                     /* Collection (Logical) */ \
    0x09, 0x42,                     /*   Usage (Tip Switch) */ \
    0x09, 0x32,                     /*   Usage (In Range) */ \
    0x15, 0x00,                     /*   Logical Minimum (0) */ \
    0x25, 0x01,                     /*   Logical Maximum (1) */ \
    0x75, 0x01,                     /*   Report Size (1) */ \
    0x95, 0x02,                     /*   Report Count (2) */ \
    0x81, 0x02,                     /*   Input (Data, Variable, Absolute) */ \
    0x95, 0x06,                     /*   Report Count (6) */ \
    0x81, 0x03,                     /*   Input (Constant, Variable, Absolute) */ \
    0x09, 0x51,                     /*   Usage (Contact Identifier) */ \
    0x25, FTM5_MAX_CONTACTS - 1,    /*   Logical Maximum */ \
    0x75, 0x08,                     /*   Report Size (8) */ \
    0x95, 0x01,                     /*   Report Count (1) */ \
    0x81, 0x02,                     /*   Input (Data, Variable, Absolute) */ \
    0x05, 0x01,                     /*   Usage Page (Generic Desktop) */ \
    0x26, 0xFF, 0x7F,               /*   Logical Maximum (32767) */ \
    0x75, 0x10,                     /*   Report Size (16) */ \
    0x55, 0x0E,                     /*   Unit Exponent (-2) */ \
    0x65, 0x11,                     /*   Unit (Centimeter) */ \
    0x35, 0x00,                     /*   Physical Minimum (0) */ \
    0x46, FTM5_PHYSICAL_X & 0xFF, FTM5_PHYSICAL_X >> 8, \
    0x09, 0x30,                     /*   Usage (X) */ \
    0x81, 0x02,                     /*   Input (Data, Variable, Absolute) */ \
    0x46, FTM5_PHYSICAL_Y & 0xFF, FTM5_PHYSICAL_Y >> 8, \
    0x09, 0x31,                     /*   Usage (Y) */ \
    0x81, 0x02,                     /*   Input (Data, Variable, Absolute) */ \
    0x45, 0x00,                     /*   Physical Maximum (0) */ \
    0x55, 0x00,                     /*   Unit Exponent (0) */ \
    0x65, 0x00,                     /*   Unit (None) */ \
    0xC0                            /* End Collection */

static const UCHAR Ftm5ReportDescriptor[] =
{
    /* Multi-touch screen, every contact in one report */
    0x05, 0x0D,                     /* Usage Page (Digitizer) */
    0x09, 0x04,                     /* Usage (Touch Screen) */
    0xA1, 0x01,                     /* Collection (Application) */
    0x85, FTM5_REPORT_ID_TOUCH,     /*   Report ID */
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    FTM5_FINGER_COLLECTION,
    0x05, 0x0D,                     /*   Usage Page (Digitizer) */
    0x09, 0x54,                     /*   Usage (Contact Count) */
    0x25, 0x7F,                     /*   Logical Maximum (127) */
    0x75, 0x08,                     /*   Report Size (8) */
    0x95, 0x01,                     /*   Report Count (1) */
    0x81, 0x02,                     /*   Input (Data, Variable, Absolute) */
    0x85, FTM5_REPORT_ID_MAXCOUNT,  /*   Report ID */
    0x09, 0x55,                     /*   Usage (Contact Count Maximum) */
    0x25, FTM5_MAX_CONTACTS,        /*   Logical Maximum */
    0xB1, 0x02,                     /*   Feature (Data, Variable, Absolute) */
    0xC0,                           /* End Collection */

    /* Device configuration, the input mode the host selects */
    0x05, 0x0D,                     /* Usage Page (Digitizer) */
    0x09, 0x0E,                     /* Usage (Device Configuration) */
    0xA1, 0x01,                     /* Collection (Application) */
    0x85, FTM5_REPORT_ID_CONFIG,    /*   Report ID */
    0x09, 0x23,                     /*   Usage (Device Settings) */
    0xA1, 0x02,                     /*   Collection (Logical) */
    0x09, 0x52,                     /*     Usage (Device Mode) */
    0x09, 0x53,                     /*     Usage (Device Identifier) */
    0x15, 0x00,                     /*     Logical Minimum (0) */
    0x25, 0x0A,                     /*     Logical Maximum (10) */
    0x75, 0x08,                     /*     Report Size (8) */
    0x95, 0x02,                     /*     Report Count (2) */
    0xB1, 0x02,                     /*     Feature (Data, Variable, Absolute) */
    0xC0,                           /*   End Collection */
    0xC0,                           /* End Collection */
};

static
NTSTATUS
Ftm5CopyOut(
    _In_ WDFREQUEST Request,
    _In_reads_bytes_(Length) const VOID *Data,
    _In_ ULONG Length)
{
    PVOID Buffer;
    NTSTATUS Status;

    Status = WdfRequestRetrieveOutputBuffer(Request, Length, &Buffer, NULL);
    if (!NT_SUCCESS(Status))
        return Status;

    RtlCopyMemory(Buffer, Data, Length);
    WdfRequestSetInformation(Request, Length);
    return STATUS_SUCCESS;
}

static volatile LONG Ftm5TracedDrains;

/**
 * @brief Hands queued reports to pending reads until one side runs dry.
 */
static
VOID
Ftm5DrainReports(
    _In_ PFTM5_DEVICE Device)
{
    FTM5_PENDING_REPORT Report;
    WDFREQUEST Request;
    NTSTATUS Status;

    for (;;)
    {
        WdfSpinLockAcquire(Device->ReportLock);
        if (Device->ReportCount == 0)
        {
            WdfSpinLockRelease(Device->ReportLock);
            return;
        }

        Status = WdfIoQueueRetrieveNextRequest(Device->ReadQueue, &Request);
        if (!NT_SUCCESS(Status))
        {
            WdfSpinLockRelease(Device->ReportLock);
            return;
        }

        Report = Device->Reports[Device->ReportHead];
        Device->ReportHead = (Device->ReportHead + 1) % FTM5_REPORT_RING;
        Device->ReportCount--;
        WdfSpinLockRelease(Device->ReportLock);

        Status = Ftm5CopyOut(Request, Report.Data, Report.Length);
        if (InterlockedIncrement(&Ftm5TracedDrains) <= FTM5_TRACE_LIMIT)
            DPRINT1("report of %lu bytes to hidclass: 0x%08lx\n", Report.Length, Status);
        WdfRequestComplete(Request, Status);
    }
}

static
VOID
Ftm5QueueReport(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(Length) const VOID *Data,
    _In_ ULONG Length)
{
    PFTM5_PENDING_REPORT Slot;

    WdfSpinLockAcquire(Device->ReportLock);

    /* Nobody is reading, so the oldest report is the one to lose */
    if (Device->ReportCount == FTM5_REPORT_RING)
    {
        Device->ReportHead = (Device->ReportHead + 1) % FTM5_REPORT_RING;
        Device->ReportCount--;
    }

    Slot = &Device->Reports[(Device->ReportHead + Device->ReportCount) % FTM5_REPORT_RING];
    RtlCopyMemory(Slot->Data, Data, Length);
    Slot->Length = Length;
    Device->ReportCount++;

    WdfSpinLockRelease(Device->ReportLock);

    Ftm5DrainReports(Device);
}

static
USHORT
Ftm5Scale(
    _In_ ULONG Value,
    _In_ ULONG Maximum)
{
    if (Value >= Maximum)
        return FTM5_LOGICAL_MAX;

    return (USHORT)((Value * FTM5_LOGICAL_MAX) / Maximum);
}

VOID
NTAPI
Ftm5ContactDown(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Slot,
    _In_ ULONG X,
    _In_ ULONG Y)
{
    Device->ContactX[Slot] = Ftm5Scale(X, FTM5_MAX_X);
    Device->ContactY[Slot] = Ftm5Scale(Y, FTM5_MAX_Y);
    Device->ContactMask |= 1 << Slot;
    Device->LiftMask &= ~(1 << Slot);
    Device->Changed = TRUE;
}

VOID
NTAPI
Ftm5ContactUp(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Slot)
{
    if (!(Device->ContactMask & (1 << Slot)))
        return;

    Device->ContactMask &= ~(1 << Slot);
    Device->LiftMask |= 1 << Slot;
    Device->Changed = TRUE;
}

/**
 * @brief Sends one report for a drained FIFO batch.
 *
 * Contacts that lifted in the batch go out once more without the tip bit, so
 * the host sees every contact end.
 */
VOID
NTAPI
Ftm5FlushContacts(
    _In_ PFTM5_DEVICE Device)
{
    FTM5_TOUCH_REPORT Touch;
    PFTM5_CONTACT_REPORT Contact;
    ULONG Slot;

    if (!Device->Changed)
        return;

    RtlZeroMemory(&Touch, sizeof(Touch));
    Touch.ReportId = FTM5_REPORT_ID_TOUCH;

    for (Slot = 0; Slot < FTM5_MAX_CONTACTS; Slot++)
    {
        BOOLEAN Down = (Device->ContactMask & (1 << Slot)) != 0;

        if (!Down && !(Device->LiftMask & (1 << Slot)))
            continue;

        Contact = &Touch.Contacts[Touch.ContactCount++];
        Contact->Flags = Down ? (FTM5_CONTACT_TIP | FTM5_CONTACT_IN_RANGE) : 0;
        Contact->ContactId = (UCHAR)Slot;
        Contact->X = Device->ContactX[Slot];
        Contact->Y = Device->ContactY[Slot];
    }

    Device->LiftMask = 0;
    Device->Changed = FALSE;

    if (Touch.ContactCount != 0)
        Ftm5QueueReport(Device, &Touch, sizeof(Touch));
}

/**
 * @brief Ends every contact still down, used when the sensor stops reporting.
 */
VOID
NTAPI
Ftm5ReleaseAll(
    _In_ PFTM5_DEVICE Device)
{
    ULONG Slot;

    for (Slot = 0; Slot < FTM5_MAX_CONTACTS; Slot++)
        Ftm5ContactUp(Device, Slot);

    Ftm5FlushContacts(Device);
}

static
NTSTATUS
Ftm5GetFeature(
    _In_ PFTM5_DEVICE Device,
    _In_ WDFREQUEST Request)
{
    PHID_XFER_PACKET Packet = WdfRequestWdmGetIrp(Request)->UserBuffer;

    if (Packet == NULL || Packet->reportBuffer == NULL || Packet->reportBufferLen < 2)
        return STATUS_INVALID_PARAMETER;

    switch (Packet->reportId)
    {
        case FTM5_REPORT_ID_MAXCOUNT:
            Packet->reportBuffer[0] = FTM5_REPORT_ID_MAXCOUNT;
            Packet->reportBuffer[1] = FTM5_MAX_CONTACTS;
            WdfRequestSetInformation(Request, 2);
            return STATUS_SUCCESS;

        case FTM5_REPORT_ID_CONFIG:
            if (Packet->reportBufferLen < 3)
                return STATUS_BUFFER_TOO_SMALL;

            Packet->reportBuffer[0] = FTM5_REPORT_ID_CONFIG;
            Packet->reportBuffer[1] = Device->InputMode;
            Packet->reportBuffer[2] = 0;
            WdfRequestSetInformation(Request, 3);
            return STATUS_SUCCESS;
    }

    return STATUS_INVALID_PARAMETER;
}

static
NTSTATUS
Ftm5SetFeature(
    _In_ PFTM5_DEVICE Device,
    _In_ WDFREQUEST Request)
{
    PHID_XFER_PACKET Packet = WdfRequestWdmGetIrp(Request)->UserBuffer;

    if (Packet == NULL || Packet->reportBuffer == NULL || Packet->reportBufferLen < 2)
        return STATUS_INVALID_PARAMETER;

    if (Packet->reportId != FTM5_REPORT_ID_CONFIG)
        return STATUS_INVALID_PARAMETER;

    Device->InputMode = Packet->reportBuffer[1];
    WdfRequestSetInformation(Request, Packet->reportBufferLen);
    return STATUS_SUCCESS;
}

VOID
NTAPI
Ftm5HidInternalIoctl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode)
{
    WDFDEVICE WdfDevice = WdfIoQueueGetDevice(Queue);
    PFTM5_DEVICE Device = Ftm5GetDevice(WdfDevice);
    WDF_REQUEST_SEND_OPTIONS Options;
    HID_DEVICE_ATTRIBUTES Attributes;
    HID_DESCRIPTOR Descriptor;
    NTSTATUS Status;

    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(InputBufferLength);

    switch (IoControlCode)
    {
        case IOCTL_HID_GET_DEVICE_DESCRIPTOR:
            RtlZeroMemory(&Descriptor, sizeof(Descriptor));
            Descriptor.bLength = sizeof(Descriptor);
            Descriptor.bDescriptorType = HID_HID_DESCRIPTOR_TYPE;
            Descriptor.bcdHID = HID_REVISION;
            Descriptor.bNumDescriptors = 1;
            Descriptor.DescriptorList[0].bReportType = HID_REPORT_DESCRIPTOR_TYPE;
            Descriptor.DescriptorList[0].wReportLength = sizeof(Ftm5ReportDescriptor);
            Status = Ftm5CopyOut(Request, &Descriptor, sizeof(Descriptor));
            break;

        case IOCTL_HID_GET_REPORT_DESCRIPTOR:
            Status = Ftm5CopyOut(Request, Ftm5ReportDescriptor, sizeof(Ftm5ReportDescriptor));
            break;

        case IOCTL_HID_GET_DEVICE_ATTRIBUTES:
            RtlZeroMemory(&Attributes, sizeof(Attributes));
            Attributes.Size = sizeof(Attributes);
            Attributes.VendorID = FTM5_HID_VENDOR;
            Attributes.ProductID = FTM5_HID_PRODUCT;
            Attributes.VersionNumber = 1;
            Status = Ftm5CopyOut(Request, &Attributes, sizeof(Attributes));
            break;

        case IOCTL_HID_READ_REPORT:
            Status = WdfRequestForwardToIoQueue(Request, Device->ReadQueue);
            if (!NT_SUCCESS(Status))
                break;

            Ftm5DrainReports(Device);
            return;

        case IOCTL_HID_GET_FEATURE:
            Status = Ftm5GetFeature(Device, Request);
            break;

        case IOCTL_HID_SET_FEATURE:
            Status = Ftm5SetFeature(Device, Request);
            break;

        case IOCTL_HID_ACTIVATE_DEVICE:
        case IOCTL_HID_DEACTIVATE_DEVICE:
            Status = STATUS_SUCCESS;
            break;

        case IOCTL_HID_GET_STRING:
        case IOCTL_HID_WRITE_REPORT:
        case IOCTL_HID_GET_INPUT_REPORT:
        case IOCTL_HID_SET_OUTPUT_REPORT:
            Status = STATUS_NOT_SUPPORTED;
            break;

        default:
            /* Not a HID request, it belongs to the bus below */
            WdfRequestFormatRequestUsingCurrentType(Request);
            WDF_REQUEST_SEND_OPTIONS_INIT(&Options, WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET);
            if (WdfRequestSend(Request, WdfDeviceGetIoTarget(WdfDevice), &Options))
                return;

            Status = WdfRequestGetStatus(Request);
            break;
    }

    WdfRequestComplete(Request, Status);
}
