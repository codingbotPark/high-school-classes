//새 개의 값을 입력받아 
//최대 12000
// 1000 10 8719
// 
// 1~10
// 1001 ~ 1010
// 2001 ~ 2010
// .
// .
// 11001 ~ 11010
// 
// 11 ~ 20
// 1011 ~ 1020
// .
// .
// 11011 ~ 11020
// 
// 21 ~ 30
// 
// 이렇게 해서 3번째 입력된 값에 도달하는데 걸리는 회수를 출력
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int tum1, tum2, search, cnt = 0;
	scanf("%d %d %d", &tum1, &tum2, &search);

	for (int t = 0; t < tum1 / tum2 + 1; t++)//나눴을 때 올림을 해줘서 소수가 나올 때를 예방
	{
		for (int i = 0; i < 12000; i += tum1)//i * tum1
		{
			for (int j = 1 * ((t * tum2) + 1); j <= tum2 * (t + 1); j++)//turn이 한번 돌 때 값과 조건 곱하기
			{
				cnt++;
				if (i/*천의 단위*/ + j == search)
				{
					printf("%d", cnt);
					return 0;
				}
			}
		}
	}

	return 0;
}



//빠른코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", (12000 / a) * (c % a / b * b) + (c / a * b) + (c % b));
	return 0;
}
