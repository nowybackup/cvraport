#include <ncurses.h>
#include "func_windows.h"

void open_ncurses(){
	initscr();
	cbreak();
         noecho();
	WINDOW *my_menu_win;
	create_menu_window(my_menu_win);
	endwin();
}
