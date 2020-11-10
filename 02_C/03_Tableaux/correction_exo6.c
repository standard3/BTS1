#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("chcp 65001");

    // Nombre de jours par mois
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    char input[11];
    int day, month, year, i, daysCount;
    
    // Saisie
    printf("Saisir une date : ");
    gets(input);
    sscanf(input, "%d/%d/%d", &day, &month, &year);
    
    // Calcul
    // Est-ce une année bissextile ? 
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        daysInMonths[1]++;
    }
    daysCount = day;
    for (i = 0; i < month - 1; i++) {
        daysCount += daysInMonths[i];
    }

    // Affichage
    printf("C'est le %d%s jour de l'année !", daysCount, daysCount == 1 ? "er" : "ème");

    return 0;
}