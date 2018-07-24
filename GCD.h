#ifndef YQ_GCD_H
#define YQ_GCD_H

int gcd(int x,int y)
{
	if(x <= 0 || y <= 0)
		return -1;
	while(true)
	{
		if(x == y)
			return x;
		if(x>y)
		{
			x^=y;
			y^=x;
			x^=y;
		}
		if(x == 1)
			return 1;
		y-=x;
	}
}

#endif
