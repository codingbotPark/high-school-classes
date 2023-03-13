/*
* ex_Push.c
*
* Created: 2022-04-05 오후 2:02:49
* Author : DGSW
*/

// 누른 버튼 곳의 불빛 키고끄기

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#define LED_DDR DDRE
#define LED_PORT PORTE
#define Switch_DDR DDRC
#define Switch_PIN PINC
#define Buzz DDRD

int first(void){
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;
	
	while (1){
		LED_PORT = ~Switch_PIN;
	}
}

void second(void){
	// 부저를 0으로 함
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;
	Buzz = 0x00;
	
	while (1){
		if(Switch_PIN == 0xfe){
			Buzz = 0xff;
			} else if (Switch_PIN == 0xfd){
			Buzz = 0x00;
			} else {
			// 1/2가 아닐 때
		}
	}
	
	
}

int main(void)
{
	
	// DDR은 출력인지 입력인지를 정함 (1 = 출력 | 0 = 입력)
	// 그래서 LED는 1을 보두 넣어 출력으로 지정
	// Switch는 0을 모두 넣어 입력으로 지정
	//
	// PIN(입력)값을 ~not 비트연산자 로 바꾸어 PORT로 출력
	

	//first()
	second();
	
	
	return 0;
}


