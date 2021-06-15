//부루 마블 (과정 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//typedef struct PLAYER layer PL;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int map[];
};
int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;
	char m;
	int random[4];
	srand((unsigned)time(NULL));
	while (1)//플레이어의 수와 순서를 정하기
	{
		printf("\n------------------------\n");
		printf("플레이어 수를 입력하세요(2~4)  ");
		scanf("%d", &n);
		if (n <= 4 && n >= 2)
		{
			printf("각자 번호를 정하세요 (다 정했으면 아무키나 입력해 주세요) ");
			scanf("%d", &m);
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
				printf("%d번 플레이어 = %d번째\n", i + 1, random[i]);
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
		printf("%d번 플레이어의 차례");
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money < 0)
			{

			}
		}

		if (i == n - 1)
		{
			i = -1;
		}
	}

	return 0;
}
