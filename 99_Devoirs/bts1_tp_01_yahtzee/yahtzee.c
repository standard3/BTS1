#include <string.h>
#include <time.h>
#include <unistd.h>
#include "yahtzee_jeu.h"
#include "yahtzee_top.h"
#include "yahtzee_sauvegarde.h"

/* TODO
* Si partie non terminée, propose de reprendre le score
*/

int main() {
    // Initialisation
    int nb_tours, des[5], 
        scores[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        totaux[6] = {0, 0, 0, 0, 0, 0},
        top[5] = {-1, -1, -1, -1, -1}, place;

    srand(time(NULL));
    system("chcp 65001");

    afficher_titre();

    // Si "yahtzee.sav" existe alors proposer de reprendre
    
    if( access("./yahtzee.sav", F_OK ) == 0 ) 
    {
        char reprendre_partie;

        printf("Une sauvegarde a été trouvée. Voulez-vous reprendre la partie ? (o/n)\n");
        scanf("%c", &reprendre_partie);

        if (reprendre_partie == 'o')
        {
            charger_score(scores, totaux);
            printf("La sauvegarde a bien été restaurée.\n");
        }
    } 

    // Déroulement normal
    for (nb_tours = 1; nb_tours <= 13; nb_tours++) {
        lancer_les_des(des);
        scorer(des, scores, totaux);

        // Sauvegarde chaque tour
        sauvegarder_score(scores, totaux);
    }
    // Supprimer fichier "yahtzee.sav" car partie terminée
    remove("./yahtzee.sav");

    // Sauvegarder le top 5 des scores
    sauvegarder_top(top);
    charger_top(top);
    for (int i = 0; i < 5; i++)
        mettre_a_jour_top(top, totaux[i]);
    afficher_top(top, place);

    return 0;
}