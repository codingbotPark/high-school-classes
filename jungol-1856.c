/**************************************************************
    Problem: 1856
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
    int n = 0, m = 0, i = 0, j = 1, a = 0;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)//-
        {
            for (a = j + (m - 1); a >= j; a--)
            {
                printf("%d ", a);
            }
            j += m;
        }
        if (i % 2 == 1)
        {
            for (j; j <= m * i; j++)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}