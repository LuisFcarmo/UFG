#include <stdio.h>
int main () {
    //numero de linhas e colunas
    int numerol, numeroc, i1,j1;
    scanf("%i %i", &numerol, &numeroc);
    int i, j;
    i = 1;
    j = 1;
    i1 = 0;
    j1 = 0;
    for (i = 1; i <= numerol; i++) {
        for (j = 1; j <= numeroc; j++){
            i1 = i; // tenho que criar a varivel e guardar o valor 
            j1 = j; // não da pra adicionar direto na matriz
        }
    }
    
    for (i = 1; i <= numerol; i++) {
        for (j = 1; j <= numeroc; j++){
            if ( i == j){
                break;
            }
            if (j != 1) {
                printf("-");
            }
            printf("(%i,%i)", i, j);
    
        }
        printf("\n");
    }
    
    return 0;
}