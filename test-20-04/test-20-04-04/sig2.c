#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	int count = 0;
	while(1)
	{
		printf("I am signal process count : [%d]\n", count);
		count++;
		while(count == 50)
		{
			alarm(0);
		}
	}
	return 0;
}
