#include <stdlib.h>

int main(void){
	open_ncurses();
	return 0;
}

/*

gcc -o main -std=c99 -Wall main.c -I include/open_ncurses.c  -I include/create_menu_date.c -I include/create_menu_exif.c -I include/create_menu_graphic.c -I include/create_menu_one.c -I include/create_menu_window.c -I include/style_colors/style_menu.c -I include/style_colors/style_window_colors.c  -l ncurses -l menu

*/
