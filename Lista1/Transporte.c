#include <stdio.h>

int main()
{
    unsigned int comp_cont, larg_cont, alt_cont, comp_navio, larg_navio, alt_navio, quant_cont;
    scanf("%d %d %d", &comp_cont, &larg_cont, &alt_cont);
    scanf("%d %d %d", &comp_navio, &larg_navio, &alt_navio);
    int area_base = comp_navio * larg_navio;
    int area_cont = comp_cont * larg_cont;
    int area_andar = area_base / area_cont;
    int num_andar = alt_navio / alt_cont;
    quant_cont = area_andar * num_andar;

    printf("%d\n", quant_cont);
}