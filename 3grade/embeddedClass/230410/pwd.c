#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	char buff[1024];
	
	if (access(argv[1],F_OK) == -1){
		mkdir(argv[1],0755);
	}
	
	chdir(argv[1]);
	getcwd(buff, 1024);
	printf("작업 디렉토리 : %s\n",buff);
}
