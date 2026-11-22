# ReactOS Mobile SDK
#
# Builds drivers and libraries out of the ReactOS tree with the headers and import
# libraries taken from a ReactOS build. It provides the ReactOS build macros the
# driver CMakeLists use (set_module_type, spec2def, add_importlibs, add_cd_file,
# add_registry_inf, ...), so a driver moves between the trees unchanged.
#
# Everything a driver installs lands in a package directory laid out like the boot
# media, with its registry INFs beside it, ready for the setup utility.

if(NOT MSVC)
    message(FATAL_ERROR "The ReactOS Mobile SDK builds with MSVC for ARM64")
endif()

get_filename_component(RMSDK_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
set(RMSDK_INCLUDE "${RMSDK_ROOT}/include")
set(RMSDK_LIB "${RMSDK_ROOT}/lib/arm64")

if(NOT RMSDK_PACKAGE_DIR)
    set(RMSDK_PACKAGE_DIR "${CMAKE_BINARY_DIR}/package")
endif()
set(RMSDK_IMPLIB_DIR "${CMAKE_BINARY_DIR}/implib")
file(MAKE_DIRECTORY "${RMSDK_PACKAGE_DIR}" "${RMSDK_IMPLIB_DIR}")

# Same target and defaults the ReactOS ARM64 debug build compiles with
add_definitions(
    -D__REACTOS__ -DDBG=1 -D_ARM64_ -D_M_ARM64 -D_WIN64 -D__aarch64__ -D__arm64__
    -D_WIN32_WINNT=0x502 -DWINVER=0x502 -D_WIN32_IE=0x603 -D_WIN32_WINDOWS=0x502
    -D_SETUPAPI_VER=0x502 -DDLL_EXPORT_VERSION=0xA00
    -DVER_PRODUCTVERSION_W=0xA00 -DVER_USE_OTHER_MAJOR_MINOR_VER
    -DMINGW_HAS_SECURE_API=1 -DUSE_COMPILER_EXCEPTIONS -D_NEW_DELETE_OPERATORS_
    -D_SEH_ENABLE_TRACE -D__RUNTIME_CHECKS__ -D__STDC__=1
    -D__RELFILE__=__FILE__)

include_directories(
    ${RMSDK_INCLUDE}
    ${RMSDK_INCLUDE}/crt
    ${RMSDK_INCLUDE}/ddk
    ${RMSDK_INCLUDE}/ndk
    ${RMSDK_INCLUDE}/psdk
    ${RMSDK_INCLUDE}/reactos
    ${RMSDK_INCLUDE}/reactos/libs
    ${RMSDK_INCLUDE}/vcruntime
    ${RMSDK_INCLUDE}/generated
    ${RMSDK_INCLUDE}/generated/psdk
    ${RMSDK_INCLUDE}/generated/ddk
    ${RMSDK_INCLUDE}/generated/reactos
    ${RMSDK_INCLUDE}/generated/reactos/mc
    ${RMSDK_INCLUDE}/pseh)

set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_DEBUG "")
add_compile_options(
    /Ob0 /Od /GF /Gy /X /Zl /GS- /FS /Zc:threadSafeInit- /forceInterlockedFunctions-
    /W3 /wd4819 /wd4244 /wd4290 /wd4800 /wd4200 /wd4214 /wd4018
    /we4013 /we4020 /we4022 /we4028 /we4047 /we4090 /we4098 /we4113 /we4129 /we4133
    /we4163 /we4229 /we4311 /we4312 /we4313 /we4477 /we4603 /we4700 /we4715 /we4716
    /we4101 /we4189 /w14115 /Zi /RTC1
    $<$<COMPILE_LANGUAGE:CXX>:/Zc:__cplusplus>
    $<$<COMPILE_LANGUAGE:CXX>:/GR->
    $<$<COMPILE_LANGUAGE:CXX>:/EHs-c->)
set(CMAKE_CXX_FLAGS "")

set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "")
set(CMAKE_MODULE_LINKER_FLAGS
    "/machine:ARM64 /debug /OPT:REF /OPT:ICF /MANIFEST:NO /INCREMENTAL:NO /SAFESEH:NO /NODEFAULTLIB /RELEASE /IGNORE:4039 /VERSION:5.01")

# Libraries the SDK ships, linked by their ReactOS names
foreach(_lib runtmchk libcntpr ntoskrnl_vista pseh stdunk uuid wdfdriverentry msvcrtex)
    add_library(${_lib} STATIC IMPORTED GLOBAL)
    set_target_properties(${_lib} PROPERTIES IMPORTED_LOCATION "${RMSDK_LIB}/${_lib}.lib")
endforeach()
set(PSEH_LIB pseh)

# The ReactOS build generates these headers, the SDK already carries them
add_custom_target(bugcodes)
add_custom_target(xdk)

set(RMSDK_KERNEL_TYPES kernelmodedriver kmdfdriver wdmdriver kerneldll)

# spec2def(<module file name> <spec> [ADD_IMPORTLIB]): exports to a .def beside the build
function(spec2def _dllname _spec_file)
    get_filename_component(_name ${_dllname} NAME_WE)
    file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/${_spec_file}" _lines)
    set(_def "LIBRARY ${_dllname}\nEXPORTS\n")
    foreach(_line ${_lines})
        if(_line MATCHES "^@[ \t]+[a-z]+[ \t]+(-[^ \t]+[ \t]+)*([A-Za-z_][A-Za-z0-9_@]*)")
            string(APPEND _def "    ${CMAKE_MATCH_2}\n")
        endif()
    endforeach()
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${_name}.def" "${_def}")
endfunction()

# set_module_type(<target> <type> [UNICODE] [ENTRYPOINT <name>])
function(set_module_type _module _type)
    cmake_parse_arguments(_arg "UNICODE" "ENTRYPOINT;IMAGEBASE" "" ${ARGN})

    set_property(TARGET ${_module} PROPERTY RMSDK_TYPE ${_type})
    target_link_options(${_module} PRIVATE "/IMPLIB:${RMSDK_IMPLIB_DIR}/lib${_module}.lib")

    if(_arg_UNICODE)
        target_compile_definitions(${_module} PRIVATE UNICODE _UNICODE)
    endif()

    if(_type IN_LIST RMSDK_KERNEL_TYPES)
        set_target_properties(${_module} PROPERTIES SUFFIX ".sys")
        target_link_options(${_module} PRIVATE /SUBSYSTEM:NATIVE,6.02 /BASE:0x140000000 /SECTION:INIT,ERWD)
        if(_type STREQUAL kernelmodedriver)
            target_link_options(${_module} PRIVATE /DRIVER)
        elseif(_type STREQUAL wdmdriver)
            target_link_options(${_module} PRIVATE /DRIVER:WDM)
        endif()

        if(_type STREQUAL kmdfdriver)
            set(_entry FxDriverEntry)
            target_include_directories(${_module} PRIVATE ${RMSDK_INCLUDE}/wdf/kmdf/1.31)
            target_compile_definitions(${_module} PRIVATE WDF_DEVICE_NO_WDMSEC_H)
            target_link_libraries(${_module} wdfdriverentry)
            add_importlibs(${_module} wdfldr)
        else()
            set(_entry DriverEntry)
        endif()
    elseif(_type STREQUAL win32dll)
        set(_entry DllMainCRTStartup)
        target_link_options(${_module} PRIVATE /DLL)
        target_compile_definitions(${_module} PRIVATE _DLL __USE_CRTIMP)
        target_link_libraries(${_module} msvcrtex)
    else()
        message(FATAL_ERROR "Module type ${_type} is not supported by the SDK")
    endif()

    if(_arg_ENTRYPOINT)
        set(_entry ${_arg_ENTRYPOINT})
    endif()
    target_link_options(${_module} PRIVATE /ENTRY:${_entry})
    target_link_libraries(${_module} runtmchk)
endfunction()

# add_importlibs(<target> <module>...): a module of this tree or one the SDK has an import library for
function(add_importlibs _module)
    foreach(_lib ${ARGN})
        if(TARGET ${_lib})
            # The import library comes out of that module's link, ninja only sees the ordering
            add_dependencies(${_module} ${_lib})
            target_link_options(${_module} PRIVATE "${RMSDK_IMPLIB_DIR}/lib${_lib}.lib")
        elseif(EXISTS "${RMSDK_LIB}/lib${_lib}.lib")
            target_link_libraries(${_module} "${RMSDK_LIB}/lib${_lib}.lib")
        else()
            message(FATAL_ERROR "${_module} imports ${_lib}, which is neither built here nor in the SDK")
        endif()
    endforeach()
endfunction()

# Precompiled headers only speed up the ReactOS build, the sources do not need them
function(add_pch)
endfunction()

# add_cd_file(TARGET <t> | FILE <f>... DESTINATION <path on the boot media> ...): stage into the package
function(add_cd_file)
    cmake_parse_arguments(_arg "NO_CAB" "TARGET;DESTINATION;NAME_ON_CD" "FILE;FOR" ${ARGN})
    if(NOT _arg_DESTINATION)
        message(FATAL_ERROR "add_cd_file needs a DESTINATION")
    endif()

    set(_dest "${RMSDK_PACKAGE_DIR}/${_arg_DESTINATION}")
    file(MAKE_DIRECTORY "${_dest}")

    if(_arg_TARGET AND NOT _arg_FILE)
        add_custom_command(TARGET ${_arg_TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:${_arg_TARGET}>" "${_dest}/"
            VERBATIM)
    else()
        foreach(_file ${_arg_FILE})
            if(NOT IS_ABSOLUTE ${_file})
                set(_file "${CMAKE_CURRENT_SOURCE_DIR}/${_file}")
            endif()
            file(COPY "${_file}" DESTINATION "${_dest}")
        endforeach()
    endif()
endfunction()

# Registry INFs go into the package for the setup utility to merge into the hives.
# ORDER lists them as they were added, later files win where they set the same value.
file(MAKE_DIRECTORY "${RMSDK_PACKAGE_DIR}/registry")
file(WRITE "${RMSDK_PACKAGE_DIR}/registry/ORDER" "")

function(add_registry_inf)
    foreach(_file ${ARGN})
        get_filename_component(_name ${_file} NAME)
        file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/${_file}" DESTINATION "${RMSDK_PACKAGE_DIR}/registry")
        file(APPEND "${RMSDK_PACKAGE_DIR}/registry/ORDER" "${_name}\n")
    endforeach()
endfunction()

# Driver INFs travel with the package, the utility installs from them
function(add_driver_inf _module)
    file(MAKE_DIRECTORY "${RMSDK_PACKAGE_DIR}/inf")
    foreach(_file ${ARGN})
        file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/${_file}" DESTINATION "${RMSDK_PACKAGE_DIR}/inf")
    endforeach()
endfunction()
