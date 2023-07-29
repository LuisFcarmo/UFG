#include <stdio.h>
int main () {
    int n1;
    int n2;
    int n3; 
    int numero;
    int quadrado;
    scanf("%i", &n1);
    scanf("%i", &n2);
    scanf("%i", &n3);
    if ((float)n1/10>=1 || (float)n2/10>=1 || (float)n3/10>=1) {
      printf("DIGITO INVALIDO");
      return 0;
    } 
    numero = (n1*100) + (n2*10) + n3;
    quadrado = numero*numero;
    printf("%i, %i", numero, quadrado);
    return 0;
}