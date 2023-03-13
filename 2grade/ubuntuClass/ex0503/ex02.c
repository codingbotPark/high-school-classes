#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <sys/timeb.h>

int main(int argc,char **argv){

    struct stat buf;
    struct utimbuf tbuf;

    if (argc != 3){
        printf("사용방법 ex01 filename filename");
        exit(1);
    }

    int ret = stat(argv[1],&buf);

    if (ret < 0){
        printf("stat 명령어 에러");
    }

    tbuf.actime = buf.st_atime;
    tbuf.modtime = buf.st_mtime;

    ret = utime(argv[2], &tbuf);
    if (ret < 0){
        printf("utime 명령어 에러");
    }

    return 0;
}