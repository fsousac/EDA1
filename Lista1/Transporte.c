#include <stdio.h>

int main()
{
    int A, B, C, X, Y, Z;

    // Leitura das dimensões dos contêineres e do navio
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);

    // Calcula quantos contêineres podem ser colocados em cada dimensão
    int cont_x = X / A;
    int cont_y = Y / B;
    int cont_z = Z / C;

    // O número máximo de contêineres é o menor entre as três dimensões
    int max_containers = cont_x * cont_y * cont_z;

    // Imprime o resultado
    printf("%d\n", max_containers);

    return 0;
}