#include <stdio.h>
#include <math.h>
double raizesEq2Grau (double a, double b, double c, double *x1, double *x2) {   
    double delta = (b*b) - (4*a*c);
    if (delta > 0) {
        *x1 = (-b + sqrt(delta))/(2*a);
        *x2 = (-b - sqrt(delta))/(2*a);
        return 2;
    }
    if (delta == 0) {
        *x1 = (-b + sqrt(delta))/(2*a);
        return 1;
    }
    if (delta < 0) {
        return 0;
    }
}
    
int main () {
    double a;
    double b;
    double c;
    double raiz1;
    double raiz2;
    double aux;
    int rps;
    scanf("%lf %lf %lf", &a, &b, &c);
    rps = raizesEq2Grau(a,b,c, &raiz1, &raiz2);
    
    if (raiz1 > raiz2){
        aux = raiz2;
        raiz2 = raiz1; 
        raiz1 = aux;
    }
    
    
    if (rps == 2 ){
        printf("RAIZES DISTINTAS\n");
        printf("X1 = %.2lf\n", raiz1);
        printf("X2 = %.2lf\n", raiz2);
    }
    if (rps == 1 ){
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", raiz1);
    }
    if (rps == 0 ){
        printf("RAIZES IMAGINARIAS\n");
    }
    return 0;
}