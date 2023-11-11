#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main () {
    int qtd;
    int valor;
    int anterior;
    cin >> qtd;
    vector <int> vetor(qtd);
    for (int i = 0; i < qtd; i++) {
        if (i == 0) {
            cin >> valor;
            vetor[i] = valor;
            anterior = valor;
        } else {
            cin >> valor;
            vetor[i] = valor + anterior;
            anterior = valor + anterior;
        }
    }
    
    cin >> qtd;

    for (int i = 0; i < qtd; i++) {
        cin >> valor;
        cout << lower_bound(vetor.begin(), vetor.end(), valor)-vetor.begin()+1 << endl;
    }
    




    

    return 0;
}