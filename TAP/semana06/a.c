#include <stdio.h>
#include <math.h>
int countDivisors (int numero) {
    if(numero == 1) return 1;
    int c;
    c = 2;
    for(int i=2; i<((int)floor(sqrt(numero)))+1; i++) {
    if(numero % i == 0){
        c += (numero/i == i) ? 1 : 2;
    }
}
    return c;
}

int MDC (int a, int b) {

    if(b == 0) return a;
    return MDC(b , a % b);

    return (b == 0) ? a : MDC(b, a % b);
}

int main () {
    int blabla = 0;
    int qtd = 0;
    int n1 = 0, n2 = 0;
    scanf("%d", &qtd);
    while (qtd--)
    {
        scanf("%d %d", &n1, &n2);
        printf("%d\n", countDivisors(MDC(n1, n2)));   
    }

}