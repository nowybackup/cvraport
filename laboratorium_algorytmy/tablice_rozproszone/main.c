#include <stdio.h>
#include <stdlib.h>

char tab[20000];
int hash = 0;
int id = 0;

void odczytaj (char *filename);

/* Procedura sumuje wartosci liter */
void func_hash(int znak){
	
	if (znak == 13){
		id = hash;
		hash = 0;
	}

	if (znak != 13){
		hash = hash + znak;
	}

}

/* Procedura czyta z pliku */
void odczytaj(char *filename){

	FILE *wp;
	int znak;

	if ((wp = fopen(filename, "r")) != NULL){

		/* Wczytanie pliku do tablicy*/

		znak = fgetc(wp);

		while (znak != EOF){
			putchar(znak);
			znak = fgetc(wp);
			func_hash(znak);
			if (znak == 13){
				printf("%d", id);
			}
		}
		if(feof(wp)){
			fprintf(stderr, "KONIEC PLIKU\n");
		}

		fclose(wp);

	} else {
		perror("Pliku nie udalo sie otworzyc");
		exit (-1);
	}

}


int main (int argc, char *argv[]){

	if (argc != 2){
		fprintf(stderr, "Uzycie: %s filename\n", argv[0]);
		return -1;
	}

	odczytaj (argv[1]);


return 0;

}
