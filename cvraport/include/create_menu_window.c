#include <ncurses>
#include <menu.h>

void create_menu_window(WINDOW *my_menu_win){
	
	start_color();
	initialize_colors();
	cbreak();
         noecho();
         keypad(stdscr, TRUE);
         init_pair(1, COLOR_RED, COLOR_BLACK);
         init_pair(2, COLOR_GREEN, COLOR_BLACK);
         init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

	MENU *my_menu;
	
	/* Ustawienie menu */
	create_menu_one(my_menu);
	
	/* Utworzenie podstawowego okna*/
	my_menu_win = newwin(10, 40, 4, 4);
         keypad(my_menu_win, TRUE);
	
         /* Ustawienie kolejnosci wyswietlanych okien */
         set_menu_win(my_menu, my_menu_win);
         set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
         set_menu_format(my_menu, 5, 1);

	/* Ustawienie parametrów graficznych okna */
         style_window_colors(my_menu_win);

         /* Przypięcie menu do okna */
         post_menu(my_menu);
         wrefresh(my_menu_win);
	
	/* Wyświetlenie pomocy dla menu */
	add_help_menu();

}
