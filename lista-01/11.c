#include <stdio.h>
int main () {
    float numero;
    float numero2;
    float numero3;
    float numero4;
    scanf ("%f", &numero);
    scanf ("%f", &numero2);
    scanf ("%f", &numero3);
    scanf ("%f", &numero4);
    
    float vetor[4];
    int contador;
    float auxiliar;
    int i;
    vetor[0] = numero;
    vetor[1] = numero2;
    vetor[2] = numero3;
    vetor[3] = numero4;
    for (contador = 0; contador <= 3; contador++) {
        for (  i = 0; i <= 2; i++)
        {
            if (vetor[i] > vetor[i+1]){
            auxiliar = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = auxiliar;
            }
    
        }
    }
    printf("%.2f, %.2f, %.2f, %.2f", vetor[0], vetor[1], vetor[2], vetor[3]);
    return 0;
}