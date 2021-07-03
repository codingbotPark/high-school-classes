//과정 15
//
// 포춘카드 (4, 12, 20, 28 번째 땅) 전체 완성
// 한번 더 주사위 굴리기 (2차 심자)
// 선택한 상대 땅을 파괴시키기 (화재상황발생) -오류수정-
// 무인도에 가기 (기말고사)
// 현재플레이어의 가장 싼 땅과 다른 플레이어의 가장 비싼 땅을 바꾸기 (튜티튜터)
// 귀가버스로 이동(복귀)
// 기숙사로 이동(점호)
// 체육관으로 이동(택견)
// 다른 플레이어들의 돈의 10%를 받음(생일)
// 운동장으로 모든플레이어가 모임(축구)
// 
// 7번 땅 이름 변경 (미술실 -> 무인택배함)
// 
// 줄넘기기(\n)를 
// 의미가 비슷한 문장끼리는 바로다음에
// 의미가 다른 문장이 나오면 한 줄을 비우고 출력되도록 수정
// 
// 
//  
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define CLS system("cls")

struct PLAYER
{
	int money;//플레이어의 돈
	int location;//플레이어의 위치
	int count;
};
struct MAP
{
	int building[32];//빌딩의 개수
	int who[32];//빌딩의 소유자
	int cost[32];
};

int map[37][37] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 10, 0, 1, 0, 11, 0, 1, 0, 12, 0, 1, 0, 13, 0, 1, 0, 14, 0, 1, 0, 15, 0, 1, 0, 16, 0, 1, 0, 17, 0, 1, 0, 18, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 20, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 21, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 22, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 23, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 25, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 2, 0, 1, 0, 33, 0, 1, 0, 32, 0, 1, 0, 31, 0, 1, 0, 30, 0, 1, 0, 29, 0, 1, 0, 28, 0, 1, 0, 27, 0, 1, 0, 26, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

//그냥 수를 넣으면 벽과 겹치기 때문에 2가 플러스된 수를 사용해
//출력할 때는 -2를 해서 활용한다

int DICE[2][5][5] = { 0, };


struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };


void TURN();
//플레이어의 수를 받아서 순서를 정하는 함수
int dice();
//주사위를 돌리는 함수
void GS(int s);//gamesetting
//게임이 시작되기 전 세팅
int judge(int s);
//어떤 상황인지 판단하는 함수(내땅인지 상대땅인지 등)
int CM(int s);//changingmoney
//어떤 상황에 따라 돈을 + - 하는 함수
void BB(int s);//buildingbuilding
//상황에 따라 빌딩을 짓는 함수
int YORN(int s);
//상황에 따라 Y또는N을 받아서 1또는 0을 반환하는 함수
void GF(int s);//gamefuntion
//게임의 기능(파산한사람의 순서를 넘기기)
//int END(int s);
//게임의 끝일 상황을 판단하는 함수
void CBC(int s);//changingbuildingcost
//건물을 지을 때 마다 땅의 가격을 바꾸는 함수
void CW(int s);//changingwho
//상황에 따라 건물의 소유자를 바꾸는 함수
void SP();//specialplace
//상황에 따라 무인도, 올림픽개최, 세계여행등
void PM();// printmap
//맵 출력 함수
int SA();//specialaction
//specialplace에 갔을 때 특수한 행동
//void PD();//printdice
////주사위의 수에 따라 모양을 출력하는 함수
//void MD();//makedice
////dice의 수에 따라 출력하는 주사위의 모양을 바꾸는 함수
void FC();//fortunecard
//포춘카드를 랜덤으로 뽑고 불러주는 함수

int i = 0;//main for문에서 사용되는 변수
int n = 0;//플레이어의 수
int random[4];//순서
char YorN;//아무키나 눌러 넘기기 / Y or N
int DorS;//더블인지 아닌지
int BN;//지을 건물의 개수
int choice;//선택하는 건물(올림픽 개최, 세계 여행 등)
char buildingname[32][20] = { "정문", "운동장", "체육관", "사회전용실", "포춘카드",
"수학전용실", "시청각실", "무인택배함", "기숙사", "방송실","창의공작실",
"모바일프로그래밍실", "포춘카드", "윈도우프로그래밍실", "오케스트라실", "도서관",
"급식실", "언턴드","스타봇", "세븐랩스", "포춘카드", "CnS", "ducami", "b1nd", "귀가 버스",
"사감실", "교장실", "재덕정", "포춘카드", "대니산", "1학년1반", "박병관" };
//빌딩의 이름
int cnt = 0;//파산한 사람의 수 +
int Dice[2] = { 0, };//주사위 1, 2
char fortunecard[10][20] = { "2차 심자", "화재상황발생", "기말고사",
"튜티튜터", "외박", "복귀", "점호", "택견", "생일","축구" };

int main()
{
	srand((unsigned)time(NULL));
	GS(2);//풀스크린
	GS(1);//빌딩값 초기화
	TURN();//순서 정하기
	GS(0);//순서그대로 플레이어 돈 초기화
	for (i = 0; i < n; i++)
	{
		GF(0);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t%d번 플레이어 차례\n\n", random[i]);
		if (PLAYER[random[i]].count != 0)//특별한 장소에 있을 때 주사위를 돌리지 않는다
		{
			if (SA())
			{
				PM();
				continue;//무인도일 때 순서 넘기기
			}
		}
		else
		{
			dice();
		}
		if (judge(3))//특수한 지역일 때
		{
			if (judge(4))
			{
				SP();
			}
			else
			{
				FC();//포춘카드
				if (judge(4))//포춘카드에서 특수한 장소가 나올 때(무인도 등)
				{
					SP();
				}
			}
		}
		else//특수한 지역이 아닐 때
		{
			if (judge(0))// 상대땅인지 아닌지 판별 아니면
			{
				if (!(judge(1)))//랜드마크인지 아닌지 아니라면
				{
					if (!(judge(2)))//건물이 3개 미만일 때
					{
						if (YORN(0))//건설할 때
						{
							BB(0);
							CW(0);
						}
					}
					else//건물이 3개일 때
					{
						if (YORN(1))//랜드마크를 지을 것인가
						{
							BB(1);
						}
					}
					if (CM(0))//짓는 건물의 개수에 따라 
					{
						continue;
					}
					CBC(0);//건물을 지음에 따라 땅의 가격을 바꿔주기
				}
				//else 랜드마크라면 넘기기
			}
			else // 맞으면
			{
				if (CM(1))//일단 돈을 내고
				{
					continue;
				}
				if (!(judge(1)))//랜드마크가 아니라면(인수가 가능하다면)
				{
					if (YORN(2))//인수를 할 것인가? 맞다면
					{
						if (CM(2))
						{
							continue;
						}
						CW(0);
						if (YORN(0))//건물을 추가로 지을건지 아닌지 맞으면
						{
							if (judge(2))//인수한 땅의 건물이 3개인지 아닌지 맞으면
							{
								if (YORN(1))//랜드마크를 지을거면
								{
									BB(1);
									if (CM(0))
									{
										continue;
									}
								}
							}
							else//아니면
							{
								BB(0);
								if (CM(0))
								{
									continue;
								}
							}
						}
						//else
					}
				}
			}
		}
		//Sleep(1000);
		//CLS;
		PM();
		//END(0);//더블사이에 끝이 날 수도 있다
		if (DorS)//더블일 때 한번 더
		{
			i--;
			continue;//continue가 쓰여서
			//함수에 넣게되면 더 길어진다
		}
		GF(1);//순서돌리기
	}

	return 0;
}

void TURN()
{
	while (1)
	{
		printf("\n=========================================================================================================================");
		printf("====================================================================\n");
		printf("\t\t\t\t\t\t\t\t\t플레이어의 수를 입력하세요(2~4) ");
		scanf("%d", &n);
		if (n > 1 && n < 5)
		{
			break;
		}
		printf("\n\t\t\t\t\t\t\t\t\t2명 이상, 4명 이하의 플레이어 수를 입력해주세요\n");
	}
	printf("\t\t\t\t\t\t\t\t각자 번호를 정하세요 (다 정했으면 아무키나 입력해 주세요) ");
	scanf(" %c", &YorN);
	for (int x = 0; x < n; x++)
	{
		random[x] = rand() % n + 1;
		for (int y = 0; y < x; y++)
		{
			if (random[y] == random[x])
			{
				random[x] = rand() % n + 1;
				y = -1;
			}
		}
		printf("\n\t\t\t\t\t\t\t\t\t\t%d번째순서 = %d번 플레이어 ", x + 1, random[x]);
		if (x == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
		}
		else if (x == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
		}
		else if (x == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x66);
		}
		else if (x == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
		}
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		printf("\n");
	}
	printf("=========================================================================================================================");
	printf("====================================================================");
}

int dice()
{
	DorS = 0;//더블인지아닌지 판단하는 변수를 초기화
	int power;
	while (1)
	{
		printf("\n\t\t\t\t\t\t\t\t\t주사위 강도를 입력해주세요(1~5) ");
		scanf("%d", &power);
		if (power > 0 && power < 6)
		{
			break;
		}
		printf("\n\t\t\t\t\t\t\t\t\t   1이상 5이하의 수를 입력해주세요\n");
		continue;
	}
	Dice[0] = rand() % 2 + power;
	Dice[1] = rand() % 6 + 1;
	if (Dice[0] == Dice[1])
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t\t  더블!\n");
		DorS = 1;
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t  주사위 = %d %d\n", Dice[0], Dice[1]);
	PLAYER[random[i]].location += (Dice[0] + Dice[1]);
	if (PLAYER[random[i]].location > 31)
	{
		PLAYER[random[i]].location -= 32;
		PLAYER[random[i]].money += 60;
		printf("\n\t\t\t\t\t\t\t\t\t\t      월급 지급!\n");
	}
	printf("\n\t\t\t\t\t\t\t\t\t%20s 도착!\n", buildingname[PLAYER[random[i]].location]);
	printf("\n\t\t\t\t\t\t\t\t\t      %d번 플레이어의 위치 = %d\n", random[i], PLAYER[random[i]].location);
}


void GS(int s)
{
	if (s == 0)
	{
		for (int x = 0; x < n; x++)
		{
			PLAYER[random[x]].money = 400;
		}
	}
	else if (s == 1)//빌딩가격을 칸 * 2로 초기화
	{
		for (int x = 0; x < 32; x++)
		{
			MAP.cost[x] = 2 * x;
		}
	}
	else if (s == 2)
	{
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	}
}
void GF(int s)
{
	if (s == 0)//파산한 플레이어를 뛰어 넘는 상황
	{
		if (PLAYER[random[i]].money <= 0)
		{
			if (i == n - 1)//i가 마지막일 때
			{
				i = -1;
			}
			i++;
		}
	}
	if (s == 1)
	{
		if (i == n - 1)//순서돌리기
		{
			i = -1;
		}
	}
}

int judge(int s)
{
	if (s == 0)//상대땅인지 아닌지 판단
	{
		if (MAP.who[PLAYER[random[i]].location] != random[i] && MAP.building[PLAYER[random[i]].location] != 0)//상대땅일 때
		{
			return 0;
		}
		else//건설 할 수 있을 때
		{
			return 1;
		}
	}
	else if (s == 1)//랜드마크인지 아닌지 판단
	{
		if (MAP.building[PLAYER[random[i]].location] == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (s == 2)//건물이 3개인지 3개 미만인지 판단(랜드마크건설)
	{
		if (MAP.building[PLAYER[random[i]].location] == 3)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (s == 3)//특수한 지역인지 아닌지 판단(무인도 등)
	{
		if (PLAYER[random[i]].location == 8 ||
			PLAYER[random[i]].location == 16 ||
			PLAYER[random[i]].location == 24 ||
			PLAYER[random[i]].location == 0 ||
			PLAYER[random[i]].location == 4 ||//포춘카드
			PLAYER[random[i]].location == 12 ||
			PLAYER[random[i]].location == 20 ||
			PLAYER[random[i]].location == 28)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (s == 4)//포춘카드와 다른 특수한 지역을 나누는 함수
	{
		if (PLAYER[random[i]].location == 8 ||
			PLAYER[random[i]].location == 16 ||
			PLAYER[random[i]].location == 24 ||
			PLAYER[random[i]].location == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


int CM(int s)
{
	if (s == 0)//아무것도 없을 때 건설
	{
		//PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];
		//건물을 지을 때 마다 더 비싸게 주고 건물을 지어야함
		PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
	}
	else if (s == 1)//통행료
	{
		PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[PLAYER[random[i]].location];//건물주인
	}
	else if (s == 2)//인수료
	{
		PLAYER[random[i]].money -= PLAYER[random[i]].location * 2;//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += PLAYER[random[i]].location * 2;//건물주인
		//MAP.cost[PLAYER[random[i]].locaiton]하지 않고 위치 * 2를 하는 이유는
		//올림픽 개최로 인해 MAP.cost가 올라가면 인수 할 때 cost가 올라간 채로 인수가 되기때문에
	}
	if (PLAYER[random[i]].money < 0)//파산확인
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t%d번 플레이어 파산\n\n", random[i]);
		cnt++;
		for (int x = 1; x < 32; x++)
		{
			if (MAP.who[x] == random[i])//지도를 비교해서 파산한 사람의 땅을 모두 없앤다
			{
				MAP.who[x] = 0;
				MAP.building[x] = 0;
				for (int p = 2; p < 35; p += 4)
				{
					for (int P = 2; P < 35; P += 4)
					{
						if (map[p][P] == x + 2 || map[p][P] == x + 38)//map의 번호와 배열의 땅 번호를 비교
						{
							for (int k = 0; k < 3; k++)
							{
								for (int K = 0; K < 3; K++)
								{
									if (k == 1 && K == 1)//중간칸은 복구
									{
										map[p][P] = x + 2;
										continue;
									}
									map[p + 1 - k][P - 1 + K] = 0;
								}
							}
						}
					}
				}
			}
		}
		if (cnt == n - 1)//게임이 끝날 때
		{
			for (int x = 0; x < n; x++)
			{
				if (PLAYER[random[x]].money > 0)
				{
					printf("\n=========================================================================================================================");
					printf("====================================================================\n");
					printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t%d번 플레이어 승리!\n\n\n\n", random[x]);
					printf("=========================================================================================================================");
					printf("====================================================================");
					exit(1);
				}
			}
		}
		return 1;
	}
	return 0;
}

void BB(int s)
{
	if (s == 0)
	{
		while (1)
		{
			printf("\n\t\t\t\t\t\t\t\t몇 개의 건물을 짓겠습니까? (추가로 지을 건물의 개수 1~3)  ");
			scanf("%d", &BN);
			if (BN + MAP.building[PLAYER[random[i]].location] >= 4 || BN <= 0 || BN > 3)
			{
				printf("\n\t\t\t\t\t\t\t\t    건물의 개수가 잘못 되었습니다 (초과 / 미만 등의 이유)\n");
				continue;
			}
			else
			{
				MAP.building[PLAYER[random[i]].location] += BN;
				for (int x = 2; x < 35; x += 4)
				{
					for (int y = 2; y < 35; y += 4)
					{
						if (PLAYER[random[i]].location == map[x][y] - 2)
						{
							for (int p = 0; p < MAP.building[PLAYER[random[i]].location]; p++)
							{
								for (int P = 0; P < 3; P++)
								{
									if (p == 1 && P == 1)
									{
										continue;
									}
									//map[x-1+p][y-1+P] = 34+i;//맵을 만드는 데 0과 1을 사용해서
									map[x + 1 - p][y - 1 + P] = 34 + i;//맵을 만드는 데 0과 1을 사용해서
									//9칸 중 왼쪽 아래에서 부터
									//땅의 번호를 적는데 33까지사용
									//땅의 소유를 표현하기 위해 34~37까지 사용
									//random[i]가 번호임을 활용해서 33+random[i];
								}
							}
							x = 36;
							y = 36;
						}
					}
				}
				break;
			}
		}
	}
	else if (s == 1)
	{
		MAP.building[PLAYER[random[i]].location] = 4;
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t***%s 건설***\n\n\n\n", buildingname[PLAYER[random[i]].location]);
		BN = 1;//빌딩넘버를 1로 맞춰서 가격이 건물 하나를 지을 때와 같이 올라가도록 하기
		for (int x = 2; x < 35; x += 4)
		{
			for (int y = 2; y < 35; y += 4)
			{
				if (PLAYER[random[i]].location == map[x][y] - 2)
				{
					map[x][y] += 36;
					break;
				}
			}
		}
	}
}

int YORN(int s)
{
	while (1)
	{
		if (s == 0)
		{
			printf("\n\t\t\t\t\t\t\t\t\t     건물을 짓겠습니까? (y / n) ");
		}
		else if (s == 1)
		{
			printf("\n\t\t\t\t\t\t\t\t\t     랜드마크를 짓겠습니까? (y / n) ");
		}
		else if (s == 2)
		{
			printf("\n\t\t\t\t\t\t\t\t\t    건물을 인수하시겠습니까? (y / n) ");
		}
		scanf(" %c", &YorN);
		if (YorN == 'Y' || YorN == 'y')
		{
			return 1;
		}
		else if (YorN == 'N' || YorN == 'n')
		{
			return 0;
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t\t Y(y)또는 N(n)중 하나의 문자를 입력해주세요\n");
		}
	}
}

//int END(int s)
//{
//	if (s == 0)
//	{
//		cnt = 0;
//		for (int x = 0; x < n; x++)
//		{
//			if (PLAYER[random[x]].money <= 0)
//			{
//				cnt++;
//			}
//		}
//		if (cnt == n - 1)
//		{
//			return 1;
//		}
//		return 0;
//	}
//}


void CBC(int s)
{
	if (s == 0)//그냥 건물을 지을 때(+로 가격 올리기)
	{
		MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
	}
}

void CW(int s)
{
	if (s == 0)
	{
		MAP.who[PLAYER[random[i]].location] = random[i];
		for (int x = 2; x < 35; x += 4)
		{
			for (int y = 2; y < 35; y += 4)
			{
				if (PLAYER[random[i]].location == map[x][y] - 2)
				{
					//색변경
					for (int x = 2; x < 35; x += 4)
					{
						for (int y = 2; y < 35; y += 4)
						{
							if (PLAYER[random[i]].location == map[x][y] - 2)
							{
								for (int p = 0; p < MAP.building[PLAYER[random[i]].location]; p++)
								{
									for (int P = 0; P < 3; P++)
									{
										if (p == 1 && P == 1)
										{
											continue;
										}
										//map[x-1+p][y-1+P] = 34+i;//맵을 만드는 데 0과 1을 사용해서
										map[x + 1 - p][y - 1 + P] = 34 + i;//맵을 만드는 데 0과 1을 사용해서
										//9칸 중 왼쪽 아래에서 부터
										//땅의 번호를 적는데 33까지사용
										//땅의 소유를 표현하기 위해 34~37까지 사용
										//random[i]가 번호임을 활용해서 33+random[i];
									}
								}
								x = 36;
								y = 36;
							}
						}
					}
				}
			}
		}
	}
}

void SP()
{
	choice = 0;
	if (PLAYER[random[i]].location == 8)
	{
		DorS = 0;
		printf("\n\t\t\t\t\t\t\t\t\t   2턴 뒤에 다시 플레이가 가능합니다\n");
		PLAYER[random[i]].count = -1;
	}
	else if (PLAYER[random[i]].location == 16)
	{
		int x = 0;
		for (x = 0; x < 32; x++)
		{
			if (MAP.who[x] == random[i])
			{
				while (1)
				{
					printf("\n\t\t\t\t\t\t선택한 땅의 가격이 2배가 됩니다(현재 플레이어의 땅 / 중복선택시 2배) ");
					scanf("%d", &choice);
					if (random[i] != MAP.who[choice] || choice < 0 || choice > 31)
					{
						printf("\n\t\t\t\t\t\t\t\t가능한 땅이 아닙니다\n");
						continue;
					}
					MAP.cost[choice] *= 2;
					printf("\t\t\t\t\t\t\t\t\t\t%s 가격 2배 성공\n", buildingname[choice]);
					break;
				}
				break;
			}
		}
		if (x > 31)
		{
			printf("\n\t\t\t\t\t\t\t\t\t     선택 가능한 땅이 없습니다\n");
		}
	}
	else if (PLAYER[random[i]].location == 24)
	{
		DorS = 0;
		PLAYER[random[i]].count = 1;
		printf("\n\t\t\t\t\t\t\t\t     다음턴에 선택한 땅으로 이동할 수 있습니다\n");
	}
	else if (PLAYER[random[i]].location == 0)
	{
		if (YORN(0))
		{
			int x = 0;
			for (x = 0; x < 32; x++)
			{
				if (MAP.who[x] == random[i])
				{
					while (1)//건설할 수 있는 땅이 있을 때
					{
						printf("\n\t\t\t\t\t\t\t\t\t  선택한 땅을 추가 건설할 수 있습니다 ");
						scanf("%d", &choice);
						if (choice < 32 && choice > 0 && MAP.who[choice] == random[i] && MAP.building[choice] != 4)
							//선택한 땅이 범위 안, 자기땅, 랜드마크가 아닐 때
						{
							if (MAP.building[choice] == 3)//랜드마크
							{
								MAP.building[choice] = 4;
								printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t***%s 건설***\n\n\n\n", buildingname[choice]);
								BN = 1;//빌딩넘버를 1로 맞춰서 가격이 건물 하나를 지을 때와 같이 올라가도록 하기
								//랜드마크 색 변경
								for (int p = 2; p < 35; p += 4)
								{
									for (int P = 2; P < 35; P += 4)
									{
										if (choice == map[p][P] - 2)
										{
											map[p][P] += 36;
											break;
										}
									}
								}
							}
							else//그냥 건물
							{
								//건물의 개수
								while (1)
								{
									printf("\t\t\t\t\t\t\t\t\t몇 개의 건물을 짓겠습니까? (추가로 지을 건물의 개수) ");
									scanf("%d", &BN);
									if (BN + MAP.building[choice] > 4 || BN <= 0 || BN > 3)
									{
										printf("\n\t\t\t\t\t\t\t건물의 개수가 잘못 되었습니다 (초과 / 미만 등의 이유)\n");
										continue;
									}
									else
									{
										MAP.building[choice] += BN;
										for (int x = 2; x < 35; x += 4)
										{
											for (int y = 2; y < 35; y += 4)
											{
												if (choice == map[x][y] - 2)
												{
													for (int p = 0; p < MAP.building[choice]; p++)
													{
														for (int P = 0; P < 3; P++)
														{
															if (p == 1 && P == 1)
															{
																continue;
															}
															map[x + 1 - p][y - 1 + P] = 34 + i;
														}
													}
													x = 36;
													y = 36;
												}
											}
										}
										break;
									}
								}
							}
							PLAYER[random[i]].money -= (BN * choice);
							MAP.cost[choice] += (BN * choice);
							//플레이어의 돈 -
							//건물의 가격 +



							//if (PLAYER[random[i]].money -= BN * PLAYER[random[i]].location > 0)
							//{
							//	PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
							//}

							//if (s == 0)//그냥 건물을 지을 때(+로 가격 올리기)
							//{
							//	MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
							//}
							break;
						}
						printf("\n\t\t\t\t\t\t\t\t\t건설할 수 없는 땅입니다\n");
					}
					break;
				}
			}
			if (x > 31)
			{
				printf("\n\t\t\t\t\t\t\t\t\t    선택 가능한 땅이 없습니다\n");
			}
		}
	}
	else if
		(PLAYER[random[i]].location == 4 ||
			PLAYER[random[i]].location == 12 ||
			PLAYER[random[i]].location == 20 ||
			PLAYER[random[i]].location == 28)
	{

	}
}

void PM()
{
	int CC = 0;
	printf("\n\n");
	//for (int p = 0; p < n; p++)
	//{
	//	for (int x = 0; x < 37; x++)//플레이어의 위치를 나타내기
	//	{
	//		for (int y = 0; y < 37; y++) 
	//		{
	//			if (PLAYER[random[p]].location + 2  == map[x][y]  || PLAYER[random[p]].location + 36 == map[x][y])
	//			{
	//				//36 + 33 = 69 즉 map에서 70부터 사용 가능
	//				if (p == 1)
	//				{
	//					map[x-1][y-1] = 69 + 1;//순서대로 +
	//				}
	//				else if (p == 2)
	//				{
	//					map[x-1][y+1] = 69 + 2;//순서대로 +
	//				}
	//				else if (p == 3)
	//				{
	//					map[x+1][y-1] = 69 + 3;//순서대로 +
	//				}
	//				else if (p == 4)
	//				{
	//					map[x+1][y+1] = 69 + 4;//순서대로 +
	//				}
	//			}
	//		}
	//	}
	//}
	for (int x = 0; x < 37; x++)
	{
		printf("\t\t\t\t\t\t\t");
		for (int y = 0; y < 37; y++)
		{
			if (map[x][y] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
				printf("□");
			}
			else if (map[x][y] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
				printf("■");
			}
			else if (map[x][y] > 1 && map[x][y] < 12)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("%d ", map[x][y] - 2);
			}
			else if (map[x][y] > 9 && map[x][y] < 34)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("%d", map[x][y] - 2);
			}
			else if (map[x][y] == 34)//첫번째 순서의 플레이어 = 빨간색 (33+1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 12 << 4);
				printf("■");
			}
			else if (map[x][y] == 35)//두번째 순서의 플레이어 = 파란색
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 | 9 << 4);
				printf("■");
			}
			else if (map[x][y] == 36)//세번째 순서의 플레이어 = 노란색
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | 6 << 4);
				printf("■");
			}
			else if (map[x][y] == 37)//네번째 순서의 플레이어 = 초록색
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 10 << 4);
				printf("■");
			}
			else if (map[x][y] > 37 && map[x][y] < 70)//랜드마크일 때
			{
				//map[x][y] - 36;
				if (map[x][y + 1] == 34)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
				}
				else if (map[x][y + 1] == 35)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x9F);
				}
				else if (map[x][y + 1] == 36)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6F);
				}
				else if (map[x][y + 1] == 37)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAF);
				}
				if (map[x][y] < 48)//한자리 수 일때
				{
					printf(" %d", map[x][y] - 38);
				}
				else
				{
					printf("%d", map[x][y] - 38);
				}
			}
			//else if (map[x][y] > 69 || map[x][y] < 74)
			//{
			//	if (map[x][y] == 70)//빨간색
			//	{
			//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 12 << 4);
			//		printf("■");
			//	}
			//	else if (map[x][y] == 71)
			//	{
			//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 | 9 << 4);
			//		printf("■");
			//	}
			//	else if (map[x][y] == 72)
			//	{
			//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | 6 << 4);
			//		printf("■");
			//	}
			//	else if (map[x][y] == 73)
			//	{
			//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 10 << 4);
			//		printf("■");
			//	}
			//	map[x][y] = map[x + 1][y];//위치를 나타내고 값을 초기화
			//}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("\n\n");
	for (int x = 0; x < n; x++)//플레이어의 정보
	{
		printf("\n\t\t\t\t\t\t\t\t%d번 플레이어의 자산 %5.d만원\t위치 = %d\t", random[x], PLAYER[random[x]].money, PLAYER[random[x]].location);
		if (x == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
		}
		else if (x == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
		}
		else if (x == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x66);
		}
		else if (x == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
		}
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	}

}

int SA()
{
	if (PLAYER[random[i]].location == 8)
	{
		printf("\n\t\t\t\t\t\t\t\t\t   %d턴 뒤에 플레이 가능합니다\n", 2 + PLAYER[random[i]].count);
		PLAYER[random[i]].count++;
		if (i == n - 1)
		{
			i = -1;
		}
		Sleep(1500);
		return 1;
	}
	else if (PLAYER[random[i]].location == 24)
	{
		while (1)
		{
			printf("\n\t\t\t\t\t\t\t\t\t     선택한 땅으로 이동합니다 ");
			scanf("%d", &choice);
			if (choice > 32 || choice < 0 || choice == 24)
			{
				printf("\n\t\t\t\t\t\t\t\t\t\t이동 가능한 땅이 아닙니다\n");
				continue;
			}
			if (choice >= 0 && choice < 24)
			{
				PLAYER[random[i]].money += 60;
				printf("\n\t\t\t\t\t\t\t\t\t\t      월급 지급!\n");
			}
			PLAYER[random[i]].location = choice;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t 이동성공");
			printf("\n\t\t\t\t\t\t\t\t\t%20s 도착!\n", buildingname[PLAYER[random[i]].location]);
			break;
		}
		PLAYER[random[i]].count--;
		return 0;
	}
}

void FC()
{
	int con = 0;
	int fc = 0;
	int x = 0;
	if (DorS == 1)//더블일 때
	{
		con = 1;//한번 더 기능 취소
	}
	fc = rand() % 9 + con;
	printf("\n\t\t\t\t\t\t\t\t\t\t\t%s\n", fortunecard[fc]);
	if (fc == 0)//한번 더 하기 기능(2차 심자)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t한번 더 할 수 있습니다\n");
		DorS = 1;
	}
	else if (fc == 1)//건물 파괴(화재상황발생)
	{
		printf("\n\t\t\t\t\t\t\t 선택한 상대의 건물을 파괴시킬 수 있습니다(랜드마크 제외)");
		for (int x = 1; x < 32; x++)
		{
			if (MAP.who[x] != 0 && MAP.who[x] != random[i])//상대땅이고 나의 땅이 아닐 때 파괴할 수 있는 땅이 있다
			{
				break;
			}
		}
		if (x == 32)
		{
			printf("\n\t\t\t\t\t\t선택할 수 있는 땅이 없습니다\n");
			return;//함수종료
		}
		while (1)
		{
			printf("\n\t\t\t\t\t\t\t\t\t    파괴할 땅을 선택하세요 ");
			scanf("%d", &x);
			if (MAP.building[x] == 0 || MAP.who[x] == random[i] || x < 1 || x > 31 || MAP.building[x] == 4)
			{//건물이 없거나 나의 땅이거나 범위를 넘어가거나 랜드마크라면
				printf("\n\t\t\t\t\t\t\t\t\t상대의 땅을 입력해주세요\n");
				continue;
			}
			MAP.building[x] = 0;
			MAP.who[x] = 0;
			for (int p = 2; p < 35; p += 4)
			{
				for (int P = 2; P < 35; P += 4)
				{
					if (map[p][P] == x + 2)
					{
						for (int k = 0; k < 3; k++)//혜당하는 칸의 색을 초기화
						{
							for (int K = 0; K < 3; K++)
							{
								if (k == 1 && K == 1)//중간 칸은 초기화 X
								{
									continue;
								}
								map[p + 1 - k][P - 1 + K] = 0;
							}
						}
						p = 35;
						P = 35;
					}
				}
			}
			break;
		}
	}
	else if (fc == 2)//무인도로 이동(기말고사)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t무인도로 이동합니다\n");
		PLAYER[random[i]].location = 8;
		DorS = 0;
		//printf("\n\t\t\t\t\t\t\t\t\t   2턴 뒤에 다시 플레이가 가능합니다\n");
		//PLAYER[random[i]].count = -1;
	}
	else if (fc == 3)//건물 바꾸기(튜티튜터)
	{
		printf("\n\t\t\t\t\t\t\t\t\t현재 플레이어의 가장 싼 땅과\n");
		printf("\t\t\t\t\t\t\t\t\t다른 플레이어의 가장 비싼 땅을 바꿉니다(랜드마크 제외)\n");
		for (int p = 1; p < 32; p++)//건물을 바꿀 수 있는 상황인지 판단
		{//현재 플레이어의 가장 싼 땅이어서 x++
			if (MAP.who[p] == random[i] && MAP.building[p] != 4)//내 땅이고 랜드마크가 아닌 건물이 있는지
			{
				for (int P = 31; P > 0; P--)
				{//상대 플레이어의 가장 비싼 땅이여서 y--;
					if (MAP.who[P] != random[i] && MAP.who[P] > 0 && MAP.building[P] != 4)//상대땅이고 랜드마크가 아닌 건물이 있는지
					{
						printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t바꾸기 성공!\n");
						printf("\t\t\t\t\t\t\t\t\t\t%d번 플레이어의 %d번 땅 <-> %d번 플레이어의 %d번 땅\n", MAP.who[p], p, MAP.who[P], P);
						//바꾸기
						MAP.who[p] = MAP.who[P];//내땅을 상대에게 주기
						MAP.who[P] = random[i];//상대땅을 내껄로 만들기
						//지도 바꾸기
						for (int k = 2; k < 35; k += 4)
						{
							for (int K = 2; K < 35; K += 4)
							{
								if (map[k][K] == p + 2)//내땅을 찾았을 때
								{
									for (x = 0; x < n; x++)//바뀌는 상대 플레이어의 수를 구하기
									{
										if (random[x] == MAP.who[p])
										{
											break;
										}
									}
									for (int a = 0; a < 3; a++)
									{
										for (int A = 0; A < 3; A++)
										{
											if (a == 1 && A == 1)
											{
												continue;
											}
											map[k + 1 - a][K - 1 + A] = 34 + x;//P번 땅의 소유자의 색
										}
									}
								}
								else if (map[k][K] == P + 2)//상대땅을 찾았을 때
								{
									for (int a = 0; a < 3; a++)
									{
										for (int A = 0; A < 3; A++)
										{
											if (a = 1 && A == 1)
											{
												continue;
											}
											map[k + -a][K - 1 + A] = 34 + i;
										}
									}
								}
							}
						}
						return;
					}
				}
			}
		}
		//바꿀 수 없다면
		printf("\n\t\t\t\t\t\t\t\t바꿀 수 있는 땅이 없습니다\n");
	}
	else if (fc == 4)//세계여행(외박)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t 복귀 버스로 이동합니다!\n");
		PLAYER[random[i]].location = 24;
	}
	else if (fc == 5)//출발점(복귀)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t  정문으로 이동합니다!\n");
		PLAYER[random[i]].location = 0;
	}
	else if (fc == 6)//기숙사(점호)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t  기숙사로 이동합니다!\n");
		PLAYER[random[i]].location = 8;
	}
	else if (fc == 7)//체육관(택견)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t체육관으로 이동합니다! (건설부가 / 인수불가)\n");
		PLAYER[random[i]].location = 2;
		if (MAP.who[PLAYER[random[i]].location] == 0)//건물의 소유가 없을 때
		{
			return;
		}
		PLAYER[random[i]].money -= MAP.cost[2];//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[2];//건물주인
	}
	else if (fc == 8)//다른 플레이어들이 돈을 줌(생일)
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t다른플레이어들의 돈중 각각 10%를 받습니다\n");
		for (int y = 0; y < n; y++)
		{
			if (PLAYER[random[y]].money <= 0 || y == i)//파산한 플레이어와 현재플레이어는 제외
			{
				continue;
			}
			PLAYER[random[i]].money += (PLAYER[random[y]].money / 10);//돈 +
			PLAYER[random[y]].money *= 0.9;//돈 -
		}
	}
	else if (fc == 9)
	{
		printf("\n\t\t\t\t\t\t\t모든 플레이어가 운동장에 모입니다! (건설불가 / 인수불가 / 운동장의 통행료를 낼 돈이 없다면 제외)\n");
		for (int y = 0; y < n; y++)
		{
			if (PLAYER[random[y]].money <= 0 || PLAYER[random[y]].money - MAP.cost[1] <= 0)//파산한 / 돈이없는 플레이어는 제외
			{
				continue;
			}
			PLAYER[random[y]].location = 1;
			if (MAP.who[PLAYER[random[y]].location] == 0)//건물의 소유가 없을 때
			{
				continue;
			}
			PLAYER[random[y]].money -= MAP.cost[1];//건물에 온 사람
			PLAYER[MAP.who[PLAYER[random[y]].location]].money += MAP.cost[1];//건물주인
		}
	}
}