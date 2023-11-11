#include <stdio.h>
void bin (int numero) {
    if (numero == 0)  {
        printf("%d", numero);
        return;
    }
    else if (numero == 1) {
        printf("%d", numero%2); 
        return;
    }
    else if (numero > 1) {
        bin(numero/2);
        printf("%d", numero%2);
    }
}

int main () {
    int qnumeros = 0;
    int numero = 0;
    int i = 0;
    scanf("%d", &qnumeros);
    for (i = 0; i < qnumeros; i++) {
        scanf("%d", &numero);
        bin(numero);
        printf("\n");

    }
    return 0;
}