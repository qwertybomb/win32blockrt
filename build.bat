@echo off

set name=blockrt

REM by default arch will be x64
if "%1"=="" (
	set arch="m64"
	call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
	goto success
)

if "%1"=="x86" (
	set arch="m32"
	call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
	goto success
)

if "%1"=="x64" (
	set arch="m64"
 	call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
 	goto success
)

REM if the argument is invaild or unknown
echo Unknown argument
goto exit
	
:success

REM setup and go to build dir
set build_dir=build_%arch%
IF NOT EXIST %build_dir% (mkdir %build_dir%)
pushd %~dp0
cd %build_dir%

REM compile code
clang-cl /LD -%arch% /nologo /Oi /O2 /W4 /GS- /Gs9999999 ..\dllmain.c /link /stack:0x100000,0x100000 /nodefaultlib kernel32.lib user32.lib shell32.lib /subsystem:windows /out:%name%.dll /implib:%name%.lib

popd
:exit
EXIT 0
