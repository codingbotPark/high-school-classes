#include "../header/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include <stdbool.h>

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

// 파일 읽기
void readFile(char path[512], char fileName[512]){
	char pathName[512];
	strcpy(pathName,path);
	strcat(pathName,fileName);

	FILE *file = NULL;
	file = fopen(pathName,"r");
	int lineCount = 1;

	const int STRING_SIZE = 256;


	while (1){
		// 버퍼에 라인 입력
		char buffer[STRING_SIZE];
		fgets(buffer,sizeof(buffer),file);
		// feof 의 작동방식 때문에 한 번씩 더 실행됐었다
		if (feof(file)){
			break;
		}
		printf("[%dline] %s",lineCount++,buffer);
	}
	fclose(file);
}


// isNew = 새로운 파일인지 아닌지
void editFile(char path[512],char fileName[512],int isNew){
	char pathName[512];
	strcpy(pathName,path);
	strcat(pathName,fileName);



	char editBuffer[100];
	// 새로 만든 파일일 때
	if (isNew){
		FILE *file;
		file = fopen(pathName, "w");
		if (file == NULL)
		{
			perror("fail to read file\n");
		}
		printf("write content : ");
		fgets(editBuffer, 100, stdin);
		// printf("%s",editBuffer);

		fputs(editBuffer,file);

		fclose(file);

	} else {
		FILE *file = fopen(pathName, "r");
		if (file == NULL)
		{
			perror("fail to read file\n");
		}

		char fileContents[100][255];
		char buf[255];

		// 파일에 있는 내용들을 모두 fileContent에 넣어준다
		int len=0;
		for (len;fgets(buf, sizeof(buf),file) != NULL;len++){
			strcpy(fileContents[len],buf);
		}

		// printf("%d",len);

		// 수정할 라인과 내용을 입력받는다
		int line;
		printf("write line : ");
		scanf("%d",&line);
		printf("write content : ");
		// 엔터를 추가해준다
		scanf(" %[^\n]", editBuffer);
		editBuffer[strlen(editBuffer)] = '\n';
		
		// 입력받은 문자를 복사
		strcpy(fileContents[line-1],editBuffer);

		// 바뀐 배열을 다시 파일로 만든다
		FILE *editFile = fopen(pathName,"w");
		if (file == NULL){
			perror("fail to read file\n");
		}

		// 문자열 수 만큼 반복
		for (int i = 0;i<len;i++){
			fputs(fileContents[i],editFile);
		}

		fclose(file);
		fclose(editFile);

	}

}