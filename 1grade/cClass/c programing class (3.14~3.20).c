//&(AND) = �� ���� ��Ʈ ��� ���� �� 1�� ��ȯ
//|(OR) = �� ���� ��Ʈ�� �ϳ��� ���� �� 1�� ��ȯ
//^(XOR) = �� ���� ��Ʈ�� ���� �ٸ� ��쿡 1�� ��ȯ
//~(NOT) = ��Ʈ�� 0���� 1��, 1���� 0���� ������Ų��
// (MSB�� �����Ǿ� ��ȣ�� �ٲ��)
//MSB = �ֻ��� ��Ʈ
//LSB = ������ ��Ʈ
//<< / >> (shift) = ��Ʈ���� nĭ�� �̵�
//(��) num = 15 num<<1 = num�� ��Ʈ ���� �������� 1ĭ�� �̵� = 30)
//sizeof = ����,���,�ڷ����� ũ�⸦ Ȯ�� �� �� �ִ�
//ASCII ��ȣ�� ���ڸ� ����� ��ȯ�� �� �ִ�
//getchar = scanf�� ����ϴ� ���� ����(���� �Է��ϰ� enter�� �����ٸ� enter�� ���� scanf�� ��)
//�� �Ͼ�� getchar(); �� �ڵ忡 �߰��� �ذ��� �� �ִ�
//int�� ������ short�� ���꺸�� ������ ����ȴ�
//�ǿ������� �ڷ��� ����ġ�� �߻��ϴ� �ڵ� ����ȯ(typcasting)
//(��)int n1=3,n2=4 double d   d=n1/n2;
//=>3/4=0 ������ �ڵ����� double������ ����ȯ �� ���ȴ�)

//3.15
 #include <stdio.h>
int main()
{
	int num1 = 15; //00000000 00000000 00000000 00001111 (1+2+4+8)
	int num2 = 20; //00000000 00000000 00000000 00010100 (4+16)
	int num3 = num1 & num2; //num1�� num2�� ��Ʈ���� & ����
	printf("AND ������ ���: %d \n",num3);	
	return 0;
} 

#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 1, d = 1;
	printf("%d", a == b & c ==d);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1 = 15, n2 = 20;
	int answer = n1 | n2;
	printf("%d", answer);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	printf("�� ������ �Է��ϼ���");
	scanf_s("%d %d", &a, &b);
	printf("%d", a | b);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2;
	printf("%d\n", n);
	printf("%d\n", n << 1);
	printf("%d\n", n << 2);
	printf("%d\n", n << 3);
	printf("%d\n", n << 4);
	printf("%d\n", n << 14);
	printf("%d\n", n << 30);//overflow (�ڷ����� ���� �� ������)
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 1024;
	printf("%d\n", n);//00000100 00000000
	printf("%d\n", n >> 1); 
	printf("%d\n", n >> 2);
	printf("%d\n", n >> 3);
	printf("%d\n", n >> 9);
	printf("%d\n", n >> 10);
	printf("%d\n", n >> 11);//0
	printf("%d\n", n >> 12);//0
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	n = ~n;
	n++;
	printf("%d\n", n);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ch = 9;
	printf("ch�� ũ�� : %d\n", sizeof(ch));
	printf("���� 9�� ũ�� : %d\n", sizeof(9));
	int n = 9;
	printf("n�� ũ�� : %d\n", sizeof(n));
	printf("���� 9�� ũ�� : %d\n", sizeof(9));
	double d = 9.1234;
	printf("d�� ũ�� : %d\n", sizeof(d));
	printf("���� 9.1234�� ũ�� : %d\n", sizeof(9.1234));
	return 0;
}

//�������� �Է¹޾� �����̸� ���ϴ� �ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double area = 0, r = 0;
	printf("�������� �Է��ϼ���");
	scanf("%lf", &r);
	area = r * r * 3.14;
	printf("������ %.lf�� ���� ���̴� %1.lf�Դϴ�", r,area);
	return 0;
}


//3.16
#include <stdio.h>
int main()
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;
	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);

	return 0;
}

//ASCII��ȣ > ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n= 0;
	scanf("%d", &n);
	printf("ASCII ���� %c\n", n);
	return 0;
}

//ASCII���� > ��ȣ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char n= 0;
	scanf("%c", &n);
	printf("ASCII ��ȣ %d\n", n);
	return 0;
}

//getchar���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
		int n= 0;
	scanf("%d", &n);
	printf("ASCII ���� %c\n", n);
	getchar();
		char n= 0;
	scanf("%c", &n);
	printf("ASCII ��ȣ %d\n", n);
	return 0;
}

//�� ���� �Է¹޾� �簢���� ���̸� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	int x = 0, y = 0, a = 0;
	printf("�簢���� �� �ϴ��� x,y��ǥ�� �Է��ϼ���");
	scanf("%d %d", &x1, &x2);
	getchar();
	printf("�簢���� �� ����� x,y��ǥ�� �Է��ϼ���");
	scanf("%d %d", &x3, &x4);
	x = x3 - x1;
	y = x4 - x2;
	a = x * y;
	printf("�簢���� ���� %d", a);
	return 0;
}

//3.17
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d", &a, &b);
	c = ++a + b--;
	printf("a = %d,b = %d,c = %d", a,b,c);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a = 0, b = 0, c = 0;
	float avg = 0;
	printf("������ �� 3������ ������ �Է��ϼ���");
	scanf("%f %f %f", &a, &b, &c);
	avg = (a + b + c) / 3;
	printf("avg = %.1f", avg);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a = 0, b = 0, c = 0, sum = 0, avg = 0;
	printf("�Ǽ��� �� 3������ ������ �Է��ϼ���");
	scanf("%f %f %f", &a, &b, &c);
	avg = a + b + c;
	avg = avg / 3;
	printf("%d\n", (int)a + (int)b + (int)c);
	printf("%.f", avg);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a > b));
	printf("%d\n", (b >= c));
	printf("%d\n", (a <= b));
	printf("%d\n", (b < c));
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double A = 0, B = 0, C = 0;
	printf("yard? ");
	scanf("%lf", &A);
	B = A * 91.44;
	printf("%.1fyard = %.1f", A, B);
	return 0;
}

//3.18
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d %d %d %d %d", a + 3, a - 3, a * 3, a / 3, a % 3);
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 10, b = 10;
	printf("���ʰ� a = %d, b = %d\n\n", a, b);
	printf("a++ = %d, ++b = %d\n", a++, ++b);
	printf("������ a = %d, b = %d\n\n", a, b);
	printf("a-- = %d, --b = %d\n", a--, --b);
	printf("������ a = %d, b = %d", a, b);
	return 0;
}

//(3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a += 100, b %= 10);
	printf("%d %d", a , b);
	return 0;
}

//(4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("%s\n", "���� ����� ���� ����ǥ�� �����մϴ�");
	printf("%d\n",123);
	printf("%f\n",6.5);
	printf("%f\n",68.6);
	printf("%d + %d = %d\n",10,5,10+5);
	printf("�� ������ %d�� %d�� %d�� �Դϴ�\n",2005,07,05);
	return 0;
}

//(5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d�ʴ� %d�� %d�� �Դϴ�.", a, a / 60, a % 60);
	return 0;
}

//(6)
#include <stdio.h>
int main()
{
	printf("\na\n");//�ٹٲ�
	printf("\fa\n");
	printf("\ta\n");//tab
	printf("\\a\n");
	printf("\va\n");
	printf("\"a\n");
	return 0;
}

//(8)
#include <stdio.h>
int main()
{
	int a = 123;
	printf("%8d\n", a);//����� ���� 8ĭȮ��
		printf("%-8d", a);
	return 0;
}