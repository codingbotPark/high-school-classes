// 1번문제
#include <stdio.h>
int main() {
	printf("Hello\nWorld");
	return 0;
}



// 2번문제
#include <stdio.h>
int main() {
	char x, y;
	scanf("%c %c", &x, &y);
	printf("%c %c", y, x);
	return 0;
}



// 3번문제
#include <stdio.h>
int main() {
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	printf("%d", m);
	return 0;
}



// 4번 못품
#include <stdio.h>
int main() {
	int y, m, d;
	scanf("%d.%d.%d", &y, &m, &d);
	printf("%02d-%02d-%04d", d, m, y);
	return 0;
}

// 5번문제
#include <stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	printf("%c", a);
	return 0;
}

// 6번문제
#include <stdio.h>
int main() {
	char a;
	scanf("%c", &a);
	printf("%c", a + 1);
	return 0;
}

// 8번문제
#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", (a < b ? a : b) < c ? (a < b ? a : b) : c);
	return 0;
}

// 9번문제
#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a % 2 == 0) {
		printf("%d\n", a);
	}
	if (b % 2 == 0) {
		printf("%d\n", b);
	}
	if (c % 2 == 0) {
		printf("%d", c);
	}
	return 0;
}

// 10번문제
#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a % 2 == 1) {
		printf("odd\n");
	}
	else {
		printf("even\n");
	}
	if (b % 2 == 1) {
		printf("odd\n");
	}
	else {
		printf("even\n");

	}
	if (c % 2 == 1) {
		printf("odd\n");
	}
	else {
		printf("even\n");

	}
	return 0;
}

// 11번문제
#include <stdio.h>
int main() {
	char a;
	scanf("%c", &a);
	int i = 97;
	while (i <= a) {
		printf("%c ", i);
		i++;
	}
	return 0;
}

// 12번문제
#include <stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i <= a; i++) {
		printf("%d\n", i);
	}
	return 0;
}

// 13번문제
#include <stdio.h>
int main() {
	int a;
	int sum = 0;
	scanf("%d", &a);
	for (int i = 0; i <= a; i++) {
		if (i % 2 == 0) {
			sum += i;
		}
	}
	printf("%d", sum);
	return 0;
}

// 14번문제
#include <stdio.h>
int main() {
	int a, i = 0, sum = 0;
	scanf("%d", &a);
	while (sum < a) {
		sum += i;
		i += 1;
	}
	printf("%d", i - 1);
	return 0;
}

#include <stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	int i = 0;
	while (a > i) {
		i += 1;
		a -= i;
	}
	printf("%d", i);
	return 0;
}


// 15번문제
#include <stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		if (i % 3 == 0) {
			printf("X ");
		}
		else {
			printf("%d ", i);
		}
	}
	return 0;
}

/*int a, b, c;
int counter = 0;
scanf_s("%d %d %d", &a, &b, &c);
for (int i = 0; i < a; i += 1) {
	for
}*/

// 16번문제
#include <stdio.h>
int main() {


	int i, j, k, c = 0;
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);

	for (i = 0; i < r; i++)
		for (j = 0; j < g; j++)
			for (k = 0; k < b; k++)
			{
				printf("%d %d %d\n", i, j, k);
				c++;
			}

	printf("%d ", c);

	return 0;
}

// 17번문제
#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", a + (b * (c - 1)));
	return 0;
}

// 19번문제
#include <stdio.h>
int main() {
	long long a;
	int b, c, d;
	scanf("%ld %d %d %d", &a, &b, &c, &d);
	for (int i = 0; i < d - 1; i++) {
		a = a * b + c;
	}
	printf("%ld", a);
	return 0;
}

// 20번문제
#include <stdio.h>
int main() {
	int a;
	//int array[100][2];
	int temp1, temp2;
	//int valueArray[100];
	int sum = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &temp1, &temp2);
		sum += temp2 % temp1;
	}
	printf("%d", sum);
	return 0;
}
