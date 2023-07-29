#include <stdio.h>
int main () {
    double rkprev, n, e, r, erroatual;
    scanf("%lf %lf", &n, &e);
    
    rkprev = 1;
    do {
        r = (rkprev + (n/rkprev))/2;
    
        erroatual = -1*(n - r*r);
        printf("r: %.9lf, err: %.9lf\n", r, erroatual);
    
        rkprev = r;
    }while (erroatual > e);
    
    
    return 0;
}