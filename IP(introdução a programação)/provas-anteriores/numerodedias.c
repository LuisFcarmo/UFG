#include <stdio.h>
int main () {
    int ano;
    int mes;
    int dia;
    double dias;
    int a;
    scanf("%d %d %d", &dia, &mes, &ano );
    if (ano % 4 == 00 && ano % 100 == 0 && ano % 400 == 0 || ano % 4 == 0 && ano % 100 != 0) {
        a = 29;
    }
    else {
        a = 28;
    }
    switch (mes)
    {
       case 1: {
         dias = dias;
         break;
       }
       case 2: {
        dias = 31 + dia;
        break;
       }
       case 3: {
        dias = 31 + a + dia;
        break;
       }
        case 4: {
        dias = 31 + a + 31 + dia;
        break;
       }
        case 5: {
        dias = 31 + a + 31 + 30 + dia;
        break;
       }
        case 6: {
        dias = 31 + a + 31 + 30 + 31 + dia;
        break;
       }
        case 7: {
        dias = 31 + a + 31 + 30 + 31 + 30 + dia;
        break;
       }
        case 8: {
        dias = 31 + a + 31 + 30 + 31 + 30 + 31 + dia;
        break;
       }
        case 9: {
        dias = 31 + a + 31 + 30 + 31 + 30 + 31 + 31 + dia;
        break;
       }
       case 10: {
        dias = 31 + a + 31 + 30 + 31 + 30 + 31 + 31 + 30 + dia;
        break;
       }
       case 11: {
        dias = 31 + a + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + dia;
       }
       case 12: {
        dias = 31 + a + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + dia;
       }
    }
    printf("%lf", dias);
    return 0;
}