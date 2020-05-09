#include <stdio.h>
#include <math.h>

int main()
{
	double value[] = { 4.8, 1.12, -2.2, 0 };
	int i = 0;
	for (i = 0; value[i] != 0; i++)
	{
		printf("%f => %f\n", value[i], ceil(value[i]));
	}
	return 0; 
}

	
