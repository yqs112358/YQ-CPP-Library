/****************************************************************************
* RegistryStartup.h				-- YQ-CPP-Libraries	
* 
* 采用  Apache 2.0  开源许可证 
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
* 
* 作者：YQ
* 最后修改时间：2018-08-07
* 
* 简述：用于设置指定程序开机自启动（写入注册表）
* 
* 备注：1.依赖 C++标准程序库(STL)
*		2.依赖 RegCtrl.h 		-- YQ-CPP-Libraries
* 		3.使用 C++11标准 编写，编译时请务必打开 C++11及以上标准 编译开关
* 		4.仅用于 Windows平台
****************************************************************************/

#ifndef YQ_REGISTRY_STARTUP_H
#define YQ_REGISTRY_STARTUP_H

#include <windows.h>
#include <string>
#include "Is64bit.h"

using std::string;

bool RegistryStartup(string fname ,string fpath ,bool all_machine=true ,bool 64bit_reg=Is64bitProcess())
{
	try
	{
		string main_key=all_machine?"HKEY_LOCAL_MACHINE":"HKEY_CURRENT_USER";
		
		RegCtrl rc(64bit_reg);
		if(!rc.CreateKey(all_machine+"\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",KEY_WRITE))
			return false;
		if(!rc.SetValue(fname,fpath))
			return false;
		return true;
	}
	catch(...)
	{
		return false;
	}
}

#endif
