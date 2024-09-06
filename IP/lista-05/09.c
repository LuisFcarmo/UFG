#include <stdio.h>
int matriz[1000][1000];
int maiorelemento(int vlinha, int vcoluna);
int menorelemento(int vlinha, int vcoluna);
int contaelementos(int vlinha, int vcoluna, int numero);
int main () { 
    int vlinha, vcoluna;
    int linha, coluna;
    int menor, maior;
    double fmenor, fmaior;
    scanf("%d %d", &vlinha, &vcoluna);
    for (linha = 0; linha < vlinha; linha++) {
        for (coluna = 0; coluna < vcoluna; coluna++) {
            scanf("%d", &matriz[linha][coluna]);        
        }
    }
    maior = maiorelemento(vlinha, vcoluna);
    menor = menorelemento(vlinha, vcoluna);
    fmaior = ((contaelementos(vlinha, vcoluna, maior)/(double)(vlinha*vcoluna))*100);
    fmenor = ((contaelementos(vlinha, vcoluna, menor)/(double)(vlinha*vcoluna))*100);
    
    printf("%d %.2lf%%\n", menor, fmenor);
    printf("%d %.2lf%%\n", maior, fmaior);
    return 0;
}
int maiorelemento(int vlinha, int vcoluna) {
    int maior = matriz[0][0];
    int linha = 0, coluna = 0;
    for (linha = 0; linha < vlinha; linha++) {
        for (coluna = 0; coluna < vcoluna; coluna++) {
            if (maior < matriz[linha][coluna]){
                maior = matriz[linha][coluna];
            }
        }
    }
    return maior;
};
int menorelemento(int vlinha, int vcoluna) {
    int menor = matriz[0][0];
    int linha = 0, coluna = 0;
    for (linha = 0; linha < vlinha; linha++) {
        for (coluna = 0; coluna < vcoluna; coluna++) {
            if (menor > matriz[linha][coluna]){
                menor = matriz[linha][coluna];
            }
        }
    }
    return menor;
};
int contaelementos(int vlinha, int vcoluna, int numero){
    int linha = 0, coluna = 0;
    int contador = 0;
    for (linha = 0; linha < vlinha; linha++) {
        for (coluna = 0; coluna < vcoluna; coluna++) {
            if (numero == matriz[linha][coluna]){
                contador++;
            }
        }
    }
    return contador;
};