#include <stdio.h>
int main (){
    double mediapar;
    double mediaimpar;
    mediapar = 0;
    mediaimpar = 0;
    int numero;
    int contadorpar;
    int contadorimpar;
    contadorimpar = 0;
    contadorpar = 0;
    numero = 1;
    //enquanto o numero for diferente de 0 ou seja o usuario não digitou 0 ele executa o while
    while (numero != 0) {
        scanf("%i", &numero);
        //se o numero digitado for par ele faz isso
        if (numero % 2 == 0 && numero != 0){
            mediapar += numero; 
            contadorpar++;
        }
        //se for impar isso
        if (numero % 2 != 0) {
            mediaimpar += numero; 
            contadorimpar++;
        }
    }
    if (contadorimpar == 0) {
        contadorimpar = 1;
    }
    if (contadorpar == 0){
        contadorpar = 1;
    }
    printf("MEDIA PAR: %lf\n", (mediapar/contadorpar));
    printf("MEDIA IMPAR: %lf\n", (mediaimpar/contadorimpar));
    
    
    return 0;
}