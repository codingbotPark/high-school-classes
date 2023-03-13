/*
 * GccApplication5.c
 *
 * Created: 2022-05-24 오전 1:32:15
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

// usart제어를 위한 정의
#define BAUD_RATE 51 // atmega128의 데이터 시트 51


// USART초기화 함수
void USART_Init(){
	// 전송 속도 설정
	UBRR1H = (unsigned char) BAUD_RATE >> 8;
	UBRR1L = (unsigned char) BAUD_RATE;
	
	// 송신 기능 설정
	UCSR1B = (1<<TXEN1);
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
}

// USART Transmitter 함수
void USART_Transmitter(unsigned char txData){
	// 송신 버퍼가 빌 때까지 대기하고, 버퍼에 데이터를 채운다
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = txData;
}

int main(void)
{
	unsigned char buffer[] = "Hello Atmega128!\r\n";
	int i;
	
	USART_Init();
    /* Replace with your application code */
    while (1) 
    {
		for (i=0;i<sizeof(buffer);i++){
			if (!buffer[i]){
				break;
			}
			USART_Transmitter(buffer[i]);
		}
		_delay_ms(1000);
    }
}

