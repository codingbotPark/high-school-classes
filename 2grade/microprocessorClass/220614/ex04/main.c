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
#include "tlcd.h"

#define BAUD_RATE 51

// USART 제어를 위한 전역 변수 선언
volatile unsigned char rxData;		// 송수신 데이터 저장 변수

char mode=0;

/* == ADC 초기화 함수 구현 ============================================================================ */
void Init_ADC()
{
	//- ADC1 채널, AREF 기준 전압 => AVCC로 H/W 설정
	ADMUX  = (1<<REFS0) | (1<<MUX0) | (1<<mode);
	
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


// USART Interrupt 함수
ISR(USART1_RX_vect)
{
	// 수신 버퍼에서 읽어 온 데이터를 다시 송신
	if (UCSR1A & (1<<RXC1))		// 읽지 않은 데이터가 있다면
	{
		rxData = UDR1;					// 수신 버퍼 데이터를 변수에 저장
		USART_Transmitter(rxData);		// PC로 전송해서 확인
		
		if (rxData == 'T'){
			mode = 1;
		}
		else if(rxData == 'L'){
			mode = 0;
		}
	}
}

void fourth(){
	unsigned int AdcResult;							//- 변환값 저장 변수

	USART_Init();		                            //- USART1 초기화
	stdout = &device;	                            //- 표준출력으로 사용할 장치 설정

	TXT_LCD_Init();
	
	
	
	while(1)
	{
		
		Init_ADC();										//- ADC 초기화
		// 모드가 계속 바뀌기 때문에 Init을 안에 넣는다
		
		char result[20];
		
		AdcResult = startADConverter();				//- ADC 변환 실행
			
			
		if (mode == 1){
			printf("T %d",AdcResult);
			sprintf(result, " T = %d", AdcResult);
			SendText(DDRAM_ADDR | 0x00, result);
		}
		else if (mode == 0){
			printf("L %d",AdcResult);
			sprintf(result, " L = %d", AdcResult);
			SendText(DDRAM_ADDR | 0x00, result);
		}
		// 디스플레이 삭제
		_delay_ms(2000);
		SendCommand(CMD_CLEAR_DISPLAY);
		_delay_us(1000);
	}
}

/* == Main 함수 구현 ================================================================================= */
int main(void)
{
	fourth();
	

	return 0;
}




