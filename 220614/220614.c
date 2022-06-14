/*
 * 220614.c
 *
 * Created: 2022-06-14 오후 7:06:59
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart_printf.h"

// led세팅
#define LED_DDR DDRE
#define LED_PORT PORTE
// 버튼세팅
#define Switch_DDR DDRC
#define Switch_PIN PINC
// 세븐세그먼트 세팅
#define Seg_DDR DDRB
#define Seg_PORT PORTB

// 세그먼트는 
//  _
// l_l
// l_l
// 위에서부터 오른쪽으로 돌며, 마지막이 안쪽
// a,b,c,d.. 즉 0000001 는 위의 세그먼트만 나온다

int num[15] = { 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x77, 0x7C, 0x39, 0x5e, 0x79, 0x71};

void turnLED(int amount) {
	unsigned char port = 0;
	
	for(int i = 0; i < amount; i++) {
		port |= (1<<i);
	}
	
	LED_PORT = port;
}

void first(){

	Seg_DDR = 0xff;
	Seg_PORT = 0x00;
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;

	
	while(1){
		for(int i = 0;i<8;i++){
			if ((Switch_PIN&(1<<i))==0){
				//LED_PORT=num[i];
				Seg_PORT = num[i];
				turnLED(i+1);
				//LED_PORT=(0xff>>(7-i));
			}
		}
	}
}

/* == ADC 초기화 함수 구현 ============================================================================ */
void Init_ADC()
{
	//- ADC1 채널, AREF 기준 전압 => AVCC로 H/W 설정 
	ADMUX  = (1<<REFS0) | (1<<MUX0);	
			                          
	//- 채널, 활성화, 프리스케일 설정
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);	
}

/* == ADC 변환 함수 구현 ============================================================================== */
unsigned int startADConverter()
{
	unsigned int result;

	cli();									//- ADC 변환 중 인터럽트 금지

	ADCSRA |= (1<<ADSC);					//- ADC 변환 시작
	while(!(ADCSRA & (1<<ADIF))) ;			//- ADC 변환 완료 신호 대기

	result = ADCL;		            	 	//- 변환 결과 저장
	result |= ((ADCH & 0x03) << 8);

	sei();									//- 인터럽트 허용

	return result;
}

void second(){
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	
	unsigned int AdcResult;							//- 변환값 저장 변수 

	USART_Init();		                            //- USART1 초기화
	stdout = &device;	                            //- 표준출력으로 사용할 장치 설정

	Init_ADC();										//- ADC 초기화

	
	while(1)
	{
		AdcResult = startADConverter();				//- ADC 변환 실행
		printf("LIGHT %d\n", AdcResult);
		if (AdcResult < 85){/*
 * 220614.c
 *
 * Created: 2022-06-14 오후 7:06:59
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart_printf.h"

// led세팅
#define LED_DDR DDRE
#define LED_PORT PORTE
// 버튼세팅
#define Switch_DDR DDRC
#define Switch_PIN PINC
// 세븐세그먼트 세팅
#define Seg_DDR DDRB
#define Seg_PORT PORTB

#include <avr/io.h>
#include <avr/interrupt.h>
#include "tlcd.h"

#define BAUD_RATE 51 // atmega128의 데이터 시트 51



// 세그먼트는 
//  _
// l_l
// l_l
// 위에서부터 오른쪽으로 돌며, 마지막이 안쪽
// a,b,c,d.. 즉 0000001 는 위의 세그먼트만 나온다

int num[15] = { 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x77, 0x7C, 0x39, 0x5e, 0x79, 0x71};

void turnLED(int amount) {
	unsigned char port = 0;
	
	for(int i = 0; i < amount; i++) {
		port |= (1<<i);
	}
	
	LED_PORT = port;
}

void first(){

	Seg_DDR = 0xff;
	Seg_PORT = 0x00;
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;

	
	while(1){
		for(int i = 0;i<8;i++){
			if ((Switch_PIN&(1<<i))==0){
				//LED_PORT=num[i];
				Seg_PORT = num[i];
				turnLED(i+1);
				//LED_PORT=(0xff>>(7-i));
			}
		}
	}
}

// --------------------

/* == ADC 초기화 함수 구현 ============================================================================ */
void Init_ADC()
{
	//- ADC1 채널, AREF 기준 전압 => AVCC로 H/W 설정 
	ADMUX  = (1<<REFS0) | (1<<MUX0);	
			                          
	//- 채널, 활성화, 프리스케일 설정
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);	
}

/* == ADC 변환 함수 구현 ============================================================================== */
unsigned int startADConverter()
{
	unsigned int result;

	cli();									//- ADC 변환 중 인터럽트 금지

	ADCSRA |= (1<<ADSC);					//- ADC 변환 시작
	while(!(ADCSRA & (1<<ADIF))) ;			//- ADC 변환 완료 신호 대기

	result = ADCL;		            	 	//- 변환 결과 저장
	result |= ((ADCH & 0x03) << 8);

	sei();									//- 인터럽트 허용

	return result;
}

void second(){
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	
	unsigned int AdcResult;							//- 변환값 저장 변수 

	USART_Init();		                            //- USART1 초기화
	stdout = &device;	                            //- 표준출력으로 사용할 장치 설정

	Init_ADC();										//- ADC 초기화

	
	while(1)
	{
		AdcResult = startADConverter();				//- ADC 변환 실행
		printf("LIGHT %d\n", AdcResult);
		if (AdcResult < 85){
			LED_PORT = 0xff;
		} else {
			LED_PORT = 0x00;
		}
		_delay_ms(2000);
	}
}

// --------------------


void USART_Init(){

	UBRR1H = (unsigned char) BAUD_RATE >> 8;
	UBRR1L = (unsigned char) BAUD_RATE;

	UCSR1B = (1<<RXCIE1) | (1<<TXEN1) | (1<<RXEN1);
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
}


unsigned char rxData;

void USART_Transmitter(unsigned char txData){
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = txData;
}

ISR(USART1_RX_vect){
	if(UCSR1A & (1<<RXC1)){
		rxData = UDR1;//수신 버퍼 데이터를 변수에 저장
		USART_Transmitter(rxData);
		
	}
}

void third(){
	TXT_LCD_Init();
	USART_Init();
	sei();
	
	while(1){
		;
	}
}

int main(void)
{
	//first();
	//second();
	third();
	
	
    /* Replace with your application code */
    
}





			LED_PORT = 0xff;
		} else {
			LED_PORT = 0x00;
		}
		_delay_ms(2000);
	}
}

void third(){
	
}

int main(void)
{
	//first();
	//second();
	third();
	
    /* Replace with your application code */
    
}




