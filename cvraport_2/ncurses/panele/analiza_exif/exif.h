#ifndef EXIF_H
#define EXIF_H

/*biblioteki ncurses*/
#include <ncurses.h>
#include <panel.h>
#include <form.h>

/*bliblioteki standarowe*/
#include <string.h>
#include <stdlib.h>

/* deklaracja zmiennych wskaznikowych */

static FIELD *field[3];
static FORM  *my_form;
static WINDOW *my_form_win;

/*deklara wszystkich funkcji tego modulu*/
void panel_exif_delete();
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

#endif
