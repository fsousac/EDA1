#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

static int checkpoint = 0;

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

void quicksort(int *v, int l, int r, int maxrec)
{
    if (maxrec == 0 || checkpoint == 1)
    {
        checkpoint = 1;
        return;
    }

    if (r - l <= 32)
    {
        return;
    }
    exch(v[(l + r) / 2], v[r - 1]);
    int ult = r - 1;
    compexch(v[ult], v[r]);
    compexch(v[l], v[ult]);
    compexch(v[r], v[ult]);

    int j = separa(v, l + 1, r - 1);
    quicksort(v, l, j - 1, maxrec - 1);
    quicksort(v, j + 1, r, maxrec - 1);
}

void fixDown(int *pq, int k, int N)
{
    int j;
    while (2 * k <= N)
    {
        j = 2 * k;

        if (j < N && less(pq[j], pq[j + 1]))
        {
            j++;
        }

        if (!less(pq[k], pq[j]))
        {
            break;
        }

        exch(pq[k], pq[j]);
        k = j;
    }
}

void heapsort(int *v, int l, int r)
{
    int *pq = v + l - 1;
    int N = r - l + 1;
    for (int k = N / 2; k >= 1; k--)
    {
        fixDown(pq, k, N);
    }
    while (N > 1)
    {
        exch(pq[1], pq[N]);
        fixDown(pq, 1, --N);
    }
}

void introsort(int *v, int l, int r)
{
    double number = r - l + 1;
    double logged = log2(number);
    int maxrec = 2 * logged;
    quicksort(v, l, r, maxrec);
    if (checkpoint == 1)
    {
        heapsort(v, l, r);
    }
    else
    {
        insertionsort(v, l, r);
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

    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}