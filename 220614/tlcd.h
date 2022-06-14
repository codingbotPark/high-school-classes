#ifndef __TLCD_H__
#define __TLCD_H__

#include <avr/io.h>
#include <util/delay.h>


/* ======================================== 모듈 제어용 정의 ========================================== */
//- LCD 제어 PORT & PIN ---------------------------------------------------------------------------
#define TLCD_DDR			DDRA		//- Data Bus 제어 Port
#define TLCD_PORT			PORTA

#define RS_BIT				PA0			//- Register Select : LOW - Command  HIGH - Data
#define RW_BIT				PA1			//- Read/Write      : LOW - Write    HIGH - Read
#define EN_BIT				PA2			//- Enable Pin      : LOW - Disable	 HIGH - Enable
#define DATA_D4				PA4			//- Data Bus PIN
#define DATA_D5				PA5
#define DATA_D6				PA6
#define DATA_D7				PA7

//- LCD 제어관련 상수 ------------------------------------------------------------------------------
#define ALL_SET				0xFF		//- 모든 Pin 1로 셋
#define ALL_CLEAR			0x00		//- 모든 Pin 0으로 클리어

#define DDRAM_ADDR 			0x80		//- DD(Display Data) RAM 주소

//- LCD 제어관련 명령어 ----------------------------------------------------------------------------
#define CMD_CLEAR_DISPLAY 	0x01		//- CLEAR_DISPLAY(0x01)
#define CMD_RETURN_HOME 	0x02		//- RETURN_HOME(0x02)

#define CMD_ENTRYMODE_SET 	0x06		//- ENTRYMODE_SET(0x04)|Left(0x02)|Shift Decrement(0x00)
#define CMD_DISPLAY_CONTROL 0x0C		//- DISPLAY_CONTROL(0x08)|Display On(0x04)|Cursor Off(0x00)|Blink Off(0x00)
#define CMD_CURSOR_SHIFT 	0x1C		//- CURSOR_SHIFT(0x10)|Shift Move(0x08)|Move Right(0x04)
#define CMD_FUNCTION_SET 	0x28		//- FUNCTION_SET(0x02)|4BIT(0x00)|2 Line(0x08)|5x8 Dots(0x00)
#define CMD_8BIT_MODE		0x03		//- FUNCTION_SET(0x02)|8BIT(0x01)
#define CMD_4BIT_MODE		0x02		//- FUNCTION_SET(0x02)|4BIT(0x00)

#define DDRAM_FS_ADDR		0x00		//- 첫번째 라인 커서 시작 주소
#define DDRAM_FE_ADDR		0x0F		//- 첫번째 라인 커서   끝 주소
#define DDRAM_SS_ADDR		0x40		//- 두번째 라인 커서 시작 주소
#define DDRAM_SE_ADDR		0x4F		//- 두번째 라인 커서   끝 주소
// ========================================= 함수 선언 ==============================================
void TXT_LCD_Init(void);
void TXT_LCD_Enable(void);
void TXT_LCD_Write(unsigned char nValue);

void Set4BitMode(void);
void SendText(unsigned char addrCommand, char *szText);
void SendCommand(unsigned char command);
void SendData(unsigned char data);

#endif