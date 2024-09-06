#include <stdio.h>
#include <stdlib.h>
int acumulador = 0;

void somarecursiva (int *vetor, int tamanho, int i) {
    if (i == tamanho) {
        printf("soma total = (%d)\n", acumulador);
        acumulador = 0;
        return;
    }
    acumulador += vetor[i];
    somarecursiva(vetor, tamanho, i+1);
}

void preenche (int *vetor, int tamanho, int i) {
    if (i == tamanho) {
        return somarecursiva(vetor, tamanho, 0);
    }
}
void leitura (int qtd) {
    if (qtd == 0) return;
    int tamanho;
    int *vetor;

    scanf("%d", &tamanho);
    vetor = (int *) malloc(sizeof(int)*tamanho);
    
    preenche(vetor, tamanho, 0);
    qtd--;
    leitura(qtd);
}
int main () {
    int qtd;
    scanf("%d", &qtd);
    leitura(qtd);
    return 0;
}