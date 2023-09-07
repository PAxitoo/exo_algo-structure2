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

int initialise(char *mot, char *trouve);
void affiche(char *trouve);
int existe(char lettre, char *mot, char *trouve);
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

  srand(getpid());
  for ( ; ; ) {

	nbmots = sizeof(table_mots)/sizeof(char *);
	// ligne normale
	strcpy (mot, table_mots[( rand() % nbmots) ]);
    // ligne pour tirer un mot particulier
	// strcpy (mot, table_mots[5]);

    nblatrouver = initialise(mot, trouve);
	printf ("Mot a trouver de %d lettres\n", nblatrouver);

    affiche(trouve);

	while (nblatrouver != 0) {
	   printf ("\nProposez une lettre : ");
	   scanf ("%c", &lettre); getchar();

	   if (existe(lettre, mot, trouve) >= 1) {
           affiche(trouve);
	   }
	   else {
		   printf ("Cette lettre ne fait pas partie du mot a trouver\n");
	   }

	   nblatrouver=encore_a_trouver(trouve);;
	}
	printf ("Bravo, vous avez trouve\n\n\n");
  }
}
