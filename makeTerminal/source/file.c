#include "../header/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

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

// vi 의 확장자를 검사
int checkCommandForVi(char command[512]){
	for (int i = strlen(command) -2;i>0;i--){
		if (command[i] == '.'){
			return 1;
		}
	}
	return 0;
}

// void readFile(char path[512], char fileName[512]){
// 	char pathName[512];
// 	strcpy(pathName,path);
// 	strcat(pathName,fileName);

// 	FILE* file;
// 	file = fopen(pathName,"r");

// 	char buf[5] = {0,};
// 	int count = 0;
// 	int total = 0;

// 	while(feof(file) == 0){ 
// 		count = fread(buf, sizeof(char), 4, file);
// 		printf("%s",buf);
// 		memset(buf,0,5);
// 		total += count;
// 	} 

// 	printf("\ntotal: %d\n", total);   
// 	fclose(file);
// }


void readFile(char path[512], char fileName[512]){
	char pathName[512];
	strcpy(pathName,path);
	strcat(pathName,fileName);

	FILE* file;
	file = fopen(pathName,"r");

	char buf[5] = {0,};
	int count = 0;
	int total = 0;

	while(feof(file) == 0){ 
		count = fread(buf, sizeof(char), 4, file);
		printf("%s",buf);
		memset(buf,0,5);
		total += count;
	}

	printf("\ntotal: %d\n", total);   
	fclose(file);
}


void editFile(char path[512],char fileName[512]){
	// printf("%s\n",path);
	// printf("%s\n",fileName);
	char pathName[512];
	strcpy(pathName,path);
	strcat(pathName,fileName);

	FILE *file;
	file = fopen(pathName,"a");
	if (file == NULL){
		printf("fail\n");
	} else { 
		printf("success\n");
	}
	
	fclose(file);
}