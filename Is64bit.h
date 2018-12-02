#include <windows.h>

bool Is64bitOS()
{
	typedef BOOL (WINAPI *HWOW64)(HANDLE,PBOOL);
	
	HMODULE hModule = GetModuleHandle("kernel32.dll");
	HWOW64 hwow64 =NULL;
	
    if (hModule == NULL)
        return false;
    else if((hwow64=(HWOW64)GetProcAddress(hModule,"IsWow64Process")) == NULL)
    	return false;
	else
		return true;
}


bool Is64bitProcess()
{
    if (!Is64bitOS())
        return false;
	else
        return sizeof(void*)*8 == 64;
}
