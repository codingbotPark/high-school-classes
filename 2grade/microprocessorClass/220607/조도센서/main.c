/*
 * 220607-2.c
 *
 * Created: 2022-06-07 오후 2:41:43
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// 조도 센서
void Init_ADC(){
	// ADC1 채널, AREF 기준 전압 및 채널 선택
	ADMUX = 1;
	//
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

unsigned int CDS_StartADConverter(){
	unsigned int result;
	
	cli(); // ADC 변환 중 인터럽트 금지

	ADCSRA |= (1<<ADSC); // 변환 시작
	while(!(ADCSRA & (1<<ADIF))); // 변환이 완료될 때 까지 while
	
	result = ADCL; // 변환 결과 저장
	result |= ((ADCH & 0x03) << 8);
	sei(); // 인터럽트 허용
	
	return result;
}

int main(void)
{
	unsigned int AdcResult;
	
	Init_ADC(); // ADC초기화
	
    /* Replace with your application code */
    while (1) 
    {
		AdcResult = CDS_StartADConverter(); // ADC변환 실행
		printf(AdcResult);
		_delay_ms(5000);
    }
}

