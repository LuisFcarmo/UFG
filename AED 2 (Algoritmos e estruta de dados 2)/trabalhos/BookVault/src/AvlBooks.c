#include "../include/defines.h"

/*implementação sem verificação da alocação de memoria feita apenas com fins didaticos*/

NoArv * Cria_No(book x) {
    NoArv * new = (NoArv * ) malloc(sizeof(NoArv));
    new -> value = x;
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
NoArv *inserir(NoArv *raiz, book x) {
    if (raiz == NULL) {
        return Cria_No(x);
    } else {
        // Comparação dos títulos para inserir em ordem alfabética
        int comparacao = strcmp(x.Name, raiz -> value.Name);
        if (comparacao < 0) {
            raiz->esquerda = inserir(raiz->esquerda, x);
        } else if (comparacao > 0) {
            raiz->direita = inserir(raiz->direita, x);
        } else {
            printf("Inserção não realizada. O livro com título %s já existe.\n", x.Name);
            return raiz; // Retorna a raiz sem fazer alterações
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
        printf("nome:%s\n", raiz -> value.Name);
        printf("author:%s\n", raiz -> value.Author);
        printf("quantidade em estoque:%d\n", raiz -> value.Amount);

        imprimir(raiz -> esquerda, nivel + 1);
    }
}

Resp Qtd_Filhos(NoArv * root, book chave) {
    if (root != NULL) {
        Resp x;
        if (strcmp(root -> value.Name, chave.Name)) {
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
            int comparacao = strcmp(chave.Name, root -> value.Name);
            if (comparacao > 0) {
                Qtd_Filhos(root -> direita, chave);
            } else {
                Qtd_Filhos(root -> esquerda, chave);
            }
        }
    } else {
        printf("Nó não esta presente na arvore");
    }
}

NoArv * Remover(NoArv * root, book chave) {
    if (root != NULL) {
        if (strcmp(root -> value.Name, chave.Name)) {
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
                    root -> value = aux -> value;
                    aux -> value = chave;
                    root -> esquerda = Remover(root -> esquerda, chave);
                    return root;
                }
            }
        } else {
            int comparacao = strcmp(chave.Name, root -> value.Name);
            if (comparacao < 0) {
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

book Find(NoArv *root, char *chave) {
    if (root == NULL) {
        book empty = { "", "", 0 }; // Valor de retorno padrão se não encontrado
        return empty;
    }
    if (strcmp(root->value.Name, chave) == 0) {
        return root->value;
    }
    if (strcmp(root->value.Name, chave) > 0) {
        return Find(root->esquerda, chave);
    }
    // Se o nome do livro for menor que a chave, procure na subárvore direita
    else {
        return Find(root->direita, chave);
    }
}
       
