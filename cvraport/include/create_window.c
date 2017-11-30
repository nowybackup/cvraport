#include <ncurses>

void create_window(){

	WINDOW *my_menu_win;
	style_menu(my_menu)

        /* Ustawienie głównego okna oraz okna podrzędnego */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
        set_menu_format(my_menu, 5, 1);

	/* Tworzenie obramowania okna gdzie znajduje sie menu*/
        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);

        /* Wydrukowanie tytulu okna gdzie znajduje sie menu */
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Moje menu", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

        /* Przypięcie menu do okna*/
        post_menu(my_menu);
        wrefresh(my_menu_win);

}
