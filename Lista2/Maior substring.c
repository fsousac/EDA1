#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoCad(int *indices, int count, int tamanhoSub)
{

    if (count == 0)
    {
        return 0;
    }
    else if (indices[1] == NULL)
    {
        return tamanhoSub;
    }
    else
    {
        return (indices[count - 1] - indices[0]) + tamanhoSub;
    }
}

int verificaCad(char *cadeia, char *subcadeia, int posicaoCad, int posicaoSub)
{

    if (subcadeia[posicaoSub] == '\0')
    {
        return 1;
    }
    else if (subcadeia[posicaoSub] == cadeia[posicaoCad])
    {
        return verificaCad(cadeia, subcadeia, posicaoCad + 1, posicaoSub + 1);
    }
    else
    {
        return 0;
    }
}

int encontrarSub(char *cadeia, char *subcadeia, int posicaoCad, int *indices, int count)
{

    if (cadeia[posicaoCad] == '\0')
    {
        return count; // Retorna o total de subcadeias encontradas
    }
    else if (cadeia[posicaoCad] == subcadeia[0] && verificaCad(cadeia, subcadeia, posicaoCad, 0))
    {
        indices[count] = posicaoCad;
        count++;
    }
    return encontrarSub(cadeia, subcadeia, posicaoCad + 1, indices, count);
}

int main()
{
    char cad[1001];
    char sub[1000];
    int indices[1000]; // Supõe que não haverá mais de 1000 ocorrências

    scanf("%s", cad);
    scanf("%s", sub);

    int count = encontrarSub(cad, sub, 0, indices, 0);
    int resultado = tamanhoCad(indices, count, strlen(sub));

    printf("%d\n", resultado);

    return 0;
}