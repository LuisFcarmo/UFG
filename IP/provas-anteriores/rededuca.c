#include <math.h>
#include <stdio.h>
double seno (double ag) {
    return sin(ag);
}
double coss (double ag) {
    return cos(ag); 
}
int main () {
    int angulo;
    char senoco;
    double andgulocp;
    scanf("%d %c", &angulo, &senoco);
    if (angulo > 90){
    andgulocp = angulo%90;}
    else {andgulocp = angulo;}
    printf("%lf", andgulocp);
    if (senoco == 'S') {
        printf("%lf",seno(andgulocp)*-1);
        if (angulo <= 180 && angulo >= 0){
            printf("sinaligual");
        }
        else {
            printf("sinalinvertido");
        }
    }
    if (senoco == 'C') {
        printf("%lf", coss(andgulocp)*-1);
        if (angulo >= 0 && angulo <= 90){
            printf("sinal igual");

        }
        
        else {
            printf("sinal invertido");
        }
    }
    return 0;
}