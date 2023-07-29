#include <stdio.h>
int main () {
    int numero;
    double fatorial;
    int contador;
    int i;
    
    contador = 2;
    
    scanf("%i", &numero);
    fatorial = numero*(numero-1);
    if (numero > 2) {
    
    //enquanto o numero - contador for diferente de 1 que é onde o fatoral deve parar ele continua
    while (numero-contador != 1)
    {
    fatorial = fatorial*(numero-contador);
    contador++;
    }
        printf("%i! = %.0lf",numero , fatorial);
    }
    //verifica as poossibilidades que minha logica inicial não aborada 2, 1,0
    if (numero == 2) {
    
        printf("%i! = %.0lf",numero , fatorial);
    
    }
    if (numero == 0){
        printf("%i! = 1",numero);
    
    
    }
    if (numero == 1){
        printf("%i! = 1",numero);
    
    }
    return 0;
};