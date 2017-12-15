/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: donmatteo
 *
 * Created on 11 grudnia 2017, 22:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tab[20000];

char zlap_wiersz[80];
char *wiersz;

int hash = 0;
int new_hash = 5381;
int id = 0;
int zlicz_kolizje = 0;

void odczytaj (char *filename);

/* Funkcja lapiaca wiesz */
void func_zlap_wiersz(int znak){
        
	if (znak == 13){
		strcpy(wiersz, zlap_wiersz);
		zlap_wiersz[0] = 0;
	}
	
	size_t n = strlen(zlap_wiersz);
         zlap_wiersz[n++] = (char)znak;
         zlap_wiersz[n] = 0;
}

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

/* Funkcja rozpraszajaca, haszujaca*/
void new_func_hash(int znak){
	
	if (znak == 13){
		id = new_hash;
		new_hash = 5381;
	}

	if (znak != 13){
		new_hash = new_hash*33 + znak;
		new_hash = new_hash%20000;
	}

}

/* Wstawianie do tablicy z rozwiązanym problemem kolizji*/
void wstaw(int id, char *wiersz){

        if(id == 20000){
            id = 0;
        }
    
	if(tab[id] != NULL){
                  zlicz_kolizje++;
	 	wstaw(id+1, wiersz);
	}
	
	if(tab[id] == NULL){
		tab[id] = wiersz;
	}
}

/*Wyszukanie zadanego elementu w tablicy liniowo*/
void wyszukaj_hash(char *slowo){

	//func_hash(slowo);

}

void wyszukaj_new_hash(){


}

/* Procedura czyta z pliku */
void odczytaj(char *filename){

	FILE *wp;
	int znak;

	if ((wp = fopen(filename, "r")) != NULL){

		/* Wczytanie pliku do tablicy*/

		znak = fgetc(wp);

		while (znak != EOF){
			znak = fgetc(wp);
			func_zlap_wiersz(znak);    /* zlapanie wiersza */
			new_func_hash(znak);       /* obliczenie id    */
			if (znak == 13){
				//wstaw(id, wiersz);
                                   //printf("%s", tab[id]);
			}
			printf("%c", znak);
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
    
        if (argv[0] == NULL){
            printf("Program musi zostac odpalony z argumentem poczatkowym");
        }
    
	if (argc != 2){
		fprintf(stderr, "Uzycie: %s filename\n", argv[0]);
		return -1;
	} 
     
	odczytaj (argv[1]);
        
        printf("Zaistniale kolizje: %d", zlicz_kolizje);

return 0;

}
