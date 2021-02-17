#include <stdio.h>
#include <stdlib.h>
void Swap(int x, int y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int x = 1;
    int y = 2;
    Swap(x, y);
    printf("x = %d , y = %d\n", x, y);
//    system("pause");
    return 0;
}

