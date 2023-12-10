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
static Item *pq;
static int N;

void initPQ(int maxN)
{
    pq = malloc(sizeof(Item) * (maxN + 1));
    N = 0;
}

int isEmptyQueue()
{
    return N == 0;
}

void fixUp(int k)
{
    while (k > 1 && less(pq[k / 2], pq[k]))
    {
        exch(pq[k], pq[k / 2]);
        k = k / 2;
    }
}

void insertPQ(Item v)
{
    pq[++N] = v;
    fixUp(N);
}

Item peekPQ()
{
    return pq[N];
}

void printPQ()
{
    if (isEmptyQueue())
    {
        printf("A fila está vazia\n");
    }
    else
    {
        for (int i = 1; i < N; i++)
        {
            printf("%d, ", pq[i]);
        }
        printf("%d\n", pq[N]);
    }
}

void fixDown(int k, int N)
{
    int j;
    while (2 * k <= N)
    {
        j = 2 * k;

        if (j > N && less(pq[j], pq[j + 1]))
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

int removePQ()
{
    exch(pq[1], pq[N]);
    fixDown(1, --N);
    return pq[N];
}

void changePQ(int k, int value)
{
    if (pq[k] < value)
    {
        pq[k] = value;
        fixUp(k);
    }
    else
    {
        pq[k] = value;
        fixDown(k, N);
    }
}

int main()
{
    initPQ(1000);
    printPQ();
    insertPQ(3);
    insertPQ(2);
    insertPQ(1);
    insertPQ(5);
    insertPQ(10);
    printPQ();
    removePQ();
    removePQ();
    printPQ();
    return 0;
}