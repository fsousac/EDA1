#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    int votos;
} Candidato;

void bubble_sort(Candidato *candidatos, int n)
{
    int trocou = 1;

    while (trocou)
    {
        trocou = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (candidatos[i].votos < candidatos[i + 1].votos ||
                (candidatos[i].votos == candidatos[i + 1].votos && candidatos[i].codigo > candidatos[i + 1].codigo))
            {
                Candidato temp = candidatos[i];
                candidatos[i] = candidatos[i + 1];
                candidatos[i + 1] = temp;
                trocou = 1;
            }
        }
    }
}

int main()
{
    int S, F, E;
    scanf("%d %d %d", &S, &F, &E);

    int presidente[100] = {0};
    Candidato *senadores = (Candidato *)malloc(S * sizeof(Candidato));
    Candidato *depFed = (Candidato *)malloc(F * sizeof(Candidato));
    Candidato *depEst = (Candidato *)malloc(E * sizeof(Candidato));

    int votosValidos = 0, votosInvalidos = 0;

    int codigo;
    while (scanf("%d", &codigo) == 1)
    {
        if (codigo >= 0)
        {
            votosValidos++;
            if (codigo < 100)
            {
                presidente[codigo]++;
            }
            else if (codigo < 1000)
            {
                senadores[codigo % 100].codigo = codigo;
                senadores[codigo % 100].votos++;
            }
            else if (codigo < 10000)
            {
                depFed[codigo % 1000].codigo = codigo;
                depFed[codigo % 1000].votos++;
            }
            else if (codigo < 100000)
            {
                depEst[codigo % 10000].codigo = codigo;
                depEst[codigo % 10000].votos++;
            }
        }
        else
        {
            votosInvalidos++;
        }
    }

    Candidato presidenteEleito = {0, 0};
    for (int i = 0; i < 100; i++)
    {
        if (presidente[i] > presidenteEleito.votos)
        {
            presidenteEleito.codigo = i;
            presidenteEleito.votos = presidente[i];
        }
    }

    bubble_sort(senadores, S);
    bubble_sort(depFed, F);
    bubble_sort(depEst, E);

    printf("%d %d\n", votosValidos, votosInvalidos);
    if ((float)presidenteEleito.votos / votosValidos < 0.51)
    {
        printf("Segundo turno\n");
    }
    else
    {
        printf("%02d\n", presidenteEleito.codigo);
    }

    for (int i = 0; i < S; i++)
    {
        printf("%d ", senadores[i].codigo);
    }
    printf("\n");

    for (int i = 0; i < F; i++)
    {
        printf("%d ", depFed[i].codigo);
    }
    printf("\n");

    for (int i = 0; i < E; i++)
    {
        printf("%d ", depEst[i].codigo);
    }
    printf("\n");

    free(senadores);
    free(depFed);
    free(depEst);

    return 0;
}
