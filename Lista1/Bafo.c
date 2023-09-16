#include <stdio.h>

int main()
{
    int R, count = 0;
    int A, B, total_A, total_B;
    do
    {
        scanf("%d", &R);
        count++;
        for (int i = 0; i < R; i++)
        {
            scanf("%d %d", &A, &B);
            if (A > B)
            {
                total_A += A;
            }
            else if (A < B)
            {
                total_B += B;
            }
        }

        if (total_A > total_B && R > 0)
        {
            printf("Teste %d\nAldo\n", count);
        }
        else if (total_A < total_B && R > 0)
        {
            printf("Teste %d\nBeto\n", count);
        }

    } while (R > 0);

    return 0;
}