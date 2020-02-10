#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

char g_Command[1024];

int GetCommand()
{
    memset(g_Command, '\0', sizeof(g_Command));
    printf("")
}

int ExecCommand()
{

}

int DealCommand()
{

}

int main()
{

    return 0;
}


#if 0 

int main()
{
    while(1){
        printf("[user@localhost] $ ");
        fflush(stdout);
        char cmd_buf[1024] = { 0 };
        
    }
    return 0;
}

#endif
