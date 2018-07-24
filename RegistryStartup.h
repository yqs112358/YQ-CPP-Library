#ifndef YQ_REGISTRY_STARTUP_H
#define YQ_REGISTRY_STARTUP_H

#include <windows.h>
#include <string>

using std::string;

bool RegistryStartup(string fname,string fpath)
{
	try
	{
		RegCtrl rc("HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",KEY_WRITE);
		if(!rc)
			return false;
		if(!rc.SetValue(fname,fpath))
			return false;
		return true;
	}
	catch(...)
	{
		return false;
	}
}

#endif
