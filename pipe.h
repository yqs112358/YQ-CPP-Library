#pragma once

#include <windows.h>

class pipe
{
	private:
		HANDLE hRead,hWrite;
	public:
		pipe()try
			:hRead(0),hWrite(0)
		{
			SECURITY_ATTRIBUTES sa={sizeof(sa)};
			sa.lpSecurityDescriptor=NULL;
			sa.bInheritHandle=true;
			CreatePipe(&hRead,&hWrite,&sa,0);
		}
		catch(...)
		{
			hRead=hWrite=0;
		}
		
		~pipe()
		{
			CloseHandle(hRead);
			CloseHandle(hWrite);
		}
		
		HANDLE ReadHandle() const noexcept
		{
			return hRead;
		}
		
		HANDLE WriteHandle() const noexcept
		{
			return hWrite;
		}
		
		int Read(char *buf,int len)
		{
			try
			{
				DWORD res;
				if(!ReadFile(hRead,buf,len,&res,NULL))
					return 0;
				return res;
			}
			catch(...)
			{
				return 0;
			}
		}
		
		int Write(char *buf,int len)
		{
			try
			{
				DWORD res;
				if(!WriteFile(hWrite,buf,len,&res,NULL))
					return 0;
				return res;
			}
			catch(...)
			{
				return 0;
			}
		}
		
		explicit operator bool() const noexcept
		{
			return (hRead>0 && hWrite>0);
		}
};
