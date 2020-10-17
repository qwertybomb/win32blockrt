@echo off

pushd %~dp0
start .\build.bat x64
cd build_m64

clang-cl -fblocks -m64 /I..\include\ ..\test\test.c /link blockrt.lib /out:..\test\test.exe && ..\test\test.exe

popd
