/*
 * PROJECT:     ReactOS Qualcomm platform drivers
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     ST FTM5 SPI touch controller as a HID digitizer under mshidkmdf
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

/*
 * Lower filter below mshidkmdf on the ACPI touch device. The SPI target, the
 * interrupt GpioInt and the reset GpioIo come from the resource hub. The rails
 * and the AP/SLPI bus switch are PEP votes on the D0 and D3 transitions.
 */

#include "ftm5touch.h"

#include <debug.h>

DRIVER_INITIALIZE DriverEntry;
static EVT_WDF_DRIVER_DEVICE_ADD Ftm5EvtDeviceAdd;
static EVT_WDF_DEVICE_PREPARE_HARDWARE Ftm5EvtPrepareHardware;
static EVT_WDF_DEVICE_RELEASE_HARDWARE Ftm5EvtReleaseHardware;
static EVT_WDF_DEVICE_D0_ENTRY Ftm5EvtD0Entry;
static EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED Ftm5EvtD0EntryPostInterruptsEnabled;
static EVT_WDF_DEVICE_D0_EXIT Ftm5EvtD0Exit;
static EVT_WDF_INTERRUPT_ISR Ftm5EvtInterruptIsr;
static EVT_WDF_INTERRUPT_WORKITEM Ftm5EvtInterruptWorkItem;
static EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL Ftm5EvtIoInternalDeviceControl;

/* FIFO drains per interrupt before giving the line back */
#define FTM5_SERVICE_LOOPS      8

static
NTSTATUS
NTAPI
Ftm5EvtPrepareHardware(
    _In_ WDFDEVICE WdfDevice,
    _In_ WDFCMRESLIST Resources,
    _In_ WDFCMRESLIST ResourcesTranslated)
{
    PFTM5_DEVICE Device = Ftm5GetDevice(WdfDevice);
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor;
    ULONG Count;
    ULONG Index;
    NTSTATUS Status;

    UNREFERENCED_PARAMETER(Resources);

    Count = WdfCmResourceListGetCount(ResourcesTranslated);
    for (Index = 0; Index < Count; Index++)
    {
        Descriptor = WdfCmResourceListGetDescriptor(ResourcesTranslated, Index);
        if (Descriptor == NULL || Descriptor->Type != CmResourceTypeConnection)
            continue;

        if (Descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_SERIAL &&
            Descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_SERIAL_SPI &&
            !Device->HasSpi)
        {
            Device->SpiId.LowPart = Descriptor->u.Connection.IdLowPart;
            Device->SpiId.HighPart = Descriptor->u.Connection.IdHighPart;
            Device->HasSpi = TRUE;
        }
        else if (Descriptor->u.Connection.Class == CM_RESOURCE_CONNECTION_CLASS_GPIO &&
                 Descriptor->u.Connection.Type == CM_RESOURCE_CONNECTION_TYPE_GPIO_IO &&
                 !Device->HasReset)
        {
            Device->ResetId.LowPart = Descriptor->u.Connection.IdLowPart;
            Device->ResetId.HighPart = Descriptor->u.Connection.IdHighPart;
            Device->HasReset = TRUE;
        }
    }

    if (!Device->HasSpi)
    {
        DPRINT1("no SPI connection in the resources\n");
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    Status = Ftm5OpenConnection(Device, Device->SpiId, &Device->Spi);
    if (!NT_SUCCESS(Status))
        return Status;

    if (Device->HasReset)
    {
        Status = Ftm5OpenConnection(Device, Device->ResetId, &Device->Reset);
        if (!NT_SUCCESS(Status))
            return Status;
    }

    /* The rails are PEP votes tied to D-states. HIDCLASS registers the stack with
       PoFx, a second registration from this filter bugchecks Windows. */
    return STATUS_SUCCESS;
}

static
NTSTATUS
NTAPI
Ftm5EvtReleaseHardware(
    _In_ WDFDEVICE WdfDevice,
    _In_ WDFCMRESLIST ResourcesTranslated)
{
    PFTM5_DEVICE Device = Ftm5GetDevice(WdfDevice);

    UNREFERENCED_PARAMETER(ResourcesTranslated);

    if (Device->Reset)
    {
        WdfObjectDelete(Device->Reset);
        Device->Reset = NULL;
    }

    if (Device->Spi)
    {
        WdfObjectDelete(Device->Spi);
        Device->Spi = NULL;
    }

    Device->HasSpi = FALSE;
    Device->HasReset = FALSE;
    return STATUS_SUCCESS;
}

static
NTSTATUS
NTAPI
Ftm5EvtD0Entry(
    _In_ WDFDEVICE WdfDevice,
    _In_ WDF_POWER_DEVICE_STATE PreviousState)
{
    PFTM5_DEVICE Device = Ftm5GetDevice(WdfDevice);
    NTSTATUS Status;

    WdfWaitLockAcquire(Device->BusLock, NULL);

    Status = Ftm5Start(Device);
    Device->Ready = NT_SUCCESS(Status);

    WdfWaitLockRelease(Device->BusLock);

    DPRINT1("D0 entry from D%d: FTM5 bring-up 0x%08lx\n", PreviousState - WdfPowerDeviceD0, Status);
    return Status;
}

/**
 * @brief Drains the FIFO until the controller has nothing left.
 */
static
VOID
Ftm5Service(
    _In_ PFTM5_DEVICE Device)
{
    ULONG Loop;
    NTSTATUS Status;

    WdfWaitLockAcquire(Device->BusLock, NULL);

    for (Loop = 0; Device->Ready && Loop < FTM5_SERVICE_LOOPS; Loop++)
    {
        Status = Ftm5ServiceFifo(Device);
        if (!NT_SUCCESS(Status) || Status == STATUS_NO_MORE_ENTRIES)
            break;
    }

    WdfWaitLockRelease(Device->BusLock);
}

/* Events queued before the interrupt was connected keep the line low until read */
static
NTSTATUS
NTAPI
Ftm5EvtD0EntryPostInterruptsEnabled(
    _In_ WDFDEVICE WdfDevice,
    _In_ WDF_POWER_DEVICE_STATE PreviousState)
{
    UNREFERENCED_PARAMETER(PreviousState);

    Ftm5Service(Ftm5GetDevice(WdfDevice));
    return STATUS_SUCCESS;
}

static
NTSTATUS
NTAPI
Ftm5EvtD0Exit(
    _In_ WDFDEVICE WdfDevice,
    _In_ WDF_POWER_DEVICE_STATE TargetState)
{
    PFTM5_DEVICE Device = Ftm5GetDevice(WdfDevice);

    DPRINT1("D0 exit to D%d, sensor %s\n", TargetState - WdfPowerDeviceD0, Device->Ready ? "ready" : "not ready");

    WdfWaitLockAcquire(Device->BusLock, NULL);

    if (Device->Ready)
        Ftm5Stop(Device);

    Device->Ready = FALSE;
    Ftm5ReleaseAll(Device);

    WdfWaitLockRelease(Device->BusLock);
    return STATUS_SUCCESS;
}

/* The line is a GPIO behind msgpioclx, the bus work has to wait for passive level */
static
BOOLEAN
NTAPI
Ftm5EvtInterruptIsr(
    _In_ WDFINTERRUPT Interrupt,
    _In_ ULONG MessageID)
{
    UNREFERENCED_PARAMETER(MessageID);

    WdfInterruptQueueWorkItemForIsr(Interrupt);
    return TRUE;
}

static
VOID
NTAPI
Ftm5EvtInterruptWorkItem(
    _In_ WDFINTERRUPT Interrupt,
    _In_ WDFOBJECT AssociatedObject)
{
    UNREFERENCED_PARAMETER(AssociatedObject);

    Ftm5Service(Ftm5GetDevice(WdfInterruptGetDevice(Interrupt)));
}

static
VOID
NTAPI
Ftm5EvtIoInternalDeviceControl(
    _In_ WDFQUEUE Queue,
    _In_ WDFREQUEST Request,
    _In_ size_t OutputBufferLength,
    _In_ size_t InputBufferLength,
    _In_ ULONG IoControlCode)
{
    Ftm5HidInternalIoctl(Queue, Request, OutputBufferLength, InputBufferLength, IoControlCode);
}

static
NTSTATUS
NTAPI
Ftm5EvtDeviceAdd(
    _In_ WDFDRIVER Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit)
{
    WDF_PNPPOWER_EVENT_CALLBACKS PnpPower;
    WDF_OBJECT_ATTRIBUTES Attributes;
    WDF_IO_QUEUE_CONFIG QueueConfig;
    WDF_INTERRUPT_CONFIG InterruptConfig;
    PFTM5_DEVICE Device;
    WDFDEVICE WdfDevice;
    NTSTATUS Status;

    UNREFERENCED_PARAMETER(Driver);

    WdfFdoInitSetFilter(DeviceInit);

    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&PnpPower);
    PnpPower.EvtDevicePrepareHardware = Ftm5EvtPrepareHardware;
    PnpPower.EvtDeviceReleaseHardware = Ftm5EvtReleaseHardware;
    PnpPower.EvtDeviceD0Entry = Ftm5EvtD0Entry;
    PnpPower.EvtDeviceD0EntryPostInterruptsEnabled = Ftm5EvtD0EntryPostInterruptsEnabled;
    PnpPower.EvtDeviceD0Exit = Ftm5EvtD0Exit;
    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &PnpPower);

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&Attributes, FTM5_DEVICE);
    Status = WdfDeviceCreate(&DeviceInit, &Attributes, &WdfDevice);
    if (!NT_SUCCESS(Status))
        return Status;

    Device = Ftm5GetDevice(WdfDevice);
    Device->Device = WdfDevice;

    WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
    Attributes.ParentObject = WdfDevice;
    Status = WdfWaitLockCreate(&Attributes, &Device->BusLock);
    if (!NT_SUCCESS(Status))
        return Status;

    Status = WdfSpinLockCreate(&Attributes, &Device->ReportLock);
    if (!NT_SUCCESS(Status))
        return Status;

    /* hidclass talks to the minidriver only through internal device controls */
    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&QueueConfig, WdfIoQueueDispatchParallel);
    QueueConfig.EvtIoInternalDeviceControl = Ftm5EvtIoInternalDeviceControl;
    Status = WdfIoQueueCreate(WdfDevice, &QueueConfig, WDF_NO_OBJECT_ATTRIBUTES, NULL);
    if (!NT_SUCCESS(Status))
        return Status;

    WDF_IO_QUEUE_CONFIG_INIT(&QueueConfig, WdfIoQueueDispatchManual);
    QueueConfig.PowerManaged = WdfFalse;
    Status = WdfIoQueueCreate(WdfDevice, &QueueConfig, WDF_NO_OBJECT_ATTRIBUTES, &Device->ReadQueue);
    if (!NT_SUCCESS(Status))
        return Status;

    WDF_INTERRUPT_CONFIG_INIT(&InterruptConfig, Ftm5EvtInterruptIsr, NULL);
    InterruptConfig.EvtInterruptWorkItem = Ftm5EvtInterruptWorkItem;
    Status = WdfInterruptCreate(WdfDevice, &InterruptConfig, WDF_NO_OBJECT_ATTRIBUTES, &Device->Interrupt);
    if (!NT_SUCCESS(Status))
        DPRINT1("WdfInterruptCreate failed, 0x%08lx\n", Status);

    return Status;
}

NTSTATUS
NTAPI
DriverEntry(
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath)
{
    WDF_DRIVER_CONFIG Config;

    WDF_DRIVER_CONFIG_INIT(&Config, Ftm5EvtDeviceAdd);
    return WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &Config, WDF_NO_HANDLE);
}
