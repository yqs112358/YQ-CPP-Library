#ifndef YQ_TASKKILL
#define YQ_TASKKILL

#include <windows.h>
#include <string>
#include <tlhelp32.h>

using std::string;

bool TaskKill(const string pro_name)
{
	if(pro_name.empty())
		return false;
		
	HANDLE hSnapshot,hPro;
	bool done=false;
	hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if(hSnapshot <=0)
		return false;
	
	PROCESSENTRY32 pe={sizeof(pe)};
	bool next=Process32First(hSnapshot,&pe);
	while(next)
	{
		if(pro_name == string(pe.szExeFile))
		{
			//                            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			hPro=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pe.th32ProcessID);
			if(hPro>0)
			{
				TerminateProcess(hPro,-1);
				done=true;
				CloseHandle(hPro);
			}
		}
		next=Process32Next(hSnapshot,&pe);
	}
	
	CloseHandle(hSnapshot);
	return done;
}

#endif
