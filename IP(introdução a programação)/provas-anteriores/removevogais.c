void remove_vogais (char *str, int *vogais) {
	int i = 0;
	int contadora = 0, contadore = 0, contadori = 0, contadoro = 0, contadoru = 0;
	while (str[i] != '\0'){
		if(str[i] == 'a' || str[i] == 'A'){
			str[i] = '-';
			contadora++;
		
		}
		if(str[i] == 'e' || str[i] == 'E'){
			contadore++;
			str[i] = '-';
		}
		if(str[i] == 'i' || str[i] == 'I'){
			contadori++;
			str[i] = '-';
		}
		if(str[i] == 'o' || str[i] == 'O'){
			contadoro++;
			str[i] = '-';
		}
		if(str[i] == 'u' || str[i] == 'U'){
			contadoru++;
			str[i] = '-';
		}
		i++;	
	}
	vogais[0] = contadora;
	vogais[1] = contadore;
	vogais[2] = contadori;
	vogais[3] = contadoro;
	vogais[4] = contadoru;
} 
	

#include<stdio.h>
int main () {
	char string[258];
	int i = 0;
	int qvogais[5];
	scanf("%[^\n]", string);
	remove_vogais(string, qvogais);
	while (string[i] != '\0'){
		if(string[i] != '-'){
		printf("%c", string[i]);
		}
		i++;
	}
	printf("\na: %d\n", qvogais[0]);
	printf("e: %d\n", qvogais[1]);
	printf("i: %d\n", qvogais[2]);
	printf("o: %d\n", qvogais[3]);
	printf("u: %d\n", qvogais[4]);

	
	return 0;
}

