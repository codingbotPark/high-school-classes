#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_DDR DDRB
#define LED_PORT PORTB

int LED_Flag = 0;

// 인터럽트 트리거 방식에는
// 0 0 = low일 때
// 0 1 = 상승
// 1 0 = 하강
// 1 1 = high일 때
void init_EINT(){
	EICRB |= ((1<<ISC41) | (0<<ISC40));
	EIMSK |= (1<<INT4);
	EICRB |= ((1<<ISC51) | (0<<ISC50));
	EIMSK |= (1<<INT5);
}

// 4번을 확인해준다
ISR(INT4_vect){
	LED_Flag = 0;
	LED_PORT = 0xff;
}
ISR(INT5_vect){
	LED_Flag = 1;
	LED_PORT = 0x00;
}

int main(void)
{
	/* Replace with your application code */
	
	LED_DDR = 0xff;
	LED_PORT = 0xff;

	// 기본적인 설정 함수 실행
	init_EINT();
	
	// 기본적인 인터럽트 확인은 꺼져있기 때문에
	// sei로 인터럽트를 활성화 해준다?
	sei();

	while (1)
	{
		
	}
	return 0;
}

