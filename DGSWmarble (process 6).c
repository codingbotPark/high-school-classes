//과정 6
// 
// 간결하게 다시
// 함수에 함수의 기능을 하는 모든 코드를 넣음
// 
// 원래 순서가 3 1 2 라면 
// 플레이어 구조체(PLAYER)은
// 그냥 순서대로 1 2 3 이였는데
// random[]배열을 활용해서 
// 플레이어 구조체와 플레이어의 번호를 일치시킴
// 
// 
// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct PLAYER
{
	int money;//플레이어의 돈
	int location;//플레이어의 위치
};
struct MAP
{
	int building[31];//빌딩의 개수
	int who[31];//빌딩의 소유자
	char name[31][16];
	int cost[31];

};

struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };

void TURN();
//플레이어의 수를 받아서 순서를 정하는 함수
int dice();
//주사위를 돌리는 함수
void GS(int s);//gamesetting
//게임이 시작되기 전 세팅
int judge(int s);
//어떤 상황인지 판단하는 함수(내땅인지 상대땅인지)
void CM(int s);//changingmoney
//어떤 상황에 따라 돈을 + - 하는 함수
void BB(int s);//buildingbuilding
//상황에 따라 빌딩을 짓는 함수
int YORN(int s);
//상황에 따라 Y또는N을 받아서 1또는 0을 반환하는 함수
void GF(int s);//gamefuntion
//게임의 기능(파산한사람의 순서를 넘기기)
int END(int s);
//게임의 끝일 상황을 판단하는 함수
void CBC(int s);//changingbuildingcost
//건물을 지을 때 마다 땅의 가격을 바꾸는 함수
void CW(int s);//changingwho
//상황에 따라 건물의 소유자를 바꾸는 함수


int i = 0;//main for문에서 사용되는 변수
int n = 0;//플레이어의 수
int random[4];//순서
char YorN;//아무키나 눌러 넘기기 / Y or N
int DorS;//더블인지 아닌지
int BN;//지을 건물의 개수
int choice;//올림픽 개최로 

int main()
{
	srand((unsigned)time(NULL));
	GS(1);//빌딩값 초기화
	TURN();//순서 정하기
	GS(0);//순서그대로 플레이어 돈 초기화
	for (i = 0; i < n; i++)
	{
		GF(0);
		dice();
		if (judge(0))// 상대땅인지 아닌지 판별 아니면
		{
			// money
			// build(building , who)
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
				CM(0);//짓는 건물의 개수에 따라 
				CBC(0);//건물을 지음에 따라 땅의 가격을 바꿔주기
			}
			//else 랜드마크라면 넘기기
		}
		else// 아니면
		{
			if (judge(1))//랜드마크인지 아닌지 판별 맞으면
			{
				CM(1);
			}
			else//랜드마크가 아니라면(인수가 가능하다면)
			{
				CM(1);//일단 돈을 내고
				if (YORN(2))//인수를 할 것인가? 맞다면
				{
					CM(1);
					CW(0);
				}
				//moeny
				//who
			}
		}
		//확인코드
		for (int x = 0; x < n; x++)
		{
			printf("%d번 플레이어의 자산 %d\n", random[x], PLAYER[random[x]].money);
		}
		for (int x = 0; x < 31; x++)
		{
			printf("%d번 건물의 개수 %d\n", x, MAP.building[x]);
			printf("%d번 건물의 소유 %d\n", x, MAP.who[x]);
		}



		if (DorS)//더블일 때 한번 더
		{
			i--;
			continue;
		}





		if (i == n - 1)//순서돌리기
		{
			i = -1;
		}
	}

	return 0;
}





void TURN()
{
	while (1)
	{
		printf("\n---------------\n");
		printf("플레이어의 수를 입력하세요(2~4) ");
		scanf("%d", &n);
		if (n > 1 && n < 5)
		{
			break;
		}
		printf("\n2명 이상, 4명 이하의 플레이어 수를 입력해주세요\n");
	}
	printf("각자 번호를 정하세요 (다 정했으면 아무키나 입력해 주세요) ");
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
		printf("\n%d번째순서 = %d번 플레이어", x + 1, random[x]);
	}
	printf("\n---------------\n");
}

int dice()
{
	DorS = 0;//더블인지아닌지 판단하는 변수를 초기화
	int power;
	int n1 = 0;//주사위1
	int n2 = 0;//주사위2
	printf("\t%d번 플레이어 차례\n", random[i]);
	while (1)
	{
		printf("주사위 강도를 입력해주세요(1~5) ");
		scanf("%d", &power);
		if (power < 1 && power > 5)
		{
			printf("1이상 5이하의 수를 입력해주세요");
			continue;
		}
		break;
	}
	n1 = rand() % 2 + power;
	n2 = rand() % 6 + 1;
	printf("\n주사위 = %d %d\n", n1, n2);
	PLAYER[random[i]].location += (n1 + n2);
	if (PLAYER[random[i]].location > 31)
	{
		PLAYER[random[i]].money += 60;

	}
	printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[random[i]].location);
	if (n1 == n2)
	{
		DorS = 1;
	}
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
		for (int x = 0; x < 31; x++)
		{
			MAP.cost[x] = 2 * x;
		}
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
}

int judge(int s)
{
	if (s == 0)//상대땅인지 아닌지 판단
	{
		if (MAP.who[PLAYER[i].location] != i && MAP.building[PLAYER[i].location] != 0)//상대땅일 때
		{
			return 0;
		}
		else//건설 할 수 있을 때
		{
			return 1;
		}
	}
	if (s == 1)//랜드마크인지 아닌지 판단
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
	if (s == 2)//건물이 3개인지 3개 미만인지 판단(랜드마크건설)
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
}


void CM(int s)
{
	if (s == 0)//아무것도 없을 때 건설
	{
		//PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];
		PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
		//건물을 지을 때 마다 더 비싸게 주고 건물을 지어야 함
	}
	else if (s == 1)
	{
		PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[PLAYER[random[i]].location];//건물주인
	}
}

void BB(int s)
{
	if (s == 0)
	{
		while (1)
		{
			printf("몇 개의 건물을 짓겠습니까? (추가로 지을 건물의 개수) ");
			scanf("%d", &BN);
			if (BN + MAP.building[PLAYER[random[i]].location] >= 4 || BN <= 0 || BN > 3)
			{
				printf("\n건물의 개수가 잘못 되었습니다 (초과 / 미만 등의 이유)\n");
				continue;
			}
			else
			{
				MAP.building[PLAYER[random[i]].location] += BN;
				break;
			}
		}
	}
	else if (s == 1)
	{
		MAP.building[PLAYER[random[i]].location] = 4;
		printf("\n***%s 건설***\n", MAP.name[PLAYER[random[i]].location]);
		BN = 1;//빌딩넘버를 1로 맞춰서 가격이 건물 하나를 지을 때와 같이 올라가도록 하기
	}
}

int YORN(int s)
{
	if (s == 0)
	{
		printf("건물을 짓겠습니까? (y / n)");
	}
	else if (s == 1)
	{
		printf("랜드마크를 짓겠습니까? (y / n)");
	}
	else if (s == 2)
	{
		printf("건물을 인수하시겠습니까? (y / n)");
	}
	while (1)
	{
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
			printf("\nY(y)또는 N(n)중 하나의 문자를 입력해주세요\n");
		}
	}
}

int END(int s)
{
	if (s == 0)
	{

	}
	else
	{

	}
}


void CBC(int s)
{
	if (s == 0)//그냥 건물을 지을 때(+로 가격 올리기)
	{
		MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
	}
	else if (s == 1)//올림픽 개최로 가격이 올라갈 때
	{

	}

}

void CW(int s)
{
	if (s == 0)
	{
		MAP.who[PLAYER[random[i]].location] = random[i];
	}
}