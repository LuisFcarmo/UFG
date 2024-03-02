#include <iostream>
#include <cmath>
int main () {
    long long largura;
    long long altura;
    long long dm_q;
    long long n_l;
    long long a_l;

    std::cin >> largura >> altura;
    std::cin >> dm_q;
    n_l = ceil((double)largura/dm_q);
    a_l = ceil((double)altura/dm_q);
    std::cout << (n_l*a_l);

}