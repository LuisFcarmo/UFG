#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void mmc (int a, int b, vector <int> lista, int n_termo) {
    int parada;
    int contador = 0;
    int divisor = 0;
    if (a > b) {
        parada = b;
    } else {
        parada = a;
    }
    while (parada != divisor)
    {
        divisor++;
        if (a % divisor == 0 && b % divisor == 0) {
            lista.push_back(divisor);
        }
    }
    
    cout << lista[lista.size()- n_termo] << endl;
   
}

int main () {
    int numero1;
    int numero2;
    int n_termo;
    vector <int> lista(0);
    cin >> numero1 >> numero2 >> n_termo;
    mmc(numero1, numero2, lista, n_termo);

}   