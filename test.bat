@echo off

pushd %~dp0
IF NOT EXIST build_m64 (.\build.bat)
cd build_m64

clang-cl -fblocks -m64 ..\test\test.c /link blockrt.lib /out:..\test\test.exe && ..\test\test.exe

popd
