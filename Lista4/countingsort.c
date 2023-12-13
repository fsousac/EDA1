#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define R 10

int aux[MAX];

void countingSort(int *v, int l, int r)
{
    int i, count[R + 1];

    for (i = 0; i <= R; i++)
        count[i] = 0;
    for (i = l; i <= r; i++)
    {
        count[v[i] + 1]++;
    }
    for (i = 1; i <= R; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = l; i <= r; i++)
    {
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }

    for (i = 0; i <= r; i++)
    {
        v[i] = aux[i - l];
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

    countingSort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}