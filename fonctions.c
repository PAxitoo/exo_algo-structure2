/* -------------------------------------------------------------
                AlgoSdec - test de programmes
                Mini jeu du pendu - les fonctions
		F. Balmas		Jan 2022
   -------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>

// extern char trouve[9];

int existe ( char lettre, char *mot, char *trouve ) {
  int pos;
  int bonl;

  bonl = 0;
  // ligne ou il y a l'erreur
  for (pos=0 ; pos < 7 && mot[pos] != '\0' ; pos++) {
  // ligne corrigee
  // for (pos=0 ; pos <= 7 && mot[pos] != '\0'; pos++) {
      if (mot[pos] == lettre) {
          bonl += 1;
	      trouve[pos] = lettre;
	  }
    }
  return bonl;
}

int initialise (char *mot, char *trouve) {
	int pos, nbl;

	for(pos=0; pos<=7 && mot[pos]!='\0' ; pos++) {
		trouve[pos]='-';
	}
	nbl=pos;
	for (  ; pos<=7 ; pos++) {
		trouve[pos]='*';
	}
	trouve[pos]='\0';

	return nbl;
}

int encore_a_trouver(char *trouve) {
    int pos, cpt;
    for (pos=0, cpt=0 ; pos <=7 ; pos++) {
        if (trouve[pos] == '-') {
            cpt++;
        }
    }
    return cpt;
}

void affiche(char *trouve) {
	int pos;

	for (pos=0 ; pos<=7 && trouve[pos]!='*' ; pos++) {
		printf("%c ", trouve[pos]);
	}
	printf("\n");
}
