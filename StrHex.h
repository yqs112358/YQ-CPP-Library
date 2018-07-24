#include <string>
#include <iostream>
using std::string;
using namespace std;

string str2hex(string s,string split="",bool upper=true)
{
	try
	{
		string res;
		for(int i=0;i<s.size();++i)
		{
			char Hc=(s[i]>>4)&15;
			char hc=s[i]&15;
			
			res.append(1,Hc>9?Hc-10+(upper?'A':'a'):Hc+'0');
			res.append(1,hc>9?hc-10+(upper?'A':'a'):hc+'0');
			res+=split;
		}
		res.erase(res.size()-split.size(),split.size());
		return res;
	}
	catch(...)
	{
		return "";
	}
}

string hex2str(string s,string split="")
{
	try
	{
		string res;
		string::size_type now=0;
		do
		{
			char Hc=s.at(now);
			char hc=s.at(now+1);
			
			if(Hc>='a')
				Hc-='a'-'A';
			if(hc>='a')
				hc-='a'-'A';
				
			Hc-=(Hc>='A')?('A'-10):'0';
			hc-=(hc>='A')?('A'-10):'0';
			res.append(1,(Hc<<4)|hc);
		}
		while(s.substr(now+1,split.size()) == split && (now+=split.size()+2) && now+2<=s.size());
		return res;
	}
	catch(...)
	{
		return "";
	}
}
