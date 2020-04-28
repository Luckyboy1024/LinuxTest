#include "test.h"

int input()
{
	int input = 0;
	printf("################################\n");
	printf("\t 1. game \n");
	printf("\t 0. exit \n");
	printf("################################\n");
	printf("Enter your choose :>_ ");
	scanf("%d", &input);
	return input;
}

void test()
{
	while(input())
	{
		game();
	}
}
