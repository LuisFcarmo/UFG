#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int numerador;
    int denominador;
} frac;
    
    
int main () {
    int qquantidade = 0;
    int vezes = 0;
    frac frac2[50];
    int boleano = 0;
    int i = 0;
    int contador = 0;
    int k = 0;    
    scanf("%d", &vezes);
    while (vezes--){
        scanf("%d", &qquantidade);
        contador++;
        for (i = 0; i < qquantidade; i++) {
            scanf("%d/%d", &frac2[i].numerador, &frac2[i].denominador);
            
        }
        printf("Caso de teste %d\n", contador);
        for (i = 0; i < qquantidade; i++) {
            for (k = i + 1; k < qquantidade; k++) {
            if ((frac2[i].numerador/(double)frac2[i].denominador) == (frac2[k].numerador/(double)frac2[k].denominador))
            {
                printf("%d/%d equivalente a %d/%d\n", frac2[i].numerador, frac2[i].denominador, frac2[k].numerador, frac2[k].denominador);
                boleano = 1;
            }
            }
        }
        if(boleano == 0) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
            boleano = 0;
        }
        boleano = 0;
    }
}