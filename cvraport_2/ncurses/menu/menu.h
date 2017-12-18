#ifndef CREATE_MENU_H
#define CREATE_MENU_H

/*stale zdefiniowane w tym module*/
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD   4

/*biblioteki ncurses*/
#include <ncurses.h>
#include <menu.h>

/*bliblioteki standarowe*/
#include <string.h>
#include <stdlib.h>

/*zmienne stale zadeklarowane w tym module*/
static ITEM **my_items;                         
static MENU *my_menu;
static WINDOW *my_menu_win;

/*funkcje zadeklarowane w tym module*/
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

void create_menu_one();
void create_menu_exif();
void create_menu_date();
void create_menu_graphic();
void create_menu_help();

int create_menu_exit();

/*przekierowanie do innego modulu*/



#endif
