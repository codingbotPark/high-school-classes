/*
* exLED.c
*
* Created: 2022-03-29 오후 3:12:17
* Author : DGSW
*/

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#define LED_DDR DDRE
#define LED_PORT PORTE // 출력
#define Switch_DDR DDRC // 방향(1이 출력 0이 입력)
#define Switch_PIN PINC // 입력
#define Seg_DDR DDRB
#define Seg_PORT PORTB
#define Buzz DDRD

int num[15] = { 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x77, 0x7C, 0x39, 0x5e, 0x79, 0x71};

void first();
void second();
void third();

int main(void)
{
	// 1번문제
	first();
	
	// 2번문제
	//second();
	
	// 3번문제
	//third();
	return 0;
}

// 세그먼트를 시작, 끝, 증가값 입력받아 제어
void printNum(int s, int e, int p){
	for (int i = s ; i < e;i+=p){
		Seg_PORT = num[i];
		_delay_ms(1000);
	}
}

void first(){
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;
	Seg_DDR = 0xff;
	Seg_PORT = 0x00;
	
	while(1){
		switch(Switch_PIN){
			case (0xfe):
				printNum(0,9,1);
				break;
			case (0xfd):
				printNum(1,8,2);
				break;
			case (0xfb):
				printNum(2,9,3);
				break;
			case (0xf7):
				printNum(9,15,1);
				break;
			case (0xef):
				Seg_PORT = 0x00;
		}
	}
}




void second(){
	LED_DDR = 0xff;
	LED_PORT = 0x01;
	
	//for (int i = 0;i<7;i++){
		//_delay_ms(1000);
		//if (i == 6){
			//Buzz = 0xff;
		//}
		//LED_PORT = LED_PORT << 1;
	//}
	//Buzz = 0x00;
	//for (int i = 0;i<7;i++){
		//_delay_ms(1000);
		//if (i == 6){
			//Buzz = 0xff;
		//}
		//LED_PORT = LED_PORT >> 1;
	//}
	//Buzz = 0x00;
	
	
	for (int i =0;i<7;i++){
		_delay_ms(1000);
		LED_PORT = (LED_PORT << 1) + 1;
	}
	Buzz = 0xff;
	_delay_ms(1000);
	Buzz = 0x00;
	for (int i = 0;i<8;i++){
		LED_PORT = LED_PORT >> 1;
		if (i == 7){
			Buzz = 0xff;
		}
		_delay_ms(1000);
	}
	Buzz = 0x00;
}


void third(){
	for (int i = 0;i<3;i++){
		Seg_DDR = 0xff;
		Seg_PORT = 0x06;
		LED_DDR = 0xff;
		LED_PORT = 0x01;
		for (int j = 2;j<9;j+=2){
			_delay_ms(1000);
			Seg_PORT = num[j];
			LED_PORT = (LED_PORT << 2) + 3;
		}
		// a출력
		Seg_PORT = num[9];
		LED_PORT = 0xff;
		_delay_ms(1000);
		
		// f출력
		Seg_PORT = num[14];
		LED_PORT = 0x00;
		_delay_ms(1000);
	}
}