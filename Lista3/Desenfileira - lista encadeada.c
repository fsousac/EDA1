#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{
    if (f == NULL || f->prox == NULL)
    {
        return 0;
    }

    celula *aux = f->prox;
    *y = aux->dado;
    f->prox = aux->prox;
    free(aux);
    return 1;
}