#include <stdlib.h>
#include <stdio.h>
int string2int (char text[]) {
    int numero;
    numero=atoi(text);
    return numero;
}
    
int main (){
    char vetnumeros[128];
    int numero;
    //aqui ocorre a entrada do texto cada linha tem no maximo cinco caracteres
    while(EOF != scanf("%[^\n]%*c", vetnumeros)){
        numero = (long int)string2int(vetnumeros);
    
        printf("%d %d\n", numero, numero*2 );
    }
    
    return 0;
}