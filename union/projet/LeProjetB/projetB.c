#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAB_SIZE 200

void gentable(char *table, int table_size, char *alphabet, int alphabet_size) {
    srand(time(NULL));

    for (int i = 0; i < table_size; i++) {
        table[i] = alphabet[rand() % alphabet_size];
    }
}

void printtable(char *table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        printf("%c", table[i]);
    }
    printf("\n");
}
void find_occu(char tab[TAB_SIZE], int jis[TAB_SIZE][2], int *taille) {
    int count = *taille;
    for(int i = 0; i < TAB_SIZE; i++){
        int j = i;
        if(tab[j]== 'D'){
            j++;
            if(tab[j]== 'G'){
                j++;
                while(tab[j]== 'G'){
                    j++;
                }
                if(tab[j]== 'H'){
                    j++;
                    while(tab[j]== 'O'){
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
void printjis(int jis[TAB_SIZE][2], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d %d\n", jis[i][0], jis[i][1]);
    }
}
void find_occu2(char tab[TAB_SIZE], int jis[TAB_SIZE][2], int *taille) {
    int count = *taille;
    for(int i = 0; i < TAB_SIZE; i++){
        int j = i;
        if(tab[j]== 'D'){
            j++;
            while(tab[j]== 'G'){
                j++;
            }
            if(tab[j]== 'H'){
                j++;
                while(tab[j]== 'O'){
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
void union_occurrences(int occurences1[TAB_SIZE][2], int occurences1_size,
                        int occurences2[TAB_SIZE][2], int occurences2_size,
                        int union_occurences[TAB_SIZE][2], int *union_occurences_size){

    // corps a corps des  tableaux d'occurrences
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
    // Saperlipopette ça tir mon tableau d'occurrences en ordre décroissant
    for (int i = 0; i < total_occurences_size; i++) {
        for (int j = i+1; j < total_occurences_size; j++) {
            if (total_occurences[i][0] < total_occurences[j][0] ||
               (total_occurences[i][0] == total_occurences[j][0] && total_occurences[i][1] < total_occurences[j][1])) {
                int temp_i = total_occurences[i][0];
                int temp_j = total_occurences[i][1];
                total_occurences[i][0] = total_occurences[j][0];
                total_occurences[i][1] = total_occurences[j][1];
                total_occurences[j][0] = temp_i;
                total_occurences[j][1] = temp_j;
            }
        }
    }
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
    find_occu(table, occurences1, &occurences1_size);
    printf("Occurrences du motif DG+HO* :\n");
    printjis(occurences1, occurences1_size);

    // Recherche des occurrences du motif DG*HO?
    find_occu2(table, occurences2, &occurences2_size);
    printf("Occurrences du motif DG*HO? :\n");
    printjis(occurences2, occurences2_size);

    // Union des occurrences
    int union_occurences[TAB_SIZE][2];
    int union_occurences_size = 0;

    union_occurrences(occurences1, occurences1_size, occurences2, occurences2_size, union_occurences, &union_occurences_size);

    printf("Union des occurrences des motifs DG+HO* et DG*HO? :\n");
    printjis(union_occurences, union_occurences_size);

    
}