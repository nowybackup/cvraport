void add_help_menu(){
	attron(MOCNY_NIEBIESKI);
         mvprintw(LINES - 2, 0, "Mozesz urzyc strzalek oraz klawisza enter");
         mvprintw(LINES - 1, 0, "Wcisniecie klawisza F1 powoduje wyjscie z programu");
         attroff(MOCNY_NIEBIESKI);
}
