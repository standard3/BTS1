#include <stdio.h>

void sauvegarder_score(int*, int*);
void charger_score(int*, int*);

/**
 * Sauvegarde des tableaux scores et totaux dans le fichier "yahtzee.sav"
 * @param scores tableau de 19 entiers contenant tous les scores
 * @param totaux tableau de 6 entiers contenant tous les totaux
 * */
void sauvegarder_score(int * scores, int * totaux)
{
    FILE * fichier;
    fichier = fopen("./yahtzee.sav", "w");

    // Écrit score[] dans fichier
    for (int i = 0; i < 19; i++)
        fprintf(fichier, "%d\n", scores[i]);

    // Écrit totaux[] dans fichier
    for (int i = 0; i < 6; i++)
        fprintf(fichier, "%d\n", totaux[i]);

    fclose(fichier);
}

/**
 * Charge les tableaux scores et totaux d'après les données
 * contenues dans le fichier "yahtzee.sav"
 * @param scores tableau de 19 entiers contenant tous les scores
 * @param totaux tableau de 6 entiers contenant tous les totaux
 * */
void charger_score(int * scores, int * totaux)
{
    FILE * fichier;
    fichier = fopen("./yahtzee.sav", "r");

    char temp[25];

    if (fichier != NULL)
    {
        for (int i = 0; EOF != fscanf(fichier, "%3[^\n]\n", temp); i++)
        {
            if (i <= 19)
                scores[i] = atoi(temp);
            else
                totaux[i] = atoi(temp);
        }   
    }

    fclose(fichier);
}