#include <stdio.h>
int main (int argc, char *argv[])
{
FILE *wp;
int tab[10000];

	if (argc != 2)
	{
		fprintf(stderr, "Uzycie: %s nazwa_pliku\n", argv[0]);
		return -1;
	}
	if ((wp = fopen(argv[1], "r")) != NULL){

	/* Wczytanie pliku do tablicy*/

	} 

	else {
		fprintf(stderr, "Pliku: %s nie udalo sie otworzyc\n", argv[1]);
		return -1;
	}

return 0;

}
