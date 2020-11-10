#include <stdio.h>

#define TAILLE_A 4
#define TAILLE_B 3

int main() {

    int a[TAILLE_A], b[TAILLE_B], c[TAILLE_A + TAILLE_B], i;

    // Remplissage
    printf("Premier tableau [%d] : ", TAILLE_A);
    for (i = 0; i < TAILLE_A; i++) {
        a[i] = i + 1;
        printf("%d%s", a[i], i < TAILLE_A - 1 ? ", " : "");
    }

    // Remplissage
    printf("\nDeuxième tableau [%d] : ", TAILLE_B);
    for (i = 0; i < TAILLE_B; i++) {
        b[i] = TAILLE_A + 1 + i;
        printf("%d%s", b[i], i < TAILLE_B - 1 ? ", " : "");
    }

    // Fusion !
    printf("\nTableau fusionné [%d] : ", TAILLE_A + TAILLE_B);
    for (i = 0; i < TAILLE_A + TAILLE_B; i++) {
        if (i < TAILLE_A) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i - TAILLE_A];
        }
    }

    // Affichage
    for (i = 0; i < TAILLE_A + TAILLE_B; i++) {
        printf("%d%s", c[i], i < TAILLE_A + TAILLE_B - 1 ? ", " : "");
    }


    return 0;
}