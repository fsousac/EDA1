#include <stdio.h>
#include <string.h>

void moveXToEnd(char *str)
{

    int length = strlen(str);

    int newXIndex = 0;

    for (int i = 0; i < length; i++)
    {

        if (str[i] != 'x')
        {
            str[newXIndex] = str[i];
            newXIndex++;
        }
    }

    while (newXIndex < length)
    {
        str[newXIndex] = 'x';
        newXIndex++;
    }
}

int main()
{
    char str[101];
    scanf("%s", str);

    moveXToEnd(str);

    printf("%s\n", str);

    return 0;
}
