#ifndef YQ_SPITE_PATH_H
#define YQ_SPITE_PATH_H

#include <string>
#include <cstdlib>

using std::string;

void SplitPath(string path,string *drive=nullptr,string *dir=nullptr,string *fname=nullptr,string *ext=nullptr)
{
	const unsigned int MAXL=path.size()+1;
	char pdrive[MAXL]="",pdir[MAXL]="",pfname[MAXL]="",pext[MAXL]="";
	_splitpath(path.c_str(),pdrive,pdir,pfname,pext);
	
	if(drive)
		*drive=string(pdrive);
	if(dir)
		*dir=string(pdir);
	if(fname)
		*fname=string(pfname);
	if(ext)
		*ext=string(pext);
}

#endif
