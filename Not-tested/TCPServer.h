<<<<<<< HEAD
/****************************************************************************
* TCPServer.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-18 
*
* 简述：网络操作类 - 服务端类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架） 
*		3.依赖 BaseSocket.h 		-- YQ-CPP-Libraries
*		4.依赖 TCPSocket.h 			-- YQ-CPP-Libraries
* 		5.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		6.仅用于 Windows平台
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
=======
/****************************************************************************
* TCPServer.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-18 
*
* 简述：网络操作类 - 服务端类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架） 
*		3.依赖 BaseSocket.h 		-- YQ-CPP-Libraries
*		4.依赖 TCPSocket.h 			-- YQ-CPP-Libraries
* 		5.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		6.仅用于 Windows平台
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
>>>>>>> 98b2ee7e864df29667f44391c7a26fdb541c4564
