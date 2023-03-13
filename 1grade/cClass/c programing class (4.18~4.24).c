 //static = 지역변수인데 전역변수와 같이 사용할 수 있다
 //(static을 사용하면 초기화가 한 번 만 된다) 
 //(전역변수는 사람에게는 편하지만 컴퓨터에게는 힘들다)
 //(단 지역변수이기 때문에 main에서는 사용할 수 없다)
 //일차원 배열의 이름은 주소이다
 //'a'와 "a"의 차이 = 'a'는 문자 "a"는 문자열
 //("a"는 문자열이 있다)
 //(sizeof로 글자의 수를 알 수 있다)
 //(\n은 한 문자로 취급한다)
 //(문자열을 출력 할 때 널문자까지 출력한다)
 //(문자열 중간에 널문자가 있으면 끝까지 출력을 못한다)
 //& = 주소 배열의 이름 = 주소 
 //(scanf에 &을 넣지 않아도 된다)

//4.19
//전역변수 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int func(int n)
{
	static int a = 0;
	a++;
	printf("a = %d, n = %d\n",a,n);
	return 0;
}
int main()
{
	func(5);
	func(5);
	return 0;
}

//일차원 배열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	int ar[5];
	ar[0] = 0;
	ar[1] = 0;
	ar[2] = 0;
	ar[3] = 0;
	ar[4] = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d번째 배열에 들어갈 수를 입력하세요", i);
		scanf("%d", &ar[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d번째 배열에 있는 수 = %d\n", i, ar[i]);
	}
	return 0;
}

//배열중 가장 큰 값의 위치를 알려주는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, a = 0;
	int ar[5];
	for (i = 0; i < 5; i++)
	{
		ar[i] = 0;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d번째 배열에 들어갈 수를 입력하세요", i);
		scanf("%d", &ar[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		if (a < ar[i])
		{
			a = i;
		}
	}
	printf("인덱스 %d의 수가 가장 크다", a);
	return 0;
}

//배열중 최소값, 총합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, min = 0, a = 0;
	int ar[5];
	for (i = 0; i < 5; i++)
	{
		ar[i] = 0;
	}
	for (i = 0; i < 5; i++)
	{
	printf("%d번째 배열에 들어갈 수를 입력하세요", i);
		scanf("%d", &ar[i]);
		min = ar[i];
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		if (min > ar[i])
		{
			min = ar[i];
		}
		a += ar[i];
	}
	printf("최소값 = %d 총합 = %d",min,a);
	return 0;
}

//문자와 문자열,널문자
#include <stdio.h>
int main()
{
	char str[] = "Hello World\n";
	printf("str = %s\n", str);
	printf("str의 크기 %d\n", sizeof(str));
	printf("%d\n", sizeof("Hello"));
	char str1[10];
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	str1[4] = 'd';
	str1[5] = 'e';
	printf("str1 = %s\n", str1);
	return 0;
}

//입력한 문자열을 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char str[20];
	scanf("%s", str);
	while (str[i] != '\0')
		printf("%c", str[i++]);
	return 0;
}

//반대로 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	char str[100];
	scanf("%s", str);
	while (1)
	{
		if (str[a] == '\0')
		{
			break;
		}
		a++;
	}
	for (a; a >= 0; a--)
		printf("%c", str[a]);
	return 0;
}
//+서준이코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strlen(char str[])
{
	int len = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		len++;
	}
	return len;
}
int main()
{
	char str[20];
	scanf("%s", str);
	int len = strlen(str);//string글자 length길이
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
//+선생님코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[20];
	int i = 0;
	scanf("%s", str);
	while (str[i] != '\0')
	{
		i++;
	}
	for (i--; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
//+띄어쓰기 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[20];
	int i = 0;
	scanf("%[^\n]", str);
	printf("%s\n", str);
	return 0;
}

//주말과제(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	//영어 문장을 입력받아
	//영어단어의 소문자의 길이(갯수)를 알려주는 프로그램을 만드시오.
	char word[50];
	int i = 0, j = 0;
	for (i = 0; i < 50; i++)
	{
		word[i] = 0;
	}
	scanf("%[^\n]", word);
	//예시 Hello 라면 4 출력
	//I Love you 라면 소문자 개수 6 출력
	for (i = 0; i < 50; i++)
	{
		if (word[i] > 96 && word[i] < 123)
		{
			j++;
		}
	}
	printf("소문자 개수 : %d", j);
	return 0;
} 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char a;
	scanf("%c", &a);
	printf("%d", a);
	return 0;
}

//주말과제(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char word[100],j=0;
	for (i = 0; i < 100; i++)
	{
		word[i] = 0;
	}
	scanf("%s", &word);
	for (i = 0; word[i] > 0; i++)
	{
		if (j < word[i])
		{
			j = word[i];
		}
	}
	printf("%c", j);
	return 0;
}

//문자열뒤집기과제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100];
	int i = 0, j = 0;
	printf("뒤집을 문자열을 입력하세요");
	for (i = 0; i < 99; i++)
	{
		str[i] = 0;
	}
	//scanf("%s", &str);이렇게 하면 왜 안되는지, %s로 scanf를 
	//받으면 어떤 원리로 스페이스바에서 짤리는지
	//scanf("%[^\n]", str);
	fgets(str, 100, stdin);
	for (i = 0; i < 99; i++)
	{
		if (str[i] == '\n')
		{
			j = i-1;
		}
	}
	for (j; j >= 0; j--)
	{
		printf("%c", str[j]);
	}
	return 0;
}

//배열예제
// (두 개의 배열을 사용
// 첫번 째 줄에 첫번 째, 두번째 배열에 넣을 수의 개수
// 두번 째 줄에 첫번 째 배열에 넣을 수
// 세번 째 줄에 두번 째 배열에 넣을 수
//
// 이 두 배열의 수들을 오름차순으로 나열하는 프로그램
// )
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, j, n = 0, m = 0, c = 0, d = 0;
	int a[999], b[999];
	scanf("%d %d", &i, &j);
	for (n = 0; n < i;n++)
	{
		scanf("%d", &a[n]);
	}
	for (n = 0; n < j; n++)
	{
		scanf("%d", &b[n]);
	}
	n = 0;
	while (1)
	{
		if (a[n] > b[m] || c == 1)
		{
			printf("%d ", b[m]);
			m++;
		}
		else if (a[n] < b[m] || d == 1)
		{
			printf("%d ", a[n]);
			n++;
		}
		else
		{
			printf("%d %d ", a[n], b[m]);
			n++;
			m++;
		}
		if (n == i && m == j)
		{
			break;
		}
		if (n >= i)
		{
			c = 1;
		}
		if (m >= j)
		{
			d = 1;
		}
	}
	return 0;
}

//4.21
//(1)
MAX = 6;
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int j = 0;
	float i=0, ar[6];
	for (j = 0; j < MAX; j++)
	{
		printf("6명의 체중을 입력하세요");
		scanf("%f", &ar[j]);
		i += ar[j];
	}
	i /= MAX;
	printf("%.1f", i);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[10], i = 0, odd = 0, even = 0;
	for (i = 0; i < 10; i++)
	{
	printf("정수를 입력하고 enter을 누르세요");
		scanf("%d", &ar[i]);
		if (i % 2 == 0)//홀수번째 수
		{
			odd += ar[i];
		}
		else
		{
			even += ar[i];
		}
	}
	printf("odd = %d\n", odd);
	printf("even = %d\n", even);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[100], i = 0, a = 0, b = 0, max = 0, min = 0;
	for (i = 0; i < 100; i++)
	{
		printf("배열의 %d번째 수를 입력하고 enter를 누르세요", i);
		scanf("%d", &ar[i]);
		if (ar[i] == 999)
		{ 
			if (i == 0)
			{
				return 0;
			}
			break;
		}
		if (i == 0)
		{
			max = ar[i];
			min = ar[i];
		}
		if (max < ar[i])
		{
			max = ar[i];
		}
		if (min > ar[i])
		{
			min = ar[i];
		}
	}
	printf("\n");
	printf("max = %d\n", max);
	printf("min = %d\n", min);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char i ,j = 0;
	scanf("%c", &j);
	while (1)
	{
		scanf("%c", &i);
		if ('\n' == i)
		{
			printf("\"Hello\"");
		}
		if ('\n'!=i)
		{
			break;
		}
	}
	return 0;
}

//4.22
//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int k, e, m,average;
	printf("국어, 영어, 수학 성적을 입력하세요");
	scanf("%d %d %d", &k, &e, &m);
	average = (k + e + m) / 3;
	if (average >= 80)
	{
		printf("합격!\t");
		printf("평균점수 = %d",average);
	}
	else
	{
		printf("불합격!\t");
		printf("부족한 점수 = %d", 80 - average);
	}
	return 0;
}

//(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int head, leg;
	scanf("%d %d", &leg, &head);
	printf("토끼 : %d\t 닭 : %d\t", (leg / 2) - head, head * 2 - (leg / 2));
	return 0;
}

//(7)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ar[30], j = 0, c = 0;
	int  i = 0,n=0;
	printf("초기값을 입력하세요");
	scanf("%s", ar);
	while (1)
	{
		printf("수정 희망 인덱스를 입력하세요");
		scanf("%d", &j);
		printf("수정값을 입력하세요");
		scanf(" %c", &i);
		ar[j-1] = i;
		printf("%s", ar);
	}
	return 0;
}