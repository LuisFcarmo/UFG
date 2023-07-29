#include <stdio.h>
int main () {
    int contador,numero, i;
    numero = 120;
    i = 0;
    contador = 0;
    int listaprimos;
    int primeiro = 1;
    listaprimos = 2;
    while (1) {
    scanf("%i", &numero);
    if (numero < 2) {
        printf("Fatoracao nao e possivel para o numero %i!\n", numero);
        continue; 
    }
    if (numero > 1) {
        printf("%i = ", numero);
        break;
    }
    }
    while (numero/listaprimos != 0) {
        
        if (numero%listaprimos != 0 )
        {
            listaprimos++;
        }
        if (numero%listaprimos == 0 )
        {
            
            numero = numero/listaprimos;
            if (primeiro) {
                printf("%i", listaprimos);
                primeiro = 0;
            }
            else {
            printf(" x %i", listaprimos);
            }
        }
    }
    return 0;
}