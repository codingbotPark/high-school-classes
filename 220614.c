/*
 * 220614.c
 *
 * Created: 2022-06-14 오후 7:06:59
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

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

void second(){
	
	
}

int main(void)
{
	//first();
	second();
	
    /* Replace with your application code */
    
}




