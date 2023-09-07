/* -------------------------------------------------------------
   Demo hashcoding

   F. Balmas                                 2022
   -------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include "freel-liste.h"
#include "hashcode.h"


char *table_mots[]= { "vigne", "calculer", "chemin", "route",
                    "cartable", "crayon", "mine", "coussin",
                    "pelochon", "cahier", "classeur", "" };

void main() {
  int i, sortie;
  char mot[21];
  char action;
  LINKED res;

  init_freeliste();
  init_tabhash();

  for (i=0; table_mots[i]!="" ; i++) {
    printf("ajout de %s\n", table_mots[i]);
    add_nom(table_mots[i]);
  }
  print_tabhash();
  printf("%d elts ajoutes\n", i);

  // a coder :
  // boucle interactive permettant de chercher si un mot est dans
  // la table_hash, avec search_nom(char *)
  // d'ajouter d'autres mots, avec add_nom(char *)
  // d'afficher la table_hash, avec print_tabhash()
  // ou de quitter
  do {
    printf("Entrez une action (s pour chercher, a pour ajouter, p pour afficher, q pour quitter): ");
    scanf(" %c", &action);
    switch (action) {
      case 's':
        printf("Entrez le mot a chercher: ");
        scanf("%s", mot);
        res = search_nom(mot);
        if (res == NULL) {
          printf("Le mot n'est pas dans la table_hash.\n");
        } else {
          printf("Le mot est dans la table_hash.\n");
        }
        break;
      case 'a':
        printf("Entrez le mot a ajouter: ");
        scanf("%s", mot);
        add_nom(mot);
        printf("Le mot a ete ajoute a la table_hash.\n");
        break;
      case 'p':
        print_tabhash();
        break;
      case 'q':
        sortie = 1;
        break;
      default:
        printf("Action non reconnue.\n");
        break;
    }
  } while (!sortie);

}

/*   traces d'execution

ajout de vigne
ajout de calculer
ajout de chemin
ajout de route
ajout de cartable
ajout de crayon
ajout de mine
ajout de coussin
ajout de pelochon
ajout de cahier
ajout de classeur
print tabhash
0 :
1 : crayon,
2 : pelochon, coussin,
3 : calculer,
4 : cahier, cartable,
5 : classeur, mine, chemin, vigne,
6 : route,
11 elts ajoutes

*/
