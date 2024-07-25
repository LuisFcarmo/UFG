#include <ncurses.h>
#include <string.h>
int main (int argc, char **argv) {
    char msg[] = "digite alog";
    char str[80];
    initscr();

    int row, col;
    getmaxyx(stdscr, row, col);

    mvprintw(row/2, (col-strlen(msg))/2, "%s", msg);

    getstr(str);
    //print algo em determinado ponto da tela
    mvprintw(LINES - 2, 0, "você digitou  %s", str);

    getch();
    refresh();
    endwin();
    return 0;
}