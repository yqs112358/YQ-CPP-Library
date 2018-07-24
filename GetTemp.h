#ifndef YQ_GET_TEMP_H
#define YQ_GET_TEMP_H

#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

string GetTemp(bool tmp_path=true,string fix="")
{
	try
	{
		char filename[MAX_PATH];
		char path[MAX_PATH];
		
		if(tmp_path)
		{
			if(!GetTempPath(MAX_PATH,path))
				return "";
		}
		else
			path=".\\";
		
		string::size_type len=fix.size();
		if(len<3)
		{
			srand(time(0));
			for(;len<3;++len)
				fix.push_back(1,char(rand()%26+65));
		}
		else
			fix=fix.substr(0,3);
		
		if(!GetTempFileName(path,fix.c_str(),0,filename)
			return "";
			
		return path+filename;
	}
	catch(...)
	{
		return "";
	}
}

#endif
