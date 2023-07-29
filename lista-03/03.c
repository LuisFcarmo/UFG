#include <stdio.h> 
int separadigitos (int numero, int *centena, int *dezena, int *unidade) {
    *centena = numero%10;
    numero /= 10;
    *dezena = numero%10;
    numero /= 10;
    *unidade = numero%10;
}
    
    
int main () {
    int numero;
    int centena = 0;
    int dezena = 0;
    int unidade = 0;
    scanf("%i", &numero);
    separadigitos(numero, &unidade, &dezena, &centena);
    printf("%i%i%i", unidade, dezena, centena);
    
    return 0;
}