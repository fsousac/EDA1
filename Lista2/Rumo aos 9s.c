#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grau9(char *c, int len)
{
    int sum = 0;
    if (len == 1)
    {
        if (c[0] == '9')
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {

        for (int i = 0; i < len; i++)
        {
            sum += c[i] - '0';
        }

        if (sum % 9 == 0)
        {
            char *temp[len];
            sprintf(temp, "%d", sum);
            return 1 + grau9(temp, strlen(temp));
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    char raw[1001];
    while (1)
    {
        scanf("%s", raw);
        if (raw[0] == '0' && strlen(raw) == 1)
        {
            break;
        }
        int len = strlen(raw);

        if (len == 1)
        {
            if (raw[0] == '9')
            {
                printf("9 is a multiple of 9 and has 9-degree 1.\n");
                continue;
            }
            else
            {
                printf("%s is not a multiple of 9.\n", raw);
                continue;
            }
        }
        int chamadas = grau9(raw, len);
        if (chamadas < 0)
        {
            printf("%s is not a multiple of 9.\n", raw);
        }
        else
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", raw, chamadas);
        }
    }

    return 0;
}