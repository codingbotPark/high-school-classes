// #include <stdlib.h> �� Ȱ����
// rand �Լ��� ����� �� �ִ�
// rand() % n = 0���� n-1������ ���� ������ ���� ����
// 
// #include <time.h> �� Ȱ����
// srand((unsigned int)time(NULL));
// ���� ������ ���� ��� �ٲ� �� �ִ�
// 
// stack�̶� LIFO (last In First Out)
// ������� a b c d�� �־����� 
// ������ d c b a�� �����Ѵ�
// �� �� ���Ǵ� ���� top �Լ��� ����Ѵ�
// 
// Queue�� FIFO (First In First Out)
// stack �ݴ��� ���� �־��� �� ���� �� ����
// Queue(�ڷᱸ��) �� ����Ѵ�
// 
// 
//{{2,2,2,2,2,2,2,2,2},
//{2,0,0,0,0,0,0,0,2},
//{2,0,2,2,0,2,2,0,2},
//{2,0,2,0,0,2,0,0,2},
//{2,0,2,0,2,0,2,0,2},
//{2.0.0.0.0.0.2.0.2},
//{2,2,0,2,2,0,2,2,2},
//{2,0,0,0,0,0,0,0,2},
//{2,2,2,2,2,2,2,2,2}};
// 
// 
// ����ü(structure) Ÿ���� �ٸ� �����͸� �ϳ��� ���� ��
// �׷��ٸ� �迭(array)�� ������ �ٸ���?
// �迭�� Ÿ���� ���� �����͸� �ϳ��� ���� ���̴�
// 
// ����ü�� ���� ���� ?
// ����ü�� �迭�� ���� ó�� 
// �迭�� ���� ������ ������ ���� �� �� ������
// ����ü�� ����ϸ� �������� ��� ���� ���� �� �� �ִ�

//5.24
//������ �� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));
	int n1 = 0;
	/*n1 = rand() & 6 + 1;*/
	n1 = rand() % 6 + 1;
	printf("%d\n", n1);
	return 0;
}

//�ֻ��� ���� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));
	int n1 = 0, n2 = 0;
	char YorN;
	int all = 0;
	while (1)
	{
		all = 0;
		printf("\n�ֻ��� ������ �Ͻðڽ��ϱ�? (y / n) ");
		scanf(" %c", &YorN);//while �� �ݺ��Ǹ鼭 ���۹����� �ذ�
		if (YorN == 'Y' || YorN == 'y')
		{
			while (1)
			{
				n1 = rand() % 6 + 1;
				n2 = rand() % 6 + 1;
				all += (n1 + n2);
				printf("\n�ֻ��� = %d %d\n", n1, n2);
				if (n1 == n2)
				{
					printf("�����Դϴ�.");
					continue;
				}
				else
				{
					printf("%dĭ �����ϼ���\n", all);
					break;
				}
			}
		}
		else if (YorN == 'N' || YorN == 'n')
		{
			break;
		}
		else
		{
			printf("Y(y)�� N(n)�� �ϳ��� ���ڸ� �Է��ϼ���\n");
		}
	}
	return 0;
}

//���� ���� �� ���� �����
// ���� = 1 ���� = 2 �� = 3
// �̱� �� = 
// ���� - ��
// ���� - ����
// �� - ����
// 
// 1 - 3
// 2 - 1
// 3 - 2 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int n = 0;
	int yours = 0;
	int computer = 0;
	int w = 0, d = 0, l = 0;
	srand((unsigned int)time(NULL));
	printf("\n������������ �� ȸ���� �Է��ϼ���");
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("(�� : %d �� : %d �� : %d)\t", w, d, l);
		computer = rand() % 3 + 1;
		printf("(1 : ����, 2 : ����, 3 : ��) : ");
		scanf("%d", &yours);
		if (computer == yours)
		{
			printf("����\n");
			d++;
			continue;
		}
		else if (yours - computer == 1 || yours - computer == -2)
		{
			printf("�̰��\n");
			w++;
			continue;
		}
		else if (computer - yours == 1 || computer - yours == -2)
		{
			printf("����\n");
			l++;
			continue;
		}
		else
		{
			printf("1, 2, 3 �� �ϳ��� ���� �Է��ϼ���\n");
			continue;
		}
	}
	printf("\n������ �����մϴ�.\n");
	return 0;
}
//+��������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	char YorN;
	int yours = 0;
	int computer = 0;
	int w = 1;
	srand((unsigned int)time(NULL));
	while (1)
	{
		w = 0;
		printf("\n�� �� ���� ������������ �Ͻðڽ��ϱ�?(y / n) ");
		scanf(" %c", &YorN);
		if (YorN == 'y' || YorN == 'Y')
		{
			while (1)
			{
				computer = rand() % 3 + 1;
				printf("(1 : ����, 2 : ����, 3 : ��) : ");
				scanf("%d", &yours);
				if (computer == yours)
				{
					printf("����\n");
					continue;
				}
				else if (yours - computer == 1 || yours - computer == -2)
				{
					printf("�̰��");
					if (w > 0)
					{
						printf("\t%d������", w);
					}
					printf("\n");
					w++;
					continue;
				}
				else if (computer - yours == 1 || computer - yours == -2)
				{
					printf("����\n");
					break;
				}
				else
				{
					printf("1, 2, 3 �� �ϳ��� ���� �Է��ϼ���\n");
					continue;
				}
			}
		}
		else if (YorN == 'n' || YorN == 'N')
		{
			break;
		}
		else
		{
			printf("\n--------Y(y) �Ǵ� N(n)�� �ϳ��� ���ڸ� �Է��ϼ���------\n");
		}
	}
	return 0;
}

//�߱����� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int V[3] = { 0, };
	int T[3] = { 0, };
	int TC = -1;
	char YorN;
	int ball = 0, strike = 0;
	int cnt = 0;
	int Wcnt = 0;
	while (1)
	{
		cnt = 1;
		printf("�߱������� �ϰڽ��ϱ�? (y / n) ");
		scanf(" %c", &YorN);
		if (YorN == 'y' || YorN == 'Y')
		{
			while (1) 
			{
			srand((int)time(NULL));
			V[0] = rand() % 9 + 1;
			V[1] = rand() % 10;
			V[2] = rand() % 10;
			if (V[0] != V[1] && V[0] != V[2] && V[2] != V[1])
				break;
			}
			while (1)
			{
				TC = -1;
				strike = 0;
				ball = 0;
				printf("\n%dȸ��\n", cnt);
				for (int i = 0; i < 3; i++)
				{
					printf("%d�� ° �� = ",i+1);
					scanf("%d", &T[i]);
					if (TC == T[i])
					{
						printf("\n----�������� �ԷµǾ����ϴ�----\n");
						printf("�ٽ� �Է����ּ���\n");
						TC = -1;
						i = -1;
						continue;
					}
					else
					{
						TC = T[i];
					}
				}
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (T[i] == V[j])
						{
							if(i == j)
							{
								strike++;
								break;
							}
							else
							{
								ball++;
							}
						}
					}
				}
				cnt++; 
				if (cnt < 10 && strike < 3)
				{
					printf("\n��Ʈ����ũ = %d\n�� = %d\n", strike, ball);
				}
				else 
				{
					printf("\n ���� = ");
					for (int i = 0; i < 3; i++)
					{
						printf("%d ", V[i]);
					}
					if (strike < 3)
					{
						printf("\n------�й��Դϴ�-------\n\n");
						break;
					}
					else
					{
						printf("\n------�����Դϴ�-------");
						printf("%dȸ �¸�\n\n", ++Wcnt);
						break;
					}
				}
			}
		}
		else if (YorN == 'n' || YorN == 'N')
		{
			break;
		}
		else
		{
			printf("Y(y) �Ǵ� N(n)�� �ϳ��� ���ڸ� �Է��ϼ���");
			continue;
		}
	}
	return 0;
}

//5.25
//�̷ΰ��� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int m[9][9] = { //maze
			 {2,2,2,2,2,2,2,2,2},
			 {2,0,0,0,0,0,0,0,2},
			 {2,0,2,2,0,2,2,0,2},
			 {2,0,2,0,0,2,0,0,2},
			 {2,0,2,0,2,0,2,0,2},
			 {2,0,0,0,0,0,2,0,2},
			 {2,2,0,2,2,0,2,2,2},
			 {2,0,0,0,0,0,0,0,2},
			 {2,2,2,2,2,2,2,2,2} };
int si, sj, ei, ej, success, top, ri[100], rj[100];
// S = start, ����� E = end, ������, sp ����������(top)
// ri, rj = ������ ���� ������ i�� ��, j�� ��
int visit(int, int);
int main()
{
	top = 0;//������ top��ġ ����
	success = 0;//�̷� Ż�� ����
	printf("==�̷� Ż�� ��� ã�� ����==\n");
	si = 1, sj = 1;//�����
	ei = 7, ej = 7;//������
	if (visit(si, sj) == 0)
	{
		printf("�ⱸ�� ã�� �� ����\n");
	}
	else
	{
		printf("��� ��θ� ã����\n");
	}
	return 0;
}
int visit(int i, int j)
{
	static int path = 1;
	//�Լ� �ȿ� ����ƽ�� ������ �� ���� �ʱ�ȭ�� �ϰ� �ȴ�
	//���� �׳� int a =0�� �ϸ� �Լ��� ���� �� �� ����
	//a �� 0���� �ʱ�ȭ �ȴ�
	//�� �Լ� ���� static������ ������ �� �� ����
	m[i][j] = 1;
	//0�� ���ִ°� ���̴� ��� �ν��ϰ�
	//������ �ڸ��� 1�� �Ѵ�
	//���ư� ���� 1�� �ٽ� ȸ���ϸ鼭 �ϸ� �ȴ�
	//=> 1�̶�� ���� '���� �Ȱ��ִ�' ��� ��
	ri[top] = i, rj[top] = j;
	top++;

	if (i == ei && j == ej)//�������� �������� ��
	{
		printf("ã�� ��� %d��\n", path++);
		for (int k = 0; k < top; k++)
		{
			printf("(%d, %d) ", ri[k], rj[k]);//��θ� ����ϴ� ����
		}
		printf("\n");
		success = 1;//��θ� ���������� ã��
	}
	//�̷� Ž�� ����
	//��� �Լ��� ����� �迭�� �ε����� �ٲ� ���� ǥ���ϰ� �ٽ� �ݺ��Ѵ�
	if (m[i][j + 1] == 0)//������
	{
		visit(i, j + 1);
	}
	if (m[i + 1][j] == 0)//�Ʒ���
	{
		visit(i + 1, j);
	}
	if (m[i][j - 1] == 0)//����
	{
		visit(i, j - 1);
	}
	if (m[i - 1][j] == 0)//����
	{
		visit(i - 1, j);
	}
	top--;
	m[i][j] = 0;//��� ���� ����
	//���ư� ��
	return success;//0 = ����, 1 = ����
}

//����ü ���
//������ ������ ������ �迭�� ����� ���� �ʿ��ϴ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Point//����ü ��
{
	int x, y;//����ü ������ �θ�
};
int main()
{
	struct Point p = { 4,5 };
	printf("x = %d, y = %d\n", p.x, p.y);
	struct Point p1;
	p1.x = 5;
	p1.y = 8;
	printf("x = %d, y = %d\n", p1.x, p1.y);
	struct Point myPoint[20];
	myPoint[0].x = 1;
	myPoint[0].y = 1;
	return 0;
}
//�ٸ�
struct Student
{
	char name[20];
	char stu_num[10];
	int age;
};
int main()
{
	struct Student class11[20];

	return 0;
}
//�������翹��
//�ѱݾ��� ������ ���Ÿ���Ʈ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct buylist
{
	char name[15];
	int cost;
};
int main()
{
	int n = -1;
	char YorN;
	struct buylist buylist[10] = { 0, };
	while (1)
	{
		n++;
		printf("���Ÿ���� �Է��Ͻðڽ��ϱ�? ( y / n )");
		scanf(" %c", &YorN);
		if (YorN == 'y' || YorN == 'Y')
		{
			printf("%d��° ���Ż�ǰ��   = ", n + 1);
			scanf("%s", &buylist[n].name);
			printf("%d��° ���Ż�ǰ���� = ", n + 1);
			scanf("%d", &buylist[n].cost);
		}
		else if (YorN == 'n' || YorN == 'N')
		{
			break;
		}
		else
		{
			printf("----\nY(y) �Ǵ� n(N)�� �ϳ��� ���ڸ� �Է����ּ���----\n");
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (buylist[i].cost == 0)
		{
			break;
		}
		printf("\n%s = %d", buylist[i].name, buylist[i].cost);
	}
	n = 0;
	printf("\n");
	return 0;
}