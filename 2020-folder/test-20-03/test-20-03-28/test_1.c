#include<stdio.h>
void swap(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main(void)
{
    int a = 10;
    swap(&a,&a);//都传入a
    printf("a = %d\n",a);
    return 0;
}
