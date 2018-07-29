#ifndef YQ_GET_THIS_PATH_H
#define YQ_GET_THIS_PATH_H

#include <string>
#include <windows.h>

using std::string;

string GetThisPath()
{
	char sPath[MAX_PATH+1];
	if(GetModuleFileName(NULL,(LPSTR)sPath,sizeof(sPath)))
		return string(sPath);
	else
		return "";
}

string GetThisDir()
{
	string sDir(GetThisPath());
	return sDir.substr(0, sDir.find_last_of('\\', sDir.length())+1);
}

#endif
