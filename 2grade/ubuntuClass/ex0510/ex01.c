// 디렉터리 관리
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

struct aa
{
    char name[512];
};

char type(mode_t mode)
{
    if (S_ISREG(mode)) return '-';
    if (S_ISDIR(mode)) return 'd';
}

char *perm(mode_t mode){

    static char mystring[10] = "---------";
    printf("mode = %o\n",mode);
    printf("S_IREAD = %o\n",S_IREAD);

    if (mode&S_IREAD){
        mystring[6] = 'r';
    }
    if (mode&S_IWRITE){
        mystring[7] = 'w';
    }
    if (mode&S_IEXEC){
        mystring[8] = 'x';
    }

    if (mode&(S_IREAD >> 3)){
        mystring[3] = "r";
    }
    if (mode&(S_IWRITE >> 3)){
        mystring[4] = "w";
    }
    if (mode&(S_IEXEC >> 3)){
        mystring[5] = "x";
    }

    if (mode&(S_IREAD >> 6)){
        mystring[6] = "r";
    }
    if (mode&(S_IWRITE >> 6)){
        mystring[7] = "w";
    }
    if (mode&(S_IEXEC >> 6)){
        mystring[8] = "x";
    }

    return mystring;
}

void printstat(char *pathname, char *file, struct stat *st){
    // printf("pathname = %s",pathname);
    // 날짜 출력(ls -al했을 때의)
    printf("%c%s",type(st -> st_mode),perm(st -> st_mode));
    
    printf("%ld\t",st -> st_blocks);
    // printf("file = %s\n",file);

    printf("%3ld",st->st_nlink);
    printf("%s %s",getpwuid(1000)->pw_name, getgrgid(1000)->gr_name);
    printf("%9ld",st->st_size);
    printf("%12s",ctime(&st->st_mtime));
    printf("%s\n",file);

};

void setaa(struct aa *pa){
    strcpy(pa -> name, "안녕하세요 이름입니다");
};
void printaa(struct aa *pa){
    printf("pa->name = %s\n",pa -> name);
};



int main(int argc, char **argv){

    // struct aa maina;

    // setaa(&maina);
    // printaa(&maina);

    // 디렉토리 엔트리(파일들이 모여져있는 것)
    DIR *dp;
    // 디렉토리, 파일 담는 곳
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    printf("BUFSIZ = %d\n",BUFSIZ);

    char directoryname[512]; 
    if (argc == 1){
        strcpy(directoryname,".");
        // 현재 폴더 위치를 저장
    } else {
        strcpy(directoryname,argv[1]);
    }
    printf("directoryname = %s\n",directoryname);
    // 이렇게 폴더를 받음

    dp = opendir(directoryname);
    if (dp == NULL){
        perror("dp is null");
        exit(0);
    }


    while ((d = readdir(dp)) != NULL){
        sprintf(path,"%s/%s", directoryname, d->d_name);

        if (lstat(path, &st) < 0){
            perror(path);
        }

        printstat(path, d->d_name, &st);

        // printf("path = %s",path);
    }

    return 0;
}