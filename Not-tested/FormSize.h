#ifndef YQ_FORMSIZE
#define YQ_FORMSIZE

#include <string>
#include "StrInt.h"

using std::string

string FormSize(unsigned int filesize)
{
	try{
		string fix[]={"B","KB","MB","GB"};
		int type=0;
		for(;filesize>=1024;filesize/=1024)
			++type
		return int2str(filesize)+fix[type];
	}catch{
		return "";
	}
}

#endif
