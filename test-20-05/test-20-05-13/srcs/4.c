#include <stdio.h>

#define m 10	// 矩阵 i
#define n 10	// 矩阵 j

int main()
{
	int matrix_1[m][n];
	int matrix_2[m][n];
	int mat1[m][n];
	int mat2[m][n];
	int i = 0;
	int j = 0;
	int x = 0;	// 变量存放矩阵维度 n
	printf("矩阵维度 :>_ ");
	scanf("%d", &x);
	printf("\nmatrix_1 :> [\n");
	for(j = 0; j < x; j++)
	{
		for(i = 0; i < x; i++)
		{
			scanf("%d", &matrix_1[j][i]);
		}
	}
	while('0' < getchar()){printf("error\n"); break;};
	printf("]\n");
	printf("\nmatrix_2 :> [\n");
	for(j = 0; j < x; j++)
	{
		for(i = 0; i < x; i++)
		{
			scanf("%d", &matrix_2[j][i]);
		}
	}
	printf("]\n");
	while('0' < getchar()){printf("error\n"); break;};
	for(j = 0; j < x; j++)
	{
		for(i = 0; i < x; i++)
		{
			mat1[j][i] = matrix_1[j][i] + matrix_2[j][i];
			for(int a = 0; a < x; a++)
			{
				mat2[j][i] += matrix_1[a][i] * matrix_2[a][i];					
			}
		}	
	}
	printf("\nmat1 = {\n");
	for(j = 0; j < x; j++)
	{
		for(i = 0; i < x; i++)
		{
			printf(" %d", mat1[j][i]);
		}
		printf("\n");
	}	
	printf("}\n");
	printf("\nmat2 = {\n");
	for(j = 0; j < x; j++)
	{
		for(i = 0; i < x; i++)
		{
			printf(" %d", mat2[j][i]);
		}
		printf("\n");
	}	
	printf("}\n");
	return 0;
}
