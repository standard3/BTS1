#include <string.h>
#include <time.h>
#include "yahtzee_jeu.h"

int main() {
    int nb_tours, des[5], 
        scores[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        totaux[6] = {0, 0, 0, 0, 0, 0},
        top[5] = {-1, -1, -1, -1, -1}, place;

    srand(time(NULL));
    system("chcp 65001");

    afficher_titre();

    for (nb_tours = 1; nb_tours <= 13; nb_tours++) {
        lancer_les_des(des);
        scorer(des, scores, totaux);
    }
    
    return 0;
}