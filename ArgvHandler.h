#ifndef YQ_ARGV_HANDLER_H
#define YQ_ARGV_HANDLER_H

#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::string;
using std::pair;
using std::vector;

class ArgvHandler
{
	private:
		string empty_sign="";
		map<string,string> dat;
		vector<string> unnamed_dat;
	public:
		ArgvHandler(int argc,char ** argv);
		string &operator[](const string &id);
		string &operator[](int id);
		bool exist(const string &str);
};

ArgvHandler::ArgvHandler(int argc,char ** argv) try
{
	int pos=1;
	while(pos<argc)
	{
		string s(argv[pos]);
		if(s[0] == '-' || s[0] == '/')
		{
			string v;
			if(pos+1<argc && argv[pos+1][0] != '-' && argv[pos+1][0] != '/')
				v=argv[++pos];
			dat.insert(make_pair(s,v));
		}
		else
			unnamed_dat.push_back(s);
		++pos;
	}
}
catch(...)	{}

string &ArgvHandler::operator[](const string &id)
{
	empty_sign="";
	try
	{
		return dat.at(id);
	}
	catch(...)
	{
		return empty_sign;
	}
}

string &ArgvHandler::operator[](int id)
{
	empty_sign="";
	try
	{
		return unnamed_dat.at(id);
	}
	catch(...)
	{
		return empty_sign;
	}
}

bool ArgvHandler::exist(const string &str)
{
	try
	{
		return dat.find(str) != dat.end();
	}
	catch(...)
	{
		return false;
	}
}

#endif
