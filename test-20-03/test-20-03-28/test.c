#include <stdio.h>

void swap(char *a,char *b)
{
    char *temp = a;
    a = b;
    b = temp;

}
int main(void)
{
    char a[] = "hello";
    char b[] = "world";
    swap(a,b);
    //输出a = hello,b = world
    printf("a = %s,b = %s\n",a,b);
    return 0;
}

