all:
	gcc main.c -Wall -std=c99 -I /initialize/colors.c cvraport.h -I /include/style/color_style.h -I /include/style/panel_style.h -o main -l ncurses -l menu
