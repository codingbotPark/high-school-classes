

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

char top[3][20];
char bottom[3][20];
int map[15][20] = { 0, };
int map1[15][20] = { 0, };

int r = 0;

void inputtop();//윗 요소를 입력하는 함수
void inputbottom();//아랫 요소를 입력하는 함수
void printtop();//위요소 출력
void printbottom();//아래 요소 출력
void printmap();//맵을 출력하는 함수
void markmap();//사다리타기 맵을 만드는, 표시하는 함수
void printvalue();
void printfinal();

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	printf("\n사다리타기 게임\n\n");

	inputtop();//위 요소 입력
	inputbottom();//아래 요소 입력

	markmap();//3개의 줄 만들기, 랜덤으로 다리 만들기

	//기본값
	printtop();
	printmap();
	printbottom();

	//첫번째 위 요소의 결과를 만들기
	printvalue();

	//첫번째 위 요소 결과 출력
	printtop();
	printmap();
	printbottom();

	//두번째 위 요소의 결과를 만들기
	printvalue();

	//두번째 위 요소 결과 출력
	printtop();
	printmap();
	printbottom();

	//세번째 위 요소의 결과를 만들기
	printvalue();

	//세번째 위 요소 결과 출력
	printtop();
	printmap();
	printbottom();



	return 0;
}










void inputtop()
{
	for (int i = 0; i < 3; i++)
	{
		printf("위 요소를 입력하세요( %d / 3 ) ", i + 1);
		scanf("%s", &top[i]);
	}
}

void inputbottom()
{
	for (int i = 0; i < 3; i++)
	{
		printf("아래 요소를 입력하세요 ( %d / 3 ) ", i + 1);
		scanf("%s", &bottom[i]);
	}
}

void printtop()
{
	printf("\n\n\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%13s", top[i]);
	}
	printf("\n");
}

void markmap()
{
	int c = 0;

	for (int i = 1; i <= 20; i++)
	{
		if (i % 6 == 0)
		{
			for (int j = 0; j < 15; j++)
			{
				map[j][i - 1] = 1;

				/*if (map[j][i] == 1 || map[j][i - 2] == 1)*/
				if (map[j][6] == 1 || map[j][10]
					|| j == 0 || j == 14)
				{
					continue;
				}


				if (!(rand() % 4))
				{
					if (i == 6)
					{
						for (int c = 0; c < 5; c++)
						{
							map[j][i + c] = 1;
						}
					}
					else
					{
						for (int c = 1; c <= 5; c++)
						{
							map[j][i - 1 - c] = 1;
						}
					}
				}
			}
		}
	}

	//배열 복사
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map1[i][j] = map[i][j];
		}
	}
}


void printmap()
{

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map1[i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xaa);
			}
			else if (map1[i][j] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xcc);
			}
			else if (map1[i][j] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
			}
			else if (map1[i][j] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xee);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
			}
			printf("■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
		}
		printf("\n");
	}
}

void printbottom()
{
	for (int i = 0; i < 3; i++)
	{
		printf("%13s", bottom[i]);
	}
	printf("\n");
	printf("\n");
}

//void printvalue()
//{
//	static int r = 0;
//	int temp;
//	int i = 0;
//	int j = 4;
//
//	map[i][j] == 2 + r;
//	while (1)
//	{
//		if (map[i][j + 1] == 1)
//		{
//			j += 1;
//			map[i][j] = 2 + r;
//			continue;
//		}
//		else if (map[i][j - 1] == 1)
//		{
//			j -= 1;
//			map[i][j] = 2 + r;
//			continue;
//		}
//		else if (map[i + 1][j] == 1)
//		{
//			i += 1;
//			map[i][j] = 2 + r;
//			continue;
//		}
//		break;
//	}
//}

void printvalue()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map1[i][j] = map[i][j];
		}
	}


	int i = 0;
	int j = 5 + (r * 6);

	map1[i][j] = 2 + r;
	while (1)
	{
		if (map1[i][j + 1] == 1)
		{
			j += 1;
			map1[i][j] = 2 + r;
			continue;
		}
		else if (map1[i][j - 1] == 1)
		{
			j -= 1;
			map1[i][j] = 2 + r;
			continue;
		}
		else if (map1[i + 1][j] == 1)
		{
			i += 1;
			map1[i][j] = 2 + r;
			continue;
		}
		break;
	}

	r += 1;
}

void printfinal()
{

}
