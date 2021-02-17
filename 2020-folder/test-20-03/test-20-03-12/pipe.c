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

    // 取当前文件描述符的属性，通过返回值返回回来
    int flags = fcntl(fd[1], F_GETFL, 0);   //给写端fd[1]设置非阻塞
    // 给返回的文件描述符的属性加上非阻塞属性
    flags |= O_NONBLOCK;   // |= 或等
    // 给当前的文件描述符设置属性
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
        char arr[1024];
        memset(arr, '0', 1024);
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}

