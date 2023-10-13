#include <stdio.h>
#include <string.h>

int pares(char *str, int i)
{
    int len = strlen(str);
    if (str[i] == '\0')
    {
        return 0;
    }
    else if (i + 2 < len && str[i] == str[i + 2])
    {
        return 1 + pares(str, i + 1);
    }
    else
    {
        return 0 + pares(str, i + 1);
    }
}

int main()
{
    char str[201];
    scanf("%s", str);
    int i = 0;
    int resposta = pares(str, i);
    printf("%d\n", resposta);
    return 0;
}