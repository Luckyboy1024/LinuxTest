#include <stdio.h>

int main()
{
	int i = 0;
	int arr[7] = { 0 };
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &arr[i]);
		while((arr[i] > 50) || (arr[i] < 1))
		{
			printf("please enter again [1~50] :>_ ");
			scanf("%d", &arr[i]);
		}
	}
	for(i = 0; i < 7; i++)
	{
		int tmp = arr[i];
		while(tmp)
		{
			printf("*");
			--tmp;
		}
		printf("\n");
	}
	return 0; 
}

	
