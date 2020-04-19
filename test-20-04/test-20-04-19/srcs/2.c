#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a = 123.45;
	double b = -1234.567;
	char *ptr = NULL;
	int decpt, sign = 0;
	ptr = fcvt(a, 2, &decpt, &sign);	// 小数点后显示 2 位数
	printf("decept = %d, sign = %d, a_value = %s\n", decpt, sign, ptr);
	ptr = fcvt(b, 3, &decpt, &sign);	// 小数点后显示 3 位数
	printf("decept = %d, sign = %d, b_value = %s\n", decpt, sign, ptr);
	return 0; 
}

	
