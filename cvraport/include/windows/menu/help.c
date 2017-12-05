#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "style/func_menu.h"

void help(WINDOW *my_menu_win){

	/* Przypięcie okna */
         wrefresh(my_menu_win);

	/* funcka (my_menu_win, my_menu) */

	int c;
         while((c = getch()) != 10)
         {       

		mvprintw(20, 0, "Pomoc : Wcisnij ENTER by wrocic");
                 wrefresh(my_menu_win);
         } 

	create_menu_one(my_menu_win);
}
