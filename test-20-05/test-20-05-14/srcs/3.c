#include <stdio.h>

int main()
{
	char* lp = (char *)malloc(10);
	memset(lp, '\0', 10);
	strcpy(lp, "hello-world-hello-world\n");	// 超过 lp 的大小，访问越界

	printf("%s\n", lp);	
	free(lp);
	return 0;
}
