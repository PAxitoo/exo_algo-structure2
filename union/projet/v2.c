#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE_TABLEAU 200

void generer_tableau_aleatoire(char *tableau, const char *alphabet) {
    int longueur_alphabet = strlen(alphabet);
    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        tableau[i] = alphabet[rand() % longueur_alphabet];
    }
}

void find_occu(char tab[], int tab_size, int jis[TAILLE_TABLEAU][2], int *taille) {
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

void find_occu2(char tab[], int tab_size, int jis[TAILLE_TABLEAU][2], int *taille) {
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

int main() {
    srand(time(NULL));
    const char *alphabet = "DGHO";
    char tableau[TAILLE_TABLEAU + 1] = {0};
    generer_tableau_aleatoire(tableau, alphabet);
    printf("Tableau: %s\n", tableau);

    int jis[TAILLE_TABLEAU][2] = {0};
    int taille = 0;

    find_occu(tableau, TAILLE_TABLEAU, jis, &taille);
    find_occu2(tableau, TAILLE_TABLEAU, jis, &taille);

    printf("Occurrences trouvées: %d\n", taille);

    for (int i = 0; i < taille; i++) {
        printf("Occurrence %d: Index de début %d, Index de fin %d\n", i + 1, jis[i][0], jis[i][1]);
    }

    return 0;
}
