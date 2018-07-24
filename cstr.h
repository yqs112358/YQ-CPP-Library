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
		//string构造函数 
		cstr(const string &str);
		//C-string构造函数 
		cstr(const char *c);
		//拷贝构造函数 
		cstr(const cstr &c);
		//移动构造函数 
		cstr(cstr &&c) noexcept;
		//析构函数 
		~cstr() noexcept;
		
		//拷贝赋值运算符 
		cstr &operator=(const cstr &c);
		
		//移动赋值运算符 
		cstr &operator=(cstr &&c) noexcept; 
		
		//到bool的类型转换 
		explicit operator bool() const noexcept
		{
			return cptr!=0;
		}
		//到char*的类型转换
		operator char*() const noexcept
		{
			return cptr?cptr:0;
		}
		
		//字符指针返回 
		char* str() const noexcept;
		//返回字符串内存大小 
		const unsigned int size();
		//返回字符串长度 
		const unsigned int length();
		//返回string字符串 
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


//string构造函数 
cstr::cstr(const string &str)try
:cptr(new (nothrow) char[str.size()+1])
{
	copy(str.c_str());
}
catch(...)
{
	cptr=0;
}
//C-string构造函数 
cstr::cstr(const char *c)try
:cptr(new (nothrow) char[strlen(c)])
{
	copy(c);
}
catch(...){
	cptr=0;
}
//拷贝构造函数 
cstr::cstr(const cstr &c)try
:cptr(new (nothrow) char[strlen(c.cptr)])
{
	copy(c.cptr);
}catch(...){
	cptr=0;
}
//移动构造函数 
cstr::cstr(cstr &&c) noexcept
:cptr(c.cptr)
{
	c.cptr=0;
}
//析构函数 
cstr::~cstr() noexcept
{
	free();
	cptr=0;
}

//拷贝赋值运算符 
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

//移动赋值运算符 
cstr& cstr::operator=(cstr &&c) noexcept
{
	if(this != &c)
	{
		cptr=c.cptr;
		c.cptr=0;
	}
	return *this;
}

//字符指针返回 
char* cstr::str() const noexcept
{
	return cptr?cptr:0;
}
//返回字符串内存大小 
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
//返回字符串长度 
const unsigned int cstr::length()
{
	return size()-1;
}
//返回string字符串 
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
