MENU style_menu(MENU *my_menu){
	
	    start_color();
	    initialize_colors(); 	
	
     	   /* Ustawienie tła dla dla opcjiru oraz koloru listy*/
   	    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    	    set_menu_back(my_menu, COLOR_PAIR(2));
     	    set_menu_grey(my_menu, COLOR_PAIR(3));

	   /*  Ustawienie znacznika wyboru opcji z listy menu " * " */
             set_menu_mark(my_menu, " -> ");

	   return my_menu;

}
