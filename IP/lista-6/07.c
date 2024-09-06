#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    double x;
    double y;
    double u;
    double z;
} ponto;
    
int main () {
    int qpontos = 0;
    double distancia = 0;
    int i = 0;
    ponto *vetorpontos;
    scanf("%d", &qpontos);
    vetorpontos = (ponto*) malloc(qpontos*sizeof(ponto));
    for (i = 0; i < qpontos; i++) {
        scanf("%lf %lf %lf %lf", &vetorpontos[i].x, &vetorpontos[i].y, &vetorpontos[i].u, &vetorpontos[i].z);
    }
    for (i = 0; i < qpontos-1; i++)    {
        distancia = sqrt(pow((vetorpontos[i].x - vetorpontos[i+1].x), 2) +
                        pow((vetorpontos[i].y - vetorpontos[i+1].y), 2) +
                        pow((vetorpontos[i].u - vetorpontos[i+1].u), 2) +
                        pow((vetorpontos[i].z - vetorpontos[i+1].z), 2)
        );
        printf("%.2lf\n", distancia);
    }
    
    
    return 0;
}