#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<signal.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<sys/types.h>

#include<linux/if_packet.h>
#include<netinet/in.h>		 
#include<netinet/if_ether.h>    // for ethernet header
#include<netinet/ip.h>		// for ip header
#include<netinet/udp.h>		// for udp header
#include<netinet/tcp.h>
#include<arpa/inet.h>           // to avoid warning at inet_ntoa


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringSerial.h>


#include <wiringPi.h>
#include <wiringSerial.h>


#include <softPwm.h>

#define LED_PIN1 1
#define LED_PIN2 2
#define SERVO_PIN 0

struct sockaddr saddr;
struct sockaddr_in source,dest;

void recv_data_process(unsigned char* buffer,int buflen);


unsigned long baud = 9600;
int fd;


int main()
{
	wiringPiSetup();
	

	int sock_recv,saddr_len,buflen;

	unsigned char* buffer = (unsigned char *)malloc(65536); 
	memset(buffer,0,65536);

	printf("starting .... \n");

	sock_recv=socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL)); 
	if(sock_recv<0)
	{
		printf("error in socket\n");
		return -1;
	}

	while(1)
	{
		saddr_len=sizeof saddr;
		buflen=recvfrom(sock_recv,buffer,65536,0,&saddr,(socklen_t *)&saddr_len);

		if(buflen<0)
		{
			printf("error in reading recvfrom function\n");
			return -1;
		}

		//---------------------------------------
		recv_data_process(buffer,buflen);
		//---------------------------------------
	}

	close(sock_recv);// use signals to close socket 
	printf("DONE!!!!\n");
}


//================================================================


void recv_data_process(unsigned char* buffer,int buflen)
{


	
	
	
	
		if ((fd = serialOpen("/dev/ttyACM0",9600)) < 0){
		fprintf(stderr,"Unable to open serial device:%s\n",strerror(errno));
		return;
	}
	
	// destination mac
	if(buffer[0] == 0xe4 && 
	buffer[1] == 0x5f && 
	buffer[2] == 0x01 && 
	buffer[3] == 0x8e && 
	buffer[4] == 0x99 && 
	buffer[5] == 0x4c)
	{
		
		// myIp (destination ip)
		printf("MY IP : ");
		for (int i =30;i<33;i++){
		printf("%d * ",buffer[i]);
		}
		printf("%d",buffer[34]);
		
		printf("\n");
		// port
		printf("PORT : ");

		
		
		printf("%d", (buffer[36] << 8) | buffer[37]);
		

		
		printf("\n");
		
		char dataString[16];
		// data
		printf("DATA : ");
		for(int i=42;i<52;i++) {
		printf("%c", buffer[i]);
		dataString[i-42] = buffer[i];
 		}
		
		printf("\n");			
		
		pinMode(LED_PIN1,OUTPUT);
		pinMode(LED_PIN1,OUTPUT);
		pinMode(LED_PIN2,OUTPUT);
		pinMode(LED_PIN2,OUTPUT);
		
		
		if(strstr(dataString,"led1on") != NULL){
			serialPuts(fd,"led1on");
		} else if (strstr(dataString,"led1off") != NULL){

			
			serialPuts(fd,"led1off");
		}else if (strstr(dataString,"led2on") != NULL){

			
			serialPuts(fd,"led2on");
			
		}else if (strstr(dataString,"led2off") != NULL){
			
			
			serialPuts(fd,"led2off");
		}else if (strstr(dataString,"servoLeft") != NULL){

			serialPuts(fd,"servoLeft");
		}else if (strstr(dataString,"servoRight") != NULL){

			serialPuts(fd,"servoRight");
		}
		
	}

}
