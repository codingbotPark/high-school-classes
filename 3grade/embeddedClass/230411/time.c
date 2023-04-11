#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(){
	time_t timep;
	time(&timep);
	printf("time : ld\n",timep);

	// printf("%d년 %d월 %d일\n",(timep / 31104000),(timep % 31104000),((timep % 31104000) / 2592000));
	
	struct timeval mytime;
	gettimeofday(&mytime,NULL);
	printf("gettimeofday : %ld:%ld\n",mytime.tv_sec, mytime.tv_usec);
	
	// ctime은 구조체 사용 없이 현재 시간 정보를 출력할 수 있다
	time_t t = time(NULL);
	printf("ctime : %s",ctime(&t));
	
	// localtime은 tm구조체를 사용해 시간을 출력한다
	time_t t2 = time(NULL);
	struct tm *t3 = localtime(&t2);
	printf("asctime : %s",asctime(t3));
	
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	// strftime = 시간을 커스텀 할 수 있도록 하는 문자열 서식화 함수
	strftime(buffer, 80, "strftime : %c",timeinfo);
	puts(buffer);
	
	return 0;
}

