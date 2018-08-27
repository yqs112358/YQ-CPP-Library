/****************************************************************************
* BaseSocket.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-18 
*
* 简述：网络操作类 - 基类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架） 
* 		3.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		4.仅用于 Windows平台
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


