/*
 * usart_printf.c
 *
 * Created: 2021-10-25 오전 7:40:15
 *  Author: anece
 */ 

#include "usart_printf.h"


// == USART 제어를 위한 전역 변수 선언
volatile unsigned char rxData;                              //- 송수신 데이터 저장 변수


//- USART 표준 출력 함수 ---------------------------------------------------------
int USART1_putchar(char txData, FILE *stream)
{
	//-New Line 출력의 경우 ‘\n\r’ 바꿔줘야 함 (\n : new line, \r : carriage return)
	if(txData == '\n')
	{
		while(!(UCSR1A & (1<<UDRE1))) ;
		UDR1 = '\n';
		while(!(UCSR1A & (1<<UDRE1))) ;
		UDR1 = '\r';
	}else{
		while(!(UCSR1A & (1<<UDRE1))) ;
		UDR1 = txData;
	}
	return 0;
}






// 표준입력 함수 ---------------------------------------
int USART1_getchar(FILE *stream)
{
	while(!(UCSR1A & (1<<RXC1))) ;
	return UDR1;
}


// == USART 초기화 함수 ============================================================================= */
void USART_Init()
{
	UBRR1H = (unsigned char) BAUD_RATE >> 8;				//- 전송 속도 설정
	UBRR1L = (unsigned char) BAUD_RATE;

	UCSR1B = (1<<RXCIE1) | (1<<TXEN1) | (1<<RXEN1);			//- 수신, 송신, 수신인터럽트 처리 기능 설정
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);						//- No Parity, 1 Stop Bit, 8 bit Data
	
	sei();					//- 글로벌 인터럽트를 활성화
}

// == USART Transmitter 함수 ==========================================================================
void USART_Transmitter(unsigned char txData)
{
	while(!(UCSR1A & (1<<UDRE1))) ;						//- 송신 버퍼가 빌 때까지 대기
	UDR1 = txData;										//- 버퍼에 데이터를 채우기
}

// == USART Interrupt 함수 ============================================================================ */
ISR(USART1_RX_vect)
{
	//- 수신 버퍼에서 읽어 온 데이터를 다시 송신
	if(UCSR1A & (1<<RXC1))
	{
		rxData = UDR1;
		USART_Transmitter(rxData);
	}
}