#include <stdio.h>
int main () {
    int vetornumero[5000];
    int quantidade = 0;
    int numero = 0;
    int contador = 0;
    int i = 0;
    int k = 0;
    int contadorvezes = 0;
    scanf("%d", &quantidade);
    for (i = 0; i < quantidade; i++){
        scanf("%d", &numero);
        vetornumero[i] = numero;
    }
    for (i = 0; i < quantidade; i++){
        for(k = 0; k < quantidade; k++){
            if (vetornumero[i] == vetornumero[k]){
                contador++;
            }
        }
        if (contador == 1) {
            contadorvezes++;
        }
        contador = 0;
    }
    printf("%d\n", contadorvezes);
    
    
    return 0;
}