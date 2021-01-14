#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* TODO
*   - Régler le soucis de buffer sans utiliser la fonction ViderBuffer()
*   - Faire le calcul de la section inférieure
*   - Réfléchir à un meilleur moyen de calculer le score (plus efficient)
*   - Améliorer design du tableau des scores & design global
*   - Améliorer lisibilité du code (voir pour prototyper les fonctions)
*/

int nb_des_selectionnes = 0;
int nb_des_lances;
int nb_tours = 0;
int de_selectionne;

int tableau_des_lances[5];
int tableau_des_selectionnes[5];

/* Totaux des scores */
int tableauSectionSuperieure[7] = {0};
int tableauSectionInferieure[9] = {0};

void NouvelleFenetre();
void AfficheScore();
void ViderBuffer();
void CalculScore(int);

int main()
{
    system("chcp 65001");
    srand(time(0));

    do
    {
        NouvelleFenetre();
        printf("-> Tour n°%d\n", ++nb_tours);
        nb_des_lances = 5 - nb_des_selectionnes;

        // Initialise les dés aléatoirement
        for (int i = 0; i <= nb_des_lances - 1; i++)
            tableau_des_lances[i] = (rand() % 6) + 1;

        for (int i = 0; i < nb_des_selectionnes - 1; i++)
            tableau_des_lances[nb_des_lances + i] = tableau_des_selectionnes[i];
        
        // Tirage
        printf("Tirage : ");
        for (int i = 0; i <= 4; i++)
            printf("[%d] ", tableau_des_lances[i]);

        printf("\n   Dés : ");
        for (int i = 0; i <= 4; i++)
            printf("[%d] ", tableau_des_selectionnes[i]);

        printf("\n");

        // Selection des dés
        if (nb_tours <= 3)
        {
            printf("Saisir les numéros des dés à conserver (1-5, 0 pour arrêter):\n");
            do
            {
                scanf("%d", &de_selectionne);
                if (de_selectionne >= 1 && de_selectionne <= 5) // Vérifier qu'on saisie de bonnes valeurs pour de_selectionne
                {
                    if (tableau_des_lances[de_selectionne - 1] != 0)
                    {
                        tableau_des_selectionnes[nb_des_selectionnes] = tableau_des_lances[de_selectionne - 1];
                        tableau_des_lances[de_selectionne - 1] = 0;
                        nb_des_selectionnes++;
                    }
                }
                else if (de_selectionne != 0)
                {
                    printf("Mauvaise saisie ! Veuillez réessayer.\n");
                }
            } while (de_selectionne != 0);
        }
        
    } while (nb_des_selectionnes != 5 && nb_tours < 3);
    
    NouvelleFenetre();
    AfficheScore();

    // Choix de la case ou barrer
    ViderBuffer();
    int choixBarrer;
    printf("Souhaitez-vous barrer une case ? (1-14)(0 pour passer)\n");
    scanf("%d", &choixBarrer);
    CalculScore(choixBarrer);
    //NouvelleFenetre();
    AfficheScore();
    
    return 0;
}

void AfficheScore()
{
    printf(" Vos dés : [%d] [%d] [%d] [%d] [%d]\n", tableau_des_selectionnes[0], tableau_des_selectionnes[1], tableau_des_selectionnes[2], tableau_des_selectionnes[3], tableau_des_selectionnes[4]);
    printf("┌────┬────────────────────────────────────────┐\n");
    printf("│    │ Section supérieure                     │\n");
    printf("│    ├────────────────────────────────┬───────┤\n");
    printf("│ 01 │                   Total des AS │  %3d  │\n", tableauSectionSuperieure[0]);
    printf("│ 02 │                 Total des DEUX │  %3d  │\n", tableauSectionSuperieure[1]);
    printf("│ 03 │                Total des TROIS │  %3d  │\n", tableauSectionSuperieure[2]);
    printf("│ 04 │               Total des QUATRE │  %3d  │\n", tableauSectionSuperieure[3]);
    printf("│ 05 │                 Total des CINQ │  %3d  │\n", tableauSectionSuperieure[4]);
    printf("│ 06 │                  Total des SIX │  %3d  │\n", tableauSectionSuperieure[5]);
    printf("│    │                          Total │  %3d  │\n", tableauSectionSuperieure[6]);
    if (tableauSectionSuperieure[6] >= 63) {tableauSectionSuperieure[6] += 35;} // Bonus
    printf("│    │ 63+        Prime des 35 points │  %3d  │\n", tableauSectionSuperieure[6]);
    printf("│    │ Total de la section supérieure │  %3d  │\n", tableauSectionSuperieure[6]);
    printf("│    ├────────────────────────────────┴───────┤\n");
    printf("│    │ Section inférieure                     │\n");
    printf("│    ├────────────────────────────────┬───────┤\n");
    printf("│ 07 │ Brelan         Total des 5 dés │  %3d  │\n", tableauSectionInferieure[0]);
    printf("│ 08 │ Carré          Total des 5 dés │  %3d  │\n", tableauSectionInferieure[1]);
    printf("│ 09 │ Full                 25 points │  %3d  │\n", tableauSectionInferieure[2]);
    printf("│ 10 │ Petite suite         30 points │  %3d  │\n", tableauSectionInferieure[3]);
    printf("│ 11 │ Grande suite         40 points │  %3d  │\n", tableauSectionInferieure[4]);
    printf("│ 12 │ Yahtzee              50 points │  %3d  │\n", tableauSectionInferieure[5]);
    printf("│ 13 │ Chance         Total des 5 dés │  %3d  │\n", tableauSectionInferieure[6]);
    printf("│ 14 │ Prime Yahtzee       100 points │  %3d  │\n", tableauSectionInferieure[7]);
    printf("│    │ Total de la section inférieure │  %3d  │\n", tableauSectionInferieure[8]);
    printf("│    │ Total de la section supérieure │  %3d  │\n", tableauSectionSuperieure[6]);
    printf("│    ├────────────────────────────────┼───────┤\n");
    printf("│    │ Total général                  │  %3d  │\n", tableauSectionInferieure[8] + tableauSectionSuperieure[6]);
    printf("└────┴────────────────────────────────┴───────┘\n");
}

void ViderBuffer() { for (int c = 0; c !='\n' && c != EOF; c = getchar()); }

void NouvelleFenetre()
{
    system("cls");
}

void CalculScore(int ligne)
{
    // Calculs basés d'après http://fr.wikipedia.org/wiki/Yahtzee
    switch (ligne)
    {
    case 1: // As
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 1) {tableauSectionSuperieure[0]++;}
        break;

    case 2: // Deux
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 2) {tableauSectionSuperieure[1]++;}
        tableauSectionSuperieure[1] *= 2;
        break;

    case 3: // Trois
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 3) {tableauSectionSuperieure[2]++;}
        tableauSectionSuperieure[2] *= 3;
        break;

    case 4: // Quatre
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 4) {tableauSectionSuperieure[3]++;}
        tableauSectionSuperieure[3] *= 4;
        break;

    case 5: // Cinq
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 5) {tableauSectionSuperieure[4]++;}
        tableauSectionSuperieure[4] *= 5;
        break;

    case 6: // Six
        for (int i = 0; i < 5; i++)
            if (tableau_des_selectionnes[i] == 6) {tableauSectionSuperieure[5]++;}
        tableauSectionSuperieure[5] *= 6;
        break;

    case 7: // Brelan
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] >= 3) 
                tableauSectionInferieure[0] += (i + 1) * tableau_des_selectionnes[i];
        }
        break;
    
    case 8: // Carré
        for (int i = 0; i < 5; ++i)
        {
            if (tableau_des_selectionnes[i] >= 4)
                tableauSectionInferieure[1] += (i + 1) * tableau_des_selectionnes[i];
        }
        break;
    
    case 9: // Full
    /*
        int compteur = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (tableau_des_selectionnes[i] == 5)
            {
                tableauSectionInferieure[2] += 25;
            }
            else
            {
                compteur += tableau_des_selectionnes[i];
            }
        }
        compteur == 5 ? 25 : 0;
        break;
    */
    case 10: // Petite suite
        if (tableau_des_selectionnes[1] && tableau_des_selectionnes[2])
        {
            if ((tableau_des_selectionnes[0] && tableau_des_selectionnes[1]) || (tableau_des_selectionnes[1] && tableau_des_selectionnes[3]) || (tableau_des_selectionnes[3] && tableau_des_selectionnes[4]))
            {
                tableauSectionInferieure[3] += 30;
            }
        }
        break;

    case 11: // Grande suite
    /*
        if (1)
        {
            tableauSectionInferieure[4] += 40;
        }
        break;
    */
    case 12: // Yahtzee
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 5)
            {
                tableauSectionInferieure[5] += 50;
            }
        }
        break;

    case 13: // Chance
        for (int i = 0; i < 5; i++)
        {
            tableauSectionInferieure[6] += tableau_des_selectionnes[i];
        }
        break;

    case 14: // Prime Yahtzee
        for (int i = 0; i < 5; i++)
        {
            
        }
        break;

    default:
        printf("Mauvaise saisie ! Veuillez réessayer.\n");
        break; // <- À voir si ça ne casse pas le switch
    }

    tableauSectionSuperieure[6] += tableauSectionSuperieure[0] + tableauSectionSuperieure[1] + tableauSectionSuperieure[2] + tableauSectionSuperieure[3] + tableauSectionSuperieure[3] + tableauSectionSuperieure[5];
    tableauSectionInferieure[8] += tableauSectionInferieure[0] + tableauSectionInferieure[1] + tableauSectionInferieure[2] + tableauSectionInferieure[3] + tableauSectionInferieure[4] + tableauSectionInferieure[5] + tableauSectionInferieure[6] + tableauSectionInferieure[7];
}

int isSuite()
{
    int tableau_face[6];
    

}