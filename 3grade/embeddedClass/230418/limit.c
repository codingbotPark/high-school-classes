#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){
	struct rlimit rlim;
	
	getrlimit(RLIMIT_NPROC, &rlim);
	printf("max user process : %lu / %ul\n", rlim.rlim_cur, rlim.rlim_max);
	
	// 오픈 가능한 파일 수
	getrlimit(RLIMIT_NOFILE, &rlim);
	printf("file size : %lu / %lu\n",rlim.rlim_cur, rlim.rlim_max);
	
	// 프로세스가 얻을 수 있는 최대 메모리
	getrlimit(RLIMIT_RSS, &rlim);
	printf("max memory size : %lu / %lu\n",rlim.rlim_cur, rlim.rlim_max);
	
	// 초 단위 CPU시간
	getrlimit(RLIMIT_CPU, &rlim);
	if (rlim.rlim_cur == RLIM_INFINITY){
		printf("cpu time : UNLIMIT\n");
	}
	
	return 0;
}
