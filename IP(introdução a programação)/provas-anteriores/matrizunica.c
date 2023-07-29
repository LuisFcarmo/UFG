#include <stdio.h>
int main () {
	int matriz[10][10];
	int vetor[100];
	int indice = 0;
	int linha = 0, coluna = 0;
	int linhatamanho = 0, colunatamanho = 0;
	int contador = 0;
	int valor = 0;
	int i, k;

	scanf("%d %d", &linhatamanho, &colunatamanho);
	for (linha = 0; linha < linhatamanho; linha ++) {
		for (coluna = 0; coluna < colunatamanho; coluna++){
			scanf("%d", &valor);
			matriz[linha][coluna] = valor;
		}
	}
	for (linha = 0; linha < linhatamanho; linha ++) {
		for (coluna = 0; coluna < colunatamanho; coluna++){
			vetor[indice] = matriz[linha][coluna];
			indice++;
		}
	}
	for (i = 0; i < (linhatamanho*colunatamanho); i++){
		for (k = 0; k < (linhatamanho*colunatamanho); k++){
			if(vetor[i] == vetor[k]){
				contador++;
			}
			}
			if (contador == 1) {
				printf("elemento unico %d\n", vetor[i]);
			
			}
			contador = 0;
		}
	return 0;
}	

