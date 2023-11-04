#include <iostream>

using namespace std;

const char O = 'O';
const char D = 'D';
const char A = 'A';

void tower(int n, char origem, char destino, char auxiliar) {
  if (n == 1) {
    cout << "(" << origem << "," << destino << ")\n";
  } else {
    tower(n - 1, origem, auxiliar, destino);
    cout << "(" << origem << "," << destino << ")\n";
    tower(n - 1, auxiliar, destino, origem);
  }
}

int main() {
  int n;
  cin >> n;

  tower(n, O, D, A);

  return 0;
}
