#include <iostream>
#include "pilha.h"
#include <stdio.h>
int main () {
    int op = 0;
    stack stack01;
    typeitem item;
    std::cout << "tabela de opções" << "\n";
    std::cout << "0 para matar o programa" << "\n";
    std::cout << "1 adicionar item a pilha" << "\n";
    std::cout << "2 retirar um item da pilha" << "\n";
    std::cout << "3 imprimir a pilha" << "\n";
    do {
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cin >> item;
            stack01.push(item);    
            break;
        case 2:
            stack01.pop();
            break;
        case 3:
            stack01.printstack();
        }
        
    } while (op != 0);
}