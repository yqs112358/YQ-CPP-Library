/****************************************************************************
* BaseSocket.cpp				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ���֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-18 
*
* ��������������� - ���� - ʵ�� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� BaseSocket.h 		-- YQ-CPP-Libraries
* 		3.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		4.������ Windowsƽ̨
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


