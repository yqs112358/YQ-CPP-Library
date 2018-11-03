/****************************************************************************
* TCPServer.cpp				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-18 
*
* 简述：网络操作类 - 服务端类 - 实现 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 TCPServer.h 		-- YQ-CPP-Libraries
* 		3.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		4.仅用于 Windows平台
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
