#include "pilha.h"
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

int main () {
    stack *Stack;
    int op = 0;
    int valor = 0;
    while (1)
    {
        while(1) {
            printf("\nopções disponiveis\n"
                  "1 Criar uma pilha\n"
                  "2 para printar a pilha\n"   
                  "3 push\n" 
                  "4 pop\n" 
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
            Stack = Stack_create();
            printf("pilha criada !!\n");

            break;
        case 2:
            Stack_print(Stack);

            break;
        case 3:
            printf("digite o valor : \n");
            scanf("%d%*c", &valor);
            Stack_push(Stack, valor);

            break;
        case 4:
            Stack_pop(Stack);
            printf("Nova pilha\n");
            Stack_print(Stack);

            break;
        case 5:
            valor = Stack_peek(Stack); 
            printf("valor do topo da pilha %d \n", valor);
            break;
        }
        sleep(1.5);
        system("clear");

    }
    Stack_destroy(Stack);
    return 0;
}