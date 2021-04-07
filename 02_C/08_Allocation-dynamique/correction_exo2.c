#include <stdio.h>
#include <stdlib.h>

int main() {
    float * reels;
    int taille, i;
    char input[10];

    // Saisie de la taille
    do {
        printf("Taille du tableau : ");
        gets(input);
        sscanf(input, "%d", &taille);
    } while (taille <= 0 || taille > 100); 
    // Limite à 100 pour éviter les débordements.

    // Allocation dynamique
    reels = (float *) malloc(taille * sizeof(float));

    if (reels != NULL) {
        // Saisie des éléments
        for (i = 0; i < taille; i++) {
            printf("Element #%02d : ", i + 1);
            gets(input);
            sscanf(input, "%f", reels + i);
            //sscanf(input, "%f", &(reels[i]));
        }

        // Affichage des éléments
        puts("\nValeurs saisies :");
        for (i = 0; i < taille; i++) {
            printf("Element #%02d : %.3f\n", i + 1, *(reels + i));
            //printf("Element #%02d : %.3f", i + 1, reels[i]);
        }

        // Libération de la mémoire
        free(reels);
    }

    return 0;
}