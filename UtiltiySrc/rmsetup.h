/*
 * PROJECT:     ReactOS Mobile Setup Utility
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Shared declarations of the servicing core both front ends use
 */

#pragma once

#define WIN32_LEAN_AND_MEAN
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/* Where the utility keeps its state inside a mounted image */
#define RMS_STATE_DIR       L"rmsetup"
#define RMS_REGISTRY_DIR    L"rmsetup\\registry"
#define RMS_ORDER_FILE      L"rmsetup\\registry\\ORDER"
#define RMS_IMAGE_INI       L"rmsetup\\image.ini"

/* Driver keys the utility hands out start here, clear of the ones the packages set */
#define RMS_FIRST_DRIVER_KEY    0x200

typedef struct _RMS_TEXT
{
    PWSTR Buffer;
    SIZE_T Length;
    SIZE_T Capacity;
} RMS_TEXT, *PRMS_TEXT;

/* Where the core reports progress, both front ends point it at their own output */
typedef VOID (*RMS_LOG_ROUTINE)(_In_ BOOL Error, _In_z_ PCWSTR Message);
extern RMS_LOG_ROUTINE RmsLogRoutine;

/* What to install of a driver INF */
typedef struct _RMS_DRIVER_OPTIONS
{
    /* Hardware ids to install for, none for every id the INF models */
    PCWSTR *Devices;
    ULONG DeviceCount;

    /* Device instance paths, like ACPI\QCOM0264\_SB_PMBT, that get Enum keys ahead of enumeration */
    PCWSTR *Instances;
    ULONG InstanceCount;

    /* Start the device's service at boot whatever the INF says */
    BOOL BootStart;

    /* The driver key under the class to use, 0 for the next free one */
    ULONG DriverKey;

    /* Only describe what would be installed, into Summary */
    BOOL DryRun;
    PRMS_TEXT Summary;
} RMS_DRIVER_OPTIONS, *PRMS_DRIVER_OPTIONS;

/* The answer to "install this one?" when a folder of drivers is added */
typedef enum _RMS_CHOICE
{
    RmsChoiceInstall,
    RmsChoiceBootStart,
    RmsChoiceSkip,
    RmsChoiceInstallAll,
    RmsChoiceCancel
} RMS_CHOICE;

typedef RMS_CHOICE (*RMS_PROMPT_ROUTINE)(_In_z_ PCWSTR InfPath, _In_z_ PCWSTR Summary, _In_opt_ PVOID Context);

/* A service of the image's SYSTEM hive */
typedef struct _RMS_SERVICE
{
    WCHAR Name[128];
    WCHAR DisplayName[256];
    WCHAR Group[128];
    WCHAR ImagePath[260];
    ULONG Start;
    ULONG Type;
    BOOL Present;   /* the image file is on the media */
} RMS_SERVICE, *PRMS_SERVICE;

typedef VOID (*RMS_SERVICE_ROUTINE)(_In_ const RMS_SERVICE *Service, _In_opt_ PVOID Context);

/* util.c */
VOID RmsError(_In_z_ _Printf_format_string_ PCWSTR Format, ...);
VOID RmsInfo(_In_z_ _Printf_format_string_ PCWSTR Format, ...);
PWSTR RmsJoin(_In_z_ PCWSTR First, _In_z_ PCWSTR Second);
BOOL RmsMakeDirectories(_In_z_ PCWSTR Path);
BOOL RmsCopyFileTo(_In_z_ PCWSTR Source, _In_z_ PCWSTR Destination);
BOOL RmsCopyTree(_In_z_ PCWSTR Source, _In_z_ PCWSTR Destination);
BOOL RmsDirectoryExists(_In_z_ PCWSTR Path);
BOOL RmsFileExists(_In_z_ PCWSTR Path);
BOOL RmsDirectoryEmpty(_In_z_ PCWSTR Path);
PWSTR RmsReadText(_In_z_ PCWSTR Path);
BOOL RmsWriteText(_In_z_ PCWSTR Path, _In_z_ PCWSTR Text);
BOOL RmsAppendLine(_In_z_ PCWSTR Path, _In_z_ PCWSTR Line);
BOOL RmsRun(_In_z_ PCWSTR CommandLine);
PCWSTR RmsToolPath(_In_z_ PCWSTR Tool);
VOID RmsTextAppend(_Inout_ PRMS_TEXT Text, _In_z_ PCWSTR String);
VOID RmsTextAppendF(_Inout_ PRMS_TEXT Text, _In_z_ _Printf_format_string_ PCWSTR Format, ...);
VOID RmsTextFree(_Inout_ PRMS_TEXT Text);

/* iso.c */
BOOL RmsExtractIso(_In_z_ PCWSTR ImageFile, _In_z_ PCWSTR Directory,
                   _Out_writes_z_(VolumeSize) PWSTR VolumeId, _In_ SIZE_T VolumeSize);

/* hive.c */
BOOL RmsEnumServices(_In_z_ PCWSTR HivePath, _In_opt_z_ PCWSTR MountDir,
                     _In_ RMS_SERVICE_ROUTINE Routine, _In_opt_ PVOID Context);

/* driver.c */
BOOL RmsTranslateDriver(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR InfPath,
                        _In_ const RMS_DRIVER_OPTIONS *Options, _Inout_ PULONG NextDriverKey);

/* image.c */
int RmsMountImage(_In_z_ PCWSTR ImageFile, _In_z_ PCWSTR MountDir);
int RmsAddPackage(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR PackagePath);
int RmsAddRegistry(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR InfPath);
int RmsAddDriver(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR DriverPath, _In_ BOOL Recurse,
                 _In_ const RMS_DRIVER_OPTIONS *Options,
                 _In_opt_ RMS_PROMPT_ROUTINE Prompt, _In_opt_ PVOID PromptContext);
int RmsAddFirmware(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR Source, _In_opt_z_ PCWSTR Destination);
int RmsAddOverlay(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR Overlay);
int RmsGetDrivers(_In_z_ PCWSTR MountDir);
int RmsListServices(_In_z_ PCWSTR MountDir, _In_ RMS_SERVICE_ROUTINE Routine, _In_opt_ PVOID Context);
int RmsCommitImage(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR ImageFile);
BOOL RmsIsMounted(_In_z_ PCWSTR MountDir);
BOOL RmsStageSystemFile(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR Source, _In_z_ PCWSTR RelativeDir, _In_opt_z_ PCWSTR TargetName);
BOOL RmsRegisterInf(_In_z_ PCWSTR MountDir, _In_z_ PCWSTR Name, _In_opt_z_ PCWSTR SourcePath, _In_opt_z_ PCWSTR Text);
