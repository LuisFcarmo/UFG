#include <stdio.h>
int  converternotasemmoedas (int dinheiro, int *notas100, int *notas50, int *notas10,int *notas1) {
    *notas100 = dinheiro/100;
    *notas50 = (dinheiro%100)/50;
    *notas10 = ((dinheiro%100)%50)/10;
    *notas1 = (((dinheiro%100)%50)%10)/1;
}
    
int main () {
    int dinheiro;
    int notas100 = 0;
    int notas50 = 0;
    int notas10 = 0;
    int notas1 =0;
    scanf("%i", &dinheiro);
    converternotasemmoedas(dinheiro, &notas100, &notas50, &notas10, &notas1);
    printf("NOTAS DE 100 = %i\n", notas100);
    printf("NOTAS DE 50 = %i\n", notas50);
    printf("NOTAS DE 10 = %i\n", notas10);
    printf("MOEDAS DE 1 = %i\n", notas1);
    
    
    return 0;
}