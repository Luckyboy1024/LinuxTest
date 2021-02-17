#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void f()
{
    char str[101];
    for (int i = 1; i < 101; i++)
    {
        str[i-1] = '#';
        fflush(stdout);
        usleep(10000);
        printf("\r[%2d%%][%-100s]", i, str);
    }
    printf("\n");
}

int main()
{
    f();
    return 0;
}
