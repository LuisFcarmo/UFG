#include <stdio.h>
int todosdivisores (int numero) {
    int contador = 1;
    int divisores = 0;
    printf("%i = ", numero);
    while (1) {
        if (numero == contador) {
            break;
        }
        if (numero % contador == 0 && contador == 1) {
            printf("%i ", contador);
            divisores += contador;
    
        }
        if (numero % contador == 0 && contador >= 2) {
            printf("+ %i ", contador);
            divisores += contador;
    
        }
        contador++;
    }
    return divisores;
}
    
    
int main () {
    int numero;
    int divisores;
    scanf("%i", &numero);
    divisores = todosdivisores(numero);
    printf("= %i", divisores);
    if (numero == divisores) {
        printf(" (NUMERO PERFEITO)");
    }
    else {
        printf(" (NUMERO NAO E PERFEITO)");
    }
    
    
    return 0;
}