#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 200

int main(int argc,char** argv){
    if(argc < 3){
        return -1;
    }
    
    char* file_path_from = argv[1];
    char* file_path_to = argv[2];

    char buffer[BUF_SIZE];

    int fd_from = open(file_path_from,O_RDONLY);
    int fd_to = open(file_path_to,O_WRONLY|O_CREAT|O_TRUNC,0700);
    int ret=0;

    if(fd_from == -1 || fd_to == -1){
        return -1;
    }

    while(ret=read(fd_from,buffer,BUF_SIZE)){
        write(fd_to,buffer,ret);
    }


}
