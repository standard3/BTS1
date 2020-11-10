#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("chcp 65001");

    // Nombre de jours par mois
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    char input[6];
    int day, month, i, daysCount;
    
    // Saisie
    printf("Saisir une date : ");
    gets(input);
    sscanf(input, "%d/%d", &day, &month);
    
    // Calcul
    // On ajoute le nombre de jour des mois précédents
    daysCount = day;
    for (i = 0; i < month - 1; i++) {
        daysCount += daysInMonths[i];
    }

    // Affichage
    printf("C'est le %d%s jour de l'année !", daysCount, daysCount == 1 ? "er" : "ème");

    return 0;
}