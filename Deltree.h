#pragma once

#include <string>
#include <stack>
#include "FindCtrl.h"

using std::string;
using std::stack;

bool DelTree(string path)
{
	try{
		if(path.empty())
			return false;
		if(path.back()!='\')
			path.append(1,'\');
			
		stack<string> s;
		stack<FindCtrl> fc;
		
		s.emplace("");
		fc.emplace(path);
		
		if(!fc.top())
			return false;
		while(!s.empty())
		{
			bool deep=false;
			do
			{
				string nowpath=path+s.top();
				string filename=fc.top().GetName();
				if(fc.top().IsDir())
				{
					if(filename == "." || filename == "..")
						continue;
						
                    string tmp=s.top()+filename+"\\";
                    s.emplace(tmp);
                    fc.emplace(path+tmp);
                    
                    deep=true;
                    break;
                }
                else
					DeleteFile((nowpath+filename).c_str());
			}while(fc.top().Next());

			if(!deep)
			{
				do
				{
					string dir=path+s.top();
					fc.pop();s.pop();
					dir.erase(dir.size()-1,1);
					if(!RemoveDirectory(dir.c_str()))
						return false;
				}while(!fc.top().Next());
			}
		}
		return true;
	}catch(...)
	{
		return false;
	}
}
