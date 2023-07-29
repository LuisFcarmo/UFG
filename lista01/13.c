#include <stdio.h> 
#include <math.h>
int main () {
    int a, b, c;
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    
    double delta, ba;
    double x1, x2;
    delta = (b*b) - (4*a*c);
    
    if (delta == 0) {
        x1 = -b/(2*a);
        printf("POSICOES: X1=%.2lf e X2=%.2lf\n", x1, x2);
    
        if (x1 >= 5 && x1 <= -5){
            printf("FORA DO EXPERIMENTO\n");
    
        };
    
        if ((a+b+c)%3 == 0) {
            printf("FATO1: DESAPARECIDA\n");
        };
        if (c%2 == 0 && c < a +b){
            printf("FATO2: ORIGEM\n");
        };
    };
    
    if (delta > 0) {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        
        if (x1 >= 5 || x1 <= -5 || x2 >= 5 || x2 <= -5){
            printf("POSICOES: X1=%.2lf e X2=%.2lf (FORA DO EXPERIMENTO)\n", x1, x2);
    
        };
        if (x1 <= 5 && x1 >= -5 && x2 <= 5 && x2 >= -5){
            printf("POSICOES: X1=%.2lf e X2=%.2lf\n", x1, x2);
    
        };        
        if ((a+b+c)%3 == 0) {
            printf("FATO1: DESAPARECIDA\n");
        };
        if (c%2 == 0 && c < a +b){
            printf("FATO2: ORIGEM\n");
        };
    };
    if (delta < 0) {
        printf("POSICOES IMAGINARIAS\n");
        return 0;
    };
    
    return 0;
}