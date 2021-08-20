#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N, M = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int s = 0; s < N - 1 - i; s++)//¶Ù¿ì±â
		{
			printf("  ");
		}

		M = 65 + i;
		while (M > 90)
		{
			M -= 26;
		}
		printf("%c ", M);

		for (int j = 0; j < i; j++)
		{
			M += (N - 1 - j);
			while (M > 90)
			{
				M -= 26;
			}
			printf("%c ", M);
		}

		printf("\n");

	}

	return 0;
}