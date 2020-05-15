#include <stdio.h>

int main()
{
	int ai, aj, bi, bj = 0;
	int matrix1[100] = { 0 };
	int matrix2[100] = { 0 };
	int mat1[100], mat2[100] = { 0 };
	int i = 0;
	do{
		printf("矩阵 A :>_ \n");
		printf("\t行数 i : "); scanf("%d", &ai);
		printf("\t列数 j : "); scanf("%d", &aj);
		if(ai != aj) {printf("\nerror\n");continue;}
		printf("输入矩阵 :>_ { \n");
		for(i = 0; i < ai*aj; i++)
		{
			scanf("%d", &matrix1[i]);
		}
		printf("}\n"); fflush(stdin);
		printf("矩阵 B :>_ \n");
		printf("\t行数 i : "); scanf("%d", &bi);
		printf("\t列数 j : "); scanf("%d", &bj);
		if((bi != bj) || (ai != bi)) {printf("\nerror\n");continue;}
		printf("输入矩阵 :>_ { \n");
		for(i = 0; i < bi*bj; i++)
		{
			scanf("%d", &matrix2[i]);
		}
		printf("}\n");
		for(i = 0; i < ai*aj; i++)
		{
			mat1[i] = matrix1[i] + matrix2[i];
			for(int x = 0; x < aj; x++)
			{
				mat2[i] += matrix1[(i%aj) + (aj*x)] * matrix2[(i/aj)*aj + x];
			}
		}
		printf("mat1 = {\n");
		for(i = 0; i < ai*aj; i++)
		{
			printf(" %d", mat1[i]);
			if(i == aj-1)
			{
				printf("\n");
			}
		}
		printf("\n}\n\nmat2 = {\n");
		for(i = 0; i < ai*aj; i++)
		{
			printf(" %d", mat2[i]);
			if(i == aj-1)
			{
				printf("\n");
			}
		}
		printf("\n}\n");
		break;
	}while(1);
	return 0;
}
