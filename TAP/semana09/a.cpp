#include "iostream"
#include "vector"
using namespace std;
long long int dp (vector <long long int> &v) {

}

int main () {
    vector <long long int> vet(100000);
    vector <long long int> vetx(100003);
    vetx[100002] = 0;
    vetx[100001] = 0;
    long long int i = 0;
    long long int num = 0;
    cin >> i;
    long long int index;
    for (int k = 0; k < i; k++) {
        cin >> num;
        vet[num-1] += num;
    }
 
    
}
