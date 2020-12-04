#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

int main()
{
    system("chcp 65001");
    srand(time(0));

    int tableau[TAILLE];
    int resultat[2];
    int choix;
    
    for (int i = 0; i < TAILLE; i++ )
    {
        tableau[i] = (rand() % 100) + 1;
    }
    
    system("cls");
    printf("Mode à choisir :\n1. Tableau\n2. Pointeur\n");
    scanf("%d", &choix);

    if (choix == 1)
    {
        int upper = tableau[0];
        int lower = tableau[0];

        for (int i = 0; i < TAILLE; i++)
        {
            if (tableau[i] > upper) { upper = tableau[i]; }
            if (tableau[i] < lower) { lower = tableau[i]; }
        }

        resultat[0] = upper;
        resultat[1] = lower;

        for (int i = 0; i < TAILLE; i++)
        {
            if (i <= TAILLE)
            {
                printf("%d / ", tableau[i]);
            }
            else
            {
                printf("%d", tableau[i]);
            }
        }

        printf("Plus grand : %d | Plus petit : %d\n", resultat[0], resultat[1]);
    }
    else
    {
        int upper = *tableau;
        int lower = *tableau;

        for (int i = 0; i < TAILLE; i++)
        {
            if (*(tableau + i) > upper) { upper = *(tableau + i); }
            if (*(tableau + i) < lower) { lower = *(tableau + i); }
        }

        *(tableau + 0) = upper;
        *(tableau + 1) = lower;

        for (int i = 0; i < TAILLE; i++)
        {
            if (i <= TAILLE)
            {
                printf("%d / ", *(tableau + i));
            }
            else
            {
                printf("%d", *(tableau + i));
            }
        }

        printf("Plus grand : %d | Plus petit : %d\n", *(tableau + 0), *(tableau + 1));
    }
    

    return 0;
}