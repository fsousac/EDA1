#include <stdio.h>

void insereOrdenado(int *v, int n)
{
    if (n <= 1)
    {
        return; // Caso base: vetor com 0 ou 1 elemento já está ordenado
    }

    // Chama recursivamente para os n-1 elementos
    insereOrdenado(v, n - 1);

    int elementoAtual = v[n - 1];
    int j = n - 2;

    // Move os elementos maiores que o elementoAtual para a direita
    while (j >= 0 && v[j] > elementoAtual)
    {
        v[j + 1] = v[j];
        j--;
    }

    // Insere o elementoAtual na posição correta
    v[j + 1] = elementoAtual;
}

void ordena(int *v, int n)
{
    if (n <= 1)
    {
        return; // Caso base: vetor com 0 ou 1 elemento já está ordenado
    }

    // Chama a função auxiliar que insere o último elemento na posição correta
    insereOrdenado(v, n);

    // Chama recursivamente para os n-1 elementos restantes
    ordena(v, n - 1);
}

// Exemplo de uso
int main()
{
    int vetor[] = {5, 2, 7, 1, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    ordena(vetor, tamanho);

    // Imprime o vetor ordenado
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}
