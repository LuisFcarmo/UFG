#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double valor;
    double grau;
    int tamanho;

} polinomio;
void leiturapolinomio (polinomio *ptrpoli, int tamanho) {
    int i = 0;
    for (i = 0; i < tamanho; i++) {
            scanf("%lf %lf", ptrpoli[i].valor, ptrpoli[i].grau);
    }
}
void somapoli (polinomio *ptrpoli1, polinomio *ptrpoli2, polinomio *ptrpoli3) {
    int i = 0, k = 0;
    for (i = 0; i < ptrpoli1[0].tamanho; i++) {
        for (k = 0; k < ptrpoli2[0].tamanho; k++) {
            if (ptrpoli1[i].grau == ptrpoli2[k]) {
                
            }
        }
    }
}
int main () {
    polinomio *a;
    polinomio *b;
    polinomio *c;
    int qvezes = 0, tamanho = 0, tamanho2 = 0;
    int i = 0;
    scanf("%d", &qvezes);
    while (qvezes--)
    {   
        scanf("%d", &tamanho);
        a = (polinomio *) malloc(tamanho*sizeof(polinomio));
        a[0].tamanho = tamanho;
        leiturapolinomio(a, tamanho);
        scanf("%d", &tamanho2);
        b = (polinomio *) malloc(tamanho2*sizeof(polinomio));
        b[0].tamanho = tamanho2;
        leiturapolinomio(b, tamanho2);
        c = (polinomio *) malloc((tamanho+tamanho2)*sizeof(polinomio));

    }    
    return 0;
}