#ifndef YQ_STR_HEX_H
#define YQ_STR_HEX_H

#include <string>
#include "CharHex.h" 
using std::string;

string str2hex(string s,bool upper=true)
{
	try
	{
		string res;
		char Hc,hc;
		for(int i=0;i<s.size();++i)
		{
			char2hex(s[i],&Hc,&hc,upper);
			res.append(1,Hc);
			res.append(1,hc);
		}
		return res;
	}
	catch(...)
	{
		return "";
	}
}

string hex2str(string s)
{
	try
	{
		if(s.size() & 1 == 1)
			return "";
		string res;
		for(int i=0;i<s.size();i+=2)
			res.append(1,hex2char(s[i],s[i]+1));
		return res;
	}
	catch(...)
	{
		return "";
	}
}

#endif
