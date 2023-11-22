#include <iostream>
long long int rodar (char matriz[100][100], int rows, int coluns, int ir, int ic, int total) {
    if (ir == rows-1) return total;
    else if (ic == coluns-1) {
        rodar(matriz, rows, coluns, ir++, ic, total++);
    }
    else if (matriz[ir][ic+1] == '.') {
        rodar(matriz, rows, coluns, ir, ic++, total++);
    }
    else if (matriz[ir][ic+1] == '#') {
        rodar(matriz, rows, coluns, ir++, ic, total++);
    }
}

int main () {
    int row; 
    int coluns;
    int linhas = 0;
    int colunas = 0;
    long long int square = 1;
    std::cin >> row >> coluns;
    char matriz[100][100];
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < coluns; k++) {
            std::cin >> matriz[i][k];
        }
    }  
    while (1) {
        if (linhas == row) break;
        else if (colunas == coluns-1 && matriz[linhas+1][colunas] == '.') {
            linhas++;
            square++;
        } else if (matriz[linhas][colunas+1] == '.') {
                colunas++;
                square++;
        } else if (matriz[linhas][colunas+1] == '#' && matriz[linhas+1][colunas] == '.') {
                linhas++;
                square++;
        } else if (matriz[linhas][colunas+1] == '#' && matriz[linhas+1][colunas] == '#') {
            break;
        }
    }
    
    std::cout << square;
    return 0;
}