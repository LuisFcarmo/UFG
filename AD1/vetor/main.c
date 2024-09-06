#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    floatvector *vetor;
    int capacity = 0, index = 0;
    int qtd;
    int op = 0;
    float valor = 0;

    printf("qual a capacidade do vetor que vc deseja alocar ?\n");
    scanf("%d%*c", &capacity);
    vetor = create(capacity);
    do {

        printf("quantos items deseja adicionar");        
        scanf("%d%*c", &qtd);
        if (qtd > capacity) {
            printf("alerta");
            printf("você está tentando adiconar mais itens que o vetor suporta\n");
        }

    } while (qtd > capacity);

    while (qtd--)
    {
        printf("digite um valor:\n");
        scanf("%f", &valor);
        append(vetor, valor);
    }
     while (1)
    {
        if (op == 7) {
            destroy(&vetor);
            printf("qual a capacidade do vetor que vc deseja alocar ?\n");
            scanf("%d%*c", &capacity);
            vetor = create(capacity);
            printf("quantos items deseja adicionar");
            
            scanf("%d%*c", &qtd);

            while (qtd--)
            {
                printf("digite um valor:\n");
                scanf("%f", &valor);
                append(vetor, valor);
            }
        }
   
        while(1) {
            printf("opções disponiveis\n"
                  "1 para visualizar um item do vetor\n"
                  "2 para capturar um item do vetor\n"
                  "3 para printar o vetor\n"   
                  "4 para setar substituir um item no vetor\n" 
                  "5 para finalizar o programa\n" 
                  "6 adicionar um item no vetor\n"  
                  "7 para criar outro vetor\n" 
            );
            printf("sua escolha:\n");
            scanf("%d", &op);
            if (op < 8 && op > 0) break;
            else continue;
        }

        if (op == 5) break;
        switch (op)
        {
        case 1:
            printf("digite o index do elemento que deseja ver :\n");
            scanf("%d", &index);
            valor = at(vetor, index-1);
            printf("valor visualizado  ==  (%lf)\n", valor);
            break;
        case 2:
            printf("digite o index do elemento que deseja ver :\n");
            scanf("%d", &index);
            valor = at(vetor, index-1);
            printf("valor visualizado  ==  (%lf)\n", valor);
            break;
        case 3:
            print(vetor);
            break;
        case 4:
            printf("digite o index do elemento que subtituir ver :\n");
            scanf("%d", &index);
            printf("valor que deseja colocar no indice:\n");
            scanf("%f", &valor);
            set(vetor, index-1, valor);
            break;
        case 6:
            printf("digite o valor que deseja adicionar:\n");
            scanf("%f", &valor);
            append(vetor, valor);
            break;
        }
        sleep(1.5);
        system("clear");

    }
    destroy(&vetor);
}