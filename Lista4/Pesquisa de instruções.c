#include <stdio.h>
#include <string.h>

#define MAX_INSTRUCOES 100

typedef struct
{
    int codigo;
    char palavraChave[16];
} Instrucao;

int main()
{
    int n;
    scanf("%d", &n);

    Instrucao instrucoes[MAX_INSTRUCOES];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavraChave);
    }

    int codigoConsulta;
    while (scanf("%d", &codigoConsulta) != EOF)
    {
        int encontrou = 0;
        for (int i = 0; i < n; i++)
        {
            if (instrucoes[i].codigo == codigoConsulta)
            {
                printf("%s\n", instrucoes[i].palavraChave);
                encontrou = 1;
                break;
            }
        }
        if (!encontrou)
        {
            printf("undefined\n");
        }
    }

    return 0;
}
