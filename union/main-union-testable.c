/* -------------------------------------------------------------
   Union de 2 ensembles
   Version de XY simplifiée

   Cours F. Balmas                            2021
   -------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "liste.h"
#include "hashcode.h"

#define NB 10

int getpid();

/*
void random_char(char c[])
{
 int i;
   for(i = 0;i < 6;i++)
   {
      int rng = rand() % (122 - 119)+97 ;
      c[i] = (char)rng;
   };
   c[i]='\0';
}
*/

int main()
{
   // char liste_mots[NB][200];
   // char liste_mots2[NB][200];
   char liste_mots[NB][10]={ "tir", "car", "bar", "mur", "cor", "pur", "mer", "sel", "mal", "vue" };
   char liste_mots2[NB][10]={ "bord", "cale", "mur", "sel", "bleu", "vert", "car", "mer", "gris", "vue" };

   int compteur = 0;
/*
   srand(getpid());
   for(int i = 0; i< NB;i++)
   {
      random_char(liste_mots[i]);
      random_char(liste_mots2[i]);
   }
*/
   init_freeliste();
   init_tabhash();
   print_tabhash();
   int cmp = 0;
   for(int i = 0 ; i< NB ; i++)
   {
        //printf("%s \n", liste_mots[i]);
        add_nom(liste_mots[i]);
        cmp++;
   }
    int nbr_elemnt_union = 0;
    for(int i = 0;i<NB;i++)
    {
      if(search_nom(liste_mots2[i]) != NULL ){
         add_nom(liste_mots2[i]);
         compteur++;
        }
    }
    nbr_elemnt_union = compteur + cmp;

    print_tabhash();

    printf("==> soit %d elt\n",compteur);
   printf("nombre element ensemble 1 : %d\nnombre element ensemble 2 : %d\nnombres elements dans l'union %d\n",NB,NB,nbr_elemnt_union);

  	return EXIT_SUCCESS;
}
