/****************************************************************************
* TCPClient.cpp				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-19 
*
* 简述：网络操作类 - 客户端类 - 实现 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 TCPClient.h 		-- YQ-CPP-Libraries
* 		3.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		4.仅用于 Windows平台
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
