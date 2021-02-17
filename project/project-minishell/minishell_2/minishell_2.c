#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>

char g_Command[1024];

int GetCommand()
{
    memset(g_Command, '\0', sizeof(g_Command));
    printf("[username@localhost] $ ");
    fflush(stdout);
    if(!fgets(g_Command, sizeof(g_Command) - 1, stdin))
    {
        printf("fgets error\n");
        return -1;
    }
    else
    {
        printf("g_Command = [%s]\n", g_Command);
    }
    return 0;
}

int ExecCommand(char* argv[])
{
    if (NULL == argv[0])
    {
        printf("ExecCommand error\n");
        return -1;                        
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return -1;                                
    }
    else if (0 == pid)
    {
        // child
        execvp(argv[0], argv);
        exit(0);
    }
    else
    {
        // father
        waitpid(pid, NULL, 0);
    }
    return 0;
}

int DealCommand(char* command)
{
    if(!command || *command == '\0')
    {
        printf("command error\n");
        return -1;
    }
    int argc = 0;
    char* argv[32] = { 0 };
    while(*command)
    {
        if(!isspace(*command))
        {
            argv[argc] = command;
            argc++;
            while((!isspace(*command)) && ('\0' != *command))
            {
                command++;
            }
            *command = '\0';
        }
        command++;
    }
    argv[argc] = NULL;
    for(int i = 0; i < argc; ++i)
    {
        printf("argv[%d] [%s]\n", i, argv[i]);
    }
    ExecCommand(argv);
    return 0;
}

int main()
{
    while(1)
    {
        if(-1 == GetCommand())
        {
            continue;
        }
        DealCommand(g_Command);
    }
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
