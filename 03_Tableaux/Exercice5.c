#include <stdio.h>

int main()
{
    int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jour, mois;

    printf("Saisir une date : ");
    scanf("%d/%d", &jour, &mois);

    // Additionner tous les jours jusqu'à date et retourner résultat
    for (int i = 0; i < date[mois]; i++)
    {
        
    }

    //printf("C'est le %deme jour de l'annee !", resultat);

    return 0;
}