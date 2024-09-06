#include <stdio.h>
#include <stdlib.h>
int main (){
	int *vetor;
	int valor;
	int tamanho, metadeprimeira = 0, segundametade = 0;
	int acumulador = 0;
	double media;
	int i;
	scanf("%d", &tamanho);
	vetor = (int*)(calloc(tamanho, sizeof(int)));
	for(i = 0; i < tamanho; i++){
		scanf("%d", &valor);
		vetor[i] = valor;
		acumulador += valor;
	}
	media = acumulador/tamanho;
	printf("%lf\n", media);
	
	if (tamanho % 2 == 0) {
		for (i = 0;i < (tamanho/2); i++){
			if(vetor[i] > media) {
				metadeprimeira++;
			}
		}
		for (i = (tamanho/2); i <= tamanho; i++){
			if(vetor[i] > media) {
				segundametade++;
			}
		}
	
	} else {
		for (i = 0; i < (tamanho/2); i++){
			if(vetor[i] > media) {
				metadeprimeira++;
			}
		}
		for (i = ((tamanho/2)+1); i < tamanho; i++){
			if(vetor[i] > media){
				segundametade++;
			}
		}
	}
	if(segundametade > metadeprimeira) {
		printf("%.2lf %d %d SEGUNDA METADE", media, metadeprimeira, segundametade);
	}
	if (metadeprimeira > segundametade){
		printf("%.2lf %d %d PRIMEIRA METADE", media, metadeprimeira, segundametade);
	}

	if(metadeprimeira == segundametade) {
		printf("EMPATE\n");
	}

	return 0;
}
