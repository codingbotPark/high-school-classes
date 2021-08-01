/**************************************************************
    Problem: 1303
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
    int n = 0, m = 0, a = 0, b = 0;
    scanf("%d %d", &n, &m);
    if (n > 0 && n <= 100 && m > 0 && m <= 100)
    {
        while (a < n * m)
        {
            a++;
            printf("%d ", a);
            if (a % m == 0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}