// typedef struct Point 를 사용해 긴 구조체를 짧게 바꿀 수 있다
// typedef sturct Point PP;
// 
// 구조체 사용 예시에서 두 점을 구조체를 활용해 정리하고
// 그 두점 사이의 거리를 구하는 예제에서
// math.h 라이브러리를 활용하여 sqrt(제곱근)을 구하는 함수를 사용해 구할 수 있다
// 
// 구조체를 사용하여 두 점의 거리를 구할 때 구조체에 x, y 의 좌표가 int 형이여도
// double을 사용해 루트값을 구할 수 있다
// 
// 파일 입출력에서 
// 
// FILE* fp = fopen("myData.txt", "w"); 에서 w는 write r은 read
// 
// 이 만들어진 file의 위치를 보려면 
// 프로젝트우클릭 -> 파일탐색기에서 볼더 열기
// 
// fprintf = file + printf 이 fprintf를 활용해
// 메모장안에 넣을 내용을 입력받아 메모장을 만들어 넣을 수 있다

//6.7
//구조체사용
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
	printf("x좌표 : %d, y좌표 : %d\n", p.x, p.y);
	//3,4좌표의 점 하나 더 만들기
	struct Point p1;
	p1.x = 3;
	p1.y = 4;
	printf("x좌표 : %d, y좌표 : %d\n", p1.x, p1.y);
	X = p.x - p1.x;
	Y = p.y - p1.y;
	V = sqrt((X * X) + (Y * Y));
	printf("두 점사이의 거리 = %f\n", V);
	return 0;
}

//visual studio에서 메모장을 만드는 방법


//파일 입출력(파일을 읽기)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* fp;
	fp = fopen("myfile.txt", "r");
	char name[80] = "";
	int myAge;
	while (!feof(fp))//파일의 끝까지 체크
	{
		fscanf(fp, "%s %d", name, &myAge);
		printf("%s %d\n", name, myAge);
	}
	fclose(fp);
	return 0;
}
myfile이라는 txt 파일이 있다면 그 txt 파일을 읽는다
txt 파일이 없다면 오류를 거르기 위해 if 문을 사용한다

//파일 입출력(파일을 쓰기)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* fp = fopen("myData.txt", "w");
	fprintf(fp, "%s %d\n", "홍길동", 34);
	fclose(fp);
	return 0;
}
//+입력할 사람의 수와 이름과 나이를 입력받아 myData.txt에 기록하는 프로그램 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	char name[10];
	int age;
	FILE* fp = fopen("myData.txt", "w");
	printf("입력할 사람의 수를 입력하세요");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 사람의 이름 ", i + 1);
		scanf(" %s", &name);
		printf("%d번째 사람의 나이 ", i + 1);
		scanf("%d", &age);
		fprintf(fp, "%d %s %d\n",i+1, name, age);
	}
	fclose(fp);
	return 0;
}