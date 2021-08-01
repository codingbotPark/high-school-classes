/**************************************************************
    Problem: 1291
    User: pbk575575
    Language: C
    Result: Success
    Time:1 ms
    Memory:1156 kb
****************************************************************/


#include <stdio.h>
int main()
{
    int s = 0, e = 0, a = 0, b = 0, c = 0;
    int A = 0, B = 0;
    while (1)
    {
        scanf("%d %d", &s, &e);
        if (s > 1 && s < 10 && e > 1 && e < 10)
        {
            if (s > e)//-秦具等促
            {
                for (A = 1; A < 10; A++)
                {
                    a = s;
                    for (a = s; a >= e; a--)
                    {
                        printf("%d * %d = %2.d   ", a, A, a * A);
                    }
                    printf("\n");
                }
            }
            else//+秦具等促
            {
                for (A = 1; A < 10; A++)
                {
                    a = s;
                    for (a = s; a <= e; a++)
                    {
                        printf("%d * %d = %2.d   ", a, A, a * A);
                    }
                    printf("\n");
                }
            }
            break;
        }
        else
        {
            printf("INPUT ERROR!\n");
            continue;
        }
    }
    return 0;
}