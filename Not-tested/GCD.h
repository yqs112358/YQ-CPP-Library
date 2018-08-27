/****************************************************************************
* GCD.h				-- YQ-CPP-Libraries
*
* 采用  Apache 2.0  开源许可证
* 		(详见：www.apache.org/licenses/LICENSE-2.0.html)
*
* 作者：YQ
* 最后修改时间：2018-8-19 
*
* 简述：求最大公因数 - 辗转相除法 
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
