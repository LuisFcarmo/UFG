#include <stdio.h>
int main () {
    int numerodev;
    int i, numero1, numero2;
    int cetena1, centena2;
    int c, d, u, c1, d1, u1, f1, f2;
    scanf ("%i", &numerodev);
    for (i = 0;i < numerodev; i++){
        scanf("%i %i", &numero1, &numero2);
        c = (numero1/100)%10;
        d = (numero1/10)%10;
        u = numero1%10;
        c1 = (numero2/100)%10;
        d1 = (numero2/10)%10;
        u1 = numero2%10;
        f1 = (u*100) + (d*10) + c;
        f2 = (u1*100) + (d1*10) + c1;
        if (f1 > f2){
            printf("%i\n", f1);
        }
        else {
            printf("%i\n", f2);
        }
    }
    return 0;
}