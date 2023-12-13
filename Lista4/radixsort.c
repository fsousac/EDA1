#include <stdio.h>
#include <stdlib.h>

#define bitsbyte 8
#define bytesword 4

#define R (1 << bitsbyte)

#define digit(N, D) (((N) >> ((D) * bitsbyte)) & (R - 1))

void radixsortLSD(int *v, int l, int r)
{
    int i, w;
    int count[R + 1], aux[r - l + 1];
    for (w = 0; w < bytesword; w++)
    {
        for (i = 0; i <= R; i++)
            count[i] = 0;
        for (i = l; i <= r; i++)
        {
            count[digit(v[i], w) + 1]++;
        }
        for (i = 1; i <= R; i++)
        {
            count[i] += count[i - 1];
        }

        for (i = l; i <= r; i++)
        {
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }
        for (i = l; i <= r; i++)
        {
            v[i] = aux[i - l];
        }
    }
}

int main()
{
    int size = 0, *v;
    v = (int *)malloc(100000 * sizeof(int));
    int temp = 0;
    while (scanf("%d", &temp) != EOF)
    {
        v[size] = temp;
        size++;
    }

    radixsortLSD(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}