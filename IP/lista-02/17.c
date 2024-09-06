#include <stdio.h>
#include <math.h>
double fatorial (double numero) {
    int fatorial;
    int contador;
    int i = 0;
    int parada = 0;
    fatorial = numero;
    contador = 1;
    if (fatorial == 0){
        return 1;
    }
    if (fatorial == 2) {
        return 2;
    }
    if (fatorial == 1) {
        return 1;
    }
    while (1){
        fatorial = fatorial*(numero-contador);
        contador++;
        parada = numero-contador;
        if (parada == 1) {
            break;
        }
    }
                
    return fatorial;
}
int main () {
    double x , n, contador;
    int i;
    i = 0;
    double sequenciatylor = 0;
    scanf("%lf %lf", &x, &n);

    for (i = 0; i <= n; i++)
    {
    sequenciatylor += (pow(x, i))/fatorial((double)i); 
    } 

    printf("e^%.2lf = %.6lf\n",x , sequenciatylor);

    return 0;
}