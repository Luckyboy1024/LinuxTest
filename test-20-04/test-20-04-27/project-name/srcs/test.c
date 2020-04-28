#include <stdio.h>
#include "test.h"

int f()
{
	if ( printf("hello...\n"))
	{
		return 0;
	}
	return -1;
}
