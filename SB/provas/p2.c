#include <stdio.h>
#include <math.h>

typedef union {
    float f;
    unsigned int i;
} U;
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
#define makefloat(s,e,f) (((s) & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(i)  ((i)>>31 & 1)
#define getexp(i)  ((i)>>23 & 0xff)
#define getfrac(i) ((i) & 0x7fffff)

int main() {
    U u;
    u.f = 56.50;

    unsigned int s = getsig(u.i);    // Extrai o sinal
    unsigned int e = getexp(u.i);    // Extrai o expoente
    unsigned int f = getfrac(u.i);   // Extrai a mantissa
    //print_binary(u.i);
    s = e >> 7;                      // Novo sinal
    e = e - '2' - 'R';
    //printf("f => %d", e);
    f = f & (1 << 8);    
    printf("f = %d, e = %d, s = %d", f, e, s);
    u.i = makefloat(s, e, f);       // Reconstrói o float
    printf("%f", u.f);

    return 0;
}