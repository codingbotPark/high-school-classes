#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd = open("myfile",O_RDWR|O_CREAT,0600);
	if (fd == 1)
		perror("error open file");
	close(fd);
	return 0;
}
