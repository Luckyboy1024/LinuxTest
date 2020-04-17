#include <stdio.h>
#include <ctype.h>
int main()
{
	char str[] = "123c@# FD sp[e?]";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (isupper(str[i]))
			printf("%c is an uppercase character\n", str[i]);
	}
	return 0; 
}

	
