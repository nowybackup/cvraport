#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "style/func_menu.h"
#include "func_menu.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void create_menu_exif(WINDOW *my_menu_win){

	ITEM **my_items;
	MENU *my_menu;

 	char *choices[] = {
                  	"Pszeszukanie dysku w poszukiwaniu danych exif",
			"Zapis znalezionych scierzek do pliku",
			"Usuniecie danych exif",
			"Cofnij",
			(char *)NULL,
		};

	
		int n_choices = 0;
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
         while((c = getch()) != 10 )
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
		       case 10: /* Enter */
                                 move(20, 0);
        	   		      clrtoeol();
        	   		      mvprintw(20, 0, "Gotowy element : %s", 
            		      item_name(current_item(my_menu)));
		      
			      break;
                 }

                 wrefresh(my_menu_win);
         } 
				if( item_name(current_item(my_menu)) == choices[3]){
					pos_menu_cursor(my_menu);
					unpost_menu(my_menu);
					free_menu(my_menu);
					//create_menu_one(my_menu_win);
				}

	pos_menu_cursor(my_menu);
	unpost_menu(my_menu);
         free_menu(my_menu);
}
