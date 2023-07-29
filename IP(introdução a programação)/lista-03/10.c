#include <stdio.h>
double computepi (int termos) {
    double par = 2;
    double impar = 1;
    int contador = 0;
    double pi = 1;
    while (termos)
    {     
    
        if (contador == 0) {
            pi *= (par/impar);
        } //essa primeira iteração é feita pois não podemos acrescentar no 0 após o 1 itera
        if (contador % 2 == 0 && contador != 0){
            par+=2; // adiciona 2 no par a cada iteração de numero par
        }
        if (contador %2 != 0){ // adiciona 2 no impar a cada iteração de numero impar
            impar+=2;
        }
        
        pi *= (par/impar);
        
        contador++;
        termos--;
    }
    return pi;
}
    
    
int main () {
    int termos;
    double pi;
    scanf("%i", &termos);
    pi = computepi(termos);    
    printf("%.12lf", pi);
    return 0;
}