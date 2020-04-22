#include <stdlib.h>
#include <stdio.h>
int main()
{
	char *endptr;
	char* ptr;
	char a[] = "a12345.6789";
	char b[] = "1234.567qwer";
	char c[] = "-232.23e4";
	printf( "a=%lf\n", strtod(a, &ptr)  );
	if (a==ptr)
	{
		printf("a and ptr is equality\n");
		/* 只有当带转换字符串第一个字符是非数字字符时候，a ptr 两个指针才相等; */	
	}else{
		printf("a and ptr is not equality\n");
	}
	printf( "b=%lf\n", strtod(b,&endptr)  );
	// 因为b字符串后面有非数字字符 ，endptr指针指向q字符，也只是转换到p，
	if (b==endptr)
	{
		printf("b and endptr is equality\n");
		/* code */ 
	}else{
		printf("b and endptr is not equality\n");
	}
	printf( "endptr=%s\n", endptr  );
	printf( "c=%lf\n", strtod(c,NULL)  );
	/* fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\*/									
	fprintf(stdout, "fprintf first:  %s\t""second:  %s\n", a,b);/*  C fprintf函数format字符串可以用两个双引号构成*/
	//                                                             /*printf(stdout, "printf first%s\t""printf second %s\n",c,a );   no way  buxing*/ 		
}
