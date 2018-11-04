<<<<<<< HEAD
/****************************************************************************
* TCPSocket.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-19 
*
* 简述：网络操作类 - 通信类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架） 
*		3.依赖 BaseSocket.h 		-- YQ-CPP-Libraries
* 		4.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		5.仅用于 Windows平台
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
=======
/****************************************************************************
* TCPSocket.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-19 
*
* 简述：网络操作类 - 通信类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架） 
*		3.依赖 BaseSocket.h 		-- YQ-CPP-Libraries
* 		4.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		5.仅用于 Windows平台
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
>>>>>>> 98b2ee7e864df29667f44391c7a26fdb541c4564
