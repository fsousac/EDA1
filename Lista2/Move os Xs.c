#include <stdio.h>
#include <string.h>

void moveXToEnd(char *str, int len, int i)
{
    if (i < len)
    {
        if (str[i] == 'x')
        {
            memmove(str + i, str + i + 1, len - i);
            str[len - 1] = 'x';
            moveXToEnd(str, len - 1, i);
        }
        else
        {
            moveXToEnd(str, len, i + 1);
        }
    }
}

int main()
{
    char str[1001];
    scanf("%s", str);

    int len = strlen(str);

    moveXToEnd(str, len, 0);

    printf("%s\n", str);

    return 0;
}
