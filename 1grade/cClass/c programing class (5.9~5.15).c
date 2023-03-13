// �����̹迭 
// ���״�� �簢���� �׸��� ���� ä��� �迭
// ���ο��� ���η� �� �� �̵��ϴ� ������ �������� ���� Ȱ��
// 
// 
// �������� 
// �������� �־��� ���� �����ϴ� ��
// swap�� ����� �̿��ϴ� �װ� ���� ��ȯ�� ���
// n���� ���� ������ �񱳴� n-1���� ���� Ȱ�� 
// 
// call by value = ���� ���� ȣ��
// �Լ� ȣ��� ���޵Ǵ� ������ ���� �����Ͽ� �Լ��� ���ڷ� �����Ѵ�.
// ����� ���ڴ� �Լ� �ȿ��� ���������� ���Ǵ� local value�� Ư���� ������.
// ���� �Լ� �ȿ��� ������ ���� ����Ǿ, �ܺ��� ������ ���� ������� �ʴ´�.
// 
// call by reference = ������ ���� ȣ��
// �Լ� ȣ��� ���ڷ� ���޵Ǵ� ������ ���۷����� �����Ѵ�. (�ش� ������ ����Ų��.)
// ���� �Լ� �ȿ��� ������ ���� ����Ǹ�, �ƱԸ�Ʈ�� ���޵� ��ü�� ���� �Բ� ����ȴ�.
// 
// 
// �������İ� ���������� ����
// ���������� �迭�� �� ��ġ�鼭 �ϳ��� ���ؼ� ��ĭ�� �̵� ��Ű����
// ���������� ������ �ڸ���� ���� ���� ���� ���� ó����...�Ѵ�
// => �������İ� �������İ� �޸� �迭�� �ε����� �ٲٰ� �������� �� �ٲٴ� ���� �����Ű��
// ������ �� �ð��� ª�� �ɸ���

//5.10
//�����̹迭
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIDE 100
int arr[SIDE][SIDE];
void makearr(int n)
{
	int cnt = 1;//1,2,3,4..
	int row = 0, col = -1;
	int inc = 1;//�ε��� ���� ����
	while (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			col += inc;//���� 0���� ���� 1, 2, 3 ... n ��ŭ
			arr[row][col] = cnt++;//�迭�� ���θ� cnt++�� �̿��� 1,2,3 ... n ��ŭ ���� �ִ´�
		}
		n--;//���η� �Է��� �ٸ�ŭ �̵� / -�� ���ָ鼭 5ĭ �� ��ġ�� 1ĭ�� �ѱ�
		// n--�� �� ���� for ���̿� �����ν� ���μ���
		if (n == 0) break;//n�� 0 �� �� ������
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
	printf("������ �迭�� ���� : ");
	scanf("%d", &n);
	makearr(n);//������ �迭 �����
	printarr(n);
	return 0;
}


//��������
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
		for (int j = 0; j < len - i - 1; j++)//�� ���� ���� ��ġ�� �迭�� ���� �ʱ� ������
			//len -i-1�� �ϸ� 0�� �� �� ���� �迭�� ����
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

//�����̹迭����
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
	printf("������ �迭�� ���� : ");
	scanf("%d", &n);
	makearr(n);//������ �迭 �����
	printarr(n);
	return 0;
}

//5.11
//call by value �� call by reference
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

void swap1(int a, int b)//�� ��ü�� �ٲ����� �ʾƼ� ���� �ȹٲ�
{
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int* a, int* b)//�� ��ü�� �ٲ㼭 ���� �ٲ�
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//�������İ� ���������� ����
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
	for (i = 0; i < n - 1; i++)//�񱳴� �迭�� ���� -1�� �Ͼ��
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (value[min] > value[j])
			{
				min = j;//���ؼ� ���� ���� ���� �ִ� �ε����� min�� �����
			}
		}
	temp = value[i];//swap�� �Ͼ
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
// �迭�� Ȱ���� 1���� 9������ ���� �Է¹޾� �Է¹��� ����ŭ�� ���� ���̸� ���� �簢��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char arr[9][9] = { 0, };
	int a = 0, i = 0, j = 0, n = 0, m = 0;
	printf("�簢�� �� ���� ���̸� �Է��ϼ���"); 
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
		printf("1���� 9������ ���� �ƴմϴ�");
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
// 3�л��� 4���� ������ �Է¹޾� �� ���κ��� ����� 80�̻��̸� p �׷��������� f + �հݼ�
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
			printf("%d��° �л��� %d��° ������ ����? ",i+1,j+1);
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
	printf("�հ� : %d", cnt);
	return 0;
}

//(5.13)
// ���� �Է��ϸ� 1���� �Էµ� �������� ���� ���� ���� ��µǴ� ���α׷�(�Լ����)
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f(int n)//�����ͷ� �ص� �Ǵ���
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
// �Է��� ���� ������ �Է��ϰ� ���� �Է��ϸ� 
// ���� ū ���� ���° �迭�� �ִ��� �˷��ִ� ���α׷�(�������� �չ�ȣ)(�Լ����)
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
	printf("�Է��� ���� ������ �Է��ϼ���");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d��° ���� �Է��ϼ���", i + 1);
		scanf("%d", &d[i]);
	}
	printf("%d", f(n));
	return 0;
}
//+����
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
	printf("�Է��� ���� ������ �Է��ϼ���");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d��° ���� �Է��ϼ���", i + 1);
		scanf("%d", &d[i]);
	}
	printf("%d", f(n));
	return 0;
}

//(3)
// �������ﰢ���� ���� ���� �Է�, ����ϴ� ���α׷�(�Լ����)
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
	printf("�Է��� �� �ﰢ���� ���� ���̸� �Է��ϼ���");
	scanf("%d", &n);
	star(n);
	return 0;
}

//(4)
// n*m�迭������ ����ϴ� ���α׷�
// 2 2 �Է½� 
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
	printf("���� ���θ� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		if (i == a - 1)//������ ��
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

//���� �����Ǵ� ������ ����
// ��) 3 15 �� 15 3  

//+����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[100][100] = {0, };
	int length, width;
	int len = 0, wid = 0;
	int cnt = 1;
	printf("���μ��θ� �Է��ϼ���");
	scanf("%d %d", &width, &length);
	for (int i = 0; i < length; i++)
	{
		if (i == length - 1)//����
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
		else//����
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
//+������(����(��)���ڵ�)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100][100] = { 0, };

void f(int y, int x) {
    int cnt = 1;
    int ind = 0;

    while (1) {
        for (int i = ind; i >= 0; i--) {
            // ù��° ���� �ϳ�, �ι�° ���� �ΰ� ... 
            if (i >= y || ind - i >= x)
                // ���̻���� ���� �Ѿ�� ���� ����
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
            // ���� ����-���ο��� �ö󰡴� ����
            // �� x + y - 1 ���� �� ���� �ִ�
            // ��) 5 5 �̸�
            // (1)  [3]     [6]     [10]    [15]
            // (2)  [5]     [9]     [14]    [19]
            // (4)  [8]     [13]    [18]    [22]
            // (7)  [12]    [17]    [21]    [24]
            // (11) (16)    (20)    (23)    (25)
            // 
            // ��ȣ�κк��� ���� �ö󰣴�
            // 
            // �� ind = �� ��ȣ�κк��� �ö󰡴� ���� ����
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
// �ڵ� ����
 //
 //3 3�� �Ѵٰ� �ϸ� ��ǥ��
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

// 3 3�Է½�
// 
// i �� ind -i �� ��
// (0,0)
// (1,0)
// (0,1)
// (2,0)
// (1,1)
// (0,2)
// (3,0) if�� i >= y���� �ɷ���
// (2,1)
// (1,2)
// (0,3) if�� ind - i >= y���� �ɷ���
// (4,0) if�� i >= y���� �ɷ���
// (3,1) if�� i >= y���� �ɷ���
// (2,2)
// (1,3) if�� ind - i >= y���� �ɷ���
// (0,4) if�� ind - i >= y���� �ɷ���

//�ڵ��غ���
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

