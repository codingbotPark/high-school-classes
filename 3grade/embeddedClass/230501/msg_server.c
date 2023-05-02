#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>

#define MSQKEY 51234

struct msgbuf{
	long mtype;
	char mtext[BUFSIZ];
};

int main(int argc, char **argv){
		key_t key;
		int n, msqid;
		struct msgbuf mb;
		
		key = MSQKEY;
		// 메시지 큐 채널 생성
		if((msqid = msgget(key, IPC_CREAT | IPC_EXCL | 0600)) < 0){
			perror("msgget()");
			return -1;
		}
		
		// 메시지 큐에서 데이터 가져오기
		while((n = msgrcv(msqid, &mb, sizeof(mb), 0, 0)) > 0){
			switch(mb.mtype){
				// 메시지 타입이 1이면 화면에 가져온 데이터를 출력한다
				case 1:
					write(1, mb.mtext,n);
					break;
				case 2:
					if (msgctl(msqid, IPC_RMID, (struct msqid_ds *)0) < 0){
							perror("msgctl()");
							return -1;
					}
					break;
			}
		}
	return 0;
}
