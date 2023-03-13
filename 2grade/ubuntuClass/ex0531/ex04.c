#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    printf("여기서 출력됨\n");
    if (fork() == 0){
        sleep(3);
        execl("/bin/echo","echo","hello",NULL);
        printf("exel 실행후 출력됨\n");
        exit(1);
    }
    printf("부모프로세스 종료\n");
}