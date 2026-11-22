cmake_minimum_required(VERSION 3.20)
project(ReactOSMobileSetupUtility C RC)

# Built for the machine it runs on, the ReactOS host tools ship beside it
add_compile_definitions(UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)
if(MSVC)
    add_compile_options(/W4 /wd4100 /wd4201)
endif()

add_library(rmscore STATIC
    util.c
    iso.c
    hive.c
    driver.c
    image.c
    rmsetup.h)

add_executable(rmsetup cli.c)
target_link_libraries(rmsetup rmscore)

add_executable(rmsetupgui WIN32 gui.c rmsetupgui.rc)
target_link_libraries(rmsetupgui rmscore comctl32 comdlg32 shell32 ole32)
target_link_options(rmsetupgui PRIVATE /ENTRY:wWinMainCRTStartup /MANIFEST:NO)

# The host tools the commit step runs, built for the same machine as the utility
if(CMAKE_C_COMPILER_ARCHITECTURE_ID MATCHES "^(ARM64|arm64)$")
    set(_tools_arch arm64)
elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID MATCHES "^(x64|X64|AMD64|x86_64)$")
    set(_tools_arch x64)
else()
    message(FATAL_ERROR "No host tools for ${CMAKE_C_COMPILER_ARCHITECTURE_ID}, add them under tools/")
endif()
file(GLOB _tools "${CMAKE_CURRENT_SOURCE_DIR}/tools/${_tools_arch}/*.exe")
foreach(_target rmsetup rmsetupgui)
    add_custom_command(TARGET ${_target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${_target}>/tools"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${_tools} "$<TARGET_FILE_DIR:${_target}>/tools/"
        VERBATIM)
endforeach()
