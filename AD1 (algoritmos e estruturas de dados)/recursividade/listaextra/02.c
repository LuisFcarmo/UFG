#include <stdio.h>
int size (char *palavra, int i) {
    if (palavra[i] == '\0') return i;
    size(palavra, i+1);
}
int contador = 0; 
int verifica (char *palavra, char caractere, char caractere2, int i) {
    if (i == size(palavra, 0)-1) return 0;
    if (palavra[i] == caractere && palavra[i+1] == caractere2) {
        contador++;
    }
    verifica(palavra, caractere, caractere2, i+1);
}

int main () {
    char palavra[5000];
    int qtd;
    scanf("%d", qtd);
    while (qtd--)
    {
        scanf("%[^\n]", palavra);
        verifica(palavra, 'h', 'i', 0);
        printf("%d", contador);

    }
    return 0;
}