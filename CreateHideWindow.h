#include <windows.h>

LRESULT CALLBACK DefWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

HWND CreateHideWindow(LPCTSTR windowClass, LPCTSTR windowCapital=TEXT(""), 
		WNDPROC windowProc=DefWndProc)
{
	WNDCLASSEX wc;
	HWND hwnd;
	HINSTANCE hInstance = GetModuleHandle(NULL);

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = windowProc; 
	wc.hInstance	 = hInstance;
	wc.lpszClassName = windowClass;

	ATOM res;
	if((res = RegisterClassEx(&wc)) == 0)
		return NULL;
	
	hwnd = CreateWindowEx(0,(LPCTSTR)(ULONG_PTR)res,windowCapital
			,0,CW_USEDEFAULT,CW_USEDEFAULT,0,0,NULL,NULL,hInstance,NULL);

	return hwnd;
}

void RunMessageProcedure(HWND hwnd=NULL)
{
	MSG msg;
	while (GetMessage(&msg,hwnd,0,0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}