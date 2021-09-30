//요일 알아내기
//1년 1월 1일을 일요일으로 계산
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int Y, M, D;
	int all = 0;
	char printday[8][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int MD[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//월별 날짜 수
	int i, j, k;
	int cnt = 0;
	int cntY = 0;

	scanf("%d", &Y);
	scanf("%d", &M);
	scanf("%d", &D);

	for (i = 1; i < Y; i++)//년도 탐색
	{
		for (j = 0; j < 365; j++)//1년의 날짜 플러스
		{
			cnt++;
		}
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
		{
			cntY++;
		}
	}
	//요기까지 올해를 제외한 전체 날짜 수를 구함

	for (j = 1; j < M; j++)
	{
		cnt += MD[j];
		//올해가 윤년이고 검색하는 월이 2월 이상일 때
		//()
		if (j > 2 && (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)))
		{
			cntY++;
		}
		//요기까지 검색하는 날짜의 전 월까지의 날짜 수를 구함
	}

	for (i = 0; i < D; i++)
	{
		cnt++;
	}
	//요기까지 구하는 날짜까지의 날짜 수를 구함

	printf("\n0부터 날짜 : %d\n\n", cnt + cntY);
	printf("%s", printday[(cnt + cntY) % 7]);


	return 0;
}