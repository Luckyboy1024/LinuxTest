#include <stdio.h>
#include <stdlib.h>

int main()
{
	ldiv_t answer;
	answer = ldiv(2345678, 76542);
	printf("Quotient = %ld, remainder = %ld\n", answer.quot, answer.rem);
	return 0; 
}

	
