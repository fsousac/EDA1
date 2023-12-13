#include <stdio.h>
#include <stdlib.h>
#define less(A, B) (A < B)
#define exch(A, B)    \
    {                 \
        Item aux = A; \
        A = B;        \
        B = aux;      \
    }

typedef int Item;

void fixDown(Item *pq, int k, int N)
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

void heapsort(Item *v, int l, int r)
{
    Item *pq = v + l - 1;
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

int main()
{
    int v[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    heapsort(v, 0, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d\n", v[9]);
    return 0;
}