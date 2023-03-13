//10.3~10.9
//퀵 정렬
//참고 (https://hongku.tistory.com/149)
// 
// 퀵 정렬 원리
// 
// 배열의 기준이 되는 수(첫 번째 수)를 정한다
// 이 수를 피봇(pivot) 이라한다
// 
// 이 피봇 다음 첫번째 수를 i, 마지막번째 수를 j 로 포인터를 정한다
// i는 처음부터 피봇보다 큰 수,
// j는 끝에서부터 피봇보다 작은 수를 찾는다
// 
// 값을 찾으면 두 수를 바꾼다(i와 j가 엇갈리기 전까지)
// 
// i와 j가 엇갈리고 다시
// i와 j가 각각 피봇보다 큰 수, 피봇보다 작은 수를 찾으면
// i와 j를 바꾸는 것이 아닌
// 피봇과 j를 바꾼다
// 
// 그렇게 되면 피봇의 위치를 기준으로
// 왼쪽은 피봇보다 작은 수들,
// 오른쪽은 피봇보다 큰 수들이 위치하게 된다
// 
// 이 때 피봇을 기준으로 나누어진 두 영역에 또다시
// 각각 피봇을 설정하고 
// 퀵 정렬을 진행한다

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int data[10];

void quick(int* data, int start, int end)
{
	if (start >= end)
	{//배열의 원소가 하나일 경우
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp = 0;

	while (i <= j)
	{
		//포인터가 엇갈리기 전까지 반복
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
			//엇갈릴 때
			//피봇과 j를 바꾼다
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			//엇갈리지 않을 때
			//i와 j를 바꾼다
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	//피봇을 기준으로 왼쪽과 오른쪽을
	//똑같이 퀵 정렬로 정렬
	//배열과 시작점, 끝점을 전달
	quick(data, start, j - 1);
	quick(data, j + 1, end);
}

int main()
{
	printf("10개의 수를 입력하세요");

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



//문제만들기
//이차방정식의 두 해의 차이가 큰 순서로 정렬
//(그래프의 폭)
// 
//해가 같거나 하나인 경우는 제외해 표시한다
//
//근의공식
//-b +- 루트 b^2 - 4ac
//ㅡㅡㅡㅡ
//2a
//
//과
//
//판별식
//b^2 - 4ac
//
//를 활용
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int arr[10][3];//이차방정식을 저장
int num;//이차방정식의 개수
int resultarr[10];//이차방정식의 두 해의 거리를 저장,
//같으면 0, 해가없다면 -1
int i;//판별, 해를 구하는 과정에서 i를 넘기기 위해 전역변수로 지정
int j;
int tmp;//스왑할 때 사용
int gap;//쉘정렬에 사용
int temp1, temp2, temp3;

void input();//이차방정식을 입력받는 함수
void determine();//판별식으로 이차방정식의 해의 개수(x축과 닿는 점의 개수)를 구하여
//result(두 개의 해를 구함)로 전달하거나
//해가 하나, 없음 으로 넘기기
void result();//근의 공식으로 이차방정식의 해를 구하여 두 해사이의 거리를 구하는 함수
void sort();//거리에 따른 정렬
void printresult();//결과를 출력


int main()
{
	printf("이차방정식의 개수를 입력하세요");
	scanf("%d", &num);
	
	input();//값 입력 

	determine();//이차방정식의 해의 개수 판별,
	//판별에 따른 분류

	sort();

	printresult();

	return 0;
}


void input()
{
	for (i = 0; i < num; i++)
	{
		printf("\n%d번째 이차방정식\n",i+1);
		printf("x^2의 계수 : ");
		scanf("%d", &arr[i][0]);
		printf("x의 계수 : ");
		scanf("%d", &arr[i][1]);
		printf("상수 : ");
		scanf("%d", &arr[i][2]);
	}
}

void determine()
{
	for (i = 0; i < num; i++)
	{
		int temp = pow(arr[i][1],2) - (4 * arr[i][0] * arr[i][2]);//판별식을 사용한 결과
		if (temp > 0)//해가 두 개일때
		{
			result();
		}
		else if (temp == 0)//해가 중복일 때
		{
			resultarr[i] = 0;//중복일 때 0을 넣음
		}
		else//해가 없을 때
		{
			resultarr[i] = -1;//없을 때 -1을 넣음
		}
	}
}


void result()//이차방정식의 해를 구하여 두 해사이의 거리를 구하는 함수
{
	//-b +- 루트 b^2 - 4ac
	//ㅡㅡㅡㅡ
	//2a
	int a = -((-arr[i][1] + (sqrt((pow(arr[i][1], 2)) - (4 * arr[i][0] * arr[i][2])))) / (2 * arr[i][0]));
	int b = -((-arr[i][1] - (sqrt((pow(arr[i][1], 2)) - (4 * arr[i][0] * arr[i][2])))) / (2 * arr[i][0]));
	resultarr[i] = b - a;//차이를 resultearr에 넣는다
}

void sort()//차이의 크기를 오름차순으로 정렬 
{
	for (gap = num / 2; gap > 0; gap /= 2)
	{//gap 이 1 이상일 때 작동함
		// = gap > 0
		for (i = gap; i < num; i++)
		{//gap만큼떨어진 인덱스끼리 비교하기 때문에
			//i = gap으로 지정함으로써 gap이 바꿔진것 만큼 반복할 수 있다
			tmp = resultarr[i];
			temp1 = arr[i][0];
			temp2 = arr[i][1];
			temp3 = arr[i][2];
			for (j = i; j >= gap && resultarr[j - gap] > tmp; j -= gap)
			{
				resultarr[j] = resultarr[j - gap];
				//for문 안에서 resultarr[j - gap] > tmp(resultarr[i]) 로 비교
				arr[j][0] = arr[j - gap][0];
				arr[j][1] = arr[j - gap][1];
				arr[j][2] = arr[j - gap][2];
			}
			resultarr[j] = tmp;
			arr[j][0] = temp1;
			arr[j][1] = temp2;
			arr[j][2] = temp3;
			//for문에 탈출해도 마지막 수는 스왑할 수 있다
			//resultarr[j] 는 resultarr[i]와 같기 때문에 바뀌지 않는다면 그대로이다
		}
	}
}
//원래 이차방정식의 순서도 변경하여 print할 때도 해의 거리에 따른 순서로 출력되도록 한다

void printresult()//결과를 출력하는 함수
{
	printf("\n그래프와 x축과 닿는 점이 업다면 -1,\n한 점에서 닿는다면 0\n");
	for (i = 0; i < num; i++)
	{
		printf(" %d\t", resultarr[i]);
		printf("%dx^2 + %dx + %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}


//문제만들기
//영어문자열 abc순으로 정렬
	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[10][20];//영어 단어를 입력받을 배열
int temp_arr[20];//영어 단어를 스왑할 때 복사할 배열(복사해야해서 20바이트이다)
int num;//단어의 개수
int i, j;//반복문에서 사용

int main()
{
	printf("단어의 개수를 입력하세요");
	scanf("%d", &num);

	//영어단어를 입력받음
	for (i = 0; i < num; i++)
	{
		scanf("%s", arr[i]);
	}

	//버블정렬 사용
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{//strcmp는 두 문자열이 같은지 다른지를 알 수 있다
				//strcmp안에 있는 두 문자열이 같다면 0을 반환,
				//strcmp안에 있는 두 문자열중 왼쪽 문자열이 크다면 양수(1) 을 반환,
				//strcmp안에 있는 두 문자열중 오른쪽 문자열이 크다면 음수(-1) 을 반환
				//즉 strcmp(arr[j], arr[j + 1] > 0) 는 abc 순서로 정렬한다
				
				strcpy_s(temp_arr, 20, arr[j]);
				strcpy_s(arr[j], 20, arr[j + 1]);
				strcpy_s(arr[j + 1], 20, temp_arr);
				//strcpy는 문자열을 복사하는 함수이다 그냥 스왑하는 과정이다
			}
		}
	}

	printf("\n");
	//영어단어들을 정렬후 출력
	for (i = 0; i < num; i++)
	{
		printf("%s\n", arr[i]);
	}
}