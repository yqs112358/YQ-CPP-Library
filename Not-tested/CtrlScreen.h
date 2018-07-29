#ifndef YQ_CTRL_SCREEN_H
#define YQ_CTRL_SCREEN_H

#include <windows.h>

inline void CloseScreen()
{
	SendMessage(FindWindow(0,0),WM_SYSCOMMAND,SC_MONITORPOWER,2);
}

inline void OpenScreen()
{
	SendMessage(FindWindow(0,0),WM_SYSCOMMAND,SC_MONITORPOWER,-1);
}

#endif
