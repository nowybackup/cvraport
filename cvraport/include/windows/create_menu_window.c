#include <ncurses.h>
#include <menu.h>

#include "menu/func_menu.h"
#include "help/func_help.h"
#include "func/func_style.h"

void create_menu_window(WINDOW *my_menu_win){
	
         keypad(stdscr, TRUE);

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

	int c;
         while((c = wgetch(my_menu_win)) != KEY_F(1))
         {       switch(c)
                 {       case KEY_DOWN:
                                 menu_driver(my_menu, REQ_DOWN_ITEM);
                                 break;
                         case KEY_UP:
                                 menu_driver(my_menu, REQ_UP_ITEM);
                                 break;
                         case KEY_NPAGE:
                                 menu_driver(my_menu, REQ_SCR_DPAGE);
                                 break;
                         case KEY_PPAGE:
                                 menu_driver(my_menu, REQ_SCR_UPAGE);
                                 break;
                 }
                 wrefresh(my_menu_win);
         } 

	unpost_menu(my_menu);
         free_menu(my_menu);
}
