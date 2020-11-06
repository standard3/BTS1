#include <stdio.h>

#define TRUE 1
#define FALSE 0

int estBissextile(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jour, mois, annee;
    int resultat;

    printf("Saisir une date (JJ/MM/AAAA): ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    // Additionner mois
    for (int i = 0; i < mois - 1; i++)
    {
        resultat += date[i];
    }

    // Additionner jours
    resultat += jour;

    // Est-ce une année bissextile ?
    if (estBissextile(annee))
    {
        resultat += 1;
    }

    // Si premier jour, sinon
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