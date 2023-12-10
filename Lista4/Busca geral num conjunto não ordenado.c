#include <stdio.h>

int buscaGeral(int *conjunto, int tamanho, int alvo)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (conjunto[i] == alvo)
        {
            return i + 1; // O índice deve ser 1-based, conforme a descrição do problema
        }
    }

    return -1;
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

        int posicao = buscaGeral(conjunto, n, alvo);
        printf("%d\n", posicao);
    }

    return 0;
}
