#include <stdio.h>
#include <stdlib.h>

void swap(int *vetor, int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux; 
}

int separa(int *vetor, int inicio, int fim) {
    int pivo, pivo_indice, i;
    pivo_indice = inicio;
    pivo = vetor[fim];

    for (i = inicio; i < fim; i++) {
        if (vetor[i] <= pivo) {
            swap(vetor, i, pivo_indice);
            pivo_indice++;
        }
    }
    swap(vetor, pivo_indice, fim);
    return pivo_indice;
}

int separa_aleatorio (int *vetor, int inicio, int fim) {
    int pivo_indice = (rand () % (fim - inicio) + 1) + inicio;
    swap(vetor, pivo_indice, fim);

    return separa(vetor, inicio, fim);
}

void quicksort_Hoare(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = separa_aleatorio(vetor, inicio, fim);
        quicksort_Hoare(vetor, inicio, pivo-1);
        quicksort_Hoare(vetor, pivo+1, fim);
    }
}

void imprimir(int *vetor, int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        printf("%d -", vetor[i]);
    }
}

int main () {
    int qtd;
    int *vetor;
    scanf("%d%*c", &qtd);
    vetor = (int*) malloc(qtd*sizeof(int));
    for (int i = 0; i < qtd; i++) {
        scanf("%d%*c", &vetor[i]);
    }

    quicksort_Hoare(vetor, 0, qtd-1);
    imprimir(vetor, 0, qtd);
    free(vetor);

}