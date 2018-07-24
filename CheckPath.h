#ifndef YQ_CHECK_PATH_H 
#define YQ_CHECK_PATH_H 

#include <string>
using std::string;

string CheckPath(string path)
{
	try
	{
		string::size_type pos=0;
		string chars("?*:<>|\"");
		while((pos=path.find_first_of(chars,pos)) != string::npos)
			path.erase(pos,1);
		return path;
	}
	catch(...)
	{
		return "";
	}
}

#endif
