/* ------------------------------------------------------------
                AlgoSdec - test de programmes
                Mini jeu du pendu - main pour tester
		F. Balmas		Jan 2022
   ------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <assert.h>

int existe (char lettre, char *mot, char *trouve);

char mot[9];
char trouve[9];


int main (void) {
  int res;

  /* creation de la configuration pour test, avec un mot de taille moyenne */
  printf("Tests avec un mot de taille moyenne : ");
  strcpy ( mot, "classe" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  /* appels a existe() et verification de son resultat */

  /* une lettre au milieu du mot */
  res = existe ('a', mot, trouve);
  assert (res == 1);

  /* une lettre qui existe deux fois */
  res = existe ('s', mot, trouve);
  assert (res == 2);

  /* la lettre au debut du mot */
  res = existe ('c', mot, trouve);
  assert (res == 1);

  /* la lettre a la fin du mot */
  res = existe ('e', mot, trouve);
  assert (res == 1);

  /* une lettre qui n'existe pas */
  res = existe ('m', mot, trouve);
  assert (res == 0);

  printf ("Tout est OK\n\n");


  /* creation de la configuration pour test, avec un mot le plus long */
  printf("Tests avec un mot le plus long possible : ");
  strcpy ( mot, "cartable" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  /* appels a existe() et verification de son resultat */

  /* une lettre au milieu du mot */
  res = existe ('t', mot, trouve);
  assert (res == 1);

  /* une lettre qui existe deux fois */
  res = existe ('a', mot, trouve);
  assert (res == 2);

  /* la lettre au debut du mot */
  res = existe ('c', mot, trouve);
  assert (res == 1);

  /* la lettre a la fin du mot */
  res = existe ('e', mot, trouve);
  assert (res == 1);

  /* une lettre qui n'existe pas */
  res = existe ('m', mot, trouve);
  assert (res == 0);

  printf ("Tout est OK\n\n");

  /* creation de la configuration pour test, avec un mot le plus court */
  printf("Tests avec un mot tres court : ");
  strcpy ( mot, "de" );
  printf("%s\n", mot);
  printf ("Debut des tests\n");

  /* appels a existe() et verification de son resultat */

  /* la lettre au debut du mot */
  res = existe ('d', mot, trouve);
  assert (res == 1);

  /* la lettre a la fin du mot */
  res = existe ('e', mot, trouve);
  assert (res == 1);

  /* une lettre qui n'existe pas */
  res = existe ('m', mot, trouve);
  assert (res == 0);

  printf ("Tout est OK\n\n");

  printf ("Fin des tests\n");

  return (EXIT_SUCCESS);
}
