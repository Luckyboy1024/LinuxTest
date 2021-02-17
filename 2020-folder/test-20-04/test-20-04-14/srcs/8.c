#include <stdio.h>
#include <ctype.h>	// isblank()
int main()
{
	char str[] = "123 c @#  Af    s[?]";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (isblank(str[i]))
			printf("str[%d] is blank character : %d\n", i, str[i]);
	}
	return 0; 
}

	
