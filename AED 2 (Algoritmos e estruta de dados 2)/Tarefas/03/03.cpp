#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#define max 256
#define defalt "Compress/defautName"
//#define defaultTxT "Arq/text.txt"
#define defaultTxT "testando.txt"
//Ruffam compress arquive algorithm

typedef struct _node Node;

class Dictionary {
    public:
        int freq;
        char x;
        int ASCI;
};

struct _node {
    char character;
    int frequence;
    //linkedlist nodes
    Node *next;
    

    //tree nodes
    Node *left;
    Node *right;
};

typedef struct {
    Node *begin;
    Node *end;
    int size;

} OrderList;


Node *Create_Node(Dictionary element) {
    Node *nd = NULL;  
    nd = (Node*) malloc(sizeof(Node)*1);
    if (nd == NULL) exit(0);
    
    //reset nodes
    nd -> next = NULL;
    nd -> left = NULL;
    nd -> right = NULL;

    //atribute values
    nd -> character = element.x;
    nd -> frequence = element.freq;
    
    return nd;
}

OrderList Create_Order_List() {
    OrderList list;
    list.begin = NULL;
    list.end = NULL;
    list.size = 0;;
    return list;
}

void Insert(OrderList *x, Node *NewNode) {
    Node *aux = x -> begin;
    Node *prev = NULL;

    if (aux == NULL) {
        x -> begin = NewNode;
        x -> end = NewNode;
    } 
    else if (NewNode -> frequence < x -> begin -> frequence) {
        NewNode -> next = x -> begin;
        x -> begin = NewNode;
    }
    else {
        while (aux -> next != NULL && aux -> next -> frequence <= NewNode -> frequence) {
            aux = aux -> next;
        }
        if (aux -> next == NULL) {
            x -> end = NewNode;
        }
        
        NewNode -> next = aux -> next;
        aux -> next = NewNode;
    }

    x -> size++;
}

Node *Remove_Begin(OrderList *list) {
    Node *aux = NULL;

    if (list -> begin) {
        aux = list -> begin;
        list -> begin = aux -> next;
        aux -> next = NULL;

        list -> size--;
    }

    return aux;
}

Node *MakeTreeHuffman(OrderList *list) {
    Node *N1, *N2, *NewNode;

    while(list -> size > 1) {
        N1 = Remove_Begin(list);
        N2 = Remove_Begin(list);
        NewNode = (Node*) malloc(sizeof(Node)*1);
        
        if (NewNode) {
            NewNode -> frequence = (N1 -> frequence + N2 -> frequence);
            NewNode -> left = N1;
            NewNode -> right = N2;
            NewNode -> next = NULL;

            Insert(list, NewNode);
        } else {
            break;
        }
    }
    return list -> begin;
}


void ResetFrequence(Dictionary *LetterFrequence) {
    for (int i = 0; i < max; i++) {
        LetterFrequence[i].freq = 0;
        LetterFrequence[i].x = 0;
        LetterFrequence[i].ASCI = 0;
    }
}

void CountFrequence(Dictionary *LetterFrequence, std::string text) {
    for (int i = 0; i < text.length(); i++) {
        if (LetterFrequence[text[i]].freq == 0)  {
            LetterFrequence[text[i]].x = text[i];
            LetterFrequence[text[i]].ASCI = text[i];
        }
        LetterFrequence[text[i]].freq++;
    }
}

void FillOrderList(OrderList *list, Dictionary *LetterFrequence) {
    for (int i = 0; i < max; i++) {
        Node *NewNode = Create_Node(LetterFrequence[i]); 

        if(LetterFrequence[i].freq != 0) {
            Insert(list, NewNode);
        }
    }
}


void PrintFrequenceTable(Dictionary *LetterFrequence) {
    for (int i = 0; i < max; i++) {
        if (LetterFrequence[i].freq != 0) {
            printf("ASCII CODE  = %u\n", LetterFrequence[i].ASCI);
            printf("FREQUENCE = %d\n", LetterFrequence[i].freq);
            printf("CHAR = %c\n", LetterFrequence[i].x);
        }
    }
}

void PrintLinkedList(OrderList x) {
    Node *aux = x.begin;
    for (int i = 0; i < x.size; i++) {
        printf("frequence = %d\n", aux -> frequence);
        printf("CHAR = %c\n", aux -> character);
        aux = aux -> next;
    }
}

void PrintHuffmanTree (Node *root, int size) {
    if (root -> left == NULL && root -> right == NULL) {
        printf("leef: %c altura: %d\n", root -> character, size);
    } else {
        PrintHuffmanTree(root -> left, size + 1);
        PrintHuffmanTree(root -> right, size + 1);
    }
}

void PrintDictionary(char **Dictionary, int column) {
    for (int i = 0; i < column; i++) {
        if (std::strlen(Dictionary[i]) >= 0) {
            printf("\n%3d %s\n",i, Dictionary[i]);
        }
    }
}


int HeightTree(Node *root) {
    int left, right;
    if (root == NULL) return -1;
    else {
        left = HeightTree(root -> left) + 1;
        right = HeightTree(root -> right) + 1;
        return (left > right) ? left : right;
    }
}

char **AlocateMemoryDictionary(int column) {
    char **matrix = NULL;
    matrix = (char**) malloc(sizeof(char*) * max);

    for (int i = 0; i < max; i++) {
        matrix[i] = (char*) malloc(sizeof(char) * (column + 1));
        matrix[i][0] = '\0';
    }
    
    return matrix;    
}

void MakeDictionary(char ***Dc, Node *root, char *pass, int Column) {
    char left[Column + 1], right[Column + 1];
    
    if(root -> left == NULL && root -> right == NULL) {
        printf("%c -> %s\n", root -> character, pass);
        std::strcpy((*Dc)[root -> character], pass);
        
    } else {
        strcpy(left, pass);
        stpcpy(right, pass);

        strcat(left, "0");
        strcat(right, "1");

        MakeDictionary(Dc, root -> left, left, Column);
        MakeDictionary(Dc, root -> right, right, Column);
    }
}

std::string Code (char **Dictionary, std::string text) {
    std::string code;
    int i;
    for(int i = 0; i < text.length(); i++) {
        unsigned char indice = text[i];
        code.append(Dictionary[indice]);   
    }
    return code;
}

std::string decode(std::string code, Node *root) {
    Node *aux = root;
    std::string dc = "";
    for (int i = 0; i < code.length(); i++) {
        if(code[i] == '0') {
            aux = aux -> left;
        } else {
            aux = aux -> right;
        }
        if (aux -> left == NULL && aux -> right == NULL) {
            dc += aux -> character;
            aux = root;
        }
    }
    return dc;
}

void Compact_Arq(std::string str) {
    FILE *arq =  fopen(defalt, "wb");
    int AuxByte = 7;
    unsigned char Byte = 0;//0000.0000
    unsigned char MaskByte = 0; 
    if(arq) {
        // 1110.0111....
        // 0000.0000 - create mask of bits
        // 1000.0000 byte & (1 << 7)
        // 1000.0000
        for (int i = 0; i < str.length(); i++) {
            MaskByte = 1;
            if (str[i] == '1') {
                MaskByte = MaskByte << AuxByte;
                Byte = Byte | MaskByte;
            } 
            AuxByte--;
            if(AuxByte < 0) {
                /*
                    we have gone through the eight bytes and now 
                    we can record it
                */
                fwrite(&Byte, sizeof(unsigned char), 1, arq);
                Byte = 0;
                AuxByte = 7;
            }
        }
        if (AuxByte != 7) {
            fwrite(&Byte, sizeof(unsigned char), 1, arq);
        }
        fclose(arq);
    } else {
        printf("error");
    }
}

unsigned int VerifyBitOne(unsigned char byte, int i) {
    unsigned int ByteMask = (1 << i); 
    return byte & ByteMask;
}

std::string Descomp_Arq(Node *root) {
    FILE *arq = fopen(defalt, "rb");
    Node *aux = root;
    unsigned char byte;
    std::string text;

    if(arq) {
        while(fread(&byte, sizeof(unsigned char), 1, arq)) {
            for(int i = 7; i >= 0; i--) {
                if(VerifyBitOne(byte, i)) {
                    aux = aux -> right;
                } else {
                    aux = aux -> left;
                }
                //verify if aux is a leaf of a HuffmanTree
                if(aux -> left == NULL && aux -> right == NULL) {
                    text += aux -> character;
                    aux = root;
                }
            }
        }
    } else {
        printf("error\n");
    }
    fclose(arq);
    return text;
}

void FreeDictionary(char ***matrix) {
    if(matrix == NULL) {
        char **aux = *(matrix);
        for(int i = 0; i < max; i++) {
            free(aux[i]);
        }
        free(aux);
        matrix = NULL;
    } else {
        exit(0);
    }
}

void FreeTreeHuffman(Node *root) {
    if (root == NULL) return;
    FreeTreeHuffman(root -> left);
    FreeTreeHuffman(root -> right);
    free(root);
}

void FreeLinkedList(OrderList x) {
    if(x.begin != NULL){
        Node *aux = x.begin;
        Node *ref = NULL;
        while(aux) {
            ref = aux;
            aux = aux -> next;
            free(ref);
        }
    } else {
        exit(0);
    }
}

void ReleaseMemory(char ***Dc, OrderList x, Node *root) {
    if(Dc != NULL && root != NULL) {
        FreeDictionary(Dc);
        FreeLinkedList(x);
        FreeTreeHuffman(root);
    } else {
        exit(0);
    }
}
void run () {
    //creating the variables that will be used to compress the text
    std::string text;
    std::string CodeText;
    std::string dco;
    std::string x;
    int height;
    char vetor[90] = {""};
    Dictionary LetterFrequence[max];
    OrderList list;
    Node *HuffmanTree;
    char **Dc;
    
    //open the arq whit the .txt what will compress
    std::ifstream arq(defaultTxT);
    if(!arq) exit(1);

    arq.seekg(0, std::ios::end);
    std::streampos fileSize = arq.tellg();
    arq.seekg(0, std::ios::beg);
    text.resize(fileSize);
    //read the arquive
    arq.read(&text[0], fileSize);    
    
    //create the structs that i will need
    list = Create_Order_List();
    ResetFrequence(LetterFrequence);
    CountFrequence(LetterFrequence, text);
    FillOrderList(&list, LetterFrequence);
    HuffmanTree = MakeTreeHuffman(&list);
    height = HeightTree(HuffmanTree) + 1;
    Dc = AlocateMemoryDictionary(height);
    MakeDictionary(&Dc, HuffmanTree, vetor, height);
    
    //compressing and creating the compressed file
    CodeText = Code(Dc, text);
    dco = decode(CodeText, HuffmanTree);    
    Compact_Arq(CodeText);
    PrintFrequenceTable(LetterFrequence);

    x = Descomp_Arq(HuffmanTree);

    //display the result
    for (int i = 0; i < x.length(); i++) {
        printf("%c", x[i]);
    }

    //freeing up memory used in program structures
    ReleaseMemory(&Dc, list, HuffmanTree);
    arq.close();
}

int main () {
    run();
    return 0;
}


