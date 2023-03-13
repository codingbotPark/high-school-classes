#include "../header/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void makeFile(char currentPath[512], char fileName[512]){
    strcat(currentPath,fileName);
    printf("%s",fileName);

    int fd = open(fileName,O_CREAT|O_TRUNC, 0777);

    if (fd == -2){
		printf("파일 생성 실패");
	} else {
		printf("파일 생성 성공");
	}
}