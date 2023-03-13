// ������ (pointer) = �ּҸ� �����ϴ� ����
// [���][���������] ��ǻ�� �׷��Ƚ�����, �׸��� �����ϱ� ���� 
// ���콺 ���� ��ġ ���� ��ġ�� ���� ����ڰ� �̵���ų �� �ִ�, 
// ȭ�鿡 ǥ�õ� ��ȣ.���Թ� ǥ��� ��Ȯ���̴�.
// 
// ������ = �ּҸ� �����ϴ� ����
// �� �����ʹ� ������ �����ϴ�(��������)
// 
// �����ϴ� ��
// int* p;
// 
// �ּҸ� ����� �� �� %p�� ����Ѵ�(16���� ���)
// 
// ������ ����
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// int main()
// {
// 	int* p;						int* p = ������ ����Ű�� �����ͺ���
// 	int a = 100;
// 	printf("%d\n", 100);
// 	p = &a;						p�� a�� �ּҰ��� ����Ű�� ��
// 	printf("%p\n", &a);
// 	printf("%d\n", a);
// 	printf("%d %p\n", *p, p);	*p = p�� �ּҰ� ����Ű�� ��	p = �ּ� 
// 	return 0;
// }
// 
// �����Ϳ� ���������ڸ� ��� �� �� ��ȣ�� ���ش�
// (��ȣ�� �� = �ּҰ� ����Ű�� ���� ���������ڸ� ��ģ��
// ��ȣ�� ���� ���� = �ּҰ� ���������ڸ� ��ģ��)
// 
// �迭�� ù ���� ����� �ּ� ���� ��Ÿ����
// �迭 a�� �迭 a[0] �� �ּҴ� ����
// (�迭 �̸��� �迭 ù��°�� �ּҴ� ����) 
// int�� �迭�� ���� �ִ´ٸ� ��ĭ��ĭ���� 
// 4byte�� ����Ѵ�
// => ù ��° �迭�� �ּҿ��� �ּҸ� 4�� �÷����ϸ� �������� ���´�
// 
//							������		�迭�̸�
// �̸��� �����ϴ°�	���� �ִ�		�翬�� �ִ�
// ������ ��Ÿ���°�	�޸��� �ּ�	�޸��� �ּ�
// �����ΰ� ����ΰ�	����			���
// 
// �� 
// int main()
// {
//		int a[5] = {0,1,2,3,4};
//		int b = 10;
//		a = &b; //a�� ����̹Ƿ� ����, a�� �������ٸ�
// }

//4.26
//������ ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int* p;
	int a = 100;
	printf("%d\n", a);
	p = &a;
	printf("%p\n", &a);
	printf("%d\n", a);
	printf("%d %p\n", *p, p);
	*p = 300;
	printf("%d\n", a);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num1 = 100, num2 = 100;
	int* pNum;
	pNum = &num1;
	(*pNum) = 50;
	pNum = &num2;
	(*pNum) = -30;
	printf("%d %d\n", num1, num2);
	int n1 = 100;
	int* p;
	p = &n1;
	printf("�ּ�(Address) :%p, &p\n", p, &n1);
	printf("����, �� :%d, %d\n", *p, n1);
	for (int i = 0; i < 5; i++)
	{
		printf("%4d", (*p)++);
	}
	printf("\n%d\n", n1);
	return 0;
}

//�迭�� �������� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[5] = { 1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%p %p\n", &a[0], &a[1]);
	printf("a�ּ� = %p a[0]�ּ� = %p\n", &a, &a[0]);
	int* p = a;
	printf("a�ּ� = %p\n", p);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	int* p;
	p = arr;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p+1), *(p+2));
	int* P = arr;
	P[1] = 0;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%p\n", &P);
	printf("&p\n", arr[1]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	int* p;
	p = arr;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));
	int* P = arr;
	P[1] = 0;
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%p\n", P);
	printf("%p\n", &arr[0]);
	return 0;
}

//������ ���� ����
//�����ͷ� �Է��� �޾� �迭�� �ֱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[10], i = 0;
	int* p = arr;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
		//scanf("%d", &(*p));
		scanf("%d", &*(p + i));
		//p += 4;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int* p,i=0;
	int arr[10];
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	p = arr;
	for (i = 0; i < 10; i++)		
	{
		scanf("%d",p);
		arr[i] = *p;
		p += 4;
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

//(4.29)
#define MAX 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int ar[MAX];
	for (i = 0; i < MAX; i++)
	{
		printf("%d�� �л��� ��c������ �Է��ϼ���", i + 1);
		scanf("%d", &ar[i]);
	}
	for (i = 0; i < MAX; i++)
	{
		if (j < ar[i])
		{
			j = ar[i];
		}
	}
	printf("�ְ����� : %d", j);
	return 0;
}
//���� ������ ������ �ڵ�
#define MAX 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int ar[MAX];
	for (i = 0; i < MAX; i++)
	{
		printf("%d�� �л��� ��c������ �Է��ϼ���", i + 1);
		scanf("%d", &ar[i]);
	}
	j = ar[0];
	for (i = 0; i < MAX-1; i++)
	{
		if (j < ar[i+1])
		{
			j = ar[i+1];
		}
	}
	printf("�ְ����� : %d", j);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[5];
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		printf("����� �Է��ϼ���");
		scanf("%d", &ar[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\t", ar[i]);
	}
	for (i = 0; i < 5; i++)
	{
		if (ar[i] > j)
		{
			j = ar[i];
		}
	}
	printf("\n�ִ밪 : %d", j);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[100];
	int i = 0, j = 0;
	float v = 0;
	printf("������ �Է¹��� �л��� ���� �Է��ϼ���");
	scanf("%d", &i);
	for (j = 0; j < i; j++)
	{
		printf("%d��° �л��� ������ �Է��ϼ���", j + 1);
		scanf("%d", &ar[j]);
		v += ar[j];
	}
	v = v / i;
	printf("��� : %.2f", v);
	return 0;
}