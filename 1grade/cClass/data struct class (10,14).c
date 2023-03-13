//10.14
//퀵정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

//메크로는 바로 일을 처리하는 느낌? 이기 때문에 함수를 사용하는 것 보다 빠르다
//괄호를 하나하나 사용함으로써 안정적으로 만든다
//예) 5+3 과 같은 수가 들어올 때 * 때문에 연산 순서가 달라짐을 방지
;
int arr[10] = { 6,4,3,6,7,3,1,2,3,9 };
int n = 10;

void quicksort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = left;
	int i = left + 1;
	int j = right;
	int temp;
	while (i <= j)//i가 j이항일 때 까지
	{
		while (arr[i] <= arr[pivot])//i위치 값이 pivot 위치의 값 이하
			i++;
		while (arr[j] >= arr[pivot] && j > left)
			j--;
		if (i > j)//i와 j가 크로스 되었을 경우
			SWAP(arr[j], arr[pivot], temp);
		else//i가 j보다 작은 경우는 피봇과 교체하지 않음
			SWAP(arr[i], arr[j], temp);
	}
	quicksort(arr, left, j - 1);//피봇으로 나누어진 왼쪽 부분 호출
	quicksort(arr, j + 1, right);//피봇 기준 오른쪽 호출
}

int main()
{
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%3d", arr[i]);
	}
	return 0;
}
