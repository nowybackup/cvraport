#include <ncurses.h>

void open_ncurses(){
	initscr();
	create_menu_window();
	endwin();
}
