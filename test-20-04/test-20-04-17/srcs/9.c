#include <stdio.h>
#include <ctype.h>
int main()
{
	char str[] = "123c@# FDs[e?]";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (isxdigit(str[i]))
			printf("%c is a hexadecimal digits\n", str[i]);
	}
	return 0; 
}

	
