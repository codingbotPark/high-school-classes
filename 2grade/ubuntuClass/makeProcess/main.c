// 프로세스 관리 시스템

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// int flag = 0;
int execute(char *commandLine)
{
    if (!strstr(commandLine, "quit"))
    {

        int child_status;
        pid_t pid = fork();

        if (pid == 0)
        {

            execl("/bin/sh", "sh", "-c", commandLine, NULL);
        }
        else if (pid == -1)
        {
            exit(0);
        }
        else
        {
            wait(&child_status);
            return child_status;
        }
    }
}

// 끝낼 때 실행할 함수
void doA()
{
    printf("doA입니다\n");
}

void doB()
{
    printf("doB입니다\n");
}

int main()
{

    atexit(doA);
    atexit(doB);

    // 입력받는 commandLine
    char commandLine[30];

    while (1)
    {
        if (strstr(commandLine, "quit"))
        {
            exit(0);
        }
        else
        {
            printf("> ");
            scanf(" %[^\n]s", commandLine);
            execute(commandLine);
        }
    }
}
