#include <stdio.h>
int main () {
    int vetorelementos[10000];
    int k = 0;
    int tamanho = 0;
    int valores = 0;
    int primeirotermo = 0;
    int contador = 0;
    int i = 0;
    while (1)
    {
    scanf("%d", &tamanho);
    if (tamanho == 0) {
        break;
    }
    for (k = 0; k < tamanho; k++){
        scanf("%d", &valores);
        vetorelementos[k] = valores;
    };
    
    primeirotermo = vetorelementos[0];
    
    for (k = 0; k < tamanho; k++){
        if(primeirotermo < vetorelementos[k]){
            primeirotermo = vetorelementos[k];
        }
    }
    
    for (k = 0; k <= primeirotermo; k++){
        for (i = 0; i < tamanho; i++){
            if(k >= vetorelementos[i]){
                contador++;
            }
        }
        printf("(%d) %d\n", k, contador);
        contador = 0;
    }
    
    }
    return 0;
}