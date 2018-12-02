#include <winsock2.h>
#include <windows.h>
//#include <string>
#include <cstddef>
#pragma comment(lib."ws2_32.lib")
//using std::string;

bool socketSend(SOCKET s,const char *data,size_t dataSize,size_t *dataSended=NULL
			,size_t bufSize=65536,int maxTry=10,int tryDelay=100)
{
	int dataSend,tryTimes=0;
	size_t dataDone=0;
	
	while(dataSize>0 && (dataSend=send(s,data+dataDone,bufSize<dataSize?bufSize:dataSize,0)) != SOCKET_ERROR)
	{
		if(dataSend == 0)
		{
			if(++tryTimes > maxTry)
				break;
			Sleep(tryDelay);
			continue;
		}
		tryTimes=0;
		dataDone+=dataSend;
		dataSize-=dataSend;
	}
	if(dataSended)
		*dataSended=dataDone;
	return dataSize == 0;
}

bool socketRecv(SOCKET s,char *buf,size_t dataSize,size_t *dataRecved=NULL)
{
	int dataRecv;
	size_t dataDone=0;
	while(dataSize>0 && (dataRecv=recv(s,buf+dataDone,dataSize,0)) > 0)
	{
		dataDone+=dataRecv;
		dataSize-=dataRecv;
	}
	if(dataRecved)
		*dataRecved=dataDone;
	return dataSize == 0;
}
