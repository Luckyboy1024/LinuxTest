#include <stdio.h>
int main()
{
	int m, a, b, c;
	for (m = 100; m <= 999; m++)	// 把 m 分解为三个数字
	{
		a = m / 100;
		b = (m / 10) % 10;
		c = m % 10;
		if (m == (a * a * a + b * b * b + c * c * c))	// 检验是否满足条件
		{
			printf("%d ", m);
		}
	}
	printf("\n");
	return 0;
}

