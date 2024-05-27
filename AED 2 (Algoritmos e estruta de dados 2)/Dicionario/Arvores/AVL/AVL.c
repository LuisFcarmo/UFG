#include "AVL.h"

/*implementação sem verificação da alocação de memoria feita apenas com fins didaticos*/
typedef struct {
    bool direita;
    bool esquerda;
    int qtd;
}
Resp;

NoArv * Cria_No(int x) {
    NoArv * new = (NoArv * ) malloc(sizeof(NoArv));
    new -> valor = x;
    new -> esquerda = NULL;
    new -> direita = NULL;
    new -> altura = 0;
    return new;
}

Resp Criar_Resp(int qtd, bool direta, bool esquerda) {
    Resp x;
    x.qtd = qtd;
    x.direita = direta;
    x.esquerda = esquerda;
    return x;
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int AlturaDoNo(NoArv * no) {
    return (no == NULL) ? -1 : no -> altura;
}

int FatorDeBalanceamento(NoArv * no) {
    if (no) {
        return (AlturaDoNo(no -> esquerda) - AlturaDoNo(no -> direita));
    } else {
        return 0;
    }
}

/*
    encontrar altura da nossa arvore
*/
int altura(NoArv * root) {
    if (root == NULL)
        return -1;
    else {
        int esquerda = altura(root -> esquerda);
        int direita = altura(root -> direita);
        if (esquerda > direita) {
            return esquerda + 1;
        } else {
            return direita + 1;
        }
    }
}

NoArv * RotacaoDireita(NoArv * NoDesbalanceado) {
    NoArv * y, * filho;
    y = NoDesbalanceado -> esquerda;
    filho = y -> direita;

    y -> direita = NoDesbalanceado;
    NoDesbalanceado -> esquerda = filho;

    //pegando a maior altura da arvore a esquerada e direita e somando um nelas
    NoDesbalanceado -> altura = maior(AlturaDoNo(NoDesbalanceado -> esquerda), AlturaDoNo(NoDesbalanceado -> direita)) + 1;
    y -> altura = maior(AlturaDoNo(y -> esquerda), AlturaDoNo(y -> direita)) + 1;

    return y;
}

NoArv * RotacaoEsquerda(NoArv * NoDesbalanceado) {
    NoArv * y, * filho;
    y = NoDesbalanceado -> direita;
    filho = y -> esquerda;

    y -> esquerda = NoDesbalanceado;
    NoDesbalanceado -> direita = filho;

    //pegando a maior altura da arvore a esquerada e direita e somando um nelas
    NoDesbalanceado -> altura = maior(AlturaDoNo(NoDesbalanceado -> esquerda), AlturaDoNo(NoDesbalanceado -> direita)) + 1;
    y -> altura = maior(AlturaDoNo(y -> esquerda), AlturaDoNo(y -> direita)) + 1;
    return y;
}

// direita esquerda // equerda direita
NoArv * RotacaoDireitaEsquerda(NoArv * NoDesbalanceado) {
    NoDesbalanceado -> direita = RotacaoDireita(NoDesbalanceado -> direita);
    return RotacaoEsquerda(NoDesbalanceado);
}

NoArv * RotacaoEsquerdaDireita(NoArv * NoDesbalanceado) {
    NoDesbalanceado -> esquerda = RotacaoEsquerda(NoDesbalanceado -> esquerda);
    return RotacaoDireita(NoDesbalanceado);
}

NoArv * balancear(NoArv * raiz) {
    short fb = FatorDeBalanceamento(raiz);
    if (fb < -1 && FatorDeBalanceamento(raiz -> direita) <= 0) {
        raiz = RotacaoEsquerda(raiz);
    } else if (fb > 1 && FatorDeBalanceamento(raiz -> esquerda) >= 0) {
        raiz = RotacaoDireita(raiz);
    } else if (fb > 1 && FatorDeBalanceamento(raiz -> esquerda) < 0) {
        raiz = RotacaoEsquerdaDireita(raiz);
    } else if (fb < -1 && FatorDeBalanceamento(raiz -> direita) > 0) {
        raiz = RotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

//inserir balanceado
NoArv *inserir(NoArv *raiz, int x) {
    if (raiz == NULL) {
        return Cria_No(x);
    } else {
        if (x < raiz->valor) {
            raiz->esquerda = inserir(raiz->esquerda, x);
        } else if (x > raiz->valor) {
            raiz->direita = inserir(raiz->direita, x);
        } else {
            printf("Inserção não realizada. O elemento %d já existe.\n", x);
        }
    }

    raiz->altura = maior(AlturaDoNo(raiz->esquerda), AlturaDoNo(raiz->direita)) + 1;
    
    // Verifica se a árvore precisa de balanceamento
    int fb = FatorDeBalanceamento(raiz);
    if (fb > 1 || fb < -1) {
        raiz = balancear(raiz);
    }
    
    return raiz;
}


void imprimir(NoArv * raiz, int nivel) {
    int i;
    if (raiz) {
        imprimir(raiz -> direita, nivel + 1);
        printf("\n\n");
        for (int i = 0; i < nivel; i++) {
            printf("\t");
        }
        printf("%d", raiz -> valor);
        imprimir(raiz -> esquerda, nivel + 1);
    }
}

Resp Qtd_Filhos(NoArv * root, int chave) {
    if (root != NULL) {
        Resp x;
        if (root -> valor == chave) {
            if (root -> direita != NULL && root -> esquerda != NULL) {
                x = Criar_Resp(2, true, true);
            } else if (root -> direita == NULL && root -> esquerda != NULL) {
                x = Criar_Resp(1, false, true);
            } else if (root -> direita != NULL && root -> esquerda == NULL) {
                x = Criar_Resp(1, true, false);
            } else {
                x = Criar_Resp(0, false, false);
            }

            return x;
        } else {
            if (chave > root -> valor) {
                Qtd_Filhos(root -> direita, chave);
            } else {
                Qtd_Filhos(root -> esquerda, chave);
            }
        }
    } else {
        printf("Nó não esta presente na arvore");
    }
}

NoArv * Remover(NoArv * root, int chave) {
    if (root != NULL) {
        if (root -> valor == chave) {
            // aqui apenas removemos nós folhas
            if (root -> esquerda == NULL && root -> direita == NULL) {
                free(root);
                return NULL; // retorna nulo pras chamadas recursivas coloca nulo no ponteiro que apontava para este nó folha
            } else {
                Resp x = Qtd_Filhos(root, chave);
                NoArv * aux = NULL;
                if (x.qtd == 1) {
                    if (x.direita) {
                        aux = root -> direita;
                    } else {
                        aux = root -> esquerda;
                    }
                    free(root);
                    return aux;
                } else {
                    NoArv * aux = root -> esquerda;
                    while (aux -> direita != NULL) aux = aux -> direita;
                    root -> valor = aux -> valor;
                    aux -> valor = chave;
                    root -> esquerda = Remover(root -> esquerda, chave);
                    return root;
                }
            }
        } else {
            if (chave < root -> valor) {
                root -> esquerda = Remover(root -> esquerda, chave);
            } else {
                root -> direita = Remover(root -> direita, chave);
            }
            root -> altura  = maior(AlturaDoNo(root -> esquerda), AlturaDoNo(root -> direita)) + 1;

            root = balancear(root);
            return root;
        }
    } else {
        printf("Nó não está na arvore\n");
        return NULL;
    }

}
int main() {
    NoArv *root = NULL;
    root = inserir(root, 10);
    root = inserir(root, 20);
    root = inserir(root, 30);
    root = inserir(root, 40);
    root = inserir(root, 50);
    root = inserir(root, 60);
    root = inserir(root, 70);
    root = inserir(root, 80);
    root = inserir(root, 90);


    Remover(root, 70);
    Remover(root, 50);
    Remover(root, 90);
    Remover(root, 80);
    Remover(root, 60);
    Remover(root, 10);


    imprimir(root, 1);
    return 0;
}