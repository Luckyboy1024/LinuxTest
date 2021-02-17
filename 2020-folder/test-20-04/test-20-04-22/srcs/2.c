#include <stdio.h>
#include <ctype.h>
int main()
{
	char s[] = "aBcDeFgH1234;!$#";
	int i = 0;
	printf("before toupper() : %s\n", s);
	for (i = 0; i < sizeof(s); i++)
	{
		s[i] = toupper(s[i]);
	}
	printf("after  toupper() : %s\n", s);
	return 0; 
}

	
