#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("myfile", O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {              
        perror("open");
        return 1;
    }
    printf("fd: %d\n", fd);
    close(fd);
    return 0;
}

