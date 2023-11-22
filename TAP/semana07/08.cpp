#include <iostream>
#include <iomanip>
#include <set>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int passo, modulo;

    while (std::cin >> passo >> modulo) {
        std::set<int> generated;
        int current = 0;

        for (int i = 0; i < modulo; ++i) {
            current = (current + passo) % modulo;

            if (generated.count(current) > 0) {
                std::cout << std::setw(10) << passo << std::setw(10) << modulo << "    Bad Choice\n\n";
                goto next_test;
            }   

            generated.insert(current);
        }

        std::cout << std::setw(10) << passo << std::setw(10) << modulo << "    Good Choice\n\n";

        next_test:;
    }

    return 0;
}

/*
    10 espacos, 10 espacos, 4 espacos + a letra
*/