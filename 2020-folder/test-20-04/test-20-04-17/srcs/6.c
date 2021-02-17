#include <stdio.h>
#include <ctype.h>	// isgraph()
int main()
{
	char str[] = "a5 @#;";
	int i = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (isgraph(str[i]))
			printf("str[%d] is printable character : %d\n", i, str[i]);
	}
	return 0; 
}

	
