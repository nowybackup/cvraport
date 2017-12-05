#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "style/func_menu.h"

void exit(WINDOW *my_menu_win){

	/* Przypięcie okna */
         wrefresh(my_menu_win);

	/* funcka (my_menu_win, my_menu) */

	int c;
         while((c = getch()) != KEY_F(1))
         {       

		mvprintw(20, 0, "Wcisnij F1 : ");

                 wrefresh(my_menu_win);
         } 

}
