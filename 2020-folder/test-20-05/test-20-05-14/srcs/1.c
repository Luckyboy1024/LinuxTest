#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h>	// memset() strcpy()

int main()
{
	char* lp = (char*)malloc(10);
	memset(lp, '\0', 10);
	strcpy(lp, "hello_world");
	printf("%s\n", lp);
	free(lp);
	free(lp);
	return 0;
}
