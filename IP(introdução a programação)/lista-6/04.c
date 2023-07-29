#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    double x;
    double y;
    double u;
    double o;
    double norma;
} pontos;
    
int main () {
    int q = 0;
    int i = 0;
    int k = 0;
    pontos *vetorpontos;
    double *vetnorma;
    double aux;
    scanf("%d", &q);
    vetorpontos = (pontos*) malloc(q*sizeof(pontos));
    vetnorma = (double*) malloc(q*sizeof(double));
    for (i = 0; i < q; i++) {
        scanf("%lf %lf %lf %lf", &vetorpontos[i].x ,&vetorpontos[i].y ,&vetorpontos[i].u ,&vetorpontos[i].o);
        
        vetorpontos[i].norma = sqrt((pow(vetorpontos[i].x, 2)) + (pow(vetorpontos[i].y, 2)) + (pow(vetorpontos[i].u, 2)) +(pow(vetorpontos[i].o, 2)));
    }
    for (i = 0; i < q; i++) {
        vetnorma[i] = vetorpontos[i].norma;
    }
    
    for (i = 0; i < q; i++){
        for (k = 0; k < q-1; k++) {
            if (vetnorma[i] <= vetnorma[k]) {
                aux = vetnorma[k];
                vetnorma[k] = vetnorma[i];
                vetnorma[i] = aux;
            }
    
        }
    }
    for (i = 0; i < q; i++) {
        for (k = 0; k < q; k++) {
            if (vetnorma[i] == vetorpontos[k].norma) {
                printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", vetorpontos[k].x ,vetorpontos[k].y ,vetorpontos[k].u ,vetorpontos[k].o, vetorpontos[k].norma);
            }
        }
    }
    
}