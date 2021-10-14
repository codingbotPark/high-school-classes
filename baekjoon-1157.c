//문자열을 입력받고 가장 많이 사용된 알파벳 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main()
{
	int value[26] = { 0, };//알파벳을 26개
	char arr[10000000];//입력받을 char형 배열
	int temp = 0;//arr의 내용을 볼 변수

	scanf("%s", &arr);

	while (arr[temp] != NULL)//arr의 끝까지
	{
		if (arr[temp] >= 97)//소문자일 때
		{
			value[arr[temp] - 97]++;
		}
		else
		{
			value[arr[temp] - 65]++;
		}
		temp++;
	}

	int max = 0;
	int cnt = 0;

	for (int i = 1; i < 26; i++)//가장 큰 값을 구하기
	{
		if (value[i] > value[max])
		{
			cnt = 0;
			max = i;
		}
		else if (value[i] == value[max])
		{
			cnt++;
		}
	}

	if (cnt > 0)
	{
		printf("?");
	}
	else
	{
		printf("%c", max + 65);
	}
}