#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm> 
using namespace std;

typedef struct {
    std::string nome;
    long long int altura;
} montain;

int main () {
    vector <montain> array;
    montain x;
    int qtd;
    cin >> qtd;
    int maior = 0;

    while (qtd--) {
        cin >> x.nome;
        cin >> x.altura;
        if (x.altura > maior) maior = x.altura;
        array.push_back(x);
    }
    
    x.altura = 0;
    for(int i = 0; i < array.size(); i++) {
        if (array[i].altura != maior){
            if (x.altura < array[i].altura) {
                x = array[i];
            }
        }
    }
    cout << x.nome << " " << x.altura;
}