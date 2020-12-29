/****************************************************************************
* TCPClient.cpp				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ����֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-19 
*
* ��������������� - �ͻ����� - ʵ�� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� TCPClient.h 		-- YQ-CPP-Libraries
* 		3.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		4.������ Windowsƽ̨
****************************************************************************/

#include "TCPClient.h"

TCPClient::TCPClient()
{
	setConn(false);
}

bool TCPClient::connect(const string &ip,unsigned int port)
{
	close();
	init();
	set(ip,port);
	setConn( (connect(getSock(),getAddr(),sizeof(sockaddr)) != SOCKET_ERROR) );
	return is_conn();
}

void TCPClient::init()
{
	setSock(SOCKET(AF_INET,SOCK_STREAM,0));
}
