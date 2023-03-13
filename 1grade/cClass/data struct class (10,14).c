//10.14
//������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

//��ũ�δ� �ٷ� ���� ó���ϴ� ����? �̱� ������ �Լ��� ����ϴ� �� ���� ������
//��ȣ�� �ϳ��ϳ� ��������ν� ���������� �����
//��) 5+3 �� ���� ���� ���� �� * ������ ���� ������ �޶����� ����
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
	while (i <= j)//i�� j������ �� ����
	{
		while (arr[i] <= arr[pivot])//i��ġ ���� pivot ��ġ�� �� ����
			i++;
		while (arr[j] >= arr[pivot] && j > left)
			j--;
		if (i > j)//i�� j�� ũ�ν� �Ǿ��� ���
			SWAP(arr[j], arr[pivot], temp);
		else//i�� j���� ���� ���� �Ǻ��� ��ü���� ����
			SWAP(arr[i], arr[j], temp);
	}
	quicksort(arr, left, j - 1);//�Ǻ����� �������� ���� �κ� ȣ��
	quicksort(arr, j + 1, right);//�Ǻ� ���� ������ ȣ��
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
