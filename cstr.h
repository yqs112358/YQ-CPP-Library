#pragma once

#include <string>
#include <new>

using std::string;
using std::nothrow;

class cstr
{
	private:
		char *cptr;
		
		void copy(const char *src);
		void free() noexcept;
		unsigned int strlen(const char *c);
	public:
		//string���캯�� 
		cstr(const string &str);
		//C-string���캯�� 
		cstr(const char *c);
		//�������캯�� 
		cstr(const cstr &c);
		//�ƶ����캯�� 
		cstr(cstr &&c) noexcept;
		//�������� 
		~cstr() noexcept;
		
		//������ֵ����� 
		cstr &operator=(const cstr &c);
		
		//�ƶ���ֵ����� 
		cstr &operator=(cstr &&c) noexcept; 
		
		//��bool������ת�� 
		explicit operator bool() const noexcept
		{
			return cptr!=0;
		}
		//��char*������ת��
		operator char*() const noexcept
		{
			return cptr?cptr:0;
		}
		
		//�ַ�ָ�뷵�� 
		char* str() const noexcept;
		//�����ַ����ڴ��С 
		const unsigned int size();
		//�����ַ������� 
		const unsigned int length();
		//����string�ַ��� 
		string sstr() const;
};


void cstr::copy(const char *src)
{
	if(cptr!=0)
	{
		char *buf=cptr;
		while(*buf++=*src++){}
	}
}

void cstr::free() noexcept
{
	delete [] cptr;
}

unsigned int cstr::strlen(const char *c)
{
	unsigned int len=0;
	if(c)
	{
		++len;
		while(*c!='\0')
		{
			++len;++c;
		}
	}
	return len;
}


//string���캯�� 
cstr::cstr(const string &str)try
:cptr(new (nothrow) char[str.size()+1])
{
	copy(str.c_str());
}
catch(...)
{
	cptr=0;
}
//C-string���캯�� 
cstr::cstr(const char *c)try
:cptr(new (nothrow) char[strlen(c)])
{
	copy(c);
}
catch(...){
	cptr=0;
}
//�������캯�� 
cstr::cstr(const cstr &c)try
:cptr(new (nothrow) char[strlen(c.cptr)])
{
	copy(c.cptr);
}catch(...){
	cptr=0;
}
//�ƶ����캯�� 
cstr::cstr(cstr &&c) noexcept
:cptr(c.cptr)
{
	c.cptr=0;
}
//�������� 
cstr::~cstr() noexcept
{
	free();
	cptr=0;
}

//������ֵ����� 
cstr& cstr::operator=(const cstr &c)
{
	if(this != &c)
		try{
			free();
			cptr=new (nothrow) char[strlen(c.cptr)];
			copy(c.cptr);
		}catch(...){
			cptr=0;
		}
	return *this;
}

//�ƶ���ֵ����� 
cstr& cstr::operator=(cstr &&c) noexcept
{
	if(this != &c)
	{
		cptr=c.cptr;
		c.cptr=0;
	}
	return *this;
}

//�ַ�ָ�뷵�� 
char* cstr::str() const noexcept
{
	return cptr?cptr:0;
}
//�����ַ����ڴ��С 
const unsigned int cstr::size()
{
	try{
		return strlen(cptr);
	}
	catch(...)
	{
		return 0;
	}
}
//�����ַ������� 
const unsigned int cstr::length()
{
	return size()-1;
}
//����string�ַ��� 
string cstr::sstr() const
{
	try{
		return cptr?string(cptr):"";
	}
	catch(...)
	{
		return "";
	}
}
