//typedef struct data {
//	char name[20];
//	int age;
//}Student;
//
// �̰Ͱ� 
//
//typedef struct data Student;
//struct data
//{
//	char name[20];
//	int age;
//};
//
// �̰��� ����
// 
// �ٸ������ �ڵ带 �������� �˰� �־�� �Ѵ�
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
// �� ����ü�� 24 ����Ʈ
// char = 1
// 1 * 2
// 
// ����ü ����
// ������ �� �� ����ü�� ����Ѵٸ�
// �������� ������ �� ���� ������ �� �ִ�
// 
// malloc �Լ��� �����
// �������� �迭�� ������ �� �ִ�
// malloc�� void pointer�� ����Ῡ ����� ������ ���� ��ȯ �� �� �־
// ȿ������ �ڵ带 © �� �ִ�
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
// ������ ����� �� free�� ����Ͽ�
// malloc�� ���� �� �ִ�
// 
// �� ������ Ȱ���Ͽ� scanf�� Ȱ���Ѵٸ� ���� �Ҵ��� �����ϴ�
// 
// 
// 
// memcpy �Լ��� �����
// �ּҰ��� �־��ָ� �� �ּҿ� �ִ� ����
// �״�� ������ �� �ִ�


//6.14
// �̸������й��� ����ü�� �Է¹޾�
// ����ϴ� ���α׷�  
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
	printf("�̸� �Է� : ");
	scanf("%s", me.name);
	printf("���� �Է� : ");
	scanf("%d", &me.age);
	printf("�й� �Է� : ");
	scanf("%d", &me.number);
	printf("\n���� �̸� = %s\n���� ���� = %d\n���� �й� = %d", me.name, me.age, me.number);
}

 //����ü�� ����Ͽ�
 //����, ����, ���� ������ �Է¹޾�
 //������ ���ϴ� ���α׷�
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
	strcpy(sum.name, "����");
	sum.kor = s[0].kor + s[1].kor;
	sum.eng = s[0].eng + s[1].eng;
	sum.math = s[0].math + s[1].math;
	printf("\n\t����\n");
	for (int i = 0; i < 2; i++)
	{
		printf("%s %d %d %d\n",s[i].name, s[i].kor, s[i].eng, s[i].math);
	}
	printf("\n\t��ü����\n");
	printf("%s %d %d %d\n", sum.name, sum.kor, sum.eng, sum.math);
}
//����ü ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _d {
	char name[30];
	int kor, eng, math;
}Stu;
Stu s1, s2, sum = { 0, };
void score()
{

	strcpy(sum.name, "����");
	sum.kor = s1.kor + s2.kor;
	sum.eng = s1.eng + s2.eng;
	sum.math = s1.math + s2.math;
}
int main()
{
	scanf(" %s %d %d %d", s1.name, &s1.kor, &s1.eng, &s1.math);
	scanf(" %s %d %d %d", s2.name, &s2.kor, &s2.eng, &s2.math);
	printf("\n\t����\n");
	printf("%s %d %d %d\n", s1.name, s1.kor, s1.eng, s1.math);
	printf("%s %d %d %d\n", s2.name, s2.kor, s2.eng, s2.math);
	score();
	printf("\n\t��ü����\n");
	printf("%s %d %d %d\n", sum.name, sum.kor, sum.eng, sum.math);
}

//����ü�� �� ���� �߾� ��ġ�� ���ϴ� ���α׷�
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

//�ﰢ���� �����߽��� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct _p
{
	double x, y;
}Point;

int main()
{
	Point p1, p2, p3;
	printf("�� A�� ��ǥ �Է�");
	scanf("%d %d", p1.x, p1.y);
	printf("�� B�� ��ǥ �Է�");
	scanf("%d %d", p2.x, p2.y);
	printf("�� C�� ��ǥ �Է�");
	scanf("%d %d", p3.x, p3.y);
	printf("%.1lf %.1lf", (p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y));
	return 0;
}

//������� ã�ƶ�
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
	printf("����� %d�� %d�� \n", king.num, king.money);

	return 0;
}

//6.15
//malloc�Լ� ���
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
//+Ȱ��
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
		printf("�޸� ���� ����\n");
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

//����ü ����
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
	strcpy(p1.name, "����ü ����");
	p1.x = 10;
	p1.y = 20;	
	//��������
	/*strcpy(p2.name, p1.name);
	p2.x = p1.x;
	p2.y = p1.y;*/
	//�̷��� �߾��� ������
	//������
	/*memcpy(&p2, &p1, sizeof(Point));*/
	//�̷��� 
	printf("%s\n", p2.name);
	printf("%d %d\n", p2.x, p2.y);
	return 0;
}

//����ü����
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
				//Ű�� ���� ���� ����
				strcpy(tmp_name, s[i].name);
				strcpy(s[i].name, s[j].name);
				strcpy(s[j].name, tmp_name);
				//��ü�� �ٲ�� �ϱ� ������ strcpy

				//Ű
				strcpy(tmp_he, s[i].he);
				strcpy(s[i].he, s[j].he);
				strcpy(s[j].he, tmp_he);

				//������
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