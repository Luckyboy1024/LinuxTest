#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
    while(1){
        printf("[username@localhost] $ ");
        fflush(stdout);
        char cmd_buf[1024] = { 0 };
        fgets(cmd_buf, 1023, stdin);
        cmd_buf[strlen(cmd_buf) -1 ] = '\0';
        printf("cmd : [%s]\n", cmd_buf);

        char *argv[32] = { NULL };
        int argc = 0;
        char *ptr = cmd_buf;
        while(*ptr != '\0'){
            if(!isspace(*ptr)){
                argv[argc] = ptr;
                argc++;
                while( !isspace(*ptr) && *ptr != '\0'){
                    ptr++;
                }
                *ptr = '\0';
            }
            ptr++;
        }
        argv[argc] = NULL;
        pid_t pid = fork();
        if(pid < 0){
            continue;
        }else if(0 == pid){
            execvp(argv[0], argv);
            exit(0);
        }
        wait(NULL);
    }
    return 0;
}
