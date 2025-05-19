#define getfrac(x)  ((x) & 0x7fffff)
#include <stdio.h>
void print_binary(unsigned int num) {
    // Um unsigned int tem 32 bits
    for (int i = 31; i >= 0; i--) {
        // Extrai o bit na posição i usando deslocamento e máscara
        printf("%d", (num >> i) & 1);
        // Opcional: adicionar espaços a cada 8 bits para legibilidade
        if (i % 8 == 0 && i > 0)
            printf(" ");
    }
}
typedef union {
    float f;
    unsigned int i;
} U;

int main() {
    U u1, u2;

    u1.f = 32.0;
    u2.f = 40.250;

    unsigned int f = getfrac(u2.i);

    print_binary(u1.i);
    printf("\n");
    print_binary(u2.i);
    printf("\n");
    print_binary(u1.i >> 9);

    printf("Resposta = %X\n", (u1.i >> 9) ^ f);
    return 0;
}