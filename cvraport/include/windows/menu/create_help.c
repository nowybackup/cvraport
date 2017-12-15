#include <ncurses.h>
#include <stdlib.h>

#include "func_menu.h"
#include "style/func_style.h"

void help(){
	
	ITEM **my_items;
	WINDOW *my_menu_win;

	initscr();
	cbreak();
         noecho();
         keypad(stdscr, TRUE);
	
	/* Utworzenie podstawowego okna*/
	my_menu_win = newwin(10, 40, 4, 4);
         keypad(my_menu_win, TRUE);

	/* Wyświetlenie pomocy dla menu */
	attron(COLOR_PAIR(2));
         mvprintw(LINES - 2, 0, "Mozesz urzyc strzalek oraz klawisza enter");
         mvprintw(LINES - 1, 0, "Wcisniecie klawisza F1 powoduje wyjscie z 		programu");
         attroff(COLOR_PAIR(2));

	/* Ustawienie parametrów graficznych okna */
         style_window_colors(my_menu_win);

	/* Przypięcie okna */
         wrefresh(my_menu_win);

	/* funcka (my_menu_win, my_menu) */

	int c;
         while((c = getch()) != 10)
         {       
		mvprintw(20, 0, "Pomoc : Wcisnij ENTER by wrocic");
                  wrefresh(my_menu_win);
         } 

	endwin();

	create_menu_one(my_menu_win);

}
