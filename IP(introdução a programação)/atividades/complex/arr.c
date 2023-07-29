    #include <stdio.h>
    #include <stdlib.h>
    typedef struct {
        int numerador;
        int denominador;
    } frac;

    int main () {
        frac *vetordinamico;
        double numerador, denominador;
        char final;
        int contador = 0;
        int qvezes = 0;
        int i = 0, k = 0;
        int boleano = 0;
        scanf("%d", &qvezes);
        for (i = 0; i < qvezes; i++) {
        printf("Caso de teste %d\n", i+1);
                boleano = 0;
            contador = 0;
            while (1)
            {
                scanf("%d/%d%c", &numerador, &denominador, &final);
                contador++;
                vetordinamico = (frac*) realloc(vetordinamico, contador * sizeof(frac));
                vetordinamico[contador-1].numerador = numerador;
                vetordinamico[contador-1].denominador = denominador;
                if(final == '\n') break;
            }
            for (i = 0; i < contador; i++) {
                for (k = i+1; k < contador; k++) {
                    if ((vetordinamico[i].numerador/(double)vetordinamico[i].denominador) == (vetordinamico[k].numerador/(double)vetordinamico[k].denominador)) {
                        printf("%d/%d equivalente a %d/%d\n", vetordinamico[i].numerador, vetordinamico[i].denominador, vetordinamico[k].numerador, vetordinamico[k].denominador);
                        boleano = 1;
                    }
                }
            }
             if (!boleano) {
             printf("Nao ha fracoes equivalentes na sequencia\n");
             }
        }
        
        return 0;
    }