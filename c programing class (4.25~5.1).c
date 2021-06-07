// 포인터 (pointer) = 주소를 저장하는 변수
// [명사][정보·통신] 컴퓨터 그래픽스에서, 항목을 선택하기 위한 
// 마우스 같은 위치 결정 장치를 갖고 사용자가 이동시킬 수 있는, 
// 화면에 표시된 기호.⇒규범 표기는 미확정이다.
// 
// 포인터 = 주소를 저장하는 변수
// 즉 포인터는 연산이 가능하다(변수여서)
// 
// 선언하는 법
// int* p;
// 
// 주소를 출력할 때 는 %p를 사용한다(16진수 사용)
// 
// 포인터 예제
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// int main()
// {
// 	int* p;						int* p = 정수를 가르키는 포인터변수
// 	int a = 100;
// 	printf("%d\n", 100);
// 	p = &a;						p는 a의 주소값을 가리키게 됨
// 	printf("%p\n", &a);
// 	printf("%d\n", a);
// 	printf("%d %p\n", *p, p);	*p = p의 주소가 가르키는 값	p = 주소 
// 	return 0;
// }
// 
// 포인터에 증감연산자를 사용 할 때 괄호를 해준다
// (괄호를 함 = 주소가 가르키는 값이 증감연산자를 거친다
// 괄호를 하지 않음 = 주소가 증감연산자를 거친다)
// 
// 배열은 첫 번재 요소의 주소 값을 나타낸다
// 배열 a와 배열 a[0] 의 주소는 같다
// (배열 이름과 배열 첫번째의 주소는 같다) 
// int형 배열에 무언갈 넣는다면 한칸한칸마다 
// 4byte를 사용한다
// => 첫 번째 배열의 주소에서 주소를 4씩 플러스하면 다음값이 나온다
// 
//							포인터		배열이름
// 이름이 존재하는가	물론 있다		당연히 있다
// 무엇을 나타내는가	메모리의 주소	메모리의 주소
// 변수인가 상수인가	변수			상수
// 
// 즉 
// int main()
// {
//		int a[5] = {0,1,2,3,4};
//		int b = 10;
//		a = &b; //a는 상수이므로 오류, a가 변수였다면
// }

//4.26
//포인터 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int* p;
	int a = 100;
	printf("%d\n", a);
	p = &a;
	printf("%p\n", &a);
	printf("%d\n", a);
	printf("%d %p\n", *p, p);
	*p = 300;
	printf("%d\n", a);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num1 = 100, num2 = 100;
	int* pNum;
	pNum = &num1;
	(*pNum) = 50;
	pNum = &num2;
	(*pNum) = -30;
	printf("%d %d\n", num1, num2);
	int n1 = 100;
	int* p;
	p = &n1;
	printf("주소(Address) :%p, &p\n", p, &n1);
	printf("내용, 값 :%d, %d\n", *p, n1);
	for (int i = 0; i < 5; i++)
	{
		printf("%4d", (*p)++);
	}
	printf("\n%d\n", n1);
	return 0;
}

//배열과 포인터의 관계
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[5] = { 1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%p %p\n", &a[0], &a[1]);
	printf("a주소 = %p a[0]주소 = %p\n", &a, &a[0]);
	int* p = a;
	printf("a주소 = %p\n", p);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	int* p;
	p = arr;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p+1), *(p+2));
	int* P = arr;
	P[1] = 0;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%p\n", &P);
	printf("&p\n", arr[1]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	int* p;
	p = arr;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));
	int* P = arr;
	P[1] = 0;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%p\n", P);
	printf("%p\n", &arr[0]);
	return 0;
}

//포인터 예제 과제
//포인터로 입력을 받아 배열에 넣기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[10], i = 0;
	int* p = arr;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
		//scanf("%d", &(*p));
		scanf("%d", &*(p + i));
		//p += 4;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int* p,i=0;
	int arr[10];
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	p = arr;
	for (i = 0; i < 10; i++)		
	{
		scanf("%d",p);
		arr[i] = *p;
		p += 4;
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

//(4.29)
#define MAX 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int ar[MAX];
	for (i = 0; i < MAX; i++)
	{
		printf("%d번 학생의 프c성적을 입력하세요", i + 1);
		scanf("%d", &ar[i]);
	}
	for (i = 0; i < MAX; i++)
	{
		if (j < ar[i])
		{
			j = ar[i];
		}
	}
	printf("최고점수 : %d", j);
	return 0;
}
//빠른 변형이 가능한 코드
#define MAX 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int ar[MAX];
	for (i = 0; i < MAX; i++)
	{
		printf("%d번 학생의 프c성적을 입력하세요", i + 1);
		scanf("%d", &ar[i]);
	}
	j = ar[0];
	for (i = 0; i < MAX-1; i++)
	{
		if (j < ar[i+1])
		{
			j = ar[i+1];
		}
	}
	printf("최고점수 : %d", j);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[5];
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		printf("양수를 입력하세요");
		scanf("%d", &ar[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\t", ar[i]);
	}
	for (i = 0; i < 5; i++)
	{
		if (ar[i] > j)
		{
			j = ar[i];
		}
	}
	printf("\n최대값 : %d", j);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[100];
	int i = 0, j = 0;
	float v = 0;
	printf("성적을 입력받을 학생의 수를 입력하세요");
	scanf("%d", &i);
	for (j = 0; j < i; j++)
	{
		printf("%d번째 학생의 성적을 입력하세요", j + 1);
		scanf("%d", &ar[j]);
		v += ar[j];
	}
	v = v / i;
	printf("평균 : %.2f", v);
	return 0;
}