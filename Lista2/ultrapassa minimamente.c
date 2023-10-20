#include <stdio.h>
#include <stdlib.h>

int *novaLista = NULL;

int calcUltrapassa(int *input, int maximo, int tamanho)
{
    int count = 0;
    int resultado = 0;
    for (int i = 0; i < tamanho; i++)
    {
        resultado += input[i];
        if (resultado > maximo)
        {
            novaLista = realloc(novaLista, (count + 1) * sizeof(int));
            novaLista[count] = input[i];
            count++;
            resultado = 0;
        }
    }
    return count;
}

int main()
{
    int *lista = NULL;
    int num, count = 0;
    int limSoma;

    do
    {
        scanf("%d", &num);
        if (num != 0)
        {
            lista = realloc(lista, (count + 1) * sizeof(int));
            lista[count] = num;
            count++;
        }
    } while (num != 0);
    scanf("%d", &limSoma);

    int contador = calcUltrapassa(lista, limSoma, count);

    for (int i = contador - 1; i >= 0; i--)
    {
        printf("%d\n", novaLista[i]);
    }

    return 0;
}