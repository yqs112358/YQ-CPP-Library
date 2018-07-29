#ifndef YQ_IF_SINGLE_H
#define YQ_IF_SINGLE_H

#include <windows.h>
#include <string>
#include "AutoHandle.h"

AutoHandle IfSingle(const string &name)
{
	try
	{
		if(name.empty())
			return AutoHandle(NULL);
		AutoHandle hMutex(CreateMutex(NULL,FALSE,name.c_str()));
		if(GetLastError() == ERROR_ALERADY_EXISTS || !hMutex)
			return AutoHandle(NULL);
		return hMutex;
	}
	catch(...)
	{
		return AutoHandle(NULL);
	}
}

#endif
