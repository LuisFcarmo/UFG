#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double numerador;
    double denominador;
} frac;
/*frac * realocaforte (frac *ponteiro, int qtd)  {
    frac *ponteiro2;
    do {
        ponteiro2 = realloc(ponteiro, qtd*sizeof(frac));
    } while (ponteiro2 == NULL);
    return ponteiro2;
}*/
int main () {
    double numerador = 0, denominador = 0;
    char parada;
    int teste = 0;
    int i = 0, k = 0;
    int contador = 0;
    int boleano = 0;
    int qteste;
    frac *vetordinamico; //= (frac*) (malloc(1*sizeof(frac)));

    scanf("%d", &qteste);
    while(qteste--){
        contador = 0;
        teste++;
        printf("Caso de teste %d\n", teste);
        while (1) {
            scanf("%lf/%lf%c", &numerador, &denominador, &parada);
            contador++;
            //vetordinamico = realocaforte(vetordinamico, contador );

            vetordinamico = (frac *) realloc(vetordinamico, contador*sizeof(frac));
            vetordinamico[contador-1].numerador = numerador;
            vetordinamico[contador-1].denominador = denominador;
            
            
            if (parada == '\n') break;
        }
        for (i = 0; i < contador; i++) {    
            for (k = i+1; k < contador; k++) {
                if ((vetordinamico[i].numerador/vetordinamico[i].denominador) == (vetordinamico[k].numerador/vetordinamico[k].denominador)) {
                    printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", vetordinamico[i].numerador, vetordinamico[i].denominador, vetordinamico[k].numerador, vetordinamico[k].denominador);
                    boleano = 1;
                }
            }
        }
        if (boleano == 0) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        boleano = 0;
        //free(vetordinamico);
    }
    return 0;
}