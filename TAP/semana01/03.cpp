#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int strlen (string x) {
    int i = 0;
    while (1) {
        if (x[i] == '\0') break;
        i++;
    }
    return i;
}

int verifica (string x, string y, int index) {
    int contador = 0;
    int pa;
    for (int i = index; i < strlen(x); i++) {
        if (x[i] == y[contador]) {
            contador++;
        }
        else {
            break;
        }
    }
    if (contador == strlen(y)) return 1;
    else return 0;
}

int main () {
    string p1;
    string p2;

    cin >> p1;
    cin >> p2;
    
    int contador = 0;

    for (int i = 0; i < strlen(p1); i++) {
        if (p1[i] == p2[0]) {
            contador = verifica(p1, p2, i);
        }
        if (contador == 1) break;
    }
    if (contador == 1) printf("Yes");
    else printf("No");
    
}