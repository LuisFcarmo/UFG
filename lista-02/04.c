#include <stdio.h> 
int main (){
    int numero;
    double acumulador;
    int i;
    acumulador = 0;
    scanf("%d", &numero);
    if (numero <= 1) {
        printf("Numero invalido!");
        return 0;
    }
    for (i = 1; i <= numero; i++) {
        acumulador += 1.0/i;
    }
    printf("%.6lf", acumulador);
    return 0;
}