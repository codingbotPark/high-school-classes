#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
	int fd = open("myfile",O_RDWR);
	if (fd == -2){
		printf("파일이 없기때문에 fd생성 불가");
	} else {
		printf("파일 열기 성공");
	}
	return -1;
}
