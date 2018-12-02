/*************************************

*************************************/

#ifndef YQ_CGI_PASS_READ
#define YQ_CGI_PASS_READ

#include <conio.h>
#include <string>

using std::string;

string CGIPassRead(int len=-1)
{
	try{
		char ch;
		int n=0;
		string s="";
		while(len<0 || len>n)
		{
			ch=getch();
			if(ch == '\r')
			{
				putch('\r');
				putch('\n');
				break;
			}
			else if(ch == '\b' && n>0)
			{
				putch('\b');
				putch(' ');
				putch('\b');
				--n;
				s.erase(s.size()-1,1);
			}
			else
			{
				putch('*');
				//fflush(stdin);
				++n;
				s.append(1,ch);
			}
		}
		return s;
	}
	catch(...)
	{
		return "";
	}
}

#endif 
