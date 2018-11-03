/****************************************************************************
* TCPServer.cpp				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ���֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-18 
*
* ��������������� - ������� - ʵ�� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� TCPServer.h 		-- YQ-CPP-Libraries
* 		3.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		4.������ Windowsƽ̨
****************************************************************************/

#include "TCPServer.h"

TCPServer::TCPServer()
{
	setIP("127.0.0.1");
	setConn(false);
}

TCPServer::~TCPServer()
{
	close();
}

void TCPServer::init()
{
	setSock(SOCKET(AF_INET,SOCK_STREAM,0));
}

bool TCPServer::is_conn()
{
	return conn;
}

void TCPServer::setConn(bool isconn)
{
	conn=isconn;
}

bool TCPServer::listen(unsigned int port,unsigned int max_conn)
{
	setPort(port);
	close();
	init();
	setConn( (bind(getSock(),getAddr(),sizeof(sockaddr)) != SOCKET_ERROR && listen(getSock(),max_conn) >= 0 ) );
	return is_conn();
}

TCPSocket TCPServer::accept()
{
	if(!is_conn())
		return TCPSocket(SOCKET_ERROR,false);
		
	SOCKET s;
	sockaddr_in a={0};
	s=accept(sock,(sockaddr*)&a,sizeof(sockaddr));
	return TCPSocket(s,s!=SOCKET_ERROR);
}

void TCPServer::close()
{
	if(is_conn())
	{
		closesocket(getSock());
		setConn(false);
	}
}
