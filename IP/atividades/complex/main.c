#include <stdio.h>
#include "complex.h"
int main () {
    Complex a, b, c;
    a = cp_new(2, 4);
    b = cp_new(1, 2);
    c = cp_sum(a, b);
    cp_print(c, 1);
    c = cp_mult(a, b);
    cp_print(c, 1);
    c = cp_div(a, b);
    cp_print(c, 0);
}
