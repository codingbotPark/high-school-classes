#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void copy(char from[],char to[]);
char line[MAXLINE];
char regstr[MAXLINE];

int main(){
	int max = 0;
	
	while (1){
		gets(line);
		printf("line = %s\n",line);
		int size = strlen(line);
		printf("size = %d\n",size);
		if (max < size){
			max = size;
			copy(regstr,line);
		}
		printf("register = %s\n\n",regstr);
	}
	return 0;

}

void copy(char from[],char to[]){
	int i = 0;
	while ( (from[i]=to[i])!= "\0"){
		i++;
	}
}
