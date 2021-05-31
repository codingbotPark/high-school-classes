//shift + Del키 = 한 줄 삭제
//#in 탭키 누르기
//ctrl + f7 = 컴파일
//ctrl + B = 빌드
//ctrl + = f5실행	
//alt + 방향키 = 줄이동
//ctrl + D = 복사

//3.1
#include <stdio.h>
int main()
{
	printf("Hello World\n");
	printf("Hello World");
	printf("Hello\n World");
	printf("\n천을로 70 105동 1504호");
	printf("\n%d", 1234);
	printf("%d%d", 10, 20);
	return 0;
}

#include <stdio.h>
int main()
{
	printf("My age : %d", 17);
	printf("나의 c언어 점수 : %d ", 100);
	return 0;
}

#include <stdio.h>
int main()
{
	int n1 = 1, n2 = 2, n3 = 3;
	printf("n1 = %d n2 = %d n3 = %d\n", n1, n2, n3);
	printf("n1 = %d n2 = %d n3 = %d\n", n1 + 1, n2 + 1, n3 + 1);
	printf("n1 = %d n2 = %d n3 = %d\n", ++n1, ++n2, ++n3);
	printf("n1 = %d n2 = %d n3 = %d\n", n1++, n2++, n3++);
	return 0;
}


#include <stdio.h>
int main()
{
	int n = 1;
	printf("n1=%d", n1);
	n1++;
	printf("n1=%d", n1++);
	printf("n1=%d", n1);


	return 0;
}

//3.2
#include <stdio.h>
int main()
{
	//비교연산자
	int n1 = 1, n2 = 2;
	int 결과=0;
	printf("결과 : %d\n", 결과);
	결과 = (n1 == n2);
	printf("결과 : %d\n", 결과);
	n2 = 1;
	결과 = (n1 == n2);
	printf("결과 : %d\n", 결과);
	결과 = (n1 >= n2);
	printf("결과 : %d\n", 결과);
	결과 = (n1 <= n2);
	printf("결과 : %d\n", 결과);
	결과 = (n1 > n2);
	printf("결과 : %d\n", 결과);
	결과 = (n1 < n2);
	printf("결과 : %d\n", 결과);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1=0, n2=0;
	scanf("%d", &n1);
	scanf("%d", &n2);
	printf("n1 = %d\nn2 = %d", n1,n2);\
	return 0;
}

//3.3
#include <stdio.h>
int main()
{
	printf("\tㅇ");

	return 0;
}

#include <stdio.h>
int main()
{
	printf("내\n이\n름");
	return 0;
}

#include <stdio.h>
int main()
{
	printf("안녕!!\n");
	printf("내 이름은 : 홍길동이야.");
	printf("나는 17살이야.");
	printf("나의 좌우명은 \"최선을 다해 노력하자\"");

	return 0;
}

//3.4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char d = 0;
	scanf("%c", &d);
	printf("%c", d);
	return 0;
}

#include <stdio.h>
int main()
{
	int x = 2147483647;
	char y = 127;
	printf("%d\n", x);
	x += 1;
	printf("%d\n", x);
	printf("%d\n", y);
	y += 1;
	printf("%d\n", y);
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


