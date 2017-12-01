#include <ncurses>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

MENU create_menu_date(MENU *my_menu){

	ITEM **my_items;

 	char *choices[] = {
			"Wyswietl tabele z bazy danych",
			"Analiza danych exif na mapie",
			"Wyniki analizy graficznej",
			"Zarzadzaj baza danych",
			"Exit",
                           (char *)NULL,
                  }

	
		int n_choices = 0;
		n_choices = ARRAY_SIZE(choices);
        		my_items = (ITEM **)calloc((n_choices), sizeof(ITEM *));

		for(int i = 0; i < n_choices; i++){
		my_items[i] = new_item(choices[i], choices[i]);
		}

	/* Utowrzenie lementow menu one */
	create_menu_one(my_items);

	/* Utworzenie menu one */
         my_menu = new_menu((ITEM **)my_items);

	/* Ustawienie opcji menu one tak, aby nie wyświetlała opisu*/
         menu_opts_off(my_menu, O_SHOWDESC);

	/* Ustawienie kolorow i parametrow czcionki*/
	style_menu(my_menu);

	return my_menu;
}
