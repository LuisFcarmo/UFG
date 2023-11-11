#include <stdio.h>
int main () {
    char letra;
    int valor;
    scanf("%d", &valor);
    
    if ((valor >= 65 && valor <= 90) || (valor >= 97 && valor <= 122)){
        letra = (char) valor;
        printf("%c", letra);
    } 
}