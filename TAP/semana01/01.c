#include <stdio.h>
int main () {
    int quantidade = 0;
    int valor = 0;
    int index = 0;
    int maior = 0;
    int aux = 0;
    scanf("%d", &quantidade);
    quantidade++;
    int vetor[quantidade];

    for (int i = 0; i < quantidade; i++) {
        vetor[i] = 0;
    }   

    for(int c = 1; c < quantidade; c++)
    {
        scanf("%d", &valor);
        

        for (int i = 0; i < c; i++) {
            vetor[i] = (vetor[i]+valor)%360;
        }
        
    }
      
    for (int i = 0; i < quantidade; i++) {
        for (int k = 0; k < quantidade; k++) {
            if (vetor[i] < vetor[k]) {
                aux = vetor[k];
                vetor[k] = vetor[i];
                vetor[i] = aux;
            }
        }
    }


    for (int i = 0; i < quantidade-1; i++) {
        if (maior < vetor[i+1]-vetor[i]) {
            maior = vetor[i+1]-vetor[i];
        }
    }
    if (maior < 360-vetor[quantidade-1]) {
        maior = 360-vetor[quantidade-1];
    };

  
    printf("%d", maior);
    return 0;
}