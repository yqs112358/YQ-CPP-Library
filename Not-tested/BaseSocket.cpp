/****************************************************************************
* BaseSocket.cpp				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-18 
*
* 简述：网络操作类 - 基类 - 实现 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 BaseSocket.h 		-- YQ-CPP-Libraries
* 		3.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		4.仅用于 Windows平台
****************************************************************************/

#include "BaseSocket.h"

void BaseSocket::setIP(const string &ip)
{
	(addr->sin_addr).S_un.S_addr=inet_addr(ip.c_str());
}

void BaseSocket::setPort(unsigned int port)
{
	addr->sin_port=htons((unsigned short)port);
}

BaseSocket::BaseSocket()
{
	addr=new sockaddr_in;
	addr->sin_family=AF_INET;
}

BaseSocket::~BaseSocket()
{
	if(addr)
		delete addr;
}

BaseSocket::BaseSocket(BaseSocket &&s)
{
	addr=s.addr;
	s.addr=NULL;
}

BaseSocket& operator=(BaseSocket &&s)
{
	if(this != &s)

void BaseSocket::setSock(SOCKET s)
{
	sock=s;
}

void BaseSocket::set(const string &ip,unsigned int port)
{
	setIP(ip);
	setPort(port);
}

SOCKET BaseSocket::getSock()
{
	return sock;
}

sockaddr* BaseSocket::getAddr()
{
	return (sockaddr*)addr;
}