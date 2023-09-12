#include <stdio.h>

int main(){
    unsigned int L,D,K,P;
    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);
    
    int valor_gas = L*K;
    int quant_ped;
    
    if (L != 0){
        quant_ped = L / D;
    } else{
        quant_ped = 0;
    }
    
    int valor_ped = quant_ped * P;
    
    int total = valor_gas + valor_ped;
    
    printf("%d\n",total);
    return 0;
}