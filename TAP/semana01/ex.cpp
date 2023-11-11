#include <stdio.h>
int main () {
    int qtd; 
    int dificuldade = 0;
    int valor = 0;
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        scanf("%d", &valor);
        if (valor == 1) { dificuldade = 1;}
    }
    if (dificuldade == 1) {printf("HARD");}
    else {printf("EASY");}


    return 0;
}