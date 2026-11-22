/*
 * PROJECT:     ReactOS Qualcomm audio (SDM845)
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     PortCls adapter: installs the wave and topology subdevices
 * COPYRIGHT:   Copyright 2026 Justin Miller <justin.miller@reactos.org>
 */

#include "precomp.h"

#define QCA_LOG(...) DbgPrint("[qcomaudio] " __VA_ARGS__)

#ifdef _MSC_VER
#pragma code_seg("PAGE")
#endif

/**
 * @brief Keeps the last start step and its status in the service Parameters key, readable without a debugger.
 */
static
VOID
RecordStartStep(
    _In_ PCWSTR Step,
    _In_ NTSTATUS Status)
{
    PAGED_CODE();

    ULONG Value = (ULONG)Status;

    RtlWriteRegistryValue(RTL_REGISTRY_SERVICES, L"qcomaudio\\Parameters", L"StartStep", REG_SZ,
                          (PVOID)Step, (ULONG)((wcslen(Step) + 1) * sizeof(*Step)));
    RtlWriteRegistryValue(RTL_REGISTRY_SERVICES, L"qcomaudio\\Parameters", L"StartStatus", REG_DWORD,
                          &Value, sizeof(Value));
}

static
NTSTATUS
InstallSubdevice(PDEVICE_OBJECT DeviceObject, PIRP Irp, PWCHAR Name, REFGUID PortClassId,
                 PFNCREATEINSTANCE MiniportCreate, PRESOURCELIST ResourceList,
                 PUNKNOWN *OutPortUnknown)
{
    PAGED_CODE();

    PPORT Port;
    PMINIPORT Miniport;
    NTSTATUS Status;

    Status = PcNewPort(&Port, PortClassId);
    if (!NT_SUCCESS(Status))
    {
        QCA_LOG("%S: PcNewPort failed 0x%08lx\n", Name, Status);
        RecordStartStep(Name[0] == L'W' ? L"Wave PcNewPort" : L"Topology PcNewPort", Status);
        return Status;
    }

    Status = MiniportCreate((PUNKNOWN *)&Miniport, PortClassId, NULL, NonPagedPool);
    if (!NT_SUCCESS(Status))
    {
        QCA_LOG("%S: miniport create failed 0x%08lx\n", Name, Status);
        RecordStartStep(Name[0] == L'W' ? L"Wave miniport create" : L"Topology miniport create", Status);
        Port->Release();
        return Status;
    }

    Status = Port->Init(DeviceObject, Irp, Miniport, NULL, ResourceList);
    if (!NT_SUCCESS(Status))
    {
        QCA_LOG("%S: port init failed 0x%08lx\n", Name, Status);
        RecordStartStep(Name[0] == L'W' ? L"Wave port init" : L"Topology port init", Status);
    }
    if (NT_SUCCESS(Status))
    {
        Status = PcRegisterSubdevice(DeviceObject, Name, Port);
        if (!NT_SUCCESS(Status))
        {
            QCA_LOG("%S: PcRegisterSubdevice failed 0x%08lx\n", Name, Status);
            RecordStartStep(Name[0] == L'W' ? L"Wave PcRegisterSubdevice" : L"Topology PcRegisterSubdevice", Status);
        }
        if (NT_SUCCESS(Status) && OutPortUnknown)
            Status = Port->QueryInterface(IID_IUnknown, (PVOID *)OutPortUnknown);
    }

    Miniport->Release();
    Port->Release();
    return Status;
}

static
NTSTATUS
NTAPI
StartDevice(PDEVICE_OBJECT DeviceObject, PIRP Irp, PRESOURCELIST ResourceList)
{
    PAGED_CODE();

    PUNKNOWN UnknownWave = NULL;
    PUNKNOWN UnknownTopology = NULL;
    NTSTATUS Status;

    RecordStartStep(L"Start", STATUS_PENDING);
    TelephonyInitialize();

    Status = InstallSubdevice(DeviceObject, Irp, L"Topology", CLSID_PortTopology,
                              CreateMiniportTopologyQcom, NULL, &UnknownTopology);
    if (!NT_SUCCESS(Status))
        return Status;

    Status = InstallSubdevice(DeviceObject, Irp, L"Wave", CLSID_PortWaveRT,
                              CreateMiniportWaveQcom, ResourceList, &UnknownWave);
    if (!NT_SUCCESS(Status))
    {
        UnknownTopology->Release();
        return Status;
    }

    Status = PcRegisterPhysicalConnection(DeviceObject, UnknownWave, PIN_WAVE_RENDER_SOURCE,
                                          UnknownTopology, PIN_TOPO_WAVE_IN);
    QCA_LOG("start: wave and topology connected 0x%08lx\n", Status);
    RecordStartStep(L"Physical connection", Status);

    UnknownTopology->Release();
    UnknownWave->Release();
    return Status;
}

extern "C"
NTSTATUS
NTAPI
AddDevice(PDRIVER_OBJECT DriverObject, PDEVICE_OBJECT PhysicalDeviceObject)
{
    PAGED_CODE();
    return PcAddAdapterDevice(DriverObject, PhysicalDeviceObject, StartDevice, MAX_MINIPORTS, 0);
}

extern "C"
NTSTATUS
NTAPI
DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPathName)
{
    PAGED_CODE();
    return PcInitializeAdapterDriver(DriverObject, RegistryPathName, AddDevice);
}

#ifdef _MSC_VER
#pragma code_seg()
#endif

int __cdecl _purecall(void)
{
    return 0;
}
