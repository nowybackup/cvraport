#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "func_menu.h"
#include "style/func_style.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void create_menu_graphic(){
	char *choices[] = {
			"Znajdz osobe",
			"Return",
			(char *)NULL,
		};
	ITEM **my_items;
	MENU *my_menu;
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

	//* Ustawienie kolejnosci wyswietlanych okien */
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
					

	pos_menu_cursor(my_menu);
	unpost_menu(my_menu);
       	free_menu(my_menu);
	endwin();
	system("clear");
}
