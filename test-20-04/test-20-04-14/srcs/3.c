#include <stdio.h>
#include <ctype.h>	// isalnum()
int main()
{
	char str[] = "*123cd#@AB[?";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (isalnum(str[i]))
			printf("%c is an alphanumeric character\n", str[i]);
	}
	return 0; 
}

	
