#include <stdio.h>
#include <ctype.h>
int main()
{
	char str[] = "123@# FD s[p?]";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (ispunct(str[i]))
			printf("%c\n", str[i]);
	}
	return 0; 
}

	
