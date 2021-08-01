/**************************************************************
    Problem: 1304
    User: pbk575575
    Language: C
    Result: Success
    Time:2 ms
    Memory:1156 kb
****************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0, i = 0, j = 0, a = 0, b = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        j = i;
        while (j <= n * n)
        {
            printf("%d ", j);
            j = j + n;
        }
        printf("\n");
    }
    return 0;
}