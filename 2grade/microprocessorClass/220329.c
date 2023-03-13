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
#define LED_PORT PORTE

void first();
void second();
void third();

int main(void)
{
	// 전체 on/off 10번
	LED_DDR = 0xff;
	LED_PORT = 0xff;
	//first();
	//second();
    third();
	return 0;
}

void first(){
	for (int i = 0;i < 10;i++)
	{
		LED_DDR = 0xff; // 전체키고
		_delay_ms(3000);
		LED_DDR = 0x00; // 전체끈다
		_delay_ms(3000);
	}
}

void second(){
	int lights = 0x00;
	for (int i=0;i<8;i++){
		lights = (lights << 1) + 1;
		LED_DDR = lights;
		_delay_ms(1000);
	}
	for (int i =0;i<8;i++){
		lights = (lights >> 1);
		LED_DDR = lights;
		_delay_ms(1000);
	}
}

//void second(){
	//int lights = 0x01;
	//for (int i = 0;i<8;i++){
		//LED_DDR = lights += pow(2,i);
		//_delay_ms(1000);
	//}
	//for (int i = 0;i<8;i++){
		//LED_DDR = lights -= pow(2,i);
		//_delay_ms(1000);
	//}
//}

//void second(){
	//int lights = 0x01;
	//for (int i = 0;i<8;i++){
		//LED_DDR = lights += hi(i);
	//}
	//for (int i = 0;i<8;i++){
		//LED_DDR = lights -= hi(i);
	//}
//}
//int hi(int i){
	//int temp = 1;
	//for (int j = 0;j<i-1;j++){
		//temp *= 2;
	//}
	//return temp;
//}

void third(){
	DDRD = 0x00;
	int lights = 0x00;
	for (int i = 0;i<8;i++){
		lights = (lights << 1) + 1;
		LED_DDR = lights;
		if (i % 2 == 0){
			DDRD = 0xff;
		} else {
			DDRD = 0x00;
		}
		_delay_ms(1000);
	}
}
