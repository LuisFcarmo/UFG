#include <iostream>

using namespace std;

int main () {
    string buscar;
    string st;
    int index = 0;
    int maioriguais = 0;
    int iguais = 0;

    getline(cin, st);
    getline(cin, buscar);

    for (int i = 0; i < st.size(); i++) {
        if (iguais > maioriguais) {
            maioriguais = iguais;
        }
        if (st[i] == buscar[index]) {
            iguais++;
            index++;
        } else {
            iguais = 0;
            index = 0;
        }
    }
    if (maioriguais == 0) {
        cout << buscar.size() - maioriguais-1;
    } else {
        cout << buscar.size() - maioriguais;
    }
}   