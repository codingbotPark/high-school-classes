/**************************************************************
    Problem: 2046
    User: pbk575575
    Language: C
    Result: Success
    Time:0 ms
    Memory:1156 kb
****************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0, m = 0, i = 0, j = 0;
    scanf("%d %d", &n, &m);
    if (m == 1)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    if (m == 2)
    {
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                while (j > 1)
                {
                    j--;
                    printf("%d ", j);
                }
            }
            if (i % 2 == 1)
            {
                for (j = 1; j <= n; j++)
                {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
    if (m == 3)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j * i <= i * n; j++)
            {
                printf("%d ", j * i);
            }
            printf("\n");
        }
    }
    return 0;
}