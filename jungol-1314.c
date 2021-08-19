#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n,m=65,k=-1;
	int v[100][100] = {0,};
	int i = 0, j = 0;
	scanf(" %d", &n);
	for (i = 0; i < n; i++)
	{
		k *= -1;
		for (j; j < n && j >= 0; j += k)
		{
			v[j][i] = m;
			m++;
			if (m > 90)
			{
				m = 65;
			}
		}
		if (i % 2 == 0)
		{
			j--;
		}
		else
		{
			j++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c ", v[i][j]);
		}
		printf("\n");
	}


	return 0;
}