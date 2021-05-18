#include <stdio.h>
#include <stdlib.h>

typedef struct entier {
    int valeur;
    struct entier * suivant;
} entier;

/**
 * Crée un entier seul dans le tas
 * @param valeur La valeur de l'entier
 * @return Le pointeur vers l'entier créé
 * */
entier * entier_creer       (int valeur);
/**
 * Crée et ajoute un entier à la fin de la liste chaînée d'entiers
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @param valeur La valeur de l'entier à créer et ajouter
 * @return Un pointeur vers le premier élément de la liste
 * */
entier * entiers_ajouter    (entier * liste, int valeur);
/**
 * Compte le nombre d'éléments dans la liste chaînée
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @return Le nombre d'éléments dans la liste chaînée
 * */
int      entiers_compter    (entier * liste);
/**
 * Renvoie l'élément à l'index demandé
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @param index L'index de l'élément demandé
 * @return Un pointeur vers l'élément attendu ou NULL si l'index est hors-limites
 * */
entier * entiers_recuperer  (entier * liste, int index);
/**
 * Supprime l'élément à l'index demandé si possible
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @param index L'index de l'élément à supprimer
 * @return Un pointeur vers le premier élément de la liste
 * */
entier * entiers_supprimer  (entier * liste, int index);
/**
 * Vide la liste et libère la mémoire
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @return NULL
 * */
void *   entiers_liberer    (entier * liste);
/**
 * Affiche la liste
 * @param liste Un pointeur vers le premier élément de la liste, peut-être NULL
 * @return Rien du tout
 * */
void     entiers_afficher   (entier * liste);

int main() {

    entier * liste = NULL, * element = NULL;
    int i;

    // Ajout de 5 valeurs
    liste = entiers_ajouter(liste, 1);
    liste = entiers_ajouter(liste, 2);
    liste = entiers_ajouter(liste, 33);
    liste = entiers_ajouter(liste, 5);
    liste = entiers_ajouter(liste, 444);

    // Comptage
    printf("\nCompte : %d\n\n", entiers_compter(liste));
    
    // Récupération et affichage d'un élément
    i = 3;
    element = entiers_recuperer(liste, i);
    if (element != NULL) {
        printf("%2d : %3d\n\n", i, element->valeur);
    }

    // Afficher tous les éléments
    entiers_afficher(liste);

    // Suppression d'un élément et affichage complet de la liste
    liste = entiers_supprimer(liste, 0);
    entiers_afficher(liste);
    liste = entiers_supprimer(liste, 7);
    entiers_afficher(liste);
    liste = entiers_supprimer(liste, 3);
    entiers_afficher(liste);
    liste = entiers_supprimer(liste, 1);
    entiers_afficher(liste);

    // Libération de la mémoire
    liste = entiers_liberer(liste);
    entiers_afficher(liste);

    return 0;
}

entier * entier_creer(int valeur) {
    return NULL;
}

entier * entiers_ajouter(entier * liste, int valeur) {
    return NULL;
}

int entiers_compter(entier * liste) {
    return 0;
}

entier * entiers_recuperer(entier * liste, int index) {
    return NULL;
}

entier * entiers_supprimer(entier * liste, int index) {
    return NULL;
}

void * entiers_liberer(entier * liste) {
    entier * courant = liste, * suivant;
    while(courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    return NULL;
}

void entiers_afficher(entier * liste) {
    entier * courant = liste;
    int i;
    for (i = 0; courant != NULL; i++) {
        printf("%2d : %3d\n", i, courant->valeur);
        courant = courant->suivant;
    }
    puts("");
}