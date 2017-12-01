#include <ncurses>

void create_window(){

	WINDOW *my_menu_win;

	/* Ustawienie menu */

	
	
         /* Ustawienie głównego okna oraz okna podrzędnego */
         set_menu_win(my_menu, my_menu_win);
         set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
         set_menu_format(my_menu, 5, 1);

	/* Ustawienie parametrów graficznych okna */
         style_window(my_menu_win);

         /* Przypięcie menu do okna*/
         post_menu(my_menu);
         wrefresh(my_menu_win);
	
	attron(MOCNY_NIEBIESKI);
         mvprintw(LINES - 2, 0, "Mozesz urzyc strzalek oraz klawisza enter");
         mvprintw(LINES - 1, 0, "Wcisniecie klawisza F1 powoduje wyjscie z programu");
         attroff(MOCNY_NIEBIESKI);

	int c;

 refresh();
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
}
