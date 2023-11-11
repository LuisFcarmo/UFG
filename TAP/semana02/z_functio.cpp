#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

long int zfunc (string st, string buscar) {
    long int acertos = 0;
    long int index = 0;
    long int acumulador = 0;

    for (long int i = 0; i < st.size(); i++) {
        if (st[i] == buscar[index]) {
            acertos++;
            index++;
        } else {
            acertos = 0;
            index = 0;
        }
        if (acertos == buscar.size()) {
            acumulador++;
            acertos--;
            index = 0;
        }
    }
    return acumulador;
}

int main () {   
    string st, buscar;   
    long int i = 0;   
    getline(cin, st);
    getline(cin, buscar);

    i = zfunc(st, buscar);

    printf("%ld", i);

    return 0;
}