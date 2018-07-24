#ifndef YQ_FINDFILE
#define YQ_FINDFILE

#include <string>
#include <vector>
#include <queue>
#include "FindCtrl.h"

using std::string;
using std::vector;
using std::queue;

struct fdata
{
	string fpath;
	unsigned int fsize;
};

bool FindFile(string path,const string filename,vector<fdata> &result,const int deep=-1)
{
	try{
		if(path.empty())
			path=".\\";
		if(path.back() != '\\')
			path.append(1,'\\');
		
		result.clear();
		queue<string> pathstr;
		queue<int> deepnum;
		
		pathstr.push("");
		deepnum.push(0);
		
		while(!pathstr.empty())
		{
			string nowpath=path+pathstr.front();
			int nowdeep=deepnum.front();
			FindCtrl fc(nowpath);
			if(!fc)
			{
				pathstr.pop();
				deepnum.pop();
				continue;
			}
			do
			{
				string nowname(fc.getName());
				if(nowname == "." || nowname == "..")
					continue;
				if(nowname == filename || filename.empty())
				{
					result.push_back({nowpath+nowname,fc.getSize()});
					continue;
				}
				if(fc.isDir() && (deep<0 || (deep>=0 && nowdeep+1 <= deep)))
				{
					pathstr.push(pathstr.front()+nowname+"\\");
					deepnum.push(deepnum.front()+1);
				}
			}
			while(fc.next());
			pathstr.pop();
			deepnum.pop();
		}
		return !result.empty();
	}
	catch(...)
	{
		return false;
	}
}
#endif
