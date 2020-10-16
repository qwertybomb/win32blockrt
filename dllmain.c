#include "runtime.c"

__declspec(noinline) int __stdcall _DllMainCRTStartup(HMODULE unused1, DWORD unused2, LPVOID unused3)
{
	(void)unused1, (void)unused2, (void)unused3;
    return 1;
}
