#include <ncurses.h>
#include <menu.h>

#include "menu/func_menu.h"
#include "help/func_help.h"
#include "style/func_windows.h"

void create_menu_window(){

	WINDOW *my_menu_win;
	
         keypad(stdscr, TRUE);
	
	/* Utworzenie podstawowego okna*/
	my_menu_win = newwin(10, 40, 4, 4);
         keypad(my_menu_win, TRUE);

	/* Wyświetlenie pomocy dla menu */
	add_help_menu();

	/* Ustawienie parametrów graficznych okna */
         style_window_colors(my_menu_win);

	/* Ustawienie menu */
	create_menu_one(my_menu_win);
	
}
