#include <stdio.h>
int Dezenamilhar (int numero) {
    int dezenamilhar;
    dezenamilhar = numero/10000;
    return dezenamilhar;
}
    
int Milhar (int numero) {
    int milhar;
    milhar = (numero - (Dezenamilhar(numero)*10000))/1000;
    return milhar;
};
    
int Centena (int numero, int milhar) {
    int centena, unidade;
    centena = ((numero-(Dezenamilhar(numero)*10000)-(milhar*1000))/100);
    return centena;
};
    
int UNIDADE (int numero) {
    int unidade;
    unidade = ((numero - (Dezenamilhar(numero)*10000)-(Milhar(numero)*1000) - (Centena(numero, Milhar(numero))
    *100))%10);
    
    return (unidade);
}
    
int Dezena (int numero) {
    int dezena;
    dezena = (((numero - (Dezenamilhar(numero)*10000)-(Milhar(numero)*1000) - (Centena(numero, Milhar(numero))
    *100)- (UNIDADE(numero)))/10));
    return dezena;
};
    
    
int main () {
    int numero; 
    int numeronovo;
    int teste;
    int dezenamilhar, milhar, centena, dezena, unidade;
    scanf("%i", &numero);
    dezenamilhar = Dezenamilhar(numero);
    milhar = Milhar(numero);
    centena = Centena(numero, milhar);
    unidade = UNIDADE(numero);
    dezena = Dezena(numero);
    
    if ((float) numero/100000 >= 1) {
        printf("NUMERO INVALIDO");
        return 0;
    };
    if (dezenamilhar >= 1) {
        numeronovo = (unidade*10000) + (dezena*1000) + (centena*100) + (milhar*10) + dezenamilhar;
        if (numeronovo == numero) {
            printf("PALINDROMO");
        } else {
                printf("NAO PALINDROMO");
        }
    };
    if (dezenamilhar == 0 && milhar >= 1) {
        numeronovo = (unidade*1000) + (dezena*100) + (centena*10) + milhar;
        printf("%i / %i / %i\n", unidade, dezena, numeronovo);
    
        if (numeronovo == numero) {
            printf("PALINDROMO");
        } else {
                printf("NAO PALINDROMO");
        }
    
    };
    if (dezenamilhar == 0 && milhar == 0 && centena >= 1) {
        numeronovo = (unidade*100) + (dezena*10) + centena;
        if (numeronovo == numero) {
            printf("PALINDROMO");
        } else {
                printf("NAO PALINDROMO");
        }
    }
    if (dezenamilhar == 0 && milhar == 0 && centena == 0 && dezena >= 1){
        numeronovo = (unidade * 10) + dezena;
        if (numeronovo == numero) {
            printf("PALINDROMO");
        } else {
                printf("NAO PALINDROMO");
        }
    }
    return 0;
    
}