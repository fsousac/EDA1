#include <stdio.h>

#define MAX_NUM_PROIBIDOS 140000

int buscaBinaria(int *proibidos, int inicio, int fim, int alvo)
{
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (proibidos[meio] == alvo)
        {
            return 1; // O número é proibido
        }
        else if (proibidos[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return 0; // O número não é proibido
}

int main()
{
    int n;
    scanf("%d", &n);

    int proibidos[MAX_NUM_PROIBIDOS];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &proibidos[i]);
    }

    int numero;
    while (scanf("%d", &numero) != EOF)
    {
        int resultado = buscaBinaria(proibidos, 0, n - 1, numero);
        if (resultado)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }

    return 0;
}
