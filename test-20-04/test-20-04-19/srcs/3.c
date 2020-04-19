#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a = 123.45;
	double b = -1234.56;
	char *ptr = NULL;
	int decpt, sign = 0;
	ptr = ecvt(a, 5, &decpt, &sign);
	printf("decept = %d, sign = %d, a_value = %s\n", decpt, sign, ptr);
	ptr = ecvt(b, 6, &decpt, &sign);
	printf("decept = %d, sign = %d, b_value = %s\n", decpt, sign, ptr);
	return 0; 
}

	
