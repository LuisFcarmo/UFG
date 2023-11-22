#include <stdio.h>

long int modulo = 1e9+7;
long int pot(int a, int b){
    if(b == 0) return 1;

    int p = pot(a, b>>1);

    p = ((p%modulo) * (p%modulo)) % modulo;

    if(b&1 == 1)
        p = ((p % modulo) * (a % modulo)) % modulo;

    return p;
}

int main(){
    int quantidade, n, numero;
    char encontrou = 0;

    scanf("%d", &quantidade);

    while(quantidade--){
        scanf("%d", &n);

        if(n%2 == 0){
            printf("%d %d\n", 1, n/2);
            continue;
        }
        if(n&1==1){
            printf("-1\n");
            continue;
        }

        encontrou = 0;
        for(int x = 2; x <= n; x++){
            for(int y = x; y <= n; y++){
                numero = (pot(x, y)*y);
                if(numero >= n) break;

                numero += pot(y,x)*x;
                if( numero == n){
                    printf("%d %d\n", x, y);
                    encontrou = 1;
                    break;
                }
                else if(numero > n) break;
            }
            if(encontrou == 1) break;
        }

        if(encontrou == 0) printf("-1\n");   

    }

    return 0;
}