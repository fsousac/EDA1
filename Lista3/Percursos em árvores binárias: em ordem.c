#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Definição da estrutura do nó da árvore
typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

// Definição de uma pilha para auxiliar no percurso
typedef struct Pilha
{
    no *itens[100]; // Tamanho máximo da pilha
    int topo;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *pilha)
{
    pilha->topo = -1;
}

// Verifica se a pilha está vazia
bool pilhaVazia(Pilha *pilha)
{
    return pilha->topo == -1;
}

// Empilha um nó
void empilhar(Pilha *pilha, no *item)
{
    pilha->itens[++pilha->topo] = item;
}

// Desempilha um nó
no *desempilhar(Pilha *pilha)
{
    if (!pilhaVazia(pilha))
    {
        return pilha->itens[pilha->topo--];
    }
    return NULL;
}

// Função não recursiva para percurso em ordem
void em_ordem(no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    Pilha pilha;
    inicializarPilha(&pilha);
    no *atual = raiz;

    while (atual != NULL || !pilhaVazia(&pilha))
    {
        while (atual != NULL)
        {
            empilhar(&pilha, atual);
            atual = atual->esq;
        }

        atual = desempilhar(&pilha);
        printf("%d ", atual->dado);
        atual = atual->dir;
    }
}

// int main()
// {
//     // Exemplo de construção da árvore
//     no *raiz = (no *)malloc(sizeof(no));
//     raiz->dado = 1;
//     raiz->esq = (no *)malloc(sizeof(no));
//     raiz->esq->dado = 2;
//     raiz->esq->esq = NULL;
//     raiz->esq->dir = (no *)malloc(sizeof(no));
//     raiz->esq->dir->dado = 4;
//     raiz->esq->dir->esq = NULL;
//     raiz->esq->dir->dir = (no *)malloc(sizeof(no));
//     raiz->esq->dir->dir->dado = 5;
//     raiz->esq->dir->dir->esq = NULL;
//     raiz->esq->dir->dir->dir = NULL;
//     raiz->dir = (no *)malloc(sizeof(no));
//     raiz->dir->dado = 3;
//     raiz->dir->esq = NULL;
//     raiz->dir->dir = (no *)malloc(sizeof(no));
//     raiz->dir->dir->dado = 6;
//     raiz->dir->dir->esq = NULL;
//     raiz->dir->dir->dir = (no *)malloc(sizeof(no));
//     raiz->dir->dir->dir->dado = 7;
//     raiz->dir->dir->dir->esq = NULL;
//     raiz->dir->dir->dir->dir = (no *)malloc(sizeof(no));
//     raiz->dir->dir->dir->dir->dado = 8;
//     raiz->dir->dir->dir->dir->esq = NULL;
//     raiz->dir->dir->dir->dir->dir = (no *)malloc(sizeof(no));
//     raiz->dir->dir->dir->dir->dir->dado = 9;
//     raiz->dir->dir->dir->dir->dir->esq = NULL;
//     raiz->dir->dir->dir->dir->dir->dir = NULL;

//     // Chamando a função de percurso em ordem
//     em_ordem(raiz);
//     printf("\n");

//     // Liberando a memória alocada
//     free(raiz->esq->dir->dir);
//     free(raiz->esq->dir);
//     free(raiz->esq);
//     free(raiz->dir->dir->dir->dir->dir);
//     free(raiz->dir->dir->dir->dir);
//     free(raiz->dir->dir->dir);
//     free(raiz->dir->dir);
//     free(raiz->dir);
//     free(raiz);

//     return 0;
// }
