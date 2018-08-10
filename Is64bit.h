#include <windows.h>

BOOL DoesWin32MethodExist(LPCSTR pszModuleName, PCSTR pszMethodName)
{
    HMODULE hModule = GetModuleHandle(pszModuleName);
    if (hModule == NULL)
    {
        return FALSE;
    }
    return (GetProcAddress(hModule, pszMethodName) != NULL);
}

bool Is64BitOS()
{
	#ifdef _WIN64
		return true;
	#else
		#ifdef _WIN32
    		HMODULE hModule = GetModuleHandle("kernel32.dll");
		    if (hModule == NULL)
		        return false;
		    else if(GetProcAddress(hModule,"IsWow64Process") == NULL)
		    	return false;
    		else
			{
				bool bIs64;
				return IsWow64Process(GetCurrentProcess(), (PBOOL)&bIs64) && bIs64;
        	}
		#else
    		return false;
    	#endif
	#endif
}


bool Is64BitProcess()
{
    if (!Is64BitOS())
        return false;
	else
        return sizeof(void*)*8 == 64;
}
