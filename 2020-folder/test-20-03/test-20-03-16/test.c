#include <stdio.h>

int main()
{
    char* p = "hello ""boy\n";
    printf("hello"," world\n");
    printf("%s", p);
    return 0;
}
