    #include <stdio.h>
    #include <stdlib.h>
    typedef struct {
        int p, o;
    }f;
    int main () {
        int l, t, m, n;
        char final;
        f *ponteiro;
        int vezes = 0, boleano = 0;
        int tamanho, ty = 0;
        scanf("%d", &vezes);
        while (vezes--){
            tamanho = 0;
            boleano = 0;
            ty++;
            while (1) {
                scanf("%d/%d%c", &l, &t, &final);
                tamanho++;
                ponteiro = (f*) (realloc(ponteiro,tamanho*sizeof(f)));
                ponteiro[tamanho-1].p = l;
                ponteiro[tamanho-1].o = t;
                if (final == '\n') break;
            }
            printf("Caso de teste %d\n", ty);
            for (m = 0; m < tamanho; m++){
                for (n = m; n < tamanho; n++) {
                    if(n > m) {
                    if ((ponteiro[m].p/(double)ponteiro[m].o)==(ponteiro[n].p/(double)ponteiro[n].o)) {
                        printf("%d/%d equivalente a %d/%d\n", ponteiro[m].p, ponteiro[m].o, ponteiro[n].p, ponteiro[n].o);
                        boleano = 1;
                    }
                    }
                }
            }
                if (!boleano) printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        
        return 0;
    }