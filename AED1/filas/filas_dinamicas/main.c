#include "fila.h"
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

int main () {
    row *Row;
    int op = 0;
    int valor = 0;
    while (1)
    {
        while(1) {
            printf("\nopções disponiveis\n"
                  "1 Criar uma fila\n"
                  "2 para printar a fila\n"   
                  "3 enqueue\n" 
                  "4 dequeue\n" 
                  "5 peek\n" 
            );
            printf("sua escolha:\n");
            scanf("%d%*c", &op);
            if (op < 6 && op > 0) break;
            else continue;
        }

        if (op == 5) break;
        switch (op)
        {
        case 1:
            Row = Row_create();
            printf("pilha criada !!\n");

            break;
        case 2:
            Row_print(Row);

            break;
        case 3:
            printf("digite o valor : \n");
            scanf("%d%*c", &valor);
            Row_enqueue(Row, valor);

            break;
        case 4:
            Row_dequeue(Row);
            printf("Nova pilha\n");
            Row_print(Row);

            break;
        case 5:
            valor = Row_peek(Row); 
            printf("valor do topo da pilha %d \n", valor);
            break;
        }
        sleep(1.5);
        system("clear");

    }
    Row_destroy(Row);
    return 0;
}