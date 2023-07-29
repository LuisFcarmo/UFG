#include <stdio.h>
int main () {
    int numero;
    int i;
    int j;
    int impar;
    int contador;
    impar = 1;
    i = 0;
    j = 0;
    contador = 1;
    scanf("%i", &numero);
    for (i = 1; i <= numero; i++) {
        printf("%i*%i*%i = ", i, i, i); 
        /*
        aqui esse primeiro for vai de 1 ate numero que faz a exibição do numero que vem
        antes da entrada exemplo
        1x1x1 =
        */
        for (j = 1; j  <= contador; j++ ){
            /* 
            esse segundo for faz a exibição dos numeros impares uma logica simples se for a 
            primeira iteração ele exibe 1
            da segunda pra frente ele exibe a quantidade desejada de numeros impares se for 
            segunda iteração ele faz 3+5
    
            */
            if (contador == 1){
                printf("%i", impar);
            }
            else {
                impar = impar + 2; //soma 2 ao impar pela logica 1 pra 3 salta dois esse padrão se repete para todos os impares
                if (j == contador) {
                    printf("%i", impar);
                }
                else {
                printf("%i+", impar);
                }
            }
        }
        printf("\n");
        contador++;
    }
    
    
    return 0;
}