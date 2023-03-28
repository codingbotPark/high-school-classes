
#include <stdio.h>


void print(int str);
int input();

int main(){
	int str = input();
	print(str);
	
	return 0;
}

void print(int str){
	printf("%d",str);
}

int input(){
	
	int a,b;
	scanf("%d %d", &a ,&b);

	
	return a+b;
}
