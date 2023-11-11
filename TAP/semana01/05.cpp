#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main () {
    long int qsalas = 0;
    long int qbonus = 0;
    long int valorbonus = 0;
    long int indicesala = 0;
    long int tempodisponivel = 0;

    //vector<tipo>nome(tamanho);

    cin >> qsalas >> qbonus >> tempodisponivel;
    
    vector <long int> vetor (qsalas);

    for ( long int i = 0; i < qsalas-1; i++) {
        cin >> vetor[i];
    }

    for ( long int i = 0; i < qbonus; i++) {
        cin >> indicesala;
        cin >> valorbonus;
        vetor[indicesala-1] -= valorbonus;
    }

    for ( long int i = 0; i < qsalas-1; i++) {
        tempodisponivel -= vetor[i];
        if (tempodisponivel <= 0) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}