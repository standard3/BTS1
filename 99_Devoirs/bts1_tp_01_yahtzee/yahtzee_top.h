#include "stdio.h"
#include "stdlib.h"

void sauvegarder_top(int*);
void charger_top(int*);
void afficher_top(int*, int);
int mettre_a_jour_top(int*, int);

/* 
int main()
{
    //int top[5] = {-1, -1, -1, -1, -1};
    int top[5] = {132, 100, 45, -1, -1};

    sauvegarder_top(top);
    charger_top(top);
    mettre_a_jour_top(top, 150);
    afficher_top(top, -1);

    return 0;
}
*/

/**
 * Sauvegarde le tableau fourni en paramètres dans le fichier "yahtzee.top"
 * @param top un tableau de 5 entiers pour stocker les valeurs
 * */
void sauvegarder_top(int * top)
{
    FILE * fichier;
    fichier = fopen("./yahtzee.top", "w");

    for (int i = 0; i < 5; i++)
        fprintf(fichier, "%d\n", top[i]);

    fclose(fichier);
}

/**
 * Rempli le tableau fourni en paramètres d'après les valeurs contenues
 * dans le fichier "yahtzee.top"
 * @param top un tableau de 5 entiers pour stocker les valeurs
 * */
void charger_top(int * top)
{
    FILE * fichier;
    fichier = fopen("./yahtzee.top", "r");

    char temp[5];
    int i = 0;

    if (fichier != NULL)
    {
        while (EOF != fscanf(fichier, "%3[^\n]\n", temp)) // Score ne peut dépasser 390
        {
            top[i] = atoi(temp);
            i++;
        }
    }

    fclose(fichier);
}

/**
 * Affiche le top 5 des scores d'après le tableau fourni en paramètres
 * @param top un tableau de 5 entiers pour stocker les valeurs
 * @param place entier qui indique la place à laquelle le joueur se trouve
 * */
void afficher_top(int * top, int place)
{
    printf("-= Top 5 des scores =-\n\n");

    for (int i = 0; i < 5; i++)
    {
        if (top[i] == -1 || top[i] == 0)
            printf("%d.\n", i + 1);
        else if (i == place)
            printf("%d. %3d < Vous !\n", i + 1, top[i]);
        else
            printf("%d. %3d\n", i + 1, top[i]);
    }
}

/**
 * Met à jour le tableau fourni en paramètres en insérant le score
 * à la bonne place, retourne l'index auquel le score à été inséré
 * @param top un tableau de 5 entiers pour stocker les valeurs
 * @param score entier du score à insérer dans le tableau
 * */
int mettre_a_jour_top(int* top, int score)
{
    // TODO
    // Régler le fait qu'on insère forcément la valeur dans
    // le tableau, ça ne devrait pas être le cas
    // Le cas échéant, faire retourner -1

    if (score < top[5])
    {
        return -1;
    }
    else
    {
        top[4] = score;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (top[j] < top[j + 1])
                {
                    int temp = top[j];
                    top[j] = top[j + 1];
                    top[j + 1] = temp;
                }
            }
        }

        // Trouve l'index auquel score se trouve
        int index;
        for (int i = 0; i < 5; i++)
            if (top[i] == score) { index = i; }

        return index;
    }
}