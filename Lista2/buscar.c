#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x)
{
    celula *c = le->prox;
    while (c != NULL && c->dado != x)
    {
        c = c->prox;
    }
    return c;
}

celula *busca_rec(celula *le, int x)
{
    if (le == NULL || le->dado == x)
    {
        return le;
    }
    else
    {
        return busca_rec(le->prox, x);
    }
}