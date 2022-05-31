/*
 * 220531-1.c
 *
 * Created: 2022-05-31 오후 1:24:44
 * Author : user
 */ 

// LCD에는 텍스트형, 그래픽 형이 있다
// 텍스트 형은 제조회사, 모델이 달라도 동일한 방식으로 동작한다

// CG ROM은 기본적으로 가지고 있는 함수,
// CG RAM은 사용자 문자 생성용 메모리

#include <avr/io.h>
#include <avr/interrupt.h>
#include "tlcd.h"

#define BAUD_RATE 51 // atmega128의 데이터 시트 51



// USART초기화 함수
void USART_Init(){
	// 전송 속도 설정
	UBRR1H = (unsigned char) BAUD_RATE >> 8;
	UBRR1L = (unsigned char) BAUD_RATE;
	
	// 송신, 수신, 수신인터럽트 기능 설정
	UCSR1B = (1<<RXCIE1) | (1<<TXEN1) | (1<<RXEN1);
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
}

//volatile unsigned char rxData;
//char rxData;
unsigned char rxData;

void USART_Transmitter(unsigned char txData){
	// 송신 버퍼가 빌 때까지 대기하고, 버퍼에 데이터를 채운다
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = txData;
}

// 인터럽트로 들어온 값을 받기
int number = 0;
ISR(USART1_RX_vect){
	if(UCSR1A & (1<<RXC1)){
		//rxData = UDR1;//수신 버퍼 데이터를 변수에 저장
		
		rxData = UDR1;
		USART_Transmitter(rxData);

		//SendText(DDRAM_ADDR | 0x00, rxData);
		//SendText(DDRAM_ADDR | 0x00, rxData);
		
		char * str;
		str = rxData;
		
		//for (int i = 0;i;)
		if (rxData == '\n'){
			//USART_Transmitter()
			USART_Transmitter(number + '0');
			number = 0;
		} else {
			number++;
			//SendData(rxData);
			
			//SendText(DDRAM_ADDR | 0x00, &str);
		}
		
		
		
		//SendText(DDRAM_ADDR | 0x00,"HELLO"); // 1행에 문자 출력
		//SendText(DDRAM_ADDR | 0x40, "1234567890"); // 2행에 문자 출력
	}
}


int main(void)
{
	// textlcd 초기화
	TXT_LCD_Init();
	
	//SendText(DDRAM_ADDR | 0x00,"HELLO"); // 1행에 문자 출력
	//SendText(DDRAM_ADDR | 0x40, "1234567890"); // 2행에 문자 출력
	
	USART_Init();
	
	sei();
	
    /* Replace with your application code */
    while (1)
    {
		;
    }
}

