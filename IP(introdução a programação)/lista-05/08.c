#include <stdio.h>
int main () {
    int matriz[500][500];
    int dim = 0;
    int linha = 0, coluna = 0;
    int contador = 0;
    int c2 = 0;
    int c3 = 0;
    scanf("%d", &dim);
    int acumulador = 0;
    for (linha = 0; linha < dim; linha++){
        for (coluna = 0; coluna < dim; coluna++){
            scanf("%d", &matriz[linha][coluna]);    
        }
    }
    for (coluna = 0; coluna < dim; coluna++){
        for (linha = 0; linha < dim; linha++){
            if (matriz[linha][coluna] == 1) {
                contador++;
            }
            acumulador += matriz[linha][coluna]; 
        }
        if (contador == 1){
            c2++;
        }
        contador = 0;
    }
    if (c2 == dim) {
        for (linha = 0; linha < dim; linha++){
            for (coluna = 0; coluna < dim; coluna++){
                if (matriz[linha][coluna] == 0) {
                    contador++;
                }
            }
            if (contador == dim-1){
                c3++;
            }
            contador = 0;
        }
        if (c3 == dim){
            printf("%d\n", dim);
            printf("PERMUTACAO\n");
            printf("%d\n", acumulador);
        }
        else {
            printf("%d\n", dim);
            printf("NAO EH PERMUTACAO\n");
            printf("%d\n", acumulador);
        }
    } else {
            printf("%d\n", dim);
            printf("NAO EH PERMUTACAO\n");
            printf("%d\n", acumulador);
    }    
    
    
    return 0;
}