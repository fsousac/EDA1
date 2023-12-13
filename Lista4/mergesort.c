#include <stdio.h>
#include <stdlib.h>
#define less(a, b) (a < b)
#define lesseq(a, b) (a <= b)
#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
#define compexch(a, b)  \
    {                   \
        if (less(b, a)) \
            exch(a, b); \
    }

void merge(int *v, int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *aux = malloc((sizeof(int)) * (r - l + 1));
    while (i <= m && j <= r)
    {
        if (v[i] < v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        aux[k] = v[i];
        i++;
    }
    while (j <= r)
    {
        aux[k] = v[j];
        j++;
    }
    k = 0;
    for (i = l; i < r; i++)
    {
        v[i] = aux[k];
        k++;
    }

    free(aux);
}

void mergesort(int *v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (r + l) / 2;
    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}