// typedef struct books BB;
// ����ü�� ����� ���� �ڵ尡 ������� ������
// typedef�� ����Ͽ� struct book �� BB�� ��� �� �� �ְ� �Ѵ�
// 
// ����ü �� �������� ����� �Ѵ�
// ����ü��.��� �� ����Ͽ� ����ü�� ����� �� �ִ�
// 
// 16�� 6��
// �ִ� �����(GCD)�� ���� ����
// 16�� ���	1, 2, 4, 8, 19
// 6�� ���		1, 2, 3, 6
// �ִ� ����� = 2
// 
// �ּ� �����(LCM)�� ���� ����
//  2 l 16  6
//    --------
//       8  3
// �� �̻� ������� ���������� ���� �� ���� �ϸ�
// 2 x 8 x 3 = 24
// �ִ� ����� = 24
// 
// ��Ŭ���� ȣ����
// 2���� �ڿ��� �Ǵ� ����(����)�� �ִ������� ���ϴ� �˰����� �ϳ��̴�. 
// ȣ�����̶� ���� �� ���� ����(��) ���� ���� ������(�)�� 
// �ᱹ ���ϴ� ���� ��� �˰����� ��Ÿ����. 
// 2���� �ڿ���(�Ǵ� ����) a, b�� ���ؼ� a�� b�� ���� �������� r�̶� �ϸ�(��, a>b), 
// a�� b�� �ִ������� b�� r�� �ִ������� ����. 
// �� ������ ����, b�� r�� ���� ������ r'�� ���ϰ�, 
// �ٽ� r�� r'�� ���� �������� ���ϴ� ������ �ݺ��Ͽ� �������� 0�� �Ǿ��� �� 
// ������ ���� a�� b�� �ִ������̴�.
// 
// �ִ� ������� ���ϸ� �ּ� ������� ���� ���� �� �ִ�.
// (
// a, b �� �ִ� ������� A ��� 
// (a * b) / A = �ּ� �����
// )
// 

//5.31
//����ü�� Ȱ���� ����
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
		printf("å %d ���� �Է� : ", i+1);
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
		book_list[i].borrowed = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("--------------");
		printf("å %s �� ����\n", book_list[i].name);
		printf("���� : %s\n", book_list[i].auth);
		printf("���ǻ� : %s\n", book_list[i].publ);
		if (book_list[i].borrowed == 0)
		{
			printf("�� ������\n");
		}
		else
		{
			printf("������ \n");
		}
	}
	return 0;
}
//+���� ���� ����
// ����ó (�Է� / Ȯ��) 
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
		printf("����ó�� Ȯ���Ϸ��� 1��\n");
		printf("����ó�� �Է��Ϸ��� 2��\n");
		printf("------------------------\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("\n------------------------\n");
			for (int i = 0; i <= last; i++)
			{
				printf("%7s\t 0%ld %7s\n", CI[i].name, CI[i].number, CI[i].relation);
				//CI[i].number �� long int �� �����ؼ�
				//ù 010�� 0�� �����Ǵ� ������ �־
				//0%ld
			}
			printf("------------------------\n");
		}
		else if (choice == 2)
		{
			printf("\n------------------------\n");
			printf("�̸��� �Է��ϼ���  \t");
			scanf(" %s",&CI[last+=1].name);
			printf("��ȭ��ȣ�� �Է��ϼ���\t");
			scanf(" %ld", &CI[last].number);
			printf("���踦 �Է��ϼ���  \t");
			scanf(" %s", &CI[last].relation);
			printf("------------------------\n");
		}
		else
		{
			printf("\n------------------------\n");
			printf("1, 2 �� �ϳ��� ���� �Է����ּ���");
			printf("\n------------------------\n");
			break;
		}
	}
	return 0;
}

//��Ÿ��󽺹�Ģ�� ����Ͽ� ���� �Ÿ��� ���ϱ�
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
//�ִ�����, �ּҰ����
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
// 16 �� 6�� �Է��ϸ�
// 6	4(16%6)
// 4	2(6%4)
// 2	0(4%2)
// �� b���� 0�� �Ǹ� a = 2
// �� �ִ� ������� 2
// 
// 
int main()
{
	int a = 16, b = 6;
	printf("�ִ����� : %d\n", gcd(a, b));
	printf("�ּҰ���� : %d\n", a * b / gcd(a, b)); 
	// a * b / (a, b) �� ������ 
	// 6	12 18 24 30 36 42 48
	// 16	32 48
	// 
	// 6 * 16 = 96 ��⼭ �ִ������� ������ �ּҰ������ ���´�  
	//
	return 0;
}

//�Ҽ��Ǻ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!(n % i)) //if((n%i)==0) �� ���ٴ� ���̴� �� �Ҽ��� �ƴ� ��
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
		printf("���� : ");
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
			//�׳� for ���� ��� �� ��
			//for ( j = 2; j*j < i; j++) // 10�� �ִٸ� 2, 3 �� �ٱ��ϸ� �Ǳ� ������
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