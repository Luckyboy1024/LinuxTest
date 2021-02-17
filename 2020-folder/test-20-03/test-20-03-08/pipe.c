#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if (0 != ret)
    {
        printf("create pipe failed\n");
        return 0;
    }
    int flags = fcntl(fd[1], F_GETFL, 0);   // 拿
    flags |= O_NONBLOCK;   // |= 或等
    fcntl(fd[1],F_SETFL, flags);    // 设置
    ret = fork();
    if (ret < 0)
    {
        perror("fork");
        return 0;
    }
    else if(0 == ret)
    {
        int count = 0;
        while(1)
        {
            printf("write count [%d]\n", count);
            write(fd[1], "1", 1);
            ++count;
        }
    }
    else 
    {
        sleep(1);
        char arr[1024] = { 0 };
        memset(arr, '0', 1024);
        while(1)
        {

        }
    }
    return 0;
}
