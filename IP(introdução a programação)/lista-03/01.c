#include <stdio.h>
double fat( unsigned int numero, double *acumulador){
    int contador = 1;
    *acumulador = numero;
    while (1) {
        if (contador == numero) {
            break;
        }
        *acumulador = *acumulador*(numero-contador);
        contador++;
    }
};
    
int main () {
    double acumulador;
    int numero;
    scanf("%i", &numero);
    if (numero == 0){
        printf("%i! = 1\n",numero);
        return 0;
    
    }
    fat(numero, &acumulador);
    printf("%i! = %.0lf\n",numero , acumulador);
    return 0;
}