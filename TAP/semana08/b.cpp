#include <iostream>
#include <vector>
int main () {
    int nivel = 0;
    int x;
    int y;
    std::cin >> nivel >> x >> y;
    int nivelatual = nivel;

    std::vector <long long> red(nivel, 0);
    std::vector <long long> blue(nivel, 0);
    red[nivel-1] = 1;
        
    long long int acumulador;
    while (1) {
        if (nivelatual == 1) break;
        for (int i = 0; i < red.size(); i++) {
            blue[i] += red[i] * x;
            red[i-1] += red[i];
            red[i] = 0;
        }

        for (int i = 0; i < blue.size(); i++) {
            blue[i-1] += y * blue[i];
            red[i-1] += blue[i];
            blue[i] = 0;
        }
    }
    std::cout << blue[0] << red[0]<< "\n";

    return 0;
}