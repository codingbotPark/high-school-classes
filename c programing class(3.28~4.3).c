//if
//else if
//esle
// 와
//if
//if
//if
//의 차이점은 else if는 앞의 if가 참이면 넘김
//if는 3개의 if를 모두통과
//3항 연산자 ((조건)?(참):(거짓))
//break (반복문에서 나온다)
//continue (아래의 내용을 생략하고 다시 반복문의 시작으로 간다)
//switch case문이 if보다 속도가 빠르다

//3.29
//별 삼각형 출력 1
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i=0; i < 5; i++)
	{
		for (j=0; j < 5-i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력 1 (선생님)
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 5; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력 (이등변 삼각형)
#include <stdio.h>
int main()
{
	int i = 0, j = 0, a = 0;
	for (i = 0; i < 5; i++)
	{
		for (a = 0; a < 5 - i; a++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//별 삼각형 출력 (이등변 삼각형)(선생님)
#include <stdio.h>
int main()
{
	int n = 5, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//if 문 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0)
		printf("0보다 작다");
	if (n > 0)
		printf("0보다 크다");
	if (n == 0)
		printf("0이다");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0)
		printf("0보다 작다");
	else if (n > 0)
		printf("0보다 크다");
	else (n == 0)
		printf("0이다");
	return 0;
}

//덧셈 뺄셈 곱셈 나눗셈
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int opt;
	double num1, num2, result;
	printf("1.덧셈 2.뺄셈 3.곱셈 4.나눗셈\n");
	scanf("%d", &opt);
	printf("두 개의 실수 입력 : ");
	scanf("%lf %lf", &num1, &num2);
	if (opt == 1)
		result = num1 + num2;
	else if (opt == 2)
		result = num1 - num2;
	else if (opt==3)
		result = num1 * num2;
	else
		result = num1 / num2;
	printf("결과 : %f", result);
	return 0;
}

//1~100 사이의 3의 배수
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			printf("%d\n", i);
	}
	return 0;
}
//+5개 출력시 한줄 내리기 //서준이는 i가 15일때 줄을 바꿈
#include <stdio.h>
int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%4d", i);
			count++;
		}
		if (count >= 5)
		{
			printf("\n");
			count-=5;
		}
	}
	return 0;
}

//5와 7의 배수 출력,결과가 5개씩 출력
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 5 == 0 || i % 7 == 0)
		{
			printf("%4d", i);
			j++;
		}
		if (j > 0 && j % 5 == 0)
		{
			printf("\n");
			j -= 5;
		}
	}
	return 0;
}

//숫자하나 입력받아 절댓값을 출력하는 프로그램
//3항 연산자 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d", (i >= 0) ? (i) : (-1 * i));
	return 0;
}

//국어, 수학 ,프로그래밍 성적을 입력받아
//90점 이상 A
//80점 이상 B
//		.
//		.
//60점 미만 F
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int Kor, Eng, Pro;
	double avg;
	printf("국어 수학 프로그래밍 점수를 입력하세요");
	scanf("%d %d %d", &Kor, &Eng, &Pro);
	avg = (Kor + Eng + Pro) / 3;
	printf("%c",(avg >= 90.0) ? ('A') : ((avg >= 80.0) ? ('B') : ((avg >= 70.0) ? ('C') : ((avg >= 60.0) ? ('D') : ('F')))));
	return 0;
}

#include <stdio.h>
int main()
{
	int sum = 0, num = 0;
	while (1)
	{
		printf("%d", ++num);
		if (num > 100000)
			break;
	}
	return 0;
}
//+홀수면 continue
#include <stdio.h>
int main()
{
	int sum = 0, num = 0;
	while (num <= 100)
	{
		if (++num % 2 == 1)
			continue;
		printf("%d", num);
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int n = 0, v=0;
	while (v <= 100000)
	{
		n++;
		v += n;
	}
	printf("%d", n);
	return 0;
}

#include <stdio.h>
int main()
{
	int n = 0, v = 0;
	for (n; v <= 50000; n++)
	{
		v += n;
	}
	v -= n;
	//for 문에서 v가 5만을 넘어가면 for이 멈추기 때문에
	//넘어서면 넘어서기 이전값을 찾아야됨 / n도 같다
	printf("%d", v);
	printf("\n%d", --n);
	return 0;
}

//2,3의 배수가 아닌 수 출력
#include <stdio.h>
int main()
{
	int n = 0;
	while (n <= 50)
	{
		n++;
		if (n % 2 == 0 || n % 3 == 0)
			continue;
		printf("%d\n", n);
	}
	return 0;
}

//3.30
//구구단 단만큼 구구단이 출력되는 프로그램
#include <stdio.h>
int main()
{
	int dan = 2, i = 1;
	for (dan = 2; dan <= 9; dan++)
	{
		printf("==============\n");
		for (i = 1; i <= dan; i++)
		{
			printf("%d * %d = %d\n", dan, i, dan * i);
		}
		printf("\n");
	}
	return 0;
}
//+짝수의 단만 출력하는 구구단
#include <stdio.h>
int main()
{
	int dan = 2, i = 1;
	for (dan = 2; dan <= 9; dan++)
	{
		if (dan % 2 == 0)
		{
			printf("==============\n");
			for (i = 1; i <= dan; i++)
			{
					printf("%d * %d = %d\n", dan, i, dan * i);
			}
			printf("\n");
		}
		else
			continue;
	}
	return 0;
}

//A Z + Z A 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, v1 = 0, v2 = 0;
	printf("복연산 할 수를 입력하세요");
	scanf("%d %d", &a, &b);
	v1 = 10 * a + b;
	v2 = 10 * b + a;
	printf("%d", v1 + v2);
	return 0;
}

//A Z + Z A경우의 수 프로그램
#include <stdio.h>
int main()
{
	int A=0, Z=0, ans=0;
	for (A = 0; A < 10; A++)
	{
		for (Z=0; Z < 10; Z++)
		{
			if (A == Z)
				continue;
			ans = (A * 10 + Z) + (Z * 10 + A);
			if (ans == 99)
				printf("A = %d, Z = %d\n", A, Z);
		}
	}
	return 0;
}

//1~5중 입력된 값을 switch를 사용해 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	printf("1~5 사이의 값을 입력하세요");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		printf("1입니다");
		break;
	case 2:
		printf("2입니다");
		break;
	case 3:
		printf("3입니다");
		break;
	case 4:
		printf("4입니다");
		break;
	case 5:
		printf("5입니다");
		break;
	default:
		printf("그 외의 숫자입니다");
	}
	return 0;
}

//다이아몬드 과제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main()
{
	int num = 0, NUM = 0, i = 0, j = 0, a = 0, b = 0;
	while (1)
	{
		printf("높이입력(홀수만 입력시 실행됩니다)");
		scanf("%d", &num);
		if (num % 2 != 0 && num > 0)
		{
			break;
		}
	}
	NUM = num / 2;
	for (i = 0; i < num; i++)
	{
		if (i <= NUM)
		{
			for (a = 0; a < NUM - i; a++)
			{
				printf(" ");
			}
			for (j = 0; j < i * 2 + 1; j++)
			{
				printf("*");
			}
		}
		if (i > NUM)//5
		{
			for (a = 0; a < i - NUM; a++)
			{
				printf(" ");
			}
			for (j = 0; j < num - ((i-NUM) * 2); j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}

//3.31
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("점수를 입력하세요");
	scanf("%d", &a);
	if (90 < a)
		printf("A");
	if (a <= 90 && a > 80)
		printf("B");
	if (a <= 80 && a > 70)
		printf("C");
	else
		printf("F");
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("점수를 입력하세요");
	scanf("%d", &a);
	if (a >= 80)
		printf("합격");
	else
		printf("불합격");
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b;
	printf("수 두개를 입력하세요");
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("%d", a - b);
	else
		printf("%d", b - a);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("나이를 입력하세요");
	scanf("%d", &a);
	if (a >= 20)
		printf("adult");
	else
		printf("%dyears later", 20 - a);
	return 0;
}

//(5) 숫자 3개 입력받아서 젤 값을 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("수 세 개를 입력하세요");
	int value,big=0,three=0;
	while (three < 3)
	{
		printf("\n수를 입력하세요");
		scanf("%d", &value);
		if (value > big)
			big = value;
		three++;
	}
	printf("\n%d", big);

	return 0;
}