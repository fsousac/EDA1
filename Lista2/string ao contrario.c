#include <stdio.h>
#include <string.h>

char *inverte(char *str)
{
    static char strInvertida[501];
    static int i = 0;
    int len = strlen(str);
    if (len == 0)
    {
        return strInvertida;
    }
    else
    {
        strInvertida[i] = str[len - 1];
        str[len - 1] = '\0';
        i++;
        inverte(str);
    }
}

int main()
{
    char str[501];
    scanf("%s", str);
    char *strInvertida;
    strInvertida = inverte(str);
    printf("%s\n", strInvertida);
    return 0;
}