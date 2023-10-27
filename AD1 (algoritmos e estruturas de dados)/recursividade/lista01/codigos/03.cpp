#include "iostream"
using namespace std;

int a (int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0 && m > 0) {
        return a(m-1, 1);
    }
    else if (n > 0 && m > 0) {
        return a(m-1, a(m, n-1));
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << a(n, m);
}