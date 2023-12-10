#include <stdio.h>
#include <stdlib.h>
#define less(A, B) ((A) < (B))

void merge(int *v, int l, int m, int r2)
{
    int k = 0, i = l, j = m + 1;
    int *v2 = (int *)malloc(sizeof(int) * (r2 - l + 1));
    while (i <= m && j <= r2)
    {
        if (less(v[i], v[j]))
        {
            v2[k++] = v[i++];
        }
        else
        {
            v2[k++] = v[j++];
        }
    }
    while (i <= m)
    {
        v2[k++] = v[i++];
    }
    while (j <= r2)
    {
        v2[k++] = v[j++];
    }

    k = 0;
    for (i = l; i <= r2; i++)
    {
        v[i] = v2[k++];
    }
    free(v2);
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}

int main()
{
    int size, i, *v;
    scanf("%d", &size);
    v = (int *)malloc(size * sizeof(int));
    int temp = 0;
    while (scanf("%d", &temp) != EOF)
    {
        v[i++] = temp;
    }

    merge_sort(v, 0, size - 1);
    for (i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}