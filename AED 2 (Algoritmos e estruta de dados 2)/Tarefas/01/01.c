#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define MAXLinha 50
#define MAXColuna 1

typedef struct {
    int matricula;
    char nome[51];
    char curso[51];
    double nota01;
    double nota02;
} registro;

typedef struct {
    int size;
    registro **matriz;
} head;

registro **Criar_matriz(int linha, int coluna) {
    registro **matriz;
    matriz = (registro **) calloc(sizeof(registro *), linha);
    if (matriz == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < linha; i++) {
        matriz[i] = (registro *) calloc(sizeof(registro), coluna);
        if (matriz[i] == NULL) {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    return matriz;
}

int tamanho(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

head Criar_Banco() {
    head x;
    x.matriz = Criar_matriz(MAXLinha, MAXColuna);
    x.size = 0;
    return x;
}

registro Criar_registro() {
    registro novo;
    int matricula;
    double nota01, nota02;
    char string[51];

    while (1) {
        while (1) {
            printf("Insira o numero de matricula\n");
            scanf("%d%*c", &matricula);
            if (matricula < 0) {
                printf("matricula invalida insira um numero positivo\n");
                continue;
            }
            else {
                novo.matricula = matricula;
                break;
            }
        }
        while (1) {
            printf("Insira a nota01\n");
            scanf("%lf%*c", &nota01);
            if (nota01 < 0 || nota01 > 10) {
                printf("a nota deve estar em um intervalo de 0 a 10\n");
            }
            else {
                novo.nota01 = nota01;
                break;
            }
        }
        while (1) {
            printf("Insira a nota02\n");
            scanf("%lf%*c", &nota02);
            if (nota02 < 0 || nota02 > 10) {
                printf("a nota deve estar em um intervalo de 0 a 10\n");
            }
            else {
                novo.nota02 = nota02;
                break;
            }
        }
        while (1) {
            printf("Insira o seu nome\n");
            scanf("%50[^\n]%*c", string);
            if (tamanho(string)-1 < 0) {
                printf("O nome está vazio\n");
            }
            else {
                strcpy(novo.nome, string);
                break;
            }
        }
        while (1) {
            printf("Insira o nome do curso\n");
            scanf("%50[^\n]%*c", string);
            if (tamanho(string)-1 < 0) {
                printf("O nome do curso está vazio\n");
            }
            else {
                strcpy(novo.curso, string);
                break;
            }
        }
        break;
    }
    return novo;
}

bool Dado_Existente(int matricula, head *ref) {
    for (int i = 0; i < MAXLinha; i++) {
        if (matricula == ref -> matriz[i][0].matricula) {
            return 1;
        }
    }
}

int Inserir_registro (registro x, head *ref) {
    if (!Dado_Existente(x.matricula, ref)){
        ref -> matriz[ref->size][0] = x;
        ref -> size++;
    } else {
        printf("impossivel adicionar usuario presente no banco\n");
    }
}

void Imprimir_Registro(registro x) {
    printf("\n");
    printf("----------------------------------------------------------\n");
    printf("- matricula = %d                                          \n", x.matricula);
    printf("- nota 01 = %lf                                           \n", x.nota01);
    printf("- nota 02 = %lf                                           \n", x.nota02);
    printf("- Nome do Curso = %s                                      \n", x.curso);
    printf("- Nome do Aluno = %s                                      \n", x.nome);
    printf("- Media do Aluno = %.2lf                                  \n", 
        (x.nota01 + x.nota02)/2
    );
    printf("----------------------------------------------------------\n"),

    printf("\n");
}

void Imprimir_Dados (head *banco) {
    for (int i = 0; i < banco -> size; i++) {
       Imprimir_Registro(banco -> matriz[i][0]);
    }
}

registro Pegar_Registro(int matricula, head *ref) {
    registro x;
    for (int i = 0; i < ref -> size; i++) {
        if (matricula == ref -> matriz[i][0].matricula) {
            return ref -> matriz[i][0];
        }
    }
    return x;
}

void Liberar_Memoria(head *ref) {
    registro *x;
    if (ref != NULL) {
        for (int i = 0; i < ref -> size; i++) {
            x = &(ref -> matriz[i][0]);
            free(x);
        }

        free(ref -> matriz);
    } else {
        printf("Impossivel deletar a matriz ela está vazia\n");
    }
}

registro **deletar_registro(head *ref, int matricula) {
    registro **Nova_Matriz = Criar_matriz(ref -> size-1, 1);
    int indice = 0;
    for (int i = 0; i < ref -> size; i++) {
        if (ref -> matriz[i][0].matricula != matricula) {
            Nova_Matriz[indice][0] = ref -> matriz[i][0];
            indice++;
        } else {
            continue;
        }
    }
    Liberar_Memoria(ref);
    ref -> size--;
    return Nova_Matriz;
};


void Deletar_Dado (int matricula, head *ref) {
    int opc = 0;
    if (Dado_Existente(matricula, ref)) {
        printf("Usuario existente deseja deletar (1 SIM) (2 NÃO) ?\n");
        scanf("%d%*c", &opc);
        if (opc == 1) {
            ref -> matriz = deletar_registro(ref, matricula);
        } else {
            printf("Usuário mantido\n");
        }
    } else {
        printf("Usuário não está presente no banco\n");
    }
}

int update(int matricula, head *ref, registro novo) {
    for (int i = 0; i < ref -> size; i++) {
        if(ref -> matriz[i][0].matricula == matricula) {
            ref -> matriz[i][0] = novo;
            return 1;
        }
    }
    return 2;
}

int main() {
    head banco = Criar_Banco();
    for (int i = 0; i < 8; i++) {   
        registro x = Criar_registro();
        Inserir_registro(x, &banco);
    }

    registro b;
    strcpy(b.curso, "matematica");
    b.matricula = 8;
    strcpy(b.nome, "matheus");
    b.nota01 = 5;
    b.nota02 = 9;


    Imprimir_Dados(&banco);
    update(8, &banco, b);
    Imprimir_Dados(&banco);

    printf("\n");
 


    return 0;
}
