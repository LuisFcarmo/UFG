#include <stdio.h>
#include <math.h>
int main () {
    double A, B, C;
    double delta;
    double X1;
    double X2;
    scanf("%lf %lf %lf", &A, &B, &C);
    delta = (B*B) - (4*A*C);
    if (delta > 0) {
        printf("RAIZES DISTINTAS\n");
        X2 = (-B + sqrt(delta))/(2*A);
        X1 = (-B - sqrt(delta))/(2*A);
    if (X1 > X2) {
        printf("X1 = %.2lf\n", X2);
        printf("X2 = %.2lf\n", X1);
    }
    if (X1 < X2) {
        printf("X1 = %.2lf\n", X1);
        printf("X2 = %.2lf\n", X2);
        }
    }
    else if (delta == 0) {
        printf("RAIZ UNICA\n");
        X1 = -B/(2*A);
        printf("X1 = %.2lf\n", X1);
    };
    if (delta < 0) {
        printf("RAIZES IMAGINARIAS\n");
    } 
     return 0;
};


