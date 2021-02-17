
#include <stdio.h>
#include <math.h>

int main()
{
	double f, k, t, y, s;
	int n, m = 0;
	printf(" 请输入位数 n (2<n<10) :>_ ");
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		t = t * 10;										
	}
	for (y = t; y < t * 10; y++)		//枚举 n 位整数
	{
		f = y;
		s = 0.0;
		for (int i = 0; i < n; i++)	 
		{
			k = fmod(f, 10);s += pow(k, n);// 循环分离 y 的 n 个数字 k
			f = floor(f / 10);		//求 y 的 n 个数字的 n 次幂之和 s
		}
		if (y == s)					//检测是否满足条件
		{
			m++;
			printf(" %.0f ", y);		//输出探索结果					
		}													
	}
	printf("\n %d 位兰德尔数共 %d 个\n", n, m);
	return 0;
}
