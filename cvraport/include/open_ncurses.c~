#include <ncurses.h>
#include "windows/func_windows.h"

void cvraport_open(){
	initscr();
	cbreak();
         noecho();
         keypad(stdscr, TRUE);
}

void cvraport_close(){

	endwin();
}

void open_ncurses(){

	cvraport_open();	

	create_menu_window();

	cv_raport_close();
}
