    #include <stdio.h>
    #include <stdlib.h>
    typedef struct {
        int encima;
        int embaixo;
    } racional;
    int MDC (racional a) {
       int resto;
       a.encima =  abs(a.encima);
       a.embaixo = abs(a.embaixo);
       while (a.embaixo != 0) {
            resto = a.encima % a.embaixo;
            a.encima = a.embaixo;
            a.embaixo = resto;
       }
       return a.encima;
    }
     
    int MMC (racional a, racional b) {
        int baixo1 = abs(a.embaixo);
        int baixo2 = abs(b.embaixo);
        int contador = 2;
        int mmc = 1;
        int boleano1 = 0, boleano2 = 0;
        while (1)
        {
            if (baixo1%contador == 0) {
                baixo1 /= contador;
                boleano1 = 1;
            } else {
                boleano1 = 0;
            } 
            if (baixo2%contador == 0) {
                baixo2 /= contador;
                boleano2 =1;
            } else {
                boleano2 = 0;
            }
            if (boleano1 == 1 || boleano2 == 1) {
                mmc *= contador;
            }
            if (boleano1 == 0 && boleano2 == 0) {
                contador++;
            }
            if ((baixo1 == 1 && baixo2 == 1)) {
                break;
            }
        }    
        return mmc;
    }
    racional  simplificafrac (racional a) {
        racional resultado;
        int mdc = MDC(a);
        resultado.encima = a.encima/mdc;
        resultado.embaixo = a.embaixo/mdc;
        return resultado;
    }
    racional somaracional (racional a, racional b) {
        racional somado;
        int mmc = MMC(a,b);
        somado.encima = ((mmc/a.embaixo)*a.encima) + ((mmc/b.embaixo)*b.encima);
        somado.embaixo = mmc;
        return simplificafrac(somado);
    };
    racional subracional (racional a, racional b) {
        racional somado;
        int mmc = MMC(a,b);
        somado.encima = ((mmc/a.embaixo)*a.encima) - ((mmc/b.embaixo)*b.encima);
        somado.embaixo = mmc;
        return simplificafrac(somado);
    }
    racional multfrac (racional a, racional b) {
        racional somado;
        somado.encima = (a.encima*b.encima);
        somado.embaixo = (a.embaixo*b.embaixo);
        return simplificafrac(somado);
    }
    racional divracional (racional a, racional b) {
        racional somado;
        somado.encima = (a.encima*b.embaixo);
        somado.embaixo = (a.embaixo*b.encima);
        return simplificafrac(somado);
    }
     
    int main () {
        racional a;
        racional b;
        racional resultado;
        char opera;
        while (EOF != scanf("%d %d %c %d %d", &a.encima, &a.embaixo, &opera, &b.encima, &b.embaixo)) {
            switch (opera)
            {
            case '+':
                resultado = somaracional(a, b);
                break;
            
            case '-':
                resultado = subracional(a, b);
                break;
            
            case '*':
                resultado = multfrac(a, b);
                break;
            case '/':
                resultado = divracional(a, b);
                break;
            }
            printf("%d %d\n", resultado.encima, resultado.embaixo);
        }
        return 0;
    }