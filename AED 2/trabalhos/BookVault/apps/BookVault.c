#include "../include/defines.h"

// Variáveis de ambiente
session *cr = NULL;
stack *ErrorsStack = NULL;
LINKLIST *LinkedListEstoque;

GtkBuilder *builder;
GtkWidget *window;
GtkStack *stackApp;
GtkStack *stack_exibir_lista;

//list store
GtkListStore* list_store_arquivos_selecionados;
GtkListStore* list_store_carrinho;
GtkTreeIter iter;

// Administrador da biblioteca
store library;

int gerarID() {
    time_t current_time;
    current_time = time(NULL);

    if (current_time == ((time_t)-1)) {
        // Se falhar em obter o tempo atual, retorne -1
        return -1;
    }
    // Use o tempo atual como base para o ID
    int id = (int)current_time;
    return id;
}

void InitVariablesAmbiente() {
    ErrorsStack = CreateStack();
    cr = CreateSessionEmpty();
    InitBookDataBase();
    library.id = gerarID();
}

void InitBookDataBase() {
    FILE *file;
    file = fopen(PATH_BOOK_DATABASE, "r");
    book ref;
    
    char name[MaxLenghtName];
    char author[MaxAuthorLenghname];
    int quantity; // Corrigido para quantity
    
    while (fscanf(file, "%[^,],%[^,],%d%*c", name, author, &quantity) != EOF) {
        // Processar os dados lidos, por exemplo:
        ref = CreateBook(name, author, quantity);
        library.Bookstorage.root = inserir(library.Bookstorage.root, ref);
    }
    imprimir(library.Bookstorage.root, 1);
    fclose(file);
}

void on_main_window_destroy() {
    LiberarMemoria(library.Bookstorage.root);
    gtk_main_quit();
}

void Register() {
    gtk_stack_set_visible_child_name(stackApp, "CadPag");
}

void VoltarLogin() {
    gtk_stack_set_visible_child_name(stackApp, "paglogin");
}

void on_bt_sair_alugar_livros_clicked () {
    render_hub();
}

void render_hub() {
    GtkLabel *TextSessionArea = GTK_LABEL(gtk_builder_get_object(builder, "LabelSession"));
    char text[100] = "";
    sprintf(text, "Usuario Atual: %s ", cr->CurrentUser.name);
    gtk_label_set_text(TextSessionArea, text);
    gtk_stack_set_visible_child_name(stackApp, "Hub");
}

void render_cad_livro_pag () {
    gtk_stack_set_visible_child_name(stackApp, "CadLivroPag");
}
void render_login() {
    gtk_stack_set_visible_child_name(stackApp, "paglogin");
}
void render_alugar_livro() {
    FILE *BookVault = AcessDataBase(PATH_BOOK_DATABASE, "r");
    GtkListStore* estoque_livros =  GTK_LIST_STORE(gtk_builder_get_object(builder, "estoque_livros"));
    GtkTreeIter iter;
    int qtd = 0;
    char name[MaxAuthorLenghname], autor[MaxAuthorLenghname];

    gtk_list_store_clear(estoque_livros);
    while (fscanf(BookVault ,"%[^,],%[^,],%d%*c", name, autor, &qtd) != EOF){
        gtk_list_store_append(estoque_livros, &iter);
            gtk_list_store_set(
                estoque_livros, &iter,
                0, name,
                1, autor,
                2, qtd,
                -1
            );
    }
    CloseDataBase(BookVault);
    gtk_stack_set_visible_child_name(stackApp, "AlugarLivro");
}

void CleanArea(GtkEntry *ref) {
    gtk_entry_set_text(ref, "");
}

bool Verify_expired_session () {
    time_t now;
    time(&now);
    int mon = cr->Expired-> tm_mday;

    struct tm* date01 = localtime(&now);    

    if (compare_dates(mon, date01->tm_mon) == 0 || compare_dates(mon, date01->tm_mon) == -1) {
        return true;
    } else {
        return false;
    }
}

void Logout() {
    FILE *delete = AcessDataBase(PATH_TO_SESSION_DATABASE, "w");
    CloseDataBase(delete);
    render_login();
}

void verify_session() {
    FILE *SessionFolder = AcessDataBase(PATH_TO_SESSION_DATABASE, "r");
    
    char aux;
    char name[MaxAuthorLenghname];
    char password[MaxPasswordLenght];
    int id = 0, day = 0, mon = 0, year = 0, contador = 0;
        

    while(fscanf(SessionFolder,"%c", &aux)!= EOF) {
        if(aux == ',') {
            contador++;
        }
    }
    if(contador == 5) {
        fseek(SessionFolder, 0, SEEK_SET);

        while(fscanf(SessionFolder, "%[^,],%[^,],%d,%d,%d,%d", name, password, &id, &day, &mon, &year) != EOF) {}
            
        cr = CreateSessionEmpty();
        cr->CurrentUser = CreateUser(name, password, id);
        cr->Expired->tm_mday = day;
        cr->Expired->tm_mon = mon;
        cr->Expired->tm_year = year;
        if(Verify_expired_session()) {
            FILE *delete = AcessDataBase(PATH_TO_SESSION_DATABASE, "w");
            CloseDataBase(delete);
            render_login();
        } else {
            render_hub();
        }

    } else {
        render_login();
    }
    CloseDataBase(SessionFolder);
};

void Login() {
    GtkEntry *eusuario = GTK_ENTRY(gtk_builder_get_object(builder, "EntryUser"));
    GtkEntry *esenha = GTK_ENTRY(gtk_builder_get_object(builder, "EntryPassword"));
    const char *usuario = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "EntryUser")));
    const char *senha = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "EntryPassword")));
    char *x1 = (char*) malloc(sizeof(char)*40);
    char *x2 = (char*) malloc(sizeof(char)*40);
    strcpy(x1, usuario);
    strcpy(x2, senha);
    user us1 = CreateUser(x1, x2, 10);
    LoginUser(us1);
    if(ErrorsStack->size > 0) {
        ShowErros(ErrorsStack);
        ErrorsStack->size = 0;
    } else {
        render_hub();
        CleanArea(eusuario);
        CleanArea(esenha);
    } 
}

void ConfirmRegister() {
    GtkEntry *eusuario = GTK_ENTRY(gtk_builder_get_object(builder, "entrycaduser"));
    GtkEntry *esenha = GTK_ENTRY(gtk_builder_get_object(builder, "entrycadpassword"));
    const char *usuario = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entrycaduser")));
    const char *senha = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entrycadpassword")));
    char *x1 = (char*) malloc(sizeof(char)*40);
    char *x2 = (char*) malloc(sizeof(char)*40);
    strcpy(x1, usuario);
    strcpy(x2, senha);
    user us1 = CreateUser(x1, x2, gerarID());

    RegisterUser(us1);
    if(ErrorsStack->size > 0) {
        ShowErros(ErrorsStack);
    } else {
        CleanArea(eusuario);
        CleanArea(esenha);
    }
}

void confirm_cad_livro () {
    GtkEntry *enomelivro = GTK_ENTRY(gtk_builder_get_object(builder, "EntryNomeLivro"));
    GtkEntry *enomeautor = GTK_ENTRY(gtk_builder_get_object(builder, "EntryAutor"));
    GtkEntry *equantidade = GTK_ENTRY(gtk_builder_get_object(builder, "EntryQuantidade"));

    const char *nomelivro = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "EntryNomeLivro")));
    const char *nomeautor = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "EntryAutor")));
    const char *quantidadelivro = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "EntryQuantidade")));

    char *MNomeLivro = (char*) malloc(sizeof(char)*60); 
    char *MNomeAutor = (char*) malloc(sizeof(char)*60);
    char *MQuantidadeLivro = (char*) malloc(sizeof(char)*60);

    strcpy(MNomeLivro, nomelivro);
    strcpy(MNomeAutor, nomeautor);
    strcpy(MQuantidadeLivro, quantidadelivro);

    book NewBook = CreateBook(MNomeLivro, MNomeAutor, atoi(MQuantidadeLivro));
    validations(&NewBook);

    if(ErrorsStack->size > 0) {
        ShowErros(ErrorsStack);
    } else {
        AddToStock(&library, &NewBook);
        CleanArea(enomelivro);
        CleanArea(enomeautor);
        CleanArea(equantidade);
    }
}

void usar_estilo () {
    //GtkCssProvider o objeto gtk que guarda o arquivo.css 
    GtkCssProvider *css_provider = gtk_css_provider_new();
    //aqui carregar o provider colocando o objeto que vai receber e o caminho para o arquivo .css
    gtk_css_provider_load_from_path(css_provider, CSS_PATH, false);
    //carregando de fato o css
    gtk_style_context_add_provider_for_screen(
            gdk_screen_get_default(),
            GTK_STYLE_PROVIDER(css_provider),
            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
}

bool VerifyQuantity (gchar *coluna1) {
    book bk;
    bk = FindBook(coluna1, &library);

    if (bk.Amount <= 0) return false;
    else { 
        order NewOrder = borrowAbook(bk.Name, 1, &library);
        insertAtBeginning(&LinkedListEstoque, NewOrder);
        printList(LinkedListEstoque);
        return true;
    };
}

void bt_finalizar_selecao () {
    if(LinkedListEstoque != NULL) {
        char CustomPath[MaxLenghtComandLine];
        sprintf(CustomPath, "%s/%s.csv", PATH_TO_ORDERS_SYSTEM, cr->CurrentUser.name);
        FILE *OrderFolder = AcessDataBase(CustomPath, "w");

        LINKLIST* temp = LinkedListEstoque;
        while (temp != NULL) {
            fprintf(OrderFolder,
                "------------------------------------------------------------------------\n"
                "- Maximo de dias Alugados: %d                                           \n"
                "- Valor da multa diario: %.3f                                             \n"
                "- Titulo escolhido: %s                                                  \n"
                "- Author: %s                                                            \n"
                "------------------------------------------------------------------------\n"
                , temp->data.MaxDays, temp->data.valueOFfine, temp->data.BorrowedBook.Name, temp->data.BorrowedBook.Author
            );
            temp = temp->next;
        }
        CloseDataBase(OrderFolder);
        render_hub();
    } else {
        node *error = CreateNode(CreateError("Impossivel finalizar carrinho de livros nenhum livro selecionado", 99));
    }
}

void livros_no_estoque_row_actived(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data){
    GtkTreeIter iter;
    GtkTreeModel *model = gtk_tree_view_get_model(tree_view);

    // Obter o iter da linha ativa
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        // Variáveis para armazenar os dados das colunas
        gchar *coluna1;
        gchar *coluna2;

        // Obter os dados da linha ativa
        gtk_tree_model_get(model, &iter,
                           0, &coluna1,
                           1, &coluna2,
                           -1);

        // Liberar a memória alocada para coluna2 (se necessário)

        if (VerifyQuantity(coluna1)) {
            GtkListStore* estoque_livros =  GTK_LIST_STORE(gtk_builder_get_object(builder, "carrinho"));
            GtkTreeIter iter;
            gtk_list_store_clear(estoque_livros);

            LINKLIST* temp = LinkedListEstoque;
            while (temp != NULL) {
                gtk_list_store_append(estoque_livros, &iter);
                            gtk_list_store_set(
                                estoque_livros, &iter,
                                0, temp->data.BorrowedBook.Author,
                                1, temp->data.BorrowedBook.Name,
                                -1
                            );

                temp = temp->next;
            }
            g_free(coluna1);
            g_free(coluna2);
        } else {
            node *error = CreateNode(CreateError("Livro não está presente no nosso acervo", 4));
            PushError(error, ErrorsStack);
        }
    } else {
        node *error = CreateNode(CreateError("Objeto nullo foi passado para função", 99));
        PushError(error, ErrorsStack);
    }
}

int main (int argc, char *argv[]) {
    InitVariablesAmbiente();
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file(PATH_BOOKVAULT_GLADE);
    
    //stack e window do programa inteiro
    stackApp = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gtk_builder_add_callback_symbols( builder,
        "on_main_window_destroy", G_CALLBACK(on_main_window_destroy),
        "on_btn_register_clicked", G_CALLBACK(Register),
        "on_BtnLogin_clicked", G_CALLBACK(Login),
        "on_BtnRegister1_clicked", G_CALLBACK(ConfirmRegister),
        "on_btvoltarcad_clicked", G_CALLBACK(VoltarLogin),
        "on_BtCadLivroConfirm_clicked", G_CALLBACK(confirm_cad_livro),
        "on_BtSairCadLivro_clicked", G_CALLBACK(render_hub),
        "on_BtALugarLivro_clicked", G_CALLBACK(render_alugar_livro),
        "on_BtCadLivro_clicked", G_CALLBACK(render_cad_livro_pag),
        "BtSair_clicked_cb", G_CALLBACK(Logout),
        "on_bt_sair_alugar_livros_clicked", G_CALLBACK(on_bt_sair_alugar_livros_clicked),
        "livros_no_estoque_row_actived", G_CALLBACK(livros_no_estoque_row_actived),
        "on_bt_finalizar_selecao_clicked", G_CALLBACK(bt_finalizar_selecao),

        NULL
    );

    //função do gtk que vai conectar todos as sinais e função de callback do programa
    gtk_builder_connect_signals(builder, NULL);
    
    //função que vai carregar o css
    usar_estilo();
    gtk_widget_show_all(window);
    verify_session();
    gtk_main();
    return 0;
}

