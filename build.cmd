@echo off
REM Builds the drivers into out\drivers\package and the setup utility into out\utility.
REM Usage: build.cmd [drivers|utility] [ninja targets]
setlocal
set VSCMD_ARG_no_logo=1
if not defined VSINSTALLDIR (
    call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" arm64 || exit /b 1
)
set "PATH=C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;C:\RosBE\bin;%PATH%"

set ROOT=%~dp0
set PART=%1
if "%PART%"=="drivers" shift
if "%PART%"=="utility" shift

if not "%PART%"=="utility" (
    if not exist "%ROOT%out\drivers\build.ninja" (
        cmake -G Ninja -S "%ROOT%Drivers" -B "%ROOT%out\drivers" -DCMAKE_BUILD_TYPE=Debug || exit /b 1
    )
    ninja -C "%ROOT%out\drivers" || exit /b 1

    REM The built drivers are the OnePlus 6 part of the board package beside this tree
    if exist "%ROOT%..\sdm845-Package\" (
        if exist "%ROOT%..\sdm845-Package\OnePlus6" rmdir /s /q "%ROOT%..\sdm845-Package\OnePlus6"
        xcopy /e /i /q /y "%ROOT%out\drivers\package" "%ROOT%..\sdm845-Package\OnePlus6" >nul || exit /b 1
    )
)

if not "%PART%"=="drivers" (
    if not exist "%ROOT%out\utility\build.ninja" (
        cmake -G Ninja -S "%ROOT%UtiltiySrc" -B "%ROOT%out\utility" -DCMAKE_BUILD_TYPE=Release || exit /b 1
    )
    ninja -C "%ROOT%out\utility" || exit /b 1
)
