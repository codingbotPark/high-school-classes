// 백준 16917
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, x, y;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	int i = 0,j=0,o=0,p=0,t=0,T=0;
	
	// i는 뭐가 더 큰지 0 = 양념 1 = 후라이드
	// j는 더 작은 것의 수 = 
	// 

	if (x > y)
	{
		j = y;
		i = 0;
	}
	else
	{
		j = x;
		i = 1;
	}
	//둘 중 작은 수는 j에 저장됨

	if (a + b >= c * 2)//반반 두 개를 사는 것보다 따로 사는것이 더 이득일 때
	{
		o = (c * 2);
	}
	else//반반 두 개를 사는 것이 더 이득일 때
	{
		o = (a + b);
	}

	if (i == 0)//x가 더 클 때
	{
		p = a*(x - y);
	}
	else
	{
		p = b * (y - x);
	}

	t = (o * j) + p;

	if (x > y)//x가 더 클때
	{
		T = x * (c * 2);
	}
	else
	{
		T = y * (c * 2);
	}

	if (T > t)
	{
		printf("%d", t);
	}
	else
	{
		printf("%d", T);
	}

	return 0;
}
