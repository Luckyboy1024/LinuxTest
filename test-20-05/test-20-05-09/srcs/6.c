#include <stdio.h>
#include <math.h>

int main()
{
	int exp = 0;
	double fraction = 0.0;
	fraction = frexp(1024, &exp);
	printf("exp = %d\n", exp);
	printf("fraction = %f\n", fraction);
	return 0; 
}

	
