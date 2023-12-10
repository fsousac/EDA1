#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 80

typedef struct
{
    char japones[MAX_PALAVRA];
    char portugues[MAX_PALAVRA];
} Traducao;

void traduz_letra(Traducao *dicionario, int M, char **letra, int N)
{
    for (int i = 0; i < N; i++)
    {
        char *linha = letra[i];
        char *token = strtok(linha, " ");

        while (token != NULL)
        {
            for (int j = 0; j < M; j++)
            {
                if (strcmp(token, dicionario[j].japones) == 0)
                {
                    printf("%s ", dicionario[j].portugues);
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        Traducao *dicionario = (Traducao *)malloc(M * sizeof(Traducao));

        for (int i = 0; i < M; i++)
        {
            scanf("%s", dicionario[i].japones);
            scanf("%s", dicionario[i].portugues);
        }

        char **letra = (char **)malloc(N * sizeof(char *));
        for (int i = 0; i < N; i++)
        {
            letra[i] = (char *)malloc(MAX_PALAVRA * sizeof(char));
            scanf(" %[^\n]", letra[i]);
        }

        traduz_letra(dicionario, M, letra, N);

        if (t != T - 1)
        {
            printf("\n");
        }

        free(dicionario);
        for (int i = 0; i < N; i++)
        {
            free(letra[i]);
        }
        free(letra);
    }

    return 0;
}
