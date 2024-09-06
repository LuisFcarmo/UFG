#include <stdio.h>
int main () {
    int numero;
    int numerog;
    int crescente = 0;
    int i =0;
    int temporaria;
    scanf("%d", &numero);
    int vetorl[numero];
    for (i = 1; i <= numero; i++){
        scanf("%d", &numerog);
        vetorl[i] = numerog;
    }
    for (i = 1; i <= numero; i++){
        if (vetorl[i] < vetorl[i+1]){
            crescente++;
            temporaria = crescente;
        }
        if (vetorl[i] > vetorl[i+1]) {
            crescente = 1;
            if (temporaria < crescente) {
            temporaria = crescente;
        }
        }
        
    }
    printf("O comprimento do segmento crescente maximo e: %i", temporaria);
    
    return 0;
}