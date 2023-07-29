#include <stdio.h>
int pot (int expoente) {
	//essa funcao retorna a potencia na base 10 contudo ela considera o expoente 0
	// ela é personalizada
	int i = 0;
	int acumulador = 1;
	// se o expoente for 0 esse laço não entra pois qualquer numero elevado a zero tem o resultado 1
	for (i = 0; i < expoente; i++){
		acumulador = 10 * acumulador;
	}
	return acumulador;
}
int strlenn (char *numeroreal) {
	//aqui eu tentei reproduzir a strlen da bibliteca string.h contudo ela também é um pouco diferente
	//ela conta o tamanho da string contudo não considera '.' ou '-' porque no exercio eu preciso do valor
	//desconsiderando esses termos
	int contador = 0;
	int i = 0;
	while (numeroreal[i] != '\0'){
		if (numeroreal[i] != '.' && numeroreal[i] != '-'){
			contador++;
		}
		i++;
	}	
	return contador-1;
}
double stringtodouble (char *numeroreal) {
	double numero;
	int contador; 
	int i = 0;
	int k = 0;
	int tamanho = strlenn(numeroreal);
	while(numeroreal[i] != '\0') {
		//aqui eu faço a conversão direta do numero retirando o '0' e multiplicando tudo pela potencia de 10 referente
		//exemplo 1.001 vai virar 1001 pois a função strlenn retorna 4 e isso vai elevado na potência exemplo do que acontece
		// (iteração 1 1*1000) + (iteração 2 0*100) + (iteração 3 0*10) + (iteração 4 1*1) 
		if(numeroreal[i]!= '.' && numeroreal[i] != '-'){
			numero += (numeroreal[i] - '0') * (pot(tamanho-k));
			contador++;
			k++;
		}
		// aqui eu trato o caso do numero apresentar . oque significa que eu preciso dividir o valor bruto pela potência de 10
		// repesctivo a quantidade de numeros após a virgula vamos tratar o exemplo anterior 1.001 até essa parte do codigo ele
		// tem o valor de 1001 pois foi multiplicado pelas potências desconsiderando o a parte fracionaria logo, eu conto
		// quantos numeros apos o . existem no caso 3 que é o expoente da potência de 10 
		if(numeroreal[i] == '.' || numeroreal[i] == '-') {
			contador = 0;
		}
		i++;
		}	
		// aqui eu verifico se o numero tem . porque caso ele não tenha contador dele vai ser igual ao tamanho da string
		// se for diferente eu divido o numero
		if(contador != (tamanho+1)) {
			numero = numero/(pot(contador));
	}
	return numero;
}
int main () {
	double numero;
	char numeroreal[128];
	
	while (scanf("%[^\n]%*c\n", numeroreal)!= EOF){
		numero = stringtodouble(numeroreal);
		//imprimindo os resultados
		if(numeroreal[0] == '-'){
			printf("%.3lf %.3lf\n", (numero*-1), ((numero+numero)*-1));
		} else {
			printf("%.3lf %.3lf\n", (numero), (numero+numero));
		}
	}
	return 0;
}
