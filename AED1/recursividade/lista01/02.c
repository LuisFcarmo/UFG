#include <stdio.h>
int fibo (int termos) {
    int acumulador;
    int numero = 0;
    if (acumulador == termos) return 0;
    printf("%d-", numero);
    return numero =+ fibo(numero+1);
}
int main () {   
    int qtermos = 0;
    scanf("%d", &qtermos);
    fibo(qtermos);


    return 0;
}