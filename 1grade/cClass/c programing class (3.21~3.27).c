//4G = �ǹ� ������ �־ ������
//5G = ������ => �ǹ� ������ ������ ������
//%g = ���ڰ� �ſ�ũ�� %e ,�ƴϸ� %f�� ǥ������
//e = 10�̶� �����ϸ� �� (e - 3 = 10�� -3�� = 0.001)
//10�� 10����, 8����, 16������ ���� �Է¹�����
//(	10���� = 10�� ���
//8���� = 10(8) = 8������ 10������ ��ȯ => 8 * 1 + 1 * 0 => 8
//16���� = 10(16) = 16������ 10������ ��ȯ => 16 * 1 + 1 * 0 => 16 )
//do while ���
//(
//		do {
//		printf("1");
//		} while (����) )
//for ���
//for (����;����;����)

//3.22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double d1 = 1.23e-3;
	printf("%f\n", d1);
	printf("%e\n", d1);
	printf("%g\n", d1);
	double d2 = 1.234567e-3;
	printf("%f\n", d2);
	printf("%e\n", d2);//�ݿø�
	printf("%g\n", d2);//�ݿø�
	double d3 = 0.01234567;
	printf("%f\n", d3);
	printf("%e\n", d3);
	printf("%g\n", d3);
	return 0;
}

//10����(%d), 8����(%o), 16����(%x)�� �Է¹޾�
//10������ ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n1, n2, n3;
	printf("10����, 8����, 16����\n");
	scanf("%d %o %x", &n1, &n2, &n3);
	printf("--10������ �ٲٸ�---\n");
	printf("%d %d %d\n", n1, n2, n3);
	//3�� �� 10�� �Է����� ��
	//10���� = 10�� ���
	//8���� = 10(8) = 8������ 10������ ��ȯ => 8 * 1 + 1 * 0 => 8
	//16���� = 10(16) = 16������ 10������ ��ȯ => 16 * 1 + 1 * 0 => 16
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1, n2, n3;
	scanf("%d %o %x", &n1, &n2, &n3);
	printf("%x %x %x\n", n1, n2, n3);
	return 0;
}

//while�� ����Ͽ� 1���� 10��ġ ���
#include <stdio.h>
int main()
{
	int a = 0;
	while (a<10)
	{
		a++;
		printf("%4d", a);
	}
	putchar('\n');
	return 0;
}

//do while ���
#include <stdio.h>
int main()
{
	int n = 1;
	do {
		printf("%4d", n);
	} while (n++ < 10);
	return 0;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n=0,m=0;
	scanf("%d", &n);
	do {
		m++;
		printf("%4d", m);
	} while (m < n);
	return 0;

}

//0�� �Էµ� �� ���� ���� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n, sum = 0;
	printf("���ڸ� �Է��ϼ���\n");
	do {
		printf("0 �Է½� ���� : ");
		scanf("%d", &n);
		sum = sum + n;
	} while (n);
	printf("���� : %d", sum);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while (n < 9)
	{
		printf("2 * %d = %d\n", n+=1, n * 2);
	}
	return 0;
}

//���� �Է¹����� �ش� �������� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, dan;
	scanf("%d", &dan);
	while (n++ < 9)
	{
		printf("%d * %d = %d\n", dan, n, dan * n);
	}
	return 0;
}

//������ 2�ܺ��� 9�ܱ��� ����ϴ� �ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2, m = 1;
	while (n < 10)
	{
		m = 1;
		while (m < 10)
		{
			printf("%d * %d = %d\n", n, m, n * m);
			m++;
		}
		printf("\n");
		n++;
	}
	return 0;
}

//������ 2�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int dan = 2, n = 0;
	for (n = 1; n < 10; n++)
	{
		printf("%d * %d = %d\n", dan, n, dan * n);
	}
	printf("%d", n);
	return 0;
}

//������ 2~9���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2, m = 1;
	for (n; n < 10; n++)
	{
		for (m=1; m < 10; m++)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("================\n");
	}
	return 0;
}

//�������� �������� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 9, m = 9;
	for (n; n > 1; n--)
	{
		for (m = 9; m > 0; m--)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("================\n");
	}
	return 0;
}

//2.23
//������ ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0;
	for (n = 2; n < 10; n++)
	{
		for (m = 1; m < 10; m++)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("======================\n");
	}
	printf("\n\n\n");
	for (n = 9; n > 1; n--)
	{
		for (m = 9; m > 0; m--)
		{
			printf("%d * %d = %d\n", n, m, n * m);
		}
		printf("==========\n");
	}
	return 0;
}

//���� �ΰ��� �Է¹����� �μ� ������ �հ� ���� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 1, j = 0;
	printf("������ ���� �� : ");
	scanf("%d", &n);
	printf("(������ ���� �� ���� Ŀ���Ѵ�) ���� ���� �� : ");
	scanf("%d", &m);
	for (n; n <= m; n++)
	{
		j += n;
		i *= n;
	}
	printf("\n���� �� : %d", j);
	printf("\n���� �� : %d", i);
	return 0;
}

//�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n=0; n < 5; n++)
	{
		for (m=0; m < 5; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ���1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 0; n < 5; n++)
	{
		for (m = 0; m <= n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ���2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m < n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�� �ﰢ�� ���3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0, m = 0, i = 0, j = 0;
	for (n = 5; n > 0; n--)
	{
		for (i=0;;)
		for (m = 0; m < n; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

 //3.24
(1)
#include <stdio.h>
int main()
{
	char a = 65;
	while (a <= 90)
	{
		printf("%c\n", a++);
	}
	return 0;
}

//(2)
#include <stdio.h>
int main()
{
	int num = 1, sum = 0;
	while (num <= 10)
	{
		sum += num;
		num++;
	}
	printf("1���� 10������ �� = %d\n",sum);
	printf("while ���� ���� ���� num�� �� = %d\n",num);
	return 0;
}

//(3)
#include <stdio.h>
int main()
{
	int i = 1, n = 0,sum=0;
	scanf_s("%d",&n);
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}

//(4)
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	printf("���� �Է��ϼ���");
	scanf_s("%d", &i);
	do
	{
		printf("%d\n", j);
		j++;
	} while (j < i);
	return 0;
}

//(5)
#include <stdio.h>
int main()
{
	int a = 0, b = 1;
	scanf_s("%d", &a);
	while (b < 10)
	{
		printf("%d * %d = %d\n", a, b, a * b);
		b++;
	}
	return 0;
}

//3.25
//(1)
 for (���۰� ; �ݺ����� ; ������)
 {
 ��ɹ�
 }
 
//(2)
#include <stdio.h>
int main()
{
	int n = 0;
	for (n = 1; n <= 20; n++)
	{
		if (n % 2 == 1)
		{
			printf("%d ", n);
		}
	}
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, n;
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &n);
	for (i; i < n; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 1, x;
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &x);
	for (i; i < 10; i++)
	{
		printf("%d X %d = %d\n", x, i, x * i);
	}
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, n;
	printf("N �Է� : ");
	scanf("%d", &n);
	for (a=0;a<n;a+=1)
	{
		for (b=0; b < n; b += 1)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//(6)
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 0; b < 5; b++)
		{
			printf("%d ", a);
		}
		printf("\n");
	}
	printf("\n");
	for (a = 0; a < 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			printf("%d ", b);
		}
		printf("\n");
	}
	return 0;
}