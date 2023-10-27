#include <stdio.h>

int print_max (int max, int acumulador) {
    if (acumulador == max) return 0; // caso base quando o acumulador tem o mesmo valor que o acumulador
    acumulador++; // incrementando o acumulador 
    
    printf("%d ", acumulador);

    print_max(max, acumulador); // aqui eu chamo a recursividade com o acumulador aumentado em uma unidade

    return acumulador;
}

int main () {
    int max = 0;
    scanf("%d", &max);
    print_max(max, 0);
    
    return 0;
}