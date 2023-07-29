#include <stdio.h>
int fibo (int numero1, int numero2, int quantidadedasequencia) {
    int fibonacci;
    int contador = 2;
        while (1)
    {
        if (contador == quantidadedasequencia ) {
            break;
        }
        fibonacci = numero1 + numero2;
        numero1 = numero2;
        numero2 = fibonacci;
        contador++;
    }
    
    return fibonacci;
}
int main () {
    int numero1;
    int numero2;
    int quantidadenasequencia;
    scanf("%i %i %i", &numero1, &numero2, &quantidadenasequencia);
    printf("%i\n", fibo(numero1, numero2, quantidadenasequencia));
    return 0;
}