#include <curses.h>
#include <menu.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD   4

char *choices[] = {
                        "Analiza EXIF",
                        "Analiza graficzna",
                        "Analiza zgromadzonych danych",
                        "Exit",
                        (char *)NULL,
                  };
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int main()
{       ITEM **my_items;
        int c;                          
        MENU *my_menu;
        WINDOW *my_menu_win;
        int n_choices, i;
        
        /* Inicializacja cuses */
        initscr();
        start_color();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);

        /* Utworzenie przedmiotow */
        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i)
                my_items[i] = new_item(choices[i], choices[i]);

        /* Utworzenie menu */
        my_menu = new_menu((ITEM **)my_items);

        /* Tworzenie obramowania okna gdzie znajduje sie menu*/
        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);
     
        /* Ustawienie głównego okna oraz okna podrzędnego */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
        set_menu_format(my_menu, 5, 1);
                        
        /*  Ustawienie znacznika wyboru opcji z listy menu " * " */
        set_menu_mark(my_menu, " * ");

	/* Ustawienie opcji menu tak by nie wyświetlac opisu*/
        menu_opts_off(my_menu, O_SHOWDESC);

        /* Wydrukowanie tytulu okna gdzie znajduje sie menu */
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Moje menu", C:OLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

        /* Ustawienie tła dla dla opcjiru oraz koloru listy*/
        set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
        set_menu_back(my_menu, COLOR_PAIR(2));
        set_menu_grey(my_menu, COLOR_PAIR(3));
        
        /* Wykonanie menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
        
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 2, 0, "Uzyj strzalek oraz klawisza ENTER, apy poruszac sie po programie");
        mvprintw(LINES - 1, 0, "Wybranie obcji exit z menu oraz wcisniecie klawisza F1 powoduje wyjscie z programu");
        attroff(COLOR_PAIR(2));
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

        /* Zwalnianie pamięci */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
        endwin();
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
