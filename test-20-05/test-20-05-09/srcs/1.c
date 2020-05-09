#include <stdio.h>
#include <math.h>

int main()
{
	int exp = 2;
	double x = 3.0;
	double answer = 0.0;
	answer = ldexp(x, exp);
	printf("3*2^(2) = %f\n", answer);
	return 0; 
}

	
