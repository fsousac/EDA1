#include <stdio.h>

int buscaBinaria(int *conjunto, int tamanho, int alvo)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (conjunto[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else if (conjunto[meio] > alvo)
        {
            fim = meio - 1;
        }
        else
        {
            return meio + 1; // O índice deve ser 1-based, conforme a descrição do problema
        }
    }

    return inicio;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int conjunto[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &conjunto[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int alvo;
        scanf("%d", &alvo);

        int indice = buscaBinaria(conjunto, n, alvo);
        printf("%d\n", indice);
    }

    return 0;
}
