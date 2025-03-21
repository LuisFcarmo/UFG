#include <stdio.h>
int acumulador = 0;
int soma(int qtd) {
    if (qtd == 0) return 1;
    int numero;
    scanf("%d%*c", &numero);
    acumulador += numero;
    qtd--;
    soma(qtd);
}
int main () {
    int qtd;
    scanf("%d%*c", &qtd);
    soma(qtd);
    printf("%d", acumulador);

    return 0;
}