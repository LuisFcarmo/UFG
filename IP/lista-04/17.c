#include <stdio.h>
#include <math.h>
double maximacoordenada (double *vetor01, double *vetor02){
    double cord01, cord02, cord03;
    cord01 = fabs((vetor02[0] - vetor01[0]));
    cord02 = fabs((vetor02[1] - vetor01[1]));
    cord03 = fabs((vetor02[2] - vetor01[2]));
    if (cord01 >= cord02 && cord01 >= cord03 ){
        return cord01;
    }
    if (cord02 >= cord01 && cord02 >= cord03 ){
        return cord02;
    }
    if (cord03 >= cord01 && cord03 >= cord02 ){
        return cord03;
    }
}
int main () {
    double vet01[3];
    double vet02[3];
    double vet03[3];
    double valores[10000];
    double valor = 0;
    double pq = 0;
    int i = 0;
    int contador = 1;
    int quantidade;
    scanf("%d", &quantidade);
    quantidade = quantidade-2;
    for(i = 0; i < 3; i++){
        scanf("%lf", &valor);
        vet01[i] = valor;   
    }
    for(i = 0; i < 3; i++){
        scanf("%lf", &valor);
        vet02[i] = valor;   
    }
    pq = maximacoordenada(vet02, vet01);
    valores[0] = pq;
    while (quantidade--)
    {
    for(i = 0; i < 3; i++){
        scanf("%lf", &valor);
        vet03[i] = valor;   
    }
    
    valores[contador] = maximacoordenada(vet02, vet03);
    
    
    
    for(i = 0; i < 3; i++){
        vet02[i] = vet03[i];   
    }
    
    contador++;
    }
    
    for (i = 0; i < contador; i++)
    {
        printf("%.2lf\n",valores[i]);
    }
    
    
    return 0;
}