#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    int pid,status,chlid;

    pid = fork();
    printf("처음 프로세스 pid = %d",getpid());
    if (pid == 0){
        // 자식프로세스
        printf("자식프로세스 pid = %d",getpid());
        exit(1);
    }
    child = wait(&status);
    printf("부모프로세스 pid = %d child = %d",getpid(),child);
}