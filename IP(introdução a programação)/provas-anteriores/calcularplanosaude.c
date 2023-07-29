#include <stdio.h>
int main () {
    double salario;
    int qpessoas;
    int salarioliquido;
    char plano; //A ou E
    double mensalidade; 
    scanf("%lf %d %c %lf", &salario, &qpessoas, &plano, &mensalidade);
    if (plano != 'A'&& plano != 'E') { // diferentes dos planos aceitos
        printf("tipo de plano invalido");
        return 0;
    }
    if (salario <= 1800 && plano == 'A'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");
            return 0;
        };
        printf("APARTAMENTO %lf", (mensalidade*0.3)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.3)*qpessoas);
    }
    if (salario <= 1800 && plano == 'E'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");
            return 0;
        };
        printf("ENFERMARIA %lf", (mensalidade*0.25)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.25)*qpessoas);
    }   
    if (salario > 1800 && salario <= 50000 && plano == 'A'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");  
            return 0;
        };
        printf("APARTAMENTO %lf", (mensalidade*0.35)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.35)*qpessoas);
    }
    if (salario > 1800 && salario <= 50000 && plano == 'E'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");
            return 0;
        };
        printf("ENFERMARIA %lf", (mensalidade*0.28)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.28)*qpessoas);
       
    }    
    if (salario > 50000 && plano == 'A'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");
            return 0;
        };
        printf("APARTAMENTO %lf", (mensalidade*0.40)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.40)*qpessoas);
    }
    if (salario > 50000 && plano == 'E'){
        if (salarioliquido < (salario*0.3)){
            printf("desconto não autorizado");
            return 0;
        };
        printf("ENFERMARIA %lf", (mensalidade*0.31)*qpessoas);
        salarioliquido = salario - ((mensalidade*0.31)*qpessoas);
    } 
    return 0;
}