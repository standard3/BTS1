#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char * chaine;

    chaine = (char *) malloc(25 * sizeof(char));
    //chaine = (char *) calloc(25, sizeof(char));
    //chaine = (char *) realloc(chaine, 25 * sizeof(char));

    if (chaine != NULL) {
        strcpy(chaine, "J'aime la programmation!");
        puts(chaine);
        free(chaine);
    }

    return 0;
}