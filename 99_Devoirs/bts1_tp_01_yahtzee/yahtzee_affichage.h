#include <stdio.h>
#include <stdlib.h>

void afficher_titre();
void afficher_tirage(int, int *, int, int *);
void afficher_tirage_final(int *);
void afficher_carte(int *, int *);

/**
 * Affiche le titre du jeu dans un style très... nineties :)
 * */
void afficher_titre() {
    system("cls");
    printf("__  __      __    __                \n");
    printf("\\ \\/ /___ _/ /_  / /_____  ___  ___ \n");
    printf(" \\  / __ `/ __ \\/ __/_  / / _ \\/ _ \\\n");
    printf(" / / /_/ / / / / /_  / /_/  __/  __/\n");
    printf("/_/\\__,_/_/ /_/\\__/ /___/\\___/\\___/ \n\n");                         
}

/**
 * Affiche l'IHM de choix des dés
 * @param nb_tirages le nombre de lancers effectués pendant ce tour/tirage
 * @param tableau_des_lances un tableau de 5 entiers (1-6) contenant le résultat du tirage aléatoire
 * @param nb_des_selectionnes le nombre de dés conservés jusqu'ici
 * @param tableau_des_selectionnes un tableau de 5 entiers (1-6) contenant les dés conservés
 * */
void afficher_tirage(int nb_tirages, int * tableau_des_lances, int nb_des_selectionnes, int * tableau_des_selectionnes) {
    int i;
    afficher_titre();
    printf("Tirage #%d : ", nb_tirages);
    for (i = 0; i < 5; i++) {
        if (tableau_des_lances[i] == 0) {
            printf("[ ] ");
        }
        else {
            printf("[%d] ", tableau_des_lances[i]);
        }
    }
    printf("\n      Dés :  1   2   3   4   5    (0 : tout)\n    Choix : ");
    for (i = 0; i < nb_des_selectionnes; i++) {
        printf("[%d] ", tableau_des_selectionnes[i]);
    }
    for (i = nb_des_selectionnes; i < 5; i++) {
        printf("[ ] ");
    }
}

/**
 * Affiche les valeurs des dés
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * */
void afficher_tirage_final(int * des) {
    int i;
    afficher_titre();
    printf("  Résultat : ");
    for (i = 0; i < 5; i++) {
        printf("[%d] ", des[i]);
    }
    printf("\n");
}

/**
 * Affiche la carte de Yahtzee avec les scores
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne
 * @param totaux un tableau de 6 entiers pour stocker les totaux
 * */
void afficher_carte(int * scores, int * totaux) {
    char texte[4] = ""; 
    printf("┌────┬────────────────────────────┐\n");
    printf("│    │     SECTION SUPERIEURE     │\n");
    printf("│    ├──────────────────────┬─────┤\n");
    sprintf(texte, "%3d", scores[0]);
    printf("│ %s │         Total des AS │ %s │\n", scores[0] > -1 ? "  " : " 1", scores[0] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[1]);
    printf("│ %s │       Total des DEUX │ %s │\n", scores[1] > -1 ? "  " : " 2", scores[1] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[2]);
    printf("│ %s │      Total des TROIS │ %s │\n", scores[2] > -1 ? "  " : " 3", scores[2] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[3]);
    printf("│ %s │     Total des QUATRE │ %s │\n", scores[3] > -1 ? "  " : " 4", scores[3] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[4]);
    printf("│ %s │       Total des CINQ │ %s │\n", scores[4] > -1 ? "  " : " 5", scores[4] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[5]);
    printf("│ %s │        Total des SIX │ %s │\n", scores[5] > -1 ? "  " : " 6", scores[5] == -1 ? "   " : texte);
    printf("│    ├──────────────────────┼─────┤\n");
    printf("│    │           Sous-total │ %3d │\n", totaux[0]);
    printf("│    │ 63+  Prime des 35pts │ %3d │\n", totaux[1]);
    printf("│    │        TOTAL SECTION │ %3d │\n", totaux[2]);
    printf("│    ├──────────────────────┼─────┤\n");
    printf("│    │     SECTION INFERIEURE     │\n");
    printf("│    ├──────────────────────┬─────┤\n");
    sprintf(texte, "%3d", scores[6]);
    printf("│ %s │ Brelan         Total │ %s │\n", scores[6] > -1 ? "  " : " 7", scores[6] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[7]);
    printf("│ %s │ Carré          Total │ %s │\n", scores[7] > -1 ? "  " : " 8", scores[7] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[8]);
    printf("│ %s │ Full              25 │ %s │\n", scores[8] > -1 ? "  " : " 9", scores[8] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[9]);
    printf("│ %s │ Petite suite      30 │ %s │\n", scores[9] > -1 ? "  " : "10", scores[9] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[10]);
    printf("│ %s │ Grande suite      40 │ %s │\n", scores[10] > -1 ? "  " : "11", scores[10] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[11]);
    printf("│ %s │ Yahtzee           50 │ %s │\n", scores[11] > -1 ? "  " : "12", scores[11] == -1 ? "   " : texte);
    sprintf(texte, "%3d", scores[12]);
    printf("│ %s │ Chance         Total │ %s │\n", scores[12] > -1 ? "  " : "13", scores[12] == -1 ? "   " : texte);
    printf("│    ├──────────────────────┼─────┤\n");
    printf("│    │ Prime Yahtzee    100 │ %3d │\n", totaux[3]);
    printf("│    │        TOTAL SECTION │ %3d │\n", totaux[4]);
    printf("│    ├──────────────────────┼─────┤\n");
    printf("│    │        TOTAL GENERAL │ %3d │\n", totaux[5]);
    printf("└────┴──────────────────────┴─────┘\n");
}