#include <curses.h>

int main (void) {
    initscr();

    mvprintw(5, 5, "Diese Zeile enth�lt einen Fehhler");
    mvprintw(6, 5, "Taste dr�cken f�r Korrektur");
    getch();
    
    mvdelch(5, 33);
    mvprintw(7, 5, "Fehler wurde korrigiert! Bitte Taste dr�cken!");
    getch();
    
    endwin();
    
    return 0;
}
