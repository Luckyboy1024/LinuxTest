#include <stdio.h>
#include <stdlib.h>

int main()
{
	div_t answer;
	answer = div(67, 4);
	printf("Quotient = %d, remainder = %d\n", answer.quot,answer.rem);
	return 0; 
}

	
