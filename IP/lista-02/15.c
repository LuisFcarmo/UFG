#include <stdio.h>
int todosdivisores (int numero) {
    int contador = 0;
    int acumulador = 0;
    contador = 1.0;
    while (1)
    {
        if (contador == numero) {
            break;
        }
        if (numero % contador == 0) {
            acumulador += contador;
        }
    
        contador++;
        
    }
    return acumulador;
}
    
int main () {
    int numero;
    int numero3;
    int numero2;
    int quantiadadeamigos;
    int contador = 0;
    numero = 220;
    
    scanf("%i", &quantiadadeamigos);
    while(1) {
    
    if (contador == quantiadadeamigos)
    {
    
        break;
    }
        
    numero3 = todosdivisores(numero);
    numero2 = todosdivisores(numero3);
    
    
    if (numero2 == numero && numero3 > numero2){
        printf("(%i,%i)\n", numero2, numero3);
    contador++;
    numero2 = 0;
    numero3 = 0;
    } 
    if (numero2 =! numero){
        numero2 = 0;
            numero3 = 0;
    }
    numero++;
}    return 0;
}