 //�����Ͷ� �����ΰ�?
 //�ּҸ� �����ϴ� ����
 //
 //�����͹迭�� �迭�������� ������
 //google
 //������ �迭�� �ּҰ����� �����ϴ� �迭 �̴�. 
 //�迭 �����ʹ� �迭�� �����ּҰ��� ������ �� �ִ� ������ �̴�.
 //naver
 //1. �����ʹ� �����ε� ���� �迭�� ����̴�.
 //pi�� ������ �޸𸮸� �����ϰ� �ְ� �������� �ٸ� ����� ����ų �� ������ 
 //ar�� ������ �� �� ��ġ�� �̹� �����ǹǷ� �ٸ� ����� ����ų �� ����.
 //ar�δ� ������ �迭�� ���� ������ ���� �� ���� ���̴�.

 //2. pi�� ����Ű�� �迭�� ũŰ�� �������� ������ �� ������ 
 //ar�� ����Ű�� �迭�� ũ��� ������ �� �������� �����ȴ�.
 //������ ������ �迭�� �ʿ��ϸ� int ar[n]; �������� �迭�� �����ϴ� ���� ���ϰ� 
 //���������� �迭�� �ʿ��ϸ� int* ���� ������ ������ ������  ��  malloc���� �Ҵ��ؼ�
 // ����ؾ� �Ѵ�.
 //�����ͷ� �Ҵ��� �迭�� ���� �߿��� realloc���� ũ�⸦ ���Ҵ��Ͽ� ������ �� �ִ�.

 //3. �迭�� �� ��ü�� ũ�� ������ �Լ��� �μ��� ������ �� ������ 
 //�����ʹ� ���ü�� �����̵簣�� 4����Ʈ�� ũ��ۿ� �������� �����Ƿ� 
 //�Լ��� ������ �� �ִ�.
 //�׷��� �迭�� �Լ��� ������ ���� �ݵ�� �����͸� ����ؾ� �Ѵ�.

 //4.�迭�� ��Ҹ� �д� �Ͱ� �����ͷ� ���ü�� �д� ������ �ӵ� ���̰� �ִ�.
 //�迭�� ÷�� ������ �Ź� �迭���ο������� ��������� 
 //�����ʹ� ���ü�� ���� �̵��ؼ� �ٷ� �����Ƿ� �׼��� �ӵ��� ������.
 // * pi�� pi�� ����Ű�� ���� �ٷ� ������ 
 //ar[n]�� * (ar + n)���� �ϴ� ������ ���� �� �о�� �ϹǷ� ���� ������.
 //�����Ͱ� �迭���� �ι� ���� ������.
 //
 //
 //�迭�� Ȱ���Ͽ� ����/ ��� ���� ���� �� �ִ�
 //
 //���ؼ� ���� �� ���++ �� �ؼ� ����� ���� �� �ִ�
 //���� ����ǥ�� ���� �� 10���� ����� �迭�� +�� �ϸ鼭 ������ �� �� �ִ�
 //
//���� ����ǥ �����
//#define NUM 20
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
//	int i, range, histo[11] = { 0, };
//	for (i = 0; i < NUM; i++)
//	{
//		histo[a[i] / 10]++;//10���� ������ ���� �ڸ��� ���µ� �� 10�� �ڸ�
//							//������ ���� �迭�� +�ؼ� ������ ����
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		printf("%3d : %3d\n", i * 10, histo[i]);
//	}
//	return 0;
//}

//5.3
//�����Ͷ� �����ΰ� 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 1,2,3 };
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	int* ptr;
	ptr = arr;
	printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
	printf("%d %d %d\n", *ptr, *(ptr+1), *(ptr+2));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[3] = { 1,2,3 };
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	int* a;
	a = arr;
	printf("%d %d %d\n", a[0], a[1], a[2]);
	printf("%p %p %p\n", a[0], a[1], a[2]);
	printf("%p %p %p\n", &a[0], &a[1], &a[2]);
	printf("%d %d %d\n", *a, *(a + 1), *(a + 2));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int* ptr1 = 1000;
	int* ptr2 = 1000;
	int* ptr3 = 1000;
	printf("%d \n", ptr1++);
	printf("%d %d\n", ptr2++, ptr3++);
	printf("%d %d %d\n", ptr1 ,ptr2, ptr3);//4����
	printf("%p %p %p\n", ptr1 ,ptr2, ptr3);//�ּ����
 //�ּҰ� ��� ���� �ʴ� ������ �ּ� 1000�̸� ������ �ü���� �ֱ� ������
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str1[10] = "abcd";
	char* str2 = "ABCD";
	printf("%s\n", str1);
	printf("%s\n", str2);
	str1[1] = 'x';
	//str2[2] = 'x';	//�̷��� �����ϸ� ��Ÿ�� ���� �߻�
	printf("%s\n", str1);
	//printf("%s\n", str2);
	return 0;
}

//�����͹迭�� �迭�������� ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 1, b = 2, c = 3;
	int Arr[3] = { 10,20,30 };
	int* pArr[3] = { &a,&b,&c };
	printf("%d \n", *pArr[0]);//*(&a) == a
	printf("%d \n", *pArr[1]);
	printf("%d \n", *pArr[2]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[3][10] = { "Kim","Hong","Lee" };
	char* pStr[3] = { "Kim","Hong","Lee" };
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", *(pStr));
	printf("%s\n", *(pStr+1));
	printf("%s\n", *(pStr+2));
	printf("%s\n", *pStr);
	printf("%s\n", *pStr+1);
	printf("%s\n", *pStr+2);
	return 0;
}

//5.4
//���� ����ǥ �����
#define NUM 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
	int i, range, histo[11] = { 0, };
	for (i = 0; i < NUM; i++)
	{
		histo[a[i] / 10]++;//10���� ������ ���� �ڸ��� ���µ� �� 10�� �ڸ�
							//������ ���� �迭�� +�ؼ� ������ ����
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%3d : %3d\n", i * 10, histo[i]);
	}
	return 0;
}
//+Ȱ���ؼ� �� ���
#define NUM 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
	int i, j, range, histo[11] = { 0, };
	for (i = 0; i < NUM; i++)
	{
		histo[a[i] / 10]++;//10���� ������ ���� �ڸ��� ���µ� �� 10�� �ڸ�
							//������ ���� �迭�� +�ؼ� ������ ����
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%3d : ", i * 10);
		for (j = 0; j < histo[i]; j++)
		{
			printf("��");
		}
		printf("\n");
	}
	return 0;
}

//��� ���ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int scores[10] = { 95,64,78,94,65,71,72,59,45,78 };
	int rank[10] = { 0, };
	int i, j;
	for (i = 0; i < 10; i++)
	{
		rank[i] = 1;
		for (j = 0; j < 10; j++)
		{
			if (scores[i] < scores[j])
			{
				rank[i]++;
			}
		}
	}
	printf("�л� ���\n");
	for (i = 0; i < 10; i++)
	{
		printf("�й� : %3d, ��� : %3d\n", i + 1, rank[i]);
	}
	return 0;
}
//+����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int scores[10] = { 95,64,78,94,65,71,72,59,45,78 };
	int rank[102] = { 0, };//0�� 101���� �÷��� �ؼ� 102
	int i, j;
	for (i = 0; i < 10; i++)
	{
		rank[scores[i]]++;//���� + 1
		// ������ �����ٸ� rank�迭�� 95,64,78,94,65,71,72,59,45,78
		// �� 1�� ���� �̷��� 1�� +�Ѵٸ� ���� ���� �־ ���� ����� + 2 �ȴ�
	}
	rank[101] = 1;//�� �κ��� �����ϰ� �� for���� i = 101�� �ϸ� ����� �����Ⱚ�� ����
	// �� ������ for���� rank[i+1]�� �־ �ʱ�ȭ�� ����� ������ ���� �ȵ���
	// �׷��ٸ� rank[101]�� �����ϰ� �� for���� i = 99�� �Ѵٸ� ����� 0���� ����
	// �� ������rank[i] = rank[i+1]�̱� ������ 1�� ������ ����� 1�� �����Ѵ�

	for (i = 100; i >= 0; i--)
	{
		rank[i] = rank[i] + rank[i + 1];//�� for���� ���� �ִ� �κп� 1�� �־��µ�
		//�� 1�� ���� �κе��� ��ĥ �� ���� +1 �� ���ϸ鼭 ��ģ��
		//��) 95 �� 90 �� �ִٸ�
		// 95 94 93 92 91 90
		//  1  1  1  1  1  2 ...  
	}
	printf("�й� ���� ���\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d %5d %3d\n", i + 1, scores[i], rank[scores[i] + 1]);
		//rank�� ������ 1 1 2 2 2 3 .... ������
		//rank[scores[i]+1]�� ���� ������ָ鼭
		//�ʿ� �� ���鸸 ��� ����Ѵ�
	}
	return 0;
}
//+�Է¹ޱ�, �������� ����� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, arr[10];
	int rank[102] = { 0, };
	for (i = 0; i < 10; i++)
	{
		printf("%d ��° �迭�� ���� ��(100������ ��)�� �Է��ϼ���", i);
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 10; i++)
	{
		rank[arr[i]+1]++;
	}
	rank[0] = 1;
	for (i = 1; i <= 101; i++)
	{
		rank[i] = rank[i] + rank[i - 1];
	}
	printf("�й� ���� ���\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d %5d %3d\n", i + 1, arr[i], rank[arr[i]]);
	}
	return 0;
}

//5.6
//(1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[11] = { 0, };
	int i = 0;
	while (1)
	{
		printf("1���� 10������ ���� �Է��ϼ���(�ƴҽ� ����)");
		scanf("%d", &i);
		if (i <= 10 && i > 0)
		{
			arr[i]++;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i <= 10; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d : %d��\n", i, arr[i]);
		}
	}
	return 0;
}

//(2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int com[3], pc[3], math[3], to[3], comto = 0, pcto = 0, mathto = 0, toto = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("%d�� ���� : ", i + 1);
        scanf("%d %d %d", &com[i], &pc[i], &math[i]);
        printf("\n");
        to[i] = com[i] + pc[i] + math[i];
        comto += com[i];
        pcto += pc[i];
        mathto += math[i];
        toto += to[i];
    }
    printf("   ����   ��c    ����    ����\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ��   %d   %d   %d   %d\n", i + 1, com[i], pc[i], math[i], to[i]);
    }
    printf("�հ�   %d   %d   %d   %d", comto, pcto, mathto, toto);
    return 0;
} 
//+����(�� �³�)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[16] = { 0, };
	int i = 0, j = 0, n = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				printf("%d�� �л��� �������� : ", i + 1);
			}
			else if (j == 1)
			{
				printf("%d�� �л��� ��c���� : ", i + 1);
			}
			else if (j == 2)
			{
				printf("%d�� �л��� �������� : ", i + 1);
			}
			else
			{
				for (n = 0; n < 3; n++)
				{
					arr[j + (i * 4)] += arr[(i * 4) + n];
				}
				continue;
			}
			scanf("%d", &arr[j + (i * 4)]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr[12 + i] += arr[(j * 4)+i];
		}
		arr[15] += arr[12 + i];
	}
	printf("��ȣ	����	��c    ����    ����");
	for (i = 0; i < 16; i++)
	{
		if (i%4==0)
		{
			printf("\n");
			printf("%d��    ", (i / 4) + 1);
		}
		printf("%d     ", arr[i]);
	}
	return 0;
}
