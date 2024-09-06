#include <stdio.h> 
int main () {
    int numero;
    int i;
    int quadrado;
    scanf("%d", &numero);
        for (i = 2; i <= numero; i += 2) {
            if ((i%2) == 0){
                quadrado = i*i;
                printf("%d^2 = %d\n", i, quadrado);
            }
        }
    
    return 0;
}