#ifndef YQ_SEND_KEY_INPUT_H
#define YQ_SEND_KEY_INPUT_H

#include <string>
#include <windows.h>

using std::wstring;

// <windows.h> in MINGW 4.8.1 has no struct called 'INPUT' ?!!!
// There is only one called tagINPUT ...
// So...
#define tagINPUT INPUT

void SendKeyInput(const wstring wstr)
{
	tagINPUT input[2];
	
	for(int i=0;i<wstr.size();++i)
	{
		memset(input, 0, 2 * sizeof(INPUT));
		
		input[0].type = INPUT_KEYBOARD;
		input[0].ki.wScan=wstr[i];
		input[0].ki.dwFlags=KEYEVENTF_UNICODE;
		
		input[1].type = INPUT_KEYBOARD;
		input[1].ki.wScan=wstr[i];
		input[1].ki.dwFlags = KEYEVENTF_KEYUP|KEYEVENTF_UNICODE;
		
		SendInput(2, input, sizeof(INPUT));
	}
}
	
#endif
