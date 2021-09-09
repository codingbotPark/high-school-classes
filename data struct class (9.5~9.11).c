// 9.6~9.11
// 스택
// FILO(First In Last Out)
// 먼저 들어온게 마지막에 나간다
// 
// 보통 코드에 'top' 을 사용
// 
// 큐
// FIFO(First In First Out)
// 먼저 들어온게 먼저 나간다
// 
// 보통 코드에 'front,back' 을 사용
// 
// switch - case 문이 if else 문보다 조금 더 빠르다
// 
// 
// 포인터 대신 전역변수도 사용할 수 있지만
// 외부에 노출되서 보안에 문제가 생길 수 있다

//9.6
//버블정렬
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




//스택과 큐
//스택
//스택에는 push 와 pop 과 관련있다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5//스택에 넣을 수 있는 최대 사이즈

void push(int);//스택에서 데이터 한 개 삽입
void pop();//스택에서 데이터 한 개 삭제
void display();//스택안의 요소를 보여주는 함수

int stack[SIZE];
int top = -1;//스택에 저장할 위치

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
		case 2://스택에서 pop
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			return 0;
		default:
			printf("다시입력하세요");
		}
	}
}

void push(int val) {
	if (top == SIZE - 1)
	{
		printf("스택이 가득참\n");
	}
	else
	{
		stack[++top] = val;
	}
}

void pop() {
	if (top == -1)
		printf("스택이 비었음\n");
	else
		printf("%d\n", stack[top--]);
}
void display()
{
	if (top == -1)
		printf("스택이 비었음 \n");
	else
		for (int i = top; i >= 0; i--)
			printf("%4d", stack[i]);
}

 //push는 최근의 값을 넣는 역할
 //
 //pop은 현재있는 값들중 가장 최근에 들어온 값을 뺀다
 //이 코드에서는 실제 값을 빼지 않고 top의 값을 옮겨서
 //출력할 때 출력을 하지 않는 방법으로 작동한다
 //
 //top은 현제있는 값들중 가장 최근에 들어온 값의 위치이다
 //
 //++top 하는 이유는 값을 push할 때 top(가장 최근에 들어온 값의 위치)
 //top-- 하는 이유는 pop할 때 값을 직접 삭제하지 않고 top의 값을 -함으로
 //출력할 때 출력이 되지 않도록 한다



//9.9
//큐
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int queue[5];

void menuf()
{
	printf("1. 큐에 삽입 2. 큐에서 삭제\n");
	printf("3. 내용 보기 4. 종료\n");
}

void Enqueue(int* back, int item)//큐에 삽입
{//back에 주소가 넘어와서 * 를 해야 값에 접근
	if (*back == 4)
	{
		printf("큐가 가득참\n");
		return;
	}
	queue[++ * back] = item;
	//전역변수로 back을 빼도 되지만
	//보안에 문제가 생길 수 있다
}

int Dequeue(int* front, int back)//큐에 삭제
{
	if (*front == back)//큐가 비었음
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
			//바뀐 값이 유지가 되어야 하기 때문에
			//call by reference
			break;
		case 2:
			item = Dequeue(&front, back);
			if (item == -1)
			{
				printf("큐가 비었음");
			}
			else
			{
				printf("%d가 삭제됨\n",item);
			}
			break;
		case 3:
			Display(front, back);//디스플레이를 보는함수
			break;
		case 4:
			return 0;
		default:
			printf("다시 입력해주세요"); 
		}
	}
	return 0;
}