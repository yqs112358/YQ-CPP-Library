#ifndef YQ_TASK_KILL
#define YQ_TASK_KILL

#include <windows.h>
#include <tlhelp32.h>
#include <cstring>

bool TaskKill(const char *proName)
{	
	HANDLE hSnapshot,hPro;
	bool isDone=false;
	hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if(hSnapshot == NULL)
		return false;
	
	PROCESSENTRY32 pe={sizeof(pe)};
	bool next=Process32First(hSnapshot,&pe);
	while(next)
	{
		if(strcmp(proName,pe.szExeFile) == 0)
		{
			hPro=OpenProcess(PROCESS_TERMINATE,FALSE,pe.th32ProcessID);
			if(hPro != NULL)
			{
				TerminateProcess(hPro,-1);
				isDone=true;
				CloseHandle(hPro);
			}
		}
		next=Process32Next(hSnapshot,&pe);
	}
	
	CloseHandle(hSnapshot);
	return isDone;
}

#endif
