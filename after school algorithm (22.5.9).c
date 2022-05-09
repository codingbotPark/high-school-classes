// 1번문제
// 1부터 n까지의 수가 쓰인 카드가 있다
// 이 카드는 가장 위에 있는 첫 째 카드를 맨 아래에 넣고
// 둘째 카드를 들추면 1,
// 그 다음  번째 카드를 뒤로 보내고,
// 그 다음 카드를 들추면 2,
// . . .

# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main() {
	int arr[100] = { 0, };
	int num;
	scanf_s("%d", &num);

	int counter = 1;// 인덱스에 넣을 값
	int i = -1;// 인덱스를 돌 값
	int toggle = 0;// 한 칸 띄었는지 아닌지
	while (counter < num + 1) {
		i++;
		if (i == num) {
			i = 0;
		}

		if (arr[i] == 0) {
			if (toggle == 0) {
				toggle = 1;
				continue;
			}
			else {
				arr[i] = counter++;
				toggle = 0;
				continue;
			}

		}

	}

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}



// 2번문제
// num번의 케이스만큼
// 5개의 점수가 부여되는데,
// 가장 큰 값, 가장 작은 값을 제외한 값의 최대,최소 값의 차이가 4가 넘을 때
// KIN을 출력, 아닐 때는 그 3개의 값의 합
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void fun(int tempArr[]) {
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (tempArr[j] > tempArr[j + 1]) {
				temp = tempArr[j];
				tempArr[j] = tempArr[j + 1];
				tempArr[j + 1] = temp;
			}
		}
	}
	if (tempArr[1] - tempArr[3] >= 4 ||
		tempArr[3] - tempArr[1] >= 4) {
		printf("KIN\n");
	}
	else {
		printf("%d", tempArr[1] + tempArr[2] + tempArr[3]);
		printf("\n");
	}
}

int main() {
	int num;
	int arr[10][5];
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
		fun(arr[i]);
	}

	return 0;
}