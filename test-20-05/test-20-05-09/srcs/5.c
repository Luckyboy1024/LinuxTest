#include <stdio.h>
#include <math.h>

int main()
{
	double integral = 0.0;
	double fractional = 0.0;
	fractional = modf(3.14159, &integral);
	printf("integral   = %f\n", integral);
	printf("fractional = %f\n", fractional);
	return 0; 
}

	
