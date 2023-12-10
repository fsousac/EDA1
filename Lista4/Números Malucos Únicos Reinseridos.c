#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    qsort(vetor, n, sizeof(int), cmpfunc);

    if (n % 2 != 0)
    {
        vetor = realloc(vetor, (n + 1) * sizeof(int));
        vetor[n] = 1000000000;
        n++;
    }

    int *nmu = (int *)malloc(n / 2 * sizeof(int));
    int k = 0;

    for (int i = 0; i < n; i += 2)
    {
        nmu[k] = vetor[i] + vetor[i + 1];
        k++;
    }

    int *nmur = (int *)malloc(n * sizeof(int));
    int j = 0;

    for (int i = 0; i < nmu; i++)
    {
        if (bsearch(&nmu[i], vetor, n, sizeof(int), cmpfunc) == NULL)
        {
            nmur[j] = nmu[i];
            j++;
        }
    }

    for (int i = 0; i < n; i += 4)
    {
        printf("%d\n", nmur[i]);
    }

    printf("Elementos: %d\n", j);

    free(vetor);
    free(nmu);
    free(nmur);

    return 0;
}
