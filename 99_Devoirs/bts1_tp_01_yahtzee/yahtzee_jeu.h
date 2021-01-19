#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define FALSE   0
#define TRUE    1

void    lancer_les_des(int *);
void    lancer_n_des(int *, int *);
void    ordonner_les_des(int *);
int     selectionner_de(int *, int *, int *);
void    garder_n_des(int *, int *, int);
void    scorer(int *, int *, int *);
int     choisir_ligne(int *);
void    calculer_score(int, int *, int *, int *);
void    calculer_score_partie_superieure(int, int *, int *, int *);
void    calculer_score_partie_inferieure(int, int *, int *, int *);
void    decompter_faces(int *, int *);
int     verifier_nombre_de_faces(int *, int);
int     verifier_suite_n_faces(int *, int);
int     additionner_des(int *);

/**
 * Simule un lancer de dés suivant les règles du Yahtzee : 3 tirages + possibilité de conserver des dés entre chaque tirage
 * @param tableau_des_lances un tableau de 5 entiers qui contiendra les 5 dés issus du lancer (mis à jour dans la fonction)
 * */
void lancer_les_des(int * tableau_des_lances) {
    int nb_des_selectionnes = 0, nb_tirages = 1, i, arreter = FALSE,
        tableau_des_selectionnes[5];
    char input[3];
    do {
        // Tirage aléatoire
        lancer_n_des(tableau_des_lances, &nb_des_selectionnes);

        // Tri des dés
        ordonner_les_des(tableau_des_lances);
        
        if (nb_tirages < 3) {
            do {
                // Affichage
                afficher_tirage(nb_tirages, tableau_des_lances, nb_des_selectionnes, tableau_des_selectionnes);

                // Sélection de dés
                arreter = selectionner_de(tableau_des_lances, tableau_des_selectionnes, &nb_des_selectionnes);
            } while (arreter != TRUE && nb_des_selectionnes != 5);
        }

        // Sauvegarde des dés sélectionnés
        garder_n_des(tableau_des_lances, tableau_des_selectionnes, nb_des_selectionnes);

        nb_tirages++;
    } while (nb_des_selectionnes != 5 && nb_tirages <= 3);
}

/**
 * Ordonne le tableau "des" en ordre croissant
 * @param des le tableau de 5 entiers à ordonner (mis à jour dans la fonction)
 * */
void ordonner_les_des(int * des) {
    int i, j, temp;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (des[j + 1] < des[j]) {
                temp = des[j];
                des[j] = des[j + 1];
                des[j + 1] = temp;
            }
        }
    }
}

/**
 * Permet à l'utilisateur de selectionner de 0 à 5 dés, 0 selectionne tous les dés, Entrée arrête la saisie
 * @param tableau_des_lances un tableau de 5 entiers (mis à jour dans la fonction)
 * @param tableau_des_selectionnes un tableau de 5 entiers (mis à jour dans la fonction)
 * @param nb_des_selectionnes le nombre de valeurs dans tableau_des_selectionnes (mis à jour dans la fonction)
 * @return 1 si l'utilisateur a appuyer sur Entrée, 0 sinon
 * */
int selectionner_de(int * tableau_des_lances, int * tableau_des_selectionnes, int * nb_des_selectionnes) {
    int i, selection = getch() - 48;
    if (selection >= 1 && selection <= 5) {
        if (tableau_des_lances[selection - 1] != 0) {
            tableau_des_selectionnes[*nb_des_selectionnes] = tableau_des_lances[selection - 1];
            tableau_des_lances[selection - 1] = 0;
            (*nb_des_selectionnes)++;
        }
    }
    if (selection == 0) {
        *nb_des_selectionnes = 5;
        for (i = 0; i < 5; i++) {
            tableau_des_selectionnes[i] = tableau_des_lances[i];
        }
    }
    return selection == -35;
}

/**
 * Tire aléatoirement (5 - nb_des_selectionnes) dés
 * @param tableau_des_lances un tableau de 5 entiers pour stocker les valeurs (mis à jour dans la fonction)
 * @param nb_des_selectionnes le nombre de dés conservés par ailleurs (mis à zéro dans la fonction)
 * */
void lancer_n_des(int * tableau_des_lances, int * nb_des_selectionnes) {
    int i;
    for (i = *nb_des_selectionnes; i < 5; i++) {
        // TO DO à décommenter :
        // tableau_des_lances[i] = rand() % 6 + 1;
        tableau_des_lances[i] = 6;
    }
    *nb_des_selectionnes = 0;
}

/**
 * Place les dés de tableau_des_selectionnes dans tableau_des_lances
 * @param tableau_des_lances un tableau de 5 entiers pour stocker les valeurs (mis à jour dans la fonction)
 * @param tableau_des_selectionnes un tableau de 5 entiers contenant les valeurs à déplacer
 * @param nb_des_selectionnes le nombre de dés à ajouter
 * */
void garder_n_des(int * tableau_des_lances, int * tableau_des_selectionnes, int nb_des_selectionnes) {
    int i;
    for (i = 0; i < nb_des_selectionnes; i++) {
        tableau_des_lances[i] = tableau_des_selectionnes[i];
    }
}

/**
 * Permet à l'utilisateur de calculer son score en fonction de son tirage de dés et de la ligne qu'il choisira sur la carte de Yahtzee
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne (mis à jour dans la fonction)
 * @param totaux un tableau de 6 entiers pour stocker les totaux (mis à jour dans la fonction)
 * */
void scorer(int * des, int * scores, int * totaux) {
    int ligne;
    ordonner_les_des(des);
    afficher_tirage_final(des);
    afficher_carte(scores, totaux);
    ligne = choisir_ligne(scores);
    calculer_score(ligne, des, scores, totaux);
    afficher_tirage_final(des);
    afficher_carte(scores, totaux);
    system("pause");
}

/**
 * Permet à l'utilisateur de choisir la ligne qu'il souhaite remplir sur la carte de Yahtzee
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne pour vérifier les lignes déjà remplies
 * */
int choisir_ligne(int * scores) {
    int ligne_selectionnee = 0;
    char input[3];
    do {
        printf("Lignes : ");
        gets(input);
        sscanf(input, "%d", &ligne_selectionnee);
    } while(ligne_selectionnee < 1 || ligne_selectionnee > 13 || scores[ligne_selectionnee - 1] != -1);
    return ligne_selectionnee;
}

/**
 * Calcule le score selon les règles du Yahtzee
 * @param ligne un entier, la ligne choisie (1-13)
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne (mis à jour dans la fonction)
 * @param totaux un tableau de 6 entiers pour stocker les totaux (mis à jour dans la fonction)
 * */
void calculer_score(int ligne, int * des, int * scores, int * totaux) {
    int i;
    // Section supérieure
    if (ligne <= 6) {
        calculer_score_partie_superieure(ligne, des, scores, totaux);
    }
    // Section inférieure
    else if (ligne >= 7) {
        calculer_score_partie_inferieure(ligne, des, scores, totaux);
    }
    totaux[5] = totaux[2] + totaux[4];
}

/**
 * Calcule d'une ligne de la partie supérieure du tableau selon les règles du Yahtzee
 * @param ligne un entier, la ligne choisie (1-13)
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne (mis à jour dans la fonction)
 * @param totaux un tableau de 6 entiers pour stocker les totaux (mis à jour dans la fonction)
 * */
void calculer_score_partie_superieure(int ligne, int * des, int * scores, int * totaux) {
    int i;
    // Initialisation à 0
    scores[ligne - 1] = 0;
    // Somme des dés dont la face correspond à la ligne
    for (i = 0; i < 5; i++) {
        if (des[i] == ligne) {
            scores[ligne - 1] += ligne;
        }
    }
    // Ajustement du total
    totaux[0] += scores[ligne - 1];
    // Ajout du bonus si + de 63
    if (totaux[0] >= 63) {
        totaux[1] = 63;
    }
    totaux[2] = totaux[0] + totaux[1];
}

/**
 * Calcule d'une ligne de la partie inférieure du tableau selon les règles du Yahtzee
 * @param ligne un entier, la ligne choisie (1-13)
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @param scores un tableau de 13 entiers pour stocker les scores de chaque ligne (mis à jour dans la fonction)
 * @param totaux un tableau de 6 entiers pour stocker les totaux (mis à jour dans la fonction)
 * */
void calculer_score_partie_inferieure(int ligne, int * des, int * scores, int * totaux) {
    int faces[6] = {0, 0, 0, 0, 0, 0};
    decompter_faces(des, faces);
    switch (ligne) {
        case 7 :
            scores[6] = verifier_nombre_de_faces(faces, 3) == 1 ? additionner_des(des) : 0;
            totaux[4] += scores[6];
            break;
        case 8 :
            scores[7] = verifier_nombre_de_faces(faces, 4) == 1 ? additionner_des(des) : 0;
            totaux[4] += scores[7];
            break;
        case 9 :
            scores[8] = verifier_nombre_de_faces(faces, 3) && verifier_nombre_de_faces(faces, 2) ? 25 : 0;
            totaux[4] += scores[8];
            break;
        case 10 :
            scores[9] = verifier_suite_n_faces(faces, 4) == 1 ? 30 : 0;
            totaux[4] += scores[9];
            break;
        case 11 :
            scores[10] = verifier_suite_n_faces(faces, 5) == 1 ? 40 : 0;
            totaux[4] += scores[10];
            break;
        case 12 :
            scores[11] = verifier_nombre_de_faces(faces, 5) == 1 ? 50 : 0;
            totaux[4] += scores[11];
            break;
        case 13 :
            scores[12] = additionner_des(des);
            totaux[4] += scores[12];
            break;
    }
    if (scores[10] == 50 && totaux[3] != 100 && verifier_nombre_de_faces(faces, 5) == 1) {
        totaux[3] = 100;
        totaux[4] += totaux[3];
    }
}

/**
 * Compte le nombre d'occurrences de chaque face d'un dé (1-6) dans le tableau de 5 dés fournis
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @param faces un tableau de 6 entiers (0-5) pour stocker les occurences de chaque face d'un dé (mis à jour dans la fonction)
 * */
void decompter_faces(int des[5], int faces[6]) {
    int i;
    for (i = 0; i < 5; i++) {
        faces[des[i] - 1]++;
    }
}

/**
 * Vérifie si une case du tableau faces contient une valeur supérieure ou égale à count
 * @param faces un tableau de 6 entiers (0-5) contenant les occurences de chaque face d'un dé
 * @param count le nombre d'occurences à vérifier
 * @return 1 si une case du tableau faces contient une valeur supérieure ou égale à count, 0 sinon
 * */
int verifier_nombre_de_faces(int * faces, int count) {
    int i, j, ok = 0;
    for (i = 0; i <= 5; i++) {
        if (faces[i] >= count) {
            ok++;
            break;
        }
    }
    return ok;
}

/**
 * Vérifie si count faces consécutives sont présentes dans le tableau faces
 * @param faces un tableau de 6 entiers (0-5) contenant les occurences de chaque face d'un dé
 * @param count le nombre de faces consécutives à vérifier
 * @return 1 si count faces consécutives sont présentes dans le tableau faces, 0 sinon
 * */
int verifier_suite_n_faces(int * faces, int count) {
    int i, ok = 0;

    for (i = 0; i <= 5; i++) {
        if (faces[i] >= 1) {
            ok++;
        }
        else if (ok < count) {
            ok = 0;
        }
    }

    return ok >= count;
}

/**
 * Additionne les valeurs des 5 dés
 * @param des un tableau de 5 entiers (1-6) contenant le résultat du tirage
 * @return le résultat de la somme des valeurs contenues dans le tableau
 * */
int additionner_des(int * des) {
    



    
    return 42;
}
