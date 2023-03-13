// atoi = 문자열을 정수로
// itoa = 입력받은 정수를 정해진 진법대로 문자열로 넣는다
// visual -> 확장 관리 -> github extension설치 -> vs에 git이 생긴다
//
// git 이란 어떠한 명령이다 
// (버전관리) 이전꺼를 나두고 수정한 부분을 저장하기 위한
//
// git hub는 어떠한 원격저장소이다
//
// 원격저장소(원격으로 저장할 공간)을 리퍼지토리라 한다
//
//
// 커밋과 푸시와 풀
//
// 커밋은 변경사항을 표시하는걸 커밋
//
// 푸시는 커밋커밋해놓은걸 푸시해야지 github에 올라감
//
// 풀은 푸시해 놓은 것을 그대로 가져와 다시 작업을 가능하게 하는 것
//
// 즉 푸시는 원격저장소에 올리는 것
// 풀은 저장소에 올라가있는 것을 가져오는 것
//
// 포크와 풀 리케스트
//
// 포크는 다른 사람이 한걸 가져오는 것
//
// 풀 리케스트는 내가 무언갈 했는데 누군가 쓸사람 있으면 사용하세요 
// 라는느낌

//5.18
//자료형의 제약을 바꾸기(atoi)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char str[256];
    printf("Enter a number : ");
    gets(str, 256);
    i = atoi(str);//문자열을 숫자로 변환
    printf("입력된 정수값 : %d, 2배의 값 : %d\n", i, i * 2);
    return 0;
}

//자료형의 제약을 바꾸기(_itoa)
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
    _itoa(i, arr, 16);//16진수
    printf("hexadecimal : %s\n", arr);
    _itoa(i, arr, 2);//2진수
    printf("binary : %s\n", arr);
    return 0;
}

//소수를 찾아라 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int v;
	int cnt1 = 0, cnt2 = 0;
	while (1)
	{
		printf("1부터 소수를 출력할 수를 입력하세요(1000이하의 자연수)");
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
//+선생님 코드
#include <stdio.h>
int isPrime(int n)
{
	//for (int i = 2; i < n; i++)
	// 하지만 이 코드는 비효율적이다.
	// (수를 일일이 다 거치기 때문에)
	// 개선하면
	for (int i=2 ; i*i<=n;i++)
	{
		if (!(n % i)) return 0;
		// if (n % i == 0) 과 if (!(n % i)) 는 같다
		// 나머지가 0이게 되면 소수가 아니다
	}
	return 1;//맞다면 1을 보내서 main에서 if문이 실행되게 한다
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

//키크기 도수 분포표
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[7] = { 0, };
	int h = 0,j=1;
	while (1)
	{
		printf("%d번째 학생의 키를 입력하세요", j);
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