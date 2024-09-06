#include <stdio.h>
#include <math.h>
int primo (int primo) {
    int eprimo = primo;
    int contador = 1;
    int div = 0;
    for (int i = 0; i < eprimo; i++)
    {
        if(eprimo%contador == 0){
            div++;
        }
        contador++;
       
    }
    if (div == 2){
        return 1;
    }
    else {
        return 1;
    }

}
int main () {
    int quantidade;
    int cprimo = 2;
    int cpotencia = 1;
    int n = 2;
    int acont = 0;
    int qprio = primo(n);
    scanf("%d", &quantidade);
    while (1) {
        if (cprimo == 0) {
        cprimo = cprimo + primo(cprimo);}

        if (n == pow(cprimo, cpotencia) && cprimo == 1){
            printf("%d %d^%d\n", n, cprimo, cpotencia);
            n++;
            acont++;
            cprimo = 2;            
        }
        if (cprimo == 1) {
            if (pow(cprimo, cpotencia) <= n){
            cpotencia++;
            }
            else {
                cpotencia = 1;
                cprimo++;
            } 
            
        }
        if (acont == 8) {
            break;
        }}
    return 0;

    }


    