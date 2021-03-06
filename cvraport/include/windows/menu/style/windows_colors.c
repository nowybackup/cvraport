#include <ncurses.h>
#include <string.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

void style_window_colors(WINDOW *my_menu_win){
		
     		/* Wydrukowanie tytulu okna gdzie znajduje sie menu */
     		box(my_menu_win, 0, 0);
     		print_in_middle(my_menu_win, 1, 0, 40, "Moje menu", COLOR_PAIR(1));
     		mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
    		mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
    		mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

}
/* opencv sarclas fire */
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
