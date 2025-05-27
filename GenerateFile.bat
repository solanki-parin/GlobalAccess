@echo off
setlocal ENABLEDELAYEDEXPANSION
cls

echo ==================================================
echo             Unreal Project Launcher
echo ==================================================

:: === Step 1: Find the .uproject file ===
set "UPROJECT_FILE="
for %%f in (*.uproject) do (
    set "UPROJECT_FILE=%%f"
    goto :found_uproject
)

echo [ERROR] No .uproject file found in this folder.
exit /b 1

:found_uproject
echo [INFO] Found project: %UPROJECT_FILE%

:: === Step 2: Extract project name ===
for %%f in ("%UPROJECT_FILE%") do set "PROJECT_NAME=%%~nf"
echo [INFO] Project name: %PROJECT_NAME%

:: === Step 3: Extract EngineAssociation version ===
set "ENGINE_VERSION="
for /f "tokens=2 delims=:" %%a in ('findstr /c:"EngineAssociation" "%UPROJECT_FILE%"') do (
    set "ENGINE_VERSION=%%a"
)

:: === Step 4: Cleanup engine version (remove quotes, commas, and whitespace) ===
set "ENGINE_VERSION=%ENGINE_VERSION:"=%"
set "ENGINE_VERSION=%ENGINE_VERSION:,=%"
for /f "tokens=* delims= " %%G in ("%ENGINE_VERSION%") do set "ENGINE_VERSION=%%G"
echo [INFO] Engine version: %ENGINE_VERSION%

:: === Step 5: Lookup Engine path from Windows Registry ===
set "UE_PATH="
for /f "tokens=3*" %%A in ('reg query "HKLM\SOFTWARE\EpicGames\Unreal Engine\%ENGINE_VERSION%" /v InstalledDirectory 2^>nul') do (
    set "UE_PATH=%%A %%B"
)

if not defined UE_PATH (
    echo [ERROR] Could not find engine version %ENGINE_VERSION% in registry.
    echo        Make sure it is installed via the Epic Games Launcher.
    exit /b 1
)

:: === Remove any trailing spaces from the UE_PATH ===
set "UE_PATH=!UE_PATH: =!"

echo [INFO] Unreal Engine path: !UE_PATH!
echo.

:: === Step 6: Regenerate project files if Source folder exists ===
if exist "Source\" (
    echo [INFO] Source folder found. Regenerating project files...

    if exist "%PROJECT_NAME%.sln" (
        echo [INFO] Deleting existing solution file...
        del "%PROJECT_NAME%.sln"
    )

    echo.
    echo [CMD] Running UnrealBuildTool...
    set "UNREALBUILDTOOL=!UE_PATH!\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"
    
    if exist "!UNREALBUILDTOOL!" (
        echo [INFO] Found UnrealBuildTool.exe: !UNREALBUILDTOOL!
        echo --------------------------------------------------
        "!UNREALBUILDTOOL!" -projectfiles -project="%cd%\%UPROJECT_FILE%" -game -engine -progress
        echo --------------------------------------------------
    ) else (
        echo [ERROR] UnrealBuildTool.exe not found in path: !UNREALBUILDTOOL!
        exit /b 1
    )

    if %ERRORLEVEL% NEQ 0 (
        echo [ERROR] Failed to generate project files.
        exit /b %ERRORLEVEL%
    )

    echo [SUCCESS] Project files generated.

    :: === Open the .sln file in Visual Studio ===
    echo [INFO] Opening solution in Visual Studio...
    start "" "%cd%\%PROJECT_NAME%.sln"
) else (
    echo [INFO] No Source folder found. Skipping project generation.

    :: === Step 7: Launch Unreal Editor ===
    echo.
    echo [CMD] Launching Unreal Editor...
    echo --------------------------------------------------
    start "" "%UE_PATH%\Engine\Binaries\Win64\UnrealEditor.exe" "%cd%\%UPROJECT_FILE%"
    echo --------------------------------------------------
    echo [INFO] Editor launched.
)

endlocal
exit /b 0
