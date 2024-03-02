#include <stdio.h>
int main () {
    int qtd;
    scanf("%d", &qtd);
    if (qtd <= 0 || qtd >= 3) {
        printf("-1\n");
    } else {
        if (qtd == 1) {
            printf("1 2 3\n");
        }
        else if (qtd == 2) {
            printf("3 4 5\n");
        }
    }


    return 0;
}