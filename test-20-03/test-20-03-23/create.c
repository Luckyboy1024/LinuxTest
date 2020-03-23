#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int ret = mkfifo("./pipe.fifo", 0664);
    if (ret < 0)
    {
        perror("mkfifo");
        return 0;
    }
    
    return 0;
}
