//default로 case에 해당 하지 않는 경우를 포함하할 수 있다
//go to를 사용하여 지정된 코드로 이동할 수 있다
//(코드가 복잡해져서 많이 사용하면 좋지않다)
//함수 선언 =
//(예)
// int odd(int n1, int n2)
// {
//	return n1 + n2;
// }
//)
//함수가 많아지면 가독성이 떨어지기 때문에 함수선언 / 메인 밑 함수를 적는 방법을 사용한다
//(함수를 위에 선언할 때 변수명까지 적을 필요는 없고 변수의 형식만 적는다)
//예)int add(int,int)

//4.5
//(1)
#include <stdio.h>
int main()
{
	int i=3,j=0;
		for (j=1; j < 10; j++)
		{
			printf("%d*%d=%d\n", i, j, i * j);
		}
		printf("\n");


	return 0;
}

//(2)
#include <stdio.h>
int main()
{
	int i=3,j=1;
	do {
		printf("%d*%d=%d\n", i, j, i * j);
		j++;
	} while (j < 10);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("숫자를 입력하세요\n");
	int p, sum=0;
	while (1)
	{
		printf("0 입력시 종료 : ");
		scanf("%d", &p);
		if (p==0)
		{
			break;
		}
		sum += p;
	}
	printf("\n총합 : %d",sum);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	scanf("%d", &i);
	for (j = 1; j <= 10; j++)
	{
		printf("%d*%d=%d\n", i, j, i * j);
	}
	return 0;
}

//(5)
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 2; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}

//(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0, a = 0, b = 1;
	printf("동생이 말한 숫자 : ");
	scanf("%d", &i);
	printf("내가 말한 숫자 : ");
	scanf("%d", &j);
	if (i > j)
	{
		for (a = j; a<= i; a++)
		{
			b *= a;
		}
	}
	else
	{
		for (a = i; a <= j; a++)
		{
			b *= a;
		}
	}
	printf("%d", b);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int s, e, t;
	int mul=1;
	scanf("%d %d", &s, &e);
	if (s > e)
	{
		t = s;
		s = e;
		e = t;
	}
	for (mul = 1; s <= e; s++)
	{
		mul *= s;
	}
	printf("%d\n",mul);
	return 0;
}

//4.6
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0, p = 1;
	scanf("%d", &i);
	for (j = 1; j <= i; j++)
	{
		p *= j;
	}
	printf("%d", p);
	return 0;
}

//(2)
#include <stdio.h>
int main()
{
	int i = 0,j=0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("*");
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
	int i = 0, j = 0,a=0;
	while (1)
	{
		scanf("%d", &a);
		if (a == 0)
			break;
		for (i = 1; i <= a; i++)
		{
			for (j = 0; j < i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

//(4)
#include <stdio.h>
int main()
{
	int i = 0, j = 0,a=0;
	for (i = 0; i < 5; i++)
	{
		for (a=0; a < i; a++)
		{
			printf(" ");
		}
		for (j = 0; j < 9 - (i * 2); j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//입력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int level, i, j, a;
	scanf("%d", &level);
	for (i = 0; i < level; i++)
	{
		for (a = 0; a < i; a++)
		{
			printf(" ");
		}
		for (j = (level * 2 - 1) - (i * 2); j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//(5)
#include <stdio.h>
int main()
{
	int i = 0, j = 0, a = 0, b = 0;
	for (i = 0; i < 9; i++)
	{
		if (i < 9 / 2)
		{
			for (a = 0; a < i; a++)
			{
				printf(" ");
			}
			for (j = 9 - (2 * i); j > 0; j--)
			{
				printf("*");
			}
		}
		else
		{
			for (b = a; b >= 0; b--)
			{
				printf(" ");
			}
			for (j = (i * 2) - 7; j > 0; j--)
			{
				printf("*");
			}
			a--;
		}
		printf("\n");
	}
	return 0;
}

//입력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int level, F, f, i, j, a, b;
	while (1)
	{
		printf("출력할 층을 입력하세요(홀수만 입력가능)");
		scanf("%d", &level);
		if (level % 2 != 0 && level > 0)
			break;
	}
	for (f = 0; f < level / 2; f++)
	{
		for (a = 0; a < f; a++)
		{
			printf(" ");
		}
		for (i = level - (f * 2); i > 0; i--)
		{
			printf("*");
		}
		printf("\n");
	}
	for (f = 0; f < level / 2 + 1; f++)
	{
		for (b = 0; b < (level / 2) - f; b++)//level / 2 +1
		{
			printf(" ");
		}
		for (j = 0; j < f * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//4.7
//switch
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char n;
	while (1)
	{
		scanf("%c", &n);
		switch (n)
		{
		case 'w':
			printf("위로 이동\n");
			break;
		case 'a':
			printf("왼쪽로 이동\n");
			break;
		case 'd':
			printf("오른쪽로 이동\n");
			break;
		case 's':
			printf("뒤쪽로 이동\n");
			break;
		}
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char day;
	printf("M : morning, A : afternoon, E : evening\n");
	printf("입력 : ");
	scanf("%c", &day);
	switch (day)
	{
	case 'M':
	case 'm':
		printf("Good Morning\n");
	case 'A':
	case 'a':
		printf("Good Afternoon");
 case 'E':
 case 'e':
 printf("Good Evening");
	}
	return 0;
}

//abc + cba 가 1232 를 만족하는 a b c를 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10; c++)
			{
				if (1232 == (100 * a + 10 * b + c) + (100 * c + 10 * b + a))
				{
					printf("%d%d%d", a, b, c);
					printf("+%d%d%d=1232\n", c , b , a);
				}
			}
		}
	}
	return 0;
}
//+입력받아서 하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, v;
	printf("만족할 값을 입력하세요");
	scanf("%d", &v);
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10; c++)
			{
				if (v==(101 * a + 20 * b + 101 * c))
				{
					printf("%d%d%d+%d%d%d=%d\n", a, b, c, c, b, a, v);
				}
			}
		}
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1, n2, n3;
	n1 = printf("I LOVE YOU\n");//영어 한글자다 1 + 공백 + \n(1)
	printf("n1=%d\n", n1);
	n2 = printf("난 널 사랑해\n");//한글 한글자다 2 + 공백 + \n(1)
	printf("n2=%d\n", n2);
	return 0;
}

//절댓값출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	printf("절대값을 구할 수를 입력하세요");
	scanf("%d", &n);
	if (n < 0)
		n = n - n - n;
	printf("%d", n);
	return 0;
}

//두 숫자를 더하는 add 함수 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int add(int , int );
int min(int , int );
int mul(int , int );
int div(int , int );
void output(char n,int a, int b)
{
	 
	if (n == '+')
		printf("%d", add(a, b));
	if (n == '-')
		printf("%d", min(a, b));
	if (n == '*')
		printf("%d", mul(a, b));
	if (n == '/')
		printf("%lf", div(a, b));
}

int main()
{
	char n;
	int a, b;
	printf("할 사칙연산 문자를 입력하세요");
	scanf("%c", &n);
	printf("숫자 두 개를 입력하세요");
	scanf("%d %d", &a, &b);
	output(n,a, b);
	return 0;
}

int add(int n1, int n2)
{
	return n1 + n2;
}
// - * / 함수
int min(int n1, int n2)
{
	return n1 - n2;
}
int mul(int n1, int n2)
{
	return n1 * n2;
}
int div(int n1, int n2)
{
	if (n2 == 0) exit(0);
	return (double)n1 / n2;
}