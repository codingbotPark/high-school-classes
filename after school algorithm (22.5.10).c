#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value(val) {
	// 배열에 다 넣고(그러면 배열이 반대가 됨)
	// 배열 하나하나 돌면서 10씩 곱해서 더하고
	// 0을 만나면 곱하는 수를 초기화
	int arr[6];
	int temp = 1;
	int returnV = 0;

	int length = 0;

	for (int i = 0; val > 0; i++) {
		arr[i] = val % 10;
		val /= 10;
		length++;
	}

	for (int i = 0; i < length; i++) {
		if (arr[i] == 0) {
			temp = 1; // 곱하는 수 초기화
		}
		else {
			returnV += arr[i] * temp;
			temp *= 10;
		}
	}

	return returnV;
}

int main() {
	int num;
	scanf_s("%d", &num);
	int sum = 0;
	int temp;
	for (int i = 1; i <= num; i++) {
		//printf("i = %d\n", i);
		temp = value(i);
		//printf("temp = %d\n", temp);
		sum += temp;
		//printf("sum = %d\n", sum);
	}
	printf("%d", sum);

	//printf("%d", value(101));

	return 0;
}