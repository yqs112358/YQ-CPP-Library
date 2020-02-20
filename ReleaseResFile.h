  
#ifndef YQ_RELEASE_RES_FILE_H
#define YQ_RELEASE_RES_FILE_H

#include <windows.h>

BOOL ReleaseResFile(DWORD dwResName, LPCSTR lpResType, LPCSTR lpFilePathName )  
{     
    HMODULE hInstance = ::GetModuleHandle(NULL);
            
    HRSRC hResID = ::FindResource(hInstance,MAKEINTRESOURCE(dwResName),lpResType);
    HGLOBAL hRes = ::LoadResource(hInstance,hResID);
    LPVOID pRes = ::LockResource(hRes);
            
    if (pRes == NULL)
    {  
        return FALSE;  
    }  
    DWORD dwResSize = ::SizeofResource(hInstance,hResID); 
    HANDLE hResFile = CreateFile(lpFilePathName,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL); 
            
    if (INVALID_HANDLE_VALUE == hResFile)  
    {  
        return FALSE;  
    }  
        
    DWORD dwWritten = 0;   
    WriteFile(hResFile,pRes,dwResSize,&dwWritten,NULL);
    CloseHandle(hResFile);
            
    return (dwResSize == dwWritten);
}

#endif
