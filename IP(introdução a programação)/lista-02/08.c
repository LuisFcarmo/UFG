#include <stdio.h>
int main () {
    int contador1;
    int contador2; 
    int quantidadep;
    int quantiaefinais;
    quantiaefinais = 0;
    scanf("%d", &quantidadep);
    if (quantidadep < 2) {
        printf("Campeonato invalido!");
        return 0;
    }
    for (contador1 = 1; contador1 < quantidadep; contador1++) { // esse contador percorre do 1 ate o penultimo numero limite
        for (contador2 =contador1+1; contador2 <= quantidadep; contador2++){ // esse percore até o limite mas não conta o numero do primeiro for
            quantiaefinais++;
            printf("Final %i: Time%i X Time%i\n", quantiaefinais, contador1, contador2);
        }
    }
    
    return 0;
}