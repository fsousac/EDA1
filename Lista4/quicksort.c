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

int separaSEDWICK(int *v, int l, int r)
{
    int c = v[r];
    int j = r, i = l - 1;
    while (i < j)
    {
        while (v[++i] < c)
            ;
        while (v[--j] >= c && j > l)
            ;
        if (i < j)
        {
            exch(v[i], v[j]);
        }
    }

    exch(v[i], v[r]);

    return i;
}

int separa(int *v, int l, int r)
{
    int c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
    {
        if (lesseq(v[k], c))
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);

    return j;
}

void quicksortS(int *v, int l, int r)
{
    if (r <= l)
    {
        return;
    }

    int c = separa(v, l, r);
    quicksortS(v, l, c - 1);
    quicksortS(v, c + 1, r);
}

void quicksort(int *v, int l, int r)
{
    if (r <= l)
    {
        return;
    }
    int m = (l + r) / 2;

    compexch(v[m], v[r]);
    compexch(v[l], v[m]);
    compexch(v[r], v[m]);

    int c = separa(v, l, r);
    quicksort(v, l, c - 1);
    quicksort(v, c + 1, r);
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

    quicksort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}