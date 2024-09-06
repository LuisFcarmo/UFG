#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char produto[50];
    float pproduto;
} frutas;
typedef struct {
    char produto[50];
    int qproduto;
} qqfrutas;
    
    
int main () {
    int qfrutas;
    int compraf;
    double acumulador = 0;
    int idafeira;
    int i = 0, k = 0;
    frutas *vetfrutas;
    qqfrutas *vetqfrutas;
    scanf("%d", &idafeira);
    while(idafeira--){
        scanf("%d", &qfrutas);
        vetfrutas = (frutas*) malloc(qfrutas*sizeof(frutas));
        
        for (i = 0; i < qfrutas; i++) {
            scanf("%s %f", vetfrutas[i].produto, &vetfrutas[i].pproduto);
        }
        
        scanf("%d", &compraf);
        vetqfrutas = (qqfrutas*) malloc(compraf*sizeof(qqfrutas));
        
        for (i = 0; i < compraf; i++) {
            scanf("%s %i", vetqfrutas[i].produto, &vetqfrutas[i].qproduto);
        }
        for (i = 0; i < compraf; i++) {
            for (k = 0; k < qfrutas; k++) {
                if(strcmp(vetqfrutas[i].produto, vetfrutas[k].produto) ==  0) {
                    acumulador += vetqfrutas[i].qproduto*vetfrutas[k].pproduto;
                }
            }
        }
        printf("R$ %.2lf\n", acumulador);
        acumulador = 0;
    }
}