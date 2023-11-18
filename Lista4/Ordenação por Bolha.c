#include <stdio.h>
#include <stdlib.h>
#define less(a, b) (a < b)
#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void bubbleSort(int *v, int l, int r)
{
    int ord = 1;
    if (l >= r)
    {
        return;
    }
    for (int i = l; i < r; i++)
    {
        if (less(v[i + 1], v[i]))
        {
            exch(v[i + 1], v[i]);
            ord = 0;
        }
    }
    if (ord == 1)
    {
        return;
    }

    bubbleSort(v, l, r - 1);
}

int main()
{
    int size = 0, *v, temp;
    v = (int *)malloc(100000 * sizeof(int));
    while (scanf("%d", &temp) != EOF)
    {
        v[size] = temp;
        size++;
    }

    bubbleSort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}