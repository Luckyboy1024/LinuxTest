#include <stdio.h>
#include <ctype.h>	// iscntrl
int main()
{
	int a[] = { 0, 10, 29, 30, 31, 32, 45, 60, 90, 110};
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		if (iscntrl(a[i]))
			printf("%d is a contrl ascii : %c\n", a[i], a[i]);
		else 
			printf("%d is not a contrl ascii : %c\n", a[i], a[i]);
	}
	return 0; 
}	
