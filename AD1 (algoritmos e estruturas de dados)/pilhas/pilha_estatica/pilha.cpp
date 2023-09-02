#include <iostream>
#include "pilha.h"
#include <stdio.h>    
    stack::stack() {
        tamanho = 0;
        estrutura = new typeitem[max_itens];    
    }//build function
    
    stack::~stack() {
        delete [] estrutura;
    }// destruct function

    bool stack::isfull() {
        return (tamanho == max_itens); //compara se o tamanho de itenms na pilha é igual ao valor maximo da pilha
    }// verify if stack is full

    bool stack::isempty() {
        return (tamanho == 0); 
    }// verify if stack is empty
    
    void stack::push( typeitem item ) {
        if (isfull() == true) {
            std::cout << "a pilha está cheia";
        }
        else {
            estrutura[tamanho] = item;
            tamanho++;
        }
    } // push item in stack
    
    typeitem stack::pop () {
         if (isempty() == true) {
            std::cout << "a pilha está vazia impossível retirar";
            return 0;
        }
        else {
            tamanho--;
            return estrutura[tamanho];
        }
    } // pop item in stack 
    
    void stack::printstack() {
        std::cout << "[";
        for (int i = 0; i < tamanho; i++) {
            std::cout << estrutura[i] << " ";
        }
        std::cout << "]";
    }//print stack
    
    int stack::lenght() {
        return tamanho;
    }