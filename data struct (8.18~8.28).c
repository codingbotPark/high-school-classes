// 8.18~8.21
// extern 이라는 예약어는	
// 다른파일의 변수를 쓸 수 있다
// 예)
// extern void func1();
// 을 선언하면 다른 파일의 func1() 을 사용할 수 있다'
// 
// 포인터(pointer) = 가르키는 것
// & 연산자 = 변수의 주소를추출
// * 연산자 = 포인터가 가르키는 곳의 내용을 추출
// 즉 예) int* p; = 정수형 변수를 가르키는 포인터이다
// 포인터의 포인터를 활용해 차원에 쉽게 접근할 수 있다
// 
// 배열의 이름은 사실상 포인터와 같은 역할이다

// 8.22~8.28
// call by value = 값에 의한 호출
// call by reference = 참조에 의한 호출
// 
// call by value는 인자로 받은 값을 복사하여 처리를 한다
// call by reference는 인자로 받은 값의 주소를 참조하여 직접 값에 영향을 준다
// 즉  값을 복사를 하여 처리하느냐, 직접 참조를 하느냐 차이이다
// 
// call by value
// 장점 = 복사를 하여 처리해서 안전하다. 원래 값이 보존된다
// 단점 = 복사를 해서 메모리가 사용량이 늘어난다
// 
// call by reference
// 장점 = 복사하지 않고 직접 참조를 하기에 빠르다
// 단점 = 직접 참조를 하기에 원래 값이 영향을 받는다
// 
// 링크드 리스트
// 내가 필요할 때마다 만들면 되서 메모리를 효율적으로 사용할 수 있다

//8.19
//포인터
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int i = 7;//전역변수(메모리의 데이터영역)
void func1();
void func2();

int main()
{
	int i = 5;//지역번수(메모리의 stack영역)
	func1();
	i++;
	printf("i=%d\n", i);//지역변수의 i
	return 0;
}

void func1()
{
	i++;//전역변수의 i
	printf("func1 i = %d \n", i);
	func2();
}

void func2()
{
	i++;//전역변수의 i
	printf("func2 i=%d \n", i);
}



#include <stdio.h>
int main()
{
	static int i = 7, * p, ** pp;
	p = &i;//변수 i

	pp = &p;//변수 i를 가르키는 포인터의 포인터
	//즉 변수 i

	printf("p\'s Address = %p\n,p");
	printf("pp\'s Address = %p\n,pp");

	(*p)++;
	printf("i = %d \t", i);
	printf("*p = %d \t", *p);
	printf("**pp = %d \n", **pp);

	(**pp)++;
	printf("i = %d \t", i);
	printf("*p = %d \t", *p);
	printf("**pp = %d \n", **pp);

	return 0;
}

#include <stdio.h>
int main()
{
	char string[] = "Hello";
	char* pstr = string;//pstr은 문자열을 가르키는 포인터이다
	while (*pstr)//문자열의 null(끝) 까지 실행한다
	{
		putchar(*pstr++);//putchar는 printf에 %c 와 같은 역할을 한다	
		//++을 만나면서 다음단어가 출력된다
	}

	return 0;
}

//8.23
//call by value
//call by reference
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap1(int a, int b)//call by value
{
	int t = a;
	a = b;
	b = t;
}

void swap2(int* a, int* b)//call by reference
{
	int t = *a;
	*a = *b;
	*b = t;
}//포인터를 사용해서 swap호출 후에도 값이 변경되어 있음

int main()
{
	int n1 = 5, n2 = 7;
	printf("n1 = %d, n2 = %d\n", n1, n2);
	swap1(n1, n2);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	swap2(&n1, &n2);//포인터를 사용하기 때문에 주소를 넘겨야 한다
	printf("n1 = %d, n2 = %d\n", n1, n2);

	return 0;
}

//팩토리얼
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int c)
{
	return ((c == 0) ? 1 : c * factorial(c - 1));
}

int main()
{
	int n = 10;
	printf("%d! = %d", n, factorial(n));
	return 0;
}
//10이하의 값들이 모두 출력되도록 바꾸기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int d=0;
int factorial(int c)
{
	if (c == 0)
	{
		return 1;
	}
	d = c * factorial(c - 1);
	printf("%d! = %d\n",c, d);
	return d;
	//return c * factorial(c - 1);
	//return ((c == 0) ? 1 : c * factorial(c - 1));
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d! = %d", n, factorial(n));
	return 0;
}
//과제)팩도리얼을 반복문을 사용하여 구하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n,v=1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		v *= i;
	}
	printf("%d! = %d",n ,v);
	return 0;
}
//선택정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int a[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &a[i]);
	}
}

void output(int a[], int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void selectionSort(int a[], int cnt)//선택정렬
{
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (a[i] > a[j])//앞이 뒤보다 클 때
			{
				swap(&a[i], &a[j]);//call by reference
			}
		}
	}
}

int main()
{
	int n;
	int a[100];
	scanf("%d", &n);
	input(a,n);
	selectionSort(a, n);
	output(a, n);
	return 0;
}
+버블정렬숙제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <time.h>
#include <stdlib.h>

int main()
{
	srand((unsigned)time(NULL));

	int a[100];
	int b,c;
	int temp = 0;


	while (1)
	{
		printf("랜덤으로 수를 입력시키려면 1\n");
		printf("직접 수를 입력하려면 2번을 입력하세요\n\n");
		scanf("%d", &b);
		printf("\n\n생성할, 입력할 숫자의 수를 입력하세요\n\n");
		scanf("%d", &c);

		if (b == 1)
		{
			printf("\n\n정렬 전 : ");
			for (int i = 0; i < c; i++)
			{
				a[i] = rand() % 100;
				printf("%d\t", a[i]);
			}
			break;
		}
		else if (b == 2)
		{
			for (int i = 0; i < c; i++)
			{
				scanf("%d", &a[i]);
			}
			break;
		}
	}

	for (int i = 0; i < c ; i++)
	{//숫자의 개수만큼 돈다
		for (int j = 0; j < c-1; j++)
		{//+ 1을 하며 비교하기때문에 마지막 숫자는
			//비교하지 않아도 된다
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("\n\n\n정렬후 : ");
	for (int i = 0; i < c; i++)
	{
		printf("%d\t", a[i]);
	}

	return 0;
}