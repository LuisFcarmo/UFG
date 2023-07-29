#include <stdio.h> 
int main () {
    int i;
    double numero;
    double celsius;
    int numerodelinhas;
    //double temperaturas[3];
    //double numeros[3];
    scanf("%i", &numerodelinhas);
    for (i == 0; i < numerodelinhas; i++){
        scanf("%lf", &numero);
        celsius = (5*(numero-32))/9;
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", numero, celsius);
    
    }
    //printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", numeros[0], temperaturas[0]);
    //printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", numeros[1], temperaturas[1]);
    // printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", numeros[2], temperaturas[2]);
    
    
    
    return 0;
}