#include <stdio.h>
#include <stdlib.h>

int main() {
    int * entiers = NULL, * courant, taille = 0, i;
    char input[10];

    do {
        // Saisie
        printf("#%02d : ", taille + 1);
        gets(input);

        // Si la saisie n'est pas vide
        if (*input != '\0') {

            // Augmentation de la taille du tableau
            taille++;
            entiers = (int *) realloc(entiers, taille * sizeof(int));
            if (entiers != NULL) {
                sscanf(input, "%d", entiers + (taille - 1));
            }

        }
        else {

            // Affichage
            printf("\n[");
            for (courant = entiers; courant < entiers + taille; courant++) {
                printf(" %d%c", *(courant), courant < entiers + taille - 1 ? ',' : ' ');
            }
            printf("] (%d octet%s", taille * sizeof(int), taille > 0 ? "s)": ")");
        
        }
    } while(*input != '\0' && entiers != NULL);

    if (entiers != NULL) {
        free(entiers);
    }

    return 0;
}