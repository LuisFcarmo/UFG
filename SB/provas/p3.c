#include <stdio.h>

struct Data {
    char a[9];    // 9 bytes
    short b[3];   // 3 * 2 = 6 bytes
    int c;        // 4 bytes
};

void dump(void *p, int n) {
    unsigned char *bytes = (unsigned char *)p;
    unsigned long long addr = (unsigned long long)p;

    for (int i = 0; i < n; i++) {
        printf("0x%016llX - %02X\n", addr + i, bytes[i]);
    }
}

int main() {
    short vetor[13] = {0};

    // Inicializa o vetor com os valores 0 a 12
    for (int i = 0; i < 13; i++) {
        vetor[i] = i;
    }

    struct Data *ptr = (struct Data *) &vetor;
    printf("%d\n", (ptr->a[2] + vetor[4]) ^ ptr->b[0]);
    // Cálculo da variável c
    ptr->c = (2 * ptr->a[3]) - ptr->b[1];

    // Modificação de vetor[2]
    vetor[2] = (ptr->a[2] + vetor[4]) ^ ptr->b[0];

    // Impressão dos bytes da struct
    dump(ptr, sizeof(struct Data));

    return 0;
}
