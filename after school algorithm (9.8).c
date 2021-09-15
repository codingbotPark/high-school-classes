//함호해독
// 문자열을 입력받아서
// 숫자를 만났을 때 그 숫자의 수만큼
// 반대로 출력 
// 예) l1ov2e1 = lvoe
// 예) love13 = evol
// 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char input[20];
	int length = 0;//현재 위치를 바꿈
	int len = 0;
	int temp = 0;//임시로 숫자를 받음
	char chartemp = 0;//임시로 

	scanf("%s", input);

	while (input[length] != NULL)//NULL이 아닐 때까지 실행
	{
		if (input[length] >= 49 && input[length] <= 57)//숫자일 때
		{
			temp = input[length] - 48;//숫자로 변환
			input[length] = '0';//숫자가 있는 자리를 0으로 만듬

			for (int i = 0; i < temp; i++)//그 숫자만큼
			{
				printf("%c", input[--length]);
				input[length] = '0';//출력한 자리를 0으로 만듬
			}

			//뒤에 남은 것들을 앞으로 당김
			for (int i = 0; i < temp + 1; i++)//숫자가 있던 자리, 출력한 수의 개수만큼 앞으로 당겨야 한다
			{
				len = length + temp - i + 1;//temp만큼 당긴다 = 만난 숫자 다음 문자자리
				//length = 출력된 문자중 가장 앞
				while (input[len] != NULL)//마지막 문자열 까지
				{
					input[len - 1] = input[len];
					len++;

				}
				//마지막번째 인덱스일 때 NULL으로 만들기
				input[len - 1] = input[len];
			}

			length--;//length를 그 자리에 머무도록 - 하기
		}
		length++;
	}

	return 0;
}