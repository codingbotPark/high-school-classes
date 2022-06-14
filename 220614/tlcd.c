/*
 * tlcd.c
 *
 * Created: 2021-11-05 오전 8:25:22
 *  Author: anece
 */ 

#include "tlcd.h"

//- TXT LCD 초기화 함수 구현 -----------------------------------------------------
void TXT_LCD_Init(void)
{
	//------ (1) TXT_LCD_Init 제어 Port 설정 및 초기화
	//- TXT_LCD 제어 Pin Output 설정 및 초기화
	TLCD_DDR  = ALL_SET;
	TLCD_PORT = ALL_CLEAR;
	
	_delay_us(50000);

	//------ (2) TXT LCD 인터페이스 설정
	Set4BitMode();
	
	//------ (3) TXT LCD 출력을 위한 설정
	//- LCD의 행, 열 , 글자 크기 설정
	SendCommand(CMD_FUNCTION_SET);
	_delay_us(2000);
	
	//- 디스플레이, 커서, 문자 깜빡임 On/Off 설정
	SendCommand(CMD_DISPLAY_CONTROL);
	_delay_us(2000);
	
	//- 커서 이동 방향, 문자 디스플레이 이동 여부 설정
	SendCommand(CMD_ENTRYMODE_SET);
	_delay_us(2000);
	
	//- LCD 화면 지우고 커서는 1행 1열 위치, DDRAM AC=0
	SendCommand(CMD_CLEAR_DISPLAY);
	_delay_us(2000);
}


//- TXT_LCD 4bit 인터페이스 설정 구현 ---------------------------------------------
void Set4BitMode(void)
{
	//- Command 전송을 위한 RS=0, RW=0, EN=0
	TLCD_PORT &= ~((1<<RS_BIT)|(1<<RW_BIT)|(1<<EN_BIT));

	TXT_LCD_Write(CMD_8BIT_MODE);
	_delay_us(4500);

	TXT_LCD_Write(CMD_8BIT_MODE);
	_delay_us(4500);
	
	TXT_LCD_Write(CMD_8BIT_MODE);
	_delay_us(150);
	
	TXT_LCD_Write(CMD_4BIT_MODE);
}


//- LCD 문자열 출력 함수 구현 ------------------------------------------------------------------------
void SendText(unsigned char addrCommand, char *szText)
{
	SendCommand(addrCommand);   //- DD Ram 주소 전달

	//- Data 전달
	while(*szText != '\0')
	{
		SendData(*szText);
		szText++;
	}
}


//- RBG_LCD 명령어 전달 함수 구현 ------------------------------------------------------------------------
void SendCommand(unsigned char command)
{
	//- Command 전송을 위한  RS=0, RW=0, EN=0
	TLCD_PORT  &= ~( (1<<RS_BIT)|(1<<RW_BIT)|(1<<EN_BIT));

	//- Data Bus에 CMD 쓰기
	TXT_LCD_Write(command>>4);
	TXT_LCD_Write(command);
}


//- RBG_LCD 데이터 전달 함수 구현 ------------------------------------------------------------------------
void SendData(unsigned char data)
{
	//- Data 전송을 위한  RS=1, RW=0, EN=0
	TLCD_PORT  |=   (1<<RS_BIT);
	TLCD_PORT  &= ~((1<<RW_BIT) | (1<<EN_BIT));

	TXT_LCD_Write(data>>4);
	TXT_LCD_Write(data);
}


//- LCD 명령어/데이터 레지스터 기록 구현 ---------------------------------------------------------------
void TXT_LCD_Write(unsigned char nValue)
{
	int nTmp  =  0;
	TLCD_PORT &= ~((1<<DATA_D4)|(1<<DATA_D5)|(1<<DATA_D6)|(1<<DATA_D7));

	for (int nIdx = 0; nIdx < 4; nIdx++)
	{
		nTmp = (nValue>>nIdx) & 0x01;
		TLCD_PORT |=  ( nTmp << (DATA_D4+nIdx) );
	}
	TXT_LCD_Enable();
}



//- LCD 모듈 활성/비활성 구현 ------------------------------------------------------------------------
void TXT_LCD_Enable(void)
{
	TLCD_PORT &=  ~(1<<EN_BIT);   //- LOW - Disable
	_delay_us(1);
	
	TLCD_PORT |=  (1<<EN_BIT);	  //- HIGH - Enable
	_delay_us(1);

	TLCD_PORT &=  ~(1<<EN_BIT);    //- LOW - Disable
	_delay_us(100);
}