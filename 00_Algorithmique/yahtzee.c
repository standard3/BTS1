#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* TODO :
*   - Régler le bug : on peut sélectionner plusieurs fois le même dé
*
*/

int main()
{
    system("chcp 65001");   // Autorise l'unicode
    srand(time(0));

    int nb_des_selectionnes = 0;
    int nb_des_lances;
    int nb_tours = 0;
    int de_selectionne;

    int tableau_des_lances[5];
    int tableau_des_selectionnes[5];

    do
    {

        // Nouvelle fenêtre
        system("cls");

        nb_tours++;
        printf("Tour n°%d\n", nb_tours);

        nb_des_lances = 5 - nb_des_selectionnes;

        for (int i = 0; i <= nb_des_lances - 1; i++)
        {
            tableau_des_lances[i] = (rand() % 6) + 1;
        }

        for (int i = 0; i < nb_des_selectionnes - 1; i++)
        {
            tableau_des_lances[nb_des_lances + i] = tableau_des_selectionnes[i];
        }

        // Affiche le tirage 
        printf("Tirage : ");
        for (int i = 0; i <= 4; i++)
        {
            if (i <= 3)
            {
                printf("%d, ", tableau_des_lances[i]);
            }
            else
            {
                printf("%d\n", tableau_des_lances[i]);
            }
        }

        // Selection des dés à conserver 
        if (nb_tours < 3)
        {
            printf("Saisir les numéros des dés à conserver (1-5, 0 pour arrêter): ");
            do
            {
                scanf("%d", &de_selectionne);
                if (de_selectionne > 1 || de_selectionne < 5) // Vérifier qu'on saisie de bonnes valeurs pour de_selectionne
                {
                    if (de_selectionne != 0)
                    {
                        tableau_des_selectionnes[nb_des_selectionnes] = tableau_des_lances[de_selectionne - 1];
                        nb_des_selectionnes++;
                    }
                }
                else
                {
                    printf("Mauvaise saisie ! Veuillez réessayer.");
                }
            } while (de_selectionne != 0);
        }
        
    } while (nb_des_selectionnes != 5 && nb_tours < 3);
    
    // Choix de la case ou barrer
    printf("Souhaitez-vous barrer une ");
    
    // Calcul du score à partir de tableau_des_lances[]
    return 0;
}