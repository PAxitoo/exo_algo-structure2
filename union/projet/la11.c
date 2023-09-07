#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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

int (*find_occu(const char *tab, int tab_size, int *occurrences_size))[2] {
    *occurrences_size = 0;
    int (*occurrences)[2] = malloc(tab_size * sizeof(*occurrences));

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
                    occurrences[*occurrences_size][0] = i;
                    occurrences[*occurrences_size][1] = j;
                    (*occurrences_size)++;
                }
            }
        }
    }

    return occurrences;
}

void print_occurrences(int (*occurrences)[2], int occurrences_size) {
    for (int i = 0; i < occurrences_size; i++) {
        printf("%d %d\n", occurrences[i][0], occurrences[i][1]);
    }
}

void free_occurrences(int (*occurrences)[2]) {
    free(occurrences);
}

int main() {
    int tab_size = 2000000; // Modifiez cette valeur pour tester des tableaux de différentes tailles
    char *table = malloc(tab_size * sizeof(char));
    int occurrences_size;
    char alphabet[] = "DGHO";

    gentable(table, tab_size, alphabet, strlen(alphabet));

    printf("Tableau : ");
    printtable(table, tab_size);

    int (*occurrences)[2] = find_occu(table, tab_size, &occurrences_size);
    printf("Occurrences du motif DG+HO* :\n");
    print_occurrences(occurrences, occurrences_size);

    free_occurrences(occurrences);
    free(table);

    return 0;
}
