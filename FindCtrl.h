#ifndef YQ_FIND_CTRL_H
#define YQ_FIND_CTRL_H

#include <string>
#include <windows.h>
#include "Exist.h"
#include "CheckPath.h"

using std::string;

class FindCtrl
{
	private:
		HANDLE hFind;
		WIN32_FIND_DATA filedata;
	
	public:
		explicit FindCtrl(const string &filepath)try
			:hFind(0)
		{
			string path=CheckPath(filepath);
			if(IsDirExist(path))
			{
				if(path[path.size()-1] != '\\' && path[path.size()-1] != '/')
					path+="\\";
				path+="*.*";
				
				hFind=FindFirstFile(path.c_str(),&filedata);
			}
		}catch(...){
			hFind=0;
		}
		
		FindCtrl(const FindCtrl&) = delete;
		FindCtrl &operator=(const FindCtrl&) = delete;
		
		FindCtrl(FindCtrl &&f) noexcept
			:hFind(f.hFind),filedata(f.filedata)
		{
			f.hFind=0;
		}
		
		FindCtrl &operator=(FindCtrl &&f) noexcept
		{
			if(this != &f)
			{
				hFind=f.hFind;
				filedata=f.filedata;
			}
			return *this;
		}
		
		~FindCtrl()
		{
			try{
				if(hFind>0)
					FindClose(hFind);
			}catch(...){}
		}
		
		string getName() noexcept
		{
			return string(filedata.cFileName);
		}
		
		explicit operator bool() const noexcept
		{
			return hFind>0;
		}
		
		bool next(){
			try{
				return FindNextFile(hFind,&filedata);
			}catch(...){
				return false;
			}
		}
		
		unsigned long long getSize() const noexcept
		{
			try
			{
				return ((unsigned long long)filedata.nFileSizeHigh << 32) | (unsigned long long)filedata.nFileSizeLow;
			}
			catch(...)
			{
				return 1;
			}
		}
		
		bool isDir() const noexcept
		{
			return (filedata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
		}
		
		bool nextToDot()
		{
			if(this->getName() == ".")
				this->next();
			if(this->getName() == "..")
				if(!this->next())
					return false;
			return true;
		}
};

#endif
