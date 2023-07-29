#include <stdio.h>
double raiz (double n, double e){
    double rkprev;
    double raiz = 0;
    double erroatual = 0;
    rkprev = 1;
    do {
        raiz = (rkprev + (n/rkprev))/2;
        erroatual = -1*(n - raiz*raiz);
        printf("r: %.9lf, err: %.9lf\n", raiz,erroatual);
        rkprev = raiz;
    }while (erroatual > e);
    return raiz;
}
double absoluto (double n, double e){
    double rkprev;
    double raiz = 0;
    double erroatual = 0;
    rkprev = 1;
    do {
        raiz = (rkprev + (n/rkprev))/2;
        erroatual = -1*(n - raiz*raiz);
        rkprev = raiz;
    }while (erroatual > e);
    return erroatual;
}
int main () {
    double n = 0;
    double e = 0;
    double raizreal = 0;
    double absolutoreal = 0;
    scanf("%lf %lf", &n, &e);
    absolutoreal = absoluto(n, e);
    raizreal = raiz(n, e);
    return 0;
    }