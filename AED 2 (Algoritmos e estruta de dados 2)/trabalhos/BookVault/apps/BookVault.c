#include <gtk-3.0/gtk/gtk.h>
#include "../include/defines.h"

//variables of ambient
stack *ErrorsStack = NULL;

GtkBuilder *builder;
GtkWidget *window;
GtkStack *stackApp;
GtkStack *stack_exibir_lista;

void InitVariablesAmbiente() {
    ErrorsStack = CreateStack();
}

void on_main_window_destroy() {
    gtk_main_quit();
}

void Register() {
    gtk_stack_set_visible_child_name(stackApp, "Cadastro");
}

void Login() {
    
}
void ConfirmRegister() {
    GtkEntry *eusuario = GTK_ENTRY(gtk_builder_get_object(builder, "entrycaduser"));
    GtkEntry *esenha = GTK_ENTRY(gtk_builder_get_object(builder, "entrycadpassword"));
    const char *usuario = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entrycaduser")));
    const char *senha = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder, "entrycadpassword")));

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
        "on_btnCadastrar_clicked", G_CALLBACK(ConfirmRegister),
        NULL
    );

    //função do gtk que vai conectar todos as sinais e função de callback do programa
    gtk_builder_connect_signals(builder, NULL);
    
    //função que vai carregar o css
    usar_estilo();
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

