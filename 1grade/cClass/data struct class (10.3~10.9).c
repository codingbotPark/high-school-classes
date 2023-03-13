//10.3~10.9
//�� ����
//���� (https://hongku.tistory.com/149)
// 
// �� ���� ����
// 
// �迭�� ������ �Ǵ� ��(ù ��° ��)�� ���Ѵ�
// �� ���� �Ǻ�(pivot) �̶��Ѵ�
// 
// �� �Ǻ� ���� ù��° ���� i, ��������° ���� j �� �����͸� ���Ѵ�
// i�� ó������ �Ǻ����� ū ��,
// j�� ���������� �Ǻ����� ���� ���� ã�´�
// 
// ���� ã���� �� ���� �ٲ۴�(i�� j�� �������� ������)
// 
// i�� j�� �������� �ٽ�
// i�� j�� ���� �Ǻ����� ū ��, �Ǻ����� ���� ���� ã����
// i�� j�� �ٲٴ� ���� �ƴ�
// �Ǻ��� j�� �ٲ۴�
// 
// �׷��� �Ǹ� �Ǻ��� ��ġ�� ��������
// ������ �Ǻ����� ���� ����,
// �������� �Ǻ����� ū ������ ��ġ�ϰ� �ȴ�
// 
// �� �� �Ǻ��� �������� �������� �� ������ �Ǵٽ�
// ���� �Ǻ��� �����ϰ� 
// �� ������ �����Ѵ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int data[10];

void quick(int* data, int start, int end)
{
	if (start >= end)
	{//�迭�� ���Ұ� �ϳ��� ���
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp = 0;

	while (i <= j)
	{
		//�����Ͱ� �������� ������ �ݺ�
		while (i <= end && data[i] <= data[pivot])
		{
			i++;
		}
		while (j > start && data[j] >= data[pivot])
		{
			j--;
		}

		if (i > j)
		{
			//������ ��
			//�Ǻ��� j�� �ٲ۴�
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			//�������� ���� ��
			//i�� j�� �ٲ۴�
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//�Ǻ��� �������� ���ʰ� ��������
	//�Ȱ��� �� ���ķ� ����
	//�迭�� ������, ������ ����
	quick(data, start, j - 1);
	quick(data, j + 1, end);
}

int main()
{
	printf("10���� ���� �Է��ϼ���");

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}

	quick(data, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", data[i]);
	}
	return 0;
}



//���������
//������������ �� ���� ���̰� ū ������ ����
//(�׷����� ��)
// 
//�ذ� ���ų� �ϳ��� ���� ������ ǥ���Ѵ�
//
//���ǰ���
//-b +- ��Ʈ b^2 - 4ac
//�ѤѤѤ�
//2a
//
//��
//
//�Ǻ���
//b^2 - 4ac
//
//�� Ȱ��
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int arr[10][3];//������������ ����
int num;//������������ ����
int resultarr[10];//������������ �� ���� �Ÿ��� ����,
//������ 0, �ذ����ٸ� -1
int i;//�Ǻ�, �ظ� ���ϴ� �������� i�� �ѱ�� ���� ���������� ����
int j;
int tmp;//������ �� ���
int gap;//�����Ŀ� ���
int temp1, temp2, temp3;

void input();//������������ �Է¹޴� �Լ�
void determine();//�Ǻ������� ������������ ���� ����(x��� ��� ���� ����)�� ���Ͽ�
//result(�� ���� �ظ� ����)�� �����ϰų�
//�ذ� �ϳ�, ���� ���� �ѱ��
void result();//���� �������� ������������ �ظ� ���Ͽ� �� �ػ����� �Ÿ��� ���ϴ� �Լ�
void sort();//�Ÿ��� ���� ����
void printresult();//����� ���


int main()
{
	printf("������������ ������ �Է��ϼ���");
	scanf("%d", &num);
	
	input();//�� �Է� 

	determine();//������������ ���� ���� �Ǻ�,
	//�Ǻ��� ���� �з�

	sort();

	printresult();

	return 0;
}


void input()
{
	for (i = 0; i < num; i++)
	{
		printf("\n%d��° ����������\n",i+1);
		printf("x^2�� ��� : ");
		scanf("%d", &arr[i][0]);
		printf("x�� ��� : ");
		scanf("%d", &arr[i][1]);
		printf("��� : ");
		scanf("%d", &arr[i][2]);
	}
}

void determine()
{
	for (i = 0; i < num; i++)
	{
		int temp = pow(arr[i][1],2) - (4 * arr[i][0] * arr[i][2]);//�Ǻ����� ����� ���
		if (temp > 0)//�ذ� �� ���϶�
		{
			result();
		}
		else if (temp == 0)//�ذ� �ߺ��� ��
		{
			resultarr[i] = 0;//�ߺ��� �� 0�� ����
		}
		else//�ذ� ���� ��
		{
			resultarr[i] = -1;//���� �� -1�� ����
		}
	}
}


void result()//������������ �ظ� ���Ͽ� �� �ػ����� �Ÿ��� ���ϴ� �Լ�
{
	//-b +- ��Ʈ b^2 - 4ac
	//�ѤѤѤ�
	//2a
	int a = -((-arr[i][1] + (sqrt((pow(arr[i][1], 2)) - (4 * arr[i][0] * arr[i][2])))) / (2 * arr[i][0]));
	int b = -((-arr[i][1] - (sqrt((pow(arr[i][1], 2)) - (4 * arr[i][0] * arr[i][2])))) / (2 * arr[i][0]));
	resultarr[i] = b - a;//���̸� resultearr�� �ִ´�
}

void sort()//������ ũ�⸦ ������������ ���� 
{
	for (gap = num / 2; gap > 0; gap /= 2)
	{//gap �� 1 �̻��� �� �۵���
		// = gap > 0
		for (i = gap; i < num; i++)
		{//gap��ŭ������ �ε������� ���ϱ� ������
			//i = gap���� ���������ν� gap�� �ٲ����� ��ŭ �ݺ��� �� �ִ�
			tmp = resultarr[i];
			temp1 = arr[i][0];
			temp2 = arr[i][1];
			temp3 = arr[i][2];
			for (j = i; j >= gap && resultarr[j - gap] > tmp; j -= gap)
			{
				resultarr[j] = resultarr[j - gap];
				//for�� �ȿ��� resultarr[j - gap] > tmp(resultarr[i]) �� ��
				arr[j][0] = arr[j - gap][0];
				arr[j][1] = arr[j - gap][1];
				arr[j][2] = arr[j - gap][2];
			}
			resultarr[j] = tmp;
			arr[j][0] = temp1;
			arr[j][1] = temp2;
			arr[j][2] = temp3;
			//for���� Ż���ص� ������ ���� ������ �� �ִ�
			//resultarr[j] �� resultarr[i]�� ���� ������ �ٲ��� �ʴ´ٸ� �״���̴�
		}
	}
}
//���� ������������ ������ �����Ͽ� print�� ���� ���� �Ÿ��� ���� ������ ��µǵ��� �Ѵ�

void printresult()//����� ����ϴ� �Լ�
{
	printf("\n�׷����� x��� ��� ���� ���ٸ� -1,\n�� ������ ��´ٸ� 0\n");
	for (i = 0; i < num; i++)
	{
		printf(" %d\t", resultarr[i]);
		printf("%dx^2 + %dx + %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}


//���������
//����ڿ� abc������ ����
	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[10][20];//���� �ܾ �Է¹��� �迭
int temp_arr[20];//���� �ܾ ������ �� ������ �迭(�����ؾ��ؼ� 20����Ʈ�̴�)
int num;//�ܾ��� ����
int i, j;//�ݺ������� ���

int main()
{
	printf("�ܾ��� ������ �Է��ϼ���");
	scanf("%d", &num);

	//����ܾ �Է¹���
	for (i = 0; i < num; i++)
	{
		scanf("%s", arr[i]);
	}

	//�������� ���
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{//strcmp�� �� ���ڿ��� ������ �ٸ����� �� �� �ִ�
				//strcmp�ȿ� �ִ� �� ���ڿ��� ���ٸ� 0�� ��ȯ,
				//strcmp�ȿ� �ִ� �� ���ڿ��� ���� ���ڿ��� ũ�ٸ� ���(1) �� ��ȯ,
				//strcmp�ȿ� �ִ� �� ���ڿ��� ������ ���ڿ��� ũ�ٸ� ����(-1) �� ��ȯ
				//�� strcmp(arr[j], arr[j + 1] > 0) �� abc ������ �����Ѵ�
				
				strcpy_s(temp_arr, 20, arr[j]);
				strcpy_s(arr[j], 20, arr[j + 1]);
				strcpy_s(arr[j + 1], 20, temp_arr);
				//strcpy�� ���ڿ��� �����ϴ� �Լ��̴� �׳� �����ϴ� �����̴�
			}
		}
	}

	printf("\n");
	//����ܾ���� ������ ���
	for (i = 0; i < num; i++)
	{
		printf("%s\n", arr[i]);
	}
}