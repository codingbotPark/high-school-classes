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

// int arrowPs(){
//     int child_status;
//     pid_t pid = fork();

//     if (pid == 0)
//     {
//         execl("/bin/sh", "sh", "-c", "ps >> a", NULL);
//     }
//     else if (pid == -1)
//     {
//         exit(0);
//     }
//     else
//     {
//         wait(&child_status);
//         return child_status;
//     }
// }

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
    // int select;

    // // echo로 출력할 것
    // char comment[30];
    // while (1)
    // {
    //     printf("\n");
    //     printf("무슨 명령어 실행할거임?\n");
    //     printf("1:ls 2:echo 3:ps 4:date 5:env 6:ps>>a 7:quit : ");
    //     scanf("%d",&select);
    //     printf("\n");   

    //     switch (select)
    //     {
    //     case 1:
    //         execute("ls");
    //         break;
    //     case 2: // echo는 그냥 출력
    //         printf("어떤 말을 echo할건가요? ");
    //         scanf("%s",comment);
    //         printf("%s\n",comment);
    //         break;
    //     case 3:
    //         execute("ps");
    //         break;
    //     case 4:
    //         execute("date");
    //         break;
    //     case 5:
    //         execute("env");
    //         break;
    //     case 6:
    //         execute("ps >> a");
    //         break;
    //     case 7:
    //         exit(0);
    //         break;
    //     // case 
    //     default:
    //         printf("1~7번까지 입력하셈!\n");
    //         break;
    //     }
    // }
    
    while(1){
        if (strstr(commandLine, "quit"))
        {
            exit(0);
        }
        else    
        {
            scanf(" %[^\n]s",commandLine);
            execute(commandLine);
        }
    }
}
