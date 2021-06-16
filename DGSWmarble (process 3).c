//부루 마블 (과정 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int n1 = 0;
int n2 = 0;

//typedef struct PLAYER layer PL;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int who[32];
	int building[32];
	char name[32][16];//dgsw실들
};
int dice(int power);//주사위를 돌리는 함수
//맵에 따라 돈 나가는 함수

int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;//플레이어의 수
	char m;//아무키나 / 건물짓기 여부
	int random[4];//플레이 순서
	int cnt;//파산한 플레이어의 수를 세아려 게임 종료
	int power;//주사위의 강도
	int SorD;//더블인지 아닌지
	int turn = 0;//텀(1~4의 플레이어가 한 턴식)이 15번 됐을 때 게임 종료
	int biggest = 0;//텀이 15번 돼서 끝날 때의 플레이어의 자산 비교
	int BN;//building number 빌딩을 몇 개 지을 것인지
	srand((unsigned)time(NULL));
	while (1)//게임 전 세팅(플레이어의 수와 순서를 정하기)
	{
		printf("\n------------------------\n");
		printf("플레이어 수를 입력하세요(2~4)  ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			PLAYER[i].money = 400;//기본 돈 400만원
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
	for (int i = 0; i < n; i++)//게임
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money <= 0)//파산했으면 다음순서
			{
				i++;
				break;
			}
		}
		while (1)//주사위 던지기
		{//그냥 PLAYER[i]
			printf("\t%d번 플레이어의 차례 \n", random[i]);
			printf("주사위를 던질 강도를 입력하세요(1~5)  ");
			scanf("%d", &power);
			SorD = dice(power);
			if (power >= 1 && power <= 5)
			{
				printf("%d칸 이동\n", n1 + n2);//더블이 아닐 때
				PLAYER[i].location += n1 + n2;
				if (PLAYER[i].location >= 32)//플레이어의 위치가 32칸을 넘었을 때
				{
					PLAYER[i].money += //한바퀴 돌 때의 월급
						PLAYER[i].location -= 32;
				}
				printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[i].location);
				if (MAP.building[PLAYER[i].location] > 0)//플레이어가 있는 곳에 빌딩이 있을 때
				{//자기껀지 비교 
				//빌딜이 있을 때(인수 y / n)
					if (MAP.who[PLAYER[i].location] == i)//자기 건물이 맞을 때
					{
						if (MAP.building[PLAYER[i].location] < 4)//랜드마크가 아닐 때
						{
							while (1)
							{
								printf("건물을 짓겠습니까? (y / n)");
								scanf(" %c", &m);
								if (m == 'Y' || m == 'y')
								{
									if (MAP.who[PLAYER[i].location] == 3)//건물이 3개일 때
									{
										while (1)
										{
											printf("랜드마크를 건설하겠습니까? (y / n)");
											scanf(" %c", &m);
											if (m == 'Y' || m == 'y')
											{
												MAP.building[PLAYER[i].location] = 4;
												printf("\n***랜드마크 건설***\n");
											}
											else if (m == 'N' || m == 'n')
											{
												break;
											}
											else
											{
												printf("Y(y) 또는 N(n) 중 하나의 문자를 입력해주세요");
											}
										}
									}
									else
									{
										printf("현재 건물의 개수 %d개\n", MAP.building[PLAYER[i].location]);
										printf("몇 개의 건물을 짓겠습니까?(최대 %d개)", 3 - MAP.building[PLAYER[i].location]);
										scanf("%d", &BN);
										if (BN > MAP.building[PLAYER[i].location] && BN < 3 - MAP.building[PLAYER[i].location])
										{
											MAP.building[PLAYER[i].location] = BN;
											break;
										}
										else
										{
											printf("잘못된 값 입력");
										}
									}
								}
								else if (m == 'N' || m == 'n')
								{
									break;
								}
								else
								{
									printf("Y(y) 또는 N(n) 중 하나의 문자를 입력해주세요");
								}
							}
						}
						else//도착한 자기 건물이 랜드마크 일 때
						{

						}
					}
					else//자기 건물이 아닐때 돈 내기
					{

					}
				}
				else//빌딩이 없을 때(구매 y / n)
				{
					while (1)
					{
						printf("건물을 짓겠습니까? (y / n)");
						scanf(" %c", &m);
						if (m == 'y' || m == 'Y')
						{
							while (1)
							{
								printf("몇 개의 건물을 짓겠습니까?(최대 3개)");
								scanf("%d", &BN);
								if (BN > 0 && BN < 4)
								{
									//건물 짓기 함수
									MAP.who[PLAYER[i].location] = i;
									MAP.building[PLAYER[i].location] = BN;
								}
								else
								{
									printf("1이상, 3이하의 수를 입력해 주세요");
								}
							}
						}
						else if (m == 'n' || m == 'N')
						{
							break;
						}
						else
						{
							printf("Y(y) 또는 N(n) 중 하나의 문자를 입력해주세요");
						}
					}
				}
				if (SorD == 0)//더블이 아닐 때
				{
					break;
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
		for (int j = 0; j < n; j++)
		{
			printf("\n%d번 플레이어의 자산 %d", random[i], PLAYER[j].money);
		}
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
		printf("------------------------\n");
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
#endif


#if 0
int n1 = 0;
int n2 = 0;
int all = 0;
while (1)
{
	n1 = rand() % 6 + 1;
	n2 = rand() % 6 + 1;
	all += (n1 + n2);
	printf("\n주사위 = %d %d\n", n1, n2);
	if (n1 == n2)
	{
		printf("더블입니다.");
		continue;
	}
	else
	{
		printf("%d칸 전진하세요\n", all);
		break;
	}
}