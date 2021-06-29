//시험준비

//6.22
//파일입출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* ifp = fopen("run.txt", "r");//파일 읽기
	FILE* ofp = fopen("result.txt", "w");//파일 쓰기
	//ifp와 ofp는 이름을 그냥 지은 것이다
	char name[10];
	double avg, n1, n2, n3;
	//scanf("%s %d %d %d", name, &n1, &n2, &n3);
	fscanf(ifp, "%s %lf %lf %lf", name, &n1, &n2, &n3);
	avg = (n1 + n2 + n3) / 3.0;
	fprintf(ofp, "%s %.1f", name, avg);
	fclose(ifp);
	fclose(ofp);
	return 0;
}
//run.txt파일의 값을 result.txt파일에 가공해서 넣는다

//소수구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n)
{
	//for (int i = 2;i<n;i++)
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	while (1)
	{
		int n;
		printf("숫자 : ");
		scanf("%d", &n);

		if (n < 2)return 0;//2미만의 수가 들언다면
		if (n >= 1000)
		{
			printf("\n");
			continue;
		}
		int primeCnt = 1;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i))
			{
				printf("%d ", i);
				if (primeCnt == 10)
				{
					printf("\n");
					primeCnt = 1;
				}//10개마다 줄바꿈
				primeCnt++;
			}
		}
	}
	return 0;
}







//기말고사대비 
//자신의이름을출력
#include <stdio.h>
int main()
{
	printf("박병관");
	return 0;
}
//자신의이름을세로로출력
#include <stdio.h>
int main()
{
	printf("박\n병\n관");
	return 0;
}
//소개
#include <stdio.h>
int main()
{
	char name[10] = "박병관";
	int age = 17;
	char string[22] = "최선을 다해 노력하자";
	printf("안녕!!!\n");
	printf("내 이름은 : %s이야\n",name);
	printf("나는 %d살이야.\n",age);
	printf("나의 좌우명은 \"%s\"", string);
	return 0;
}
//과목점수를 입력받아 총점과 평균을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int K, E, M, C;
	int sum = 0, avg = 0;
	scanf("%d %d %d %d", &K, &E, &M, &C);
	sum = K + E + M + C;
	avg = sum / 4;
	printf("sum %d\navg %d", sum, avg);

	return 0;
}
//두 정수를 입력받아 몫과 나머지를 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int one, two;
	scanf("%d %d", &one, &two);
	printf("%d / %d = %d...%d", one, two, one / two, one % two);

	return 0;
}
//직사각형의 가로세로를 입력받고
//가로는 + 5 세로는 * 2해서 가로세로넓이 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int w, h;
	scanf("%d %d", &w, &h);
	printf("width = %d\n", w += 5);
	printf("lenght = %d\n", h *= 2);
	printf("area = %d\n", h * w);

	return 0;
}
//정수 a와 b를 입력받아 
//a = 전치, b = 후치 연산자를 사용,
//a = 증가, b = 감소
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = ++a + b--;
	printf("a = %d, b = %d, c = %d", a, b, c);
	return 0;
}
//3과목의 점수를 입력받아 평균을 구한 후 반올림 => 소수 첫째자리
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	float avg = 0;
	//scanf("%f %f %f", &a, &b, &c);
	scanf("%d %d %d", &a, &b, &c);
	avg = a + b + c;
	printf("avg = %.2f", avg / 3);
	return 0;
}
//3과목의 점수를 입력받아 총점은 정수부분의 합계, 평균은 실수의 평균을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a, b, c;
	int sum;
	float avg;
	scanf("%f %f %f", &a, &b, &c);
	sum = (int)a + (int)b + (int)c;
	printf("sum = %d\n", sum);
	avg = a + b + c;
	printf("avg = %.f", avg/3);

	return 0;
}
//5개의 정수를 입력 받아 각각의 수에 +3, -3, ×3, /3, %3의 연산을 실행하여 
//그 값을 저장한 후 차례대로 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	a += 3;
	b -= 3;
	c *= 3;
	d /= 3;
	e %= 3;
	printf("%d %d %d %d %d", a, b, c, d, e);
	return 0;
}
//알파벳 ‘A’부터 ‘Z’까지 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 65;
	while (a<91)
	{
		printf("%c", a++);
	}
	return 0;
}
//1부터 20까지 홀수를 차례대로 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 1;
	for (a = 1; a < 20; a += 2)
	{
		printf("%d ", a);
	}
	return 0;
}
//10 미만의 정수를 입력받아 팩토리얼을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num;
	int val = 1;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		val *= i;
	}
	printf("%d", val);
	return 0;
}
//6명의 체중을 입력받아 평균을 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float weight[6];
	float avg = 0;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &weight[i]);
		avg += weight[i];
	}
	printf("avg = %.1f", avg);
	return 0;
}	