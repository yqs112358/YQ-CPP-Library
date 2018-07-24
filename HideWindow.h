#ifndef YQ_HIDE_WINDOW_H
#define YQ_HIDE_WINDOW_H

#include <windows.h>

bool HideWindow(HANDLE &hWindow,const int try_times=0)
{
	try
	{
		if(hWindow <= 0)
			return false;
		 
		bool shown;
		int now=-1;
		ShowWindow(hWindow,SW_HIDE);
		while(true)
		{
			if(times>0)
				if(++now > times)
					return false;
			shown=ShowWindow(hWindow,SW_HIDE);
			if(!shown)
				return true;
		}
	}
	catch(...)
	{
		return false;
	}
}

#endif
