#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x)
{
    celula *novoNo = (celula *)malloc(sizeof(celula));
    if (novoNo == NULL)
    {
        return NULL; // Retornar NULL em caso de falha na alocação de memória
    }

    novoNo->dado = x;
    novoNo->prox = NULL;

    if (f == NULL)
    {
        // Se a fila estiver vazia, o novo nó se torna a cabeça da fila
        return novoNo;
    }

    celula *temp = f;
    while (temp->prox != NULL)
    {
        temp = temp->prox;
    }

    temp->prox = novoNo; // Adiciona o novo nó no final da fila
    return f;            // Retorna a cabeça da fila
}