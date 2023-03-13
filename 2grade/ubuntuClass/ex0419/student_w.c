#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct student{
    char name[24];
    int id;
    int score;
} STUDENT;

int main(){
    int fd1;
    fd1 = open("studentdb",O_WRONLY|O_CREAT|O_EXCL,0640);

    if (fd1 == -1){
        printf("fd1 create 실패");
        return -1;
    }
    printf("학번 이름 점수 입력하세요");

    STUDENT student;

    while(scanf("%d %s %d", &student.id, student.name, &student.score) == 3){
        lseek(fd1,student.id * sizeof(student),SEEK_SET); // 크기만큼 넘김
        write(fd1,&student,sizeof(student));
        printf("\n");
    }

    return 0;
}