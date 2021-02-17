#include <stdio.h>
#include <unistd.h>
#include "main.h"

void test()
{
	printf("%d\n", add(10, 20));
	printf("%d\n", max(10, 20));
	printf("test...\n");
	while(f())
	{
		sleep(1);
	}
}

int main()
{
	test();
	return 0;
}
