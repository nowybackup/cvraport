#include <menu.h>

void style_menu(MENU *my_menu){
	
	    start_color();
	
	    init_pair(1, COLOR_RED, COLOR_BLACK);
        	    init_pair(2, COLOR_CYAN, COLOR_BLACK);
      	    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

     	   /* Ustawienie tła dla dla opcjiru oraz koloru listy*/
   	    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    	    set_menu_back(my_menu, COLOR_PAIR(2));
     	    set_menu_grey(my_menu, COLOR_PAIR(3));

	   /*  Ustawienie znacznika wyboru opcji z listy menu " * " */
             set_menu_mark(my_menu, " -> ");

}
