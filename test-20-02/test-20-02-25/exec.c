#include <stdio.h>
#include <unistd.h>

int main()
{
    char* argv[3] = { 0 };
    argv[0] = "ls";
    argv[1] = "-l";
    //argv[2] = NULL;
    execvp("ls", argv);
    printf("hello\n");
    return 0;
}
