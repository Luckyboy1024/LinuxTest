#include <stdio.h>
#include <ctype.h>
int main()
{
	int a = 217;
	char b;
	printf("before toascii() : a_value = %d (%c)\n", a, a);
	b = toascii(a);
	printf("before toascii() : a_value = %d (%c)\n", b, b);
	return 0; 
}

	
