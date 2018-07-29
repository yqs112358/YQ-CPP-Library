#ifndef YQ_REG_CTRL_H
#define YQ_REG_CTRL_H

#include <windows.h>
#include <Winreg.h>
#include <string>

using std::string;

class RegCtrl
{
	private:
		HKEY hKey;
		bool isopen=false;
		
		HKEY getroot(string str);
		string getkey(string str);
	public:
		RegCtrl();
		RegCtrl(string key,REGSAM rs=KEY_ALL_ACCESS,bool *open=nullptr,SECURITY_ATTRIBUTES *sa=nullptr,DWORD op=REG_OPTION_NON_VOLATILE);
		RegCtrl(const RegCtrl&) = delete;
		RegCtrl(RegCtrl &&rc) noexcept;
		
		~RegCtrl();
		
		//创建/打开键 
		bool CreateKey(string key,REGSAM rs=KEY_ALL_ACCESS,bool *open=nullptr,SECURITY_ATTRIBUTES *sa=nullptr,DWORD op=REG_OPTION_NON_VOLATILE);
		//打开键 
		bool OpenKey(string key,REGSAM rs=KEY_ALL_ACCESS);
		//删除键 
		bool DelKey(string key);
		//设置值(字符串)
		bool SetValue(string value,string dat,DWORD ty=REG_SZ);
		//设置值(数值) 
		bool SetValue(string value,DWORD dat,DWORD ty=REG_DWORD);
		//删除值 
		bool DelValue(string value);
		//读取值（字符串） 
		bool GetValue(string value,string &dat,DWORD ty=REG_SZ,const int MAX_BUF=65536);
		//读取值（数值） 
		bool GetValue(string value,DWORD &dat,DWORD ty=REG_SZ);
		
		
		RegCtrl& operator=(const RegCtrl&) = delete;
		RegCtrl& operator=(RegCtrl&& rc) noexcept;
		
		explicit operator bool() const noexcept
		{
			return isopen;
		}
};


HKEY RegCtrl::getroot(string str)
{
	string key=str.substr(0,str.find('\\'));
	if(key == "HKEY_LOCAL_MACHINE")
		return HKEY_LOCAL_MACHINE;
	if(key == "HKEY_CURRENT_USER")
		return HKEY_CURRENT_USER;
	if(key == "HKEY_CURRENT_CONFIG")
		return HKEY_CURRENT_CONFIG;
	if(key == "HKEY_CLASSES_ROOT")
		return HKEY_CLASSES_ROOT;
	if(key == "HKEY_USERS")
		return HKEY_USERS;
	
	return HKEY_CURRENT_USER;
}

string RegCtrl::getkey(string str)
{
	return str.substr(str.find('\\')+1);
}

RegCtrl::RegCtrl() {}
RegCtrl::RegCtrl(string key,REGSAM rs,bool *open,SECURITY_ATTRIBUTES *sa,DWORD op)
{
	CreateKey(key,rs,open,sa,op);
}

RegCtrl::~RegCtrl()
{
	if(isopen)
		RegCloseKey(hKey);
}

bool RegCtrl::CreateKey(string key,REGSAM rs,bool *open,SECURITY_ATTRIBUTES *sa,DWORD op)
{
	if(isopen)
	{
		RegCloseKey(hKey);
		isopen=false;
	}
	DWORD res;
	
	string subkey(getkey(key));
	bool bRet=RegCreateKeyEx(getroot(key),subkey.c_str(),0,NULL,op,rs,sa,&hKey,&res) == ERROR_SUCCESS;
	if(open != 0)
		*open=(res == REG_OPENED_EXISTING_KEY);
	if(bRet)
		isopen=true;
	
	return bRet;
}

bool RegCtrl::OpenKey(string key,REGSAM rs)
{
	if(isopen)
	{
		RegCloseKey(hKey);
		isopen=false;
	}
	
	string subkey(getkey(key));
	if(RegOpenKeyEx(getroot(key),subkey.c_str(),0,rs,&hKey) == ERROR_SUCCESS)
	    isopen=true;
	
	return isopen;
}

bool RegCtrl::DelKey(string key)
{
	string subkey(getkey(key));
	return RegDeleteKey(getroot(key),subkey.c_str()) == ERROR_SUCCESS;
}

bool RegCtrl::SetValue(string value,string dat,DWORD ty)
{
	const char *pdat=dat.c_str();
	return RegSetValueEx(hKey,value.c_str(),0,ty,(LPBYTE)pdat,(lstrlen(pdat)+1)*sizeof(TCHAR)) == ERROR_SUCCESS;
}

bool RegCtrl::SetValue(string value,DWORD dat,DWORD ty)
{
	return RegSetValueEx(hKey,value.c_str(),0,ty,(LPBYTE)&dat,sizeof(DWORD)) == ERROR_SUCCESS;
}

bool RegCtrl::DelValue(string value)
{
	return RegDeleteValue(hKey,value.c_str()) == ERROR_SUCCESS;
}

bool RegCtrl::GetValue(string value,string &dat,DWORD ty,const int MAX_BUF)
{
	char buf[MAX_BUF];
	memset(buf,sizeof(buf),0);
	DWORD dLen;
	
	if(RegQueryValueEx(hKey,value.c_str(),0,&ty,(LPBYTE)&buf,&dLen) == ERROR_SUCCESS)
	{
		dat=string(buf,(int)dLen);
		return true;
	}
	return false;
}

bool RegCtrl::GetValue(string value,DWORD &dat,DWORD ty)
{
	DWORD dLen=0;
	DWORD res=0;
	if(RegQueryValueEx(hKey,value.c_str(),0,&ty,(LPBYTE)&res,&dLen) == ERROR_SUCCESS)
	{
		dat=res;
		return true;
	}
	else return false;
}

RegCtrl::RegCtrl(RegCtrl &&rc) noexcept
	:hKey(rc.hKey)
{
	rc.isopen=false;
}

RegCtrl& RegCtrl::operator=(RegCtrl&& rc) noexcept
{
	if(this != &rc)
	{
		hKey=rc.hKey;
		isopen=rc.isopen;
		rc.isopen=false;
	}
	return *this;
}
#endif
