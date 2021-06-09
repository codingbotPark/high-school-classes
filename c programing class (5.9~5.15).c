// 달팽이배열 
// 말그대로 사각형을 그리며 값을 채우는 배열
// 가로에서 세로로 갈 때 이동하는 개수가 적어지는 점을 활용
// 
// 
// 버블정렬 
// 무작위로 주어진 수를 정렬하는 것
// swap을 사용해 이웃하는 항과 비교해 교환을 사용
// n개의 값이 있으면 비교는 n-1번인 점을 활용 
// 
// call by value = 값에 의한 호출
// 함수 호출시 전달되는 변수의 값을 복사하여 함수의 인자로 전달한다.
// 복사된 인자는 함수 안에서 지역적으로 사용되는 local value의 특성을 가진다.
// 따라서 함수 안에서 인자의 값이 변경되어도, 외부의 변수의 값은 변경되지 않는다.
// 
// call by reference = 참조에 의한 호출
// 함수 호출시 인자로 전달되는 변수의 레퍼런스를 전달한다. (해당 변수를 가르킨다.)
// 따라서 함수 안에서 인자의 값이 변경되면, 아규먼트로 전달된 객체의 값도 함께 변경된다.
// 
// 
// 버블정렬과 선택정렬의 차이
// 버블정렬은 배열을 다 거치면서 하나씩 비교해서 한칸씩 이동 시키지만
// 선택정렬은 정해진 자리대로 가장 작은 수를 가장 처음에...한다
// => 선택정렬과 버블정렬과 달리 배열의 인덱스만 바꾸고 마지막에 그 바꾸는 값을 실행시키기
// 때문에 더 시간이 짧게 걸린다

//5.10
//달팽이배열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIDE 100
int arr[SIDE][SIDE];
void makearr(int n)
{
	int cnt = 1;//1,2,3,4..
	int row = 0, col = -1;
	int inc = 1;//인덱스 증가 감소
	while (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			col += inc;//가로 0부터 시작 1, 2, 3 ... n 만큼
			arr[row][col] = cnt++;//배열의 가로를 cnt++을 이용해 1,2,3 ... n 만큼 값을 넣는다
		}
		n--;//가로로 입력한 줄만큼 이동 / -를 해주면서 5칸 중 겹치는 1칸을 넘김
		// n--를 두 개의 for 사이에 둠으로써 가로세로
		if (n == 0) break;//n이 0 이 될 때까지
		for (int i = 0; i < n; i++)
		{
			row += inc;
			arr[row][col] = cnt++;
		}
		inc *= -1;
	}
}
void printarr(int n)
{
	for (int i = 0; i	< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	printf("달팽이 배열의 길이 : ");
	scanf("%d", &n);
	makearr(n);//달팽이 배열 만들기
	printarr(n);
	return 0;
}


//버블정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int arr[], int len);

int main()
{
	int arr[5] = { 4,6,1,3,9 };
	BubbleSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}

void BubbleSort(int* arr, int len)
{
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)//한 번만 수를 거치면 배열이 되지 않기 때문에
			//len -i-1을 하며 0이 될 때 까지 배열을 돈다
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//달팽이배열연습
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100
int arr[SIZE][SIZE] = { 0, };
void makearr(int n)
{
	int cnt = 1;
	int row = 0, col = -1;
	int inc = 1;
	while (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			col += inc;
			arr[row][col] = cnt++;
		}
		n--;
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			row += inc;
			arr[row][col] = cnt++;
		}
		inc *= -1;
	}
}
void printarr(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	printf("달팽이 배열의 길이 : ");
	scanf("%d", &n);
	makearr(n);//달팽이 배열 만들기
	printarr(n);
	return 0;
}

//5.11
//call by value 와 call by reference
#include <stdio.h>
void swap1(int, int);
void swap2(int*, int*);
int main()
{
	int a = 5, b = 8;
	printf("a=%d, b=%d\n", a, b);
	swap1(a, b);
	printf("a=%d, b=%d\n", a, b);
	swap2(&a, &b);
	printf("a=%d, b=%d\n",a, b);
	return 0;
}

void swap1(int a, int b)//값 자체를 바꾸지는 않아서 값은 안바뀜
{
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int* a, int* b)//값 자체를 바꿔서 값이 바뀜
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//버블정렬과 선택정렬의 차이
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printArr(int value[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d", value[i]);
	}
	printf("\n");
}
void selectionSort(int* value, int n)
{
	int i, j, min = 0, temp = 0;
	for (i = 0; i < n - 1; i++)//비교는 배열의 개수 -1번 일어난다
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (value[min] > value[j])
			{
				min = j;//비교해서 가장 작은 수가 있는 인덱스가 min에 저장됨
			}
		}
	temp = value[i];//swap이 일어남
	value[i] = value[min];
	value[min] = temp;
	}
}
int main()
{
	int value[] = { 4,7,9,11,3,7,6 };
	int n = sizeof(value) / sizeof(int);
	printArr(value, n);
	selectionSort(value, n);
	printArr(value, n);

	return 0;
}

//5.12
//(1)	
// 배열을 활용해 1부터 9까지의 수를 입력받아 입력받은 수만큼의 변의 길이를 가진 사각형
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char arr[9][9] = { 0, };
	int a = 0, i = 0, j = 0, n = 0, m = 0;
	printf("사각형 한 변의 길이를 입력하세요"); 
	scanf("%d", &a);
	if (a < 10 == a > 0)
	{
		for (i = 0; i < a; i++)
		{
			if (i == 0 || i == a - 1)
			{
				for (j = 0; j < a; j++)
				{
					arr[i][j] = '*';
				}
			}
			else
			{
				for (j = 0; j < a; j++)
				{
					if (j == 0 || j == a - 1)
					{
						arr[i][j] = '*';
					}
					else
					{
						arr[i][j] = ' ';
					}
				}
			}
		}
	}
	else
	{
		printf("1부터 9사이의 수가 아닙니다");
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//(2)
// 3학생의 4과목 점수를 입력받아 각 개인별로 평균이 80이상이면 p 그렇지않으면 f + 합격수
#define N 3
#define P 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0, j = 0,arr[3][4];
	int f = 0, cnt = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < P; j++)
		{
			printf("%d번째 학생의 %d번째 과목의 점수? ",i+1,j+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++)
	{
		f = 0;
		for (j = 0; j < P; j++)
		{
			f += arr[i][j];
		}
		if (f / 4 >= 80)
		{
			printf("pass");
			cnt += 1;
		}
		else
		{
			printf("fail");
		}
		printf("\n");
	}
	printf("합격 : %d", cnt);
	return 0;
}

//(5.13)
// 수를 입력하면 1부터 입력된 수까지의 수를 더한 수가 출력되는 프로그램(함수사용)
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f(int n)//포인터로 해도 되는지
{
	int a = 0;
	for (int i = 1; i <= n; i++)
	{
		a += i;
	}
		return a;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}

//(2)
// 입력할 수의 개수를 입력하고 수를 입력하면 
// 가장 큰 수가 몇번째 배열에 있는지 알려주는 프로그램(같은수는 앞번호)(함수사용)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, d[110];
int f(int n)
{
	int a = 0, b = d[0];
	for (int i = 0; i < n; i++)
	{
		if (d[i] > b)
		{
			b = d[i];
			a = i;
		}
	}
	return a + 1;
}
int main()
{
	printf("입력할 수의 개수를 입력하세요");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d번째 수를 입력하세요", i + 1);
		scanf("%d", &d[i]);
	}
	printf("%d", f(n));
	return 0;
}
//+개선
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, d[110];
int f(int n)
{
	int a = 0, b = d[0];
	for (int i = 0; i < n; i++)
	{
		if (d[i] > b)
		{
			b = d[i];
			a = i;
		}
	}
	return a + 1;
}
int main()
{
	printf("입력할 수의 개수를 입력하세요");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d번째 수를 입력하세요", i + 1);
		scanf("%d", &d[i]);
	}
	printf("%d", f(n));
	return 0;
}

//(3)
// 별직각삼각형의 변의 개수 입력, 출력하는 프로그램(함수사용)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void star(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			for (int j = 0; j < n; j++)
			{
				printf("*");
			}
			break;
		}
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
int main()
{
	int n;
	printf("입력할 별 삼각형의 변의 길이를 입력하세요");
	scanf("%d", &n);
	star(n);
	return 0;
}

//(4)
// n*m배열구조를 출력하는 프로그램
// 2 2 입력시 
 //(
 //13
 //24
 //)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[100][100];
	int a = 0, b = 0;
	int cnt = 1;
	int n = 0, m = 0;
	printf("세로 가로를 입력하세요");
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		if (i == a - 1)//가로일 때
		{
			for (int j = 0; j < b; j++)
			{
				n = a - 1;
				m = j;
				while (n>=0||m<=b-1)
				{
					arr[n][m] = cnt++;
					n--;// = cnt++;
					m++;
				}
			}
		}
		else
		{
			n = i;
			m = 0;
			for (int j=0;j<=i;j++)
			{
				arr[n][m] = cnt++;
				n--;
				m++;
			}
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//값이 점프되는 오류가 있음
// 예) 3 15 와 15 3  

//+개선
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[100][100] = {0, };
	int length, width;
	int len = 0, wid = 0;
	int cnt = 1;
	printf("가로세로를 입력하세요");
	scanf("%d %d", &width, &length);
	for (int i = 0; i < length; i++)
	{
		if (i == length - 1)//가로
		{
			for (int j = 0; j < width; j++)
			{
				len = length - 1;
				wid = j;
				while (1)
				{
					arr[len][wid] = cnt++;
					len--;
					wid++;
					if (len < 0 || wid > width - 1)
					{
						break;
					}
				}

			}
		}
		else//세로
		{
			len = i;
			wid = 0;
			while (1)
			{
				//len = length - j - 1;
				arr[len][wid] = cnt++;
				len--;
				wid++;
				if (len < 0 || wid > width - 1)
				{
					break;
				}
			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//+더개선(서준(김)이코드)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100][100] = { 0, };

void f(int y, int x) {
    int cnt = 1;
    int ind = 0;

    while (1) {
        for (int i = ind; i >= 0; i--) {
            // 첫번째 줄은 하나, 두번째 줄은 두개 ... 
            if (i >= y || ind - i >= x)
                // 반이상부터 값이 넘어가는 것을 방지
                continue;
            else
                arr[i][ind - i] = cnt++;
                // (0,0)
                // (1,0)
                // (0,1)
                // (2,0)
                // (1,1)
                // (0,2)
                // ...
        }
        ind++;

        if (ind == x + y - 1)
            // 수는 세로-가로에서 올라가는 형식
            // 즉 x + y - 1 개의 수 열이 있다
            // 예) 5 5 이면
            // (1)  [3]     [6]     [10]    [15]
            // (2)  [5]     [9]     [14]    [19]
            // (4)  [8]     [13]    [18]    [22]
            // (7)  [12]    [17]    [21]    [24]
            // (11) (16)    (20)    (23)    (25)
            // 
            // 괄호부분부터 수가 올라간다
            // 
            // 즉 ind = 이 괄호부분부터 올라가는 수의 개수
            // 
            break;
    }
}
int main() {
    int x, y;

    scanf("%d %d", &y, &x);
    f(y, x);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
}
// 코드 이해
 //
 //3 3을 한다고 하면 좌표는
 //(0,0)(0,1)(0,2)
 //(1.0)(1,1)(1,2)
 //(2,0)(2,1)(2,2)

for (int i = ind; i >= 0; i--) {
    if (i >= y || ind - i >= x)
        continue;
    else
        arr[i][ind - i] = cnt++;
}
ind++;

// 3 3입력시
// 
// i 와 ind -i 의 값
// (0,0)
// (1,0)
// (0,1)
// (2,0)
// (1,1)
// (0,2)
// (3,0) if문 i >= y에서 걸러짐
// (2,1)
// (1,2)
// (0,3) if문 ind - i >= y에서 걸러짐
// (4,0) if문 i >= y에서 걸러짐
// (3,1) if문 i >= y에서 걸러짐
// (2,2)
// (1,3) if문 ind - i >= y에서 걸러짐
// (0,4) if문 ind - i >= y에서 걸러짐

//코딩해보기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100][100] = { 0, };
void f(int x, int y)
{
    int cnt = 1;
    int ind = 0;
    while (1)
    {
        for (int i = ind; i >= 0; i--)
        {
            if (i >= y || ind -i >= x)
            {
                continue;
            }
            else
            {
                arr[i][ind -i] = cnt++;
            }
        }
        ind++;
        if (ind >= x + y - 1)
        {
            break;
        }
    }
}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    f(x, y);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

