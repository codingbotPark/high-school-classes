//if
//else if
//esle
// ��
//if
//if
//if
//�� �������� else if�� ���� if�� ���̸� �ѱ�
//if�� 3���� if�� ������
//3�� ������ ((����)?(��):(����))
//break (�ݺ������� ���´�)
//continue (�Ʒ��� ������ �����ϰ� �ٽ� �ݺ����� �������� ����)
//switch case���� if���� �ӵ��� ������

//3.29
//�� �ﰢ�� ��� 1
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i=0; i < 5; i++)
	{
		for (j=0; j < 5-i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ��� 1 (������)
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 5; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ��� (�̵ �ﰢ��)
#include <stdio.h>
int main()
{
	int i = 0, j = 0, a = 0;
	for (i = 0; i < 5; i++)
	{
		for (a = 0; a < 5 - i; a++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ��� (�̵ �ﰢ��)(������)
#include <stdio.h>
int main()
{
	int n = 5, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//if �� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0)
		printf("0���� �۴�");
	if (n > 0)
		printf("0���� ũ��");
	if (n == 0)
		printf("0�̴�");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0)
		printf("0���� �۴�");
	else if (n > 0)
		printf("0���� ũ��");
	else (n == 0)
		printf("0�̴�");
	return 0;
}

//���� ���� ���� ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int opt;
	double num1, num2, result;
	printf("1.���� 2.���� 3.���� 4.������\n");
	scanf("%d", &opt);
	printf("�� ���� �Ǽ� �Է� : ");
	scanf("%lf %lf", &num1, &num2);
	if (opt == 1)
		result = num1 + num2;
	else if (opt == 2)
		result = num1 - num2;
	else if (opt==3)
		result = num1 * num2;
	else
		result = num1 / num2;
	printf("��� : %f", result);
	return 0;
}

//1~100 ������ 3�� ���
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			printf("%d\n", i);
	}
	return 0;
}
//+5�� ��½� ���� ������ //�����̴� i�� 15�϶� ���� �ٲ�
#include <stdio.h>
int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%4d", i);
			count++;
		}
		if (count >= 5)
		{
			printf("\n");
			count-=5;
		}
	}
	return 0;
}

//5�� 7�� ��� ���,����� 5���� ���
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 5 == 0 || i % 7 == 0)
		{
			printf("%4d", i);
			j++;
		}
		if (j > 0 && j % 5 == 0)
		{
			printf("\n");
			j -= 5;
		}
	}
	return 0;
}

//�����ϳ� �Է¹޾� ������ ����ϴ� ���α׷�
//3�� ������ ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d", (i >= 0) ? (i) : (-1 * i));
	return 0;
}

//����, ���� ,���α׷��� ������ �Է¹޾�
//90�� �̻� A
//80�� �̻� B
//		.
//		.
//60�� �̸� F
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int Kor, Eng, Pro;
	double avg;
	printf("���� ���� ���α׷��� ������ �Է��ϼ���");
	scanf("%d %d %d", &Kor, &Eng, &Pro);
	avg = (Kor + Eng + Pro) / 3;
	printf("%c",(avg >= 90.0) ? ('A') : ((avg >= 80.0) ? ('B') : ((avg >= 70.0) ? ('C') : ((avg >= 60.0) ? ('D') : ('F')))));
	return 0;
}

#include <stdio.h>
int main()
{
	int sum = 0, num = 0;
	while (1)
	{
		printf("%d", ++num);
		if (num > 100000)
			break;
	}
	return 0;
}
//+Ȧ���� continue
#include <stdio.h>
int main()
{
	int sum = 0, num = 0;
	while (num <= 100)
	{
		if (++num % 2 == 1)
			continue;
		printf("%d", num);
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int n = 0, v=0;
	while (v <= 100000)
	{
		n++;
		v += n;
	}
	printf("%d", n);
	return 0;
}

#include <stdio.h>
int main()
{
	int n = 0, v = 0;
	for (n; v <= 50000; n++)
	{
		v += n;
	}
	v -= n;
	//for ������ v�� 5���� �Ѿ�� for�� ���߱� ������
	//�Ѿ�� �Ѿ�� �������� ã�ƾߵ� / n�� ����
	printf("%d", v);
	printf("\n%d", --n);
	return 0;
}

//2,3�� ����� �ƴ� �� ���
#include <stdio.h>
int main()
{
	int n = 0;
	while (n <= 50)
	{
		n++;
		if (n % 2 == 0 || n % 3 == 0)
			continue;
		printf("%d\n", n);
	}
	return 0;
}

//3.30
//������ �ܸ�ŭ �������� ��µǴ� ���α׷�
#include <stdio.h>
int main()
{
	int dan = 2, i = 1;
	for (dan = 2; dan <= 9; dan++)
	{
		printf("==============\n");
		for (i = 1; i <= dan; i++)
		{
			printf("%d * %d = %d\n", dan, i, dan * i);
		}
		printf("\n");
	}
	return 0;
}
//+¦���� �ܸ� ����ϴ� ������
#include <stdio.h>
int main()
{
	int dan = 2, i = 1;
	for (dan = 2; dan <= 9; dan++)
	{
		if (dan % 2 == 0)
		{
			printf("==============\n");
			for (i = 1; i <= dan; i++)
			{
					printf("%d * %d = %d\n", dan, i, dan * i);
			}
			printf("\n");
		}
		else
			continue;
	}
	return 0;
}

//A Z + Z A ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, v1 = 0, v2 = 0;
	printf("������ �� ���� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	v1 = 10 * a + b;
	v2 = 10 * b + a;
	printf("%d", v1 + v2);
	return 0;
}

//A Z + Z A����� �� ���α׷�
#include <stdio.h>
int main()
{
	int A=0, Z=0, ans=0;
	for (A = 0; A < 10; A++)
	{
		for (Z=0; Z < 10; Z++)
		{
			if (A == Z)
				continue;
			ans = (A * 10 + Z) + (Z * 10 + A);
			if (ans == 99)
				printf("A = %d, Z = %d\n", A, Z);
		}
	}
	return 0;
}

//1~5�� �Էµ� ���� switch�� ����� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	printf("1~5 ������ ���� �Է��ϼ���");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		printf("1�Դϴ�");
		break;
	case 2:
		printf("2�Դϴ�");
		break;
	case 3:
		printf("3�Դϴ�");
		break;
	case 4:
		printf("4�Դϴ�");
		break;
	case 5:
		printf("5�Դϴ�");
		break;
	default:
		printf("�� ���� �����Դϴ�");
	}
	return 0;
}

//���̾Ƹ�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main()
{
	int num = 0, NUM = 0, i = 0, j = 0, a = 0, b = 0;
	while (1)
	{
		printf("�����Է�(Ȧ���� �Է½� ����˴ϴ�)");
		scanf("%d", &num);
		if (num % 2 != 0 && num > 0)
		{
			break;
		}
	}
	NUM = num / 2;
	for (i = 0; i < num; i++)
	{
		if (i <= NUM)
		{
			for (a = 0; a < NUM - i; a++)
			{
				printf(" ");
			}
			for (j = 0; j < i * 2 + 1; j++)
			{
				printf("*");
			}
		}
		if (i > NUM)//5
		{
			for (a = 0; a < i - NUM; a++)
			{
				printf(" ");
			}
			for (j = 0; j < num - ((i-NUM) * 2); j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}

//3.31
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("������ �Է��ϼ���");
	scanf("%d", &a);
	if (90 < a)
		printf("A");
	if (a <= 90 && a > 80)
		printf("B");
	if (a <= 80 && a > 70)
		printf("C");
	else
		printf("F");
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("������ �Է��ϼ���");
	scanf("%d", &a);
	if (a >= 80)
		printf("�հ�");
	else
		printf("���հ�");
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b;
	printf("�� �ΰ��� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("%d", a - b);
	else
		printf("%d", b - a);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("���̸� �Է��ϼ���");
	scanf("%d", &a);
	if (a >= 20)
		printf("adult");
	else
		printf("%dyears later", 20 - a);
	return 0;
}

//(5) ���� 3�� �Է¹޾Ƽ� �� ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("�� �� ���� �Է��ϼ���");
	int value,big=0,three=0;
	while (three < 3)
	{
		printf("\n���� �Է��ϼ���");
		scanf("%d", &value);
		if (value > big)
			big = value;
		three++;
	}
	printf("\n%d", big);

	return 0;
}