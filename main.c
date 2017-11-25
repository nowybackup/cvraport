#include <ncurses.h>  // ncurses.h zawiera stdio.h
#include <string.h>
 
int main()
{
    char mesg[]="Podaj napis: "; // wiadomość do wyświetlenia
    char str[80];
 
    int row,col;                 // zmienne do przechowywania
                                 // ilości kolumn i rzędów
 
    initscr();                   // tryb curses
 
    getmaxyx(stdscr,row,col);    // pozyskiwanie ilości
                                 // kolumn i rzędów
 
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                                 // drukowanie wiadomości
                                 // na środku ekranu
 
    getstr(str);
 
    mvprintw(LINES - 2, 0, "Podales: %s", str);
 
    getch();
    endwin();
 
    return 0;
}
