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

int partition(int *v, int l, int r)
{
    int j = l;
    int pivo = v[r];
    for (int k = l; k < r; k++)
    {
        if (lesseq(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quicksort3M(int *v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (r - l) / 2;
    compexch(v[m], v[r]);
    compexch(v[l], v[m]);
    compexch(v[r], v[m]);

    int choseOne = partition(v, l, r);
    quicksort3M(v, l, choseOne - 1);
    quicksort3M(v, choseOne + 1, r);
}