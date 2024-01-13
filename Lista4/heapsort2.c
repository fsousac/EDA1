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

void fixDown(int *pq, int k, int N)
{
    while (2 * k <= N)
    {
        int j = 2 * k;
        if (j < N && pq[j] < pq[j + 1])
        {
            j++;
        }

        if (less(pq[k], pq[j]))
        {
            exch(pq[j], pq[k])
        }
        else
        {
            break;
        }
        k = j;
    }
}

void heapsort(int *v, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int size = r - l + 1;
    int *pq = v + l - 1;
    for (int i = size / 2; i > 0; i--)
    {
        fixDown(pq, i, size);
    }

    exch(pq[1], pq[size]);
    heapsort(v, l, r - 1);
}