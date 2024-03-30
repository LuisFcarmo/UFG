#include <iostream>
using namespace std;

bool malignidade_linha (char matriz[][11], int linha, int coluna) {
    for (int k = 0; k < coluna; k++) {
        if (matriz[linha][k] == 'S') {
            return false;
        }
    }
    return true;
}

bool malignidade_coluna (char matriz[][11], int linha, int coluna) {
    for (int k = 0; k < linha; k++) {
        if (matriz[k][coluna] == 'S') {
            return false;
        }
    }
    return true;
}

int main () {
    bool comidas[11][11];
    char matriz[11][11];
    int linha;
    int coluna;
    int v = 0;
    cin >> linha >> coluna;
    
    malignidade_coluna(matriz, 0, coluna);

    for (int i = 0; i < linha; i++) {
        for (int k = 0; k < coluna; k++) {
            cin >> matriz[i][k];
        }
    }

    for (int i = 0; i < linha; i++) {
        if (malignidade_linha(matriz, i, coluna)) {
            for (int k = 0; k < coluna; k++) {
                matriz[i][k] = 'l';
            }
        }
    }
    // dkskdakskdakd
    for (int i = 0; i < coluna; i++) {
        if (malignidade_coluna(matriz, linha, i)) {
            for (int k = 0; k < coluna; k++) {
                matriz[i][k] = 'l';
            }
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int k = 0; k < coluna; k++) {
            if (matriz[i][k] != 'l') {
                v++;
            }
        }
    }

    cout << v;
     
    
    return 0;
}