#include <stdio.h>
#include <stdlib.h>

typedef char Item;
#define maxstring 101
#define bitsbyte 8
#define R (1 << bitsbyte)

int charAt(char s[], int d)
{
    if (d < strlen(s))
        return s[d];
    else
        return -1;
}

void radixMSD(char a[][maxstring], int l, int r, int d)
{
    if (r <= l)
        return;
    char aux[r - l + 1][maxstring];

    int count[R + 1];
    for (int i = 0; i <= R; i++)
        count[i] = 0;

    for (int i = l; i <= r; i++)
        count[charAt(a[i], d) + 1]++;

    for (int i = 1; i <= R; i++)
        count[i] += count[i - 1];

    for (int i = l; i <= r; i++)
        strcpy(aux[count[charAt(a[i], d)]++], a[i]);

    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]);

    for (int i = 1; i <= R; i++)
    {
        radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);
    }
}
