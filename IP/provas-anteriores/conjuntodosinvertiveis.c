#include <stdio.h>
int main () {
    int numero;
    int i;
    int q;
    scanf("%d", &numero);
    for (i = 1; i <= (numero-1); i++){
        for (q = 1; q <= (numero-1); q++){
            if (i <= q && ((q*i)%numero) == 1){
                printf("(%d,%d)\n", i, q);
            }
        }
    }
    return 0;
}