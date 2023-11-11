#include <iostream>
using namespace std;
int main () {
    string palavra;
    cin >> palavra;
    for (int i = 0; i < palavra.size(); i++) {
        palavra[i] -= 32;
    }
    cout << palavra;

    return 0;
}