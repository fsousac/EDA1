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

void insertionsort(int *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        compexch(v[i - 1], v[i]);
    }

    for (int i = l + 2; i <= r; i++)
    {
        int j = i, temp = v[j];
        while (less(temp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
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

int partition(int *v, int l, int r)
{
    int j = l;
    int pivo = v[r];
    for (int k = l; k < r; k++)
    {
        if (lesseq(v[k], pivo))
        {
            exch(v[j], v[k]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void introsort(int *v, int l, int r, int maxrec)
{
    if (l >= r)
    {
        return;
    }
    if ((r - l + 1) < 32)
    {
        insertionsort(v, l, r);
    }
    else if (maxrec == 0)
    {
        heapsort(v, l, r);
    }
    else
    {
        int m = (r + l) / 2;
        compexch(v[m], v[r]);
        compexch(v[l], v[m]);
        compexch(v[r], v[m]);

        int pivo = partition(v, l, r);
        introsort(v, l, pivo - 1, --maxrec);
        introsort(v, pivo + 1, r, --maxrec);
    }
}
