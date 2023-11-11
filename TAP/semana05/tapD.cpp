#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int binarySearch ( vector<int> v, int l , int r , int k ){
    while ( l <= r ){
        int c = ( l + r ) / 2;
        if ( v [c] == k ) return c ; // Is the key in position c?
        if ( v [c] < k )
        l = c + 1; // Ignore left half.
        else
        r = c - 1; // Ignore right half.
    }

    return -1; // The key is not in v.
}
*/

int busca(vector<int> v, int num){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == num) return i+1;       
    }
    
    return -1;
}

int main(){
    int n, q;
    int cont = 1;
    cin >> n >> q;
    
    

    while(n != 0 && q != 0){

        vector<int> mar (n);
        vector<int> qur (q);


        for(int i = 0; i < n; i++){
            cin >> mar[i];
        }
        sort(mar.begin(), mar.end());
        
        for(int j = 0; j < q; j++){
            cin >> qur[j];
        }
        cout << "CASE# " << cont << ":\n";
        for(int j = 0; j < q; j++){      
            if( busca(mar, qur[j]) != -1){
                cout << qur[j] << " found at " << busca(mar, qur[j]) << '\n';
            }else{
                cout << qur[j] << " not found\n"; 
            }
        }
        cont++;
        cin >> n >> q;
    }

    return 0;
}