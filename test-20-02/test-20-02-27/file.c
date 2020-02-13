
#include <stdio.h>
#include <fcntl.h>     // open();
#include <unistd.h>    // write(); read();
#include <string.h>    
int main()
{
    // open(pathname, flags, mode);
    int fd = open("./tmp.txt", O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    // ssize_t write(int fd, const void* buf, size_t count); 
    // 向文件buf中写入count个字节
    char str[] = "hello world\n";
    int ret = write(fd, str, strlen(str));
    if (ret < 0)
    {
        perror("write");
    }

    lseek(fd, 2, SEEK_SET);    // 重置文件流指针位置

    // ssize_t read(int fd, void* buf, size_t count);
    // fd ：文件描述符
    // buf：读到哪里去
    // count：读多少字节，一定要预留 \0 的位置
    char buf[1024] = { 0 };
    ret = 0;
    ret = read(fd, buf, sizeof(buf) - 1);
    if (ret < 0)
    {
        perror("read");
        return 0;
    }
    printf("buf = [%s]\n", buf);
    printf("fd = [%d]\n", fd);
    close(fd);
    return 0;
}

    // buf：读到哪里去
    // count：读多少字节，一定要预留 \0 的位置
//    char buf[1024] = { 0 };
//    ret = read(fd, buf, sizeof(buf) - 1);
//    if (ret < 0)
//    {
//        perror("read");
//        return 0;
//    }
//    printf("");
