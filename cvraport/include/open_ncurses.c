#include <ncurses.h>
#include "windows/func_windows.h"

void open_ncurses(){
	initscr();
	cbreak();
         noecho();
	create_menu_window();
	endwin();
}
