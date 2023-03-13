//#define _CRT_SECURE_NO_WARNINGS를 사용해 보안으로 인한 안내를 무시
//(제일 위에 적어야 한다)
//long -> %ld
//double -> %lf

//3.8
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

//3.9
반지름을 입력받아 원넓이를 구하는 코드
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

ASCII번호 > 문자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n= 0;
	scanf("%d", &n);
	printf("ASCII 문자 %c\n", n);
	return 0;
}

ASCII문자 > 번호
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

//3.10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
int Korean = 0, English = 0, math = 0, computer = 0, sum = 0, avg = 0;
printf("국어, 영어, 수학, 컴퓨터 과목 점수를 차례대로 입력하세요");
scanf("%d%d%d%d", &Korean, &English, &math, &computer);
sum = Korean + English + math + computer;
printf("sum %d\n", sum);
avg = sum / 4;
printf("avg %d", avg);
return 0;
}

#define _crt_secure_no_warnings
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("두 정수를 입력하세요");
	scanf("%d %d", &a, &b);
	printf(" %d / %d = %d . . . %d", a, b, a / b, a % b);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("가로 세로의 길이를 입력하세요");
	scanf("%d %d", &a, &b);
	a += 5;
	b = b * 2;
	printf("%d\n%d\n%d", a, b, a * b);
	return 0;
}

//3.11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("두 수를 입력하세요");
	scanf("%d %d", &a, &b);
	printf("%d %d", ++a, b--);
	printf("\n%d %d", a, b);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0,f=0;
	printf("민수의 키와 몸무게를 입력하세요");
	scanf("%d %d", &a, &b);
	printf("기영이의 키와 몸무게를 입력하세요");
	scanf("%d %d", &c, &d);
	printf("%d", (a > c && b > d) ? (e = 1) : (e = 0));
	return 0;
}

