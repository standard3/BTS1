#include <stdio.h>
#include <stdlib.h>

#define TAILLE 10

int main()
{
    system("chcp 65001");

    int tableau[TAILLE];
    int nbrPairs[TAILLE];
    int nbrImpairs[TAILLE];
    int compteurPair = 0;
    int compteurImpair = 0;
    int choix;
    
    // Saisie 10 entiers
    for (int i = 0; i < TAILLE; i++)
    {
        system("cls");
        printf("Saisir valeur N°%d: ", i + 1);
        scanf("%d", &tableau[i]);
    }

    system("cls");
    printf("Mode à choisir :\n1. Tableau\n2. Pointeur\n");
    scanf("%d", &choix);

    if (choix == 1)
    {
        system("cls");
        for (int i = 0; i < TAILLE; i++)
        {
            if ((tableau[i] % 2) == 0) // Si pair
            {
                nbrPairs[compteurPair] = tableau[i];
                compteurPair++;
            }
            else
            {
                nbrImpairs[compteurImpair] = tableau[i];
                compteurImpair++;
            }
        }
        
        printf("Tableau nombres pairs : ");
        for (int i = 0; i < compteurPair; i++)
        {
            printf("[%d] ", nbrPairs[i]);
        }

        printf("\nTableau nombres impairs : ");
        for (int i = 0; i < compteurImpair; i++)
        {
            printf("[%d] ", nbrImpairs[i]);
        }
    }
    else
    {
        system("cls");
        for (int i = 0; i < TAILLE; i++)
        {
            if (*(tableau + i) % 2 == 0) // Si pair
            {
                *(nbrPairs + compteurPair) = *(tableau + i);
                compteurPair++;
            }
            else
            {
                *(nbrImpairs + compteurImpair) = *(tableau + i);
                compteurImpair++;
            }
        }

        printf("Tableau nombres pairs : ");
        for (int i = 0; i < compteurPair; i++)
        {
            printf("[%d] ", *(nbrPairs + i));
        }

        printf("\nTableau nombres impairs : ");
        for (int i = 0; i < compteurImpair; i++)
        {
            printf("[%d] ", *(nbrImpairs + i));
        }
    }

    return 0;
}