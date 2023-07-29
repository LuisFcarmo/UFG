#include <stdio.h>
int main () {
    int vetor[1000000];
    int quantidade;
    int buscas;
    int numero;
    int k = 0;
    int i = 0;
    scanf("%d", &quantidade);
    for (i = 0; i < quantidade;i++){
        scanf("%d", &numero);
        vetor[i] = numero;
    }
    scanf("%d", &buscas);
    //quantas buscas ira fazer
    for (i = 0; i < buscas; i++){
        scanf("%d", &numero);
        for (k = 0; k < quantidade; k++){
            if (numero == vetor[k]) {
                printf("ACHEI\n");
                break;
            }
            if (k == quantidade-1){
                printf("NAO ACHEI\n");
            }
        }
    }
    return 0;
}