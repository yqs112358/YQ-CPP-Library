/****************************************************************************
* TCPClient.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-19 
*
* 简述：网络操作类 - 客户端类 - 定义 
*
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 winsock2.h 和 ws2_32.lib （微软套接字框架）  
*		3.依赖 TCPSocket.h 			-- YQ-CPP-Libraries
* 		4.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		5.仅用于 Windows平台
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


