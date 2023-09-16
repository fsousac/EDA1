#include <stdio.h>

int main()
{
    int cartas[5], temp;
    int aux = 0;

    scanf("%d %d %d %d %d", &cartas[0], &cartas[1], &cartas[2], &cartas[3], &cartas[4]);

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            temp = cartas[i];
            continue;
        }
        else
        {
            if (temp < cartas[i])
            {
                temp = cartas[i];
                aux++;
            }
            else if (temp > cartas[i])
            {
                temp = cartas[i];
                aux--;
            }
            else
            {
                printf("N\n");
                return 0;
            }
        }
    }

    if (aux == 4)
    {
        printf("C\n");
    }
    else if (aux == -4)
    {
        printf("D\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}