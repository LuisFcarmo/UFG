#include <stdio.h>
int main () {
    int vetoramostral[1000000];
    int tamanho;
    int i, q;
    int valor;
    double mediana;
    int indice;
    int auxiliar;
    scanf("%d", &tamanho);
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &valor);
        vetoramostral[i] = valor;
    }
    
    for ( i = 0; i < tamanho; i++){ // algoritmo de ordenação bubble sort 
        for( q = 0 ; q < tamanho-1; q++){
        if(vetoramostral[q] > vetoramostral[q+1]){ // compara o primeiro indice do vetor e troca se for menor
            auxiliar = vetoramostral[q]; // feito em dois for porque precisa rodar isso para cada numero do for
            vetoramostral[q] = vetoramostral[q+1];
            vetoramostral[q+1] = auxiliar;}
        }
    }
    
    if (tamanho%2 == 0) {
        indice = tamanho/2;
        mediana = (vetoramostral[indice] + vetoramostral[indice-1])/(double)2;
    }else {
        indice = tamanho/2;
        mediana = vetoramostral[indice];
    }
    printf("%.2lf", mediana);
    
    return 0;
}