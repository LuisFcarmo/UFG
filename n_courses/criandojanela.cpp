#include <ncurses.h>
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

typedef struct _win_border_struct {
    chtype ls, rs, ts, bs, tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {
    int startx, starty;
    int heigth, width;
    WIN_BORDER border;
} WIN;

void init_win_params(WIN *p_win);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);


int main (int argc, char *argv[]) {
    WINDOW *my_win;
    int startx = 0, starty = 0, width = 0, heigth = 0;
    int ch;
    int max_colum, max_lim;
    int x_box, y_box;

    initscr();
    start_color();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(false);



    heigth = 19;
    width = 10;
    starty = (LINES - heigth) / 2;
    startx = (COLS - width) / 2;
    printf("presione F1 para sair");
    refresh();
    my_win = create_newwin(heigth, width, starty, startx);

    while ((ch = getch()) != KEY_F(1))
    {
        if (starty < 0) {
            starty = LINES;
            my_win = create_newwin(heigth, width, starty, startx);
        } 
        if (starty > LINES) {
            starty = 0;
            my_win = create_newwin(heigth, width, starty, startx);
        }
        if (startx < 0) {
            startx = COLS;
            my_win = create_newwin(heigth, width, starty, startx);
        } 
        if (startx > COLS) {
            startx = 0;
            my_win = create_newwin(heigth, width, starty, startx);
        }
        switch (ch)
        {            
        case KEY_LEFT:
            destroy_win(my_win);
            my_win = create_newwin(heigth, width, starty, --startx);
            break;
        case KEY_RIGHT:
            destroy_win(my_win);
            my_win = create_newwin(heigth, width, starty, ++startx);
            break;
        case KEY_UP:
            destroy_win(my_win);
            my_win = create_newwin(heigth, width, --starty, startx);
            break;
        case KEY_DOWN:
            destroy_win(my_win);
            my_win = create_newwin(heigth, width, ++starty, startx);
        default:
            break;
        }
    }
    
    endwin();
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    wrefresh(local_win);
    return local_win;
};

void destroy_win(WINDOW *local_win) {

    wborder (local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    /* Os parâmetros usados são
        * 1. win: a janela na qual operar
        * 2. ls: caractere a ser usado para o lado esquerdo da janela
        * 3. rs: caractere a ser usado para o lado direito da janela
        * 4. ts: caractere a ser usado na parte superior da janela
        * 5. bs: caractere a ser usado na parte inferior da janela
        * 6. tl: caractere a ser usado para o canto superior esquerdo da janela
        * 7. tr: caractere a ser usado no canto superior direito da janela
        * 8. bl: caractere a ser usado no canto inferior esquerdo da janela
        * 9. br: caractere a ser usado no canto inferior direito da janela
        */
   wrefresh(local_win);
   delwin(local_win);
}