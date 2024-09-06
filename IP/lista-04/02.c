#include <stdio.h>
int main () {
    int vetornumero[1000];
    int tamanho = 0;
    int i = 0;
    int numero = 0;
    int numerobuscar = 0;
    int contador = 0;
    //aqui eu pergunto o tamanho do espaço amostral, e verifico se é um tamanho valido
    while (1)
    {   
        scanf("%d", &tamanho);
        if (tamanho >= 1 && tamanho <= 1000) {
            break;
        }
    }
    // aqui eu gravo os valores no vetor   
    for(i = 0; i < tamanho; i++){
        scanf("%d", &numero);
        vetornumero[i] = numero;
    }
    //pego o numero que deseja ser buscado no vetor e quantos numeros são maiores ou iguais a ele
    printf("\n");
    scanf("%d", &numerobuscar);
    //verifico quantos numeros são menores ou iguais aos desejados
    for (i = 0; i < tamanho; i++){
        if (vetornumero[i] >= numerobuscar ) {
            contador++;
        }
    }
    //exibo o valor
    printf("%d\n", contador);
    return 0;
}