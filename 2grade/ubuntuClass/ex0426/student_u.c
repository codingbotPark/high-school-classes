#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

typedef struct{
    char name[24];
    int id;
    int score;
} STUDENT;

void stdempty(){
    while(getchar()=='\n');
}

int main() {
    int fd;
    int fd1; 
    char c;

    fd = open("studentDB",O_RDWR);
    if (fd == -1){
        printf("file open fail");
    }
    fd1 = open("studentDV", O_RDONLY);
    // printf("fd : %d\n",fd);
    // printf("fd : %d\n",fd1);

    STUDENT student =   {"박성한",2004,22};

    do{
        printf("검색하실 학번을 입력해 주세요");
        scanf("%d",&student.id);
        getchar();   // 입력 버퍼 지우기
         
        if(fd != 0){
            lseek(fd,sizeof(student),SEEK_SET);
            read(fd,&student,sizeof(student));
            
            printf("학번 = %d 이름 = %s 점수 = %d",student.id,student.name,student.score);

            printf("수정하실 점수 입력");
            scanf("%d",&student.score);
            
            if(student.score != 0){
                lseek(fd,-(sizeof(student)),SEEK_CUR);
                write(fd,&student,sizeof(student));
            }

        }
        printf("계속 하시겠습니까? (Y/N) ");
        scanf("%c",&c);
        getchar();
    }while(c == 'Y');
    close(fd);

    return 0;
}