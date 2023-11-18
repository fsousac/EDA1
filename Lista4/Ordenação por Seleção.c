#include <stdio.h>
#include <stdlib.h>
#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
#define less(a, b) (a < b)

void selectionSort(int *v, int l, int r)
{
    int min = l;
    int max = r;
    int aux = v[min];
    if (l >= r)
    {
        return;
    }
    for (int i = min + 1; i <= max; i++)
    {
        if (less(v[i], aux))
        {
            exch(v[i], aux);
        }
    }
    v[min] = aux;
    selectionSort(v, l + 1, r);
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

    selectionSort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}