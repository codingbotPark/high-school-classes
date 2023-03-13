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

// #include "../header/file.h"
// #include "../header/ls.h"
// #include "../header/dir.h"
#include "./file.h"
#include "./ls.h"
#include "./dir.h"

#include <sys/wait.h>

// 현재 절대경로를 구하는 함수
char *findAbsolutePath();

// home/유저 까지, 즉 ~$ 까지 만들어 주기
char *colPath(char absolutePath[1024]);

// 슬레쉬의 개수
int countSlash(char cwd[1024]);

// 경로를 출력해주는 함수
void printPath(char current[1024]);

void checkEmpty(char commandOper[512]);

int isDirectoryExists(char current[512]);

int isFileExists(char path[512], char fileName[512]);

int execute(char *commandLine);

int main()
{
    // 현재 경로가 저장된 곳을 가르키는 변수
    char *absolutePath = findAbsolutePath();
    // home/유저이름/d의 경로
    char *current = colPath(absolutePath);

    while (1)
    {
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
        for (i; (commandLine[i] != ' ') && 
        (commandLine[i] != '\0') && 
        (commandLine[i] != '\n'); i++)
        {
            command[i] = commandLine[i];
        }
        // 명령어 뒤의 값들을 걸러냄
        for (i++; (commandLine[i] != '\n') && 
        (commandLine[i] != '\0'); i++)
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


        // 기본적으로 명령어와 뒤에 오는 말 
        // 이외에 띄어쓰기가 있으면 오류로 간주

        // 단수의 명령
        if (!strcmp(command, "ls")){
            listFileDir(current);
            continue;
        } else if (!strcmp(command, "quit")){
            break;
        }

        // 연산자와 commandOper를 확인하지 않고,
        // 내가 지정하지 않은 명령어라면 else로
        // execl함수가 실행되기 때문에 주석
        // ----------------------
        // // 연산자 확인
        // if (commandOper[0] == '\0'){
        //     perror("cannot find command");
        //     continue;
        // }
        // checkEmpty(commandOper);
        // ----------------------

        if (!strcmp(command,"cd")){
            // 복사된 경로로 먼저 만들고
            // 실제로 있는 디렉토리인지 확인,
            // 실제로 없다면 다시 현제 경로
            char copiedCurrent[512];
            strcpy(copiedCurrent,current);
            if (!strcmp(commandOper,"..")){ // 뒤로
                // ~$ 에서 cd .. 이 먹히지 않도록 하기 위해
                if (countSlash(copiedCurrent) > 3){
                    // null 을 뺀 -1 , 최소 한 글자라서 -1, -2
                    for (int i = strlen(copiedCurrent)-2;
                    copiedCurrent[i] != '/';i--){
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
        else {
            // 없을 땐 execl함수를 실행시킨다
            execute(commandLine);
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
int countSlash(char cwd[1024])
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

int execute(char *commandLine)
{
    int child_status;
    pid_t pid = fork();
    if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", commandLine, NULL);
    }
    else if (pid == -1)
    {
        exit(0);
    }
    else
    {
        wait(&child_status);
        return child_status;
    }
}