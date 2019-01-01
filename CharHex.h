#ifndef YQ_CHAR_HEX_H
#define YQ_CHAR_HEX_H

void char2hex(char dat,char *high_hex,char *low_hex,bool upper=true)
{
	char Hc=(dat >> 4) & char(15);
	char hc=dat & char(15);
	if(high_hex)
		*high_hex=Hc>9 ? Hc-10+(upper?'A':'a') : Hc+'0';
	if(low_hex)
		*low_hex=hc>9 ? hc-10+(upper?'A':'a') : hc+'0';
}

char hex2char(char high_hex,char low_hex)
{
	if(high_hex >= '0' && high_hex <= '9')
		high_hex-='0';
	else if(high_hex >= 'A' && high_hex <= 'F')
		high_hex-='A'-char(10);
	else if(high_hex >= 'a' && high_hex <= 'a')
		high_hex-='a'-char(10);
	else
		return '\0';
	
	if(low_hex >= '0' && low_hex <= '9')
		low_hex-='0';
	else if(low_hex >= 'A' && low_hex <= 'F')
		low_hex-='A'-char(10);
	else if(low_hex >= 'a' && low_hex <= 'a')
		low_hex-='a'-char(10);
	else
		return '\0';
	
	return (high_hex << 4) | low_hex;
}

bool isHexChar(char c)
{
	return (c>='0' && c<='9') || (c>='A' && c<='F') || (c>='a' && c<='f');
}

#endif 
