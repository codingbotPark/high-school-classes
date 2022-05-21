// 제출기한
// 5월 22일

// 커널함수를 호출하여 다음과 같은 기능을 가진 프로그램을 구현하도록 한다.

// 기본 기능
// 1. 파일생성
// 예시)
//   파일명을 입력하세요 a
//   파일권한을 입력하세요 777

// 성공적으로 만들어졌습니다.
// 같은 파일명이 있어 만들기 실패하였습니다.

// 2. 파일삭제
// 예시)
//  파일명을 입력하세요 aa

// 성공적으로 삭제하였습니다.

// 3. 파일내용수정(문자열입력받아서 파일에 내용을 넣기)
// 예시)

//  파일명을 입력하세요 aa
//  파일에 추가하실 내용을 입력하세요 안녕하세요

// 성공적으로 파일내요을 수정하였습니다.

// 4. 디렉토리보기(ls 명령어)
// 예시)

//  디렉토리 경로를 입력하세요

// 5. 디렉토리만들기
// 예시)

//  디렉토리명 입력하세요

// 6. 디렉토리삭제
//  디렉토리명 입력하세요

// 추가하고 싶은 기능 추가 가능

// 제출파일
// 1.원본소스
// 2. 메뉴얼.ppt
// 3.실행동영상파일
// 압축해서 다음과 같은 파일명으로 제출하세요.

// 기본 경로는 home/park

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
// access 함수
// #include <io.h>	
#include <unistd.h>

#include "../header/file.h"
#include "../header/ls.h"
#include "../header/dir.h"

// 현재 절대경로를 구하는 함수
char *findAbsolutePath();

// home/유저 까지, 즉 ~$ 까지 만들어 주기
char *colPath(char absolutePath[1024]);

// 슬레쉬의 개수
int countBackslash(char cwd[1024]);

// 경로를 출력해주는 함수
void printPath(char current[1024]);

void checkEmpty(char commandOper[512]);

int isDirectoryExists(char current[512]);

int isFileExists(char path[512], char fileName[512]);

int main()
{
    // 현재 경로가 저장된 곳을 가르키는 변수
    char *absolutePath = findAbsolutePath();
    // home/유저이름/d의 경로
    char *current = colPath(absolutePath);


    // char fileName[512] = "myfile";
    while (1)
    {

        // cd 스페이스 했을 때 오류


        printPath(current);

        // 명령어 받기
        char commandLine[512];
        // 입력받은 명령어 중 명령어부분
        char command[100] = "";
        // 명령어 뒤의 값들
        char commandOper[411] = "";
        // 입력받기
        fgets(commandLine, 512, stdin);

        int i = 0;
        // 명령어를 걸러냄
        int j = 0;
        for (i; (commandLine[i] != ' ') && (commandLine[i] != '\0') && (commandLine[i] != '\n'); i++)
        {
            command[i] = commandLine[i];
        }
        // 명령어 뒤의 값들을 걸러냄
        for (i++; (commandLine[i] != '\n') && (commandLine[i] != '\0'); i++)
        {
            commandOper[j] = commandLine[i];
            j++;
        }

        // touch [파일이름] 는 파일생성
        // rm [파일이름] 파일삭제
        // ls [ls또는ls-al] 디렉토리보기
        // mkdir [디렉토리명] 디렉토리 만들기
        // rmdir [없앨디렉토리]
        // cat 파일
        // vi [있는파일이름] 파일 수정


        // 기본적으로 명령어와 뒤에 오는 말 이외에 띄어쓰기가 있으면 오류로 간주

        // 단수의 명령
        if (!strcmp(command, "ls")){
            listFileDir(current);
            continue;
        } else if (!strcmp(command, "quit")){
            break;
        }

        // 연산자 확인
        if (commandOper[0] == '\0'){
            perror("cannot find command");
            continue;
        }
        checkEmpty(commandOper);

        if (!strcmp(command,"cd")){
            // 복사된 경로로 먼저 만들고
            // 실제로 있는 디렉토리인지 확인,
            // 실제로 없다면 다시 현제 경로
            char copiedCurrent[512];
            strcpy(copiedCurrent,current);
            if (!strcmp(commandOper,"..")){ // 뒤로
                // ~$ 에서 cd .. 이 먹히지 않도록 하기 위해
                if (countBackslash(copiedCurrent) > 3){
                    // null 을 뺀 -1 , 최소 한 글자라서 -1, -2
                    for (int i = strlen(copiedCurrent)-2;copiedCurrent[i] != '/';i--){
                    // 널로 넣어줌
                    copiedCurrent[i] = '\0';
                    }
                }
            } else { // 안으로
                char temp[2] = "/";
                strcat(copiedCurrent,commandOper);
                strcat(copiedCurrent,temp);
            }
            // 존재하면
            if (isDirectoryExists(copiedCurrent)){
                // 아래처럼 하면 pointer가 같아져서
                // copiedCurrent가 current에 계속 들어가게 된다
                // current = copiedCurrent
                strcpy(current,copiedCurrent);
            } else {
                printf("cannot find path\n");
            }
        }
        else if (!strcmp(command, "touch"))
        {
            makeFile(current,commandOper);
        }
        else if (!strcmp(command, "rm"))
        {
            // 실제로 있는지 확인
            removeFile(current,commandOper);
        }else if (!strcmp(command,"cat")){
            // 파일이 있을 때 실행
            if (isFileExists(current,commandOper)){
                readFile(current,commandOper);
            } else {
                printf("cannot find file\n");
            }
        }
        else if (!strcmp(command, "vi"))
        {
            // 파일이 없으면 만들고 수정
            // file.c에 있는 vi의 확장자를 검사하는 함수
            if (checkCommandForVi(commandOper)){
                // 파일이 존재할 때 
                if (isFileExists(current,commandOper)){
                    readFile(current,commandOper);
                    editFile(current,commandOper,0);
                } else {
                    // 없다면 만들고 추가
                    makeFile(current,commandOper);
                    editFile(current,commandOper,1);
                }
            } else {
                printf("please add extension\n");
            }
            // 확장자까지 입력
        }
        
        else if (!strcmp(command, "mkdir"))
        {
            char copiedCurrent[512];
            strcpy(copiedCurrent,current);
            strcat(copiedCurrent,commandOper);
            if (!isDirectoryExists(copiedCurrent)){
                makeDirectory(current,commandOper);
            } else {
                printf("already exists directory\n");
            }
        }
        else if (!strcmp(command, "rmdir"))
        {
            char copiedCurrent[512];
            strcpy(copiedCurrent,current);
            strcat(copiedCurrent,commandOper);
            if (isDirectoryExists(copiedCurrent)){
                removeDirectory(current,commandOper);
            } else {
                printf("not exists directory");
            }
        }
    }
    return 0;
}



// 디렉토리 존재하는지
int isDirectoryExists(char copiedCurrent[512]){
    struct stat statbuf;
    // io.h 의 access는 사용할 수 없어서 fopen사용
    if (stat(copiedCurrent, &statbuf) != -1){
        if (S_ISDIR(statbuf.st_mode)){
            return 1;
        }
    } else {
        return 0;
    }
}

int isFileExists(char path[512], char fileName[512]){ 
    char copiedPathName[512];
    strcpy(copiedPathName,path);
    strcat(copiedPathName,fileName);
    struct stat buffer;
    int exist = stat(copiedPathName,&buffer);
    if (exist == 0){
        return 1;
    } else {
        return 0;
    }
}


// 현재 절대경로를 구하는 함수
char *findAbsolutePath()
{
    // cwd가 밖에서도 사용될 수 있도록 static을 붙여준다
    static char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    return cwd;
}
// home/유저 까지, 즉 ~$ 까지 만들어 주기
char *colPath(char absolutePath[1024])
{
    static char currentPath[1024];
    int counter = 0;
    for (int i = 0; absolutePath[i] != '\0'; i++)
    {
        currentPath[i] = absolutePath[i];
        if (absolutePath[i] == '/')
        {
            counter++;
            if (counter == 3)
            {
                break;
            }
        }
    }
    if (counter < 3)
    {
        perror("잘못된 현재 경로입니다");
    }
    return currentPath;
}


// 슬레쉬의 개수
int countBackslash(char cwd[1024])
{
    int counter = 0;
    for (int i = 0; cwd[i] != '\0'; i++)
    {
        if (cwd[i] == '/')
        {
            counter++;
        }
    }
    return counter;
}

// 경로를 출력해주는 함수
void printPath(char currentPath[1024])
{
    // printf("%s\n",currentPath);
    int slashCounter = 0;
    printf("~");

    // printf("%s",currentPath);
    char afterPath[1024];
    // /home/유저이름/ 을 뺀다
    int i = 0;
    int j = 0;
    for (i; slashCounter < 3; i++)
    {
        if (currentPath[i] == '/')
        {
            slashCounter++;
        }
    }
    // 슬레쉬가 없어지지 않게 i--해준다
    for (i--; currentPath[i] != '\0'; j++)
    {
        afterPath[j] = currentPath[i];
        i++;
    }
    // $일 때는 /가 없다
    if (j > 0){
        // printf("/");
        afterPath[j-1] = '\0';
    }
    printf("%s", afterPath);
    printf("$ ");
}


// 명령어와 연산자 이외에 공백이 있는지 검사
void checkEmpty(char commandOper[512]){
    
    for (int i = 0;(commandOper[i] != '\n') && (commandOper[i] != '\0');i++){
        if (commandOper[i] == ' '){
            perror("명령어와 연산 이외의 띄어쓰기를 사용할 수 없습니다");
        }
    }
}

