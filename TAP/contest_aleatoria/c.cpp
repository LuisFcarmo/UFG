#include <iostream>
int main () {
    int number;
    int init;
    std::cin >> init;
    for (;init < 1000; init++) {
        if (init % 10 == (init/100 * ((init - 100*(init/100))/10))) {
            break;
        }
    }
    std::cout << init;
    return 0;
}