/* ------------------------------------------------------------
                AlgoSdec - test de programmes
                Mini jeu du pendu
		F. Balmas		Jan 2022
   ------------------------------------------------------------
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int initialise(char *mot, char *trouve);
void affiche(char *trouve);
int existe(char lettre, char *mot, char* trouve);
int encore_a_trouver(char *trouve);

char *table_mots[]= { "classe", "calculs", "zoo",
    "chemin", "route", "cartable", "crayon", "mine",
    "coussin", "peluche", "cahier", "classeur", "de" };
char trouve[9];


int main() {
char mot[9];
int pos;
char lettre;
int nbmots;
int nblatrouver;
int bonl;
char test;
	int res;

	strcpy(mot,"class");
	printf("%s\n",mot);
	printf("Debut des tests");

	if(res !=1){
		printf("erreur dans %c\n", test);
		test = 'a';   
		res = existe(test,mot,trouve);
	}
	
	if(res !=1){
		printf("erreur dans %c\n", test);
		test = 'c';   
		res = existe(test,mot,trouve);
	}

	if(res !=1){
		printf("erreur dans %c\n", test);
		test = 'h';
		res = existe(test,mot,trouve);
	}
	
	printf("Tout est Ok\n\n");
	printf("Fin des test\n");
	return(EXIT_SUCCESS);

}
