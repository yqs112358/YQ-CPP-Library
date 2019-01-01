#ifndef YQ_ENCODE_H
#define YQ_ENCODE_H

#include <string>
#include <sstream>
#include "StrHex.h"
using std::string;
using std::ostringstream;

string YQEncode(string s)
{
	ostringstream res;
	string bak=str2hex(s);
	for(int i=0;i<bak.size();i+=2)
		res << int(bak[i]) << int(bak[i+1]);
		
	string b=res.str();
	int n=b.size();
	for(int i=0;i<n/2;++i)
	{
		b[i]^=b[n-i-1];
		b[n-i-1]^=b[i];
		b[i]^=b[n-i-1];
	}
	return b;
}

string YQDecode(string s)
{
	int n=s.size();
	string b;
	for(int i=0;i<n/2;++i)
	{
		s[i]^=s[n-i-1];
		s[n-i-1]^=s[i];
		s[i]^=s[n-i-1];
	}
	for(int i=0;i<n;i+=2)
		b.append(1,char((s[i]-'0')*10+(s[i+1]-'0')));       
	return hex2str(b);
}

#endif
