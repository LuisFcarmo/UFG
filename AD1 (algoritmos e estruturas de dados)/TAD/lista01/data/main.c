#include <stdio.h>
#include "data.h"
int main () {
    int i = 0;
    char *string = (char*) malloc(sizeof(char)*8);
    Data d = criaData(31, 12, 1902);
    print_data(d);
    string = imprimeData(d, "aaaammdd");
    printf("%d", i);
    //blabla = comparaData(d, d2);
    return 0;
}