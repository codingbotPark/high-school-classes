// typedef struct Point �� ����� �� ����ü�� ª�� �ٲ� �� �ִ�
// typedef sturct Point PP;
// 
// ����ü ��� ���ÿ��� �� ���� ����ü�� Ȱ���� �����ϰ�
// �� ���� ������ �Ÿ��� ���ϴ� ��������
// math.h ���̺귯���� Ȱ���Ͽ� sqrt(������)�� ���ϴ� �Լ��� ����� ���� �� �ִ�
// 
// ����ü�� ����Ͽ� �� ���� �Ÿ��� ���� �� ����ü�� x, y �� ��ǥ�� int ���̿���
// double�� ����� ��Ʈ���� ���� �� �ִ�
// 
// ���� ����¿��� 
// 
// FILE* fp = fopen("myData.txt", "w"); ���� w�� write r�� read
// 
// �� ������� file�� ��ġ�� ������ 
// ������Ʈ��Ŭ�� -> ����Ž���⿡�� ���� ����
// 
// fprintf = file + printf �� fprintf�� Ȱ����
// �޸���ȿ� ���� ������ �Է¹޾� �޸����� ����� ���� �� �ִ�

//6.7
//����ü���
#include <stdio.h>
#include <math.h>
struct Point
{
	int x, y;
};
int main()
{
	double X = 0;
	double Y = 0;
	double V = 0;
	struct Point p;
	p.x = 1;
	p.y = 2;
	printf("x��ǥ : %d, y��ǥ : %d\n", p.x, p.y);
	//3,4��ǥ�� �� �ϳ� �� �����
	struct Point p1;
	p1.x = 3;
	p1.y = 4;
	printf("x��ǥ : %d, y��ǥ : %d\n", p1.x, p1.y);
	X = p.x - p1.x;
	Y = p.y - p1.y;
	V = sqrt((X * X) + (Y * Y));
	printf("�� �������� �Ÿ� = %f\n", V);
	return 0;
}

//visual studio���� �޸����� ����� ���


//���� �����(������ �б�)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* fp;
	fp = fopen("myfile.txt", "r");
	char name[80] = "";
	int myAge;
	while (!feof(fp))//������ ������ üũ
	{
		fscanf(fp, "%s %d", name, &myAge);
		printf("%s %d\n", name, myAge);
	}
	fclose(fp);
	return 0;
}
myfile�̶�� txt ������ �ִٸ� �� txt ������ �д´�
txt ������ ���ٸ� ������ �Ÿ��� ���� if ���� ����Ѵ�

//���� �����(������ ����)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* fp = fopen("myData.txt", "w");
	fprintf(fp, "%s %d\n", "ȫ�浿", 34);
	fclose(fp);
	return 0;
}
//+�Է��� ����� ���� �̸��� ���̸� �Է¹޾� myData.txt�� ����ϴ� ���α׷� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	char name[10];
	int age;
	FILE* fp = fopen("myData.txt", "w");
	printf("�Է��� ����� ���� �Է��ϼ���");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("%d��° ����� �̸� ", i + 1);
		scanf(" %s", &name);
		printf("%d��° ����� ���� ", i + 1);
		scanf("%d", &age);
		fprintf(fp, "%d %s %d\n",i+1, name, age);
	}
	fclose(fp);
	return 0;
}