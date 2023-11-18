#include <stdio.h>
#include <stdlib.h>
#define less(a, b) (a < b)
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

void insertion_sort(int *v, int l, int r)
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

    insertion_sort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}