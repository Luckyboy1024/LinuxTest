#include <stdio.h>
#include <ctype.h>	// islower()
int main()
{
	char str[] = "123c@#FDsp[e? ]";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if(islower(str[i]))
			printf("%c is a lower-case character\n", str[i]);
	}
	return 0; 
}

	
