#include <stdio.h>
void inv_vetor(int *v, int i, int f) {
    if(i>=f) return;
    int t = v[i];
    v[i] = v[f];
    v[f] = t;
    inv_vetor(v,i+1,f-1);
}

//definição recursiva: inv_vetor(v,i,f) = -return, i>=f
//                                        -t = v[i];
//                                         v[i] = v[f];
//                                         v[f] = t;

 int times_k(int K, int N, int i) {
    if(N==0) return i;
    int n = N/10;
    if(K == N % 10) i++;
    times_k(K,n,i);
}

int main () {
    printf("%d", times_k(2,762021192,0));
    return 0;
}