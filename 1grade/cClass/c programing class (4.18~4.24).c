 //static = ���������ε� ���������� ���� ����� �� �ִ�
 //(static�� ����ϸ� �ʱ�ȭ�� �� �� �� �ȴ�) 
 //(���������� ������Դ� �������� ��ǻ�Ϳ��Դ� �����)
 //(�� ���������̱� ������ main������ ����� �� ����)
 //������ �迭�� �̸��� �ּ��̴�
 //'a'�� "a"�� ���� = 'a'�� ���� "a"�� ���ڿ�
 //("a"�� ���ڿ��� �ִ�)
 //(sizeof�� ������ ���� �� �� �ִ�)
 //(\n�� �� ���ڷ� ����Ѵ�)
 //(���ڿ��� ��� �� �� �ι��ڱ��� ����Ѵ�)
 //(���ڿ� �߰��� �ι��ڰ� ������ ������ ����� ���Ѵ�)
 //& = �ּ� �迭�� �̸� = �ּ� 
 //(scanf�� &�� ���� �ʾƵ� �ȴ�)

//4.19
//�������� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int func(int n)
{
	static int a = 0;
	a++;
	printf("a = %d, n = %d\n",a,n);
	return 0;
}
int main()
{
	func(5);
	func(5);
	return 0;
}

//������ �迭
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	int ar[5];
	ar[0] = 0;
	ar[1] = 0;
	ar[2] = 0;
	ar[3] = 0;
	ar[4] = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d��° �迭�� �� ���� �Է��ϼ���", i);
		scanf("%d", &ar[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d��° �迭�� �ִ� �� = %d\n", i, ar[i]);
	}
	return 0;
}

//�迭�� ���� ū ���� ��ġ�� �˷��ִ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, a = 0;
	int ar[5];
	for (i = 0; i < 5; i++)
	{
		ar[i] = 0;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d��° �迭�� �� ���� �Է��ϼ���", i);
		scanf("%d", &ar[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		if (a < ar[i])
		{
			a = i;
		}
	}
	printf("�ε��� %d�� ���� ���� ũ��", a);
	return 0;
}

//�迭�� �ּҰ�, ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, min = 0, a = 0;
	int ar[5];
	for (i = 0; i < 5; i++)
	{
		ar[i] = 0;
	}
	for (i = 0; i < 5; i++)
	{
	printf("%d��° �迭�� �� ���� �Է��ϼ���", i);
		scanf("%d", &ar[i]);
		min = ar[i];
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		if (min > ar[i])
		{
			min = ar[i];
		}
		a += ar[i];
	}
	printf("�ּҰ� = %d ���� = %d",min,a);
	return 0;
}

//���ڿ� ���ڿ�,�ι���
#include <stdio.h>
int main()
{
	char str[] = "Hello World\n";
	printf("str = %s\n", str);
	printf("str�� ũ�� %d\n", sizeof(str));
	printf("%d\n", sizeof("Hello"));
	char str1[10];
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	str1[4] = 'd';
	str1[5] = 'e';
	printf("str1 = %s\n", str1);
	return 0;
}

//�Է��� ���ڿ��� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char str[20];
	scanf("%s", str);
	while (str[i] != '\0')
		printf("%c", str[i++]);
	return 0;
}

//�ݴ�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	char str[100];
	scanf("%s", str);
	while (1)
	{
		if (str[a] == '\0')
		{
			break;
		}
		a++;
	}
	for (a; a >= 0; a--)
		printf("%c", str[a]);
	return 0;
}
//+�������ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int strlen(char str[])
{
	int len = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		len++;
	}
	return len;
}
int main()
{
	char str[20];
	scanf("%s", str);
	int len = strlen(str);//string���� length����
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
//+�������ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[20];
	int i = 0;
	scanf("%s", str);
	while (str[i] != '\0')
	{
		i++;
	}
	for (i--; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
//+���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[20];
	int i = 0;
	scanf("%[^\n]", str);
	printf("%s\n", str);
	return 0;
}

//�ָ�����(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	//���� ������ �Է¹޾�
	//����ܾ��� �ҹ����� ����(����)�� �˷��ִ� ���α׷��� ����ÿ�.
	char word[50];
	int i = 0, j = 0;
	for (i = 0; i < 50; i++)
	{
		word[i] = 0;
	}
	scanf("%[^\n]", word);
	//���� Hello ��� 4 ���
	//I Love you ��� �ҹ��� ���� 6 ���
	for (i = 0; i < 50; i++)
	{
		if (word[i] > 96 && word[i] < 123)
		{
			j++;
		}
	}
	printf("�ҹ��� ���� : %d", j);
	return 0;
} 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char a;
	scanf("%c", &a);
	printf("%d", a);
	return 0;
}

//�ָ�����(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char word[100],j=0;
	for (i = 0; i < 100; i++)
	{
		word[i] = 0;
	}
	scanf("%s", &word);
	for (i = 0; word[i] > 0; i++)
	{
		if (j < word[i])
		{
			j = word[i];
		}
	}
	printf("%c", j);
	return 0;
}

//���ڿ����������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[100];
	int i = 0, j = 0;
	printf("������ ���ڿ��� �Է��ϼ���");
	for (i = 0; i < 99; i++)
	{
		str[i] = 0;
	}
	//scanf("%s", &str);�̷��� �ϸ� �� �ȵǴ���, %s�� scanf�� 
	//������ � ������ �����̽��ٿ��� ©������
	//scanf("%[^\n]", str);
	fgets(str, 100, stdin);
	for (i = 0; i < 99; i++)
	{
		if (str[i] == '\n')
		{
			j = i-1;
		}
	}
	for (j; j >= 0; j--)
	{
		printf("%c", str[j]);
	}
	return 0;
}

//�迭����
// (�� ���� �迭�� ���
// ù�� ° �ٿ� ù�� °, �ι�° �迭�� ���� ���� ����
// �ι� ° �ٿ� ù�� ° �迭�� ���� ��
// ���� ° �ٿ� �ι� ° �迭�� ���� ��
//
// �� �� �迭�� ������ ������������ �����ϴ� ���α׷�
// )
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, j, n = 0, m = 0, c = 0, d = 0;
	int a[999], b[999];
	scanf("%d %d", &i, &j);
	for (n = 0; n < i;n++)
	{
		scanf("%d", &a[n]);
	}
	for (n = 0; n < j; n++)
	{
		scanf("%d", &b[n]);
	}
	n = 0;
	while (1)
	{
		if (a[n] > b[m] || c == 1)
		{
			printf("%d ", b[m]);
			m++;
		}
		else if (a[n] < b[m] || d == 1)
		{
			printf("%d ", a[n]);
			n++;
		}
		else
		{
			printf("%d %d ", a[n], b[m]);
			n++;
			m++;
		}
		if (n == i && m == j)
		{
			break;
		}
		if (n >= i)
		{
			c = 1;
		}
		if (m >= j)
		{
			d = 1;
		}
	}
	return 0;
}

//4.21
//(1)
MAX = 6;
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int j = 0;
	float i=0, ar[6];
	for (j = 0; j < MAX; j++)
	{
		printf("6���� ü���� �Է��ϼ���");
		scanf("%f", &ar[j]);
		i += ar[j];
	}
	i /= MAX;
	printf("%.1f", i);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[10], i = 0, odd = 0, even = 0;
	for (i = 0; i < 10; i++)
	{
	printf("������ �Է��ϰ� enter�� ��������");
		scanf("%d", &ar[i]);
		if (i % 2 == 0)//Ȧ����° ��
		{
			odd += ar[i];
		}
		else
		{
			even += ar[i];
		}
	}
	printf("odd = %d\n", odd);
	printf("even = %d\n", even);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ar[100], i = 0, a = 0, b = 0, max = 0, min = 0;
	for (i = 0; i < 100; i++)
	{
		printf("�迭�� %d��° ���� �Է��ϰ� enter�� ��������", i);
		scanf("%d", &ar[i]);
		if (ar[i] == 999)
		{ 
			if (i == 0)
			{
				return 0;
			}
			break;
		}
		if (i == 0)
		{
			max = ar[i];
			min = ar[i];
		}
		if (max < ar[i])
		{
			max = ar[i];
		}
		if (min > ar[i])
		{
			min = ar[i];
		}
	}
	printf("\n");
	printf("max = %d\n", max);
	printf("min = %d\n", min);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char i ,j = 0;
	scanf("%c", &j);
	while (1)
	{
		scanf("%c", &i);
		if ('\n' == i)
		{
			printf("\"Hello\"");
		}
		if ('\n'!=i)
		{
			break;
		}
	}
	return 0;
}

//4.22
//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int k, e, m,average;
	printf("����, ����, ���� ������ �Է��ϼ���");
	scanf("%d %d %d", &k, &e, &m);
	average = (k + e + m) / 3;
	if (average >= 80)
	{
		printf("�հ�!\t");
		printf("������� = %d",average);
	}
	else
	{
		printf("���հ�!\t");
		printf("������ ���� = %d", 80 - average);
	}
	return 0;
}

//(6)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int head, leg;
	scanf("%d %d", &leg, &head);
	printf("�䳢 : %d\t �� : %d\t", (leg / 2) - head, head * 2 - (leg / 2));
	return 0;
}

//(7)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ar[30], j = 0, c = 0;
	int  i = 0,n=0;
	printf("�ʱⰪ�� �Է��ϼ���");
	scanf("%s", ar);
	while (1)
	{
		printf("���� ��� �ε����� �Է��ϼ���");
		scanf("%d", &j);
		printf("�������� �Է��ϼ���");
		scanf(" %c", &i);
		ar[j-1] = i;
		printf("%s", ar);
	}
	return 0;
}