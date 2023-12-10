#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void conta(char s[])
{
    if (strlen(s) == 1)
    {
        printf("1 %c 0\n", s[0]);
        return;
    }
    for (int i = 0; i < strlen(s);)
    {
        char c = s[i];
        int count = 1;
        int j = i + 1;
        for (; s[j] == c; j++)
        {
            count++;
        }
        printf("%d %c %d\n", count, c, i);
        i = j;
    }
}

int main()
{
    char string[100001];
    scanf("%s", string);
    conta(string);
    return 0;
}