#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ** strings = NULL, input[128];
    int count = 0, length, i;

    do {
        // Saisie
        printf("#%02d : ", count + 1);
        gets(input);
        length = strlen(input);
        
        // Ajout d'une chaine
        if (length != 0) {
            count++;
            
            // Réallocation pour ajouter un pointeur
            strings = (char **) realloc(strings, count * sizeof(char *));
            if (strings != NULL) {
                // Allocation pour la nouvelle chaîne
                // Ne pas oublier le \0
                //*(strings + count - 1) = (char *) malloc((length + 1) * sizeof(char));
                strings[count - 1] = (char *) malloc((length + 1) * sizeof(char));
                // Copie dans le tas
                //if (*(strings + count - 1) != NULL) {
                if (strings[count - 1] != NULL) {
                    //strcpy(*(strings + count - 1), input);
                    strcpy(strings[count - 1], input);
                }
            }
        }
        // Fin de la saisie et affichage
        else {
            printf("\nValeurs saisies :\n");
            for (i = 0; i < count; i++) {
                printf("#%02d : %s\n", i, *(strings + i));
            }
        }
    } while(length != 0 && strings != NULL && *(strings + count - 1) != NULL);

    // Libération
    for (i = 0; i < count; i++) {
        free(*(strings + i));
    }
    free(strings);

    return 0;
}