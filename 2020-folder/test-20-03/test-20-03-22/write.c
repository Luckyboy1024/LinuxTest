#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("./test.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    while(1)
    {
        write(fd, "file", 4);
        sleep(1);
    }
    return 0;
}

