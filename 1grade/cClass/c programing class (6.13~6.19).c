//typedef struct data {
//	char name[20];
//	int age;
//}Student;
//
// 이것과 
//
//typedef struct data Student;
//struct data
//{
//	char name[20];
//	int age;
//};
//
// 이것은 같다
// 
// 다른사람의 코드를 보기위해 알고 있어야 한다
// 
// 
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//typedef struct data Student;
//struct data
//{
//	char name[20];
//	int age;
//};
// 이 구조체는 24 바이트
// char = 1
// 1 * 2
// 
// 구조체 리턴
// 리턴을 할 때 구조체를 사용한다면
// 여러개의 정보를 한 번에 리턴할 수 있다
// 
// malloc 함수를 사용해
// 동적으로 배열을 생성할 수 있다
// malloc에 void pointer를 사용햐여 사용할 때마다 형을 변환 할 수 있어서
// 효율적인 코드를 짤 수 있다
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int arr[4] = { 1,2,3,4 };
//	int* pArr;
//	pArr = (int*)malloc(sizeof(int) * 4);
//	for (int i = 0; i < 4; i++)
//	{
//		pArr[i] = i * i;
//		printf("pArr[i] = %d\n", pArr[i]);
//	}
//	free(pArr);
//	return 0;
//}
// 말록을 사용한 후 free를 사용하여
// malloc을 없앨 수 있다
// 
// 이 말록을 활용하여 scanf를 활용한다면 동적 할당익 가능하다
// 
// 
// 
// memcpy 함수를 사용해
// 주소값을 넣어주면 그 주소에 있는 값을
// 그대로 복사할 수 있다


//6.14
// 이름나이학번을 구조체로 입력받아
// 출력하는 프로그램  
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct data Student;
struct data
{
	char name[20];
	int age;
	int number;
};
int main()
{
	Student me;
	printf("이름 입력 : ");
	scanf("%s", me.name);
	printf("나이 입력 : ");
	scanf("%d", &me.age);
	printf("학번 입력 : ");
	scanf("%d", &me.number);
	printf("\n나의 이름 = %s\n나의 나이 = %d\n나의 학번 = %d", me.name, me.age, me.number);
}

 //구조체를 사용하여
 //국어, 영어, 수학 점수를 입력받아
 //총합을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _d {
	char name[30];
	int kor, eng, math;
}Stu;

int main()
{
	Stu s[2], sum;
	for (int i = 0; i < 2; i++)
	{
		scanf(" %s %d %d %d", s[i].name, &s[i].kor, &s[i].eng, &s[i].math);
	}
	strcpy(sum.name, "총합");
	sum.kor = s[0].kor + s[1].kor;
	sum.eng = s[0].eng + s[1].eng;
	sum.math = s[0].math + s[1].math;
	printf("\n\t총합\n");
	for (int i = 0; i < 2; i++)
	{
		printf("%s %d %d %d\n",s[i].name, s[i].kor, s[i].eng, s[i].math);
	}
	printf("\n\t전체총합\n");
	printf("%s %d %d %d\n", sum.name, sum.kor, sum.eng, sum.math);
}
//구조체 리턴
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _d {
	char name[30];
	int kor, eng, math;
}Stu;
Stu s1, s2, sum = { 0, };
void score()
{

	strcpy(sum.name, "총합");
	sum.kor = s1.kor + s2.kor;
	sum.eng = s1.eng + s2.eng;
	sum.math = s1.math + s2.math;
}
int main()
{
	scanf(" %s %d %d %d", s1.name, &s1.kor, &s1.eng, &s1.math);
	scanf(" %s %d %d %d", s2.name, &s2.kor, &s2.eng, &s2.math);
	printf("\n\t총합\n");
	printf("%s %d %d %d\n", s1.name, s1.kor, s1.eng, s1.math);
	printf("%s %d %d %d\n", s2.name, s2.kor, s2.eng, s2.math);
	score();
	printf("\n\t전체총합\n");
	printf("%s %d %d %d\n", sum.name, sum.kor, sum.eng, sum.math);
}

//구조체로 두 점의 중앙 위치를 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _p {
	double x, y;
}Point;

int main()
{
	Point p1, p2;
	scanf("%lf %lf", &p1.x, &p1.y);
	scanf("%lf %lf", &p2.x, &p2.y);
	printf("\n%lf %lf\n", (p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	return 0;
}

//삼각형의 무게중심을 구하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _p
{
	double x, y;
}Point;

int main()
{
	Point p1, p2, p3;
	printf("점 A의 좌표 입력");
	scanf("%d %d", p1.x, p1.y);
	printf("점 B의 좌표 입력");
	scanf("%d %d", p2.x, p2.y);
	printf("점 C의 좌표 입력");
	scanf("%d %d", p3.x, p3.y);
	printf("%.1lf %.1lf", (p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y));
	return 0;
}

//저축왕을 찾아라
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _m
{
	int num;
	int money;
}Money;

Money maxMoney(Money m[], int n)
{
	Money max = m[0];
	for (int i = 1; i < n; i++)
	{
		if (m[i].money > max.money)
		{
			max = m[i];
		}
	}
	return max;
}

int main()
{
	Money m[5], king;
	for (int i = 0; i < 5; i++)
	{
		m[i].num = 1;
		scanf("%d", &m[i].money);
	}
	king = maxMoney(m, 5);
	printf("저축왕 %d번 %d원 \n", king.num, king.money);

	return 0;
}

//6.15
//malloc함수 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[4] = { 1,2,3,4 };
	int* pArr;
	pArr = (int*)malloc(sizeof(int) * 4);
	for (int i = 0; i < 4; i++)
	{
		pArr[i] = i * i;
		printf("pArr[i] = %d\n", pArr[i]);
	}
	free(pArr);
	return 0;
}
//+활용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[4] = { 1,2,3,4 };
	int* pArr;
	scanf("%d", &n);
	pArr = (int*)malloc(sizeof(int) * n);
	if (pArr == NULL)
	{
		printf("메모리 공간 부족\n");
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		pArr[i] = i * i;
		printf("pArr[i] = %d\n", pArr[i]);
	}
	free(pArr);
	return 0;
}

//구조체 복사
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct _p {
	char name[20];
	int x;
	int y;
}Point;
int main()
{
	Point p1, p2;
	strcpy(p1.name, "구조체 복사");
	p1.x = 10;
	p1.y = 20;	
	//옛날에는
	/*strcpy(p2.name, p1.name);
	p2.x = p1.x;
	p2.y = p1.y;*/
	//이렇게 했었다 하지만
	//요즘은
	/*memcpy(&p2, &p1, sizeof(Point));*/
	//이렇게 
	printf("%s\n", p2.name);
	printf("%d %d\n", p2.x, p2.y);
	return 0;
}

//구조체정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _p {
	char name[5][10];
	int he[5];
	double we[5];
}Student;
Student s[5];
void input()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d %lf", s[i].name, &s[i].he, &s[i].we);
	}
}
void sort()
{
	char tmp_name[20] = { 0, };
	int tmp_he=0;
	double tmp_we=0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (s[j].he > s[i].he)
			{
				//키가 작은 순로 정렬
				strcpy(tmp_name, s[i].name);
				strcpy(s[i].name, s[j].name);
				strcpy(s[j].name, tmp_name);
				//전체를 바꿔야 하기 때문에 strcpy

				//키
				strcpy(tmp_he, s[i].he);
				strcpy(s[i].he, s[j].he);
				strcpy(s[j].he, tmp_he);

				//몸무게
				strcpy(tmp_we, s[i].we);
				strcpy(s[i].we, s[j].we);
				strcpy(s[j].we, tmp_we);
			}
		}
	}
}
void output()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s %d %.lf \n", s[i].name, s[i].he, s[i].we);
	}
}
int main()
{
	input();
	sort();
	output();

	return 0;
}