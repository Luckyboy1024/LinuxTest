#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 3; i++)
	{
		int ret = rand() % 20 + 1;
		printf("%d ", ret);
	}
	return 0; 
}
			

