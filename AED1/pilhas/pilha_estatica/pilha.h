typedef int typeitem;
const int max_itens = 3;

class stack {
    private:
    int tamanho = 0;
    typeitem * estrutura;
    
    public:
    stack(); //build function
    ~stack(); // destruct function
    bool isfull(); // verify if stack is full
    bool isempty(); // verify if stack is empty
    void push( typeitem item ); // push item in stack
    typeitem pop (); // pop item in stack 
    void printstack(); //print stack
    int lenght(); 
};