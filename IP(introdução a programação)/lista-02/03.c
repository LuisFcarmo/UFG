#include <stdio.h>
int main () {
    int numero1, numero2;
    int i;
    scanf("%d %d", &numero1, &numero2);
    if (numero1 % 2 == 0)
    {
        for (i == 0; i < numero2; i++){
            printf("%i ", numero1);
            numero1 += 2;
        }  
            printf(" \n");
    } 
    else {
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
    }


    return 0;
}