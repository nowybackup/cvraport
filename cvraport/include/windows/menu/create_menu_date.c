#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "style/func_menu.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void create_menu_date(WINDOW *my_menu_win){

	ITEM **my_items;
	MENU *my_menu;

 	char *choices[] = {
			"Wyswietl tabele z bazy danych",
			"Analiza danych exif na mapie",
			"Wyniki analizy graficznej",
			"Zarzadzaj baza danych",
			"Exit",
                           (char *)NULL,
                  };
	
		int n_choices;
		n_choices = ARRAY_SIZE(choices);
        		my_items = (ITEM **)calloc((n_choices), sizeof(ITEM *));

		for(int i = 0; i < n_choices; i++){
		my_items[i] = new_item(choices[i], choices[i]);
		}

	/* Utworzenie menu one */
         my_menu = new_menu((ITEM **)my_items);

	/* Ustawienie opcji menu one tak, aby nie wyświetlała opisu*/
         menu_opts_off(my_menu, O_SHOWDESC);

	/* Ustawienie kolorow i parametrow czcionki*/
	style_menu(my_menu);

	/* Ustawienie kolejnosci wyswietlanych okien */
         set_menu_win(my_menu, my_menu_win);
         set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
         set_menu_format(my_menu, 5, 1);

         /* Przypięcie menu do okna */
         post_menu(my_menu);

	/* Przypięcie okna */
         wrefresh(my_menu_win);

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
