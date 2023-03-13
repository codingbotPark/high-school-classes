/*
* ex01.c
*
* Created: 2022-06-17 오후 2:19:32
* Author : user
*/



#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart_printf.h"

// led세팅
#define LED_DDR DDRE
#define LED_PORT PORTE

#define BUZZ_DDR DDRD
#define BUZZ_PORT PORTD

#define BAUD_RATE 51

unsigned char rxData;


int flag = 0;
int cnt = 0;
char com[3];

ISR(USART1_RX_vect){
	if(UCSR1A & (1<<RXC1)){
		rxData = UDR1;//수신 버퍼 데이터를 변수에 저장
		USART_Transmitter(rxData);
		if (rxData == '\n'){
			flag = 1;
			cnt = 0;
		} else {
			com[cnt++] = rxData;
		}
	}
}

void third(){
	USART_Init();
	sei();
	
	while (1)
	{
		if(flag == 1){
			flag = 0;
			
			if (com[0] == 'L'){
				if (com[2] == '1'){
					LED_PORT |= (0x01 << (com[1]-'0'));
				}
				else if (com[2] == '0'){
					LED_PORT ^= (0x01 << (com[1]-'0'));
				}
			}
			else if (com[0] == 'B'){
				if (com[1] == '1'){
					BUZZ_PORT = 0x00;
				}
				else if (com[1] == '0'){
					BUZZ_PORT = 0xff;
				}
			}
		}
	}
}

int main(void)
{
	BUZZ_DDR = 0xff;
	BUZZ_PORT = 0xff;
	LED_DDR = 0xff;
	LED_PORT = 0x00;

	third();

	/* Replace with your application code */
	
}


