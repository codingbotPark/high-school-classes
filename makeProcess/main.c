// 프로세스 관리 시스템

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int execute(char *command){
    int child_status;
    pid_t pid = fork();

    if (pid == 0){
        execl("/bin/sh","sh","-c",command,NULL);
    } else if (pid == -1){
        exit(0);
    } else {
        wait(&child_status);
        return child_status;
    }
}

int main()
{

    char command[30];

    
    while(1){
        scanf("%s",command);
        execute(command);
    }
}

// int terminal(char *command)
// {
//     int child_status;
//     pid_t pid = fork();
//
//     if (pid == 0)
//     {
//         if (!strstr(command, "exit"))
//         {
//             exit(0);
//         }
//         else
//         {
//             execl("/bin/sh", "sh", "-c", command, NULL);
//         }
//     }
//     else if (pid == -1)
//     {
//         perror("fork");
//         exit(0);
//     }
//     else
//     {
//         wait(&child_status);
//         return child_status;
//     }
// }