#include <stdio.h>
int contador = 0;

void fila_coelhos (int x) {
    if (x == 0) {
        printf("%d", contador);
        contador = 0;
        return; // caso base
    }
    if (x % 2 != 0) contador += 2;
    if (x % 2 == 0) contador += 3;
    fila_coelhos(x-1);
}

void leitura (int qtd) {
    if (qtd == 0) return; // caso base
    int numero = 0;
    scanf("%d", &numero);
    fila_coelhos(numero);

    qtd-=1;
    leitura(qtd);
}

int main () {
    int qtd;
    scanf("%d", &qtd);
    leitura(qtd);

    return 0;
}