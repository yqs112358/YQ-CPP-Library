/****************************************************************************
* RegistryStartup.h				-- YQ-CPP-Libraries	
* 
* ����  Apache 2.0  ��Դ���֤ 
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
* 
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-08-07
* 
* ��������������ָ�����򿪻���������д��ע���
* 
* ��ע��1.���� C++��׼�����(STL)
*		2.���� RegCtrl.h 		-- YQ-CPP-Libraries
* 		3.ʹ�� C++11��׼ ��д������ʱ����ش� C++11�����ϱ�׼ ���뿪��
* 		4.������ Windowsƽ̨
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
