// #include <stdlib.h> 을 활용해
// rand 함수를 사용할 수 있다
// rand() % n = 0부터 n-1까지의 수중 랜덤한 수가 나옴
// 
// #include <time.h> 을 활용해
// srand((unsigned int)time(NULL));
// 으로 랜덤한 값을 계속 바꿀 수 있다
// 
// stack이란 LIFO (last In First Out)
// 예를들어 a b c d를 넣었으면 
// 뺄때는 d c b a로 빼야한다
// 이 때 사용되는 것이 top 함수를 사용한다
// 
// Queue란 FIFO (First In First Out)
// stack 반대인 빨리 넣었을 때 빨리 뺄 때는
// Queue(자료구조) 를 사용한다
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
// 구조체(structure) 타입이 다른 데이터를 하나로 묶는 법
// 그렇다면 배열(array)과 무엇이 다를까?
// 배열은 타입이 같은 데이터를 하나로 묶는 법이다
// 
// 구조체가 좋은 이유 ?
// 구조체와 배열의 차이 처럼 
// 배열은 같은 데이터 끼리만 관리 할 수 있지만
// 구조체를 사용하면 데이터의 모든 것을 관리 할 수 있다

//5.24
//랜덤한 수 만들기
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

//주사위 게임 만들기
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
		printf("\n주사위 게임을 하시겠습니까? (y / n) ");
		scanf(" %c", &YorN);//while 문 반복되면서 버퍼문제를 해결
		if (YorN == 'Y' || YorN == 'y')
		{
			while (1)
			{
				n1 = rand() % 6 + 1;
				n2 = rand() % 6 + 1;
				all += (n1 + n2);
				printf("\n주사위 = %d %d\n", n1, n2);
				if (n1 == n2)
				{
					printf("더블입니다.");
					continue;
				}
				else
				{
					printf("%d칸 전진하세요\n", all);
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
			printf("Y(y)와 N(n)중 하나의 문자를 입력하세요\n");
		}
	}
	return 0;
}

//가위 바위 보 게임 만들기
// 가위 = 1 바위 = 2 보 = 3
// 이길 때 = 
// 가위 - 보
// 바위 - 가위
// 보 - 바위
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
	printf("\n가위바위보를 할 회수를 입력하세요");
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("(승 : %d 무 : %d 패 : %d)\t", w, d, l);
		computer = rand() % 3 + 1;
		printf("(1 : 가위, 2 : 바위, 3 : 보) : ");
		scanf("%d", &yours);
		if (computer == yours)
		{
			printf("비겼다\n");
			d++;
			continue;
		}
		else if (yours - computer == 1 || yours - computer == -2)
		{
			printf("이겼다\n");
			w++;
			continue;
		}
		else if (computer - yours == 1 || computer - yours == -2)
		{
			printf("졌다\n");
			l++;
			continue;
		}
		else
		{
			printf("1, 2, 3 중 하나의 수를 입력하세요\n");
			continue;
		}
	}
	printf("\n게임을 종료합니다.\n");
	return 0;
}
//+질때까지
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
		printf("\n질 때 까지 가위바위보를 하시겠습니까?(y / n) ");
		scanf(" %c", &YorN);
		if (YorN == 'y' || YorN == 'Y')
		{
			while (1)
			{
				computer = rand() % 3 + 1;
				printf("(1 : 가위, 2 : 바위, 3 : 보) : ");
				scanf("%d", &yours);
				if (computer == yours)
				{
					printf("비겼다\n");
					continue;
				}
				else if (yours - computer == 1 || yours - computer == -2)
				{
					printf("이겼다");
					if (w > 0)
					{
						printf("\t%d연승중", w);
					}
					printf("\n");
					w++;
					continue;
				}
				else if (computer - yours == 1 || computer - yours == -2)
				{
					printf("졌다\n");
					break;
				}
				else
				{
					printf("1, 2, 3 중 하나의 수를 입력하세요\n");
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
			printf("\n--------Y(y) 또는 N(n)중 하나의 문자를 입력하세요------\n");
		}
	}
	return 0;
}

//야구게임 만들기
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
		printf("야구게임을 하겠습니까? (y / n) ");
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
				printf("\n%d회차\n", cnt);
				for (int i = 0; i < 3; i++)
				{
					printf("%d번 째 수 = ",i+1);
					scanf("%d", &T[i]);
					if (TC == T[i])
					{
						printf("\n----같은수가 입력되었습니다----\n");
						printf("다시 입력해주세요\n");
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
					printf("\n스트라이크 = %d\n볼 = %d\n", strike, ball);
				}
				else 
				{
					printf("\n 정답 = ");
					for (int i = 0; i < 3; i++)
					{
						printf("%d ", V[i]);
					}
					if (strike < 3)
					{
						printf("\n------패배입니다-------\n\n");
						break;
					}
					else
					{
						printf("\n------정답입니다-------");
						printf("%d회 승리\n\n", ++Wcnt);
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
			printf("Y(y) 또는 N(n)중 하나의 문자를 입력하세요");
			continue;
		}
	}
	return 0;
}

//5.25
//미로게임 만들기
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
// S = start, 출발점 E = end, 도착점, sp 스택포인터(top)
// ri, rj = 지나간 길을 저장함 i는 행, j는 열
int visit(int, int);
int main()
{
	top = 0;//스택의 top위치 저장
	success = 0;//미로 탈출 여부
	printf("==미로 탈출 경로 찾기 게임==\n");
	si = 1, sj = 1;//출발점
	ei = 7, ej = 7;//도착점
	if (visit(si, sj) == 0)
	{
		printf("출구를 찾을 수 없음\n");
	}
	else
	{
		printf("모든 경로를 찾았음\n");
	}
	return 0;
}
int visit(int i, int j)
{
	static int path = 1;
	//함수 안에 스테틱을 넣으면 한 번만 초기화를 하게 된다
	//만약 그냥 int a =0을 하면 함수가 실행 될 때 마다
	//a 가 0으로 초기화 된다
	//단 함수 안의 static변수에 접근은 할 수 없다
	m[i][j] = 1;
	//0이 되있는걸 길이다 라고 인식하고
	//지나간 자리를 1로 한다
	//돌아갈 때는 1을 다시 회수하면서 하면 된다
	//=> 1이라는 것은 '길을 걷고있다' 라는 뜻
	ri[top] = i, rj[top] = j;
	top++;

	if (i == ei && j == ej)//도착점에 도착했을 때
	{
		printf("찾은 경로 %d번\n", path++);
		for (int k = 0; k < top; k++)
		{
			printf("(%d, %d) ", ri[k], rj[k]);//경로를 출력하는 과정
		}
		printf("\n");
		success = 1;//경로를 성공적으로 찾음
	}
	//미로 탐색 로직
	//재귀 함수를 사용해 배열의 인덱스가 바뀐 곳을 표시하고 다시 반복한다
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
	top--;
	m[i][j] = 0;//경로 원상 복귀
	//돌아갈 때
	return success;//0 = 실패, 1 = 성공
}

//구조체 사용
//변수가 여러개 있으면 배열을 만드는 것이 필요하다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Point//구조체 점
{
	int x, y;//구조체 멤버라고 부름
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
//다른
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
//내가만든예시
//총금액이 나오는 구매리스트
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
		printf("구매목록을 입력하시겠습니까? ( y / n )");
		scanf(" %c", &YorN);
		if (YorN == 'y' || YorN == 'Y')
		{
			printf("%d번째 구매상품명   = ", n + 1);
			scanf("%s", &buylist[n].name);
			printf("%d번째 구매상품가격 = ", n + 1);
			scanf("%d", &buylist[n].cost);
		}
		else if (YorN == 'n' || YorN == 'N')
		{
			break;
		}
		else
		{
			printf("----\nY(y) 또는 n(N)중 하나의 문자를 입력해주세요----\n");
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