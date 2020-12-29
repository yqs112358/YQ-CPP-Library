/****************************************************************************
* TCPServer.h				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ����֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-18 
*
* ��������������� - ������� - ���� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� winsock2.h �� ws2_32.lib ��΢���׽��ֿ�ܣ� 
*		3.���� BaseSocket.h 		-- YQ-CPP-Libraries
*		4.���� TCPSocket.h 			-- YQ-CPP-Libraries
* 		5.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		6.������ Windowsƽ̨
****************************************************************************/

#ifndef YQ_TCP_SERVER_H
#define YQ_TCP_SERVER_H

#include "BaseSocket.h"
#include "TCPSocket.h"

class TCPServer : public BaseSocket
{
private:
	bool conn;

protected:
	using BaseSocket::setIP(const string &ip);
	using BaseSocket::set(const string &ip,unsigned int port);
	
	void init();
	void setConn(bool isconn);
	
public:
	TCPSocket();
	~TCPSocket();
	
	void close();
	bool listen(unsigned int port,unsigned int max_conn=256);
	TCPSocket accept();
	bool is_conn();
	
	explicit operator bool() const
	{
		return is_conn();
	}
};

#endif 
