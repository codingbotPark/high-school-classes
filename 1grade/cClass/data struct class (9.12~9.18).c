// 9.13
// 
// ADT = Abstract Data Type
// 추상 데이터 타입
// 
// 컴퓨터에서의 JOB = 실행한 프로그램 하나
// 
// 
// 큐의 단점
// * 데이터를 아주 많이 넣었다 뺐다가 할 큰 배열이 필요하다
// * 배열을 100%사용하지 못한다
// 
// 이러한 큐의 단점을 보안하는게 원형큐/환원큐이다
// 
// front와 rear가 같으면 큐배열이 빈 것이다
// 원형큐는 빈 것과 찬것이 구분이 안되기 때문에 배열의 한 칸을 남긴다
// 
// 원형큐에서 다시 0으로 넘어갈 때는 % 를 사용한다
// 
//

// 9.16
// 희소행렬
// 행렬 안의 많은 항들이 0으로 되어있는 행렬이다
// 
// 엄청난 희소행렬을 사용한다면 메모리 낭비가 심해진다
// 컴파일러에 따라 사용하지 못 할수도 있다
// 
// 
// 계산 효율성 측면에서 큰 이점이 있다
// 
// 쉘 소트
// 어느정도 정렬이 되어있는 배열에서 빠르게	정렬한다
// 
// 쉘 정렬의 과정은 
// 1. 데이터를 십수 개 정도 듬성듬성 나누어서 삽입 정렬한다.
// 2. 데이터를 다시 잘게 나누어서 삽입 정렬한다.
// 3. 이렇게 계속 하여 마침내 정렬이 된다.
//



//9.13
// 반드시 정렬이
// 이분탐색, 이진탐색 : 정렬된 배열 속 데이터 찾기
// 한 번 탐색할 때 반씩 나눌 수 있다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//이분탐색, 이진탐색 : 정렬된 배열 속 데이터 찾기
//한 번 탐색할 때 반씩 나눌 수 있다

int arr[10] = { 1,1,2,3,4,5,6,7,8,9 };
int n, k;

int binarysearch(int s, int e) {
	while (s <= e) {
		int m = (s + e) / 2;//m은 middle
		if (arr[m] == k)
			return m;//찾은 배열의 인덱스
		if (arr[m] > k)
			e = m - 1;//e가 -된다는 것은 middle인덱스의 값보다 작다는 뜻
		else
			s = m + 1;//s가 +된다는 것은 middle인덱스의 값보다 크다는 뜻
	}
	return -1;//숫자를 못찾음
}

int main()
{
	printf("찾을 숫자 입력");
	scanf("%d", &k);
	printf("%d번째에서 발견\n", binarysearch(0, 10));
	return 0;
}
//못찾을 경우 %d번째 만에 못찾았다는 말 추가
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arr[10] = {1,1,2,3,4,5,6,7,8,9};
int n, k ,c=0;
int cnt=0;

int binarysearch(int s, int e) {
	while (s <= e) {
		int m = (s + e) / 2;//m은 middle
		cnt++;
		if (arr[m] == k)
			return m;//찾은 배열의 인덱스
		if (arr[m] > k)
			e = m - 1;//e가 -된다는 것은 middle인덱스의 값보다 작다는 뜻
		else
			s = m + 1;//s가 +된다는 것은 middle인덱스의 값보다 크다는 뜻
	}
	return -1;//숫자를 못찾음
}

int main()
{
	printf("찾을 숫자 입력");
	scanf("%d", &k);
	c = binarysearch(0, 10);
	if (c < 0)
	{
		printf("%d번만에 못찾았습니다\n", cnt);
	}
	else
	{
	printf("%d번만에 %d번째에서 찾았습니다\n", cnt, binarysearch(0, 10));
	}
	return 0;
}

//9.16
미로탐색(카피)
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
	printf("딜레이를 입력해주세요 (밀리초) : ");
	int speed; scanf("%d", &speed);
	system("cls");
	gotoxy(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%s", map[i][j] ? "■" : "□");
		putchar(10);
	}
	gotoxy(player.X, player.Y);
	printf("★");
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
		printf("★");
		gotoxy(back.X, back.Y);
		printf("□");
		gotoxy(0, 10);
		printf("goal : %d %d\n", end.X, end.Y);
		printf("player : %d %d\n", player.X, player.Y);
		printf("last pos : %d %d\n", back.X, back.Y);
		printf("facing : %s", facing == 0 ? "up   " : facing == 1 ? "right" : facing == 2 ? "down " : "left ");
		back.X = player.X;
		back.Y = player.Y;
	}
}
//만들기
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


int Si, Sj, Ei, Ej; // Start : 출발, End : 도착 지점 표시
int success, top, Path_i[100], Path_j[100];
// S : Start -> 출발점, E : End -> 도착점, Top : 경로 배정 배열 인덱스
// Path_i, Path_j : 지나간 길, 즉 행과 열을 저장함 ( i : 행, j : 열 )

int visit(int, int);

int main()
{
    top = 0;
    success = 0;
    printf("미로 탈출 경로 찾기 게임===\n");
    Si = 1, Sj = 1;
    Ei = 7, Ej = 7;

    if (visit(Si, Sj) == 0)
        printf("미로의 출구를 찾을 수 없음\n");
    else
        printf("미로의 모든 경로를 찾았음\n");
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
        printf("찾은 경로 %d번\n", pathCount++);
        printPath();//경로를 출력해주는 함수
        success = 1;//경로를 찾았음
    }

    //미로 탐색하기
    if (m[i][j + 1] == 0)//오른쪽
    {
        visit(i, j + 1);
    }
    if (m[i + 1][j] == 0)//아래쪽
    {
        visit(i + 1, j);
    }
    if (m[i][j - 1] == 0)//왼쪽
    {
        visit(i, j - 1);
    }
    if (m[i - 1][j] == 0)//위쪽
    {
        visit(i - 1, j);
    }
    top --;//왔던 기을 다시 돌아간다
    m[i][j] = 0;//1로 되여있는 길을 0으로 초기화
}