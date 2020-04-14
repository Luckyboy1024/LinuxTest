#include <stdio.h>
#include <ctype.h>	// isalpha()
int main()
{
	char str[] = "*123cd#@AB[?";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		// if (isalnum(str[i]))printf("%c is an alphanumeric character\n", str[i]);
		if (isalpha(str[i]))printf("%c is an alphabeticric character\n", str[i]);
	}
	return 0; 
}

	
