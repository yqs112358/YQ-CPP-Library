/****************************************************************************
* TCPClient.h				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ����֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-19 
*
* ��������������� - �ͻ����� - ���� 
*
* ��ע��1.���� C++��׼�����(STL)
*		2.���� winsock2.h �� ws2_32.lib ��΢���׽��ֿ�ܣ�  
*		3.���� TCPSocket.h 			-- YQ-CPP-Libraries
* 		4.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		5.������ Windowsƽ̨
****************************************************************************/

#ifndef YQ_TCP_CLIENT_H
#define YQ_TCP_CLIENT_H

#include <string>
#include "TCPSocket.h"

using std::string;

class TCPClient : public TCPSocket
{
protected:
	void init();

public:
	TCPClient();
	bool connect(const string &ip,unsigned int port);	
};

#endif


