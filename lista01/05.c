#include <stdio.h>
int main () {
    double numero;
    double numero2;
    double numero3;

    scanf ("%lf", &numero);
    scanf ("%lf", &numero2);
    scanf ("%lf", &numero3);

    float vetor[3];
    int contador;
    float auxiliar;
    int i;
    vetor[0] = numero;
    vetor[1] = numero2;
    vetor[2] = numero3;
    for (contador = 0; contador <= 2; contador++) {
        for (  i = 0; i <= 1; i++)
        {
            if (vetor[i] > vetor[i+1]){
            auxiliar = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = auxiliar;
            }

        }
    }
    printf("%.2lf, %.2lf, %.2lf", vetor[0], vetor[1], vetor[2]);
    return 0;
}


