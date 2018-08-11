#pragma once

#include <string>
#include "SockCtrl.h"

using std::string;

string GetLocalAddr(SOCKET s,int *port=nullptr)
{
	try{
		int len=sizeof(sockaddr_in);
		sockaddr_in sa;
		if(s == SOCKET_ERROR)
			return "";
		if(getsockname(s,(sockaddr*)&sa,&len) == 0)
		{
			if(port)
				*port=ntohs(sa.sin_port);
			return string(inet_ntoa(sa.sin_addr));
		}
		else
			return "";
	}catch(...)
	{
		return "";
	}
}

string GetRemoteAddr(SOCKET s,int *port=nullptr)
{
	try{
		int len=sizeof(sockaddr_in);
		sockaddr_in sa;
		if(s == SOCKET_ERROR)
			return "";
		if(getpeername(s,(sockaddr*)&sa,&len) == 0)
		{
			if(port)
				*port=ntohs(sa.sin_port);
			return string(inet_ntoa(sa.sin_addr));
		}
		else
			return "";
	}catch(...)
	{
		return "";
	}
}
