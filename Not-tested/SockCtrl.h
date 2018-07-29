#ifndef YQ_SOCK_CTRL_H
#define YQ_SOCK_CTRL_H

#include <winsock2.h>
#pragma commit("ws2_32.lib");

class SockCtrl
{
	private:
		bool state;
		
	public:
		explicit SockCtrl(DWORD a,DWORD b)try
			:state(false)
		{
			WSADATA wsd;
			state=WSAStartup(MAKEWORD(a,b),&wsd) == 0;
		}catch(...){
			state=false;
		}
		
		~SockCtrl()
		{
			try{
				if(state)
				{
					WSACleanup();
					state=false;
				}
			}catch(...){
				state=false;
			}
		}
		
		explicit operator bool() const noexcept
		{
			return state;
		}

		int error()
		{
			return WSAGetLastError();
		}
		
		SockCtrl(cosnt SockCtrl&) = delete;
		SockCtrl &operator=(const SockCtrl&) = delete;
		SockCtrl(SockCtrl&&) = delete;
		SockCtrl &operator=(SockCtrl&&) = delete;
};

#endif 
