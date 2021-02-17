#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    // 读操作
    int fd = open("./test.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    char buf[1024] = { 0 };// 要注意在数组当中预留 \0 的位置
    while(1)
    {
        memset(buf, '\0', 1024); // 将数组先清零并初始化
        read(fd, buf, sizeof(buf) - 1);
        printf("I am read [%s]\n", buf);
    }
    while(1);
    return 0;
}

