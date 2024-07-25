#include <ncurses.h>
#include <iostream>

int main (int argc, char **argv) {
    int ch, prev, row, col;
    prev = EOF;
    FILE *fp;
    int y, x;

    if (argc != 2) {
        std::cout << "Use um nome de arquivo: " << argv[0] << '\n';
        exit(1);
    }
    initscr();
    getmaxyx(stdscr, row, col);		
    while((ch = fgetc(fp)) != EOF) {
        getyx(stdscr, y, x);
        if (y == (row-1)) {
            printw("pressione qualquer tecla");
            getch();
            clear();	
                move(0, 0);				
        }
        if(prev == '/' &&  '*'){
            attron(A_BOLD);			
            getyx(stdscr, y, x);		
            move(y, x - 1);			
            printw("%c%c", '/', ch); 		
        }else{
            printw("%c", ch);
        }
        refresh();
        if(prev == '*' && ch == '/'){
            attroff(A_BOLD);
        }
        prev = ch;
    }
    endwin();                       	
    fclose(fp);
   
    return 0;
}