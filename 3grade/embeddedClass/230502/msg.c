#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PERM 0666
#define MAXLINE 255
#define MSGTYPE 1
struct mesg {
	long type;
	char text[255];
};
int main()
{
	int msgid, n;
	struct mesg msgbuf;
	if ((msgid = msgget(IPC_PRIVATE,PERM|IPC_CREAT|IPC_EXCL)) < 0) {
		perror("error");
		exit(1);
	}
	if (fork() == 0) { /* child */
		while ((n = msgrcv(msgid, &msgbuf, 255, 0, 0)) != -1) {
			printf("child received msg: \n");
			write(STDOUT_FILENO, msgbuf.text, n);
			printf("\n");
		}
		exit(0);
	}
	else { /* parent */
		msgbuf.type = MSGTYPE;
		while ((n = read(STDIN_FILENO, msgbuf.text, 255)) > 0) {
			msgsnd(msgid, &msgbuf, n, 0);
			printf("parent sent a msg\n");
		}
		msgctl(msgid, IPC_RMID, (struct msqid_ds *) 0);
	}
	return 0;
}
