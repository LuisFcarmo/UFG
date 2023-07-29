#include <stdio.h> 
int main () {
    int contador,i, numero, acumulador, divisor, parada;
    acumulador = 0;
    divisor = 1;
    parada = 1;
    contador = 0;
    int vetordiv[200];
    scanf("%i", &numero);
    while (1)
    {   
    
        if (divisor != numero && numero%divisor == 0) {
            acumulador += divisor;
            vetordiv[contador] = divisor;
            contador++;
            divisor ++;
        }
            if (divisor != numero && numero%divisor != 0) {
            divisor ++;
        }
        if (parada == numero) {
            break;
        }
    
        parada++;
    
    }
    printf("%i = ", numero);
    for(i = 0; i <= contador; i++){
        if (i == contador-1){
            printf("%i ", vetordiv[i]);
            break;
        }
        printf("%i + ", vetordiv[i]);
    }
    printf("= %i ", acumulador);
    if (acumulador == numero) {
        printf("(NUMERO PERFEITO)");
    }
    else {
        printf("(NUMERO NAO E PERFEITO)");
    }
    
    
    return 0;
}