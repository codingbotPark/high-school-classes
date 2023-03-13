// 9.13
// 
// ADT = Abstract Data Type
// �߻� ������ Ÿ��
// 
// ��ǻ�Ϳ����� JOB = ������ ���α׷� �ϳ�
// 
// 
// ť�� ����
// * �����͸� ���� ���� �־��� ���ٰ� �� ū �迭�� �ʿ��ϴ�
// * �迭�� 100%������� ���Ѵ�
// 
// �̷��� ť�� ������ �����ϴ°� ����ť/ȯ��ť�̴�
// 
// front�� rear�� ������ ť�迭�� �� ���̴�
// ����ť�� �� �Ͱ� ������ ������ �ȵǱ� ������ �迭�� �� ĭ�� �����
// 
// ����ť���� �ٽ� 0���� �Ѿ ���� % �� ����Ѵ�
// 
//

// 9.16
// ������
// ��� ���� ���� �׵��� 0���� �Ǿ��ִ� ����̴�
// 
// ��û�� �������� ����Ѵٸ� �޸� ���� ��������
// �����Ϸ��� ���� ������� �� �Ҽ��� �ִ�
// 
// 
// ��� ȿ���� ���鿡�� ū ������ �ִ�
// 
// �� ��Ʈ
// ������� ������ �Ǿ��ִ� �迭���� ������	�����Ѵ�
// 
// �� ������ ������ 
// 1. �����͸� �ʼ� �� ���� �뼺�뼺 ����� ���� �����Ѵ�.
// 2. �����͸� �ٽ� �߰� ����� ���� �����Ѵ�.
// 3. �̷��� ��� �Ͽ� ��ħ�� ������ �ȴ�.
//



//9.13
// �ݵ�� ������
// �̺�Ž��, ����Ž�� : ���ĵ� �迭 �� ������ ã��
// �� �� Ž���� �� �ݾ� ���� �� �ִ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//�̺�Ž��, ����Ž�� : ���ĵ� �迭 �� ������ ã��
//�� �� Ž���� �� �ݾ� ���� �� �ִ�

int arr[10] = { 1,1,2,3,4,5,6,7,8,9 };
int n, k;

int binarysearch(int s, int e) {
	while (s <= e) {
		int m = (s + e) / 2;//m�� middle
		if (arr[m] == k)
			return m;//ã�� �迭�� �ε���
		if (arr[m] > k)
			e = m - 1;//e�� -�ȴٴ� ���� middle�ε����� ������ �۴ٴ� ��
		else
			s = m + 1;//s�� +�ȴٴ� ���� middle�ε����� ������ ũ�ٴ� ��
	}
	return -1;//���ڸ� ��ã��
}

int main()
{
	printf("ã�� ���� �Է�");
	scanf("%d", &k);
	printf("%d��°���� �߰�\n", binarysearch(0, 10));
	return 0;
}
//��ã�� ��� %d��° ���� ��ã�Ҵٴ� �� �߰�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arr[10] = {1,1,2,3,4,5,6,7,8,9};
int n, k ,c=0;
int cnt=0;

int binarysearch(int s, int e) {
	while (s <= e) {
		int m = (s + e) / 2;//m�� middle
		cnt++;
		if (arr[m] == k)
			return m;//ã�� �迭�� �ε���
		if (arr[m] > k)
			e = m - 1;//e�� -�ȴٴ� ���� middle�ε����� ������ �۴ٴ� ��
		else
			s = m + 1;//s�� +�ȴٴ� ���� middle�ε����� ������ ũ�ٴ� ��
	}
	return -1;//���ڸ� ��ã��
}

int main()
{
	printf("ã�� ���� �Է�");
	scanf("%d", &k);
	c = binarysearch(0, 10);
	if (c < 0)
	{
		printf("%d������ ��ã�ҽ��ϴ�\n", cnt);
	}
	else
	{
	printf("%d������ %d��°���� ã�ҽ��ϴ�\n", cnt, binarysearch(0, 10));
	}
	return 0;
}

//9.16
�̷�Ž��(ī��)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
int map[9][9] = {
{2,2,2,2,2,2,2,2,2},
{2,0,0,0,0,0,0,0,2},
{2,0,2,2,0,2,2,0,2},
{2,0,2,0,0,2,0,0,2},
{2,0,2,0,2,0,2,0,2},
{2,0,0,0,0,0,2,0,2},
{2,2,0,2,2,0,2,2,2},
{2,0,0,0,0,0,0,0,2},
{2,2,2,2,2,2,2,2,2}
};
int facing = 0;
const COORD end = { 7,7 };
COORD back = { 1,1 };
COORD player = { 1,1 };
void gotoxy(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main() {
	printf("�����̸� �Է����ּ��� (�и���) : ");
	int speed; scanf("%d", &speed);
	system("cls");
	gotoxy(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%s", map[i][j] ? "��" : "��");
		putchar(10);
	}
	gotoxy(player.X, player.Y);
	printf("��");
	while (end.X != player.X || end.Y != player.Y) {
		Sleep(speed);
		facing += 3;
		facing %= 4;
		while (player.X == back.X && player.Y == back.Y) {
			switch (facing) {
			case 0:
				if (map[player.Y - 1][player.X]) {
					facing++;
				}
				else {
					player.Y--;
				}
				break;
			case 1:
				if (map[player.Y][player.X + 1]) {
					facing++;
				}
				else {
					player.X++;
				}
				break;
			case 2:
				if (map[player.Y + 1][player.X]) {
					facing++;
				}
				else {
					player.Y++;
				}
				break;
			case 3:
				if (map[player.Y][player.X - 1]) {
					facing = 0;
				}
				else {
					player.X--;
				}
				break;
			}
		}
		gotoxy(player.X, player.Y);
		printf("��");
		gotoxy(back.X, back.Y);
		printf("��");
		gotoxy(0, 10);
		printf("goal : %d %d\n", end.X, end.Y);
		printf("player : %d %d\n", player.X, player.Y);
		printf("last pos : %d %d\n", back.X, back.Y);
		printf("facing : %s", facing == 0 ? "up   " : facing == 1 ? "right" : facing == 2 ? "down " : "left ");
		back.X = player.X;
		back.Y = player.Y;
	}
}
//�����
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


int Si, Sj, Ei, Ej; // Start : ���, End : ���� ���� ǥ��
int success, top, Path_i[100], Path_j[100];
// S : Start -> �����, E : End -> ������, Top : ��� ���� �迭 �ε���
// Path_i, Path_j : ������ ��, �� ��� ���� ������ ( i : ��, j : �� )

int visit(int, int);

int main()
{
    top = 0;
    success = 0;
    printf("�̷� Ż�� ��� ã�� ����===\n");
    Si = 1, Sj = 1;
    Ei = 7, Ej = 7;

    if (visit(Si, Sj) == 0)
        printf("�̷��� �ⱸ�� ã�� �� ����\n");
    else
        printf("�̷��� ��� ��θ� ã����\n");
    return 0;
}

void printPath()
{
    for (int i = 0; i < top; i++)
    {
        printf("[%d,%d]", Path_i[i], Path_j[i]);
    }
    printf("\n");
}

int visit(int i, int j)
{
    static int pathCount = 1;
    m[i][j] = 1;
    Path_i[top] = i;
    Path_j[top] = j;
    top++;

    if (i == Ei && j == Ej)
    {
        printf("ã�� ��� %d��\n", pathCount++);
        printPath();//��θ� ������ִ� �Լ�
        success = 1;//��θ� ã����
    }

    //�̷� Ž���ϱ�
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
    top --;//�Դ� ���� �ٽ� ���ư���
    m[i][j] = 0;//1�� �ǿ��ִ� ���� 0���� �ʱ�ȭ
}