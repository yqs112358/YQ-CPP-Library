/****************************************************************************
* TCPSocket.h				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ����֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-19 
*
* ��������������� - ͨ���� - ���� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� winsock2.h �� ws2_32.lib ��΢���׽��ֿ�ܣ� 
*		3.���� BaseSocket.h 		-- YQ-CPP-Libraries
* 		4.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		5.������ Windowsƽ̨
****************************************************************************/

#ifndef YQ_TCP_SOCKET_H
#define YQ_TCP_SOCKET_H

#include <string>
#include <cstddef>
#include "BaseSocket.h"

using std::string;

class TCPSocket : private BaseSocket
{
	friend TCPSocket TCPServer::accept();
	
private:
	bool conn;
	TCPSocket(SOCKET s,bool is_ok=true);

protected:
	using BaseSocket::getSock();
	using BaseSocket::getAddr();
	
	void setConn(bool isconn);

public:
	visual ~TCPSocket();
	void close();
	bool is_conn();
	
	string getRemoteAddr(unsigned int *port=nullptr);
	string getLocalAddr(unsigned int *port=nullptr);
	
	bool send(const char *data,size_t size);
	bool send(const string &data,bool is_text=true);
	bool recv(char *buf,size_t size,bool peek=false);
	bool recv(string *buf,string::size_type size,bool is_text=true,bool peek=false);
	
	explicit operator bool() const
	{
		return is_conn();
	}
};

#endif 
