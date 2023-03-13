/*
 * 220607-1.c
 *
 * Created: 2022-06-07 오후 1:38:04
 * Author : user
 */ 

// 아날로그를 디지털로 변환할 때 10bit를 사용한다
 


#include <avr/io.h>

//unsigned int CDS_StartADConverter(){
	//unsigned int reulst;
	//cli(); // ADC 변환 중 인터럽트 금지
	//
	//ADCSRA |= (1<<ADSC);
	//while(!(ADCSRA & (1<<ADIF)));
	//
	//result = ADCL;
	//result |= ((ADCH & oxo3) << 8);
	//
	//sei();
	//
//}

#include "usart_printf.h"



int main(void)
{
	USART_Init();
	stdout = &device;
	
    /* Replace with your application code */
    while (1) 
    {
		printf("Hello Atmega128!\n");
		_delay_ms(1000);
    }
	return 0;
}

