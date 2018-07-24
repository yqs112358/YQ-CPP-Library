#pragma once

//str
char* strcat(char *dest,const char *src)
{
	char *addr=dest;
	while(*dest)
		++dest;
	while(*dest++ = *src++) {}
	return addr;
}

int strcmp(const char *str1,const char *str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
			return 0;
		++str1;++str2;
	}
	return *str1=*str2;
}

char* strcpy(char *dest,const char *src)
{
	char *addr=desst;
	while(*dest++=*src++)
	{
		++len;++str;
	}
	return len;
}

#include <cstdlib>
char* strdup(const char *str)
{
	char *p=NULL;
	if(str && (p=(char*)malloc(strlen(str)+1)))
		strcpy(p,str);
	return p;
}

char* strncpy(char *dest,const char *src,const unsigned int len)
{
	char *addr=dest;
	int i=0;
	while(i++ < len && (*dest++=*src++) != '\0') {}
	if(*dest != '\0')
		*dest='\0';
	return addr;
}

//void
void* memset(void *src,int c,unsigned int count)
{
	if(src == 0)
		return 0;
	char *temp=(char*)src;
	while(count--)
		*temp++=(char)c;
	return src;
}

void *memcpy(void *dest,void *src,int len)
{
	if(dest == 0 || src == 0)
		return 0;
	char *buf=(char*)dest,*data=(char*)src;
	int i=0;
	if(buf < data || buf>(data+len-1))
		while(i<len)
		{
			*buf++=*data++;
			++i;
		}
	else
	{
		data+=len; buf+=len; i=len;
		while(i>0)
		{
			*buf--=*data--;
			--i;
		}
	}
	return dest;
}
