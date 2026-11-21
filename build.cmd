@echo off
REM Builds the drivers into out\drivers\package with the ARM64 MSVC toolchain.
REM Usage: build.cmd [ninja targets]
setlocal
set VSCMD_ARG_no_logo=1
if not defined VSINSTALLDIR (
    call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" arm64 || exit /b 1
)
set "PATH=C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;C:\RosBE\bin;%PATH%"

set ROOT=%~dp0
if not exist "%ROOT%out\drivers\build.ninja" (
    cmake -G Ninja -S "%ROOT%Drivers" -B "%ROOT%out\drivers" -DCMAKE_BUILD_TYPE=Debug || exit /b 1
)
ninja -C "%ROOT%out\drivers" %*
