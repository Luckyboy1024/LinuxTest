#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if (0 != ret)
    {
        printf("create pipe failed\n");
        return 0;
    }
    // 创建一个子进程
    ret = fork();
    if (ret < 0)
    {
        perror("fork");
        return 0;
    }
    else if (0 == ret) 
    {
        // 子进程
        // fd[1] 写端
        write(fd[1], "hello world", 11);    // 11 是写入数据(字符串)的大小
    }
    else
    {
        // 父进程
        // fd[0] 读端
        sleep(1);
        char arr[1024] = { 0 };
        read(fd[0], arr, sizeof(arr) - 1);  // 读取
        printf("fd[0] read [%s]\n", arr);
    }
    return 0;
}

