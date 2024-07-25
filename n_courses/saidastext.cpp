#include <ncurses.h>
#include <cstring> 
int main () {
    char msg[] = "alguma string";
      initscr();				
    int row, colum;
    getmaxyx(stdscr,row,colum);		
    
    
    mvprintw(row/2,(colum-strlen(msg))/2,"%s",msg);
    
    mvprintw(row-2,0,"Essa tela tem %d linhas e %d colunas\n",row,colum);


    printw("Tente redimensionar sua janela (se possível) e execute este programa novamente.");

    refresh();
    getch();
    endwin();
    endwin();
    
    return 0;
}
