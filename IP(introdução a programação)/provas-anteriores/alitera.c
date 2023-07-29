#include <stdio.h>
int verificaalitera (char *string) {
	int i = 0;
	int contador = 0;
	int segundastring;
	char fixo;	
	int alitera;
	fixo = string[0];
	while(string[i] != '\0') {
		if(string[i] == ' ') {
			if(fixo == string[i+1] || fixo == (string[i+1]+32)){
				contador++;
				if(contador == 1) {
				alitera++;
				}
			}
			if(fixo != string[i+1] && fixo+32 != string[i+1]) {
				fixo = string[i+1];
				contador = 0;
			}
		}
		i++;
	}
	return alitera;
}
int main () {
	char string[50];
	int resposta;
	scanf("%[^\n]", string);
	resposta = verificaalitera(string);
	printf("%d", resposta);
	return 0;
}
