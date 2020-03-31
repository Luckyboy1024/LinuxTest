		
#include <stdio.h>
int main()
{
	int m, a, b, c;
	for (a = 1; a <= 9; a++)
	{
		for(b = 0; b <= 9; b++)
		{
			for(c = 0; c <= 9; c++)
			{
				m = a * 100 + b * 10 + c;	// 由 a,b,c 组合为三位数
				if (m == a * a * a + b * b * b + c * c * c)
				{	
					printf("%d ", m);
				}
			}
		}
	}
	return 0;
}

