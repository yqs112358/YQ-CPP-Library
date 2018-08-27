/****************************************************************************
* GCD.h				-- YQ-CPP-Libraries
*
* ����  Apache 2.0  ��Դ���֤
* 		(�����www.apache.org/licenses/LICENSE-2.0.html)
*
* ���ߣ�YQ
* ����޸�ʱ�䣺2018-8-19 
*
* ��������������� - շת����� 
*
****************************************************************************/

#ifndef YQ_GCD_H
#define YQ_GCD_H

int gcd(int x,int y)
{
	if(x<0)
		x=-x;
	if(y<0)
		y=-y;
		
	if(x<y)
	{
		x^=y;y^=x;x^=y;
	}
	if(x == 0)
		return y;
	
	int tmp;
	while(y!=0)
	{
		tmp=x;
		x=y;
		y%=tmp;
	}
	return x;
}

#endif
