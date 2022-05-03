#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

// 입력받은 수만큼의 권한을 입력된 파일에 준다
int main(int argc, char **argv){
    int perm = strtol(argv[1], (char **)NULL,8);
    chmod(argv[2],perm);
}

