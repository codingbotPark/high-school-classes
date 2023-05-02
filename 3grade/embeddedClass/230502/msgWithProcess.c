#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	int shmid;
	int *num;
	key_t key=987654;
	void *memory_segment=NULL;

	if((shmid=shmget(key,sizeof(int),IPC_CREAT|0666)) == -1){
		printf("shmget failed\n");
		exit(0);
	}

	if((memory_segment=shmat(shmid,NULL,0))==(void*)-1){
		printf("shmat failed\n");
		exit(0);
	}

	num=(int*)memory_segment;
	(*num)++;
	printf("shared memory value : %d\n",(*num));
	return 0;

}
