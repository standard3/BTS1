#include <stdio.h>
#include <stdlib.h>

int main() {
    int max, i;
    float somme = 0, note;

    system("chcp 65001"); // Passe l'encodage de la console en UTF8
    
    do {
        printf("Nombre de notes :\n> ");
        scanf("%d", &max);
    }
    while (max < 0);

    for (i = 1; i <= max; i++) {
        do {
            printf("Note %d : ", i);
            scanf("%f", &note);
        }
        while (note < 0 || note > 20);
        somme += note;
    }

    printf("Moyennes des notes : %.2f", somme / max);

    return 0;
}