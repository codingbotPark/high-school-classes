// 디렉터리 관리
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    // 디렉토리 엔트리(파일들이 모여져있는 것)
    DIR *dp;
    // 디렉토리, 파일 담는 곳
    struct dirent *d;

    char directoryname[512]; 
    if (argc == 1){
        strcpy(directoryname,".");
        // 현재 폴더 위치를 저장
    } else {
        strcpy(directoryname,argv[1]);
    }
    printf("directoryname = %s",directoryname);
    // 이렇게 폴더를 받음

    dp = opendir(directoryname);
    if (dp == NULL){
        perror("dp is null");
        exit(0);
    }
    while ((d = readdir(dp)) != NULL){
        printf("%s\n",d ->d_name);
    }

    return 0;
}