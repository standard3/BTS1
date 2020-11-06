#include <stdio.h>

int main()
{
    int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jour, mois;
    int resultat;

    printf("Saisir une date (JJ/MM): ");
    scanf("%d/%d", &jour, &mois);

    // Additionner tous les jours jusqu'à date et retourner résultat
    for (int i = 0; i < mois - 1; i++)
    {
        resultat += date[i];
    }
    resultat += jour;

    if (resultat == 1)
    {
        printf("C'est le premier jour de l'annee !", resultat);
    }
    else
    {
        printf("C'est le %deme jour de l'annee !", resultat);
    }

    return 0;
}