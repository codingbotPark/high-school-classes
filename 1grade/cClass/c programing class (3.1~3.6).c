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
