#include <stdio.h>
#include <stdlib.h>

int main () {
    //deslocamente de bits a esquerda
    //realizar deslocamentos de de bits a esquerda
    //equivale a multiplicar um numero por x
    int a, b;
    a = 1; // 0001
    b = a << 1; 
    //0010 desloca o bit do numero uma vez para esquerda 
    //agora ele vai valer 2

    b = a << 2; 
    //0100
    //0100 = 4;

    b = a << 3;
    //1000
    //1000 = 8;este texto esta adlksskadkdkak d

    //deslocamento a direita
    //equivalite a dividir por 2

    a = 10;
    b = a >> 1; // 1010 - 0101 = 5
    b = a >> 2; // 1010 - 0010 = 2
    b = a >> 3; // 1010 - 0001 = 1

    //operadores de bits
    //Operador bit a bit NOT (~)
    
    /*
        1 = 0001
        ~1 = 1110 (-2)
        2 = 0010 (-3)
        ~2 = 1101 (-4)
    */
    int b, c;
    a = 1;
    b = ~b;
    printf("%d %d", a, b);

    /*
        complemente de dois como representar o -2 em binário
        2 - em decimal
    
        0010 - dois em binario
        
        faz a soma do inverso com 1 e você chegara na representação binaria do
        numero
        1101
          11 
        1110   
    */

    //opeador and (&) mesma coisa que o operador normal 
    /*
        A B  (A & B)
        0 0     0
        0 1     0
        1 0     0
        1 1     1

        exemplo beat a bit
        a = 1 1 1 0 1
        b = 1 0 1 1 1
            1 0 0 0 1
        c = a & b 
    */
    a = 73;
    b = a & (1 << 3); // testando se o 3 bit mais a esquerda tá ligado

    if (a & 1) {
        printf("numero par\n");
    } else {
        printf("numero impar\n");
    }

    //operar ou (|) or ||
    /*
        A B A | B
        0 0   0 
        0 1   1
        1 0   1
        1 1   1
    */ 
    int a, b , c;
    a = 30;
    b = 19;
    a = a | b;

    printf("%d & %d = %d\n", a, b, c);

    //usado para ativar um bit 
    a = 1; //0000.0001
    b = a | (1 << 3); 
    //0000.0010
    //aqui eu irei ativar o 3 bit a esquerda 

    //operador bit a bit OU Exclusivo (^)
    /*
        mesmo operador da logica matematica
        A B  A ^ A
        0 0    0
        0 1    1
        1 0    1
        1 1    0

        Esta operação é util quando precisamos inverter o estado de um bit
        xxxxx.xxxx
        00000.0010
        xxxxx.xx0x
        
        invertendo os estados desejados dos bits espeficos
        xx0xx.x0xx
        xx1xx.x1xx
    */

    a = 73; // 01001001
    b = a ^ (1 << 3); // 00001000
    printf("a:%d b:%d", a, b); 

    return 0;
}