#ifndef YQ_NET_PROXY_H
#define YQ_NET_PROXY_H

#include <string>
#include <windows.h>
#include "RegCtrl.h";
#include "StrInt.h"

using std::string;

#define NET_PROXY_REGISTRY "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings"

bool SetNetProxy(string proxy_ip,int port)
{
	int ifopen=(proxy_ip.empty())?0:1;
	string dat=proxy_ip+":"+int2str(port);
	
	RegCtrl rc(NET_PROXY_REGISTRY,KEY_WRITE);
	if(!rc)
		return false;
	if(!rc.SetValue("ProxyEnable",ifopen,REG_DWORD))
		return false;
	if(ifopen == 1 && !rc.SetValue("ProxyServer",dat))
		return false;
	return true;
}

bool QueryNetProxy(string &proxy_ip,int &port)
{
	RegCtrl rc;
	string addr;
	int isopen;
	
	if(!rc.OpenKey(NET_PROXY_REGISTRY,KEY_QUERY_VALUE))
		return false;
	if(!rc.GetValue("ProxyEnable",&isopen,REG_SZ))
		return false;
	if(!isopen)
	{
		proxy_ip="";
		port=0;
		return false;
	}
	if(!rc.GetValue("ProxyServer",&addr,REG_SZ))
		return false;
	
	proxy_ip=adr.substr(0,addr.find(":"));
	port=str2int(addr.substr(addr.find(":")+1));
	return true;
}

#endif
