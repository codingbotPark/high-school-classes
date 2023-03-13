/*
 * usart_printf.h
 *
 * Created: 2021-10-25 오전 7:40:00
 *  Author: anece
 */ 


#ifndef USART_PRINTF_H_
#define USART_PRINTF_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

// == USART 제어를 위한 정의
#define	BAUD_RATE	51                                      //- ATmega128 데이터 시트 51(19200bps) 값 참조

//- USART 표준 출력 제어를 위한 정의 --------------------------------------------------
int USART1_putchar(char txData, FILE *stream);

static FILE device=FDEV_SETUP_STREAM(USART1_putchar, NULL, _FDEV_SETUP_WRITE);





//char USART1_getchar(FILE *stream);
//static FILE in_device=FDEV_SETUP_STREAM(NULL, USART1_getchar, _FDEV_SETUP_READ);

// == USART 초기화 함수
void USART_Init();

// == USART Interrupt 함수
ISR(USART1_RX_vect);

void USART_Transmitter(unsigned char txData);


#endif /* USART_PRINTF_H_ */