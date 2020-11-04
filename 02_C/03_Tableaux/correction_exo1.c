#include <stdio.h>

#define TAILLE 5

int main() {
    int i;
    int valeurs[TAILLE];
    for (i = 0; i < TAILLE; i++) {
        printf("Saisir un entier : ");
        scanf("%d", &valeurs[i]);
    }
    
    printf("AXEL : Les entiers sont ");
    for (i = 0; i < TAILLE - 1; i++) {
        printf("%d, ", valeurs[i]);
    }
    printf("%d", valeurs[TAILLE - 1]);


    printf("\nTHEO : Les entiers sont ");
    for (i = 0; i < TAILLE; i++) {
        if (i == TAILLE - 1) {
            printf("%d", valeurs[i]);
        }
        else {
            printf("%d, ", valeurs[i]);
        }
    }

    printf("\nPROF : Les entiers sont ");
    for (i = 0; i < TAILLE; i++) {
        printf("%d%s", valeurs[i], i < TAILLE - 1 ? ", " : "");
    }

    return 0;
}