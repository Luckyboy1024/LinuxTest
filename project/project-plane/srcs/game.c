#include "game.h"

int menu()
{
	int input = 0;

	printf("##############################\n");
	printf("  1. play \n");
	printf("  2. choose \n");
	printf("  0. exit \n");
	printf("##############################\n");
	scanf("%d", &input);
	return input;
}
