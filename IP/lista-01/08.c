#include <stdio.h>
int main() {
    int numero;
    int alg1, alg2, alg3, algarismofinal;
    scanf("%i", &numero);
    alg1 = (numero % 100) % 10;
    alg2 = ((numero % 100) / 10);
    alg3 = (numero / 100);
    algarismofinal = (alg1 * 100) + (alg2 * 10) + alg3 ;
    printf("%i\n", algarismofinal);
    return 0;
}