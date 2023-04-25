#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv){
		pid_t pid;
		int pfd[2];
		char line[BUFSIZ];
		int status;
		
		if(pipe(pfd)<0){
			perror("pipe()");
			return -1; 
		}
}
