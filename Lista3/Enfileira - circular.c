#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (f->u == f->N)
    {
        f->N++;
        f->dados = realloc(f->dados, sizeof(int) * f->N);
    }
    f->dados[f->u] = x;
    f->u++;
    return 1;
}

// int main()
// {
//     fila minhaFila;
//     minhaFila.dados = (int *)malloc(sizeof(int) * 5); // Tamanho inicial
//     minhaFila.N = 5;
//     minhaFila.p = 0;
//     minhaFila.u = 0;

//     enfileira(&minhaFila, 10);
//     enfileira(&minhaFila, 20);
//     enfileira(&minhaFila, 30);
//     enfileira(&minhaFila, 40);
//     enfileira(&minhaFila, 50);
//     enfileira(&minhaFila, 60);
//     enfileira(&minhaFila, 70);
//     for (int i = 0; i < minhaFila.N; i++)
//     {
//         printf("%d\n", minhaFila.dados[i]);
//     }

//     free(minhaFila.dados);

//     return 0;
// }