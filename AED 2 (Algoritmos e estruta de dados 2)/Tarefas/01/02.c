#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[51];
    char curso[51];
    double nota01;
    double nota02;
} registro;

typedef struct _node node;

typedef struct
{
    node *begin;
    node *end;
    int size;
} head;

struct _node
{
    registro value;
    node *next;
    node *prev;
};

int tamanho(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

registro Criar_registro()
{
    registro novo;
    int matricula;
    double nota01, nota02;
    char string[51];

    while (1)
    {
        while (1)
        {
            printf("Insira o numero de matricula\n");
            scanf("%d%*c", &matricula);
            if (matricula < 0)
            {
                printf("matricula invalida insira um numero positivo\n");
                continue;
            }
            else
            {
                novo.matricula = matricula;
                break;
            }
        }
        while (1)
        {
            printf("Insira a nota01\n");
            scanf("%lf%*c", &nota01);
            if (nota01 < 0 || nota01 > 10)
            {
                printf("a nota deve estar em um intervalo de 0 a 10\n");
            }
            else
            {
                novo.nota01 = nota01;
                break;
            }
        }
        while (1)
        {
            printf("Insira a nota02\n");
            scanf("%lf%*c", &nota02);
            if (nota02 < 0 || nota02 > 10)
            {
                printf("a nota deve estar em um intervalo de 0 a 10\n");
            }
            else
            {
                novo.nota02 = nota02;
                break;
            }
        }
        while (1)
        {
            printf("Insira o seu nome\n");
            scanf("%50[^\n]%*c", string);
            if (tamanho(string) - 1 < 0)
            {
                printf("O nome está vazio\n");
            }
            else
            {
                strcpy(novo.nome, string);
                break;
            }
        }
        while (1)
        {
            printf("Insira o nome do curso\n");
            scanf("%50[^\n]%*c", string);
            if (tamanho(string) - 1 < 0)
            {
                printf("O nome do curso está vazio\n");
            }
            else
            {
                strcpy(novo.curso, string);
                break;
            }
        }
        break;
    }
    return novo;
}

head *Create_List()
{
    head *x = NULL;
    do
    {
        x = (head *)malloc(sizeof(head) * 1);
        x->begin = NULL;
        x->end = NULL;
        x->size = 0;
        return x;
    } while (x == NULL);
};

node *Create_Node(registro x)
{
    node *aux = NULL;
    do
    {
        aux = (node *)malloc(sizeof(node) * 1);
    } while (aux == NULL);
    aux->next = NULL;
    aux->prev = NULL;
    aux->value = x;
    return aux;
};

void Add_Fist(registro x, head *list)
{
    if (list != NULL)
    {
        node *aux = Create_Node(x);
        node *ref = NULL;

        if (list->size == 0)
        {
            list->begin = aux;
            list->end = aux;
        }
        else
        {
            ref = list->begin;
            list->begin = aux;
            list->begin->next = ref;
            ref->prev = list->begin;
        }
        list->size++;

        // return true;
    }
    else
    {
        printf("Memmory not alocated\n");
        // return false;
    }
}

bool imprimir(head *x)
{
    node *aux = NULL;
    aux = x->begin;
    for (int i = 0; i < x->size; i++)
    {
        printf("\n");
        printf("----------------------------------------------------------\n");
        printf("- matricula = %d                                          \n", aux->value.matricula);
        printf("- nota 01 = %lf                                           \n", aux->value.nota01);
        printf("- nota 02 = %lf                                           \n", aux->value.nota02);
        printf("- Nome do Curso = %s                                      \n", aux->value.nome);
        printf("- Nome do Aluno = %s                                      \n", aux->value.curso);
        printf("- Media do Aluno = %.2lf                                  \n",
               (aux->value.nota01 + aux->value.nota02) / 2);
        printf("----------------------------------------------------------\n"),

        aux = aux->next;
    }
}

bool IsPresent(int matricula, head *list)
{
    node *aux = list->begin;
    for (int i = 0; i < list->size; i++)
    {
        if (aux->value.matricula == matricula)
        {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

void Destruct_node(node **ref) {
    if (ref != NULL && *ref != NULL) {
        node *aux = *ref;
        free(aux);  
        *ref = NULL;
    }
}

void Update(int matricula, registro new, head *list)
{
    node *aux = Create_Node(new);
    node *cm = list -> begin;

    if (IsPresent(matricula, list))
    {
        for (int i = 0; i < list -> size; i++)
        {
            if (cm->value.matricula == matricula)
            {
                if (cm == list->end)
                {
                    list -> end -> next = aux;
                    aux -> prev = list -> end;
                    list -> end = aux;
                }
                if (cm == list->begin)
                {
                    aux -> next = list -> begin -> next;
                    list -> begin -> next -> prev = aux;
                    list -> begin = aux;
                }
                else
                {
                    aux -> prev = cm -> prev;
                    aux -> next = cm -> next;
                    cm -> prev -> next = aux;
                    cm -> next -> prev = aux;
                }
            }
            cm = cm -> next;
        }
        Destruct_node(&cm);
    }
    else
    {
        printf("O Elemento está presente no array\n");
    }
}

void Delete(head *list, int matricula) {
    if (IsPresent(matricula, list)) {
        int op = 0;
        printf("Usuario existente deseja deletar (1 SIM) (2 NÃO) ?\n");
        scanf("%d%*c", &op);
        if(op == 1) {
            node *aux = list -> begin;
            for (int i = 0; i < list -> size; i++) {
                if (aux -> value.matricula ==  matricula) {
                    if (aux == list -> end) {
                        list -> end = list -> end -> prev;
                        break;
                    }
                    else if (aux == list -> begin) {
                        list -> begin = list -> begin -> next;
                        break;
                    } else {
                        aux -> prev -> next = aux -> next;
                        aux -> next -> prev = aux -> prev;
                    }
                }
                aux = aux -> next;
            }
            list -> size--;
        } else {
            printf("Nenhum elemento foi deletado do array\n");
        }
    } else  {
        printf("O valor não está presente no array\n");
    }
}

int main()
{
    head *list = Create_List();
    registro x = Criar_registro();
    /*
    for (int i = 0; i < 5; i++)
    {
        registro x = Criar_registro();
        Add_Fist(x, list);
    }

    registro teste = Criar_registro();
    
    
    Update(3, teste, list);
    Delete(list, 1);
    Delete(list, 111);
    */
    /// printf("%d", list -> begin->value.matricula);
    imprimir(list);

    return 0;
}