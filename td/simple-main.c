/*  Fichier de demo pour l'utilisation de la librairie list

    F. Balmas 2023
*/


#include <stdio.h>
#include <string.h>
#include "simple-liste.h"

void main() {

    struct linked TETE;
    LINKED T, ptr, ptr2;
    int i, nb;
    char buf[20];

    T=&TETE;
    init_list(T);

    // ajout de 5 elts dans la liste (au debut ou a la fin)
    printf("ajout de 5 elts initiaux\n");
    for (i=0 ; i<5 ; i++) {
        ptr = alloc_list();
        //init_list(ptr);
        sprintf(buf, "elt%d", i+1);
        strcpy(ptr->nom, buf);
        // add_begin(T, ptr);
        add_end(T, ptr);
    }
    print_list(T);

    // ajout de 1 elt en 2eme position
    printf("\najout de eltA en 2eme position\n");
    ptr = alloc_list();
    strcpy(ptr->nom, "eltA");
    ptr2 = T->cell;
    ptr->cell = ptr2->cell;
    ptr2->cell = ptr;
    print_list(T);

    // ajout de 1 elt en 4eme position
    printf("\najout de eltB en 4eme position\n");
    ptr = alloc_list();
    strcpy(ptr->nom, "eltB");
    ptr2 = T->cell->cell->cell;
    ptr->cell = ptr2->cell;
    ptr2->cell = ptr;
    print_list(T);

    // suppression du 2eme elt
    printf("\nsuppression du 2eme elt\n");
    T->cell->cell = T->cell->cell->cell;
    print_list(T);

    // permutation des elts 1 et 2
    printf("\npermutation des elts 1 et 2\n");
    ptr = T->cell->cell;
    T->cell->cell = T->cell->cell->cell;
    ptr->cell = T->cell;
    T->cell = ptr;
    print_list(T);

    // ajouter 1 elt au debut
    printf("\najouter eltDEB au debut\n");
    ptr = alloc_list();
    strcpy(ptr->nom, "eltDEB");
    add_begin(T, ptr);
    print_list(T);

    // ajouter 1 elt a la fin
    printf("\najouter eltFIN a la fin\n");
    ptr = alloc_list();
    strcpy(ptr->nom, "eltFIN");
    add_end(T, ptr);
    print_list(T);

    // calculer la longueur de la liste
    nb = length(T);
    printf("\nla liste contient %d elts\n", nb);
    print_list(T);

    // chercher si un elt fait partie de la liste
    printf("\nrecherche de elt3\n");
    ptr = member("elt3", T);
    if (ptr==NULL)
        printf("elt3 n'est pas dans la liste\n");
    else
        printf("elt3 est dans la liste\n");

    // chercher si un elt fait partie de la liste
    printf("\nrecherche de elt15\n");
    ptr = member("elt15", T);
    if (ptr==NULL)
        printf("elt15 n'est pas dans la liste\n");
    else
        printf("elt15 est dans la liste\n");


    // suppression de 2 elts a la fin
    printf("\nsuppression de 2 elts par la fin\n");
    for (i=0 ; i<2 ; i++) {
        remove_end(T);
        print_list(T);
    }

    // suppression de 3 elts au debut
    printf("\nsuppression de 3 elts au debut\n");
    for (i=0 ; i<3; i++) {
        remove_begin(T);
        print_list(T);
    }

    printf("\nliste finale\n");
    print_list(T);
}

/* trace d'execution

ajout de 5 elts initiaux
elt1, elt2, elt3, elt4, elt5,

ajout de eltA en 2eme position
elt1, eltA, elt2, elt3, elt4, elt5,

ajout de eltB en 4eme position
elt1, eltA, elt2, eltB, elt3, elt4, elt5,

suppression du 2eme elt
elt1, elt2, eltB, elt3, elt4, elt5,

permutation des elts 1 et 2
elt2, elt1, eltB, elt3, elt4, elt5,

ajouter eltDEB au debut
eltDEB, elt2, elt1, eltB, elt3, elt4, elt5,

ajouter eltFIN a la fin
eltDEB, elt2, elt1, eltB, elt3, elt4, elt5, eltFIN,

la liste contient 8 elts
eltDEB, elt2, elt1, eltB, elt3, elt4, elt5, eltFIN,

recherche de elt3
elt3 est dans la liste

recherche de elt15
elt15 n'est pas dans la liste

suppression de 2 elts par la fin
eltDEB, elt2, elt1, eltB, elt3, elt4, elt5,
eltDEB, elt2, elt1, eltB, elt3, elt4,

suppression de 3 elts au debut
elt2, elt1, eltB, elt3, elt4,
elt1, eltB, elt3, elt4,
eltB, elt3, elt4,

liste finale
eltB, elt3, elt4,

*/