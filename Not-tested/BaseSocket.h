/****************************************************************************
* BaseSocket.h				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ����֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-18 
*
* ��������������� - ���� - ���� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� winsock2.h �� ws2_32.lib ��΢���׽��ֿ�ܣ� 
* 		3.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		4.������ Windowsƽ̨
****************************************************************************/

#ifndef YQ_BASE_SOCKET_H
#define YQ_BASE_SOCKET_H

#pragma comment(lib,"ws2_32.lib")

#include <winsock2.h>
#include <string>

using std::string;

class BaseSocket
{
private:
	SOCKET sock;
	sockaddr_in *addr;
	
	BaseSocket();

protected:
	void setSock(SOCKET s);
	SOCKET getSock();
	sockaddr* getAddr();
	
	visual ~BaseSocket();

public:
	void setIP(const string &ip);
	void setPort(unsigned int port);
	void set(const string &ip,unsigned int port);
	
	BaseSocket(const BaseSocket&) = delete;
	BaseSocket &operator=(const BaseSocket&) = delete;
	BaseSocket(BaseSocket &&s);
	BaseSocket &operator=(BaseSocket&&);		
};

#endif


