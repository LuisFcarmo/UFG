#include <iostream>

using namespace std;


void tower(int n) {
  if (n == 1) {
    //cout << origem << destino;
  } else {
    tower(n - 1, origem, auxiliar, destino);
    //cout << origem << destino;
    tower(n - 1, auxiliar, destino, origem);
  }
}

int main() {
  int n;
  cin >> n;

  tower(n);

  return 0;
}
