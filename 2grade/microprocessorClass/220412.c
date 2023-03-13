/*
 * ex220405.c
 *
 * Created: 2022-04-12 오후 1:55:28
 * Author : DGSW
 */ 

#include <avr/io.h>
#include <math.h>
#include <util/delay.h>
#define LED_DDR DDRE
#define LED_PORT PORTE // 출력
#define Switch_DDR DDRC // 방향(1이 출력 0이 입력)
#define Switch_PIN PINC // 입력

#define Seg_DDR DDRB
#define Seg_PORT PORTB

void first(void){
	LED_DDR = 0xff;
	LED_PORT = 0x00;
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;
	
	while(1){
		if (Switch_PIN == 0xfe){
			LED_PORT = 0xff;
		} else {
			LED_PORT = 0x00;
		}
	}
}

void second(void){
	Seg_DDR = 0xff;
	Seg_PORT = 0x00;
	int num[16] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x77, 0x7C, 0x39, 0x5e, 0x79, 0x71};
	while(1){
		for (int i = 0;i<16;i++){
			Seg_PORT = num[i];
			_delay_ms(500);
		}
	}
}

void third(void){
	Switch_DDR = 0x00;
	Switch_PIN = 0xff;
	Seg_DDR = 0xff;
	Seg_PORT = 0x00;
	while(1){
		switch(Switch_PIN){
			case (0xfe):
				Seg_PORT = 0x06;
				break;
			case (0xfd):
				Seg_PORT = 0x5b;
				break;
			case (0xfb):
				Seg_PORT = 0x4F;
				break;
			case (0xf7):
				Seg_PORT = 0x66;
				break;
			case (0xef):
				Seg_PORT = 0x6D;
				break;
			case (0xdf):
				Seg_PORT = 0x7D;
				break;
			case (0xbf):
				Seg_PORT = 0x07;
				break;
			case (0x7f):
				Seg_PORT = 0x7F;
		}
	}
}

int main(void)
{
	//first();
	second();
	//third();
	
	return 0;
}

