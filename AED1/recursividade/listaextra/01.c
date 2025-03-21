#include <stdio.h>
int size (char *palavra, int i) {
    if (palavra[i] == '\0') return i;
    size(palavra, i+1);
}
int contador = 0; 
int verifica (char *palavra, char caractere, int i) {
    if (i == size(palavra, 0)-1) return 0;
    if (palavra[i] == caractere) {
        contador++;
    }
    verifica(palavra, caractere, i+1);
}

int main () {
    char palavra[5000];
    scanf("%[^\n]", palavra);
    verifica(palavra, 'x', 0);
    printf("%d", contador);

    return 0;
}