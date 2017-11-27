void start(){
	if(!initscr()) {
	fprintf(stderr, "Nie udalo uruchomic ncurses");
	return -1;
	}
}
