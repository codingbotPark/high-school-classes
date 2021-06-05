//지역변수 = 하나의 함수 안에서만 사용되는 변수
//전역변수 = 함수에 상관없이 프로그램 전체에서 사용할 수 있는 변수
//전역변수는 선언만 하면 0으로 초기화
//#pragma warnings(disable : 4996)// = #define _CRT_SECURE_NO_WARNINGS와 같은역할
//재귀함수를 사용하여 반복되는 작업을 할 수 있다
//f11을 눌러 순서대로 디버깅 할 수 있다.(shift + f5 를 눌러 탈출)

//4.12
//지역변수 전역변수
#include <stdio.h>
int num = 5;
int main()
{
	int num = 1;
	if (num == 1)
	{
		int num = 7;
		num += 10;
		printf("if문 내 지역변수 num : %d\n", num);
	}
	printf("main함수 내 지역변수 num : %d\n", num);
	return 0;
}

//세 개의 정수를 인자로 전달받아
//그 중 가장 큰 수를 반환하는 함수와
//가장 작은 수를 반환하는 함수가 있는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b, int c)
{
	int t = (a > b) ? (a) : (b);
	return (t > c) ? (t) : (c);	
}
int min(int a, int b, int c)
{
	int t = (a > b) ? (b) : (a);
	return (t > c) ? (c) : (t);
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("max = %d\n", max(a, b, c));
	printf("min = %d\n", min(a, b, c));
	return 0;
}

//피보나치 수열 (전의 수 2개를 더한 값(0 1 1 2 3 5 8 13 ...))
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacii(int n)
{
	int f1 = 0;
	int f2 = 1, f3;
	if (n == 0)
		printf("%d", f1);
	else
		printf("%d %d", f1 , f2);
	for (int i = 0; i < n - 2; i++)
	{
		f3 = f2 + f1;
		printf(" %d", f3);
		f1 = f2;
		f2 = f3;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	fibonacii(n);
}

//math.h라이브러리를 검색하여 예제하나를 만드는 과제
//2차함수 근을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
int main()
{
	double a, b, c, x1 = 0, x2 = 0;
	double X = 0;
	printf("aX^2 + bX + c = 0일때의 a b c를 입력하세요");
	scanf("%lf %lf %lf", &a, &b, &c);
	X=sqrt((double) (b * b - 4*a*c));
	x1 = (-b - X) / (2 * a);
	x2 = (-b + X) / (2 * a);
	if (x1 != x2)
		printf("%lf\n%lf", x1, x2);
	else
		printf("%lf", x1);
	return 0;
}

//4.13
//피보나치 테스트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h.>
int F(n)
{
	int f1 = 1, f2 = 1, f3 = 0, i = 0;
	if (n > 0)
	{
		if (n == 1)
		{
			printf("%d ", f1);
		}
		else
		{
			printf("%d ", f1);
			printf("%d ", f2);
			for (i = 2; i < n; i++)
			{
				f3 = f1 + f2;
				printf("%d ", f3);
				f1 = f2;
				f2 = f3;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	F(n);
	return 0;
}

//전역변수사용
#pragma warnings(disable : 4996)// = #define _CRT_SECURE_NO_WARNINGS와 같은역할
#include <stdio.h>
int n;
void add(int);
int main()
{
	printf("n : %d\n", n);
	add(3);
	printf("n : %d\n", n);
	n++;
	printf("n : %d\n", n);
	return 0;
}
void add(int x)
{
	n += x;
}

//재귀함수사용
#pragma warnings(disable : 4996)
#include <stdio.h>
void recur(int n)
{
	if (n < 0)
		return 0;
	printf("함수안에 함수 호출 : %d\n", n);
	recur(n - 1);
}
int main()
{
	recur(5);
	return 0;
}

//재귀함수로 팩토리얼 만들기
#pragma warning(disable : 4996)
#include <stdio.h>
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
int main()
{
	printf("%d\n", fact(5));
	return 0;
}

//4.14
//(1)
//break		반복문을 빠져나옴
//continue	뒤의 문장을 수행하지 않고 다시 올라간다

//(2)
if (조건 1)
 {
 조건1이 참일 경우 실행되는 명령문
 }
else if(조건 2)
 {
 조건 2가 참일 경우 실행되는 명령문
 }
else
 {
 위의 조건에 맞지 않는 경우 실행되는 명령문
 }


//(3)
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
int main()
{
	int score, pass;
	printf("점수를 입력하세요: ");
	scanf("%d", &score);
	printf("합격점을 입력하세요");
	scanf("%d", &pass);
	printf("%s", score >= pass ? "합격" : "불합격");
}

//(4)
조건		= 조건식의 결과가 정수나 문자가 될 수 있는 조건 또는 변수
 
case 값 n = 조건의 결과가 값 n일 때 해당 명령을 실행
(n은 반드시 정수형 상수이어야 하며, 변수는 올 수 없다)
 
break		= swtich문을 종료하는 명령
 
default	= case에 없는 그 외의 모든 경우에 실행되는 명령문


//(5)
switch (a)
{
case 1 : printf("1st"); break;
case 2 : printf("2ed"); break;
case 3 : printf("3th"); break;
default : printf("%dth"); break;
}

//(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int l, j = 0, n = 1, m = 0;
	printf("출력할 층을 입력하세요");
	scanf("%d", &l);
	for (j = 0; j <= l; j++)
	{
		for (m = 0; m < j; m++)
		{
			printf("%4d", n);
			n++;
		}
		printf("\n");
	}
	return 0;
}

//4.15
//(1)
//(하)
#include <stdio.h>
int main()
{
	int i = 0, j = 0, n = 0, m = 0,a=0,b=0;
	for (i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			for (a = 0; a < i; a++)
			{
				printf(" ");
			}
			printf("*");
			for (b = 5-(i*2); b > 0; b--)
			{
				printf(" ");
			}
			printf("*");
		}
		else if (i == 3)
		{
			printf("   *");
		}
		else
		{
			for (a = 0; a < 6-i; a++)
			{
				printf(" ");
			}
			printf("*");
			for (b = 0; b <= ((i - 4) * 2); b++)
			{
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//(답)
#include <stdio.h>
int main()
{
	int i, j, k, l;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i == j || i + j == 6)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
//(입력받기)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, j, k, l,n;
	while (1)
	{
		printf("출력할 층을 입력하세요(홀수만 입력시 출력됩니다)");
		scanf("%d", &n);
		if (n % 2 == 1)
			break;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j || i + j == n-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}


//(2)
#include <stdio.h>
int main()
{
	int d = 2, i = 0, j = 0, n = 0, m = 0;
	for (i = 1; i < 10; i++)
	{
		for (d = 2; d < 10; d++)
		{
			printf("%d * %d = %3d   ", d, i, d * i);
		}
		printf("\n");
	}
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int d = 0, n = 0, m = 0, i = 0, j = 0;
	printf("단을 입력하세요");
	scanf("%d", &d);
	for (n = 1; n <= d; n++)
	{
		for (m = 1; m <= d; m++)
		{
			printf("(%d,%d) ", n, m);
		}
		printf("\n");
	}
}