// atoi = ���ڿ��� ������
// itoa = �Է¹��� ������ ������ ������� ���ڿ��� �ִ´�
// visual -> Ȯ�� ���� -> github extension��ġ -> vs�� git�� �����
//
// git �̶� ��� ����̴� 
// (��������) �������� ���ΰ� ������ �κ��� �����ϱ� ����
//
// git hub�� ��� ����������̴�
//
// ���������(�������� ������ ����)�� �������丮�� �Ѵ�
//
//
// Ŀ�԰� Ǫ�ÿ� Ǯ
//
// Ŀ���� ��������� ǥ���ϴ°� Ŀ��
//
// Ǫ�ô� Ŀ��Ŀ���س����� Ǫ���ؾ��� github�� �ö�
//
// Ǯ�� Ǫ���� ���� ���� �״�� ������ �ٽ� �۾��� �����ϰ� �ϴ� ��
//
// �� Ǫ�ô� ��������ҿ� �ø��� ��
// Ǯ�� ����ҿ� �ö��ִ� ���� �������� ��
//
// ��ũ�� Ǯ ���ɽ�Ʈ
//
// ��ũ�� �ٸ� ����� �Ѱ� �������� ��
//
// Ǯ ���ɽ�Ʈ�� ���� ���� �ߴµ� ������ ����� ������ ����ϼ��� 
// ��´���

//5.18
//�ڷ����� ������ �ٲٱ�(atoi)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char str[256];
    printf("Enter a number : ");
    gets(str, 256);
    i = atoi(str);//���ڿ��� ���ڷ� ��ȯ
    printf("�Էµ� ������ : %d, 2���� �� : %d\n", i, i * 2);
    return 0;
}

//�ڷ����� ������ �ٲٱ�(_itoa)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i;
    char arr[50];
    printf("Enter a number : ");
    scanf("%d", &i);
    _itoa(i, arr, 10);
    printf("decimal : %s\n", arr);
    _itoa(i, arr, 16);//16����
    printf("hexadecimal : %s\n", arr);
    _itoa(i, arr, 2);//2����
    printf("binary : %s\n", arr);
    return 0;
}

//�Ҽ��� ã�ƶ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int v;
	int cnt1 = 0, cnt2 = 0;
	while (1)
	{
		printf("1���� �Ҽ��� ����� ���� �Է��ϼ���(1000������ �ڿ���)");
		scanf("%d", &v);
		if (v > 1 && v <= 1000)
		{
			for (int i = 2; i <= v; i++)
			{
				for (int j = 2; j < i;j++)
				{
					if (i % j == 0)
					{
						cnt1++;
						break;
					}
				}
				if (cnt1 != 0)
				{
					cnt1 = 0;
					continue;
				}
				printf("%d ", i);
				cnt2++;
				if (cnt2 > 9)
				{
					cnt2 = 0;
					printf("\n");
				}
			}
			break;
		}
		printf("\n");
	}
	return 0;
}
//+������ �ڵ�
#include <stdio.h>
int isPrime(int n)
{
	//for (int i = 2; i < n; i++)
	// ������ �� �ڵ�� ��ȿ�����̴�.
	// (���� ������ �� ��ġ�� ������)
	// �����ϸ�
	for (int i=2 ; i*i<=n;i++)
	{
		if (!(n % i)) return 0;
		// if (n % i == 0) �� if (!(n % i)) �� ����
		// �������� 0�̰� �Ǹ� �Ҽ��� �ƴϴ�
	}
	return 1;//�´ٸ� 1�� ������ main���� if���� ����ǰ� �Ѵ�
}

int main()
{
	for (int i = 2; i < 100; i++)
	{
		if (isPrime(i))
		{
			printf("%4d", i);
		}
	}
	return 0;
}

//Űũ�� ���� ����ǥ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[7] = { 0, };
	int h = 0,j=1;
	while (1)
	{
		printf("%d��° �л��� Ű�� �Է��ϼ���", j);
		scanf("%d", &h);
		if (h == -99)
		{
			break;
		}
		else
		{
			arr[(h - 150) / 5]++;
		}
		j++;
	}
	for (int i = 0; i < 7; i++)
	{
		printf("%d - %d = %d\n", 150 + (5 * i), 149 + (5 * (i + 1)), arr[i]);
	}
}