#include "../header/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// 절대경로로 생성
void makeFile(char path[512], char fileName[512]){
	// 복사가 된다
	char copiedCurrent[512];
	strcpy(copiedCurrent,path);
    strcat(copiedCurrent,fileName);
    int fd = open(copiedCurrent,O_CREAT|O_TRUNC, 0777);
    if (fd == -2){
		perror("파일 생성 실패");
	}
}

void removeFile(char path[512], char fileName[512]){
	char copiedCurrent[512];
	strcpy(copiedCurrent,path);
	strcat(copiedCurrent,fileName);
	int fd = remove(copiedCurrent);
	if (fd == -1){
		perror("파일 삭제 실패");
	}
}