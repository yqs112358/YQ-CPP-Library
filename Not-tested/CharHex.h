#ifndef YQ_CHAR_HEX_H
#define YQ_CHAR_HEX_H

void char2hex(char dat,char *high_hex,char *low_hex,bool upper=true)
{
	char Hc=(dat >> 4) & 15;
	char hc=dat & 15;
	if(high_hex)
		*high_hex=Hc>9 ? Hc-10+(upper?'A':'a') : Hc+'0';
	if(low_hex)
		*low_hex=hc>9 ? hc-10+(upper?'A':'a') : hc+'0';
}

char hex2char(char high_hex,char low_hex)
{
	if(high_hex >= 'a')
		high_hex -= 'a'-10;
	else if (high_hex >= 'A')
		high_hex -= 'A'-10;
	else
		high_hex -= '0';
	
	if(low_hex >= 'a')
		low_hex -= 'a'-10;
	else if (low_hex >= 'A')
		low_hex -= 'A'-10;
	else
		low_hex -= '0';
	
	return (high_hex << 4) | low_hex;
}

#endif 
