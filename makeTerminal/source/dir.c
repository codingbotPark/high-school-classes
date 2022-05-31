#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>



void makeDirectory(char current[512],char commandOper[512]){
    char copidPath[512];
    strcpy(copidPath,current);
    strcat(copidPath,commandOper);

    DIR *dir_info;
    struct dirent *dir_entry;

    int success = mkdir(copidPath,0755);
    if (success == -1){
        perror("fail to mkdir");
    }
}



void removeDirectory(char current[512], char commandOper[512]){
    char copiePath[512];
    strcpy(copiePath,current);
    strcat(copiePath,commandOper);

    DIR *dir_info;
    struct dirent *dir_entry;

    int success = rmdir(copiePath);
    if (success == -1){
        perror("fail to rmdir");
    }
}