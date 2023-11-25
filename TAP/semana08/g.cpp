#include <bits/stdc++.h>

using namespace std;

const int max_o = (int) 1e4 + 10;
const int max_i = 60;

int N;
int usados[max_i];
int notas[max_i][2];
int dp[max_o][max_i][max_i];


int banco(int o, int l){

    if(o == 0) return 1; 
    if(o < 0) return 0;
    if(l >= N) return 0; 

    if(dp[o][l][usados[l]] != -1){
        return dp[o][l][usados[l]];
    }

    if(usados[l] < notas[l][1]){
        usados[l]++;
        if(banco(o - notas[l][0], l)){
            return dp[o][l][usados[l]+1] = 1;
        }
        usados[l]--;
    }

    if(banco(o, l+1)){
        return dp[o][l][usados[l]] = 1;
    }
   return dp[o][l][usados[l]] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;

    cin >> N >> X;

    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k < max_i; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        cin >> notas[i][0] >> notas[i][1];
    }

    if(banco(X, 0)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
