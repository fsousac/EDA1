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

void insertion_sortH(int *v, int l, int r, int h)
{
    for (int i = l + h; i <= r; i++)
    {
        int j = i, temp = v[i];
        for (; j >= l + h && less(temp, v[j - h]); j -= h)
        {
            v[j] = v[j - h];
        }
        v[j] = temp;
    }
}

void shell_sort(int *v, int l, int r)
{
    int h = 1;
    while (h < (r - l) / 9)
    {
        h = 3 * h + 1;
    }

    for (; h > 0; h = h / 3)
    {
        insertion_sortH(v, l, r, h);
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

    shell_sort(v, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", v[i]);
    }

    printf("%d\n", v[size - 1]);
    free(v);

    return 0;
}