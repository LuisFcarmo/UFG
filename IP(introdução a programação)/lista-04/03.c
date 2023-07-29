#include <stdio.h>
int main () {   
    int vetornumeros[5000];
    int tamanho = 0;
    int valor = 0;
    int i = 0;
    scanf("%d", &tamanho);
    for ( i = 0; i < tamanho; i++)
    {
        scanf("%d", &valor);
        vetornumeros[i] = valor;
    }
    for (i = tamanho-1; i >= 0;i--){
        printf("%d ", vetornumeros[i]);
        
    }
}