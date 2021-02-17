#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("tmp.txt", O_RDWR | O_CREAT, 0664);
    if (fd < 0)
    {
        return 0;
    }

    dup2(fd, 1);    //将标准输出重定向到 fd 中去了
    printf("%s\n", "hello world");
    return 0;
}

