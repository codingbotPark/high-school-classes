//�������� = �ϳ��� �Լ� �ȿ����� ���Ǵ� ����
//�������� = �Լ��� ������� ���α׷� ��ü���� ����� �� �ִ� ����
//���������� ���� �ϸ� 0���� �ʱ�ȭ
//#pragma warnings(disable : 4996)// = #define _CRT_SECURE_NO_WARNINGS�� ��������
//����Լ��� ����Ͽ� �ݺ��Ǵ� �۾��� �� �� �ִ�
//f11�� ���� ������� ����� �� �� �ִ�.(shift + f5 �� ���� Ż��)

//4.12
//�������� ��������
#include <stdio.h>
int num = 5;
int main()
{
	int num = 1;
	if (num == 1)
	{
		int num = 7;
		num += 10;
		printf("if�� �� �������� num : %d\n", num);
	}
	printf("main�Լ� �� �������� num : %d\n", num);
	return 0;
}

//�� ���� ������ ���ڷ� ���޹޾�
//�� �� ���� ū ���� ��ȯ�ϴ� �Լ���
//���� ���� ���� ��ȯ�ϴ� �Լ��� �ִ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int a, int b, int c)
{
	int t = (a > b) ? (a) : (b);
	return (t > c) ? (t) : (c);	
}
int min(int a, int b, int c)
{
	int t = (a > b) ? (b) : (a);
	return (t > c) ? (c) : (t);
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("max = %d\n", max(a, b, c));
	printf("min = %d\n", min(a, b, c));
	return 0;
}

//�Ǻ���ġ ���� (���� �� 2���� ���� ��(0 1 1 2 3 5 8 13 ...))
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacii(int n)
{
	int f1 = 0;
	int f2 = 1, f3;
	if (n == 0)
		printf("%d", f1);
	else
		printf("%d %d", f1 , f2);
	for (int i = 0; i < n - 2; i++)
	{
		f3 = f2 + f1;
		printf(" %d", f3);
		f1 = f2;
		f2 = f3;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	fibonacii(n);
}

//math.h���̺귯���� �˻��Ͽ� �����ϳ��� ����� ����
//2���Լ� ���� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
int main()
{
	double a, b, c, x1 = 0, x2 = 0;
	double X = 0;
	printf("aX^2 + bX + c = 0�϶��� a b c�� �Է��ϼ���");
	scanf("%lf %lf %lf", &a, &b, &c);
	X=sqrt((double) (b * b - 4*a*c));
	x1 = (-b - X) / (2 * a);
	x2 = (-b + X) / (2 * a);
	if (x1 != x2)
		printf("%lf\n%lf", x1, x2);
	else
		printf("%lf", x1);
	return 0;
}

//4.13
//�Ǻ���ġ �׽�Ʈ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h.>
int F(n)
{
	int f1 = 1, f2 = 1, f3 = 0, i = 0;
	if (n > 0)
	{
		if (n == 1)
		{
			printf("%d ", f1);
		}
		else
		{
			printf("%d ", f1);
			printf("%d ", f2);
			for (i = 2; i < n; i++)
			{
				f3 = f1 + f2;
				printf("%d ", f3);
				f1 = f2;
				f2 = f3;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	F(n);
	return 0;
}

//�����������
#pragma warnings(disable : 4996)// = #define _CRT_SECURE_NO_WARNINGS�� ��������
#include <stdio.h>
int n;
void add(int);
int main()
{
	printf("n : %d\n", n);
	add(3);
	printf("n : %d\n", n);
	n++;
	printf("n : %d\n", n);
	return 0;
}
void add(int x)
{
	n += x;
}

//����Լ����
#pragma warnings(disable : 4996)
#include <stdio.h>
void recur(int n)
{
	if (n < 0)
		return 0;
	printf("�Լ��ȿ� �Լ� ȣ�� : %d\n", n);
	recur(n - 1);
}
int main()
{
	recur(5);
	return 0;
}

//����Լ��� ���丮�� �����
#pragma warning(disable : 4996)
#include <stdio.h>
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
int main()
{
	printf("%d\n", fact(5));
	return 0;
}

//4.14
//(1)
//break		�ݺ����� ��������
//continue	���� ������ �������� �ʰ� �ٽ� �ö󰣴�

//(2)
if (���� 1)
 {
 ����1�� ���� ��� ����Ǵ� ��ɹ�
 }
else if(���� 2)
 {
 ���� 2�� ���� ��� ����Ǵ� ��ɹ�
 }
else
 {
 ���� ���ǿ� ���� �ʴ� ��� ����Ǵ� ��ɹ�
 }


//(3)
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
int main()
{
	int score, pass;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &score);
	printf("�հ����� �Է��ϼ���");
	scanf("%d", &pass);
	printf("%s", score >= pass ? "�հ�" : "���հ�");
}

//(4)
����		= ���ǽ��� ����� ������ ���ڰ� �� �� �ִ� ���� �Ǵ� ����
 
case �� n = ������ ����� �� n�� �� �ش� ����� ����
(n�� �ݵ�� ������ ����̾�� �ϸ�, ������ �� �� ����)
 
break		= swtich���� �����ϴ� ���
 
default	= case�� ���� �� ���� ��� ��쿡 ����Ǵ� ��ɹ�


//(5)
switch (a)
{
case 1 : printf("1st"); break;
case 2 : printf("2ed"); break;
case 3 : printf("3th"); break;
default : printf("%dth"); break;
}

//(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int l, j = 0, n = 1, m = 0;
	printf("����� ���� �Է��ϼ���");
	scanf("%d", &l);
	for (j = 0; j <= l; j++)
	{
		for (m = 0; m < j; m++)
		{
			printf("%4d", n);
			n++;
		}
		printf("\n");
	}
	return 0;
}

//4.15
//(1)
//(��)
#include <stdio.h>
int main()
{
	int i = 0, j = 0, n = 0, m = 0,a=0,b=0;
	for (i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			for (a = 0; a < i; a++)
			{
				printf(" ");
			}
			printf("*");
			for (b = 5-(i*2); b > 0; b--)
			{
				printf(" ");
			}
			printf("*");
		}
		else if (i == 3)
		{
			printf("   *");
		}
		else
		{
			for (a = 0; a < 6-i; a++)
			{
				printf(" ");
			}
			printf("*");
			for (b = 0; b <= ((i - 4) * 2); b++)
			{
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//(��)
#include <stdio.h>
int main()
{
	int i, j, k, l;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i == j || i + j == 6)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
//(�Է¹ޱ�)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, j, k, l,n;
	while (1)
	{
		printf("����� ���� �Է��ϼ���(Ȧ���� �Է½� ��µ˴ϴ�)");
		scanf("%d", &n);
		if (n % 2 == 1)
			break;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j || i + j == n-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}


//(2)
#include <stdio.h>
int main()
{
	int d = 2, i = 0, j = 0, n = 0, m = 0;
	for (i = 1; i < 10; i++)
	{
		for (d = 2; d < 10; d++)
		{
			printf("%d * %d = %3d   ", d, i, d * i);
		}
		printf("\n");
	}
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int d = 0, n = 0, m = 0, i = 0, j = 0;
	printf("���� �Է��ϼ���");
	scanf("%d", &d);
	for (n = 1; n <= d; n++)
	{
		for (m = 1; m <= d; m++)
		{
			printf("(%d,%d) ", n, m);
		}
		printf("\n");
	}
}