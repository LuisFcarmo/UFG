#include <iostream>
using namespace std;

int main () {
    string st;
    char aux;
    bool ba = false;
    while (1) {
        if (st[0] == st[st.size()-1]) {
            aux = st[st.size()-1];
            for (int i = st.size()-1; i > 0; i--) {
                st[i] = st[i-1];
            }
            st[0] = aux;
            ba = true;
        }
        if (st[0] > st[st.size()-1]) {
            aux = st[0];
            st[st.size()-1] = st[0];
            st[st.size()-1] = aux;
            ba = true;
        } 
        if (ba == false) {
            break;
        }
    }
    cout << st;

    return 0;
}