/*
 * PROJECT:     ReactOS Qualcomm platform drivers
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     ST FTM5 bring-up and event FIFO handling
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

#include "ftm5touch.h"

#include <debug.h>

static volatile LONG Ftm5TracedEvents;

VOID
NTAPI
Ftm5Delay(
    _In_ ULONG Milliseconds)
{
    LARGE_INTEGER Interval;

    Interval.QuadPart = -10000LL * Milliseconds;
    KeDelayExecutionThread(KernelMode, FALSE, &Interval);
}

static
NTSTATUS
Ftm5ReadFifo(
    _In_ PFTM5_DEVICE Device,
    _Out_writes_bytes_(Count * FTM5_EVENT_SIZE) PUCHAR Events,
    _In_ ULONG Count)
{
    UCHAR Op = FTM5_OP_FIFO_READ;

    return Ftm5SpiWriteRead(Device, &Op, sizeof(Op), Events, Count * FTM5_EVENT_SIZE);
}

static
NTSTATUS
Ftm5ReadRegister(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Address,
    _Out_writes_bytes_(Length) PUCHAR Data,
    _In_ ULONG Length)
{
    UCHAR Command[5];

    Command[0] = FTM5_OP_HW_REG_READ;
    Command[1] = (UCHAR)(Address >> 24);
    Command[2] = (UCHAR)(Address >> 16);
    Command[3] = (UCHAR)(Address >> 8);
    Command[4] = (UCHAR)Address;

    return Ftm5SpiWriteRead(Device, Command, sizeof(Command), Data, Length);
}

static
NTSTATUS
Ftm5WriteRegister(
    _In_ PFTM5_DEVICE Device,
    _In_ ULONG Address,
    _In_ UCHAR Value)
{
    UCHAR Command[6];

    Command[0] = FTM5_OP_HW_REG_WRITE;
    Command[1] = (UCHAR)(Address >> 24);
    Command[2] = (UCHAR)(Address >> 16);
    Command[3] = (UCHAR)(Address >> 8);
    Command[4] = (UCHAR)Address;
    Command[5] = Value;

    return Ftm5SpiWrite(Device, Command, sizeof(Command));
}

static
NTSTATUS
Ftm5SetScanMode(
    _In_ PFTM5_DEVICE Device,
    _In_ UCHAR Mode,
    _In_ UCHAR Settings)
{
    UCHAR Command[3];

    Command[0] = FTM5_OP_SCAN_MODE;
    Command[1] = Mode;
    Command[2] = Settings;

    return Ftm5SpiWrite(Device, Command, sizeof(Command));
}

/**
 * @brief Polls the FIFO until the firmware says it finished booting.
 */
static
NTSTATUS
Ftm5WaitReady(
    _In_ PFTM5_DEVICE Device)
{
    UCHAR Event[FTM5_EVENT_SIZE];
    ULONG Waited;
    NTSTATUS Status;

    for (Waited = 0; Waited < FTM5_READY_TIMEOUT_MS; Waited += FTM5_READY_POLL_MS)
    {
        Status = Ftm5ReadFifo(Device, Event, 1);
        if (!NT_SUCCESS(Status))
            return Status;

        if (Event[0] == FTM5_EVENT_CONTROLLER_READY)
            return STATUS_SUCCESS;

        if (Event[0] == FTM5_EVENT_ERROR)
            DPRINT1("error event during boot: %02x %02x %02x %02x\n", Event[1], Event[2], Event[3], Event[4]);

        Ftm5Delay(FTM5_READY_POLL_MS);
    }

    return STATUS_IO_TIMEOUT;
}

/**
 * @brief Resets the controller, waits for its firmware and turns sensing on.
 *
 * The rails and the bus switch are already set by the PEP D0 entry.
 */
NTSTATUS
NTAPI
Ftm5Start(
    _In_ PFTM5_DEVICE Device)
{
    UCHAR ChipId[2];
    NTSTATUS Status;

    if (Device->Reset)
    {
        Status = Ftm5GpioWrite(Device->Reset, FALSE);
        if (!NT_SUCCESS(Status))
            return Status;

        Ftm5Delay(FTM5_RESET_PULSE_MS);

        Status = Ftm5GpioWrite(Device->Reset, TRUE);
    }
    else
    {
        Status = Ftm5WriteRegister(Device, FTM5_REG_SYSTEM_RESET, FTM5_SYSTEM_RESET_VALUE);
    }

    if (!NT_SUCCESS(Status))
        return Status;

    Status = Ftm5WaitReady(Device);
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("controller never reported ready, 0x%08lx\n", Status);
        return Status;
    }

    Status = Ftm5ReadRegister(Device, FTM5_REG_CHIP_ID, ChipId, sizeof(ChipId));
    if (!NT_SUCCESS(Status))
        return Status;

    if (ChipId[0] != FTM5_CHIP_ID_0 || ChipId[1] != FTM5_CHIP_ID_1)
    {
        DPRINT1("unexpected chip id %02x%02x\n", ChipId[0], ChipId[1]);
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    return Ftm5SetScanMode(Device, FTM5_SCAN_MODE_ACTIVE, FTM5_SCAN_ALL);
}

NTSTATUS
NTAPI
Ftm5Stop(
    _In_ PFTM5_DEVICE Device)
{
    return Ftm5SetScanMode(Device, FTM5_SCAN_MODE_ACTIVE, FTM5_SCAN_NONE);
}

static
VOID
Ftm5HandleEvent(
    _In_ PFTM5_DEVICE Device,
    _In_reads_bytes_(FTM5_EVENT_SIZE) const UCHAR *Event)
{
    ULONG Class = Event[0] >> 4;
    ULONG Type = Event[1] & 0x0F;
    ULONG Slot = Event[1] >> 4;
    ULONG X;
    ULONG Y;

    if (Event[0] == FTM5_EVENT_ERROR)
    {
        DPRINT1("error event %02x %02x %02x %02x\n", Event[1], Event[2], Event[3], Event[4]);
        return;
    }

    if (Class != FTM5_EVENT_CLASS_ENTER && Class != FTM5_EVENT_CLASS_MOTION && Class != FTM5_EVENT_CLASS_LEAVE)
        return;

    if (Slot >= FTM5_MAX_CONTACTS)
        return;

    if (Class == FTM5_EVENT_CLASS_LEAVE)
    {
        Ftm5ContactUp(Device, Slot);
        return;
    }

    /* Hover is not a contact, the rest all are */
    if (Type == FTM5_TOUCH_TYPE_HOVER || Type > FTM5_TOUCH_TYPE_PALM)
        return;

    X = ((ULONG)(Event[3] & 0x0F) << 8) | Event[2];
    Y = ((ULONG)Event[4] << 4) | (Event[3] >> 4);

    if (InterlockedIncrement(&Ftm5TracedEvents) <= FTM5_TRACE_LIMIT * 3)
        DPRINT1("slot %lu type %lu at %lu,%lu\n", Slot, Type, X, Y);

    Ftm5ContactDown(Device, Slot, X, Y);
}

/**
 * @brief Drains the FIFO and reports what changed.
 *
 * The last byte of the first event counts the events still queued behind it.
 */
NTSTATUS
NTAPI
Ftm5ServiceFifo(
    _In_ PFTM5_DEVICE Device)
{
    UCHAR Events[FTM5_EVENT_SIZE * FTM5_FIFO_DEPTH];
    ULONG Remaining;
    ULONG Index;
    NTSTATUS Status;

    Status = Ftm5ReadFifo(Device, Events, 1);
    if (!NT_SUCCESS(Status))
        return Status;

    if (Events[0] == FTM5_EVENT_NONE || Events[0] == 0xFF)
        return STATUS_NO_MORE_ENTRIES;

    Remaining = Events[FTM5_EVENT_SIZE - 1] & FTM5_EVENT_REMAINING_MASK;
    if (Remaining > FTM5_FIFO_DEPTH - 1)
        Remaining = FTM5_FIFO_DEPTH - 1;

    if (Remaining != 0)
    {
        Status = Ftm5ReadFifo(Device, &Events[FTM5_EVENT_SIZE], Remaining);
        if (!NT_SUCCESS(Status))
            Remaining = 0;
    }

    for (Index = 0; Index <= Remaining; Index++)
    {
        const UCHAR *Event = &Events[Index * FTM5_EVENT_SIZE];

        if (Event[0] == FTM5_EVENT_NONE)
            break;

        Ftm5HandleEvent(Device, Event);
    }

    Ftm5FlushContacts(Device);
    return STATUS_SUCCESS;
}
