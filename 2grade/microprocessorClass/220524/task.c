#include <avr/io.h>
// 항상 메시지 송신을 기다릴 수는 없기 때문에 인터럽트를 include
// RX수신 처리 인터럽트
#include <avr/interrupt.h>

#define LED_DDR DDRB
#define LED_PORT PORTB

// usart제어를 위한 정의
#define BAUD_RATE 51 // atmega128의 데이터 시트 51

volatile unsigned char rxData;

// USART초기화 함수
void USART_Init(){
	// 전송 속도 설정
	UBRR1H = (unsigned char) BAUD_RATE >> 8;
	UBRR1L = (unsigned char) BAUD_RATE;
	
	// 송신, 수신, 수신인터럽트 기능 설정
	UCSR1B = (1<<RXCIE1) | (1<<TXEN1) | (1<<RXEN1);
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
}

// USART Transmitter 함수
void USART_Transmitter(unsigned char txData){
	// 송신 버퍼가 빌 때까지 대기하고, 버퍼에 데이터를 채운다
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = txData;
}

char previousValue = ' ';

// 인터럽트로 들어온 값을 받기
ISR(USART1_RX_vect){
	if(UCSR1A & (1<<RXC1)){
		rxData = UDR1;//수신 버퍼 데이터를 변수에 저장
		
		USART_Transmitter(rxData);//pc로 전송해서 확인
		
		// line ending 없으로 해야됨
		// 케리지 리턴, 뉴라인이 있으면 for문에 들어가지 못함
		PORTB = 0x00;
		
		// 이 if문으로 1 -> 1 일 때 꺼지게 하고 다시 1이 들어오면 켜지게 함ㅈ
		
		// 이전 값과 다를 때 for문 실행
		if (previousValue != rxData){
			previousValue = rxData;
			
			for (int i = 0;i<rxData - '0';i++){
				PORTB = PORTB << 1;
				PORTB |= 1;
			}	
			
		} else {
		
			previousValue = ' ';
		}
		
		
		
	}
}

int main(void)
{
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	
	// 통신하기 위한 기본 세팅
	USART_Init();
	
	// 예외처리 사용
	sei();
	
	// 통신으로 S를 보낸다
	USART_Transmitter('S');
	
	
	
	/* Replace with your application code */
	while (1)
	{
		;
	}
}

