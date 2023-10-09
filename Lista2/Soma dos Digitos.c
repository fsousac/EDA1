#include <stdio.h>
#include <string.h>

int somaDigitos(char *n, int tamanho)
{
    int soma = 0;
    if (tamanho > 0)
    {
        soma += n[tamanho - 1] - '0';
        soma += somaDigitos(n, tamanho - 1);
    }

    return soma;
}

int main()
{
    char n[13];
    scanf("%s", n);
    int tamanho = strlen(n);
    int resultado = somaDigitos(n, tamanho);
    printf("%d\n", resultado);
    return 0;
}