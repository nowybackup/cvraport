#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>

#include "style/func_menu.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void create_menu_one(MENU *my_menu){

	ITEM **my_items;

 	char *choices[] = {
			"Analiza Exif",
			"Analiza graficzna",
			"Analiza zgromadzonych danych",
			"Pomoc",
			"Exit",
			(char *)NULL,
		};

	
		int n_choices = 0;
		n_choices = ARRAY_SIZE(choices);
        		my_items = (ITEM **)calloc((n_choices), sizeof(ITEM *));

		for(int i = 0; i < n_choices; i++){
		my_items[i] = new_item(choices[i], choices[i]);
		}

	/* Utworzenie menu one */
         my_menu = new_menu((ITEM **)my_items);

	/* Ustawienie opcji menu one tak, aby nie wyświetlała opisu*/
         menu_opts_off(my_menu, O_SHOWDESC);

	/* Ustawienie kolorow i parametrow czcionki*/
	style_menu(my_menu);

}