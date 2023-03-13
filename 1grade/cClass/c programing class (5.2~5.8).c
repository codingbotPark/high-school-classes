 //포인터란 무엇인가?
 //주소를 저장하는 변수
 //
 //포인터배열과 배열포인터의 차이점
 //google
 //포인터 배열은 주소값들을 저장하는 배열 이다. 
 //배열 포인터는 배열의 시작주소값을 저장할 수 있는 포인터 이다.
 //naver
 //1. 포인터는 변수인데 비해 배열은 상수이다.
 //pi는 고유의 메모리를 차지하고 있고 언제든지 다른 대상을 가리킬 수 있지만 
 //ar은 선언할 때 그 위치가 이미 고정되므로 다른 대상을 가리킬 수 없다.
 //ar로는 오로지 배열의 선두 번지를 읽을 수 있을 뿐이다.

 //2. pi가 가리키는 배열의 크키는 동적으로 결정할 수 있지만 
 //ar이 가리키는 배열의 크기는 선언할 때 정적으로 결정된다.
 //고정된 길이의 배열이 필요하면 int ar[n]; 선언문으로 배열을 생성하는 것이 편리하고 
 //가변길이의 배열이 필요하면 int* 형의 포인터 변수를 선언한  후  malloc으로 할당해서
 // 사용해야 한다.
 //포인터로 할당한 배열은 실행 중에라도 realloc으로 크기를 재할당하여 변경할 수 있다.

 //3. 배열은 그 자체가 크기 때문에 함수의 인수로 전달할 수 없지만 
 //포인터는 대상체가 무엇이든간에 4바이트의 크기밖에 차지하지 않으므로 
 //함수로 전달할 수 있다.
 //그래서 배열을 함수로 전달할 때는 반드시 포인터를 사용해야 한다.

 //4.배열로 요소를 읽는 것과 포인터로 대상체를 읽는 동작의 속도 차이가 있다.
 //배열의 첨자 연산은 매번 배열선두에서부터 출발하지만 
 //포인터는 대상체로 직접 이동해서 바로 읽으므로 액세스 속도가 빠르다.
 // * pi는 pi가 가리키는 곳을 바로 읽지만 
 //ar[n]은 * (ar + n)으로 일단 번지를 더한 후 읽어야 하므로 조금 느리다.
 //포인터가 배열보다 두배 정도 빠르다.
 //
 //
 //배열을 활용하여 개수/ 등수 등을 구할 수 있다
 //
 //비교해서 작을 때 등수++ 을 해서 등수를 구할 수 있다
 //도수 분포표를 만들 때 10으로 나누어서 배열에 +를 하면서 개수를 셀 수 있다
 //
//도수 분포표 만들기
//#define NUM 20
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
//	int i, range, histo[11] = { 0, };
//	for (i = 0; i < NUM; i++)
//	{
//		histo[a[i] / 10]++;//10으로 나누면 십의 자리만 남는데 이 10의 자리
//							//개수에 따라 배열에 +해서 개수를 센다
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		printf("%3d : %3d\n", i * 10, histo[i]);
//	}
//	return 0;
//}

//5.3
//포인터란 무엇인가 
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
	printf("%d %d %d\n", ptr1 ,ptr2, ptr3);//4증가
	printf("%p %p %p\n", ptr1 ,ptr2, ptr3);//주소출력
 //주소가 출력 되지 않는 이유는 주소 1000이면 윈도우 운영체제가 있기 때문에
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
	//str2[2] = 'x';	//이렇게 접근하면 런타임 에러 발생
	printf("%s\n", str1);
	//printf("%s\n", str2);
	return 0;
}

//포인터배열과 배열포인터의 차이점
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
//도수 분포표 만들기
#define NUM 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
	int i, range, histo[11] = { 0, };
	for (i = 0; i < NUM; i++)
	{
		histo[a[i] / 10]++;//10으로 나누면 십의 자리만 남는데 이 10의 자리
							//개수에 따라 배열에 +해서 개수를 센다
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%3d : %3d\n", i * 10, histo[i]);
	}
	return 0;
}
//+활용해서 별 찍기
#define NUM 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[] = { 35, 26,48,77,56,98,75,78,99,0,43,56,67,84,99,100 ,45,37,49,78 };
	int i, j, range, histo[11] = { 0, };
	for (i = 0; i < NUM; i++)
	{
		histo[a[i] / 10]++;//10으로 나누면 십의 자리만 남는데 이 10의 자리
							//개수에 따라 배열에 +해서 개수를 센다
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%3d : ", i * 10);
		for (j = 0; j < histo[i]; j++)
		{
			printf("★");
		}
		printf("\n");
	}
	return 0;
}

//등수 구하기
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
	printf("학생 등수\n");
	for (i = 0; i < 10; i++)
	{
		printf("학번 : %3d, 등수 : %3d\n", i + 1, rank[i]);
	}
	return 0;
}
//+개선
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int scores[10] = { 95,64,78,94,65,71,72,59,45,78 };
	int rank[102] = { 0, };//0과 101까지 플러스 해서 102
	int i, j;
	for (i = 0; i < 10; i++)
	{
		rank[scores[i]]++;//값에 + 1
		// 실행이 끝난다면 rank배열의 95,64,78,94,65,71,72,59,45,78
		// 에 1이 들어간다 이렇게 1식 +한다면 같은 수가 있어도 다음 등수가 + 2 된다
	}
	rank[101] = 1;//이 부분을 제거하고 밑 for문에 i = 101을 하면 등수에 쓰레기값이 들어간다
	// 그 이유는 for문에 rank[i+1]이 있어서 초기화를 해줘야 쓰레기 값이 안들어간다
	// 그렇다면 rank[101]을 제거하고 밑 for문에 i = 99를 한다면 등수에 0등이 들어간다
	// 그 이유는rank[i] = rank[i+1]이기 때문에 1이 없으면 등수가 1씩 감소한다

	for (i = 100; i >= 0; i--)
	{
		rank[i] = rank[i] + rank[i + 1];//전 for문에 값이 있는 부분에 1씩 넣었는데
		//이 1씩 넣은 부분들을 거칠 때 마다 +1 씩 더하면서 거친다
		//예) 95 와 90 이 있다면
		// 95 94 93 92 91 90
		//  1  1  1  1  1  2 ...  
	}
	printf("학번 점수 등수\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d %5d %3d\n", i + 1, scores[i], rank[scores[i] + 1]);
		//rank의 값들은 1 1 2 2 2 3 .... 있지만
		//rank[scores[i]+1]의 값만 출력해주면서
		//필요 한 값들만 골라서 출력한다
	}
	return 0;
}
//+입력받기, 작을수록 등수가 높음
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, arr[10];
	int rank[102] = { 0, };
	for (i = 0; i < 10; i++)
	{
		printf("%d 번째 배열에 넣을 수(100이하의 수)를 입력하세요", i);
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
	printf("학번 점수 등수\n");
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
		printf("1부터 10사이의 수를 입력하세요(아닐시 종료)");
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
			printf("%d : %d개\n", i, arr[i]);
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
        printf("%d번 점수 : ", i + 1);
        scanf("%d %d %d", &com[i], &pc[i], &math[i]);
        printf("\n");
        to[i] = com[i] + pc[i] + math[i];
        comto += com[i];
        pcto += pc[i];
        mathto += math[i];
        toto += to[i];
    }
    printf("   컴일   프c    수학    총점\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d 번   %d   %d   %d   %d\n", i + 1, com[i], pc[i], math[i], to[i]);
    }
    printf("합계   %d   %d   %d   %d", comto, pcto, mathto, toto);
    return 0;
} 
//+개선(이 맞나)
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
				printf("%d번 학생의 컴일점수 : ", i + 1);
			}
			else if (j == 1)
			{
				printf("%d번 학생의 프c점수 : ", i + 1);
			}
			else if (j == 2)
			{
				printf("%d번 학생의 수학점수 : ", i + 1);
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
	printf("번호	컴일	프c    수학    총점");
	for (i = 0; i < 16; i++)
	{
		if (i%4==0)
		{
			printf("\n");
			printf("%d번    ", (i / 4) + 1);
		}
		printf("%d     ", arr[i]);
	}
	return 0;
}
