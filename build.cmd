@echo off
REM Builds the drivers into out\drivers\package and the setup utility into out\utility.
REM Usage: build.cmd [drivers|utility] [ninja targets]
REM The drivers always target arm64, the utility is built for the machine running this.
setlocal
set VSCMD_ARG_no_logo=1
set "VCVARSALL=C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat"
set "PATH=C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;C:\RosBE\bin;%PATH%"

set HOST=x64
if /i "%PROCESSOR_ARCHITECTURE%"=="ARM64" set HOST=arm64
if /i "%PROCESSOR_ARCHITEW6432%"=="ARM64" set HOST=arm64

set ROOT=%~dp0
set PART=%1
if "%PART%"=="drivers" shift
if "%PART%"=="utility" shift

if not "%PART%"=="utility" (
    call :drivers || exit /b 1
)
if not "%PART%"=="drivers" (
    call :utility || exit /b 1
)
exit /b 0

:drivers
setlocal
if /i not "%VSCMD_ARG_TGT_ARCH%"=="arm64" (
    if "%HOST%"=="arm64" (
        call "%VCVARSALL%" arm64 || exit /b 1
    ) else (
        call "%VCVARSALL%" x64_arm64 || exit /b 1
    )
)
if not exist "%ROOT%out\drivers\build.ninja" (
    cmake -G Ninja -S "%ROOT%Drivers" -B "%ROOT%out\drivers" -DCMAKE_BUILD_TYPE=Debug || exit /b 1
)
ninja -C "%ROOT%out\drivers" || exit /b 1

REM The built drivers are the OnePlus 6 part of the board package beside this tree
if exist "%ROOT%..\sdm845-Package\" (
    if exist "%ROOT%..\sdm845-Package\OnePlus6" rmdir /s /q "%ROOT%..\sdm845-Package\OnePlus6"
    xcopy /e /i /q /y "%ROOT%out\drivers\package" "%ROOT%..\sdm845-Package\OnePlus6" >nul || exit /b 1
)
exit /b 0

:utility
setlocal
if /i not "%VSCMD_ARG_TGT_ARCH%"=="%HOST%" (
    call "%VCVARSALL%" %HOST% || exit /b 1
)
if not exist "%ROOT%out\utility\build.ninja" (
    cmake -G Ninja -S "%ROOT%UtiltiySrc" -B "%ROOT%out\utility" -DCMAKE_BUILD_TYPE=Release || exit /b 1
)
ninja -C "%ROOT%out\utility" || exit /b 1
exit /b 0
