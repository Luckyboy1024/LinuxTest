#include <stdio.h>
#include <ctype.h>
int main()
{
	char s[] = "aBcDeFgH12345;!#$";
	int i = 0;
	printf("before tolower() : %s\n", s);
	for (i = 0; i < sizeof(s); i++)
	{
		s[i] = tolower(s[i]);
	}
	printf("after  tolower() : %s\n", s);
	return 0; 
}

	
