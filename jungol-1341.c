/**************************************************************
    Problem: 1341
    User: pbk575575
    Language: C
    Result: Success
    Time:1 ms
    Memory:1156 kb
****************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int s = 0, e = 0, a = 0, b = 0, c = 0, d = 0;
    scanf("%d %d", &s, &e);
    if (s < 10 && s>1 && e < 10 && e>1)
    {
        if (s < e)//+
        {
            for (s; s <= e; s++)
            {
                a = 0;
                while (a < 9)
                {
                    a += 1;
                    printf("%d * %d = %2d   ", s, a, s * a);
                    if (a % 3 == 0)
                    {
                        printf("\n");
                    }
                }
                printf("\n");
            }
        }
        else//-
        {
            for (s; s >= e; s--)
            {
                a = 0;
                while (a < 9)
                {
                    a += 1;
                    printf("%d * %d = %2d   ", s, a, s * a);
                    if (a % 3 == 0)
                    {
                        printf("\n");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}