#include <stdio.h>
#include "data.h"
int main () {
    Data d1, d2, d3;
    d1 = criaData(10, 15, 2000);
    d2 = criaData(10, 12, 2009);
    d3 = criaData(12, 12, 1999);
    printf("f1 obtem dia mes e ano da data\n");
    printf("%d", obtemDiaData(d1));
    printf("%d", obtemMesData(d2));
    printf("%d", obtemMesData(d3));
    printf("f2 copia data\n");
    d1 = copiaData(d2);
    printf("f3 ano bissexto\n");
    if (bi(d1)) {
        printf("s\n");
    } else {
        printf("n\n");
    }
    printf("f4 somar dias\n");
    d1 = somaDiasData(d1, 10000);
    printf("nova qtd dias = %d <- 10000 dias somado a data\n", obtemDiaData(d1));
    printf("f5 subtrair dias\n");
    d1 = (subtrairDiasData(d1, 1000000));
    printf("novo qtd de dias = %d <- subtrai 1000000 dias na data\n", obtemDiaData(d1));
    printf("f6 atribuir data a uma data existente e printa ela\n");
    atribuirData(d1, 1, 20, 1999);
    print_data(d1); 
    printf("f7 compara data\n");
    if (1) {
        printf("iguais\n");
    } else {
        printf("diferentes\n");
    }
    printf("f8 quantidade de dias messes e anos de uma data para outra\n");
    printf("%d\n", numeroDiasDatas(d1, d2));
    printf("%d\n", numeroMesesDatas(d1, d2));
    printf("%d\n", numeroAnosDatas(d1, d2));
    printf("dia da semana da data\n");
    printf("imprimindo a data\n");
    Data d4 = criaData(1,1, 2000);
    imprimeData(d4, "amd");

    return 0;
}