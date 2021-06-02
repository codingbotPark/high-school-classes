//4G = 건물 나무가 있어도 괜찮음
//5G = 직진성 => 건물 나무가 있으면 안좋음
//%g = 숫자가 매우크면 %e ,아니면 %f로 표현해줌
//e = 10이라 생각하면 됨 (e - 3 = 10의 -3승 = 0.001)
//10을 10진수, 8진수, 16진수로 각각 입력받으면
//(	10진수 = 10이 출력
//8진수 = 10(8) = 8진수를 10진수로 변환 => 8 * 1 + 1 * 0 => 8
//16진수 = 10(16) = 16진수를 10진수로 변환 => 16 * 1 + 1 * 0 => 16 )
//do while 사용
//(
//		do {
//		printf("1");
//		} while (조건) )
//for 사용
//for (선언;조건;증감)

//3.22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double d1 = 1.23e-3;
	printf("%f\n", d1);
	printf("%e\n", d1);
	printf("%g\n", d1);
	double d2 = 1.234567e-3;
	printf("%f\n", d2);
	printf("%e\n", d2);//반올림
	printf("%g\n", d2);//반올림
	double d3 = 0.01234567;
	printf("%f\n", d3);
	printf("%e\n", d3);
	printf("%g\n", d3);
	return 0;
}

//10진수(%d), 8진수(%o), 16진수(%x)로 입력받아
//10진수로 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n1, n2, n3;
	printf("10진수, 8진수, 16진수\n");
	scanf("%d %o %x", &n1, &n2, &n3);
	printf("--10진수로 바꾸면---\n");
	printf("%d %d %d\n", n1, n2, n3);
	//3개 다 10을 입력했을 때
	//10진수 = 10이 출력
	//8진수 = 10(8) = 8진수를 10진수로 변환 => 8 * 1 + 1 * 0 => 8
	//16진수 = 10(16) = 16진수를 10진수로 변환 => 16 * 1 + 1 * 0 => 16
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1, n2, n3;
	scanf("%d %o %x", &n1, &n2, &n3);
	printf("%x %x %x\n", n1, n2, n3);
	return 0;
}

//while문 사용하여 1부터 10까치 출력
#include <stdio.h>
int main()
{
	int a = 0;
	while (a<10)
	{
		a++;
		printf("%4d", a);
	}
	putchar('\n');
	return 0;
}

//do while 사용
#include <stdio.h>
int main()
{
	int n = 1;
	do {
		printf("%4d", n);
	} while (n++ < 10);
	return 0;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n=0,m=0;
	scanf("%d", &n);
	do {
		m++;
		printf("%4d", m);
	} while (m < n);
	return 0;

}

//0이 입력될 때 까지 수를 더하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n, sum = 0;
	printf("숫자를 입력하세요\n");
	do {
		printf("0 입력시 종료 : ");
		scanf("%d", &n);
		sum = sum + n;
	} while (n);
	printf("총합 : %d", sum);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while (n < 9)
	{
		printf("2 * %d = %d\n", n+=1, n * 2);
	}
	return 0;
}

//단을 입력받으면 해당 구구단을 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, dan;
	scanf("%d", &dan);
	while (n++ < 9)
	{
		printf("%d * %d = %d\n", dan, n, dan * n);
	}
	return 0;
}

//구구단 2단부터 9단까지 출력하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2, m = 1;
	while (n < 10)
	{
		m = 1;
		while (m < 10)
		{
			printf("%d * %d = %d\n", n, m, n * m);
			m++;
		}
		printf("\n");
		n++;
	}
	return 0;
}

//구구단 2단 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int dan = 2, n = 0;
	for (n = 1; n < 10; n++)
	{
		printf("%d * %d = %d\n", dan, n, dan * n);
	}
	printf("%d", n);
	return 0;
}

//구구단 2~9출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2, m = 1;
	for (n; n < 10; n++)
	{
		for (m=1; m < 10; m++)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("================\n");
	}
	return 0;
}

//구구단을 역순으로 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 9, m = 9;
	for (n; n > 1; n--)
	{
		for (m = 9; m > 0; m--)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("================\n");
	}
	return 0;
}

//2.23
//구구단 출력 연습
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0;
	for (n = 2; n < 10; n++)
	{
		for (m = 1; m < 10; m++)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("======================\n");
	}
	printf("\n\n\n");
	for (n = 9; n > 1; n--)
	{
		for (m = 9; m > 0; m--)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("==========\n");
	}
	return 0;
}

//숫자 두개를 입력받으면 두수 사이의 합과 곱을 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 1, j = 0;
	printf("동생이 말한 수 : ");
	scanf("%d", &n);
	printf("(동생이 말한 수 보다 커야한다) 내가 말한 수 : ");
	scanf("%d", &m);
	for (n; n <= m; n++)
	{
		j += n;
		i *= n;
	}
	printf("\n정수 합 : %d", j);
	printf("\n정수 곱 : %d", i);
	return 0;
}

//별 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n=0; n < 5; n++)
	{
		for (m=0; m < 5; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 0; n < 5; n++)
	{
		for (m = 0; m <= n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m < n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 5; n > 0; n--)
	{
		for (i=0;;)
		for (m = 0; m < n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

 //3.24
(1)
#include <stdio.h>
int main()
{
	char a = 65;
	while (a <= 90)
	{
		printf("%c\n", a++);
	}
	return 0;
}

//(2)
#include <stdio.h>
int main()
{
	int num = 1, sum = 0;
	while (num <= 10)
	{
		sum += num;
		num++;
	}
	printf("1부터 10까지의 합 = %d\n",sum);
	printf("while 문이 끝난 후의 num의 값 = %d\n",num);
	return 0;
}

//(3)
#include <stdio.h>
int main()
{
	int i = 1, n = 0,sum=0;
	scanf_s("%d",&n);
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}

//(4)
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	printf("수를 입력하세요");
	scanf_s("%d", &i);
	do
	{
		printf("%d\n", j);
		j++;
	} while (j < i);
	return 0;
}

//(5)
#include <stdio.h>
int main()
{
	int a = 0, b = 1;
	scanf_s("%d", &a);
	while (b < 10)
	{
		printf("%d * %d = %d\n", a, b, a * b);
		b++;
	}
	return 0;
}

//3.25
//(1)
 for (시작값 ; 반복조건 ; 증감식)
 {
 명령문
 }
 
//(2)
#include <stdio.h>
int main()
{
	int n = 0;
	for (n = 1; n <= 20; n++)
	{
		if (n % 2 == 1)
		{
			printf("%d ", n);
		}
	}
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, n;
	printf("수를 입력하세요 : ");
	scanf("%d", &n);
	for (i; i < n; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 1, x;
	printf("단을 입력하세요 : ");
	scanf("%d", &x);
	for (i; i < 10; i++)
	{
		printf("%d X %d = %d\n", x, i, x * i);
	}
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, n;
	printf("N 입력 : ");
	scanf("%d", &n);
	for (a=0;a<n;a+=1)
	{
		for (b=0; b < n; b += 1)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//(6)
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 0; b < 5; b++)
		{
			printf("%d ", a);
		}
		printf("\n");
	}
	printf("\n");
	for (a = 0; a < 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			printf("%d ", b);
		}
		printf("\n");
	}
	return 0;
}