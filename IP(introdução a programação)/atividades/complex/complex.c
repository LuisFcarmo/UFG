#include "complex.h"
#include <stdio.h>
#include <math.h>
Complex cp_new (double r, double i) {
    Complex c;
    c.r = r;
    c.i = i;
    return c;
};
Complex cp_sum(Complex a, Complex b) {
    Complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
};
void cp_print(Complex a, int i) {
    if (i == 1) {
        printf("forma retangular\n");
        printf("%.2lf %.2lf\n", a.r, a.i);
    } else {
        printf("forma polar\n");
        printf("%.2lf %.2lf\n", tamanho(a), angulo(a));
    }   
};
Complex cp_mult(Complex a, Complex b) {
   Complex result;
   result.r = (a.r * b.r) + ((b.i * a.i)*-1);
   result.i = (a.r * b.i) +  (a.i * b.r); 
   return result;
}; 
Complex cp_div (Complex a, Complex b) {
    Complex d;
    d.r = (a.r * b.r) + (a.r *(- b.i)) + (a.i * b.r) +(a.i * b.i );
    d.i = -1*((b.r * b.r) + (b.r * (-b.i)) + (b.i * b.r) +((b.i * b.i)*-1));
    return d;
};
double tamanho (Complex a) {
    return sqrt(a.r * a.r + a.i * a.i);
};
double angulo (Complex a) {
    return atan(a.i/a.r);
};