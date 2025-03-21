#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
int string2num(char *s, int base) {
    int a = 0;
    char caractere = 0; 
    int digit;

    for ( ; *s; s++) {
        if (base > 36) return -1;
        if (*s >= '0' && *s <= '9')  digit = *s - '0';
        else if (*s >= 'A' && *s <= 'Z')  digit = *s - 'A' + 10;
        else if (*s >= 'a' && *s <= 'z')  digit = *s - 'a' + 10;
        else return -1;
        if (digit >= base) return -1;

        a = a*base + digit;
    }

    return a;
}

int is_little(){
    int inteiro = 0x01;
    unsigned char *p = ( unsigned char* )&inteiro;
    return (*p == 0x01) ? 1 : 0;
}

void testar_string2num() {
    // Teste para base 2 (binário)
    assert(string2num("101", 2) == 5);  
    assert(string2num("1101", 2) == 13); 
    assert(string2num("100000", 2) == 32);  
    assert(string2num("102", 2) == -1);   

    // Teste para base 8 (octal)
    assert(string2num("17", 8) == 15);
    assert(string2num("25", 8) == 21); 
    assert(string2num("100", 8) == 64);  
    assert(string2num("8", 8) == -1);  

    // Teste para base 10 (decimal)
    assert(string2num("123", 10) == 123);  
    assert(string2num("456", 10) == 456); 
    assert(string2num("999", 10) == 999);  
    assert(string2num("01", 10) == 1);  

    // Teste para base 16 (hexadecimal)
    assert(string2num("1A", 16) == 26);  
    assert(string2num("FF", 16) == 255);  
    assert(string2num("10", 16) == 16);
    assert(string2num("G", 16) == -1);  

    // Teste para base 36 (alfabética + numérica)
    assert(string2num("Z", 36) == 35);  
    assert(string2num("1Z", 36) == 71);  
    assert(string2num("10", 36) == 36);  
    assert(string2num("A", 36) == 10);  
    assert(string2num("ZZ", 36) == 1295); 

    // Teste de base inválida
    assert(string2num("101", 1) == -1);  
    assert(string2num("101", 37) == -1);  
    // Teste com caracteres inválidos para base
    assert(string2num("G", 16) == -1);  
    assert(string2num("Z", 10) == -1);  

    printf("Todos os testes passaram!\n");
}

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}
void invert_string(char *string, int size) {
    char temp1;
    char temp2;       
    for (int i = 0; i < size/2; i++) {
        temp1 = string[(size-1)-i];
        temp2 = string[i];
        string[(size-1)-i] = temp2;
        string[i] = temp1;
    }
}

bool validar (int base){
 // faltar validar
}
void num3string(int num, int base, char *resp){
    int div_resto = 0;
    int contador = 0;
    while (num) {
        div_resto = num%base;
        if (div_resto > 9) {
            div_resto = 'A' + (div_resto - 10);
        } else {
            div_resto = div_resto + '0';
        }
        resp[contador] = (char) div_resto ;
        num /= base;
        contador++;
    }
    resp[contador] = '\0';
    invert_string(resp, contador);
}


void print(char *texto) {
    printf("%s\n", texto);
}

// Função de teste
void testar_num3string() {
    char buffer[50];

    // Teste 1: Decimal para binário (base 2)
    num3string(31, 2, buffer);
    assert(strcmp(buffer, "11111") == 0); // 31 em binário é 11111
    printf("Teste 1 passou: %s\n", buffer);

    // Teste 2: Decimal para hexadecimal (base 16) com letras maiúsculas
    num3string(268435455, 16, buffer);
    assert(strcmp(buffer, "FFFFFFF") == 0); // 255 em hexadecimal é FF (maiúsculas)
    printf("Teste 2 passou: %s\n", buffer);

    // Teste 3: Decimal para base 36
    num3string(12345, 36, buffer);
    assert(strcmp(buffer, "9IX") == 0); // 12345 em base 36 é 9IX
    printf("Teste 3 passou: %s\n", buffer);

    // Teste 5: Número positivo na base 10
    num3string(255, 10, buffer);
    assert(strcmp(buffer, "255") == 0); // 255 na base 10
    printf("Teste 5 passou: %s\n", buffer);

}


int main() {
    /*
    int inteiro = 10000;
    long long_num = 1000;
    char palavra = 97;
    short short_p = 'a';
    char p[] = "7509";

    print("printando o inteiro e o endereço dos 4 bits e os valores neles");
    dump(&inteiro, 4);
    print("printando o long e o endereço dos 8 bits e os valores neles");
    dump(&long_num, 8);
    print("printando o char e o endereço dos 1 bits e os valores neles");
    dump(&palavra, 1);
    print("printando o short e o endereço dos 2 bits e os valores neles");
    dump(&short_p, 2);
    print("printando o vetor de char e o endereço dos 4 bits e os valores neles");
    dump(&p, 4);

    //conerversor de string para number

    printf("==> %d\n", string2num("1234", 10));
    printf("==> %d\n", string2num("1234", 10) + 1);
    printf("==> %d\n", string2num("1234", 10) + string2num("1", 10));
    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("a09b", 16));
    printf("%d\n", string2num("k09b", 36));

    testar_string2num();
    if (is_little())

        printf("Little-endian\n");

    else

        printf("Big-endian\n");
    */
    char buf[128];


    num3string(2024, 16, buf);
    testar_num3string();
    return 0;
}
