//&(AND) = 두 개의 비트 모두 참일 때 1을 반환
//|(OR) = 두 개의 비트중 하나라도 참일 때 1을 반환
//^(XOR) = 두 개의 비트가 서로 다른 경우에 1을 반환
//~(NOT) = 비트를 0에서 1로, 1에서 0으로 반전시킨다
// (MSB도 반전되어 부호도 바뀐다)
//MSB = 최상위 비트
//LSB = 최하위 비트
//<< / >> (shift) = 비트열을 n칸씩 이동
//(예) num = 15 num<<1 = num의 비트 열을 왼쪽으로 1칸씩 이동 = 30)
//sizeof = 변수,상수,자료형의 크기를 확인 할 수 있다
//ASCII 번호와 문자를 사용해 전환할 수 있다
//getchar = scanf를 사용하다 버퍼 문제(값을 입력하고 enter를 누른다면 enter이 다음 scanf에 들어감)
//가 일어나면 getchar(); 를 코드에 추가해 해결할 수 있다
//int형 연산이 short형 연산보다 빠르게 연산된다
//피연산자의 자료형 불일치로 발생하는 자동 형변환(typcasting)
//(예)int n1=3,n2=4 double d   d=n1/n2;
//=>3/4=0 하지만 자동으로 double형으로 형변환 해 계산된다)

//3.15
 #include <stdio.h>
int main()
{
	int num1 = 15; //00000000 00000000 00000000 00001111 (1+2+4+8)
	int num2 = 20; //00000000 00000000 00000000 00010100 (4+16)
	int num3 = num1 & num2; //num1과 num2의 비트단위 & 연산
	printf("AND 연산의 결과: %d \n",num3);	
	return 0;
} 

#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 1, d = 1;
	printf("%d", a == b & c ==d);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1 = 15, n2 = 20;
	int answer = n1 | n2;
	printf("%d", answer);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	printf("두 정수를 입력하세요");
	scanf_s("%d %d", &a, &b);
	printf("%d", a | b);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2;
	printf("%d\n", n);
	printf("%d\n", n << 1);
	printf("%d\n", n << 2);
	printf("%d\n", n << 3);
	printf("%d\n", n << 4);
	printf("%d\n", n << 14);
	printf("%d\n", n << 30);//overflow (자료형이 수를 다 못담음)
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 1024;
	printf("%d\n", n);//00000100 00000000
	printf("%d\n", n >> 1); 
	printf("%d\n", n >> 2);
	printf("%d\n", n >> 3);
	printf("%d\n", n >> 9);
	printf("%d\n", n >> 10);
	printf("%d\n", n >> 11);//0
	printf("%d\n", n >> 12);//0
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	n = ~n;
	n++;
	printf("%d\n", n);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ch = 9;
	printf("ch의 크기 : %d\n", sizeof(ch));
	printf("숫자 9의 크기 : %d\n", sizeof(9));
	int n = 9;
	printf("n의 크기 : %d\n", sizeof(n));
	printf("숫자 9의 크기 : %d\n", sizeof(9));
	double d = 9.1234;
	printf("d의 크기 : %d\n", sizeof(d));
	printf("숫자 9.1234의 크기 : %d\n", sizeof(9.1234));
	return 0;
}

//반지름을 입력받아 원넓이를 구하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double area = 0, r = 0;
	printf("반지름을 입력하세요");
	scanf("%lf", &r);
	area = r * r * 3.14;
	printf("반지름 %.lf의 원의 넓이는 %1.lf입니다", r,area);
	return 0;
}


//3.16
#include <stdio.h>
int main()
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;
	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);

	return 0;
}

//ASCII번호 > 문자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n= 0;
	scanf("%d", &n);
	printf("ASCII 문자 %c\n", n);
	return 0;
}

//ASCII문자 > 번호
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char n= 0;
	scanf("%c", &n);
	printf("ASCII 번호 %d\n", n);
	return 0;
}

//getchar사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
		int n= 0;
	scanf("%d", &n);
	printf("ASCII 문자 %c\n", n);
	getchar();
		char n= 0;
	scanf("%c", &n);
	printf("ASCII 번호 %d\n", n);
	return 0;
}

//두 점을 입력받아 사각형의 넓이를 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	int x = 0, y = 0, a = 0;
	printf("사각형의 좌 하단의 x,y좌표를 입력하세요");
	scanf("%d %d", &x1, &x2);
	getchar();
	printf("사각형의 우 상단의 x,y좌표를 입력하세요");
	scanf("%d %d", &x3, &x4);
	x = x3 - x1;
	y = x4 - x2;
	a = x * y;
	printf("사각형의 넓이 %d", a);
	return 0;
}

//3.17
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d", &a, &b);
	c = ++a + b--;
	printf("a = %d,b = %d,c = %d", a,b,c);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a = 0, b = 0, c = 0;
	float avg = 0;
	printf("정수로 된 3과목의 점수를 입력하세요");
	scanf("%f %f %f", &a, &b, &c);
	avg = (a + b + c) / 3;
	printf("avg = %.1f", avg);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a = 0, b = 0, c = 0, sum = 0, avg = 0;
	printf("실수로 된 3과목의 점수를 입력하세요");
	scanf("%f %f %f", &a, &b, &c);
	avg = a + b + c;
	avg = avg / 3;
	printf("%d\n", (int)a + (int)b + (int)c);
	printf("%.f", avg);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a > b));
	printf("%d\n", (b >= c));
	printf("%d\n", (a <= b));
	printf("%d\n", (b < c));
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double A = 0, B = 0, C = 0;
	printf("yard? ");
	scanf("%lf", &A);
	B = A * 91.44;
	printf("%.1fyard = %.1f", A, B);
	return 0;
}

//3.18
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d %d %d %d %d", a + 3, a - 3, a * 3, a / 3, a % 3);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 10, b = 10;
	printf("최초값 a = %d, b = %d\n\n", a, b);
	printf("a++ = %d, ++b = %d\n", a++, ++b);
	printf("실행후 a = %d, b = %d\n\n", a, b);
	printf("a-- = %d, --b = %d\n", a--, --b);
	printf("실행후 a = %d, b = %d", a, b);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a += 100, b %= 10);
	printf("%d %d", a , b);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("%s\n", "수를 출력할 때는 따옴표를 생략합니다");
	printf("%d\n",123);
	printf("%f\n",6.5);
	printf("%f\n",68.6);
	printf("%d + %d = %d\n",10,5,10+5);
	printf("내 생일은 %d년 %d월 %d일 입니다\n",2005,07,05);
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d초는 %d분 %d초 입니다.", a, a / 60, a % 60);
	return 0;
}

//(6)
#include <stdio.h>
int main()
{
	printf("\na\n");//줄바꿈
	printf("\fa\n");
	printf("\ta\n");//tab
	printf("\\a\n");
	printf("\va\n");
	printf("\"a\n");
	return 0;
}

//(8)
#include <stdio.h>
int main()
{
	int a = 123;
	printf("%8d\n", a);//출력할 공간 8칸확보
		printf("%-8d", a);
	return 0;
}