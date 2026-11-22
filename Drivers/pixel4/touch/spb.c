/*
 * PROJECT:     ReactOS Qualcomm platform drivers
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     SPI and GPIO connections opened through the resource hub
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

#include "ftm5touch.h"

#include <debug.h>

#define FTM5_IO_TIMEOUT_MS      500

/* Largest read: a full FIFO plus the dummy byte */
#define FTM5_SPI_READ_MAX       (FTM5_EVENT_SIZE * FTM5_FIFO_DEPTH + FTM5_SPI_DUMMY_BYTES)

NTSTATUS
NTAPI
Ftm5OpenConnection(
    _In_ PFTM5_DEVICE Device,
    _In_ LARGE_INTEGER Id,
    _Out_ WDFIOTARGET *Target)
{
    DECLARE_UNICODE_STRING_SIZE(Path, RESOURCE_HUB_CONNECTION_PATH_CHARS);
    WDF_IO_TARGET_OPEN_PARAMS OpenParams;
    WDF_OBJECT_ATTRIBUTES Attributes;
    WDFIOTARGET NewTarget;
    NTSTATUS Status;

    *Target = NULL;

    Status = RESOURCE_HUB_CREATE_PATH_FROM_ID(&Path, Id.LowPart, Id.HighPart);
    if (!NT_SUCCESS(Status))
        return Status;

    WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
    Attributes.ParentObject = Device->Device;

    Status = WdfIoTargetCreate(Device->Device, &Attributes, &NewTarget);
    if (!NT_SUCCESS(Status))
        return Status;

    WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(&OpenParams, &Path, GENERIC_READ | GENERIC_WRITE);
    Status = WdfIoTargetOpen(NewTarget, &OpenParams);
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("open of %wZ failed, 0x%08lx\n", &Path, Status);
        WdfObjectDelete(NewTarget);
        return Status;
    }

    *Target = NewTarget;
    return STATUS_SUCCESS;
}

static
VOID
Ftm5SetTimeout(
    _Out_ PWDF_REQUEST_SEND_OPTIONS Options)
{
    WDF_REQUEST_SEND_OPTIONS_INIT(Options, WDF_REQUEST_SEND_OPTION_TIMEOUT);
    WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(Options, WDF_REL_TIMEOUT_IN_MS(FTM5_IO_TIMEOUT_MS));
}

NTSTATUS
NTAPI
Ftm5SpiWrite(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(Length) PVOID Buffer,
    _In_ ULONG Length)
{
    WDF_MEMORY_DESCRIPTOR Memory;
    WDF_REQUEST_SEND_OPTIONS Options;
    ULONG_PTR Written = 0;
    NTSTATUS Status;

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&Memory, Buffer, Length);
    Ftm5SetTimeout(&Options);

    Status = WdfIoTargetSendWriteSynchronously(Device->Spi, NULL, &Memory, NULL, &Options, &Written);
    if (NT_SUCCESS(Status) && Written != 0 && Written != Length)
        Status = STATUS_DEVICE_PROTOCOL_ERROR;

    return Status;
}

/**
 * @brief Sends the op code and reads back under one chip select. The first
 * byte clocked in is a dummy and is dropped before the data is returned.
 */
NTSTATUS
NTAPI
Ftm5SpiWriteRead(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(WriteLength) PVOID WriteBuffer,
    _In_ ULONG WriteLength,
    _Out_writes_bytes_(ReadLength) PVOID ReadBuffer,
    _In_ ULONG ReadLength)
{
    SPB_TRANSFER_LIST_AND_ENTRIES(2) Sequence;
    UCHAR Raw[FTM5_SPI_READ_MAX];
    WDF_MEMORY_DESCRIPTOR Memory;
    WDF_REQUEST_SEND_OPTIONS Options;
    ULONG_PTR Transferred = 0;
    ULONG RawLength = ReadLength + FTM5_SPI_DUMMY_BYTES;
    NTSTATUS Status;

    if (RawLength > sizeof(Raw))
        return STATUS_BUFFER_OVERFLOW;

    SPB_TRANSFER_LIST_INIT(&Sequence.List, 2);
    Sequence.List.Transfers[0] = SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(SpbTransferDirectionToDevice,
                                                                     0,
                                                                     WriteBuffer,
                                                                     WriteLength);
    Sequence.List.Transfers[1] = SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(SpbTransferDirectionFromDevice,
                                                                     0,
                                                                     Raw,
                                                                     RawLength);

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&Memory, &Sequence, sizeof(Sequence));
    Ftm5SetTimeout(&Options);

    Status = WdfIoTargetSendIoctlSynchronously(Device->Spi,
                                               NULL,
                                               IOCTL_SPB_EXECUTE_SEQUENCE,
                                               &Memory,
                                               NULL,
                                               &Options,
                                               &Transferred);
    /* Controllers differ on what they count, so only a short transfer fails */
    if (NT_SUCCESS(Status) && Transferred != 0 && Transferred < RawLength)
        Status = STATUS_DEVICE_PROTOCOL_ERROR;

    if (NT_SUCCESS(Status))
        RtlCopyMemory(ReadBuffer, Raw + FTM5_SPI_DUMMY_BYTES, ReadLength);

    return Status;
}

NTSTATUS
NTAPI
Ftm5GpioWrite(
    _In_ WDFIOTARGET Target,
    _In_ BOOLEAN High)
{
    WDF_MEMORY_DESCRIPTOR Memory;
    WDF_REQUEST_SEND_OPTIONS Options;
    UCHAR Value = High ? 1 : 0;

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&Memory, &Value, sizeof(Value));
    Ftm5SetTimeout(&Options);

    return WdfIoTargetSendIoctlSynchronously(Target,
                                             NULL,
                                             IOCTL_GPIO_WRITE_PINS,
                                             &Memory,
                                             NULL,
                                             &Options,
                                             NULL);
}
