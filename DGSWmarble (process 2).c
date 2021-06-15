//부루 마블 (과정 2)
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
	int map[32];
	int building[32];
};
int dice(int power);//주사위를 돌리는 함수


int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;
	char m;
	int random[4];
	int cnt;
	int power;
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
			if (power >= 1 && power <= 5)
			{
				if (dice(power) == 0)
				{
					printf("%d칸 이동\n", n1 + n2);//더블이 아닐 때
					PLAYER[i].location += n1 + n2;
					printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[i].location);
					break;
				}
				else
				{
					printf("%d칸 이동\n", n1 + n2);//더블
					PLAYER[i].location += n1 + n2;
					printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[i].location);
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
						{
							printf("********\n%d번 플레이어 승리\n********", random[m]);
							return 0;
						}
					}
				}
			}
		}
		if (i == n - 1)//순서 돌리기
		{
			i = -1;
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