#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (f->u == f->N - 1)
    {
        int novoTamanho = f->N * 2; // Dobrar o tamanho do vetor
        int *novoDados = (int *)malloc(sizeof(int) * novoTamanho);

        if (novoDados == NULL)
        {
            return 0; // Falha na alocação de memória
        }

        for (int i = f->p; i <= f->u; i++)
        {
            novoDados[i - f->p] = f->dados[i]; // Copia os elementos para o novo vetor
        }

        free(f->dados);
        f->dados = novoDados;
        f->N = novoTamanho;
        f->u = f->u - f->p; // Atualiza os índices
        f->p = 0;
    }

    f->u++;
    f->dados[f->u] = x;
    return 1; // Inserção bem-sucedida
}