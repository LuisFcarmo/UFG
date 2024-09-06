#include <stdio.h>
#include <math.h>
/*
int n, p:
    
função que calcula a potência e subtrai do numero e isso modulo 
fabs(); 
compara com o numero; 
se ele for menor auxiliar vai receber o numero que está sendo usado no pow
condição de parada se contador ² > numero break 
    
*/
int nextpot (int numero,int expoente) {
    int contador = 0;
    // valores para comapração
    int distancia = 0;
    int distancia02 = 0;
    // guarda o valor do contador que é a base elevada ao expoente desejado
    int axuliar = 0;
    // calcula a distância da potência em relação ao numero
    distancia = fabs(numero - pow(contador, expoente));
    contador++;
    
    while (1)
    {
        distancia02 = fabs(numero - pow(contador, expoente));
        if (distancia > distancia02) {
            distancia = distancia02;
            axuliar = contador;
        }
        
        if (distancia02 < numero) {
            contador++;
        }
        else {
            break;
        }
    }
    return axuliar;
}
    
int main(){
    int n = 0;
    int p = 0; 
    int resposta = 0;
    scanf("%d %d", &n, &p);
    resposta = nextpot(n,p);
    printf("%d -> %d^%d = %.0lf",n, resposta, p, pow(resposta, p));
    return 0;
}