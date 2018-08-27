/****************************************************************************
* TCPSocket.cpp				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-21 
*
* 简述：网络操作类 - 通信类 - 实现 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 TCPSocket.h 		-- YQ-CPP-Libraries
*		3.依赖 GetAddr.h 		-- YQ-CPP-Libraries
* 		4.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		5.仅用于 Windows平台
****************************************************************************/

#include "TCPSocket.h"
#include "GetAddr.h"

void TCPSocket::close()
{
	if(is_conn())
	{
		closesocket(getSock());
		setConn(false);
	}
}

bool TCPSocket::is_conn()
{
	return conn;
}

TCPSocket::~TCPSocket()
{
	close();
}

TCPSocket::TCPSocket(SOCKET s,bool is_ok)
{
	setSock(s);
	setConn(is_ok);
}

string TCPSocket::getRemoteAddr(unsigned int *port)
{
	if(!is_conn())
		return "";
	return ::GetRemoteAddr(getSock(),port);
}

string TCPSocket::getRemoteAddr(unsigned int *port)
{
	if(!is_conn())
		return "";
	return ::GetLocalAddr(getSock(),port);
}

bool TCPSocket::send(const char *data,size_t size)
{
	return is_conn() && ::send(getSock(),data,size,0)>0;
}

bool TCPSocket::send(const string &data,bool is_text)
{
	return is_conn() && this->send(data.c_str(),is_text?data.size()+1:data.size());
}

bool TCPSocket::recv(char *buf,size_t size,bool peek)
{
	return is_conn() && ::recv(getSock(),buf,size,peek?MSG_PEEK:0);
}

bool TCPSocket::recv(string *buf,string::size_type size,bool is_text,bool peek)
{
	if(!is_conn())
		return false;
	char *c_data=new char[size+1];
	if(!this->recv(c_data,size,peek))
	{
		delete [] c_data;
		return false;
	}
	*buf=string(c_data,is_text?size+1:size);
	delete [] c_data;
	return true;
}
