#include <stdio.h>
#include <string.h>

void trocaX(char *str, int i)
{
    if (str[i] == '\0')
    {
        return;
    }
    else if (str[i] == 'x')
    {
        str[i] = 'y';
        trocaX(str, i + 1);
    }
    else
    {
        trocaX(str, i + 1);
    }
}

int main()
{
    char str[81];
    scanf("%s", str);
    int i = 0;
    trocaX(str, i);
    printf("%s\n", str);
    return 0;
}