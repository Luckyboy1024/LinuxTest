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
			kill(getpid(), 9);	// 给进程自己发送一个 9 号信号 
		}
	}
	return 0;
}
