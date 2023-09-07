/*  Ce fichier contient les definitions necessaires pour
    l'implementation de la librairie list (version simplifiee)

    F. Balmas 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple-liste.h"


// malloc systematique, pas de freelist
LINKED alloc_list(void) {
LINKED p;

 p = (LINKED)malloc(sizeof(struct linked));
 if (p == NULL) {
     printf("Pb memoire\n");
     exit(1);
 }
 init_list(p);
 return p;
}

void init_list (LINKED l) {
	l->cell = NULL;
}

void add_begin (LINKED t, LINKED l) {
	l->cell = t->cell;
	t->cell = l;
}

void add_end (LINKED t, LINKED l) {
LINKED p;
	for (p=t ; p->cell!=NULL ; p=p->cell);
	p->cell = l;
}

LINKED remove_begin (LINKED t) {
LINKED ptr;
    if (t->cell == NULL) {
        fprintf(stderr, "liste vide, remove imposible\n");
        return NULL;
    }
    ptr = t->cell;
	t->cell = (t->cell)->cell;
    return ptr;
}

LINKED remove_end (LINKED t) {
LINKED p, ptr;
    if (t->cell == NULL) {
        fprintf(stderr, "liste vide, remove imposible\n");
        return NULL;
    }
	for (p=t ; (p->cell)->cell != NULL ; p=p->cell);
    ptr = p->cell;
	p->cell = NULL;
    return ptr;
}

void print_list (LINKED l) {
LINKED p;

	for (p=l->cell ; p!= NULL ; p=p->cell)
	    print_nom(p);
	printf ("\n");
}

void print_nom(LINKED contact) {
  printf ("%s, ", contact->nom);
}

LINKED member (char *x, LINKED l) {
LINKED p;
	for (p=l->cell ; p!=NULL ; p=p->cell) {
	   if ( strcmp(p->nom, x) == 0 )
		return (p);
	   }
	return ((LINKED) 0);
}

int length(LINKED l) {
LINKED p;
int n=0;
 for (p=l->cell ; p!=NULL ; p=p->cell)
   n++;
 return n;
}
