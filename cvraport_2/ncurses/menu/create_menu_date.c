#include "menu.h"



void create_menu_date(){     
                 
        char *choices[] = {
                 	"Wyswietlenie tabeli exif",
		"Wyswitlenie tabeli exif na mapie",
		"Wyswietlenie wynikow analizy graficznej",
		"Zarzadzanie baza danych",
		"Exit",
		(char *)NULL,
        };         
                    
        int n_choices;
        
        initscr();
        start_color();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);

        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(int i = 0; i < n_choices; ++i)
                my_items[i] = new_item(choices[i], choices[i]);

        my_menu = new_menu((ITEM **)my_items);

        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);
     
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
        set_menu_format(my_menu, 5, 1);
                        

        set_menu_mark(my_menu, " -> ");


        menu_opts_off(my_menu, O_SHOWDESC);

        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Analiza danych", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        
        post_menu(my_menu);
        wrefresh(my_menu_win);
        
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 2, 0, "Mozesz poruszac sie po menu strzalkami");
        mvprintw(LINES - 1, 0, "Program mozna zamknac wybierajac exit z menu");
        attroff(COLOR_PAIR(2));
        refresh();

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
        	   		      mvprintw(20, 0, "Wybrany element : %s", 
            		      item_name(current_item(my_menu)));
		      
			      break;
                 }

                 wrefresh(my_menu_win);
         }    
        
	if( item_name(current_item(my_menu)) == choices[0]){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		/* przekierowanie do innego modulu */
	}
	
	if( item_name(current_item(my_menu)) == choices[1]){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		/* przekierowanie do innego modulu */
	}
	
	if( item_name(current_item(my_menu)) == choices[2]){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		/* przekierowanie do innego modulu */
	}
	
		
	if( item_name(current_item(my_menu)) == choices[3]){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		/* przekierowanie do innego modulu */
	}
	
	if( item_name(current_item(my_menu)) == choices[4]){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		create_menu_one();
	}
	
	if( item_name(current_item(my_menu)) == NULL){
		unpost_menu(my_menu);
		free_menu(my_menu);
		for(int i = 0; i < n_choices; ++i)
			free_item(my_items[i]);
		endwin();
		my_items = NULL;
		my_menu = NULL;
		my_menu_win = NULL;
		create_menu_one();
	}
}
