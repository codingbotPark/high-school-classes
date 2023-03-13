// typedef struct books BB;
// 구조체를 사용할 때는 코드가 길어지기 때문에
// typedef를 사용하여 struct book 를 BB라 적어도 될 수 있게 한다
// 
// 구조체 안 변수들을 멤버라 한다
// 구조체명.멤버 를 사용하여 구조체를 사용할 수 있다
// 
// 16과 6의
// 최대 공약수(GCD)를 구할 때는
// 16의 약수	1, 2, 4, 8, 19
// 6의 약수		1, 2, 3, 6
// 최대 공약수 = 2
// 
// 최소 공배수(LCM)를 구할 때는
//  2 l 16  6
//    --------
//       8  3
// 더 이상 공약수로 나누어지지 않을 때 까지 하면
// 2 x 8 x 3 = 24
// 최대 공배수 = 24
// 
// 유클리드 호제법
// 2개의 자연수 또는 정식(整式)의 최대공약수를 구하는 알고리즘의 하나이다. 
// 호제법이란 말은 두 수가 서로(互) 상대방 수를 나누어(除)서 
// 결국 원하는 수를 얻는 알고리즘을 나타낸다. 
// 2개의 자연수(또는 정식) a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면(단, a>b), 
// a와 b의 최대공약수는 b와 r의 최대공약수와 같다. 
// 이 성질에 따라, b를 r로 나눈 나머지 r'를 구하고, 
// 다시 r을 r'로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때 
// 나누는 수가 a와 b의 최대공약수이다.
// 
// 최대 공약수를 구하면 최소 공배수를 쉽게 구할 수 있다.
// (
// a, b 의 최대 공약수가 A 라면 
// (a * b) / A = 최소 공배수
// )
// 

//5.31
//구조체를 활용한 예시
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct Books BB;
struct Books
{
	char name[30];
	char auth[30];
	char publ[30];
	int borrowed;
};
int main()
{
	BB book_list[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		printf("책 %d 정보 입력 : ", i+1);
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
		book_list[i].borrowed = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("--------------");
		printf("책 %s 의 정보\n", book_list[i].name);
		printf("저자 : %s\n", book_list[i].auth);
		printf("출판사 : %s\n", book_list[i].publ);
		if (book_list[i].borrowed == 0)
		{
			printf("안 빌려짐\n");
		}
		else
		{
			printf("빌려짐 \n");
		}
	}
	return 0;
}
//+내가 만든 예시
// 연락처 (입력 / 확인) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct CI
{
	char name[10];
	long int number;
	char relation[10];
};
int main()
{
	struct CI CI[10] = { 0, };
	int choice;
	int last = -1;
	char dname[10];
	while (1)
	{
		printf("\n------------------------\n");
		printf("연락처를 확인하려면 1번\n");
		printf("연락처를 입력하려면 2번\n");
		printf("------------------------\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("\n------------------------\n");
			for (int i = 0; i <= last; i++)
			{
				printf("%7s\t 0%ld %7s\n", CI[i].name, CI[i].number, CI[i].relation);
				//CI[i].number 을 long int 로 선언해서
				//첫 010에 0이 삭제되는 오류가 있어서
				//0%ld
			}
			printf("------------------------\n");
		}
		else if (choice == 2)
		{
			printf("\n------------------------\n");
			printf("이름을 입력하세요  \t");
			scanf(" %s",&CI[last+=1].name);
			printf("전화번호를 입력하세요\t");
			scanf(" %ld", &CI[last].number);
			printf("관계를 입력하세요  \t");
			scanf(" %s", &CI[last].relation);
			printf("------------------------\n");
		}
		else
		{
			printf("\n------------------------\n");
			printf("1, 2 중 하나의 수를 입력해주세요");
			printf("\n------------------------\n");
			break;
		}
	}
	return 0;
}

//피타고라스법칙을 사용하여 점의 거리를 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
typedef struct Point
{
	int x; int y;
}Point;
int main()
{
	Point p1; Point p2;
	p1.x = 30; p1.y = 20;
	p2.x = 60; p2.y = 50;
	double sol;
	double a = 0;
	double b = 0;
	a = p2.x - p1.x;
	b = p2.y - p1.y;
	sol = sqrt(a * a + b * b);
	printf("%f\n", sol);
	return 0;
}

//6.1
//최대공약수, 최소공배수
#include <stdio.h>
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
// 16 과 6을 입력하면
// 6	4(16%6)
// 4	2(6%4)
// 2	0(4%2)
// 이 b값이 0이 되면 a = 2
// 즉 최대 공약수는 2
// 
// 
int main()
{
	int a = 16, b = 6;
	printf("최대공약수 : %d\n", gcd(a, b));
	printf("최소공배수 : %d\n", a * b / gcd(a, b)); 
	// a * b / (a, b) 인 이유는 
	// 6	12 18 24 30 36 42 48
	// 16	32 48
	// 
	// 6 * 16 = 96 요기서 최대공약수로 나누면 최소공배수가 나온다  
	//
	return 0;
}

//소수판별
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!(n % i)) //if((n%i)==0) 과 같다는 말이다 즉 소수가 아닐 때
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i = 0;
	int j = 0;
	while (1) 
	{
		int n;
		printf("숫자 : ");
		scanf("%d", &n);
		if (n < 2) return 0;
		if (n >= 1000)
		{
			printf("\n");
			continue;
		}
		for (i = 2; i <= n; i++)
		{
			if (isPrime(i))
			{
				printf("%d");
			}
			//그냥 for 문을 사용 할 때
			//for ( j = 2; j*j < i; j++) // 10이 있다면 2, 3 만 바교하면 되기 때문에
			//{
			//	if (i % j == 0)
			//	{
			//		break;
			//	}
			//}
			//if (j == i)
			//{
			//	printf("%d ",i);
			//}
		}
		printf("\n");
	}
	return 0;
}