#include <stdlib.h>
#include <stdio.h>
/*
    algoritmos de ordenação
*/
void swap (int *array, int i, int j) {
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

/*
    Complexidade
    Melhor caso O(n)
    Caso médio O(n²)
    pior caso O(n²)
    Estabilidade estável
*/
void booble_sort (int *array, char order, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int k = i+1; k < size; k++) {
            if (array[i] >= array[k]) {
                swap(array, i, k);
            }
        }
    }
}   

/*
    Complexidade
    Melhor caso O(n²)
    Caso médio O(n²)
    pior caso O(n²)
    Estabilidade não estável
*/
void selection_sort (int *array, char order, int size) {
    for (int i = 0; i < size; i++) {
        int indice_menor = i;
        //encontrando o menor elemento do array e pegando o indice dele
        for (int k = i + 1; k < size; k++) {
            if (array[indice_menor] >= array[k]) {
                indice_menor = k;
            } 
        }
        /*
            colocando o menor elemento no indice respectivo 
            exemplo
            0 1 2  3 4   5
            9 4 23 2 323 1

            indice do menor elemento 5
            swar(5 com 0)

            0 1 2  3  4   5     
            1 4 23 2  323 9

            indice do menor elemento 2
            swap(3 com 1)
            0 1 2  3  4   5     
            1 2 23 4  323 9
            .........
        */
        swap(array, i, indice_menor);
    }
}

/*
    Complexidade
    Melhor caso O(n)
    Caso médio O(n²)
    pior caso O(n²)
    Estabilidade não estável
*/

void insertion_sort (int *array, char order, int size) {
    int j = 0;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j > 0 && array[j] <= array[j-1]) {
            swap(array, j, j-1);
            j--;
        }
    }
}

/*
    Complexidade
    Melhor caso O(n log n)
    Caso médio O(n log n)
    pior caso O(n²)
    Estabilidade não estável
*/

int particion(int *array, int left, int right) {
    int i = left;
    int pivot = array[left];
    for (int j = left + 1; j <= right; j++) {
        if (array[j] <= pivot) {
            swap(array, i ,j);
            i++;
        }
    }
    swap(array, i, right);
    return i;
}

void quicksort(int *array, int left, int right) {
    if (left < right) {
        int index_pivot = particion(array, left, right);
        quicksort(array, left, index_pivot -1);
        quicksort(array, index_pivot + 1, right);
    }
}
/*
    Complexidade
    Melhor caso O(n log n)
    Caso médio O(n log n)
    pior caso O(n²)
    Estabilidade não estável
*/


/*
    data structs
    stack
    list
    row
*/
typedef struct _node { 
    struct _node *next;
    int valor;
}node;

node *create_node (int valor) {
    node *novo_no = NULL;
    novo_no = (node*) malloc(sizeof(node)*1);
    novo_no -> valor = valor;
    novo_no -> next = NULL;

    return novo_no;
}

void trans_list_in_circlist (node **list) {
    if (*list == NULL) {
        return;
    }
    else {
        node *aux = *list;
        if (aux -> next == NULL) {
            aux -> next = aux;
        }
        else {
            node *end = *list;
            while (end -> next != NULL) {
                end = end -> next;
            }
            end -> next = aux;
        }
    }
}

void print_circ_list (node *list, int qtd) {
    node *aux = list;
    int contador = 0;
    while (1)
    {
        if (aux == list) {
            contador++;
        }
        if (contador == qtd+1) break;
        printf("%d\n", aux -> valor);
        aux = aux -> next;
    }
}

void insert_in_order (node **ref, int valor) {
    if (*ref == NULL) {
        *ref = create_node(valor);
    } else {
        node *novo_no = create_node(valor);
        node *current = *ref;
        node *passed = NULL;

        while (valor >= current -> valor) {
            passed = current;
            current = current -> next;
            if (current == NULL) break;
        }
        if (passed == NULL) {
            novo_no -> next = current;
            *ref = novo_no;
        }
        else if (current == NULL) {
            passed -> next = novo_no;
        }
        else {
            passed -> next = novo_no;
            novo_no -> next = current;
        }
    }
}

void push (node **stack, int value) {
    node *new_node = create_node(value);
    if (*stack == NULL) {
        *stack = new_node;
    } else {
        node *current = *stack;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = new_node;
    }
}


void pop(node **stack) {
    node *aux = *stack;
    if (*stack == NULL) {
        return;
    }
    else {
        node *current = *stack;
        node *passed = NULL;
        if (current -> next == NULL) {
            free(current);
            *stack = NULL;
        } 
        else {
            while (current -> next != NULL) {
                passed = current;
                current = current -> next;
            }
            free(current);
            passed -> next = NULL;
        }
    }
}

void dequeue (node **fifo) {
    if (*fifo == NULL) {
        return;
    } else {
        node *aux = *fifo;
        node *ref_next = NULL;
        if (aux -> next == NULL) {
            free(aux);
            *fifo = NULL;
        }
        else {
            ref_next = aux -> next;
            free(aux);
            *fifo = ref_next;
        }
    }
}

void enqueue(node **fifo, int value) {
    node *new_node = create_node(value);
    if (*fifo == NULL) {
        *fifo = new_node;
    } else {
        node *passed = *fifo;
        *fifo = new_node;
        new_node -> next = passed;
    }
}

void print_lista(node *lista) {
    node* aux = lista;
    while (aux != NULL) {
        printf("%d\n", aux -> valor);
        aux = aux -> next;
    }
}

int main () {
    int vetor[17];
    int total = 17;
   
    for (int i = 0; i < 17; i++) {
        vetor[i] = total--;
    }

    quicksort(vetor, 0, 16);

    for (int i = 0; i < 17; i++) {
        printf("%d\n", vetor[i]);
    }


    /*node *lista = NULL;
    node *stack = NULL;
    node *fifo = NULL;
    int valor;

    for (int i = 0; i < 6; i++) {
        push(&stack, i);
    }
    pop(&stack); 
    print_lista(stack);
    printf("\n");


    for (int i = 0; i <  4; i++) {
        enqueue(&fifo, i);
    }
    dequeue(&fifo); 
    print_lista(fifo);
    
    for (int i = 0; i < 5; i++) {
        insert_in_order(&lista, i);
    }

    trans_list_in_circlist(&lista);
    print_circ_list(lista, 8);
    */



    return 0;
}