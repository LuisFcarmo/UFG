#include "iostream"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int x;
    int y;
    bool visitado;
} labirinto;

using namespace std;

int main () {
    int coluna = 0;
    int linha = 0;
    int xatual = 0;
    int yatual = 0;
    int temp = 0;

    cin >> coluna;
    cin >> linha;
    labirinto lb[coluna][coluna];

    for (int k = 0; k < linha; k++) {
        for (int l = 0; l < coluna; l++) {
            cin >> lb[k][l].x;
            cin >> lb[k][l].y;
        }
    }
   
    cin >> xatual;
    cin >> yatual;

    while (1) {
        if (lb[xatual][yatual].visitado == true) {
            cout << "PRESO";
            break;
        }
        if (lb[xatual][yatual].x == 0 && lb[xatual][yatual].y == 0) {
            cout << "VENCE";
            break;
        }
        lb[xatual][yatual].visitado = true;
        temp = xatual;
        xatual = lb[temp][yatual].x;
        yatual = lb[temp][yatual].y;

    }
    return 0;
}