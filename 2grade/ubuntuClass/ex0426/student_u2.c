#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char **argv){
    printf("argc = %d",argc);
    printf("argv[1] = %s",argv[1]);

    struct stat buf;
    lstat(argv[1],&buf);

    printf("stat %o %x",buf.st_mode ,buf.st_mode);

    if (S_ISREG(buf.st_mode))
        printf("일반 파일 입니다\n");
    if (S_ISDIR(buf.st_mode))
        printf("디렉토리 파일 입니다\n");
}
