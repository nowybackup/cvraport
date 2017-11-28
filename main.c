#include <curses.h>
#include <menu.h>
#include <string.h>
#include <stdlib.h>
#include <panel.h>

#include "include/initialize/colors.c"

#include "cvraport.h"
#include "include/style/color_style.h"
#include "include/style/panel_style.h"

void inicialize_program(){

	ITEM **my_items;
         WINDOW *my_menu_win;	
      	int c;

         initscr(); 		/* Inicializacja curses */
         start_color();
         cbreak();
         noecho();
         keypad(stdscr, TRUE);

         initialize_colors(); 	/* Inicializacja wszystkich kolorow */

}

void elemnts_menu_one(void){
	char *choices_menu_one[] = {
			"Analiza Exif",
			"Analiza graficzna",
			"Analiza zgromadzonych danych",
			"Pomoc",
			"Exit",
			(char *)NULL,
		}
}

void elemnts_menu_exif(void){
	char *choices_menu_exif[] = {
                  	"Pszeszukanie danych dysku w poszukiwaniu danych exif",
			"Zapis znalezionych scierzek do pliku",
			"Usuniecie danych exif",
			"Exit",
			(char *)NULL,
		}
}

void elemnts_menu_graphic(void){
	char *choices_menu_graphic[] = {
			"Znajdz osobe",
			"Exit",
			(char *)NULL,
		}
}

void elemnts_menu_date(void){
	char *choices_menu_date[] = {
			"Wyswietl tabele z bazy danych",
			"Analiza danych exif na mapie",
			"Wyniki analizy graficznej",
			"Zarzadzaj baza danych",
			"Exit",
                           (char *)NULL,
                  }
}

void create_menu_one(ITEM **my_items){
	extern char *choices_menu_one[];
	int n_choices_menu = 0;
		n_choices_menu = ARRAY_SIZE(choices_menu_one);
        		my_items = (ITEM **)calloc((n_choices_menu), sizeof(ITEM *));

		for(int i = 0; i < n_choices_menu; i++){
		my_items[i] = new_item(choices_menu_one[i], choices_menu_one[i]);
		}

	}


void create_menu_exif(ITEM **my_items){
	extern char *choices_menu_exif[];
	int n_choices_menu = 0;
		n_choices_menu = ARRAY_SIZE(choices_menu_exif);
        		my_items = (ITEM **)calloc((n_choices_menu), sizeof(ITEM *));

		for(int i = 0; i < n_choices_menu; i++){
		my_items[i] = new_item(choices_menu_exif[i], choices_menu_exif[i]);
		}

	}

void create_menu_graphic(ITEM **my_items){
	extern char *choices_menu_graphic[];
	int n_choices_menu = 0;
		n_choices_menu = ARRAY_SIZE(choices_menu_graphic);
        		my_items = (ITEM **)calloc((n_choices_menu), sizeof(ITEM *));

		for(int i = 0; i < n_choices_menu; i++){
		my_items[i] = new_item(choices_menu_graphic[i], choices_menu_graphic[i]);
		}

	}

void create_menu_date(ITEM **my_items){
	extern char *choices_menu_date[];
	int n_choices_menu = 0;
		n_choices_menu = ARRAY_SIZE(choices_menu_date);
        		my_items = (ITEM **)calloc((n_choices_menu), sizeof(ITEM *));

		for(int i = 0; i < n_choices_menu; i++){
		my_items[i] = new_item(choices_menu_date[i], choices_menu_date[i]);
		}

	}

void create_menu(ITEM **my_items){
	
	MENU *my_menu;

        /* Utworzenie elementow menu */         
	create_menu_one(my_items);
	create_menu_exif(my_items);
	create_menu_graphic(my_items);
	create_menu_date(my_items);

	/* Utworzenie menu */
        my_menu = new_menu((ITEM **)my_items);

	/* Ustawienie opcji menu tak by nie wyświetlac opisu*/
        menu_opts_off(my_menu, O_SHOWDESC);
	
}

void windows(){

        /* Ustawienie głównego okna oraz okna podrzędnego */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
        set_menu_format(my_menu, 5, 1);
                        
        /*  Ustawienie znacznika wyboru opcji z listy menu " * " */
        set_menu_mark(my_menu, " * ");

        /* Przypięcie menu do okna*/
        post_menu(my_menu);
        wrefresh(my_menu_win);

}

void graphic_menu(void){

	/* Tworzenie obramowania okna gdzie znajduje sie menu*/
        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);

        /* Ustawienie tła dla dla opcjiru oraz koloru listy*/
        set_menu_fore(my_menu, MOCNY_CZERWONY | A_REVERSE);
        set_menu_back(my_menu, JASNY_NIEBIESKI);
        set_menu_grey(my_menu, MOCNY_ZIELONY);

        /* Wydrukowanie tytulu okna gdzie znajduje sie menu */
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Moje menu", MOCNY_CZERWONY);
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

}

void help_menu(){

        attron(MOCNY_NIEBIESKI);
        mvprintw(LINES - 2, 0, "Mozesz urzyc strzalek oraz klawisza enter");
        mvprintw(LINES - 1, 0, "Wcisniecie klawisza F1 powoduje wyjscie z programu");
        attroff(MOCNY_NIEBIESKI);

}

void open_interfejs(){
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

void free_unpost(){

        /* Zwalnianie pamięci */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(int i = 0; i < n_choices_menu; i++){
		free_item(my_items[i]);
	}
	
        endwin();

}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int main()
{       
        

}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{       int length, x, y;
        float temp;

        if(win == NULL)
                win = stdscr;
        getyx(win, y, x);
        if(startx != 0)
                x = startx;
        if(starty != 0)
                y = starty;
        if(width == 0)
                width = 80;

        length = strlen(string);
        temp = (width - length)/ 2;
        x = startx + (int)temp;
        wattron(win, color);
        mvwprintw(win, y, x, "%s", string);
        wattroff(win, color);
        refresh();
}
