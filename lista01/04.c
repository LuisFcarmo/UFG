#include <stdio.h>
int main () {
    float a;
    float b;
    float c;
    float d;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    float determinante;
    determinante = (a*d) - (b*c);
    printf("O VALOR DO DETERMINANTE E = %.2f\n", determinante);
    return 0;
}
