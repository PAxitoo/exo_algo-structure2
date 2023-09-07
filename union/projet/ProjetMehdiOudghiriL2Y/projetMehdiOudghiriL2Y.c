#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define TAB_SIZE 200

//génère un tableau aléatoire à partir d'un alphabet donné.

void gentable(char *table, int table_size, char *alphabet, int alphabet_size) {
    srand(time(NULL));

    for (int i = 0; i < table_size; i++) {
        table[i] = alphabet[rand() % alphabet_size];
    }
}

// affiche un tableau de caractères sur le terminal.

void printtable(char *table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        printf("%c", table[i]);
    }
    printf("\n");
}

void find_occu(char tab[], int tab_size, int jis[TAB_SIZE][2], int *taille) {
    int count = *taille;
    for (int i = 0; i < tab_size; i++) {
        int j = i;
        if (tab[j] == 'D') {
            j++;
            if (tab[j] == 'G') {
                j++;
                while (tab[j] == 'G') {
                    j++;
                }
                if (tab[j] == 'H') {
                    j++;
                    while (tab[j] == 'O') {
                        j++;
                    }
                    jis[count][0] = i;
                    jis[count][1] = j;
                    count++;
                }
            }
        }
    }
    *taille = count;
}


void find_occu2(char tab[], int tab_size, int jis[TAB_SIZE][2], int *taille) {
    int count = *taille;
    for (int i = 0; i < tab_size; i++) {
        int j = i;
        if (tab[j] == 'D') {
            j++;
            while (tab[j] == 'G') {
                j++;
            }
            if (tab[j] == 'H') {
                j++;
                while (tab[j] == 'O') {
                    j++;
                }
                jis[count][0] = i;
                jis[count][1] = j;
                count++;
            }
        }
    }
    *taille = count;
}

void printjis(int jis[TAB_SIZE][2], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d %d\n", jis[i][0], jis[i][1]);
    }
}


void sort_occurrences(int occurrences[][2], int occurrences_size) {
    for (int i = 0; i < occurrences_size; i++) {
        for (int j = i+1; j < occurrences_size; j++) {
            if (occurrences[i][0] < occurrences[j][0] ||
               (occurrences[i][0] == occurrences[j][0] && occurrences[i][1] < occurrences[j][1])) {
                int temp_i = occurrences[i][0];
                int temp_j = occurrences[i][1];
                occurrences[i][0] = occurrences[j][0];
                occurrences[i][1] = occurrences[j][1];
                occurrences[j][0] = temp_i;
                occurrences[j][1] = temp_j;
            }
        }
    }
}

void union_occurrences(int occurences1[TAB_SIZE][2], int occurences1_size,
                        int occurences2[TAB_SIZE][2], int occurences2_size,
                        int union_occurences[TAB_SIZE][2], int *union_occurences_size){

    // corps a corps des ++ tableaux d'occurrences
    int total_occurences_size = occurences1_size + occurences2_size;
    int total_occurences[total_occurences_size][2];

    for (int i = 0; i < occurences1_size; i++) {
        total_occurences[i][0] = occurences1[i][0];
        total_occurences[i][1] = occurences1[i][1];
    }

    for (int i = 0; i < occurences2_size; i++) {
        total_occurences[occurences1_size + i][0] = occurences2[i][0];
        total_occurences[occurences1_size + i][1] = occurences2[i][1];
    }
    // Saperlipopette ça tri mon tableau d'occurrences en ordre décroissant
    sort_occurrences(total_occurences, total_occurences_size);

    // OMG ça ajout des occurrences triées dans le tableau union_occurences
    int count = 0;
    for (int i = 0; i < total_occurences_size; i++) {
        if (i == 0 ||
           (total_occurences[i][0] != total_occurences[i-1][0] || total_occurences[i][1] != total_occurences[i-1][1])) {
            union_occurences[count][0] = total_occurences[i][0];
            union_occurences[count][1] = total_occurences[i][1];
            count++;
        }
    }

    *union_occurences_size = count;
}

void test_find_occu() {
    char test_table[] = "DGHO";
    int occurences_attendu[][2] = {0, 4};
    int occurences_attendu_size = 1;
    int occurrences[TAB_SIZE][2];
    int occurrences_size = 0;

    find_occu(test_table, strlen(test_table), occurrences, &occurrences_size);

    if (occurrences_size != occurences_attendu_size) {
        printf("Test find_occu: FAILURE\n");
        return;
    }

    for (int i = 0; i < occurrences_size; i++) {
        if (occurrences[i][0] != occurences_attendu[i][0] || occurrences[i][1] != occurences_attendu[i][1]) {
            printf("Test find_occu: FAILURE\n");
            return;
        }
    }

    printf("Test find_occu: SUCCESS\n");
}

void test_find_occu2() {
    char test_table[] = "DH";
    int occurences_attendu[][2] = {0, 2};
    int occurences_attendu_size = 1;
    int occurrences[TAB_SIZE][2];
    int occurrences_size = 0;

    find_occu2(test_table, strlen(test_table), occurrences, &occurrences_size);

    if (occurrences_size != occurences_attendu_size) {
        printf("Test find_occu2: FAILURE\n");
        return;
    }

    for (int i = 0; i < occurrences_size; i++) {
        if (occurrences[i][0] != occurences_attendu[i][0] || occurrences[i][1] != occurences_attendu[i][1]) {
            printf("Test find_occu2: FAILURE\n");
            return;
        }
    }
    printf("Test find_occu2: SUCCESS\n");
}

void test_union_occurrences() {
    int occurences1[][2] = {{1, 4}, {6, 9}, {11, 14}};
    int occurences1_size = 3;
    int occurences2[][2] = {{3, 6}, {6, 9}, {13, 16}};
    int occurences2_size = 3;

    int expected_union_occurences[][2] = {{1, 4}, {6, 9}, {11, 14}, {3, 6}, {13, 16}};
    int expected_union_occurences_size = 5;

    int actual_union_occurences[TAB_SIZE][2];
    int actual_union_occurences_size = 0;

    union_occurrences(occurences1, occurences1_size, occurences2, occurences2_size, actual_union_occurences, &actual_union_occurences_size);

    if (actual_union_occurences_size != expected_union_occurences_size) {
        printf("Test union_occurrences: FAILURE\n");
        return;
    }

    sort_occurrences(actual_union_occurences, actual_union_occurences_size);
    sort_occurrences(expected_union_occurences, expected_union_occurences_size);

    for (int i = 0; i < actual_union_occurences_size; i++) {
        if (actual_union_occurences[i][0] != expected_union_occurences[i][0] || actual_union_occurences[i][1] != expected_union_occurences[i][1]) {
            printf("Test union_occurrences: FAILURE\n");
            return;
        }
    }

    printf("Test union_occurrences: SUCCESS\n");
}



void test_sort_occurrences() {
    int occurrences[][2] = {{3, 6}, {1, 4}, {7, 10}, {5, 8}};
    int occurrences_size = 4;
    int expected_sorted[][2] = {{7, 10}, {5, 8}, {3, 6}, {1, 4}};
    
    sort_occurrences(occurrences, occurrences_size);

    for (int i = 0; i < occurrences_size; i++) {
        if (occurrences[i][0] != expected_sorted[i][0] || occurrences[i][1] != expected_sorted[i][1]) {
            printf("Test sort_occurrences: FAILURE\n");
            return;
        }
    }

    printf("Test sort_occurrences: SUCCESS\n");
}


void affiche_un_motif (char *str, int deb, int fin) { 
    if (deb>fin) {
        printf(" ");
        return;
    }
    printf("%c", str[deb]);
    affiche_un_motif (str, deb+1, fin);
}

void affiche_motifs(int *taboccur, int indocc, int nbocc, char *str) {
    if (indocc >= nbocc*2) {
        printf("\n");
        return;
    }
    affiche_un_motif(str, taboccur[indocc], taboccur[indocc+1]); 
    affiche_motifs(taboccur, indocc+2, nbocc, str);
}



int main() {
    char table[TAB_SIZE];
    int occurences1[TAB_SIZE][2];
    int occurences1_size = 0;
    int occurences2[TAB_SIZE][2];
    int occurences2_size = 0;

    srand(time(NULL));
    char alphabet[] = "DGHO";
    for (int i = 0; i < TAB_SIZE; i++) {
        table[i] = alphabet[rand() % strlen(alphabet)];
    }

    printf("Tableau : ");
    printtable(table, TAB_SIZE);

    // Recherche des occurrences du motif DG+HO*
    find_occu(table, TAB_SIZE, occurences1, &occurences1_size);
    printf("Occurrences du motif DG+HO* :\n");
    printjis(occurences1, occurences1_size);

    // Recherche des occurrences du motif DG*HO
    find_occu2(table, TAB_SIZE, occurences2, &occurences2_size);
    printf("Occurrences du motif DG*HO? :\n");
    printjis(occurences2, occurences2_size);

    // Union des occurrences
    int union_occurences[TAB_SIZE][2];
    int union_occurences_size = 0;

    union_occurrences(occurences1, occurences1_size, occurences2, occurences2_size, union_occurences, &union_occurences_size);

    printf("Union des occurrences des motifs DG+HO* et DG*HO? :\n");
    printjis(union_occurences, union_occurences_size);

    // Tests pour les fonctions find_occu et find_occu2
    test_find_occu();
    test_find_occu2();

    // Tests pour la fonction union_occurrences
    test_union_occurrences();


    // Tests pour la fonction sort_occurrences
    test_sort_occurrences();

    // Conversion du tableau d'occurrences 2D en un tableau 1D
    int union_occurences_plat[TAB_SIZE * 2];
    for (int i = 0; i < union_occurences_size; i++) {
        union_occurences_plat[i * 2] = union_occurences[i][0];
        union_occurences_plat[i * 2 + 1] = union_occurences[i][1];
    }

    // Appel de la fonction affiche_motifs
    printf("Motifs trouvés pour chaque occurrence:\n");
    affiche_motifs(union_occurences_plat, 0, union_occurences_size, table);

    return 0;
}
