
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


struct sockaddr saddr;
struct sockaddr_in source,dest;

void recv_data_process(unsigned char* buffer,int buflen);



int main()
{

	

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

	/*
	char arr[8];	
	
	int j = 0;
	
	int fd;
	if ((fd = serialOpen("/dev/ttyACM0",9600)) < 0){
		fprintf(stderr,"Unable to open serial device:%s\n",strerror(errno));
		return;
	}
	*/
	

	/*
	// 00:0c:29:36:ec:29
	// 00:0c:29:36:ec:29
	if(buffer[0] == 0xfc && 
	buffer[1] == 0xb3 && 
	buffer[2] == 0xbc && 
	buffer[3] == 0x4b && 
	buffer[4] == 0xe1 && 
	buffer[5] == 0x6e)
	{
		// on = 2 off = 3
		
		for(int i=42;i<50;i++) {
		printf("%c", buffer[i]);
		arr[j++] = buffer[i];
 		}
		
		serialPuts(fd, arr);
		 serialFlush(arr);
		j=0;
		printf("\n");			
		
	}
	*/
	
	// destination ip
	if(buffer[0] == 0x00 && 
	buffer[1] == 0x0c && 
	buffer[2] == 0x29 && 
	buffer[3] == 0x40 && 
	buffer[4] == 0x9c && 
	buffer[5] == 0xb1)
	
	
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
		/*
		printf("%d",buffer[36]);
		printf("%d",buffer[37]);
		*/
		
		
		printf("%d", (buffer[36] << 8) | buffer[37]);
		
		
		/*
		char portStrings[16];
		int j = 0;
		for (int i = 7;i>=0;--i){
			int result = buffer[36] >> i & 1;
			portStrings[j++] = result;
		}
		for (int i = 7;i>=;--i){
			int result = buffer[37] >> i & 1;
		}
		*/
		
		
		
		printf("\n");
		
		// data
		printf("DATA : ");
		for(int i=42;i<50;i++) {
		printf("%c", buffer[i]);
 		}
		
		printf("\n");			
		
	}

}
