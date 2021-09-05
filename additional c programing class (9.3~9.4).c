//정수를 입력받고  a b c f 등급
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a;
	char b;
	scanf("%f", &a);
	if (a > 90)
	{
		b = 'A';
	}
	else if (a >= 80)
	{
		b = 'B';
	}
	else if (a >= 70)
	{
		b = 'C';
	}
	else
	{
		b = 'F';
	}
	printf("%c", b);

	return 0;
}

//1부터 입력받은 수까지 더하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a,b;
	printf("수를 입력하세요 : ");
	scanf("%d", &a);
	b = (a + 1) * (a / 2);
	if (a % 2 == 1)//홀수일 때
	{
		b += (a / 2) + 1;
	}
	printf("%d", b);
	return 0;
}

//입력한 단을 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("단을 입력하세요");
	scanf("%d", &a);
	for (int i = 1; i < 10; i++)
	{
		printf("%d X %d = %d\n", a, i, a * i);
	}
	return 0;
}

//1부터 입력한 수까지 중 3의 배수를 제외한 수를 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		if (i % 3 == 0)
		{
			continue;
		}
		printf("%d ", i);
	}
	return 0;
}


//1부터 입력한수까지 홀수의 경우 덧셈, 짝수의 경우 뺄셈 하여 모든 수의 합계
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a,b=0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		if (i % 2 == 1)
		{
			b += i;
		}
		else
		{
			b -= i;
		}
	}
	printf("%d", b);
	return 0;
}

//문자열의 길이, 문자열, 특정문자를 입력받아 특정 문자의 개수 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	char c;
	int  n, cnt = 0;

	printf("문자열 길이 입력 : ");
	scanf(" %d", &n);
	printf("문자열 입력 : ");
	scanf(" %s", str);
	printf("특정 문자 입력 : ");
	scanf(" %c", &c);

	for (int i = 0; i < n; i++)
	{
		if (str[i] == c)
		{
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}

//영어 소문자는 대문자로, 대문자는 소문자로 바꾸기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	char c;
	int n, cnt = 0;

	printf("문자열 길이 : ");
	scanf("%d", &n);
	printf("문자열 입력 : ");
	scanf(" %s", str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] > 90)
		{
			printf("%c", str[i] - 'a' + 'A');
		}
		else
		{
			printf("%c", str[i] + 'a' - 'A');
		}
	}
	return 0;
}


//정렬하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a[100] = { 0, }, b, temp = 0;
	srand((unsigned)time(NULL));

	printf("생성할 수의 개수를 입력하세요 : ");
	scanf("%d", &b);

	for (int i = 0; i < b; i++)
	{
		a[i] = rand() % 100;
	}

	for (int i = 0; i < b-1; i++)
	{
		for (int j = 0; j < b - 1 - i ; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < b; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}

//피보나치 수열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	int a = 1, b = 1, c = 0;
	scanf("%d", &n);
	for (int i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d", c);
	return 0;
}
//이렇게 3개의 변수를 사용하면 예전의 피보나치 수열값을 알 수 없다
//즉 같은 계산이 계속 필요하면 배열과 같은 곳에 기록을 함으로써
//중복되는 경우에 계산하는 과정을 없앤다
//이 기법을 메모이제이션이라 한다
//+재귀함수로 피보나치
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[100];

int p(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return p(n - 1) + p(n - 2);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", p(n));

	return 0;
}	
//재귀함수 = 결과중심
//반복문 = 과정중심
//재귀함수에서 리턴한 값이 돌아가는 것을 백트레킹이라 한다
//
//입력된 문자열을 거꾸로 저장한 후 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[100], tmp;
	int i;

	scanf(" %s", &str);
	for (i = 0;; i++)
	{
		if (str[i] == NULL)
		{
			break;
		}
	}
	for (int j = 0; j < i / 2; j++)
	{
		tmp = str[j];
		str[j] = str[(i-1) - j];
		str[(i-1) - j] = tmp;
	}
	printf("%s", str);
	return 0;
}

//문자열길이 측정
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	int i;
	scanf("%s", &str);
	for (i = 0;; i++)
	{
		if (str[i] == NULL)
		{
			break;
		}
	}
	printf("%d", i);
	return 0;
}

//문자열을 비교하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[100];
	int i;
	scanf("%s %s", str1, str2);
	if (strlen(str1) == strlen(str2))
	{
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				break;
			}
		}
		if (i == strlen(str1))
		{
			printf("같다");
			return 0;
		}
	}
	printf("다르다");
	return 0;
}

//문자열을 다른 배열에 복사하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = { 0, }, str2[100] = { 0, };
	int i;
	scanf("%s", str1);

	for (i = 0; i < strlen(str1); i++)
	{
		str2[i] = str1[i];
	}

	printf("%s\n%s", str1, str2);
	return 0;
}

//첫 번째 문자열 뒤에 두 번째 문자열을 붙이기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = { 0, }, str2[100] = {0,};
	int i, j;
	scanf("%s %s", str1, str2);
	j = strlen(str2);
	i = strlen(str1);
	for (int k =0; k < j;k++)
	{
		str1[i + k] = str2[k];
	}
	printf("%s", str1);
	return 0;
}