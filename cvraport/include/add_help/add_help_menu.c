#include <ncurses.h>

void add_help_menu(){
	attron(COLOR_PAIR(2));
         mvprintw(LINES - 2, 0, "Mozesz urzyc strzalek oraz klawisza enter");
         mvprintw(LINES - 1, 0, "Wcisniecie klawisza F1 powoduje wyjscie z programu");
         attroff(COLOR_PAIR(2));
}
