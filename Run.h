#pragma once

#include <string>
#include <windows.h>

#include "cstr.h"

using std::string;

bool Run(string filepath,string cmdpara="",bool hidden=false,
			HANDLE hPipeIn=0,HANDLE hPipeOut=0,
			HANDLE *hPro=0,HANDLE *hThr=0,
			SECURITY_ATTRIBUTES *sa=NULL)
{
	try{
		if(filepath.empty())
			return false;
		
		string cmdline="\""+filepath+"\" "+cmdpara;
		STARTUPINFO si={sizeof(si)};
		PROCESS_INFORMATION pi;
		
		si.wShowWindow=hidden?SW_HIDE:SW_SHOW;
		si.dwFlags=STARTF_USESHOWWINDOW;
		
		if(hPipeIn != 0)
		{
			si.dwFlags|=STARTF_USESTDHANDLES;
			si.hStdInput=hPipeIn;
		}
		if(hPipeOut != 0)
		{
			si.dwFlags|=STARTF_USESTDHANDLES;
			si.hStdOutput=hPipeOut;
			si.hStdError=hPipeOut;
		}
		
		if(CreateProcess(NULL,cstr(cmdline),sa,sa,(sa==NULL?false:true),CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi))
		{
			if(hPro == 0)
				CloseHandle(pi.hProcess);
			else
				*hPro=pi.hProcess;
			
			if(hThr == 0)
				CloseHandle(pi.hThread);
			else
				*hThr=pi.hThread;
			return true;
		}
		return false;
	}catch(...){
		return false;
	}
}
