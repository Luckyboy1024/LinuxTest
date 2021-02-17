#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a = 123.45;
	double b = -1234.56;
	char *ptr = NULL;
	ptr = gcvt(a, 5, ptr);
	printf("a_value = %s\n", ptr);
	ptr = gcvt(b, 6, ptr);
	printf("b_value = %s\n", ptr);
	return 0; 
}

	
