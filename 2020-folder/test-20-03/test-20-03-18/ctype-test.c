#include <stdio.h>
#include <ctype.h>


void test()
{
    char str[] = "123abcd@#$[?]";
    int i;
    for (i = 0; str[i] != 0; i++)
    {
        if (isalnum(str[i]))
        {
            printf("%c is an alphanumeric character\n", str[i]);
        }
    }
}


int main()
{
    test();
    return 0;
}
