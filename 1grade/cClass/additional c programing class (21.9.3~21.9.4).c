//������ �Է¹ް�  a b c f ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a;
	char b;
	scanf("%f", &a);
	if (a > 90)
	{
		b = 'A';
	}
	else if (a >= 80)
	{
		b = 'B';
	}
	else if (a >= 70)
	{
		b = 'C';
	}
	else
	{
		b = 'F';
	}
	printf("%c", b);

	return 0;
}

//1���� �Է¹��� ������ ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a,b;
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &a);
	b = (a + 1) * (a / 2);
	if (a % 2 == 1)//Ȧ���� ��
	{
		b += (a / 2) + 1;
	}
	printf("%d", b);
	return 0;
}

//�Է��� ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	printf("���� �Է��ϼ���");
	scanf("%d", &a);
	for (int i = 1; i < 10; i++)
	{
		printf("%d X %d = %d\n", a, i, a * i);
	}
	return 0;
}

//1���� �Է��� ������ �� 3�� ����� ������ ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		if (i % 3 == 0)
		{
			continue;
		}
		printf("%d ", i);
	}
	return 0;
}


//1���� �Է��Ѽ����� Ȧ���� ��� ����, ¦���� ��� ���� �Ͽ� ��� ���� �հ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a,b=0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		if (i % 2 == 1)
		{
			b += i;
		}
		else
		{
			b -= i;
		}
	}
	printf("%d", b);
	return 0;
}

//���ڿ��� ����, ���ڿ�, Ư�����ڸ� �Է¹޾� Ư�� ������ ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	char c;
	int  n, cnt = 0;

	printf("���ڿ� ���� �Է� : ");
	scanf(" %d", &n);
	printf("���ڿ� �Է� : ");
	scanf(" %s", str);
	printf("Ư�� ���� �Է� : ");
	scanf(" %c", &c);

	for (int i = 0; i < n; i++)
	{
		if (str[i] == c)
		{
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}

//���� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� �ٲٱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	char c;
	int n, cnt = 0;

	printf("���ڿ� ���� : ");
	scanf("%d", &n);
	printf("���ڿ� �Է� : ");
	scanf(" %s", str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] > 90)
		{
			printf("%c", str[i] - 'a' + 'A');
		}
		else
		{
			printf("%c", str[i] + 'a' - 'A');
		}
	}
	return 0;
}


//�����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a[100] = { 0, }, b, temp = 0;
	srand((unsigned)time(NULL));

	printf("������ ���� ������ �Է��ϼ��� : ");
	scanf("%d", &b);

	for (int i = 0; i < b; i++)
	{
		a[i] = rand() % 100;
	}

	for (int i = 0; i < b-1; i++)
	{
		for (int j = 0; j < b - 1 - i ; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < b; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}

//�Ǻ���ġ ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	int a = 1, b = 1, c = 0;
	scanf("%d", &n);
	for (int i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d", c);
	return 0;
}
//�̷��� 3���� ������ ����ϸ� ������ �Ǻ���ġ �������� �� �� ����
//�� ���� ����� ��� �ʿ��ϸ� �迭�� ���� ���� ����� �����ν�
//�ߺ��Ǵ� ��쿡 ����ϴ� ������ ���ش�
//�� ����� �޸������̼��̶� �Ѵ�
//+����Լ��� �Ǻ���ġ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[100];

int p(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return p(n - 1) + p(n - 2);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", p(n));

	return 0;
}	
//����Լ� = ����߽�
//�ݺ��� = �����߽�
//����Լ����� ������ ���� ���ư��� ���� ��Ʈ��ŷ�̶� �Ѵ�
//
//�Էµ� ���ڿ��� �Ųٷ� ������ �� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[100], tmp;
	int i;

	scanf(" %s", &str);
	for (i = 0;; i++)
	{
		if (str[i] == NULL)
		{
			break;
		}
	}
	for (int j = 0; j < i / 2; j++)
	{
		tmp = str[j];
		str[j] = str[(i-1) - j];
		str[(i-1) - j] = tmp;
	}
	printf("%s", str);
	return 0;
}

//���ڿ����� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100] = { 0, };
	int i;
	scanf("%s", &str);
	for (i = 0;; i++)
	{
		if (str[i] == NULL)
		{
			break;
		}
	}
	printf("%d", i);
	return 0;
}

//���ڿ��� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[100];
	int i;
	scanf("%s %s", str1, str2);
	if (strlen(str1) == strlen(str2))
	{
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				break;
			}
		}
		if (i == strlen(str1))
		{
			printf("����");
			return 0;
		}
	}
	printf("�ٸ���");
	return 0;
}

//���ڿ��� �ٸ� �迭�� �����ϴ� �Լ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = { 0, }, str2[100] = { 0, };
	int i;
	scanf("%s", str1);

	for (i = 0; i < strlen(str1); i++)
	{
		str2[i] = str1[i];
	}

	printf("%s\n%s", str1, str2);
	return 0;
}

//ù ��° ���ڿ� �ڿ� �� ��° ���ڿ��� ���̱�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100] = { 0, }, str2[100] = {0,};
	int i, j;
	scanf("%s %s", str1, str2);
	j = strlen(str2);
	i = strlen(str1);
	for (int k =0; k < j;k++)
	{
		str1[i + k] = str2[k];
	}
	printf("%s", str1);
	return 0;
}