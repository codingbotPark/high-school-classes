// 9.27
// 순혈과 조합
// 쉽게말하면
// 순서를 생각하면 순열
// 순서를 생각하지 않으면 조합
// 
// 서로다른 원소를 가진 집합에서 대상들을 선택하여 순서있게 배열하는 것
// 각각의 조들의 모임


//9.27
//쉘정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void shellSort(int arr[], int n) {
	int i, j, tmp, gap;
	for (gap = n / 2; gap > 0; gap /= 2) 
	{
		for (i = gap; i < n; i++)
		{
			tmp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = tmp;
		}
	}
}

int main() {
	int arr[] = { 1,9,15,12,3,7,5,8,11,2 };
	int n = sizeof(arr) / sizeof(int);
	printf("%d개 데이터 정렬 \n", n);
	shellSort(arr, n);
	for (int i = 0; i < n; i++)
		printf("%4d", arr[i]);
	printf("\n");
	return 0;
}

//파스칼의 삼각형
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

long combi(int, int);

int main()
{
	int n, r, t;
	for (n = 0; n <= 10; n++) {
		for (t = 0; t < (N - n) * 3; t++) {
			printf(" ");
		}
		for (r = 0; r <= n; r++) {
			printf("%3ld   ", combi(n, r));
		}
		printf("\n");
	}

	return 0;
}

long combi(int n, int r) {
	int i;
	long p = 1;
	for (i = 1; i <= r; i++) {
		p = p * (n - i + 1) / i;
	}
	return p;
}

//9.30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num[2];
	int big = 0;

	scanf("%d", &num[0]);
	scanf("%d", &num[1]);

	if (num[0] > num[1])
		big = 1;
	else
		big = 2;

	printf("%d%d", num[big - 1], num[big == 1 ? 1 : 0]);


	return 0;
}


//삽입정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int arr[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}

int main()
{
	int list[] = { 3,4,1,8,9,9,5,65,24,64,4,43};
	int n = sizeof(list) / sizeof(int);
	insertionSort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", list[i]);
	}
	return 0;
}
