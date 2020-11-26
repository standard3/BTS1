#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* TODO
*   - Régler le soucis de buffer sans utiliser la fonction ViderBuffer()
*   - Faire le calcul de la section inférieure
*   - Réfléchir à un meilleur moyen de calculer le score (plus efficient)
*   - Faire un array / enum pour totaux des scores 
*   - Améliorer design du tableau des scores & design global
*   - Améliorer lisibilité du code (voir pour prototyper les fonctions)
*/

int nb_des_selectionnes = 0;
int nb_des_lances;
int nb_tours = 0;
int de_selectionne;

int tableau_des_lances[5];
int tableau_des_selectionnes[5];

/* Hardcode des totaux des scores */
int totalAs = 0, totalDeux = 0, totalTrois = 0, totalQuatre = 0, totalCinq = 0, totalSix = 0, totalSectionSuperieure = 0;
int totalBrelan = 0, totalCarre = 0, totalFull = 0, totalPetiteSuite = 0, totalGrandeSuite = 0, totalYahtzee = 0, totalChance = 0, totalPrimeYahtzee = 0, totalSectionInferieure = 0;
int totalGeneral = 0;

void ViderBuffer() { for(int c = 0; c!='\n' && c!=EOF; c = getchar()); }

void NouvelleFenetre()
{
    system("cls");
}

void Tirage()
{
    printf("Tirage : ");
    for (int i = 0; i <= 4; i++)
    {
        printf("[%d] ", tableau_des_lances[i]);
    }

    printf("\n   Dés : ");
    for (int i = 0; i <= 4; i++)
    {
        printf("[%d] ", tableau_des_selectionnes[i]);
    }

    printf("\n");
}

void SelectionDes()
{
    if (nb_tours <= 3)
    {
        printf("Saisir les numéros des dés à conserver (1-5, 0 pour arrêter):\n");
        do
        {
            scanf("%d", &de_selectionne);
            if (de_selectionne >= 1 || de_selectionne <= 5) // Vérifier qu'on saisie de bonnes valeurs pour de_selectionne
            {
                if (tableau_des_lances[de_selectionne - 1] != 0)
                {
                    tableau_des_selectionnes[nb_des_selectionnes] = tableau_des_lances[de_selectionne - 1];
                    tableau_des_lances[de_selectionne - 1] = 0;
                    nb_des_selectionnes++;
                }
            }
            else
            {
                printf("Mauvaise saisie ! Veuillez réessayer.");
            }
        } while (de_selectionne != 0);
    }
}

void CalculScore(int ligne)
{
    // Calculs basés d'après http://fr.wikipedia.org/wiki/Yahtzee
    switch (ligne)
    {
    case 1: // As
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 1) {totalAs++;}
        }
        break;

    case 2: // Deux
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 2) {totalDeux++;}
        }
        totalDeux *= 2;
        break;

    case 3: // Trois
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 3) {totalTrois++;}
        }
        totalTrois *= 2;
        break;

    case 4: // Quatre
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 4) {totalQuatre++;}
        }
        totalQuatre *= 4;
        break;

    case 5: // Cinq
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 5) {totalCinq++;}
        }
        totalDeux *= 5;
        break;

    case 6: // Six
        for (int i = 0; i < 5; i++)
        {
            if (tableau_des_selectionnes[i] == 6) {totalSix++;}
        }
        totalSix *= 6;
        break;

    default:
        printf("Mauvaise saisie ! Veuillez réessayer.");
        break; // <- À voir si ça ne casse pas le switch
    }

    totalSectionSuperieure += totalAs + totalDeux + totalTrois + totalQuatre + totalCinq + totalSix;
    totalSectionInferieure += totalBrelan + totalCarre + totalFull + totalPetiteSuite + totalGrandeSuite + totalYahtzee + totalChance + totalPrimeYahtzee;
}

void AfficheScore()
{
    printf("   ┌────────────────────────────────────────┐\n");
    printf("   │ Section supérieure                     │\n");
    printf("   ├────────────────────────────────┬───────┤\n");
    printf(" 1 │                   Total des AS │  %3d  │\n", totalAs);
    printf(" 2 │                 Total des DEUX │  %3d  │\n", totalDeux);
    printf(" 3 │                Total des TROIS │  %3d  │\n", totalTrois);
    printf(" 4 │               Total des QUATRE │  %3d  │\n", totalQuatre);
    printf(" 5 │                 Total des CINQ │  %3d  │\n", totalCinq);
    printf(" 6 │                  Total des SIX │  %3d  │\n", totalSix);
    printf("   │                          Total │  %3d  │\n", totalSectionSuperieure);
    if (totalSectionSuperieure >= 63) {totalSectionSuperieure += 35;} // Bonus
    printf("   │ 63+        Prime des 35 points │  %3d  │\n", totalSectionSuperieure);
    printf("   │ Total de la section supérieure │  %3d  │\n", totalSectionSuperieure);
    printf("   ├────────────────────────────────┴───────┤\n");
    printf("   │ Section inférieure                     │\n");
    printf("   ├────────────────────────────────┬───────┤\n");
    printf(" 7 │ Brelan         Total des 5 dés │  %3d  │\n", totalBrelan);
    printf(" 8 │ Carré          Total des 5 dés │  %3d  │\n", totalCarre);
    printf(" 9 │ Full                 25 points │  %3d  │\n", totalFull);
    printf("10 │ Petite suite         30 points │  %3d  │\n", totalPetiteSuite);
    printf("11 │ Grande suite         40 points │  %3d  │\n", totalGrandeSuite);
    printf("12 │ Yahtzee              50 points │  %3d  │\n", totalYahtzee);
    printf("13 │ Chance         Total des 5 dés │  %3d  │\n", totalChance);
    printf("14 │ Prime Yahtzee       100 points │  %3d  │\n", totalPrimeYahtzee);
    printf("   │ Total de la section inférieure │  %3d  │\n", totalSectionInferieure);
    printf("   │ Total de la section supérieure │  %3d  │\n", totalSectionSuperieure);
    printf("   ├────────────────────────────────┼───────┤\n");
    printf("   │ Total général                  │  %3d  │\n", totalGeneral);
    printf("   └────────────────────────────────┴───────┘\n");
}

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
        {
            tableau_des_lances[i] = (rand() % 6) + 1;
        }

        for (int i = 0; i < nb_des_selectionnes - 1; i++)
        {
            tableau_des_lances[nb_des_lances + i] = tableau_des_selectionnes[i];
        }

        Tirage();
        SelectionDes();
        
    } while (nb_des_selectionnes != 5 && nb_tours < 3);
    
    NouvelleFenetre();
    //AfficheScore();

    // Choix de la case ou barrer
    ViderBuffer();
    int choixBarrer;
    printf("Souhaitez-vous barrer une case ? (1-14)(0 pour passer)\n");
    scanf("%c", &choixBarrer);
    CalculScore(choixBarrer);
    //NouvelleFenetre();
    //AfficheScore();
    
    return 0;
}