#include <stdio.h>
int main () {
    int numero;
    int v[7];
    int i;
    int f;
    scanf("%i", &numero);
    if (numero < 0 || numero > 255) {
        printf("Numero invalido!");
    }
    else {
    for (i = 1; i <= 8; i++) {
        v[i] = numero%2 ;
        numero = numero/2;
    }
    for (i = 8; i > 0; i--) {
        printf("%d", v[i]) ;
    
    }}
    return 0;
};