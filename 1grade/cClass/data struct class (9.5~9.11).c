// 9.6~9.11
// ����
// FILO(First In Last Out)
// ���� ���°� �������� ������
// 
// ���� �ڵ忡 'top' �� ���
// 
// ť
// FIFO(First In First Out)
// ���� ���°� ���� ������
// 
// ���� �ڵ忡 'front,back' �� ���
// 
// switch - case ���� if else ������ ���� �� ������
// 
// 
// ������ ��� ���������� ����� �� ������
// �ܺο� ����Ǽ� ���ȿ� ������ ���� �� �ִ�

//9.6
//��������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void bubble1(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
}

int main()
{
	int a[5] = { 5,2,3,4,1 };
	bubble1(a, 5);
	printf("%d %d %d %d %d", a[0], a[1], a[2], a[3], a[4]);

}




//���ð� ť
//����
//���ÿ��� push �� pop �� �����ִ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5//���ÿ� ���� �� �ִ� �ִ� ������

void push(int);//���ÿ��� ������ �� �� ����
void pop();//���ÿ��� ������ �� �� ����
void display();//���þ��� ��Ҹ� �����ִ� �Լ�

int stack[SIZE];
int top = -1;//���ÿ� ������ ��ġ

int main()
{
	int val, choice;
	printf("\n----Menu----\n");
	while (1)
	{
		printf("1.push  2.pop  3.display  4.exit\n");
		printf("Choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			scanf("%d", &val);
			push(val);
			break;
		case 2://���ÿ��� pop
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			return 0;
		default:
			printf("�ٽ��Է��ϼ���");
		}
	}
}

void push(int val) {
	if (top == SIZE - 1)
	{
		printf("������ ������\n");
	}
	else
	{
		stack[++top] = val;
	}
}

void pop() {
	if (top == -1)
		printf("������ �����\n");
	else
		printf("%d\n", stack[top--]);
}
void display()
{
	if (top == -1)
		printf("������ ����� \n");
	else
		for (int i = top; i >= 0; i--)
			printf("%4d", stack[i]);
}

 //push�� �ֱ��� ���� �ִ� ����
 //
 //pop�� �����ִ� ������ ���� �ֱٿ� ���� ���� ����
 //�� �ڵ忡���� ���� ���� ���� �ʰ� top�� ���� �Űܼ�
 //����� �� ����� ���� �ʴ� ������� �۵��Ѵ�
 //
 //top�� �����ִ� ������ ���� �ֱٿ� ���� ���� ��ġ�̴�
 //
 //++top �ϴ� ������ ���� push�� �� top(���� �ֱٿ� ���� ���� ��ġ)
 //top-- �ϴ� ������ pop�� �� ���� ���� �������� �ʰ� top�� ���� -������
 //����� �� ����� ���� �ʵ��� �Ѵ�



//9.9
//ť
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int queue[5];

void menuf()
{
	printf("1. ť�� ���� 2. ť���� ����\n");
	printf("3. ���� ���� 4. ����\n");
}

void Enqueue(int* back, int item)//ť�� ����
{//back�� �ּҰ� �Ѿ�ͼ� * �� �ؾ� ���� ����
	if (*back == 4)
	{
		printf("ť�� ������\n");
		return;
	}
	queue[++ * back] = item;
	//���������� back�� ���� ������
	//���ȿ� ������ ���� �� �ִ�
}

int Dequeue(int* front, int back)//ť�� ����
{
	if (*front == back)//ť�� �����
	{
		return -1;
	}
	return queue[++ * front];
	
}

void Display(int front, int back)
{
	for (int i = front+1; i <= back; i++)
	{
		printf("%d\n", queue[i]);
	}
}

int main()
{
	int front = -1, back = -1;
	int menu, item;
	while (1)
	{
		menuf();
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			scanf("%d", &item);
			Enqueue(&back,item);
			//�ٲ� ���� ������ �Ǿ�� �ϱ� ������
			//call by reference
			break;
		case 2:
			item = Dequeue(&front, back);
			if (item == -1)
			{
				printf("ť�� �����");
			}
			else
			{
				printf("%d�� ������\n",item);
			}
			break;
		case 3:
			Display(front, back);//���÷��̸� �����Լ�
			break;
		case 4:
			return 0;
		default:
			printf("�ٽ� �Է����ּ���"); 
		}
	}
	return 0;
}