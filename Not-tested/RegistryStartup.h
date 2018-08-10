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

using std::string;

bool RegistryStartup(string fname,string fpath)
{
	try
	{
		RegCtrl rc("HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",KEY_WRITE);
		if(!rc)
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
