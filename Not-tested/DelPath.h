#ifndef YQ_DEL_PATH_H
#define YQ_DEL_PATH_H 

#include <windows.h>
#include <string>
#include <stack>
#include <queue>
#include "FindCtrl.h"
#include "Exist.h"

using std::string;
using std::stack;
using std::queue;

namespace DEL_PATH_H_HELP_FUNCS
{
	bool RemoveFile(string path)
	{
		DeleteFile(path.c_str());
	}
	
	bool RemoveDir(string path)
	{
		RemoveDirectory(path.c_str());
	}
}

bool DelPath(string path)
{
	namespace FUNC = DEL_PATH_H_HELP_FUNCS;
	try{
		if(path.empty())
			return false;
		
		path=CheckPath(path);
		if(IsFileExist(path))
			return FUNC::RemoveFile(path);
		if(path.back() == '\\' || path.back() == '/')
			path.pop_back();
		if(!IsDirExist(path))
			return false;
		
		queue<string> flist;
		stack<string> dirlist;
		flist.push(path);
		string nowpath;
		
		while(!flist.empty())
		{
			nowpath=flist.front();
			flist.pop();
			
			FindCtrl fc(nowpath+"\\");
			if(!fc.nextToDot())
			{
				if(!FUNC::RemoveDir(nowpath))
					return false;
				continue;
			}
			dirlist.push(nowpath);
			nowpath+="\\";
			
			do
			{
				if(fc.isDir())
					flist.push(nowpath+fc.getName());
				else if(!FUNC::RemoveFile(nowpath+fc.getName()))
					return false;
			}
			while(fc.next());
		}
		
		while(!dirlist.empty())
		{
			if(!FUNC::RemoveDir(dirlist.top()))
				return false;
			dirlist.pop();
		}
		
		return true;
	}
	catch(...)
	{
		return false;
	}
}

#endif
