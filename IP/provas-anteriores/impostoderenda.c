#include <stdio.h>
int main () {
    int matricula;
    double salariom;
    int qpessoas;
    double salariof;
    double taxaimposto;
    double taxamin;
    double impostobruto;
    double impostonormal;
    double impostoliquido;
    double pagooudevolvido;
    scanf("%d %lf %d %lf %lf", &matricula, &salariom, &qpessoas, &salariof, &taxamin);
    if (salariof > (12*salariom)){
        impostobruto = salariof*(0.2);
    }
     if (salariof > (5*salariom)){
        impostobruto = salariof*(0.08);
    }
     if (salariof <= (5*salariom)){
        impostobruto = salariof*0;
    }
    impostonormal = salariof * (taxamin/100);
    impostoliquido = impostobruto - (300*qpessoas);
    pagooudevolvido = impostoliquido - impostonormal;
    printf("%i %lf %lf %.2lf", matricula, impostobruto, impostoliquido, pagooudevolvido);
    if (pagooudevolvido < 0) {
        printf("imposto a receber");
    } else {
        printf("imposto a pagar");
    }

    if (pagooudevolvido == 0){
        printf("imposto quitado");
    }
    return 0;
}