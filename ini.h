#ifndef YQ_INI_H
#define YQ_INI_H

#include <windows.h>
#include <string>
#include "Exist.h"

using std::string;

class ini
{
	private:
		string path;
		bool fExist(const string &fpath);
	public:
		ini()	{}
		explicit ini(string fpath);
		
		bool open(string fpath);
		bool write(const string &sec,const string &key,const string value="");
		string getStr(const string &sec,const string &key,const string def="",const unsigned int len=65536);
		int getInt(const string &sec,const string &key,const int def=0);
		
		explicit operator bool()
		{
			return !path.empty() && fExist(path);
		}
};

ini::ini(string fpath)
{
	open(fpath);
}

bool ini::open(string fpath)
{
	if(fpath.find("\\") == string::npos && fpath.find("/") == string::npos)
		fpath="./"+fpath;
	if(fExist(fpath))
	{
		path=fpath;
		return true;
	}
	else
	{
		path.clear();
		return false;
	}
}

bool ini::write(const string &sec,const string &key,const string value)
{
	return WritePrivateProfileString(sec.c_str(),key.c_str(),value.c_str(),path.c_str());
}

string ini::getStr(const string &sec,const string &key,const string def,const unsigned int len)
{
	char buf[len];
	memset(buf,0,sizeof(buf));
	if(GetPrivateProfileString(sec.c_str(),key.c_str(),def.c_str(),buf,sizeof(buf),path.c_str()) > 0)
		return string(buf);
	else
		return def;
}

int ini::getInt(const string &sec,const string &key,const int def)
{
	return int(GetPrivateProfileInt(sec.c_str(),key.c_str(),def,path.c_str()));
}

bool ini::fExist(const string &fpath)
{
	return IsFileExist(fpath);
}

#endif
