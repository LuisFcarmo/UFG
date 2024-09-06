#include <stdio.h>
int main (){
    double matriz[2][2];
    int i = 0, j = 0;
    double dt;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    dt = (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]);
    printf("%.2lf", dt);
    return 0;
}