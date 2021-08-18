#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n, v=65;
	int m[100][100];
	scanf("%d", &n);
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j >= 0; j--)
		{
			m[j][i] = v++;
			if (v > 90)
			{
				v = 65;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c ", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
