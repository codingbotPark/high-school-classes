#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void printSigset(sigset_t *set);   
static void sigHandler(int);

int main(int argc, char **argv){
	sigset_t pset; // 시그널 등록할 sigset_t
	sigemptyset(&pset);	// 모두 0으로 설정
	sigaddset(&pset, SIGQUIT); 
	sigaddset(&pset, SIGRTMIN);
	sigprocmask(SIG_BLOCK,&pset,NULL);
	
	printSigset(&pset);
	
	if(signal(SIGINT, sigHandler) == SIG_ERR){
		perror("signal() : SIGINT");
		return -1;
	} 
}

static void sigHandler(int signo){
		if (signo == SIGINT){
				printf("SIGINT is catched : %d\n",signo);
				exit(0);
		}else if(signo == SIGUSR1){
		printf("SIGUSR1 is catched\n");
	} else if (signo == SIGUSR2){
		printf("SIGUSR2 is catched\n");
	} else if (signo == SIGQUIT){
		printf("SIGQUIT is catched\n");
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset,SIGINT);
		sigprocmask(SIG_UNBLOCK, &uset,NULL);
	} else {
		fprintf(stderr, "Catched signal : %s\n", strsignal(signo));
	}
}

static void printSigset(sigset_t *set){
	int i;
	for(i=1;i<NSIG;++i){
		printf((sigismember(set,i)?"1":"0"));
	}
	putchar('\n');
}

