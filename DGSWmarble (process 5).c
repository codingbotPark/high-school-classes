//부루 마블 (과정 5)
// 빌딩의 가격을 하나하나 계산했던 함수 (BN함수)를
// =>
// 원래 구조체에 빌딩의 가격을 넣고 그냥 인수 할 때만 BN함수에서 * 2 로만들어
// 각격을 두 배 할 수 있도록 함
// 
// +모서리부분에 start에 도착하면 3개 미만인 건물을 더 건설할 수 있는 기능
// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int n1 = 0;
int n2 = 0;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int who[32];
	int building[32];
	char name[32][16];
	int cost[32];
};
struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };
int dice(int power);
void change(int i, int S);

char m;//아무키나 / 건물짓기 여부
int n;//플레이어의 수

int main()
{
	int random[4];//플레이 순서
	int cnt;//파산한 플레이어의 수를 세아려 게임 종료
	int power;//주사위의 강도
	int SorD;//더블인지 아닌지
	int turn = 0;//텀(1~4의 플레이어가 한 턴식)이 15번 됐을 때 게임 종료
	int biggest = 0;//텀이 15번 돼서 끝날 때의 플레이어의 자산 비교
	int BN;//building number 빌딩을 몇 개 지을 것인지
	srand((unsigned)time(NULL));

	for (int i = 0; i < 32; i++)//31까지 사용한다
	{
		MAP.cost[i] *= 4;
	}
	while (1)//게임 전 세팅(플레이어의 수와 순서를 정하기)
	{
		printf("\n------------------------\n");
		printf("플레이어 수를 입력하세요(2~4)  ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			PLAYER[i].money = 400;
		}
		if (n <= 4 && n >= 2)
		{
			printf("각자 번호를 정하세요 (다 정했으면 아무키나 입력해 주세요) ");
			scanf(" %c", &m);
			printf("\n\t순서\n");
			for (int i = 0; i < n; i++)
			{
				random[i] = rand() % n + 1;
				for (int j = 0; j < i; j++)
				{
					if (random[i] == random[j])
					{
						random[i] = rand() % n + 1;
						j = -1;
					}
				}
				printf("%d번 플레이어 = %d번째\n", random[i], i + 1);
			}
			printf("------------------------\n");
			break;
		}
		else
		{
			printf("2명 이상, 4명 이하의 플레이어 수를 입력해주세요\n");
		}
	}
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money <= 0)
			{
				i++;
				break;
			}
		}
		while (1)
		{//그냥 PLAYER[i]
			printf("\t%d번 플레이어의 차례 \n", random[i]);
			printf("주사위를 던질 강도를 입력하세요(1~5)  ");
			scanf("%d", &power);
			SorD = dice(power);
			if (power >= 1 && power <= 5)
			{
				printf("%d칸 이동\n", n1 + n2);
				PLAYER[i].location += n1 + n2;
				if (PLAYER[i].location >= 32)
				{
					PLAYER[i].money += 60;
					PLAYER[i].location -= 32;
				}
				printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[i].location);
				if (PLAYER[i].location == 8 || PLAYER[i].location == 16 || PLAYER[i].location == 24 || PLAYER[i].location == 0)//특수한 곳에 왓을 때
				{// 8 = 기숙사(무인도)		16 = 급식실(올림픽 개최)		24 = 귀가버스(세계여행)		0 = 정문(출발점)
					if (PLAYER[i].location == 8)
					{
						printf("\n기숙사 도착!\n");
						break;//한 턴 넘기기
					}
					else if (PLAYER[i].location == 16)
					{
						printf("\n급식실 도착!\n");
					}
					else if (PLAYER[i].location == 24)
					{
						printf("\n귀가버스 도착!\n");
					}
					else
					{
						printf("\n정문 도착!\n");
					}
					break;
				}
				else if (MAP.who[PLAYER[i].location] != i && MAP.building[PLAYER[i].location] != 0)//건물이 상대의 것일 때
				{
					change(random[i], 2);
					break;
				}
				else//건물이 없거나 나의 것일 때
				{
					if (MAP.building[PLAYER[i].location] < 3)//건물 3개 미만
					{
						while (1)
						{
							printf("건물을 짓겠습니까? (y / n)");
							scanf(" %c", &m);
							if (m == 'Y' || m == 'y')
							{
								while (1)
								{
									printf("몇 개의 건물을 짓겠습니까? (추가로 지을 건물의 개수)");
									scanf("%d", &BN);
									if (BN + MAP.building[PLAYER[i].location] > 3 || BN <= 0)
									{//건물의 개수가 원래 건물의 개수보다 작을 것을 방지
										printf("\n건물의 개수가 잘못 돼었습니다 (초과 / 미만)의 이유\n");
										continue;
									}
									else
									{
										change(i, 1);
										MAP.building[PLAYER[i].location] += BN;
										MAP.who[PLAYER[i].location] = random[i];
										break;
									}
								}
								break;
							}
							else if (m == 'N' || m == 'n')
							{
								break;
							}
							else
							{
								printf("\nY(y) 또는 N(n)중 하나의 문자를 입력해 주세요\n");
							}
						}
					}
					else if (MAP.building[PLAYER[i].location] == 3)//건물이 3개
					{
						while (1)
						{
							printf("랜드마크를 짓겠습니까? (y / n)");
							scanf(" %c", &m);
							if (m == 'Y' || m == 'y')
							{
								MAP.building[PLAYER[i].location] = 4;
								printf("\n***%s 건설***\n", MAP.name[PLAYER[i].location]);
								break;
							}
							else if (m == 'N' || m == 'n')
							{
								break;
							}
							else
							{
								printf("Y(y) 또는 N(n)중 하나의 문자를 입력해주세요");
							}
						}
					}
					if (SorD == 0)//더블이 아닐 때
					{
						break;
					}
				}
			}
			else
			{
				printf("\n1이상, 5이하의 강도를 입력해 주세요\n");
			}
		}
		for (int j = 0; j < n; j++)//게임의 끝(한명을 제외한 나머지 사람들이 파산)
		{
			if (PLAYER[j].money <= 0)
			{
				cnt++;
				if (cnt == n - 1)
				{
					for (int m = 0; m < n; m++)
					{
						if (PLAYER[m].money > 0)
							//random배열의 순서대로 구조체를 사용한 것이 아닌
							//그냥 1번째는 구조체1번, 2번째는 구조체2번 ...
						{
							printf("********\n%d번 플레이어 승리\n********", random[m]);
							return 0;
						}
					}
				}
			}
		}

		//현재 지도

		//확인코드
		//--------------------
		for (int j = 0; j < n; j++)
		{
			printf("\n%d번 플레이어의 자산 %d", random[j], PLAYER[j].money);//한 턴이 끝나고 자산을 표시
		}
		for (int j = 0; j < 32; j++)
		{
			printf("\n%d번째 건물의 개수 %d", j, MAP.building[j]);
			printf("\n%d번째 건물의 소유 %d", j, MAP.who[j]);
		}
		//---------------------
		if (i == n - 1)//순서 돌리기
		{
			i = -1;
			turn++;//각자 한 턴씩 했을 때
			if (turn >= 15)//turn이 15번 돌 때 금액이 가장 많은 사람이 승리
			{
				for (int j = 1; j < n; j++)
				{
					if (PLAYER[biggest].money < PLAYER[j].money)
					{
						biggest == j;
					}
					if (j == n - 1)
					{
						printf("********\n%d번 플레이어 승리\n********", random[biggest]);
						return 0;
					}
				}
			}
		}
		printf("\n------------------------\n");
	}
	return 0;

}
int dice(int power)
{
	n1 = 0;
	n2 = 0;
	n1 = rand() % 2 + power;
	n2 = rand() % 6 + 1;
	//all += (n1 + n2);
	printf("\n주사위 = %d %d\n", n1, n2);
	if (n1 == n2)
	{
		//printf("더블입니다.");
		return 1;
	}
	else
	{
		//printf("%d칸 전진하세요\n", all);
		return 0;
	}
}
// random이 돌아가는건
// random[i]
// 	   3
// 	   2
// 	   1
// 
// 
// PLAYER[i]
// 	   1
// 	   2
// 	   3


void change(int i, int S)
{
	if (S == 1)//건물을 지을 때
	{
		PLAYER[i].money -= MAP.cost[PLAYER[i].location];//돈빼기 함수사용
	}
	else if (S == 2)
	{
		if (MAP.building[PLAYER[i].location] == 4)//상대건물이 랜드마크일 때
		{
			PLAYER[i].money -= MAP.cost[PLAYER[i].location];//돈빼기 함수사용
		}
		else//상대건물이 랜드마크가 아닐 때
		{
			while (1)
			{
				PLAYER[i].money -= MAP.cost[PLAYER[i].location];
				printf("건물을 인수하시겠습니까? (Y / n)");
				scanf(" %c", &m);
				if (m == 'Y' || m == 'y')
				{
					PLAYER[i].money -= 2 * MAP.cost[PLAYER[i].location];
					PLAYER[MAP.who[PLAYER[i].location]].money += 2 * MAP.cost[PLAYER[i].location];
					MAP.who[PLAYER[i].location] = i;
					break;
				}
				else if (m == 'N' || m == 'n')
				{
					break;
				}
				else
				{
					printf("\nY(y) 또는 N(n)중 하나의 문자를 입력해주세요\n");
				}
			}
		}
	}
}